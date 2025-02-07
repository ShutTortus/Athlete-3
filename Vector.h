/**
 * @file Vector.h
 * @author Daniel O'Neill
 * @date 9/25/2024
 * @section 1003
 *
 * @note I pledge my word of honor that I have abided by the
 * CSN Academic Integrity Policy while completing this assignment.
 */

// Instructions:
// - Copy this starter file from the /home/shared/cs202/pa12/ directory.
// - Complete the required documentation header at the top of the file.
// - Read and understand each of the function prototypes provided, then...
// - Define each of the functions prototyped below.
//   - One-line functions may be inlined.
//   - All other functions should be defined in the implementation file.
// - Do not use `operator[]` to access array elements. Use only pointers.
// - Remove these instructions before submission.

/**
 * @class Vector
 * @brief Vector is a sequence container that encapsulates dynamic size arrays.
 *
 * The elements are stored contiguously, which means that elements can be
 * accessed using offsets to regular pointers to elements. This means that a
 * pointer to an element of a vector may be passed to any function that
 * expects a pointer to an element of an array.
 *
 * The storage of the vector is handled automatically, being expanded as
 * needed. Vectors usually occupy more space than static arrays, because more
 * memory is allocated to handle future growth. This way a vector does not
 * need to reallocate each time an element is inserted, but only when the
 * additional memory is exhausted. The total amount of allocated memory can
 * be queried using capacity() function.
 *
 * @note Partial custom implementation of std::vector<int>.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>


class Vector {
public:
    // Public aliases
    using value_type      = int;
    using size_type       = std::size_t;
    using reference       = value_type&;
    using const_reference = const value_type&;
    using pointer         = value_type*;
    using const_pointer   = const value_type*;

    /* Constructors and Destructor */

    /**
     * Constructs the container with count copies of elements with value value.
     * @param count The number of elements to be constructed in the vector
     * (default zero).
     * @param value The value to initialize each element with (default value).
     */
    Vector(size_type count = 0, const value_type& value = value_type{});

    /**
     * Copy constructor. Constructs the container with the copy of the contents
     * of other.
     * @param other Another Vector object to copy from.
     */
    Vector(const Vector& other);

    /**
     * Destructs the vector. The used storage is deallocated.
     */
    virtual ~Vector();

    /* Element Access */

    /**
     * Returns a reference to the element at specified location pos, with
     * bounds checking.
     * @pre pos is within the range of the container (i.e., pos < size())
     * @assert pos is within the range of the container.
     * @param pos The position of the element to access.
     * @return Reference to the element at the specified position.
     */
    reference at(size_type pos);
    const_reference at(size_type pos) const;

    /**
     * Returns a reference to the first element in the container.
     * @note Calling front on an empty container causes undefined behavior.
     * @return Reference to the first element.
     */
    reference front();
    const_reference front() const;

    /**
     * Returns a reference to the last element in the container.
     * @note Calling back on an empty container causes undefined behavior.
     * @return Reference to the last element.
     */
    reference back();
    const_reference back() const;

    /**
     * Returns a pointer to the first element of the vector.
     * If the vector is empty, the returned pointer will be equal to end().
     * @return Pointer to the first element.
     */
    pointer begin() {return m_data;}
    const_pointer begin() const {return m_data;}

    /**
     * Returns an iterator to the element following the last element of
     * the vector.
     * @return Pointer to one past the last element.
     */
    pointer end() {return m_data + m_count;}
    const_pointer end() const {return m_data + m_count;}

    /* Capacity */

    /**
     * Checks if the container has no elements, i.e. whether begin() == end().
     * @return True if the container is empty, otherwise false.
     */
    bool empty() const;

    /**
     * Returns the number of elements in the container, i.e. value of m_count.
     * @return The number of elements in the container.
     */
    size_type size() const {return m_count;}

    /**
     * Returns the number of elements that the container has currently
     * allocated space for, i.e., value of m_capacity.
     * @return The current capacity of the container.
     */
    size_type capacity() const {return m_capacity;}

    /* Modifiers */

    /**
     * Erases all elements from the container. After this call, size()
     * returns zero.
     */
    void clear() {m_count = 0;}

    /**
     * Appends the given element value to the end of the container.
     * If after the operation the new size() is greater than old capacity(),
     * a reallocation takes place, in which case all pointers (including the
     * end() pointer) and all references to the elements are invalidated.
     * Otherwise only the end() iterator is invalidated.
     *
     * @post The element value is added to the end of the container. If the
     * operation causes the vector to resize (i.e., if the new size exceeds
     * the current capacity), memory may be reallocated, and pointers
     * to elements (e.g., begin()) may change.
     *
     * @param value The value to be appended to the end of the container.
     */
    void push_back(const value_type& value);

    /**
     * Removes the last element of the container. Calling pop_back on an empty
     * container results in undefined behavior. Pointers (including the end()
     * pointer) and references to the last element are invalidated.
     *
     * @post The last element of the container is removed. If the vector was
     * not empty before this operation, the size of the container (size()) is
     * reduced by one. The capacity of the vector remains unchanged, and the
     * memory allocated for the removed element is not freed.
     */
    void pop_back();

    /* Do not modify: leave as is for pa12. */
    Vector& operator=(const Vector&) = delete;

private:
    pointer   m_data;      ///< Pointer to the dynamic array holding elements
    size_type m_capacity;  ///< Current capacity of the dynamic array
    size_type m_count;     ///< Number of active elements in the array
};

// ----------------------------------------------------------------------------

/* Non-members */

/**
 * Compares two vector objects for equality, i.e., if both the size of lhs
 * and rhs are equal and each element in lhs has equivalent value in rhs at
 * the same position.
 * @param lhs The left-hand side Vector object for comparison.
 * @param rhs The right-hand side Vector object for comparison.
 * @return True if the vectors are equal, otherwise false.
 */
bool equal(const Vector& lhs, const Vector& rhs);

#endif /* VECTOR_H */
/* EOF */

