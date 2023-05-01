/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utygett <utygett@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:23:02 by utygett           #+#    #+#             */
/*   Updated: 2022/05/28 17:06:14 by utygett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{
	template <class It>
	struct iterator_traits
	{
		typedef typename It::difference_type	difference_type;
		typedef typename It::value_type			value_type;
		typedef typename It::pointer			pointer;
		typedef typename It::reference			reference;
		typedef typename It::iterator_category	iterator_category;
	};
	
	template <bool, class T = void> 
	struct  enable_if {};

	template <class T> 
	struct  enable_if<true, T> {typedef T type;};
	
	struct random_access_iterator_tag {};
	struct bidirectional_iterator_tag {};
	template<class T, T v>
    struct integral_constant
    {
        typedef T value_type;
        static const value_type value = v;
    };
	
	typedef struct integral_constant<bool, true> true_type;
    typedef struct integral_constant<bool, false> false_type;
	
	template<class T> struct is_integral_base : public false_type {};
    template<class T> struct is_integral_base<const T> : public is_integral_base<T> {};
    template<class T> struct is_integral_base<volatile const T> : public is_integral_base<T> {};
    template<class T> struct is_integral_base<volatile T> : public is_integral_base<T> {};
    template<> struct is_integral_base<bool> : public true_type {};
    template<> struct is_integral_base<char> : public true_type {};
	template<> struct is_integral_base<wchar_t> : public true_type {};
	template<> struct is_integral_base<char16_t> : public true_type {};
    template<> struct is_integral_base<signed char> : public true_type {};
    template<> struct is_integral_base<short int> : public true_type {};
    template<> struct is_integral_base<int> : public true_type {};
    template<> struct is_integral_base<long int> : public true_type {};
	template<> struct is_integral_base<long long int> : public true_type {};
    template<> struct is_integral_base<unsigned char> : public true_type {};
    template<> struct is_integral_base<unsigned short int> : public true_type {};
    template<> struct is_integral_base<unsigned int> : public true_type {};
    template<> struct is_integral_base<unsigned long int> : public true_type {};
	template<> struct is_integral_base<unsigned long long int> : public true_type {};

	template<class T>
    struct is_integral : public is_integral_base<T> {};

	template <class InputIterator1, class InputIterator2>
		bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1) return false;
			else if (*first1 < *first2) return true;
			++first1; ++first2;
		}
		return first2!=last2;
	}

	template<class InputIt1, class InputIt2, class Compare>
	inline bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2,
								Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, ++first2 ) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2>
		bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1) {
			if (!(*first1 == *first2)) 
				return false;
			++first1; ++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	inline bool equal ( InputIterator1 first1, InputIterator1 last1,
						InputIterator2 first2, BinaryPredicate pred )
	{
		while (first1 != last1) {
			if (!pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class Arg1, class Arg2, class Result>
	struct binary_function
	{
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};
    
    template <class T>
	struct less : binary_function<T, T, bool>
	{
		bool operator() (const T& x, const T& y) const { return (x < y); }
	};

	
	// template<class T, class Compare>
    // class value_compare
    // {
    // private:
    //     typedef T           value_type;
    //     typedef Compare     key_compare;
    // public:
    //     typedef bool        result_type;
    //     typedef value_type  first_argument_type;
    //     typedef value_type  second_argument_type;
                     
    //     value_compare(key_compare c) : comp(c) {};
    //     value_compare(const value_compare& other) : comp(other.comp) {};
    //     bool    operator()(const value_type& x, const value_type& y) const {return comp(x.first, y.first);}
    // protected:
    //     key_compare comp;
    // };

  
}


#endif