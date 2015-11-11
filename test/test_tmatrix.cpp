#include "utmatrix.h"

#include <gtest.h>

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
	TMatrix<int> a(10);
	for (int i = 0; i < 10; i++)
		a[i][i] = i;
	TMatrix<int> b(a);
	EXPECT_EQ(a, b);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> a(10);
	a[1][2] = 0;
	TMatrix<int> b(a);
	b[1][2] = 100;

	EXPECT_NE(a[1][2], b[1][2]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> a(10);
	ASSERT_NO_THROW(a.GetSize());
	EXPECT_EQ(10, a.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> a(10);
	a[1][2] = 10;
	EXPECT_EQ(10, a[1][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> a(10);
	ASSERT_ANY_THROW(a[1][-1] = 10);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> a(10);
	ASSERT_ANY_THROW(a[1][100] = 10);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> a(10);
	a[2][3] = 1;
	ASSERT_NO_THROW(a = a);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> a(10), b(10), c(10);
	a[1][1] = 10;
	c[1][1] = 10;
	ASSERT_NO_THROW(b = a);
	EXPECT_EQ(c, b);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> a(10), b(100);
	a[1][1] = 1;
	ASSERT_NO_THROW(a = b);
	EXPECT_EQ(100, a.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> a(10), b(100), c(10);
	a[1][1] = 5;
	c[1][1] = 5;
	ASSERT_NO_THROW(b = a);
	EXPECT_EQ(c, b);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> a(10), b(10);
	a[1][1] = 1;
	b[1][1] = 1;
	ASSERT_TRUE(a == b);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> a(10);
	a[1][1] = 1;
	ASSERT_TRUE(a == a);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> a(10), b(100);
	a[1][1] = 1;
	b[1][1] = 1;
	EXPECT_NE(a, b);

}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> a(10), b(10), c(10);
	a[1][1] = 10;
	a[2][3] = 11;
	b[1][1] = 10;
	b[2][3] = 1;
	b[3][1] = 1;
	c[1][1] = 20;
	c[2][3] = 12;
	c[3][1] = 1;
	EXPECT_EQ(c, a + b);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> a(5), b(10);
	a[1][1] = 5;
	b[1][1] = 4;
	ASSERT_ANY_THROW(a + b);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> a(10), b(10), c(10);
	a[1][1] = 20;
	a[2][3] = 10;
	b[1][1] = 10;
	b[2][3] = 5;
	b[3][1] = 1;
	c[1][1] = 10;
	c[2][3] = 5;
	c[3][1] = -1;
	EXPECT_EQ(c, a - b);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> a(10), b(100);
	a[1][1] = 10;
	b[1][1] = 100;
	ASSERT_ANY_THROW(a - b);

}