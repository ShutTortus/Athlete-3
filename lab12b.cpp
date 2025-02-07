/// @file lab12b.cpp
/// @author Daniel O'Neill
/// @date 9/18/2024
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief Unit tests for custom array manipulation functions using pointers
/// @note
///
/// Instructions:
/// - Copy this starter file from the /home/shared/cs202/lab12/ directory.
/// - Complete the required documentation header to the top of the file.
/// - Read and understand each of the function prototypes provided, then...
/// - Define each of the functions prototyped below. Function stubs provided.
/// - Do not use `operator[]` to access array elements. Use only pointers.
/// - Do not alter the unit tests.
/// - Compile normally, and test using valgrind.

#include <cstddef>
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

// ============================================================================

/** T Y P E   A L I A S E S **/

/// The typedefs in this code provide a layer of abstraction, enhancing
/// readability and maintainability. By using typedefs for common types like
/// pointers, references, and size types, the code becomes more flexible,
/// allowing for easy modifications to the underlying data types without
/// extensive changes throughout the codebase. This practice is particularly
/// useful for generic programming where changing a single typedef can adapt
/// the code to different data types or constraints.

typedef int               value_type;       // type of values stored in array
typedef size_t            size_type;        // represents sizes and counts
typedef value_type&       reference;        // reference to an element in array
typedef const value_type& const_reference;  // same, but constant references
typedef value_type*       pointer;          // point to elements within an array
typedef const value_type* const_pointer;    // same, but constant value_type

// ============================================================================

/** F U N C T I O N   P R O T O T Y P E S **/

/// @brief Counts the elements that are equal to value in the range [first,last)
/// using operator==.
/// @param first - A const_pointer to the first element in the range.
/// @param last - A const_pointer to the element following the last element
/// in the range.
/// @param value - The value to be compared with the elements in the range.
/// @return size_type representing the number of elements equal to value
/// in the range.
size_type count_values(const_pointer first, const_pointer last,
                       const_reference value);

/// @brief Returns a pointer to the first element in the range [first,last)
/// that is equal to value using operator==.
/// @param first - A pointer to the first element in the range.
/// @param last - A pointer to the element following the last element
/// in the range.
/// @param value - The value to be compared with the elements in the range.
/// @return A pointer to the first element in the range that is equal
/// to the value. If no such element is found, the function returns a pointer
/// to the element pointed to by `last`.
pointer find_value(pointer first, pointer last, const_reference value);
const_pointer find_value(const_pointer first, const_pointer last,
                         const_reference value);

/// @brief Copies all elements in the range [first,last), starting from first
/// and proceeding to last, to another range beginning at d_first.
/// @param first - A const_pointer to the first element in the range
/// to copy from.
/// @param last - A const_pointer to the element following the last element
/// in the range to copy from.
/// @param d_first - A pointer to the first element in the destination range.
/// @return pointer to the element in the destination range, one past
/// the last element copied.
pointer copy_range(const_pointer first, const_pointer last, pointer d_first);

/// @brief Assigns the given value to the elements in the range [first,last).
/// @param first - A pointer to the first element in the range.
/// @param last - A pointer to the element following the last element
/// in the range.
/// @param value - The value to assign to the elements in the range.
void fill_range(pointer first, pointer last, const_reference value);

/// @brief Returns true if the range [first1,last1) is equal to the range
/// [first2,last2), and false otherwise. Two ranges are considered equal if
/// they have the same number of elements and each corresponding pair
/// of elements from the two ranges are equal, as determined by operator==.
/// @param first1 - A const_pointer to the first element of the first range.
/// @param last1 - A const_pointer to the element following the last element
/// of the first range.
/// @param first2 - A const_pointer to the first element of the second range.
/// @param last2 - A const_pointer to the element following the last element
/// of the second range.
/// @return True if the length of the range [first1,last1) is equal
/// to the length of the range [first2,last2) and all corresponding elements
/// are equal. Returns false otherwise.
bool equal_range(const_pointer first1, const_pointer last1,
    const_pointer first2, const_pointer last2);

// ============================================================================

/** D E F I N E   Y O U R   F U N C T I O N S   H E R E **/

size_type count_values(const_pointer first, const_pointer last, const_reference value) {
    // TODO
    size_type size = 0;

    for (const_pointer i = first; i < last; i++)
    {
        if (*first == value)
        {
            size++;
        }
        first += 1;
    }
    return size;
}

pointer find_value(pointer first, pointer last, const_reference value) {
    // TODO
    size_type size = 0;
    pointer num;


    for (pointer i = first; i < last; i++)
    {
        if (size == 0 && *first == value)
        {
            size = 1;
            num = first;
        }
        first += 1;
    }
    if (size == 0)
    {
        num = last;
    }
    return num;
}

const_pointer find_value(const_pointer first, const_pointer last, const_reference value) {
    // TODO
    size_type size = 0;
    const_pointer num1 = first;
    const_pointer num2 = last;


    for (const_pointer i = first; i < last; i++)
    {
        if (size == 0 && *first == value)
        {
            size = 1;
            num1 = first;
        }
        first += 1;
    }
    if(size > 0)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}

pointer copy_range(const_pointer first, const_pointer last, pointer d_first) {
    // TODO

    int* end;
    int i = 0;

    while (first < last)
    {
        *d_first = *first;
        d_first += 1;
        first += 1;
        i++;
    }
    end = d_first + i;
    return end;
}

void fill_range(pointer first, pointer last, const_reference value) {
    // TODO
    for (pointer i = first; i < last; i++)
    {
        *first = value;
        first += 1;
    }
}

