/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:11:05 by ladawi            #+#    #+#             */
/*   Updated: 2022/07/07 19:09:17 by ladawi           ###   ########.fr       */
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

			
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;

			typedef ft::MapIterator<value_type>					iterator;
			typedef ft::ConstMapIterator<value_type>			const_iterator;

		public:

			node_pointer	_head;
			allocator_type	_alloc;
			key_compare		_key_comp;

		private:

		typedef typename allocator_type::template rebind<map_node>::other		_node_allocator;

		public:


	/*
		=========================== Member functions ===========================
	*/
		explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _head(0), _alloc(alloc), _key_comp(comp)
		{
			// key_compare(_head->value.first, _head->value.second);
		
		};
		// map (const key_compare& kc, const allocator_type& alloc);
		// map< Key, T>();
		~map() {
			std::cout << "Destructor map called." << std::endl;
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
			node_pointer	tmp = _head;
			while(tmp && tmp->right)
				tmp = tmp->right;
			return (tmp);
		}

		const_iterator	end() const {
			node_pointer	tmp = _head;
			while(tmp && tmp->right)
				tmp = tmp->right;
			return (tmp);
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
			if (root == NULL) {
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

			_head = _insert(val, _head, NULL);
			return (ft::pair<iterator, int>(NULL,1));
		};
	/*
		=============================== Overload ===============================
	*/

	/*
		============================== End public ==============================
	*/

	/*
		============================ Private method ============================
	*/
	private:

		node_pointer	_insert(const value_type& val, node_pointer node, node_pointer parent) {
			if (!node)
			{
				// add node
				node = new map_node(val);
				node->parent = parent;
				return (node);
			}
			else if (val.first == node->value.first) {
				// ret = ft::pair<iterator, bool>(node, false);
				std::cout << "Monaks" << std::endl;
				return (node);
			}
			else if (_key_comp(val.first, node->value.first)) {
				node->left = _insert(val, node->left, node);
			}
			else if (_key_comp(node->value.first, val.first)) {
				node->right = _insert(val, node->right, node);
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
			if (!node)
				return (0);
			return(1 + _getsize(node->left) + _getsize(node->right));
		}
};

}

#endif