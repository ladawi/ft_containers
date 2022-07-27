/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:11:05 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/27 17:41:22 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MAP_HPP
# define MAP_HPP

# include "MapIterator.hpp"
# include "CoreMapIterator.hpp"
# include "ConstMapIterator.hpp"
# include "Ft_iterators.hpp"
# include "sfinae_template.hpp"
# include "RevIterator.hpp"
# include "Pair.hpp"
# include "vector.hpp"
# include "stdexcept"
# include "ft_utils.hpp"
# include "node.hpp"
# include <cmath>

namespace ft {

	template < class Key,                                     // map::key_type
				class T,                                       // map::mapped_type
				class Compare = ft::less<Key>,                     // map::key_compare
				class Alloc = std::allocator<pair<const Key,T> >    // map::allocator_type
				>
	class map {

		public:

			typedef	Key											key_type;
			typedef	T											mapped_type;
			typedef	pair<const key_type, mapped_type>			value_type;
			typedef	Compare										key_compare;
			typedef	Alloc										allocator_type;
			typedef std::ptrdiff_t								difference_type;
			typedef size_t										size_type;

			typedef ft::node<value_type>						map_node;
			typedef map_node*									node_pointer;


			class	value_compare {
				public:
					Compare comp;
					value_compare (Compare c = key_compare()) : comp(c) {}  // constructed with map's comparison object
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};
			
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;

			typedef ft::MapIterator<value_type, value_compare>		iterator;
			typedef ft::ConstMapIterator<value_type, value_compare>	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		private:

			typedef typename allocator_type::template rebind<map_node>::other	map_node_allocator;
			typedef typename allocator_type::template rebind<value_type>::other	value_type_alloc;

		private:

			node_pointer		_head;
			allocator_type		_alloc;
			key_compare			_key_comp;
			node_pointer		_ghost;
			map_node_allocator	_map_node_alloc;

		public:


	/*
		=========================== Member functions ===========================
	*/
		explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _head(0), _alloc(alloc), _key_comp(comp)
		{
			// _ghost = new map_node();
			_ghost = _map_node_alloc.allocate(1);
			_map_node_alloc.construct(_ghost, value_type());
			_ghost->height = 0;
			_head = _ghost;
		};

