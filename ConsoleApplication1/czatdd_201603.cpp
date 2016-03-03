#include <stdlib.h>
#include "czatdd_201603.h"

GridPoint create_gridpoint(int x, int y) {
	GridPoint p;
	p.x = x;
	p.y = y;
	return p;
}

bool is_equal(GridPoint p1, GridPoint p2) {
	return p1.x == p2.x && p1.y == p2.y;
}

bool is_neighbor(GridPoint p1, GridPoint p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y) == 1;
}

GridPointGroup2 create_group2(GridPoint p1, GridPoint p2) {
	GridPointGroup2 group;
	group.p1 = p1;
	group.p2 = p2;
	return group;
}

bool is_connected(GridPointGroup2 group) {
	return is_neighbor(group.p1, group.p2);
}

GridPointGroup create_group(unsigned int len) {
	GridPointGroup group = (GridPointGroup)malloc(sizeof(GridPointGroup) + sizeof(GridPoint) * len);
	group->len = len;
	group->count = 0;
	return group;
}

void add_to_group(GridPointGroup group, GridPoint point) {
	group->points[group->count] = point;
	group->count++;
}

bool is_connected(GridPointGroup group) {
	if (group->len == 0) {
		return true;
	}
	bool *connected = (bool*)malloc(sizeof(bool) * group->len);
	connected[0] = true;
	for (int i = 1; i < group->len; i++) {
		connected[i] = false;
	}

	int connected_count = 1;
	bool modified;
	do {
		modified = false;
		for (int i = 0; i < group->len; i++) {
			if (!connected[i]) {
				continue;
			}
			for (int j = 0; j < group->len; j++) {
				if (!connected[j] && is_neighbor(group->points[i], group->points[j])) {
					connected[j] = true;
					modified = true;
					connected_count++;
				}
			}
		}
		if (connected_count == group->len) {
			return true;
		}
	} while (modified);
	return false;
}
