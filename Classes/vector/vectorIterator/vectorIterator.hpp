#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

# include <iostream>
# define PRINT(x) std::cout << x << std::endl;

namespace ft {

	template <class Type>
	class vectorIterator {

		public:

			vectorIterator() {}
			vectorIterator( Type* adress ) : _adress(adress) {}
			vectorIterator( vectorIterator const & src ) { *this = src; }
			vectorIterator & operator=( vectorIterator const & rhs ) {

				this->_adress = rhs._adress;
				this->_inc = rhs._inc;
				this->_len = rhs._len;

				return *this;
			}
			~vectorIterator( void ) {}

			typedef Type				value_type;
			typedef	value_type*			pointer;
			typedef const value_type*	const_pointer;

			vectorIterator &	operator++() { this->_adress += 1; return *this; }
			vectorIterator		operator++( int ) { vectorIterator	newInstance = *this; operator++(); return newInstance; }

			vectorIterator &	operator--() { this->_adress -= 1; return *this; }
			vectorIterator		operator--( int ) { vectorIterator	newInstance = *this; operator--(); return newInstance; }

			vectorIterator & operator[]( int const index ) const { this->_adress += index; return *this; }

			bool	operator!=( vectorIterator const & compare ) {

				if (this->_adress != compare._adress)
					return true;
				return false;
			}

			bool	operator==( vectorIterator const & compare ) {

				if (this->_adress == compare._adress)
					return true;
				return false;
			}

			Type & operator*() const { return *(this->_adress); }

		private:

			pointer	_adress;
			size_t	_inc;
			size_t	_len;
	};
}

#endif
