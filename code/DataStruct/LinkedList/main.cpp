#include<iostream>
#include<stack>

#include "LinkedList.h"
#include "BinaryTree.h"
#include "stack.h"
#include "queue.h"

using namespace std;

int main()
{
	/*LinkedList list;
	cout << "add head" << endl;
	list.addAtHead(3);
	list.addAtHead(5);
	list.addAtHead(10);
	list.addAtHead(12);
	list.print();
	cout << "add tail" << endl;
	list.addAtTail(4);
	list.addAtTail(6);
	list.print();
	cout << "delete head" << endl;
	list.removeAtHead();
	list.print();
	cout << "delete tail" << endl;
	list.removeAtTail();
	list.print();
	cout << "delete index 0" << endl;
	list.deleteNode(0);
	list.print();
	cout << "insert index 2 5" << endl;
	list.insertNode(2, 5);
	list.print();
	cout << "reverse" << endl;
	list.reverse();
	list.print();
	cout << "index 5 to last" << endl;
	cout<<list.reTopk(5) << endl;
	cout << "delete val==4" << endl;
	list.deletevalNode(list.head, 6);
	list.print();
	cout << "sort list" << endl;
	list.sortList(list.head, nullptr);
	list.print();*/
	

	/*stack<int> mystack;
	int sum = 0;
	for (int i = 0; i <= 10; i++) {
		mystack.push(i);
	}
	cout << "size is " << mystack.size() << endl;
	while (!mystack.empty()) {
		cout << " " << mystack.top();
		mystack.pop();
	}
	cout << endl;
	system("pause");*/


	//cout << "-------------------------Start--------------------------" << endl;
	//cout << "---------------------����ԭʼ������---------------------" << endl;
	//string str = "ABD#G##E##CF###";
	//BTree<int>* T = new BTree<int>(str);
	//BTreeNode<int>* root = T->getRoot();
	//cout << "������� " << T->getSize() << " �����" << endl;

	//int zifu = 'G';
	//if (T->Find(zifu)) {
	//	cout << "������� " << (char)zifu << " ���" << endl;
	//}
	//else {
	//	cout << "������� " << (char)zifu << " ���" << endl;
	//}
	//BTreeNode<int>* node = T->getData(zifu, root);
	//if (node) {
	//	cout << (char)node->data << endl;
	//	BTreeNode<int>* nodeParent = T->FindParent(root, node);
	//	if (!nodeParent) {
	//		cout << "�Ҳ������׽��" << endl;
	//	}
	//	else {
	//		cout << "��� " << (char)zifu << " �ĸ��׽����: " << (char)nodeParent->data << " ���" << endl;
	//		if (nodeParent->left) cout << "�ҵ�������: " << (char)nodeParent->left->data << endl;
	//		else cout << "��û������..." << endl;
	//		if (nodeParent->right) cout << "�ҵ��Һ�����: " << (char)nodeParent->right->data << endl;
	//		else cout << "��û���Һ���..." << endl;
	//	}
	//}
	//cout << "������ĸ߶�Ϊ: " << T->getHeight() << endl;

	//vector<int> vec = T->preOrder();
	//for (auto i : vec) {
	//	cout << (char)i;
	//}
	//cout << endl;

	//vec.clear();
	//vec = T->inOrder();
	//for (auto i : vec) {
	//	cout << (char)i;
	//}
	//cout << endl;

	//vec.clear();
	//vec = T->postOrder();
	//for (auto i : vec) {
	//	cout << (char)i;
	//}
	//cout << endl;

	//vec.clear();
	//vec = T->levelOrder();
	//for (auto i : vec) {
	//	cout << (char)i;
	//}
	//cout << endl;


	//cout << "-----------------------���ƶ�����-----------------------" << endl;
	// ���ƶ�����
	//vector<int> vec;
	//BTreeNode<int>* root = T->getRoot();
	//BTreeNode<int>* copyRoot = new BTreeNode<int>;
	//T->Copy(copyRoot);          // ����һ
	//T->CopyTree(root, copyRoot);  // ������

	//vec.clear();
	//cout << "��ȡǰ���������...." << endl;
	//cout << ">>>>";
	//T->preOrderTraversal(copyRoot, vec);
	//for (auto i : vec) {
	//	cout << (char)i;
	//}
	//cout << endl;

	//vec.clear();
	//cout << "��ȡ�����������...." << endl;
	//cout << ">>>>";
	//T->inOrderTraversal(copyRoot, vec);
	//for (auto i : vec) {
	//	cout << (char)i;
	//}
	//cout << endl;

	//vec.clear();
	//cout << "��ȡ�����������...." << endl;
	//cout << ">>>>";
	//T->postOrderTraversal(copyRoot, vec);
	//for (auto i : vec) {
	//	cout << (char)i;
	//}
	//cout << endl;

	//vec.clear();
	//cout << "��ȡ�����������...." << endl;
	//cout << ">>>>";
	//T->levelOrderTraversal(copyRoot, vec);
	//for (auto i : vec) {
	//	cout << (char)i;
	//}
	//cout << endl;
	//cout << "---------------------���ٸ��ƶ�����---------------------" << endl;
	//T->destroyCopyTree(copyRoot);
	//cout << "---------------------����ԭʼ������---------------------" << endl;
	//T->~BTree();
	//cout << "--------------------------End---------------------------" << endl;
	
	//Stack stack;
	//stack.Push(5.0);
	//stack.Push(6.5);
	//stack.Push(-3.0);
	//stack.Push(-8.0);

	//stack.DisplayStack();
	////cout << "Top: " << stack.Top() << endl;
	////stack.Pop();
	////cout << "Top: " << stack.Top() << endl;

	//
	////stack.Pop();
	//int ans = 0;
	//while (!stack.IsEmpty())
	//{
	//	stack.Pop();
	//}
	//cout << ans << endl;
	//stack.DisplayStack();

	Queue queue;
	cout << "Enqueue 5 items." << endl;
	for (int x = 0; x < 5; x++)
		queue.Enqueue(x);
	cout << "Now attempting to enqueue again..." << endl;
	queue.Enqueue(8);
	queue.DisplayQueue();
	double value;
	queue.Dequeue(value);
	cout << "Retrieved element = " << value << endl;
	queue.DisplayQueue();
	queue.Enqueue(7);
	queue.DisplayQueue();
	
	return 0;
}
