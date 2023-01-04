#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "../vectorIterator/vectorIterator.hpp"
# include "../../enableIf/enableIf.hpp"
# include "../../isIntegral/isIntegral.hpp"

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {

		public:

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
	

		//	CONSTRUCTORS, ASSIGN OPERATOR AND DESTRUCTOR

			vector( const allocator_type& alloc = allocator_type() ) : _myVector(nullptr), _availableData(0), _usedData(0) {

				this->_myAllocator = alloc;
				this->_availableData = 0;
				this->_usedData = 0;

				this->_newAlloc(2);		
			}

			vector( size_type n, const_reference val = value_type(), const allocator_type& alloc = allocator_type() ) {

				this->_myAllocator = alloc;
				this->_availableData = 0;
				this->_usedData = 0;

				for (size_type i = 0; i < n; ++i) {

					this->push_back(val);
				}
			}

			template <class InputIterator>
         	vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) {

				this->_myAllocator = alloc;
				this->_availableData = 0;
				this->_usedData = 0;

				for (iterator it = first; it != last; ++it) {

					this->push_back(*it);
				}
			}

			vector( vector const & src ) { 
				
				this->_availableData = 0;
				this->_usedData = 0;

				*this = src;
			}

			vector & operator=( vector const & rhs ) {

				assign(rhs.begin(), rhs.end());

				return *this;
			}

			~vector( void ) {

				this->_myAllocator.deallocate(this->_myVector, this->_availableData);
			}


		//	||-----PUBLIC FUNCTIONS-----||


			iterator		begin() const { return iterator(this->_myVector); }
			iterator		end() const { return iterator( this->_myVector + this->_usedData); }

			const_iterator	cbegin() const { return iterator(this->_myVector); }
			const_iterator	cend() const { return iterator( this->_myVector + this->_usedData); }

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


			//	Elemement acces

			reference		operator[]( size_type n ) { return this->_myVector[n]; }
			const_reference	operator[]( size_type n ) const { return this->_myVector[n]; }

			reference 		at( size_type n ) { return this->_myVector[n]; }
			const_reference	at( size_type n ) const { return this->_myVector[n]; }

			reference		front() { return this->_myVector[0]; }
			const_reference	front() const { return this->_myVector[0]; }

			reference		back() { return this->_myVector[this->_usedData - 1]; }
			const_reference	back() const { return this->_myVector[this->_usedData - 1]; }

			pointer			data() { return this->_myVector; }
			const_pointer	data() const { return this->_myVector; }


			//	Modifiers

			template <class InputIterator>
			void	assign( InputIterator first, InputIterator last ) {

				this->clear();

				for (; first != last; ++first) { 

					this->push_back(*first);
				}
			}

			void 	assign( size_type n, const_reference val ) {

				this->clear();

				for (size_type i = 0; i < n; ++i) {

					this->push_back(val);
				}
			}

			void	push_back( const_reference val ) {

				if (this->_availableData == this->_usedData)
					_newAlloc(this->_availableData + 1);
				
				this->_myVector[this->_usedData] = val;
				this->_usedData += 1;
			}

			void	pop_back() {

				if (this->_usedData > 0) {

					this->_myVector[ this->_usedData ].~T();
					this->_usedData -= 1;
				}
			}

			void	swap( vector& x ) {

				iterator		tmpBegin = this->begin();
				iterator		tmpEnd = this->end();

				allocator_type	tmpMyAllocator	= this->_myAllocator;
				size_t 			tmpAvailableData = this->_availableData;
				size_t	 		tmpUsedData = this->_usedData;

				
				x = temp;
			}

			void	clear() {

				size_type	used = this->_usedData;

				for (size_type i = 0; i < used; ++i) {

					this->pop_back();
				}
			}

			template <class InputIterator>
			void		insert( iterator position, InputIterator first, InputIterator last );
			iterator	insert( iterator position, const_reference val );
    		void		insert( iterator position, size_type n, const_reference val );

			iterator	erase( iterator position );
			iterator	erase( iterator first, iterator last );

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
