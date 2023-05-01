/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:55:41 by utygett           #+#    #+#             */
/*   Updated: 2022/05/09 16:59:20 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <memory>
#include <iterator>
#include "reverse_iterator.hpp"
// using namespace std;
namespace ft
{

	template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
    
        typedef T                                   value_type;
        typedef Alloc                               allocator_type;
        typedef std::size_t                         size_type;
        typedef std::ptrdiff_t                      difference_type;
        typedef value_type&                         reference;
        typedef const value_type&                   const_reference;
        typedef typename Alloc::pointer             pointer;
        typedef typename Alloc::const_pointer       const_pointer;
	private:
		pointer         first;
        pointer         last;
        size_t          alloc_size;
        size_t          alloc_cap;
        allocator_type  alloc_t;
	public:
		/*constructor*/
		explicit vector (const allocator_type& alloc = allocator_type());
		/*fill constructor*/
		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
		/*range constructor*/
		 template <class InputIterator>
                    vector(InputIterator first, InputIterator last, 
                           const allocator_type &alloc = allocator_type(),
						   typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0);
		/*copy constructor*/
		vector (const vector& x);
		/*destructor*/
		~vector();
		
		vector& operator= (const vector& x);
        allocator_type  get_allocator() const { return alloc_t;}
		/*Iterators*/
		class const_iterator;

        class iterator
        {
        public:
			typedef T							value_type;
			typedef	T*							pointer;
			typedef T&							reference;
			typedef std::ptrdiff_t				difference_type;
			typedef random_access_iterator_tag  iterator_category;
		private:
            value_type  *current_ptr;
		public:
			iterator() : current_ptr(NULL){}
			iterator(value_type *ptr) : current_ptr(ptr) {}
			iterator(const iterator &iter) : current_ptr(iter.current_ptr){}
			iterator &	operator=(const iterator& for_assign){
				if (this == &for_assign)
					return (*this);
				current_ptr = for_assign.current_ptr;
				return (*this);
			}
			bool	operator==(const iterator & other) const {return current_ptr == other.current_ptr;}
			bool	operator==(const const_iterator & other) const {return current_ptr == other.current_ptr;}
			bool	operator!=(const iterator & other) const {return !(*this == other);}
			bool	operator!=(const const_iterator & other) const {return !(*this == other);}
			reference	operator*() const {return *current_ptr;}
			pointer		operator->() const {return current_ptr;}
			reference	operator[](difference_type n) const {return *(current_ptr + n);}
			iterator &	operator++() {++current_ptr; return *this;}
			iterator	operator++(int) {
				iterator temp = *this;
				++(*this);
				return temp;
			}
			iterator &	operator--(){--current_ptr; return *this;}
            iterator	operator--(int){
				iterator temp = *this;
				--(*this);
				return temp;
			}
			iterator	operator+(difference_type n) const {
				iterator temp = *this;
				temp.current_ptr += n;
				return temp;
			}
			iterator	operator-(difference_type n) const {
				iterator temp = *this;
				temp.current_ptr -= n;
				return temp;
			}
			difference_type	operator-(const iterator & other) {
				return static_cast<difference_type>(this->current_ptr - other.current_ptr);
			}
			difference_type	operator-(const const_iterator & other) {
				return static_cast<difference_type>(this->current_ptr - other.current_ptr);
			}
			bool	operator<(const iterator other) const {return current_ptr < other.current_ptr;}
			bool	operator<(const const_iterator other) const {return current_ptr < other.current_ptr;}
			bool	operator<=(const iterator & other) const {return !(other < *this);}
			bool	operator<=(const const_iterator & other) const {return !(other < *this);}
			bool	operator>(const iterator & other) const {return current_ptr > other.current_ptr;}
			bool	operator>(const const_iterator & other) const {return current_ptr > other.current_ptr;}
            bool	operator>=(const iterator & other) const {return !(other > *this);}
            bool	operator>=(const const_iterator & other) const {return !(other > *this);}
			iterator & operator+=(difference_type n) {current_ptr += n; return *this;}
			iterator & operator-=(difference_type n) {current_ptr -= n; return *this;}
            friend iterator operator+(difference_type n, const iterator& it){return (it + n);}

		};
		
		class const_iterator
        {
		private:
            value_type  *current_ptr;
        public:
			typedef T							value_type;
			typedef	T*							pointer;
			typedef T&							reference;
			typedef std::ptrdiff_t				difference_type;
			typedef random_access_iterator_tag  iterator_category;
			
			const_iterator() : current_ptr(NULL){}
			const_iterator(value_type *ptr) : current_ptr(ptr) {}
			const_iterator(const const_iterator &iter) : current_ptr(iter.current_ptr){}
			const_iterator(const iterator &iter) : current_ptr(iter.operator->()){}
			const_iterator &	operator=(const const_iterator& for_assign){
				if (this == &for_assign)
					return (*this);
				current_ptr = for_assign.current_ptr;
				return (*this);
			}
			bool	operator==(const iterator & other) const {return current_ptr == other.current_ptr;}
			bool	operator==(const const_iterator & other) const {return current_ptr == other.current_ptr;}
			bool	operator!=(const iterator & other) const {return !(*this == other);}
			bool	operator!=(const const_iterator & other) const {return !(*this == other);}
			reference	operator*() const {return *current_ptr;}
			pointer		operator->() const {return current_ptr;}
			reference	operator[](difference_type n) const {return *(current_ptr + n);}
			const_iterator &	operator++() {++current_ptr; return *this;}
			const_iterator	operator++(int) {
				const_iterator temp = *this;
				++(*this);
				return temp;
			}
			const_iterator &	operator--(){--current_ptr; return *this;}
            const_iterator	operator--(int){
				const_iterator temp = *this;
				--(*this);
				return temp;
			}
			const_iterator	operator+(difference_type n) const {
				const_iterator temp = *this;
				temp.current_ptr += n;
				return temp;
			}
			const_iterator	operator-(difference_type n) const {
				const_iterator temp = *this;
				temp.current_ptr -= n;
				return temp;
			}
			difference_type	operator-(const iterator & other) {
				return static_cast<difference_type>(this->current_ptr - other.current_ptr);
			}
			difference_type	operator-(const const_iterator & other) {
				return static_cast<difference_type>(this->current_ptr - other.current_ptr);
			}
			bool	operator<(const iterator other) const {return current_ptr < other.current_ptr;}
			bool	operator<(const const_iterator other) const {return current_ptr < other.current_ptr;}
			bool	operator<=(const iterator & other) const {return !(other < *this);}
			bool	operator<=(const const_iterator & other) const {return !(other < *this);}
			bool	operator>(const iterator & other) const {return current_ptr > other.current_ptr;}
			bool	operator>(const const_iterator & other) const {return current_ptr > other.current_ptr;}
            bool	operator>=(const iterator & other) const {return !(other > *this);}
            bool	operator>=(const const_iterator & other) const {return !(other > *this);}
			const_iterator & operator+=(difference_type n) {current_ptr += n; return *this;}
			const_iterator & operator-=(difference_type n) {current_ptr -= n; return *this;}
            friend const_iterator operator+(difference_type n, const const_iterator& it){return (it + n);}

		};
	public:
		/* Iterators*/
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		iterator		begin(){ return first;}
		iterator		end(){return last;}
		const_iterator	begin() const {return const_iterator(first);}
		const_iterator	end() const {return const_iterator(last);}
		reverse_iterator		rbegin(){return       reverse_iterator(end());}
		const_reverse_iterator	rbegin() const {return const_reverse_iterator(end());}
		reverse_iterator		rend(){return       reverse_iterator(begin());}
		const_reverse_iterator	rend() const {return const_reverse_iterator(begin());}
		/*Capacity*/
		size_type size() const {return static_cast<size_type>(last - first);}
		size_type max_size() const {return alloc_t.max_size();}
		size_type  capacity() const {return alloc_cap;}
		void resize (size_type n, value_type val = value_type());
		bool empty() const { return first == last;}
		void reserve (size_type n);
		/*Element access*/
		reference operator[] (size_type n) {return first[n];}
		const_reference operator[] (size_type n) const {return first[n];}
		reference at (size_type n);
		const_reference at (size_type n) const;
		reference front() {return *first;}
		const_reference front() const {return *first;}
		reference back() {return *(last - 1);}
		const_reference back() const {return *(last - 1);}
		/*Modifiers*/
		template <class InputIterator>
        	void    assign(InputIterator _first, InputIterator _last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0);
        void        assign(size_type n, const value_type &val);
		void push_back (const value_type& val);
		void swap (vector& x);
		void clear() {vector<T, Alloc>().swap(*this);}
		void pop_back();
		iterator insert (iterator position, const value_type& val);
    	void insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
            void    insert(iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0);
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);

	private:
		size_type	nextPowOf2(size_type);
		void        clear_range(pointer begin, size_t n);
		size_t 		realloc_copy(size_type new_size);
		void		take_back(const value_type& x) { push_back(x); }
	};
	
	template <class T, class Alloc>
	vector<T, Alloc>::vector(const Alloc & alloc)
	{
		first = NULL;
		last = NULL;
		alloc_size = 0;
		alloc_cap = 0;
		alloc_t = alloc;
	}

	template <class T, class Alloc>
    vector<T, Alloc>::vector(size_type n, const value_type &val, const allocator_type &alloc)
    {
        alloc_t = alloc;
		if(n > this->max_size())
			throw(std::length_error("vector"));
        alloc_size = n;
        alloc_cap = nextPowOf2(alloc_size);
        first = alloc_t.allocate(alloc_cap + 1);
        size_type i;
        for (i = 0; i < alloc_size; ++i)
            alloc_t.construct(first + i, val);
        last = first + i;
    }

