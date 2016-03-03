#pragma once

typedef struct {
	int x;
	int y;
} GridPoint;

typedef struct {
	GridPoint p1;
	GridPoint p2;
} GridPointGroup2;

typedef struct _GridPointGroup {
	unsigned int len;
	unsigned int count;
	GridPoint points[0];
};

typedef struct _GridPointGroup* GridPointGroup;

GridPoint create_gridpoint(int x, int y);

bool is_equal(GridPoint p1, GridPoint p2);

bool is_neighbor(GridPoint p1, GridPoint p2);

GridPointGroup2 create_group2(GridPoint p1, GridPoint p2);

bool is_connected(GridPointGroup2 group);

GridPointGroup create_group(unsigned int len);

void add_to_group(GridPointGroup group, GridPoint point);

bool is_connected(GridPointGroup group);

