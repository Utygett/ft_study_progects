/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:45:23 by utygett           #+#    #+#             */
/*   Updated: 2022/06/11 22:51:44 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include "utils.hpp"
#include "pair.hpp"
#include "reverse_iterator.hpp"
namespace ft
{
	template <class T, class Compare, class Alloc>
	class binary_tree
	{
	public:
		typedef T					value_type;
		typedef Compare				key_compare;
		typedef Alloc				allocator_type;
		typedef value_type&			reference;
		typedef value_type*			pointer;
		typedef	const value_type&	const_reference;
		typedef	std::size_t			size_type;

		struct node_type
		{
			node_type();
			node_type(const T & value);
			node_type(const node_type& node);
			node_type& operator=(const node_type & node);
			
			node_type		*parent;
			node_type		*child[2];
			T				value;
		};
		
		typedef typename allocator_type::template rebind<node_type>::other   allocator_node_type;
		
		class const_iterator;
		
		class iterator
		{
		private:
			node_type	*node_iterator;
		public:
			typedef std::ptrdiff_t              difference_type;
            typedef T                           value_type;
            typedef T*                          pointer;
            typedef T&                          reference;
            typedef bidirectional_iterator_tag  iterator_category;

			iterator() : node_iterator(NULL){}
			iterator(node_type *p_node) : node_iterator(p_node){}
			iterator(const iterator & it) : node_iterator(it.node_iterator){}
			iterator &	operator=(const iterator& for_assign) {
				if (this == &for_assign)
					return *this;
				node_iterator = for_assign.node_iterator;
				return *this;
			}
			~iterator(){}
			node_type *getPointer() const {return node_iterator;}

			iterator&	operator++();
			iterator	operator++(int);
			iterator&	operator--();
			iterator	operator--(int);
			bool        operator==(const iterator& it) const {return node_iterator == it.node_iterator;}
            bool        operator!=(const iterator& it) const {return node_iterator != it.node_iterator;}
            bool        operator==(const const_iterator& it) const {return node_iterator == it.node_iterator;}
            bool        operator!=(const const_iterator& it) const {return node_iterator != it.node_iterator;}
            
            reference   operator*() {return node_iterator->value;}
            pointer     operator->() {return &(node_iterator->value);}
		};

		class const_iterator
		{
		private:
			const node_type	*node_iterator;
		public:
			typedef std::ptrdiff_t              difference_type;
            typedef T                           value_type;
            typedef T*                          pointer;
            typedef T&                          reference;
            typedef bidirectional_iterator_tag  iterator_category;

			const_iterator() : node_iterator(NULL){}
			const_iterator(node_type *p_node) : node_iterator(p_node){}
			const_iterator(const iterator & it) : node_iterator(it.node_iterator){}
			const_iterator(const const_iterator & it) : node_iterator(it.node_iterator){}
			const_iterator &	operator=(const const_iterator& for_assign) {
				if (this == &for_assign)
					return (*this);
				node_iterator = for_assign.node_iterator;
				return (*this);
			}
			~const_iterator(){}
			node_type *getPointer() const {return node_iterator;}

			const_iterator&	operator++();
			const_iterator	operator++(int);
			const_iterator&	operator--();
			const_iterator	operator--(int);
			bool        operator==(const iterator& it) const {return node_iterator == it.node_iterator;}
            bool        operator!=(const iterator& it) const {return node_iterator != it.node_iterator;}
            bool        operator==(const const_iterator& it) const {return node_iterator == it.node_iterator;}
            bool        operator!=(const const_iterator& it) const {return node_iterator != it.node_iterator;}
            
            const_reference  operator*() const {return node_iterator->value;}
            pointer     operator->() const {return &(node_iterator->value);}
		};

        typedef reverse_iterator<const_iterator>    const_reverse_iterator;
		typedef reverse_iterator<iterator>          reverse_iterator;

		binary_tree(const key_compare& comp, const allocator_type& alloc);
        binary_tree(const binary_tree& other);
        ~binary_tree();

		binary_tree&	operator=(const binary_tree& for_assign);

		iterator        begin();
        const_iterator  begin() const;
        iterator        end();
        const_iterator  end() const;
		
		pair<iterator, bool>    insert_node(node_type *);
        pair<iterator, bool>    insert_node(iterator, node_type *);
        void			copy_tree(node_type*& current, node_type* parent, node_type* curr_copy);
		void            clear();
		void			clear_tree(node_type *node);

		allocator_type			get_allocator() const {return t_alloc_pair;}
		allocator_node_type     get_alloc_node() const {return t_alloc_node;}
		void                    dealloc_node(node_type* node);
		size_type               size() const { return t_size;}
		void                  	erase(iterator erase_it);
		void 					swap(binary_tree& other);
		bool					find_node(const value_type &k) const;
		iterator                                lower_bound(const value_type&);
        const_iterator                          lower_bound(const value_type&) const;
        iterator                                upper_bound(const value_type&);
        const_iterator                          upper_bound(const value_type&) const;
        pair<iterator, iterator>                equal_range(const value_type &k);
        pair<const_iterator, const_iterator>    equal_range(const value_type &k) const;

	private:
		enum    direction{
			RIGHT = 0,
			LEFT = 1
		};
		node_type           *head;
		node_type           *root;
		allocator_node_type t_alloc_node;
		allocator_type      t_alloc_pair;
		key_compare         t_comp;
		size_type           t_size;
		void                            set_head_children();
        void                            set_head_children(node_type* node);
		void							swap_node_and_delete(node_type* curr, node_type* target);
	};

	template <class T, class Compare, class Alloc>
    binary_tree<T, Compare, Alloc>::binary_tree(const key_compare& comp, const allocator_type& alloc) : t_comp(comp)
    {
        t_alloc_pair = alloc;
        t_alloc_node = allocator_node_type();
        t_comp = comp;
        head = t_alloc_node.allocate(1);
        t_alloc_node.construct(head, node_type());
        t_size = 0;
        root = NULL;
    }

    template <class T, class Compare, class Alloc>
    binary_tree<T, Compare, Alloc>::binary_tree(const binary_tree& other) : t_comp(other.t_comp)
    {
        t_alloc_pair = other.t_alloc_pair;
        t_alloc_node = other.t_alloc_node;
        
        *this = other;
    }

	template <class T, class Compare, class Alloc>
    binary_tree<T, Compare, Alloc>::~binary_tree()
	{
		clear();
        dealloc_node(head);
        head = NULL;
        root = NULL;
	}

	template <class T, class Compare, class Alloc>
    void binary_tree<T, Compare, Alloc>::copy_tree(node_type*& current, node_type* curr_parent, node_type* curr_copy)
    {
        if (!curr_copy)
            current = NULL;
        else
        {
            current = t_alloc_node.allocate(1);
            t_alloc_node.construct(current, *curr_copy);
            current->parent = curr_parent;
            copy_tree(current->child[LEFT], current, curr_copy->child[LEFT]);
            copy_tree(current->child[RIGHT], current, curr_copy->child[RIGHT]);
        }
    }

	
	template <class T, class Compare, class Alloc>
    void binary_tree<T, Compare, Alloc>::clear()
    {
        if (root)
        {
            clear_tree(root);
            root = NULL;
            t_size = 0;
        }
    }

    template <class T, class Compare, class Alloc>
    void binary_tree<T, Compare, Alloc>::clear_tree(node_type *node)
    {
        // if (node->child[LEFT])
        //     clear_tree(node->child[LEFT]);
        // if (node->child[RIGHT])
        //     clear_tree(node->child[RIGHT]);
        // dealloc_node(node);
		iterator start = begin();
		iterator buf;
		while (start != end())
		{
			buf = start++;
			erase(buf);
		}
		
    }

    template <class T, class Compare, class Alloc>
    binary_tree<T, Compare, Alloc>& binary_tree<T, Compare, Alloc>::operator=(const binary_tree& other)
    {
        if (this == &other)
            return (*this);
        clear();
        head = t_alloc_node.allocate(1);
        t_alloc_node.construct(head, node_type());
        copy_tree(root, head, other.root);
        t_size = other.t_size;
        head->parent = NULL;
        set_head_children();
        return (*this);
    }
	
	template <class T, class Compare, class Alloc>
	void binary_tree<T, Compare, Alloc>::set_head_children()
    {
        if (!root) {
            head->child[LEFT] = NULL;
            head->child[RIGHT] = NULL;
            return ;
        }
        node_type* temp = root;
        while (temp->child[LEFT])
            temp = temp->child[LEFT];
        head->child[RIGHT] = temp;
        temp = root;
        while (temp->child[RIGHT])
            temp = temp->child[RIGHT];
        head->child[LEFT] = temp;
    }

	template <class T, class Compare, class Alloc>
    void binary_tree<T, Compare, Alloc>::set_head_children(node_type* node)
    {
        if (t_comp(node->value, head->child[RIGHT]->value))
            head->child[RIGHT] = node;
        else if (t_comp(head->child[LEFT]->value, node->value))
            head->child[LEFT] = node;
    }


	template <class T, class Compare, class Alloc>
    typename binary_tree<T, Compare, Alloc>::iterator   binary_tree<T, Compare, Alloc>::begin()
    {
        if (root)
            return iterator(head->child[RIGHT]);
        return iterator(head);
    }

	template <class T, class Compare, class Alloc>
    typename binary_tree<T, Compare, Alloc>::const_iterator  binary_tree<T, Compare, Alloc>::begin() const
    {
        if (root)
            return const_iterator(head->child[RIGHT]);
        return const_iterator(head);    
    }

	template <class T, class Compare, class Alloc>
    typename binary_tree<T, Compare, Alloc>::iterator   binary_tree<T, Compare, Alloc>::end()
    {
        return iterator(head);
    }

	template <class T, class Compare, class Alloc>
    typename binary_tree<T, Compare, Alloc>::const_iterator  binary_tree<T, Compare, Alloc>::end() const
    {
        return const_iterator(head);
    }

	template <class T, class Compare, class Alloc>
    pair<typename binary_tree<T, Compare, Alloc>::iterator, bool>    binary_tree<T, Compare, Alloc>::insert_node(node_type *node)
    {
        node_type   *t_node = root;
        if (!t_node)
        {
            root = node;
            root->parent = head;
            head->parent = NULL;
            head->child[LEFT] = root;
            head->child[RIGHT] = root;
            ++t_size;
            return ft::make_pair(iterator(root), true);
        }
        node_type   *t_parent = NULL;
		if(head->child[LEFT]->value.first < node->value.first)
			t_node = head->child[LEFT];
		if(head->child[RIGHT]->value.first > node->value.first)
			t_node = head->child[RIGHT];
        while (t_node)
        {
            if (t_node->value.first == node->value.first)
                return ft::make_pair(iterator(t_node), false);
            t_parent = t_node;
            t_node = t_node->child[(int)t_comp(node->value, t_node->value)];
        }
        t_parent->child[(int)t_comp(node->value, t_parent->value)] = node;
        node->parent = t_parent;
        set_head_children(node);
        ++t_size;
        return ft::make_pair(iterator(node), true);
    }

    template <class T, class Compare, class Alloc>
    pair<typename binary_tree<T, Compare, Alloc>::iterator, bool>    binary_tree<T, Compare, Alloc>::insert_node(iterator pos, node_type *node)
    {
        if (pos != iterator(head) && t_comp(*pos, node->value) && (!pos.getPointer()->child[RIGHT]) &&
            ((++pos == iterator(head)) || t_comp(node->value, *pos)))
        {
            --pos;
            pos.getPointer()->child[RIGHT] = node;
            node->parent = pos.getPointer();
            set_head_children(node);
            ++t_size;
            return make_pair(iterator(node), true);
        }
        return insert_node(node);
    }

	template <class T, class Compare, class Alloc>
    void binary_tree<T, Compare, Alloc>::dealloc_node(node_type *node)
    {
        	t_alloc_pair.destroy(&node->value);
        	t_alloc_node.deallocate(node, 1);
    }

	template <class T, class Compare, class Alloc>
    void    binary_tree<T, Compare, Alloc>::erase(iterator erase_it)
    {
        node_type*  erase_node = erase_it.getPointer();

		if (!erase_node->child[RIGHT] && !erase_node->child[LEFT] && erase_node->value.first == root->value.first)
		{
			root = NULL;
		}
		else if (!erase_node->child[RIGHT] && !erase_node->child[LEFT])
		{
			if (erase_node->parent->child[RIGHT] == erase_node)
				erase_node->parent->child[RIGHT] = NULL;
			else
				erase_node->parent->child[LEFT] = NULL;
		}
		else if (!erase_node->child[RIGHT] || !erase_node->child[LEFT])
		{
			if (!erase_node->child[RIGHT])
			{
				if (erase_node->parent->child[RIGHT] == erase_node)
				{
					erase_node->parent->child[RIGHT] = erase_node->child[LEFT];
					erase_node->child[LEFT]->parent = erase_node->parent;

				}
				else
				{
					erase_node->parent->child[LEFT] = erase_node->child[LEFT];
					erase_node->child[LEFT]->parent = erase_node->parent;
				}
				if(erase_node == root)
						root = erase_node->child[LEFT];
			}
			else
			{
				if (erase_node->parent->child[RIGHT] == erase_node)
				{
					erase_node->parent->child[RIGHT] = erase_node->child[RIGHT];
					erase_node->child[RIGHT]->parent = erase_node->parent;
					
				}
				else
				{
					erase_node->parent->child[LEFT] = erase_node->child[RIGHT];
					erase_node->child[RIGHT]->parent = erase_node->parent;

				}
				if(erase_node == root)
						root = erase_node->child[RIGHT];
			}
		}
		else if (erase_node->child[RIGHT] && erase_node->child[LEFT])
		{
			node_type*  erase_node_tmp = erase_node->child[LEFT];
			while (erase_node_tmp->child[RIGHT])
			{
				erase_node_tmp = erase_node_tmp->child[RIGHT];
			}
			swap_node_and_delete(erase_node, erase_node_tmp);
			if(erase_node == root)
				root = erase_node->child[LEFT];
		}
		if (erase_node == head->child[LEFT] || erase_node == erase_node->child[RIGHT])
        	set_head_children();
		dealloc_node(erase_node);
        --t_size;
    }
					
	template <class T, class Compare, class Alloc>
    void    binary_tree<T, Compare, Alloc>::swap_node_and_delete(node_type* curr, node_type* target)
	{
		if(curr != root)
		{
			if (curr->parent->child[RIGHT] == curr)
				curr->parent->child[RIGHT] = target;
			else
				curr->parent->child[LEFT] = target;
		}
		else
			root = target;
		if(curr->child[LEFT] == target)
		{	
			target->parent = curr->parent;

			target->child[RIGHT] = curr->child[RIGHT];
			curr->child[RIGHT]->parent = target;
			return ;
		}
		target->parent->child[RIGHT] = target->child[LEFT];
		if(target->child[LEFT])
			target->child[LEFT]->parent = target->parent;
		target->parent = curr->parent;
		target->child[RIGHT] = curr->child[RIGHT];
		target->child[LEFT] = curr->child[LEFT];
		target->child[RIGHT]->parent = target;
		target->child[LEFT]->parent = target;
	}
	
	template <class T, class Compare, class Alloc>
    void    binary_tree<T, Compare, Alloc>::swap(binary_tree& other)
	{
		node_type           *tmp_head = other.head;
		node_type           *tmp_root = other.root;
		size_type           tmp_t_size = other.t_size;

		other.head = head;
		other.root = root;
		other.t_size = t_size;

		head = tmp_head;
		root = tmp_root;
		t_size = tmp_t_size;
	}

	template <class T, class Compare, class Alloc>
    typename binary_tree<T, Compare, Alloc>::iterator  binary_tree<T, Compare, Alloc>::lower_bound(const value_type& k)
    {
        node_type   *temp = root;
        node_type   *before_temp = NULL;
        while (temp)
        {
            if (temp->value == k)
                return (iterator(temp));
            before_temp = temp;
            temp = temp->child[(int)t_comp(k, temp->value)];
        }
        if (t_comp(k, before_temp->value))
            return (iterator(before_temp));
        return (++iterator(before_temp));
    }
        
    template <class T, class Compare, class Alloc>
    typename binary_tree<T, Compare, Alloc>::const_iterator    binary_tree<T, Compare, Alloc>::lower_bound(const value_type& k) const
    {
        const node_type   *temp = root;
        const node_type   *before_temp = NULL;
        while (temp)
        {
            if (temp->value == k)
                return (const_iterator(temp));
            before_temp = temp;
            temp = temp->child[(int)t_comp(k, temp->value)];
        }
        if (t_comp(k, before_temp->value))
            return (const_iterator(before_temp));
        return (++const_iterator(before_temp));
    }
        
    template <class T, class Compare, class Alloc>
    typename binary_tree<T, Compare, Alloc>::iterator  binary_tree<T, Compare, Alloc>::upper_bound(const value_type& k)
    {
        node_type   *temp = root;
        node_type   *before_temp = NULL;
        while (temp)
        {
            if (temp->value == k)
                return (++iterator(temp));
            before_temp = temp;
            temp = temp->child[(int)t_comp(k, temp->value)];
        }
        if (t_comp(k, before_temp->value))
            return (iterator(before_temp));
        return (++iterator(before_temp));
    }
        
    template <class T, class Compare, class Alloc>
    typename binary_tree<T, Compare, Alloc>::const_iterator    binary_tree<T, Compare, Alloc>::upper_bound(const value_type& k) const
    {
        const node_type   *temp = root;
        const node_type   *before_temp = NULL;
        while (temp)
        {
            if (temp->value == k)
                return (++const_iterator(temp));
            before_temp = temp;
            temp = temp->child[(int)t_comp(k, temp->value)];
        }
        if (t_comp(k, before_temp->value))
            return (const_iterator(before_temp));
        return (++const_iterator(before_temp));
    }
        
    template <class T, class Compare, class Alloc>
    pair<typename binary_tree<T, Compare, Alloc>::iterator,
    typename binary_tree<T, Compare, Alloc>::iterator>         binary_tree<T, Compare, Alloc>::equal_range(const value_type &k)
    {
        return (ft::make_pair(lower_bound(k), upper_bound(k)));
    }
        
    template <class T, class Compare, class Alloc>
    pair<typename binary_tree<T, Compare, Alloc>::const_iterator,
    typename binary_tree<T, Compare, Alloc>::const_iterator>    binary_tree<T, Compare, Alloc>::equal_range(const value_type &k) const
    {
        return (ft::make_pair(lower_bound(k), upper_bound(k)));
    }

	/*Node definition*/
		
	template <class T, class Compare, class Alloc>
    binary_tree<T, Compare, Alloc>::node_type::node_type() : value(value_type())
    {
        parent = NULL;
        child[LEFT] = NULL;
        child[RIGHT] = NULL;
    }
	 template <class T, class Compare, class Alloc>
    binary_tree<T, Compare, Alloc>::node_type::node_type(const T &val) : value(val)
    {
        parent = NULL;
        child[LEFT] = NULL;
        child[RIGHT] = NULL;
    }

    template <class T, class Compare, class Alloc>
    binary_tree<T, Compare, Alloc>::node_type::node_type(const node_type& node) : value(node.value)
    {
        parent = NULL;
        child[LEFT] = NULL;
        child[RIGHT] = NULL;
    }


	/*Iterators operator definition*/
	
	template <class T, class Compare, class Alloc>
    typename binary_tree<T, Compare, Alloc>::iterator&   binary_tree<T, Compare, Alloc>::iterator::operator++()
    {
		if(!node_iterator->child[RIGHT]) {
			while (node_iterator->parent && node_iterator->parent->child[RIGHT] == node_iterator)
				node_iterator = node_iterator->parent;
			if (node_iterator->parent)
				node_iterator = node_iterator->parent;
		}
		else {
			node_iterator = node_iterator->child[RIGHT];
			while (node_iterator->child[LEFT])
				node_iterator = node_iterator->child[LEFT];		
		}
		return *this;
	}
	
	template <class T, class Compare, class Alloc>
    typename binary_tree<T, Compare, Alloc>::iterator   binary_tree<T, Compare, Alloc>::iterator::operator++(int)
    {
        iterator    temp = *this;
        
        ++(*this);
        return temp;
    }

	template <class T, class Compare, class Alloc>
    typename binary_tree<T, Compare, Alloc>::iterator&   binary_tree<T, Compare, Alloc>::iterator::operator--()
    {
		if(!node_iterator->child[LEFT]) {
			while (node_iterator->parent && node_iterator->parent->child[LEFT] == node_iterator)
				node_iterator = node_iterator->parent;
			if (node_iterator->parent)
				node_iterator = node_iterator->parent;
		}
		else {
			node_iterator = node_iterator->child[LEFT];
			while (node_iterator->child[RIGHT])
				node_iterator = node_iterator->child[RIGHT];
		}
		return *this;
	}
	
	template <class T, class Compare, class Alloc>
    typename binary_tree<T, Compare, Alloc>::iterator   binary_tree<T, Compare, Alloc>::iterator::operator--(int)
    {
        iterator    temp = *this;
        
        --(*this);
        return temp;
    }

	template <class T, class Compare, class Alloc>
    typename binary_tree<T, Compare, Alloc>::const_iterator&   binary_tree<T, Compare, Alloc>::const_iterator::operator++()
    {
		if(!node_iterator->child[RIGHT]) {
			while (node_iterator->parent && node_iterator->parent->child[RIGHT] == node_iterator)
				node_iterator = node_iterator->parent;
			if (node_iterator->parent)
				node_iterator = node_iterator->parent;			
		}
		else {
			node_iterator = node_iterator->child[RIGHT];
			while (node_iterator->child[LEFT])
				node_iterator = node_iterator->child[LEFT];			
		}
		return *this;
	}
	
	template <class T, class Compare, class Alloc>
    typename binary_tree<T, Compare, Alloc>::const_iterator   binary_tree<T, Compare, Alloc>::const_iterator::operator++(int)
    {
        iterator    temp = *this;
        
        ++(*this);
        return temp;
    }

	template <class T, class Compare, class Alloc>
    typename binary_tree<T, Compare, Alloc>::const_iterator&   binary_tree<T, Compare, Alloc>::const_iterator::operator--()
    {
		if(!node_iterator->child[LEFT]) {
			while (node_iterator->parent && node_iterator->parent->child[LEFT] == node_iterator)
				node_iterator = node_iterator->parent;
			if (node_iterator->parent)
				node_iterator = node_iterator->parent;			
		}
		else {
			node_iterator = node_iterator->child[LEFT];
			while (node_iterator->child[RIGHT])
				node_iterator = node_iterator->child[RIGHT];			
		}
		return *this;
	}
	
	template <class T, class Compare, class Alloc>
    typename binary_tree<T, Compare, Alloc>::const_iterator   binary_tree<T, Compare, Alloc>::const_iterator::operator--(int)
    {
        iterator    temp = *this;
        
        --(*this);
        return temp;
    }

	template <class T, class Compare, class Alloc>
    bool binary_tree<T, Compare, Alloc>::find_node(const value_type &k) const
    {
        node_type   *temp = root;
        while (temp)
        {
            if (temp->value.first == k.first)
                return (true);
            temp = temp->child[(int)t_comp(k, temp->value)];
        }
        return (false);
    }
}

#endif
