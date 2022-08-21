#pragma once

namespace Wake {
	namespace Math {
		class Vector3
		{
		public:
			Vector3();
			Vector3(float _x, float _y, float _z);
			~Vector3();

			static Vector3 zero();

		private:
			float x, y, z;
		};
	}
}
