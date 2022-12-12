#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "../vectorIterator/vectorIterator.hpp"

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {

		public:

		//	CONSTRUCTORS, ASSIGN OPERATOR AND DESTRUCTOR

			vector( void ) : _myVector(nullptr), _availableData(0), _usedData(0) {

				this->_newAlloc(2);		
			}

			vector( vector const & src ) { *this = src; }

			vector & operator=( vector const & rhs );

			~vector( void ) { 

				this->_myAllocator.deallocate(this->_myVector, this->_availableData);
			}

		//	TYPEDEFS

			typedef T					value_type;
			typedef Alloc				allocator_type;

			typedef value_type&			reference;
			typedef const value_type&	const_reference;

			typedef value_type*			pointer;
			typedef const value_type*	const_pointer;

			typedef ft::vectorIterator<T>	iterator;
			typedef const iterator			const_iterator;

			typedef	size_t	size_type;


		//	||-----PUBLIC FUNCTIONS-----||


			iterator		begin() const { return iterator(this->_myVector); }
			iterator		end() const { return iterator( this->_myVector + this->_usedData); }

			// const_iterator	cbegin() const { return this->_adress; }
			// const_iterator	cend() const { return this->_adress + this->_len; }

			//	Capacity

			size_type	size() const { return this->_usedData; }
			size_type	max_size() const;
			void 		resize( size_type n, value_type val = value_type() );
			size_type	capacity() const { return this->_availableData; }
			bool		empty() const {

				if (this->_usedData < 1)
					return true;
				return false;
			}
			void		reserve( size_type n );
			void		shrink_to_fit();


			//	Elemement acces

			reference		operator[]( size_type n );
			const_reference	operator[]( size_type n ) const;

			reference 		at( size_type n );
			const_reference	at( size_type n ) const;

			reference		front();
			const_reference	front() const;

			reference		back();
			const_reference	back() const;

			pointer			data();
			const_pointer	data() const;


			//	Modifiers	

			template <class InputIterator>
			void	assign( InputIterator first, InputIterator last );
			void 	assign( size_type n, const_reference val );

			void	push_back( const_reference val ) {

				if (this->_availableData == this->_usedData)
					_newAlloc(this->_availableData + 1);

				this->_myVector[this->_usedData] = val;
				this->_usedData += 1;
			}

			void	pop_back() {

				if (this->_usedData > 0) {

					this->_myVector[ this->_usedData ].~T();
					this->_usedData -=1;
				}
			}

			void	swap( vector& x );
			void	clear();

			template <class InputIterator>
			void		insert( iterator position, InputIterator first, InputIterator last );
			iterator	insert( iterator position, const_reference val );
    		void		insert( iterator position, size_type n, const_reference val );

			iterator	erase( iterator position );
			iterator	erase( iterator first, iterator last );

			// template <class... Args>
			// iterator emplace( const_iterator position, Args&&... args );
			// template <class... Args>
			// void		emplace_back( Args&&... args );

			//	Allocator

			allocator_type	get_allocator() const { return this->_myAllocator; }


		private:

			T*				_myVector;
			allocator_type	_myAllocator;

			size_t	_availableData;
			size_t	_usedData;

			//	||-----PRIVATE FUNCTIONS-----||

			void	_newAlloc( size_t newSize ) {

				if (newSize > this->_availableData) {

					T*	newVector = this->_myAllocator.allocate( newSize / 2 + newSize );

					for (size_t i = 0; i < this->_usedData; ++i) {

						newVector[i] = this->_myVector[i];
					}

					if (this->_availableData > 0)
						this->_myAllocator.deallocate( this->_myVector, this->_availableData );

					this->_myVector = newVector;
					this->_availableData = newSize;
				}
			}

			// void	_deAlloc( size_t newSize ) {

			// 	if (newSize < this->_availableData) {

			// 		if (this->_availableData > 0)
			// 			this->_myAllocator.deallocate( this->_myVector, this->_availableData );

			// 		T*	newVector = this->_myAllocator.allocate( (newSize * 2) / 3 );

			// 		for (int i = 0, i < this->_usedData, ++i) {

			// 			newVector[i] = this->_myVector[i];
			// 		}
					
			// 		this->myVector = newVector;
			// 		this->_availableData = newSize;
			// 	}
			// }

	};
}


//	Non-member function overloads

template <class T, class Alloc>
bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs );

template <class T, class Alloc>
bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs );

template <class T, class Alloc>
bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs );

template <class T, class Alloc>
bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs );

template <class T, class Alloc>
bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs );

template <class T, class Alloc>
bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs );

template <class T, class Alloc>
void swap ( ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y );

#endif
