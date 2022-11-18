#include"DataNode.h"
#include<iostream>
template<class T>

void tournamentSort(T a[], int n)
{
	DataNode<T>* tree;
	DataNode<T> item;

	int bottomRowSize;

	int treeSize;
		
	int loadindex;
	int i, j;
	bottomRowSize = pow(n,2);
	treeSize = 2 * bottomRowSize - 1;
	tree = new DataNode<T>(treesize);
	j = 0;
	for (i = loadindex; i < treeSize; i++) {

		item.index = 1;
		if (j < n) {
			item.active = 1;
			item.data = a[j++];
		}

		else
			item.active = 0;
		tree[i] = item;
	}
	i = loadindex;
	while (i > 0) {

		j = i;
		while (j < 2 * i)
		{
			if (!tree[j + 1].active || tree[j] < tree[j + 1])
				tree[(j - 1) / 2] = tree[j];
			else
				tree[(j - 1) / 2] = tree[j + 1];
			j += 2;
		}
		for (i = 0; i < n - 1; i++) {

			a[i] = tree[0].data;
			tree[tree[0].index].active = 0;
			updateTree(tree, tree[0].index);
		}
		a[n - 1] = tree[0].data;
	}
}


template<class T>
void updateTree(DataNode<T>* tree, int i) {
	int j;
	if(i % 2 == 0)
		tree[(i - 1) / 2] = tree[i - 1];
	else
	tree[(i - 1) / 2] = tree[i + 1];

	i = (i - 1) / 2;
	while (i > 0)
	{
		if (i % 2 == 0)
			j = i - 1;
		else
			j = i + 1;
	if (!tree[i].active || !tree[j].active)
		if (tree[i].active)
			tree[(i - 1) / 2] = tree[i];
		else
			tree[(i - 1) / 2] = tree[j];
	else
		if (tree[i] < tree[j])
			tree[(i - 1) / 2] = tree[i];
		else
			tree[(i - 1) / 2] = tree[j];
	i = (i - 1) / 2;

	}
}