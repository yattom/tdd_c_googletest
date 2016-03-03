#include "gtest/gtest.h"
#include "czatdd_201603.h"

TEST(Create, Normal) {
	GridPoint p = create_gridpoint(4, 7);
	EXPECT_EQ(4, p.x);
	EXPECT_EQ(7, p.y);
}

TEST(Create, Minus) {
	GridPoint p = create_gridpoint(-4, -7);
	EXPECT_EQ(-4, p.x);
	EXPECT_EQ(-7, p.y);
}

TEST(Compare, Equal) {
	GridPoint p1 = create_gridpoint(4, 7);
	GridPoint p2 = create_gridpoint(4, 7);
	EXPECT_TRUE(is_equal(p1, p2));
}

TEST(Compare, NotEqual) {
	GridPoint p1 = create_gridpoint(4, 7);
	GridPoint p2 = create_gridpoint(3, 8);
	EXPECT_FALSE(is_equal(p1, p2));
}

TEST(Compare, Neighbor) {
	GridPoint p1 = create_gridpoint(4, 7);
	GridPoint p2 = create_gridpoint(3, 7);
	EXPECT_TRUE(is_neighbor(p1, p2));
}

TEST(Compare, NotNeighbor) {
	GridPoint p1 = create_gridpoint(4, 7);
	GridPoint p2 = create_gridpoint(3, 8);
	EXPECT_FALSE(is_neighbor(p1, p2));
}

TEST(GridPointGroup2, Connected) {
	GridPoint p1 = create_gridpoint(4, 7);
	GridPoint p2 = create_gridpoint(4, 8);
	GridPointGroup2 g = create_group2(p1, p2);
	EXPECT_TRUE(is_connected(g));
}

TEST(GridPointGroup, Connected) {
	GridPointGroup g = create_group(2);
	add_to_group(g, create_gridpoint(4, 7));
	add_to_group(g, create_gridpoint(4, 8));
	EXPECT_TRUE(is_connected(g));
}

TEST(GridPointGroup, ConnectedComplex) {
	GridPointGroup g = create_group(5);
	add_to_group(g, create_gridpoint(6, 9));
	add_to_group(g, create_gridpoint(4, 7));
	add_to_group(g, create_gridpoint(5, 8));
	add_to_group(g, create_gridpoint(5, 9));
	add_to_group(g, create_gridpoint(4, 8));
	EXPECT_TRUE(is_connected(g));
}

