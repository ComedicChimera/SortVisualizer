#include "../sort.h"

#include <iostream>

namespace Sort {
	struct Node {
		int key;
		Node *left, *right;

		Node(int val) {
			key = val;
			left = right = NULL;
		}
	};

	class TreeSorter {
		SortArray &m_Arr;
		Node *m_Root;

		int m_InsertionIndex;

		Node* insert(Node* node, int key) {
			if (node == NULL) return new Node(key);

			if (key < node->key)
				node->left = insert(node->left, key);
			else if (key > node->key)
				node->right = insert(node->right, key);

			return node;
		}

		void traverse(Node *node, int &i, int item) {
			if (node != NULL) {
				traverse(node->left, i, item);

				if (node->key == item)
					m_InsertionIndex = i;

				m_Arr[i++] = node->key;
				traverse(node->right, i, item);
			}
		}

		void traverse(int item) {
			int start = 0;
			traverse(m_Root, start, item);
		}

	public:
		TreeSorter(SortArray &arr)
			: m_Arr(arr)
			, m_Root(NULL)
			, m_InsertionIndex(0)
		{}

		void sort() {
			m_Root = insert(m_Root, m_Arr[0]);
			

			for (int i = 1; i < m_Arr.size; i++) {
				insert(m_Root, m_Arr[i]);
				traverse(m_Arr[i]);

				m_Arr.draw(2, m_InsertionIndex, i);
			}
		}
	};

	void treeSort(SortArray &arr) {
		TreeSorter ts(arr);
		ts.sort();

		arr.draw(0);
	}
}