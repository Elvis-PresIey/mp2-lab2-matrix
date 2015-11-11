#include "utmatrix.h"

#include <gtest.h>

#define SIZE 10

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
	TVector<int> v(SIZE);
	for (int i = 0; i < SIZE; i++)
		v[i] = i + 1;
	TVector<int> b(v);
	EXPECT_EQ(v.GetSize(), b.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(v[i], b[i]);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v1(SIZE);
	v1[3] = 1;
	TVector<int> v2(v1);
	v2[2] = 3;

	EXPECT_NE(v1, v2);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(SIZE);
	ASSERT_ANY_THROW(v[-1] = 7);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(SIZE);
	ASSERT_ANY_THROW(v[SIZE + 1] = 1);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> vec(SIZE);
	for (int i = 0; i < SIZE; i++)
		vec[i] = i;
	vec = vec;
	EXPECT_EQ(SIZE, vec.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(vec, vec);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> a(SIZE), b(SIZE);
	for (int i = 0; i < SIZE; i++)
		a[i] = i + 2;
	b = a;
	EXPECT_EQ(SIZE, a.GetSize());
	EXPECT_EQ(a.GetSize(), b.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(a[i], b[i]);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> a(SIZE), b(SIZE + SIZE);
	a[1] = 1;
	b[SIZE] = 2;
	a = b;

	EXPECT_EQ(SIZE + SIZE, a.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> a(SIZE), b(SIZE + SIZE);
	TVector<int> c(SIZE + SIZE);
	for (int i = 0; i < SIZE + SIZE; i++)
		b[i] = i;
	a = b;
	for (int i = 0; i < SIZE + SIZE; i++)
		c[i] = i;
	EXPECT_EQ(SIZE + SIZE, a.GetSize());
	EXPECT_EQ(b.GetSize(), a.GetSize());
	for (int i = 0; i < SIZE + SIZE; i++)
		EXPECT_EQ(c[i], a[i]);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> a(2 * SIZE), b(SIZE);
	for (int i = 0; i < 2 * SIZE; i++)
		a[i] = i;
	b = a;
	EXPECT_EQ(true, b == a);
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
	int size = 7;
	TVector<int> a(2 * SIZE);
	TVector<int> b(SIZE);
	for (int i = 0; i < 2 * SIZE; i++)
		a[i] = i;
	for (int i = 0; i < SIZE; i++)
		b[i] = i;
	EXPECT_EQ(true, b != a);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> a(SIZE);
	for (int i = 0; i < SIZE; i++)
		a[i] = i;
	a = a + 1;
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(i + 1, a[i]);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> a(SIZE);
	for (int i = 0; i < SIZE; i++)
		a[i] = i;
	a = a - 1;
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(i - 1, a[i]);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> a(SIZE);
	for (int i = 0; i < SIZE; i++)
		a[i] = i;
	a = a * 2;
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(i * 2, a[i]);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> a(SIZE), b(SIZE), c(SIZE);
	for (int i = 0; i < SIZE; i++)
		a[i] = i;
	for (int i = 0; i < SIZE; i++)
		b[i] = i;
	c = a + b;
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(2 * i, c[i]);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> a(SIZE), b(SIZE + SIZE);
	for (int i = 0; i < SIZE; i++)
		a[i] = i;
	for (int i = 0; i < SIZE + SIZE; i++)
		b[i] = i;
	ASSERT_ANY_THROW(a + b);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> a(SIZE), b(SIZE), c(SIZE);
	for (int i = 0; i < SIZE; i++)
		a[i] = i;
	for (int i = 0; i < SIZE; i++)
		b[i] = i;
	c = a - b;
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(0, c[i]);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> a(SIZE), b(SIZE + SIZE);
	for (int i = 0; i < SIZE; i++)
		a[i] = i;
	for (int i = 0; i < SIZE + SIZE; i++)
		b[i] = i;
	ASSERT_ANY_THROW(a - b);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> a(SIZE), b(SIZE);
	int c = 0;
	int expectedSum = 0;
	for (int i = 0; i < SIZE; i++)
		a[i] = i;
	for (int i = 0; i < SIZE; i++)
		b[i] = i;
	c = a * b;
	for (int i = 0; i < SIZE; i++)
		expectedSum += (i * i);
	EXPECT_EQ(expectedSum, c);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> a(SIZE), b(SIZE + SIZE);
	for (int i = 0; i < SIZE; i++)
		a[i] = i;
	for (int i = 0; i < SIZE + SIZE; i++)
		b[i] = i;
	ASSERT_ANY_THROW(a * b);
}

