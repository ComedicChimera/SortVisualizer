#include "../sort_array.h"

#include <stdexcept>

int& SortArray::operator[](unsigned int index) {
	if (index < size) return m_Array[index];

	throw new std::out_of_range("Index out of range of sorted array.");
}

void SortArray::swap(int a, int b) {
	if (a < size && b < size) {
		if (a != b) {

			int c = m_Array[a];
			m_Array[a] = m_Array[b];
			m_Array[b] = c;

		}
		return;
	}


	throw new std::out_of_range("Index out of range of sorted array.");
}