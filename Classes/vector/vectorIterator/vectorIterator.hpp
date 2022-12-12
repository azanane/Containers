#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

# include <iostream>

namespace ft {

	template <class Type>
	class vectorIterator {

		public:

			vectorIterator( void ) {}
			vectorIterator( vectorIterator const & src ) { *this = src; }
			vectorIterator & operator=( vectorIterator const & rhs );
			~vectorIterator( void ) {}

			typedef Type				value_type;
			typedef	value_type*			pointer;
			typedef const value_type*	const_pointer;

			pointer	begin() const { return this->_adress; }
			pointer	end() const { return this->_adress + this->_len; }

			const_pointer	cbegin() const { return this->_adress; }
			const_pointer	cend() const { return this->_adress + this->_len; }

			vectorIterator &	operator++() { this->_adress += 1; return *this; }
			vectorIterator		operator++( int ) { vectorIterator	newInstance = *this; operator++(); return newInstance; }

			vectorIterator &	operator--() { this->_adress -= 1; return *this; }
			vectorIterator		operator--( int ) { vectorIterator	newInstance = *this; operator--(); return newInstance; }

			vectorIterator & operator[]( int const index ) const { this->_adress += index; return *this; }

		private:

			pointer	_adress;
			size_t	_inc;
			size_t	_len;
	};
}

#endif
