#include "../sort_array.h"

#include <stdexcept>

int& SortArray::operator[](unsigned int index) {
	if (index < size) return m_Array[index + m_SliceOffset];

	throw new std::out_of_range("Index out of range of sorted array.");
}

void SortArray::swap(int a, int b) {
	if (a < size && b < size) {
		if (a != b) {
			if (m_SliceOffset > 0) {
				a += m_SliceOffset;
				b += m_SliceOffset;
			}

			int c = m_Array[a];
			m_Array[a] = m_Array[b];
			m_Array[b] = c;

		}
		return;
	}


	throw new std::out_of_range("Index out of range of sorted array.");
}

void SortArray::slice(int l, int h) {
	m_SliceOffset = l;
	size = h - l;
}

void SortArray::restore() {
	size = m_TrueSize;
	m_SliceOffset = 0;
}