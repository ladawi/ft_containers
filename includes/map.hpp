/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:11:05 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/08 14:20:37 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MAP_HPP
# define MAP_HPP

# include "MapIterator.hpp"
# include "ConstMapIterator.hpp"
# include "Ft_iterators.hpp"
# include "sfinae_template.hpp"
# include "RevIterator.hpp"
# include "Pair.hpp"
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

			struct	val_comp {
				val_comp(key_compare key_comp = key_compare()) : kc(key_comp) {};
				bool	operator()(const value_type &first, const value_type &second) {
					return (kc(first.first, second.first));
				}
				key_compare	kc;
			};
			
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;

			typedef ft::MapIterator<value_type, val_comp>					iterator;
			typedef ft::ConstMapIterator<value_type, val_comp>			const_iterator;

		public:

			node_pointer	_head;
			allocator_type	_alloc;
			key_compare		_key_comp;
			node_pointer	_ghost;

		private:

		typedef typename allocator_type::template rebind<map_node>::other		_node_allocator;

		public:


	/*
		=========================== Member functions ===========================
	*/
		explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _head(0), _alloc(alloc), _key_comp(comp)
		{
			_ghost = new map_node();
			_ghost->height = 0;
			_head = _ghost;
		};

		template <class InputIterator>
		map (InputIterator first, typename ft::enable_if<ft::is_input_iterator<InputIterator>::value, InputIterator>::type last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _head(0), _alloc(alloc), _key_comp(comp)
		{
			_ghost = new map_node();
			_ghost->height = 0;
			while (first != last)
			{
				insert(*first);
				++(first);
			}
		};
		map (const map& x) {
			_ghost = x._ghost;
			_head = x._head;
			_alloc = x._alloc;
			_key_comp = x._key_comp;
			_set_ghost();
		};

		~map() {
			// std::cout << "Destructor map called." << std::endl;
			delete _head;
		};
		
	/*
		=============================== Iterator ===============================
	*/

		iterator	begin() {
			node_pointer	tmp = _head;
			while(tmp && tmp->left)
				tmp = tmp->left;
			return (tmp);
		}

		const_iterator	begin() const {
			node_pointer	tmp = _head;
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

	/*
		=============================== Capacity ===============================
	*/
		bool empty() const {
			return(_head == 0 ? 1 : 0);
		};

		size_type	size() const { return (_getsize(_head)); };

		size_type	max_size() const { return _node_allocator().max_size(); };
	/*
		============================ Element access ============================
	*/

	/*
		============================== Print Tree ==============================
	*/
		struct Trunk
		{
			Trunk *prev;
			std::string str;

			Trunk(Trunk *prev, std::string str)
			{
				this->prev = prev;
				this->str = str;
			}
		};

		// Helper function to print branches of the binary tree
		void showTrunks(Trunk *p)
		{
			if (p == NULL) {
				return;
			}

			showTrunks(p->prev);
			std::cout << p->str;
		}

		void printTree(node_pointer root, Trunk *prev, bool isLeft)
		{
			if (root == NULL || root == _ghost) {
				return;
			}

			std::string prev_str = "    ";
			Trunk *trunk = new Trunk(prev, prev_str);
			printTree(root->right, trunk, true);

			if (!prev) {
				trunk->str = "———";
			}
			else if (isLeft)
			{
				trunk->str = ".———";
				prev_str = "   |";
			}
			else {
				trunk->str = "`———";
				prev->str = prev_str;
			}

			showTrunks(trunk);
			std::cout << " " << root->value.first << "\n";//<< root->height << endl;

			if (prev) {
				prev->str = prev_str;
			}
			trunk->str = "   |";
			printTree(root->left, trunk, false);
		}
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
		// template <class InputIterator>
		// void insert (InputIterator first, InputIterator last) {
			
		// };
	/*
		=============================== Overload ===============================
	*/

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

	/*
		============================ Private method ============================
	*/
	private:

		node_pointer	_insert(const value_type& val, node_pointer node, node_pointer parent, pair<iterator,bool> ret) {
			if (!node || node == _ghost)
			{
				// add node
				node = new map_node(val);
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
			// std::cout << "d=8" << std::endl;
			if (balanceFactor < -1 && _key_comp(node->right->value.first, val.first))
			{
				return(_left_rotate(node));
			}
			if (balanceFactor < -1 && _key_comp(val.first, node->right->value.first))
			{
				node->right = _right_rotate(node->right);
				return (_left_rotate(node));
			}
			if (balanceFactor > 1 && _key_comp(val.first, node->right->value.first))
			{
				return(_right_rotate(node));
			}
			if (balanceFactor > 1 && _key_comp(node->right->value.first, val.first))
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
};

}

#endif