		template <class InputIterator>
		map (InputIterator first, typename ft::enable_if<ft::is_input_iterator<InputIterator>::value, InputIterator>::type last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _head(0), _alloc(alloc), _key_comp(comp)
		{
			// _ghost = new map_node();
			_ghost = _map_node_alloc.allocate(1);
			_map_node_alloc.construct(_ghost, value_type());
			// _ghost->height = 0;
			insert(first, last);
			while (first != last)
			{
				insert(*first);
				++(first);
			}
		};
		map (const map& x) {
			_key_comp = x._key_comp;
			_alloc = x._alloc;
			_map_node_alloc = map_node_allocator();
			_head = _copy(x._head, NULL);
			_ghost = _map_node_alloc.allocate(1);
			_map_node_alloc.construct(_ghost, value_type());
			_set_ghost();
		};

		map& operator= (const map& x) {
			if (&x == this)
				return (*this);

			clear();
			if (x._head != x._ghost)
				insert(x.begin(), x.end());
			return (*this);
		};

		~map() {
			// std::cout << "Destructor map called." << std::endl;
			clear();
			delete _head;
		};
		
	/*
		=============================== Iterator ===============================
	*/

		iterator	begin() {
			node_pointer	tmp = _head;
			if (!_head)
				return(end());
			while (tmp && tmp->left)
				tmp = tmp->left;
			return (tmp);
		}

		const_iterator	begin() const {
			node_pointer	tmp = _head;
			if (!_head)
				return(end());
			while(tmp && tmp->left)
				tmp = tmp->left;
			return (tmp);
		}

		iterator	end() {
			return (_ghost);
		}

		const_iterator	end() const {
			return (_ghost);
		}

		reverse_iterator	rbegin() {
			return (end());
		}

		const_reverse_iterator rbegin() const {
			return (end());
		};

		reverse_iterator	rend() {
			return (begin());
		}

		const_reverse_iterator	rend() const {
			return (begin());
		}

	/*
		=============================== Capacity ===============================
	*/
		bool empty() const {
			return(!size());
		};

		size_type	size() const { return (_getsize(_head)); };

		size_type	max_size() const { return map_node_allocator().max_size(); };
	/*
		============================ Element access ============================
	*/

		mapped_type& operator[] (const key_type& k) {
			return ((*((this->insert(ft::make_pair(k, mapped_type()))).first)).second);
		};

	/*
		=============================== Modifiers ==============================
	*/

		pair<iterator, bool> insert (const value_type& val) {
			pair<iterator, bool> ret;
			_disable_ghost();
			_head = _insert(val, _head, NULL, ret);
			_set_ghost();
			return (ret);
		};

		iterator insert (iterator , const value_type& val) {
			pair<iterator, bool> ret;

			_disable_ghost();
			_head = _insert(val, _head, NULL, ret);
			_set_ghost();
			return (ret.first);
		};

		template <class InputIterator>
		void	insert (InputIterator first, typename ft::enable_if<ft::is_input_iterator<InputIterator>::value, InputIterator>::type last) {
			pair<iterator, bool> ret;

			_disable_ghost();
			while (first != last) {
				_head = _insert(*first, _head, NULL, ret);
				++(first);
			}
			_set_ghost();
		};

		void clear() {
			_disable_ghost();
			_clear(_head);
			_head = _ghost;
		};

		void	erase (iterator position) {
			if (position._node == _ghost)
				return;
			_disable_ghost();
			_head = _erase(_head, position._node->value.first);
			_set_ghost();
		};

		size_type erase (const key_type& k) {
			size_type size = this->size();

			_disable_ghost();
			_head = _erase(_head, k);
			_set_ghost();
			return (size - this->size());
		};

		void	erase (iterator first, iterator last) {
			ft::vector<key_type>tmp;

			while (first != last) {
				tmp.push_back(first->first);
				++first;
			}

			for (typename ft::vector<key_type>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
				erase(*it);
			}
		};

		void swap (map& x) {
			node_pointer		tmp_head = this->_head;
			allocator_type		tmp_alloc = this->_alloc;
			key_compare			tmp_key_comp = this->_key_comp;
			node_pointer		tmp_ghost = this->_ghost;
			map_node_allocator	tmp_map_node_alloc = this->_map_node_alloc;

			this->_head = x._head;
			this->_alloc = x._alloc;
			this->_key_comp = x._key_comp;
			this->_ghost = x._ghost;
			this->_map_node_alloc = x._map_node_alloc;

			x._head = tmp_head;
			x._alloc = tmp_alloc;
			x._key_comp = tmp_key_comp;
			x._ghost = tmp_ghost;
			x._map_node_alloc = tmp_map_node_alloc;
			};

	/*
		=============================== Overload ===============================
	*/

		bool operator==( const map& rhs ) const {
			const_iterator ite = rhs.begin();
			if (this->size() != rhs.size())
				return (0);
			for (const_iterator it = this->begin(); it != this->end(); it++)
			{
				if (*it != *ite)
					return (0);
				ite++;
			}
			return (1);
		};

		bool operator!=( const map& rhs ) const {
			return (!(*this == rhs));
		};

		bool operator<(const map& rhs) const {
			return(ft::lexicographical_compare(this->begin(), this->end(), rhs.begin(), rhs.end()));
		}

		bool operator>(const map& rhs) const {
			return (!(ft::lexicographical_compare(this->begin(), this->end(), rhs.begin(), rhs.end())) && this->operator!=(rhs));
		}
		bool operator>=(const map& rhs) const {
			return (!(*this < rhs));
		}

		bool operator<=(const map& rhs) const {
			return(ft::lexicographical_compare(this->begin(), this->end(), rhs.begin(), rhs.end()) || this->operator==(rhs));
		}

	/*
		============================== Observers ===============================
	*/

		key_compare key_comp() const {
			return (_key_comp);
		}
		value_compare value_comp() const { return value_compare(); };

	/*
		============================== Operations ==============================
	*/
		iterator lower_bound (const key_type& k) {
			iterator it = begin();

			while (_key_comp(it->first, k) && it != end())
				it++;
			return (it);
		};

		const_iterator lower_bound (const key_type& k) const {
			const_iterator it = begin();

			while (_key_comp(it->first, k) && it != end())
				it++;
			return (it);
		};

		iterator upper_bound (const key_type& k) {
			iterator it = begin();

			while (_key_comp(k, it->first) != true && it != end())
				it++;
			return (it);
		};

		const_iterator upper_bound (const key_type& k) const {
			const_iterator it = begin();

			while (_key_comp(k, it->first) != true && it != end())
				it++;
			return (it);
		};

		pair<const_iterator,const_iterator>	equal_range (const key_type& k) const {
			const_iterator it = lower_bound(k);
			const_iterator ite = upper_bound(k);
			
			return (ft::make_pair(it, ite));
		};

		pair<iterator,iterator>				equal_range (const key_type& k) {
			iterator it = lower_bound(k);
			iterator ite = upper_bound(k);
			
			return (ft::make_pair(it, ite));
		};

		iterator find (const key_type& k) {
			return (_find(_head, k));
		};

		const_iterator find (const key_type& k) const {
			return (_find(_head, k));
		};

		size_type count (const key_type& k) const {
			const_iterator cit;

			cit = find(k);
			return(cit != end());
		};

	/*
		=============================== Allocator ===============================
	*/
		allocator_type	get_allocator() const {
			return (_alloc);
		};
	/*
		============================ Private method ============================
	*/
	private:

		node_pointer	_insert(const value_type& val, node_pointer node, node_pointer parent, pair<iterator,bool> &ret) {
			if (!node || node == _ghost)
			{
				// add node
				// node = new map_node(val);
				node = _map_node_alloc.allocate(1);
				_map_node_alloc.construct(node, val);
				node->parent = parent;
				ret = ft::pair<iterator, bool>(node, true);
				return (node);
			}
			else if (val.first == node->value.first) {
				ret = ft::pair<iterator, bool>(node, false);
				return (node);
			}
			else if (_key_comp(val.first, node->value.first)) {
				node->left = _insert(val, node->left, node, ret);
			}
			else if (_key_comp(node->value.first, val.first)) {
				node->right = _insert(val, node->right, node, ret);
			}
			
			node->height = 1 + ft::max(height(node->left), height(node->right));
			int balanceFactor = getBalanceFactor(node);
			if (balanceFactor < -1 && _key_comp(node->right->value.first, val.first))
			{
				return(_left_rotate(node));
			}
			if (balanceFactor < -1 && _key_comp(val.first, node->right->value.first))
			{
				node->right = _right_rotate(node->right);
				return (_left_rotate(node));
			}
			if (balanceFactor > 1 && _key_comp(val.first, node->left->value.first))
			{
				return(_right_rotate(node));
			}
			if (balanceFactor > 1 && _key_comp(node->left->value.first, val.first))
			{
				node->left = _left_rotate(node->left);
				return (_right_rotate(node));
			}
			return (node);
		}

		node_pointer	_left_rotate(node_pointer node) {
			node_pointer tmp_right = node->right;
			node_pointer tmp_p = node->parent;

			node->right = tmp_right->left;
			if (node->right)
				node->right->parent = node;
			tmp_right->left = node;

			node->parent = tmp_right;

			if (tmp_right)
				tmp_right->parent = tmp_p;

			node->height = 1 + ft::max(height(node->left), height(node->right));
			tmp_right->height = 1 + ft::max(height(tmp_right->left), height(tmp_right->right));
			return (tmp_right);
		};
		
		node_pointer	_right_rotate(node_pointer node) {
			node_pointer tmp_left = node->left;
			node_pointer tmp_p = node->parent;

			node->left = tmp_left->right;
			if (node->left)
				node->left->parent = node;
			tmp_left->right = node;

			node->parent = tmp_left;

			if (tmp_left)
				tmp_left->parent = tmp_p;

			node->height = 1 + ft::max(height(node->left), height(node->right));
			tmp_left->height = 1 + ft::max(height(tmp_left->left), height(tmp_left->right));
			return (tmp_left);
		};
		
		int		height(node_pointer N) {
			if (N == NULL)
				return 0;
			return N->height;
		};

		int		getBalanceFactor(node_pointer N) {
			if (N == NULL)
				return 0;
			return (height(N->left) - height(N->right));
		};

		size_type	_getsize(node_pointer node) const {
			if (!node || node == _ghost)
				return (0);
			return(1 + _getsize(node->left) + _getsize(node->right));
		}

		void		_disable_ghost() {
			if (_head == _ghost) {
				_head = NULL;
			}
			_ghost->left = NULL;
			_ghost->right = NULL;
			if (_ghost->parent)
				_ghost->parent->right = NULL;
			_ghost->parent = NULL;
		}

		void		_set_ghost() {
			node_pointer	tmp = _head;
			if (!tmp)
				return;
			while (tmp->right)
				tmp = tmp->right;
			tmp->right = _ghost;
			_ghost->left = tmp;
			_ghost->parent = tmp;
			_ghost->right = tmp;
		}

		node_pointer	_destroy_node(node_pointer node, node_pointer ret = NULL) {
			if (ret) {
				ret->parent = node->parent;
			}
			_map_node_alloc.destroy(node);
			_map_node_alloc.deallocate(node, 1);
			return (ret);
		}

		node_pointer	_clear(node_pointer node) {
			if (node == NULL || node == _ghost)
				return NULL;
			node->left = _clear(node->left);
			node->right = _clear(node->right);
			return (_destroy_node(node));
		}

		node_pointer	_copy(node_pointer node, node_pointer parent) {
			node_pointer	tmp = NULL;

			if (node && ((!node->left && !node->right) || node->left != node->right))
			{
				tmp = _map_node_alloc.allocate(1);
				_map_node_alloc.construct(tmp, node->value);
				tmp->parent = parent;

				tmp->left = _copy(node->left, tmp);
				tmp->right = _copy(node->right, tmp);
			}
			return (tmp);
		}

		node_pointer	_find_max(node_pointer node) {
			if (!node || (node->parent == node->right))
				return (node);
			while (node->right)
				node = node->right;
			return (node);
		}

		iterator	_find(node_pointer node, const key_type& k) const {
			if (!node || node == _ghost)
				return _ghost;
			if (!_key_comp(k, node->value.first) && !_key_comp(node->value.first, k))
				return (node);
			if (_key_comp(k, node->value.first))
				return (_find(node->left, k));
			return (_find(node->right, k));
		}

		node_pointer	_erase(node_pointer	node, const key_type& val) {
			if (!node)
				return NULL;
			if (_key_comp(val, node->value.first)) {
				node->left = _erase(node->left, val);
			}
			else if (_key_comp(node->value.first, val)) {
				node->right = _erase(node->right, val);
			}
			else {

				if (node->left && node->right) {
					node_pointer	max = _find_max(node->left);
					value_type_alloc().destroy(&node->value);
					value_type_alloc().construct(&node->value, max->value);
					node->left = _erase(node->left, max->value.first);
				}
				else if (!node->left && node->right) {
					return (_destroy_node(node, node->right));
				}
				else if (node->left && !node->right) {
					return (_destroy_node(node, node->left));
				}
				else {
					return (_destroy_node(node));
				}
			}
			node->height = 1 + ft::max(height(node->left), height(node->right));
			int balanceFactor = getBalanceFactor(node);

			if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
				node->left = _left_rotate(node->left);
				return (_right_rotate(node));
			}
			if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
				return (_right_rotate(node));
			if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
				return (_left_rotate(node));
			if (balanceFactor < -1 && getBalanceFactor(node->right) < 0) {
				node->right = _right_rotate(node->right);
				return (_left_rotate(node));
			}
			return node;
		}


};

		template< class Key, class T, class Compare, class Alloc >
		void swap( ft::map<Key,T,Compare,Alloc>& lhs,
				ft::map<Key,T,Compare,Alloc>& rhs ) {
			lhs.swap(rhs);
		};


}

#endif