#include "utmatrix.h"

#include <gtest.h>

#define SIZE 100

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector <int> v1(SIZE);
	for (int i = 0; i < SIZE ; i++)
		v1[i] = i;
	TVector <int> v2(v1);
	EXPECT_EQ(SIZE, v2.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(i, v2[i]);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector <int> v1(SIZE);
	for (int i = 0; i < SIZE; i++)
		v1[i] = i;
	TVector <int> v2(v1);
	for (int i = 0; i < SIZE; i++)
		v2[i] = i + 1;
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(i + 1, v2[i]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(SIZE);

  EXPECT_EQ(SIZE, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(SIZE, 1);

  EXPECT_EQ(1, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(SIZE);
  v[0] = 42;
  EXPECT_EQ(42, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(SIZE);
	ASSERT_ANY_THROW(v[-42] = 100);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(SIZE);
	ASSERT_ANY_THROW(v[SIZE + 42] = 100);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(SIZE);
	for (int i = 0; i < SIZE; i++)
		v[i] = i;
	ASSERT_NO_THROW(v = v);
	EXPECT_EQ(SIZE, v.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(i, v[i]);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v1(SIZE), v2(SIZE);
	for (int i = 0; i < SIZE; i++)
		v1[i] = i;
	for (int i = 0; i < SIZE; i++)
		v2[i] = 42 * i;
	ASSERT_NO_THROW(v1 = v2);
	EXPECT_EQ(SIZE, v1.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(42 * i, v1[i]);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v1(SIZE);
	TVector<int> v2(SIZE + 1);
	ASSERT_NO_THROW(v1 = v2);
	EXPECT_EQ(SIZE + 1, v1.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v1(SIZE), v2(SIZE + 1);
	for (int i = 0; i < SIZE; i++)
		v1[i] = i;
	for (int i = 0; i < SIZE + 1; i++)
		v2[i] = 42 * i;
	ASSERT_NO_THROW(v1 = v2);
	EXPECT_EQ(SIZE + 1, v1.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(42 * i, v1[i]);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1(SIZE), v2(SIZE);
	for (int i = 0; i < SIZE; i++) {
		v1[i] = i;
		v2[i] = i;
	}
	EXPECT_TRUE(v1 == v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> a(SIZE);
	for (int i = 0; i < SIZE; i++)
		a[i] = i;
	EXPECT_EQ(true, a == a);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> a(SIZE);
	TVector<int> b(SIZE + 1);
	for (int i = 0; i < SIZE; i++)
		a[i] = i;
	for (int i = 0; i < SIZE + 1; i++)
		b[i] = i;
	EXPECT_TRUE(b != a);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v1(SIZE);
	for (int i = 0; i < SIZE; i++)
		v1[i] = i;
	TVector<int> v2(v1);
	ASSERT_NO_THROW(v1 + 42);
	v2 = v1 + 42;
	EXPECT_EQ(SIZE, v2.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(i + 42, v2[i]);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v1(SIZE);
	for (int i = 0; i < SIZE; i++)
		v1[i] = i;
	TVector<int> v2(v1);
	ASSERT_NO_THROW(v1 - 42);
	v2 = v1 - 42;
	EXPECT_EQ(SIZE, v2.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(i - 42, v2[i]);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v1(SIZE);
	for (int i = 0; i < SIZE; i++)
		v1[i] = i;
	TVector<int> v2(v1);
	ASSERT_NO_THROW(v1 * 42);
	v2 = v1 * 42;
	EXPECT_EQ(SIZE, v2.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(i * 42, v2[i]);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> a(SIZE), b(SIZE), c(SIZE);
	for (int i = 0; i < SIZE; i++)
		a[i] = i;
	for (int i = 0; i < SIZE; i++)
		b[i] = 42 * i;
	ASSERT_NO_THROW(a + b);
	c = a + b;
	EXPECT_EQ(SIZE, c.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(42 * i + i, c[i]);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> a(SIZE), b(SIZE + 1);
	for (int i = 0; i < SIZE; i++)
		a[i] = i;
	for (int i = 0; i < SIZE + 1; i++)
		b[i] = i;
	ASSERT_ANY_THROW(a + b);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> a(SIZE), b(SIZE), c(SIZE);
	for (int i = 0; i < SIZE; i++)
		a[i] = i;
	for (int i = 0; i < SIZE; i++)
		b[i] = 42 * i;
	ASSERT_NO_THROW(a - b);
	c = a - b;
	EXPECT_EQ(SIZE, c.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(i - 42 * i, c[i]);}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> a(SIZE), b(SIZE + 1);
	for (int i = 0; i < SIZE; i++)
		a[i] = i;
	for (int i = 0; i < SIZE + 1; i++)
		b[i] = i;
	ASSERT_ANY_THROW(a - b);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> a(SIZE), b(SIZE);
	int c = 0;
	int expectedSum = 0;
	for (int i = 0; i < SIZE; i++) { 
		a[i] = b[i] = i;
		expectedSum += i * i;
	}
	ASSERT_NO_THROW(a * b);
	c = a * b;
	EXPECT_EQ(expectedSum, c);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> a(SIZE), b(SIZE + 1);
	for (int i = 0; i < SIZE; i++)
		a[i] = i;
	for (int i = 0; i < SIZE + 1; i++)
		b[i] = i;
	ASSERT_ANY_THROW(a * b);
}

