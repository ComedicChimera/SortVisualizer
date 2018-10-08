#include "../sort.h"

namespace Sort {
	// Smooth Sort Algorithm Credit: https://www.programmingalgorithms.com/algorithm/smooth-sort?lang=C%2B%2B
	class SmoothSorter {
		SortArray &m_Array;

		// no m_ prefix cause no
		int q, r, p, b, c, r1, b1, c1;

		void up(int &ia, int &ib, int &temp) {
			temp = ia;
			ia += ib + 1;
			ib = temp;
		}

		void down(int &ia, int &ib, int &temp) {
			temp = ib;
			ib = ia - ib - 1;
			ia = temp;
		}

		void sift() {
			int r0 = r1, r2, temp = 0;
			int t = m_Array[r0];

			while (b1 >= 3)
			{
				r2 = r1 - b1 + c1;

				if (m_Array[r1 - 1] > m_Array[r2])
				{
					r2 = r1 - 1;
					down(b1, c1, temp);
				}

				if (m_Array[r2] <= t)
				{
					b1 = 1;
				}
				else
				{
					m_Array[r1] = m_Array[r2];
					m_Array.draw(2, r1, r2);

					r1 = r2;
					down(b1, c1, temp);
				}
			}

			if (r1 - r0) {
				m_Array[r1] = t;
				m_Array.draw(1, r1);
			}	
		}

		void trinkle() {
			int p1 = p, r2, r3, r0 = r1, temp = 0, t = m_Array[r1];
			b1 = b;
			c1 = c;

			while (p1 > 0) {
				while ((p1 & 1) == 0)
				{
					p1 >>= 1;
					up(b1, c1, temp);
				}

				r3 = r1 - b1;

				if ((p1 == 1) || (m_Array[r3] <= t))
				{
					p1 = 0;
				}
				else {
					--p1;

					if (b1 == 1)
					{
						m_Array[r1] = m_Array[r3];
						m_Array.draw(2, r1, r3);

						r1 = r3;
					}
					else
					{
						if (b1 >= 3)
						{
							r2 = r1 - b1 + c1;

							if (m_Array[r1 - 1] > m_Array[r2])
							{
								r2 = r1 - 1;
								down(b1, c1, temp);
								p1 <<= 1;
							}
							if (m_Array[r2] <= m_Array[r3])
							{
								m_Array[r1] = m_Array[r3];
								m_Array.draw(2, r1, r3);

								r1 = r3;
							}
							else
							{
								m_Array[r1] = m_Array[r2];
								m_Array.draw(2, r1, r2);

								r1 = r2;
								down(b1, c1, temp);
								p1 = 0;
							}
						}
					}
				}
			}

			if (r0 - r1) {
				m_Array[r1] = t;
				m_Array.draw(1, r1);
			}

			sift();
		}

		void semiTrinkle() {
			r1 = r - c;

			if (m_Array[r1] > m_Array[r]) {
				m_Array.swap(r1, r);
				m_Array.draw(2, r, r1);

				trinkle();
			}
		}

	public:
		SmoothSorter(SortArray &arr)
			: m_Array(arr)
			, q(1)
			, r(0)
			, p(1)
			, b(1)
			, c(1)
		{}

		void sort() {
			int temp = 0;

			while (q < m_Array.size)
			{
				r1 = r;
				if ((p & 7) == 3)
				{
					b1 = b;
					c1 = c;
					sift();
					p = (p + 1) >> 2;
					up(b, c, temp);
					up(b, c, temp);
				}
				else if ((p & 3) == 1)
				{
					if (q + c < m_Array.size)
					{
						b1 = b;
						c1 = c;
						sift();
					}
					else
					{
						trinkle();
					}

					down(b, c, temp);
					p <<= 1;

					while (b > 1)
					{
						down(b, c, temp);
						p <<= 1;
					}

					++p;
				}

				++q;
				++r;
			}

			r1 = r;
			trinkle();

			while (q > 1)
			{
				--q;

				if (b == 1)
				{
					--r;
					--p;

					while ((p & 1) == 0)
					{
						p >>= 1;
						up(b, c, temp);
					}
				}
				else
				{
					if (b >= 3)
					{
						--p;
						r = r - b + c;
						if (p > 0)
							semiTrinkle();

						down(b, c, temp);
						p = (p << 1) + 1;
						r = r + c;
						semiTrinkle();
						down(b, c, temp);
						p = (p << 1) + 1;
					}
				}
			}
		}
	};

	void smoothSort(SortArray &arr) {
		SmoothSorter s(arr);
		s.sort();

		arr.draw(0);
	}
}