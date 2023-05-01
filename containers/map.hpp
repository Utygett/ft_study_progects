/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:15:10 by utygett           #+#    #+#             */
/*   Updated: 2022/05/21 23:37:02 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <memory>
#include "utils.hpp"
#include "pair.hpp"
#include "binary_tree.hpp"
#include "reverse_iterator.hpp"
namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map
	{
	
	public:
		typedef Key     										key_type;
		typedef T                                        		mapped_type;
		typedef pair<const key_type, mapped_type>				value_type;
		typedef Compare											key_compare;
		typedef Alloc											allocator_type;


		class value_compare : ft::binary_function<value_type, value_type, bool>
			{
				friend class map<key_type, mapped_type, key_compare, Alloc>;
				
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
				
				public:
					bool operator() (const value_type& x, const value_type& y) const
					{ return (comp(x.first, y.first)); }
			};
	private:
		typedef binary_tree<pair <const Key, T> , value_compare, Alloc>  tree_type;
	public:
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename allocator_type::size_type				size_type;
		typedef typename allocator_type::difference_type		difference_type;
		typedef typename tree_type::iterator					iterator;
        typedef typename tree_type::const_iterator				const_iterator;
        typedef reverse_iterator<const_iterator>				const_reverse_iterator;
        typedef reverse_iterator<iterator>						reverse_iterator;


		
	
		

		explicit map(const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) : _base(value_compare(comp), alloc), _comp(comp){}
		template <class InputIterator>
  		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
       			const allocator_type& alloc = allocator_type());
		map(const map& x);
		map&    operator=(const map& x);
		~map(){}

		iterator                begin();
        const_iterator          begin() const;
        iterator                end();
        const_iterator          end() const;
        reverse_iterator        rbegin();
        const_reverse_iterator  rbegin() const;
        reverse_iterator        rend();
        const_reverse_iterator  rend() const;

		pair<iterator, bool>    insert(const value_type& val);
		iterator                insert(iterator position, const value_type& val);
        template <class InputIterator>
        void                    insert(InputIterator first, InputIterator last);
		bool empty() const {return _base.size() == 0;}
		size_type   size() const {return _base.size();}
        size_type   max_size() const {return _base.get_alloc_node().max_size();}
		mapped_type& operator[](const key_type& k);
     	void erase(iterator position);
		size_type erase(const key_type& k);
		void erase(iterator first, iterator last);
		iterator find(const key_type& k);
		const_iterator find(const key_type& k) const;
		void swap(map& x);
		void clear();
		key_compare key_comp() const;
		value_compare value_comp() const;
		size_type count(const key_type& k) const;
		iterator                                lower_bound(const key_type&);
        const_iterator                          lower_bound(const key_type&) const;
        iterator                                upper_bound(const key_type&);
        const_iterator                          upper_bound(const key_type&) const;
        pair<iterator, iterator>                equal_range(const key_type &k);
        pair<const_iterator, const_iterator>    equal_range(const key_type &k) const;
		allocator_type get_allocator() const {return _base.get_allocator();}
		
	private:
		tree_type 	  _base;
		key_compare   _comp;

	};
	template <class Key, class T, class Compare, class Alloc>
    template <class InputIterator>
    map<Key, T, Compare, Alloc>::map(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc):  _base(value_compare(comp), alloc), _comp(comp)
    {
        insert(first, last);
    }

    template <class Key, class T, class Compare, class Alloc>
    map<Key, T, Compare, Alloc>::map(const map& x) : _base(value_compare(x._comp), x.get_allocator()), _comp(x._comp)
    {
        *this = x; 
    }
	
	template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::iterator        map<Key, T, Compare, Alloc>::begin()
    {
        return (_base.begin());
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_iterator  map<Key, T, Compare, Alloc>::begin() const
    {
        return (_base.begin());
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::iterator        map<Key, T, Compare, Alloc>::end()
    {
        return (_base.end());
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_iterator  map<Key, T, Compare, Alloc>::end() const
    {
        return (_base.end());
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::reverse_iterator        map<Key, T, Compare, Alloc>::rbegin()
    {
        return (reverse_iterator(end()));
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_reverse_iterator  map<Key, T, Compare, Alloc>::rbegin() const
    {
        return (const_reverse_iterator(end()));
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::reverse_iterator        map<Key, T, Compare, Alloc>::rend()
    {
        return (reverse_iterator(begin()));
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_reverse_iterator  map<Key, T, Compare, Alloc>::rend() const
    {
        return (const_reverse_iterator(begin()));
    }

	template <class Key, class T, class Compare, class Alloc>
    pair<typename map<Key, T, Compare, Alloc>::iterator, bool>    map<Key, T, Compare, Alloc>::insert(const value_type& val)
    {
        pair<iterator, bool>    pair_result;
        typename tree_type::node_type   *new_node = _base.get_alloc_node().allocate(1);
        _base.get_alloc_node().construct(new_node, typename tree_type::node_type(val));
        _base.get_allocator().construct(&new_node->value, val);
        pair_result = _base.insert_node(new_node);
        if (!pair_result.second)
            _base.dealloc_node(new_node);
        return (pair_result);
    }

	template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::iterator    map<Key, T, Compare, Alloc>::insert(iterator position, const value_type& val)
    {
        pair<iterator, bool>    pair_result;
        typename tree_type::node_type   *new_node = _base.get_alloc_node().allocate(1);
        _base.get_alloc_node().construct(new_node, typename tree_type::node_type(val));
        _base.get_allocator().construct(&new_node->value, val);
        pair_result = _base.insert_node(position, new_node);
        if (!pair_result.second)
            _base.dealloc_node(new_node);
        return (pair_result.first);
    }

    template <class Key, class T, class Compare, class Alloc>
    template <class InputIterator>
    void    map<Key, T, Compare, Alloc>::insert(InputIterator first, InputIterator last)
    {
        for (InputIterator it = first; it != last; ++it)
            insert(*it);
    }
	template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::mapped_type&    map<Key, T, Compare, Alloc>::operator[](const key_type& k)
    {
        return ((*((insert(ft::make_pair(k, mapped_type()))).first)).second);
    }

	template <class Key, class T, class Compare, class Alloc>
    void            map<Key, T, Compare, Alloc>::erase(iterator position)
    {
        _base.erase(position);
    }
    
    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::size_type       map<Key, T, Compare, Alloc>::erase(const key_type& k)
    {
        iterator pos = find(k);
        if (pos != end())
        {
            erase(pos);
            return (1);
        }
        return (0);
    }

    
    template <class Key, class T, class Compare, class Alloc>
    void            map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
    {
        for (iterator it = first; it != last;)
            erase(it++);
    }

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::find(const key_type& k)
	{
		iterator pos = begin();
		while (pos != end())
		{
			if (pos->first == k)
				break;
			++pos;
		}
		return pos;
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::find(const key_type& k) const
	{
		iterator pos = begin();
		while (pos != end())
		{
			if (pos->first == k)
				break;
			++pos;
		}
		return pos;
	}
	
	template <class Key, class T, class Compare, class Alloc>
	void map<Key, T, Compare, Alloc>::swap(map& x)
	{
		_base.swap(x._base);
	}

	template <class Key, class T, class Compare, class Alloc>
	void map<Key, T, Compare, Alloc>::clear()
	{
		_base.clear();
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::key_compare map<Key, T, Compare, Alloc>::key_comp() const
	{
		return _comp;
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::value_compare map<Key, T, Compare, Alloc>::value_comp() const
	{
		return value_compare(_comp);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::count(const key_type& k) const
	{
		if(_base.find_node(ft::make_pair(k, mapped_type())))
            return (1);
        return (0);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::lower_bound (const key_type& k)
	{
		return _base.lower_bound(ft::make_pair(k, mapped_type()));
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::lower_bound (const key_type& k) const
	{
		return _base.upper_bound(ft::make_pair(k, mapped_type()));
	}

	template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::iterator          map<Key, T, Compare, Alloc>::upper_bound(const key_type& k)
    {
        return (_base.upper_bound(ft::make_pair(k, mapped_type())));
    }
        
    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_iterator    map<Key, T, Compare, Alloc>::upper_bound(const key_type& k) const
    {
        return (_base.upper_bound(ft::make_pair(k, mapped_type())));
    }
        
    template <class Key, class T, class Compare, class Alloc>
    pair<typename map<Key, T, Compare, Alloc>::iterator,
    typename map<Key, T, Compare, Alloc>::iterator>         map<Key, T, Compare, Alloc>::equal_range(const key_type &k)
    {
        return (_base.equal_range(ft::make_pair(k, mapped_type())));
    }
        
    template <class Key, class T, class Compare, class Alloc>
    pair<typename map<Key, T, Compare, Alloc>::const_iterator,
    typename map<Key, T, Compare, Alloc>::const_iterator>    map<Key, T, Compare, Alloc>::equal_range(const key_type &k) const
    {
        return (_base.equal_range(ft::make_pair(k, mapped_type())));
    }
	
	template <class Key, class T, class Compare, class Alloc>
    map<Key, T, Compare, Alloc>&    map<Key, T, Compare, Alloc>::operator=(const map& x)
    {
        if (this == &x)
            return (*this);
        clear();
        insert(x.begin(), x.end());
        return (*this);
    }

	template <class Key, class T, class Compare, class Alloc>
    bool    operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        typename map<Key, T, Compare, Alloc>::const_iterator  t_last = lhs.end();
        for (typename map<Key, T, Compare, Alloc>::const_iterator i = lhs.begin(), j = rhs.begin(); i != t_last; ++i, ++j)
            if (*i != *j)
                return (false);
        return (true);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool    operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool    operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        typename map<Key, T, Compare, Alloc>::const_iterator   t_last_l = lhs.end();
        typename map<Key, T, Compare, Alloc>::const_iterator   t_last_r = rhs.end();
        typename map<Key, T, Compare, Alloc>::const_iterator   j = rhs.begin();
        for (typename map<Key, T, Compare, Alloc>::const_iterator i = lhs.begin(); i != t_last_l; ++i, ++j)
            if (j == t_last_r || *j < *i)
                return (false);
            else if (*i < *j)
                return (true);
        return (j != t_last_r);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool    operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        return (!(rhs < lhs));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool    operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool    operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }
}

#endif