template <class T, class Alloc>
    template <class InputIterator>
    vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type &alloc,
                                typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type*)
    {
        alloc_size = 0;
        alloc_t = alloc;
        for (InputIterator i = first; i != last; ++i)
            ++alloc_size;
        alloc_cap = nextPowOf2(alloc_size);
        this->first = alloc_t.allocate(alloc_cap + 1);
        size_type j = 0;
        for (InputIterator i = first; i != last; ++i)
            alloc_t.construct(this->first + j++, *i);
        this->last = this->first + j;
    }

    template <class T, class Alloc>
    vector<T, Alloc>::vector(const vector& x)
    {
        alloc_t = x.get_allocator();
        alloc_size = 0;
        alloc_cap = 0;
        *this = x;
    }

	template <class T, class Alloc>
	vector<T, Alloc>::~vector()
	{
		clear_range(first, alloc_size);
        alloc_t.deallocate(first, alloc_cap + 1);
	}
	
	template <class T, class Alloc>
    void        vector<T, Alloc>::resize(size_type n, value_type val)
	{
		if (n < alloc_size)
			clear_range(first + n, alloc_size - n);
		else if (n > alloc_cap) {
			for (size_type i = realloc_copy(n); i < n; ++i)
				alloc_t.construct(first + i, val);
		} 
		else if (n > alloc_size) {
			for (size_type i = alloc_size; i < n; ++i)
				alloc_t.construct(first + i, val);
		}
		alloc_size = n;
		last = first + n;
	}

	template <class T, class Alloc>
    void    vector<T, Alloc>::reserve(size_type n)
	{
		if (n > max_size())
			throw(std::length_error(" allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size"));
		if (n > alloc_cap)
			realloc_copy(n);
	}
	
	template <class T, class Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n)
    {
        if (n >= alloc_size)
            throw(std::out_of_range("index out of range"));
        return (first[n]);
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const
    {
        if (n >= alloc_size)
            throw(std::out_of_range("index out of range"));
        return (first[n]);
    }

	template <class T, class Alloc>
    template <class InputIterator>
    void    vector<T, Alloc>::assign(InputIterator _first, InputIterator _last,
                                        typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type*)
	{
		clear();
		for(; _first != _last; ++_first)
			take_back(*_first);
	}

	template <class T, class Alloc>
    void    vector<T, Alloc>::assign(size_type n, const value_type &val)
    {
        if (n > alloc_size)
        {
            clear_range(first, alloc_size);
            alloc_t.deallocate(first, alloc_cap + 1);
            alloc_cap = nextPowOf2(n);
            first = alloc_t.allocate(alloc_cap + 1);
        }
        alloc_size = n;
        for (size_type i = 0; i < alloc_size; ++i)
            alloc_t.construct(first + i, val);
        last = first + alloc_size;
    }

	template <class T, class Alloc>
    void    vector<T, Alloc>::push_back(const value_type &val)
    {
        if (alloc_size + 1 > alloc_cap)
            realloc_copy(alloc_size + 1);
        alloc_t.construct(first + alloc_size, val);
        ++alloc_size;
        last = first + alloc_size;
    }
	
	template <class T, class Alloc>
    void    vector<T, Alloc>::swap(vector &x)
	{
		pointer temp_first = x.first;
		pointer temp_last = x.last;
		size_t	temp_alloc_size = x.alloc_size;
		size_t	temp_alloc_cap = x.alloc_cap;

		x.first = first;
		x.last = last;
		x.alloc_size = alloc_size;
		x.alloc_cap = alloc_cap;

		first = temp_first;
		last = temp_last;
		alloc_size = temp_alloc_size;
		alloc_cap = temp_alloc_cap;
	}

	template <class T, class Alloc>
    void    vector<T, Alloc>::pop_back()
    {
        if (!alloc_size)
            return ;
        --alloc_size;
        last = first + alloc_size;
        alloc_t.destroy(last);
    }

	template <class T, class Alloc>
    typename vector<T, Alloc>::iterator    vector<T, Alloc>::insert(iterator position, const value_type & val)
	{
		size_type	pos = position - begin();
		if (alloc_size + 1 > alloc_cap)
			realloc_copy(alloc_size + 1);
		position = begin() + pos;
		for(iterator i = end(); i >= position; --i)
			alloc_t.construct(&(*(i + 1)), *i);
		alloc_t.construct(&(*position), val);
		++alloc_size;
		last = first + alloc_size;
		return(position);
	}

	template <class T, class Alloc>
    void        vector<T, Alloc>::insert(iterator position, size_type n, const value_type & val)
	{
		size_type	pos = position - begin();
		if (alloc_size + n > alloc_cap)
			realloc_copy(alloc_size + n);
		position = begin() + pos;
		for (iterator i = end(); i >= position; --i)
			alloc_t.construct(&(*(i + n)), *i);
		for (size_type  i =0; i < n; ++i)
			alloc_t.construct(&(*(position + i)), val);
		alloc_size += n;
		last = first + alloc_size;
	}
    
	
	template <class T, class Alloc>
    template <class InputIterator>
    void        vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last,
                                            typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type*)
    {
        size_type n = 0;
        for (InputIterator i = first; i != last; ++i)
            ++n;
        size_type  pos_num = position - begin();
        if (alloc_size + n > alloc_cap)
            realloc_copy(alloc_size + n);
        position = begin() + pos_num;
        for (iterator i = end(); i >= position; --i)
            alloc_t.construct(&(*(i + n)), *i);
        size_type j = 0;
		for (InputIterator i = first; i != last; ++i, ++j)
		{
			try {
			alloc_t.construct(&(*(position + j)), *i);
			}
			catch(...){
				clear_range(&(*position), j);
				this->last = this->first + alloc_size;
				throw;
			}
		}
        alloc_size += n;
        this->last = this->first + alloc_size;
    }

	template <class T, class Alloc>
    typename vector<T, Alloc>::iterator    vector<T, Alloc>::erase(iterator position)
	{
		if (!alloc_size)
			return (position);
		iterator temp_last = end();
		for (iterator i = (position + 1); i < temp_last; ++i)
			alloc_t.construct(&(* (i - 1)), *i);
		--alloc_size;
		last = first + alloc_size;
		return position;		
	}

    template <class T, class Alloc>
    typename vector<T, Alloc>::iterator    vector<T, Alloc>::erase(iterator first, iterator last)
	{
		if (!alloc_size)
			return first;
		size_type n = last - first;
		iterator temp_last = end();
		for(iterator i = last; i < temp_last; ++i)
			alloc_t.construct(&(*(i - n)), *i);
		alloc_size -= n;
		this->last = this->first + alloc_size;
		return first;
	}

	template <class T, class Alloc>
    vector<T, Alloc>  &vector<T, Alloc>::operator=(const vector& x)
	{
		if (this == &x)
            return (*this);
        if (alloc_cap < x.size() && alloc_cap) {
            clear_range(first, alloc_size);
            alloc_t.deallocate(first, alloc_cap + 1);
            alloc_cap = x.capacity();
            first = alloc_t.allocate(alloc_cap + 1);
        } 
		else if (!alloc_cap) {
            alloc_cap = x.capacity();
            first = alloc_t.allocate(alloc_cap + 1);
        }
        alloc_size = x.size();
        size_type j = 0;
        const_iterator    t_last = x.end();
        for (const_iterator i = x.begin(); i != t_last; ++i, ++j)
            alloc_t.construct(first + j, *i);
        last = first + j;
        return (*this);
	}

	template <class T, class Alloc>
    bool    operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        typename vector<T, Alloc>::const_iterator  t_last = lhs.end();
        for (typename vector<T, Alloc>::const_iterator i = lhs.begin(), j = rhs.begin(); i != t_last; ++i, ++j)
            if (*i != *j)
                return (false);
        return (true);
    }

    template <class T, class Alloc>
    bool    operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }
    
    template <class T, class Alloc>
    bool    operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool    operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(rhs < lhs));
    }

    template <class T, class Alloc>
    bool    operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template <class T, class Alloc>
    bool    operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }

    template <class T, class Alloc>
    void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }
	
	template <class T, class Alloc>
    size_t  vector<T, Alloc>::nextPowOf2(size_type n)
    {
		
		--n;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
		++n;
		if (n > max_size())
			throw(std::length_error(" allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size"));
		return n;
    }

	template <class T, class Alloc>
	void	vector<T, Alloc>::clear_range(pointer begin, size_t n)
	{
		for (size_t i = 0; i < n; ++i)
			alloc_t.destroy(begin + i);
	}
	
	template <class T, class Alloc>
	size_t	vector<T, Alloc>::realloc_copy(size_type new_size){
		size_type	temp_cap = nextPowOf2(new_size);
		pointer		temp = alloc_t.allocate(temp_cap + 1);
		size_type	i = 0;
		if (first) {
			for (; i < alloc_size; ++i)
				alloc_t.construct(temp + i, first[i]);
			clear_range(first, alloc_size);
			alloc_t.deallocate(first, alloc_cap + 1);
		}
		first = temp;
		last = temp + i;
		alloc_cap = temp_cap;
		return i;
	}
}
#endif