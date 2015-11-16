#include "utmatrix.h"

#include <gtest.h>

#define SIZE 100

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix <int> m1(SIZE);
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			m1[i][j] = i + j;
	TMatrix <int> m2(m1);
	EXPECT_EQ(m1.GetSize(), m2.GetSize());
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			EXPECT_EQ(i + j, m2[i][j]);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix <int> m1(SIZE);
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			m1[i][j] = i + j;
	TMatrix <int> m2(m1);
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			m2[i][j] = i + j + 1;
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			EXPECT_EQ(i + j, m1[i][j]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> a(SIZE);
	ASSERT_NO_THROW(a.GetSize());
	EXPECT_EQ(SIZE, a.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(SIZE);
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			m[i][j] = i + j;
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			EXPECT_EQ(i + j, m[i][j]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> a(SIZE);
	ASSERT_ANY_THROW(a[1][-42] = 100);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> a(SIZE);
	ASSERT_ANY_THROW(a[1][SIZE + 1] = 10);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(SIZE);
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			m[i][j] = i + j;
	ASSERT_NO_THROW(m = m);
	EXPECT_EQ(SIZE, m.GetSize());
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			EXPECT_EQ(i + j, m[i][j]);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m1(SIZE), m2(SIZE);
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			m1[i][j] = 0;
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			m2[i][j] = j;
	ASSERT_NO_THROW(m1 = m2);
	EXPECT_EQ(SIZE, m1.GetSize());
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			EXPECT_EQ(j, m1[i][j]);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> a(SIZE), b(SIZE + 1);
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			a[i][j] = i;
	ASSERT_NO_THROW(b = a);
	EXPECT_EQ(SIZE, b.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> a(SIZE), b(SIZE + 1);
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			a[i][j] = i;
	for (int i = 0; i < SIZE + 1; i++)
		for (int j = i; j < SIZE + 1; j++)
			b[i][j] = j;
	ASSERT_NO_THROW(b = a);
	EXPECT_EQ(SIZE, b.GetSize());
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			EXPECT_EQ(i, b[i][j]);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(SIZE), m2(SIZE);
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++) {
			m1[i][j] = m2[i][j] = i + j;
		}
	EXPECT_TRUE(m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(SIZE);
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			m[i][j] = i;
	EXPECT_TRUE(m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(SIZE), m2(SIZE + 1);
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			m1[i][j] = j;
	for (int i = 0; i < 3; i++)
		for (int j = i; j < SIZE + 1; j++)
			m2[i][j] = j;
	EXPECT_TRUE(m1 != m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> a(SIZE), b(SIZE), c(SIZE);
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
		{
			a[i][j] = i;
			b[i][j] = j;
		}
	ASSERT_NO_THROW(a + b);
	c = a + b;
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			EXPECT_EQ(i + j, c[i][j]);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(SIZE), m2(SIZE + 1);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> a(SIZE), b(SIZE), c(SIZE);
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
		{
			a[i][j] = i;
			b[i][j] = j;
		}
	ASSERT_NO_THROW(a - b);
	c = a - b;
	for (int i = 0; i < SIZE; i++)
		for (int j = i; j < SIZE; j++)
			EXPECT_EQ(i - j, c[i][j]);
	EXPECT_EQ(a - b, c);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(SIZE), m2(SIZE + 1);
	ASSERT_ANY_THROW(m1 - m2);
}