bool equal_range(const_pointer first1, const_pointer last1,
                 const_pointer first2, const_pointer last2) {
    // TODO
    bool check = false;

    int sum1 = 0;
    int len1 = 0;
    int sum2 = 0;
    int len2 = 0;

    for (const_pointer i = first1; i < last1; i++)
    {
        sum1 = *first1;
        first1 += 1;
        len1++;
    }

    for (const_pointer i = first2; i < last2; i++)
    {
        sum2 = *first2;
        first2 += 1;
        len2++;
    }
    if (len1 == len2 && sum1 == sum2)
    {
        check = true;
    }
    return check;
}

// ============================================================================

/** I N T E G R A T E D   U N I T   T E S T S  ---  DO NOT MODIFY **/

/// @brief Tests for the count_values function.
///
/// This test suite checks the correctness of count_values function, ensuring it
/// counts elements accurately under various scenarios including counting an
/// existing value, a non-existing value, and in an empty range.

TEST_CASE("count_values tests") {
    value_type arr[]    = {1, 2, 3, 2, 2, 5};
    const_pointer start = arr;
    const_pointer end   = arr + 6;

    SECTION("count existing value") {
        CHECK(count_values(start, end, 2) == 3);
        CHECK(count_values(start, end, 5) == 1);
    }

    SECTION("count non-existing value") {
        CHECK(count_values(start, end, 4) == 0);
    }

    SECTION("count with empty range") {
        CHECK(count_values(start, start, 1) == 0);
    }
}

/// @brief Tests for the find_value function (both const and non-const versions).
///
/// This test suite checks the find_value function's ability to find a specified
/// value within an array for both const and non-const versions. It tests for
/// finding both existing and non-existing values, in full, partial, and
/// empty ranges.

TEST_CASE("find_value tests (non-const)") {
    value_type arr[] = {1, 2, 3, 4, 5};
    pointer start    = arr;
    pointer end      = arr + 5;

    // Testing non-const version
    SECTION("non-const: find existing value") {
        CHECK(*find_value(start, end, 3) == 3);
    }

    SECTION("non-const: find non-existing value") {
        CHECK(find_value(start, end, 6) == end);
    }

    SECTION("non-const: find in partial range") {
        CHECK(*find_value(start, start + 3, 2) == 2);
    }

    SECTION("non-const: find in empty range") {
        CHECK(find_value(start, start, 1) == start);
    }
}

TEST_CASE("find_value tests (const)") {
    const value_type arr[] = {1, 2, 3, 4, 5};
    const_pointer c_start  = arr;
    const_pointer c_end    = arr + 5;

    // Testing const version
    SECTION("const: find existing value") {
        CHECK(*find_value(c_start, c_end, 3) == 3);
    }

    SECTION("const: find non-existing value") {
        CHECK(find_value(c_start, c_end, 6) == c_end);
    }

    SECTION("const: find in partial range") {
        CHECK(*find_value(c_start, c_start + 3, 2) == 2);
    }

    SECTION("const: find in empty range") {
        CHECK(find_value(c_start, c_start, 1) == c_start);
    }
}

/// @brief Tests for the copy_range function.
///
/// This test suite verifies the copy_range function, ensuring it correctly
/// copies elements from one range to another. It includes tests for copying an
/// entire range and copying an empty range.

TEST_CASE("copy_range tests") {
    value_type arr[]    = {1, 2, 3, 4, 5};
    value_type dest[5]  = {0};
    const_pointer start = arr;
    const_pointer end   = arr + 5;

    SECTION("copy entire range") {
        copy_range(start, end, dest);
        for (size_t i = 0; i < 5; ++i) {
            CHECK(arr[i] == dest[i]);
        }
    }

    SECTION("copy empty range") {
        copy_range(start, start, dest);
        CHECK(dest[0] != 1); // Assuming dest is not initially filled with 1
    }
}

/// @brief Tests for the fill_range function.
///
/// This test suite examines the fill_range function to ensure it correctly
/// assigns a given value to each element in a range. It tests both filling an
/// entire range and filling an empty range.

TEST_CASE("fill_range tests") {
    value_type arr[5] {};
    pointer start = arr;
    pointer end   = arr + 5;

    SECTION("fill entire range") {
        fill_range(start, end, 9);
        for (size_t i = 0; i < 5; ++i) {
            CHECK(arr[i] == 9);
        }
    }

    SECTION("fill empty range") {
        fill_range(start, start, 9);
        CHECK(arr[0] != 9); // Assuming arr is not initially filled with 9
    }
}

/// @brief Tests for the equal_range function.
///
/// This test suite assesses the equal_range function for comparing two ranges.
/// It tests scenarios where the ranges are equal, not equal, and compares a
/// non-empty range with an empty range.

TEST_CASE("equal_range tests") {
    value_type arr1[] = {1, 2, 3, 4, 5};
    value_type arr2[] = {1, 2, 3, 4, 5};
    value_type arr3[] = {1, 2, 3, 4, 6};

    const_pointer start1 = arr1;
    const_pointer end1   = arr1 + 5;
    const_pointer start2 = arr2;
    const_pointer end2   = arr2 + 5;
    const_pointer start3 = arr3;
    const_pointer end3   = arr3 + 5;

    SECTION("equal ranges") {
        CHECK(equal_range(start1, end1, start2, end2));
    }

    SECTION("unequal ranges") {
        CHECK_FALSE(equal_range(start1, end1, start3, end3));
    }

    SECTION("compare with empty range") {
        CHECK_FALSE(equal_range(start1, end1, start1, start1));
    }
}

/* EOF */

