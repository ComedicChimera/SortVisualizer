#include "../sort.h"

#include <vector>
#include <queue>

namespace Sort {
	struct Node {
		int value, index;

		Node *left, *right;
	};

	Node* newNode(int value, int index) {
		Node* node = new Node;
		node->value = value;
		node->index = index;
		
		node->left = node->right = NULL;
		
		return node;
	}

	Node* buildCartesianTree(SortArray &arr) {
		Node* root = newNode(arr[0], 0);

		std::vector<Node*> nodes;
		nodes.push_back(root);

		bool addedNode = false;
		Node* node;
		for (int i = 1; i < arr.size; i++) {
			for (int j = nodes.size() - 1; j >= 0; j--) {
				if (nodes[j]->value < arr[i]) {
					node = newNode(arr[i], i);

					if (nodes[j]->right != NULL)
						node->left = nodes[j]->right;

					nodes[j]->right = node;
					nodes.push_back(node);

					addedNode = true;
					break;
				}
			}

			if (!addedNode) {
				node = newNode(arr[i], i);

				node->left = nodes[0];
				root = node;

				nodes.insert(nodes.begin(), node);
			}
			else
				addedNode = false;
		}

		return root;
	}

	void traverse(SortArray &arr, Node* root, int &ndx) {
		arr[ndx] = root->value;
		arr.draw(2, ndx, root->index);

		root->index = ndx++;

		if (root->left != NULL)
			traverse(arr, root->left, ndx);

		if (root->right != NULL)
			traverse(arr, root->right, ndx);
	}

	void traverseAndSort(SortArray &arr, Node* root) {
		int ndx = 0;
		traverse(arr, root, ndx);

		std::vector<Node*> pQueue;
		ndx = 0;

		pQueue.push_back(root);

		Node* node;
		while (pQueue.size() > 0) {
			node = pQueue.front();

			arr[ndx] = node->value;
			arr.draw(2, ndx++, pQueue.front()->index);

			pQueue.erase(pQueue.begin());

			if (node->left != NULL)
				pQueue.push_back(node->left);

			if (node->right != NULL)
				pQueue.push_back(node->right);

			if (pQueue.size() > 1) {
				int minIndex = 0;
				int minVal = arr.size + 1;

				for (int i = 0; i < pQueue.size(); i++) {
					if (pQueue[i]->value < minVal) {
						minVal = pQueue[i]->value;
						minIndex = i;
					}
				}

				pQueue.insert(pQueue.begin(), pQueue[minIndex]);
				pQueue.erase(pQueue.begin() + minIndex + 1);
			}
		}
	}

	void cartesianTreeSort(SortArray &arr) {
		auto root = buildCartesianTree(arr);
		traverseAndSort(arr, root);

		arr.draw(0);
	}
}