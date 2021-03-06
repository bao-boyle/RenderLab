#ifndef _CPPUTIL_BASIC_MATH_UGM_POINT4_H_
#define _CPPUTIL_BASIC_MATH_UGM_POINT4_H_

#include <CppUtil/Basic/UGM/Point.h>
#include <CppUtil/Basic/UGM/Vector4.h>

#include <CppUtil/Basic/UGM/ext/Alias.h>
#include <CppUtil/Basic/UGM/ext/Basic_Val4.h>
#include <CppUtil/Basic/UGM/ext/Metric_Euclidean_4.h>

namespace CppUtil {
	namespace Basic {
		template <typename T>
		class Point<4, T> : public EXT::ME_B<4,T,Point<4,T>> {
		public:
			using EXT::ME_B<4, T, Point<4, T>>::ME_B;

		public:
			const Point operator+(const Vector<4, T> &v) const {
				return Point(x + v.x, y + v.y, z + v.z, w + v.w);
			}

			Point & operator+=(const Vector<4, T> &v) {
				x += v.x;
				y += v.y;
				z += v.z;
				w += v.w;
				return *this;
			}

			const Vector<4, T> operator-(const Point &p) const {
				return Vector<4, T>(x - p.x, y - p.y, z - p.z, w - p.w);
			}

			const Point operator-(const Vector<4, T> &v) const {
				return Point(x - v.x, y - v.y, z - v.z, w - v.w);
			}

			const Point & operator-=(const Vector<4, T> &v) {
				x -= v.x;
				y -= v.y;
				z -= v.z;
				w -= v.w;
				return *this;
			}

#ifndef NDEBUG
			// 仅用于 Debug 时方便在 IDE 中显示结果
		public:
			Point & operator =(const Point & p) {
				*static_cast<EXT::ME_B<4, T, Point<4, T>>*>(this) = p;
				return *this;
			}
		private:
			const T & _x{ *(((T*)this) + 0) };
			const T & _y{ *(((T*)this) + 1) };
			const T & _z{ *(((T*)this) + 2) };
			const T & _w{ *(((T*)this) + 3) };
#endif // !NDEBUG
		};
	}
}

#endif // !_CPPUTIL_BASIC_MATH_UGM_POINT4_H_
