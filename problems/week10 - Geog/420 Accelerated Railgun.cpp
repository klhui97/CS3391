
#include <cmath>
#include <queue>
#include <memory>
#include <algorithm>
#include <iostream>

#define VERY_SMALL_NUMBER 1e-7L

using std::deque;
using std::shared_ptr;

/**
 * A class that can used to represent one 2D point or one vector, and to
 * carryout vector calculations.
 */
class TwoDPoint {
private:
	double _x;
	double _y;

public:
	TwoDPoint(double x, double y) : _x(x), _y(y) {}

	double get_x() { return this->_x; }
	double get_y() { return this->_y; }

	/*
	 * Basic operations
	 */
	inline TwoDPoint add(const TwoDPoint &other) const {
		return TwoDPoint(this->_x + other._x,
			this->_y + other._y);
	}

	inline TwoDPoint minus(const TwoDPoint &other) const {
		return TwoDPoint(this->_x - other._x,
			this->_y - other._y);
	}

	inline double dot(const TwoDPoint &other) const {
		return this->_x * other._x + this->_y * other._y;
	}

	inline double cross(const TwoDPoint &other) const {
		return this->_x * other._y - this->_y * other._x;
	}

	/*
	 * Size related
	 */

	inline double get_length() const {
		return sqrt(_x*_x + _y * _y);
	}

	inline TwoDPoint normalize() const {
		double length = this->get_length();
		return TwoDPoint(_x / length, _y / length);
	}

	/*
	 * Position related
	 */

	 /**
	  * Does pt2 and pt3 at the same side of the _straight line_ that
	  * pt0 and pt1 are on?
	  * This function does not take care of the marinal case
	  */
	static int on_same_side(
		const TwoDPoint &pt0, const TwoDPoint &pt1,
		const TwoDPoint &pt2, const TwoDPoint &pt3) {
		TwoDPoint v01 = pt1.minus(pt0);
		TwoDPoint v02 = pt2.minus(pt0);
		TwoDPoint v03 = pt3.minus(pt0);
		return v01.cross(v02) * v01.cross(v03) > 0;
	}

	inline int is_parallel_with(const TwoDPoint &other) const {
		return is_approximately_equal(this->cross(other), 0);
	}

	/*
	 * get the angle attained by rotate this counter-clockwise to other
	 */
	inline double get_angle_to(const TwoDPoint &other) const {
		double a_other = atan2(other._y, other._x);
		double a_this = atan2(this->_y, this->_x);
		return a_other - a_this;
	}

	/**
	 * Calculate the ditance from this point to the line crossing
	 * lp1 and lp2
	 */
	double get_distance_to_line(TwoDPoint &lp1, TwoDPoint &lp2) {
		TwoDPoint l = lp2.minus(lp1);
		TwoDPoint lthis = this->minus(lp1);
		return l.cross(lthis) / l.get_length();
	}

	/**
	 * is this on the the straight line line from p1 to p2
	 */
	int is_on_line(TwoDPoint &p1, TwoDPoint &p2) {
		TwoDPoint v12 = p2.minus(p1);
		TwoDPoint v1 = this->minus(p1);
		return v1.is_parallel_with(v12);
	}

	/*
	 * Utilities
	 */
	inline static int is_approximately_equal(double a, double b) {
		double d = b - a;
		return d < VERY_SMALL_NUMBER && -d < VERY_SMALL_NUMBER;
	}

};

class PointCmp {
private:
	TwoDPoint _p;
public:
	PointCmp(TwoDPoint p) : _p(p) {}

	/**
	 * Is the angle p1,p0,p2 conter-closewise
	 */
	int operator() (const TwoDPoint &p1, const TwoDPoint &p2) const {
		TwoDPoint v1 = p1.minus(_p);
		TwoDPoint v2 = p2.minus(_p);
		return v1.cross(v2) > 0;
	}
};

int main(void) {
	using namespace std;
	cin.tie(nullptr);
	ios_base::sync_with_stdio(0);
	double range;
	double px, py, vx, vy;
	while (cin >> range) {
		if (range == 0)
			break;
		cin >> px >> py >> vx >> vy;
		TwoDPoint p(px, py);
		TwoDPoint v(vx, vy);
		int possible = 1;
		if (! p.is_parallel_with(v)) {
			possible = 0;
		}
		else {
			if (p.dot(v) > 0) {
				// v points outward
				if (2 - p.get_length() > range)
					possible = 0;
			}
			else {
				// v point inward
				if (p.get_length() > range)
					possible = 0;
			}
		}

		if (possible) {
			cout << "possible\n";
		}
		else {
			cout << "impossible\n";
		}
	}
	return 0;
}