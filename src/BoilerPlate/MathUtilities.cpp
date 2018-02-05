#include "MathUtilities.hpp"

namespace Engine
{
	namespace Math {
		float M_PI = 3.1415926535897323846f;

		MathUtilities::MathUtilities()
		{}

		MathUtilities::~MathUtilities()
		{}

		inline int MathUtilities::GetNearestInt(int a)
		{
			m_intToFloat = (float)(a);
			//std::cout << intToFloat << std::endl;
			return m_intToFloat;
		}

		inline float MathUtilities::RoundFloatToInt(float a)
		{
			m_floatToInt = (int)roundf(a);
			//std::cout << floatToInt << std::endl;
			return m_floatToInt;
		}

		float MathUtilities::ConvertRadToDegrees(float angleInRadians)
		{
			return angleInRadians * (M_PI / 180);
		}

		float MathUtilities::ConvertDegreesToRad(float angleInDegrees)
		{
			return angleInDegrees * (180 / M_PI);
		}

		inline int MathUtilities::IsPowerOfTwo(int n)
		{
			while (((n % 2) == 0) && n > 1)
				n /= 2;

			return (n == 1);
		}

		double MathUtilities::AngularDistances(double, double)
		{
			return 0.0;
		}

		template<class T>
		inline T MathUtilities::MaximumN(T arr[4])
		{
			T maxN;
			for (int x = 0; x < 4; x++)
			{
				std::cin >> arr[x];
			}

			for (int i = 0; i < 4; i++)
			{
				naxN = std::max(arr[i]);
			}
			//std::cout << maxN << std::endl;
			return maxN;
		}

		template<class T>
		inline T MathUtilities::MinimumN(T arr[4])
		{
			T minN;
			for (int x = 0; x < 4; x++)
			{
				std::cin >> arr[x];
			}

			for (int i = 0; i < 4; i++)
			{
				minN = std::min(arr[i]);
			}
			//std::cout << minN << std::endl;
			return minN;
		}

		template<class T>
		inline T MathUtilities::Clamp(T number)
		{
			int max = 255, min = 0;
			int clamp;
			clamp = number < min ? min : number;
			return clamp > max ? max : clamp;
		}

		template<class T>
		inline T MathUtilities::Interpolate(T n)
		{
			int start = 0.0;
			int end = 1.0;
			return n;
		}
	}
}