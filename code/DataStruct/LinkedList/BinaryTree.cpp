#include "BinaryTree.h"

template<class T>
BTree<T>::BTree(string str) 
{
	createTree(root, str);
	cout << "���棺����һ�Ŷ���������ɣ�����" << endl;
}

template<class T>
void BTree<T>::createTree(BTreeNode<T>*& bt, string str) 
{
	static int i = 0;
	char ch = ' ';
	ch = str[i++];

	if (ch == '#') bt = nullptr;
	else 
	{
		bt = new BTreeNode<T>(ch);
		createTree(bt->left, str);
		createTree(bt->right, str);
	}
};

// �ж������շ�
template<class T>
bool BTree<T>::IsEmpty() 
{
	return (root == nullptr) ? true : false;
}

// ���������
template<class T>
int BTree<T>::Size(BTreeNode<T>* cur) 
{
	if (cur == nullptr)
		return 0;
	else
		return 1 + Size(cur->left) + Size(cur->right);
}

// ��ȡ������
template<class T>
int BTree<T>::getSize() {
	return Size(root);
}

// ȡ�ý������
template<class T>
BTreeNode<T>* BTree<T>::getData(T& item, BTreeNode<T>* cur) {
	if (cur == nullptr) return nullptr;
	if (cur->data == item) return cur;
	return getData(item, cur->left) != nullptr ? getData(item, cur->left) : getData(item, cur->right);
}

// �ж�item�Ƿ�������
template<class T>
bool BTree<T>::Find(T& item) {
	if (this->getData(item, root) == nullptr) return false;
	else return true;
}

// �����߶�
template<class T>
int BTree<T>::Height(BTreeNode<T>* bt) {
	if (bt == nullptr) return 0;
	else {
		int leftH = Height(bt->left);
		int rightH = Height(bt->right);
		return (leftH > rightH) ? leftH + 1 : rightH + 1;
	}
}

// ��ȡ���߶�
template<class T>
int BTree<T>::getHeight() {
	return Height(root);
}

// ��ȡ�� 
template<class T>
BTreeNode<T>* BTree<T>::getRoot() {
	if (!root) return nullptr;
	else {
		return this->root;
	}
}

// ��������
template<class T>
BTree<T>::~BTree<T>() {
	//cout << "������������" << endl;
	destroyTree(root);
	cout << "���棬������Ѿ��������!!!" << endl;
}

// ���ٶ����� 
template<class T>
void BTree<T>::destroyTree(BTreeNode<T>* bt) {
	// �������ɾ����ΪsubTree��������
	if (bt != nullptr) {
		destroyTree(bt->left);    //ɾ��������
		destroyTree(bt->right);   //ɾ��������
		delete bt; 			      //ɾ�������
	}
}

// ǰ�����
template<class T>
void BTree<T>::preOrderTraversal(BTreeNode<T>* cur, vector<int>& vec) {
	if (cur == nullptr)
		return;
	vec.push_back(cur->data);           // ��
	preOrderTraversal(cur->left, vec);  // ��
	preOrderTraversal(cur->right, vec); // ��
}

// ����ǰ�����������vector
template<class T>
vector<T> BTree<T>::preOrder() {
	cout << "��ȡǰ���������...." << endl;
	cout << ">>>>";
	vector<T> resVec;
	preOrderTraversal(root, resVec);
	return resVec;
}

// �������
template<class T>
void BTree<T>::inOrderTraversal(BTreeNode<T>* cur, vector<int>& vec) {
	if (cur == nullptr)
		return;
	inOrderTraversal(cur->left, vec);  // ��
	vec.push_back(cur->data);          // ��
	inOrderTraversal(cur->right, vec); // ��
}

// �����������������vector
template<class T>
vector<T> BTree<T>::inOrder() {
	cout << "��ȡ�����������...." << endl;
	cout << ">>>>";
	vector<T> resVec;
	inOrderTraversal(root, resVec);
	return resVec;
}

// �������
template<class T>
void BTree<T>::postOrderTraversal(BTreeNode<T>* cur, vector<int>& vec) {
	if (cur == nullptr)
		return;
	postOrderTraversal(cur->left, vec);  // ��
	postOrderTraversal(cur->right, vec); // ��
	vec.push_back(cur->data);            // ��
}

// ���ú������������vector
template<class T>
vector<T> BTree<T>::postOrder() {
	cout << "��ȡ�����������...." << endl;
	cout << ">>>>";
	vector<T> resVec;
	postOrderTraversal(root, resVec);
	return resVec;
}

// �������
template<class T>
void BTree<T>::levelOrderTraversal(BTreeNode<T>* cur, vector<int>& vec) {
	if (cur == nullptr) return;
	queue<BTreeNode<T>*> Queue;
	BTreeNode<T>* p;
	Queue.push(cur); // ����������
	while (!Queue.empty()) {
		p = Queue.front();
		//cout << p->data << " ";//������ӽ�������
		vec.push_back(p->data);
		Queue.pop();
		if (p->left != nullptr) {
			Queue.push(p->left);
		}
		if (p->right != nullptr) {
			Queue.push(p->right);
		}
	}
}

// ���ò������������vector
template<class T>
vector<T> BTree<T>::levelOrder() {
	cout << "��ȡ�����������...." << endl;
	cout << ">>>>";
	vector<T> resVec;
	levelOrderTraversal(root, resVec);
	return resVec;
}

template<class T>
void BTree<T>::CopyTree(BTreeNode<T>* root, BTreeNode<T>*& copyRoot) {
	if (!root) {
		copyRoot = nullptr;
	}
	else {
		copyRoot = new BTreeNode<T>;
		copyRoot->data = root->data;           //���Ƹ��ڵ�
		CopyTree(root->left, copyRoot->left);  //�ݹ鸴��������
		CopyTree(root->right, copyRoot->right);//�ݹ鸴��������
	}
}

template<class T>
void BTree<T>::Copy(BTreeNode<T>*& copyRoot) {
	CopyTree(root, copyRoot);
}

template<class T>
void BTree<T>::destroyCopyTree(BTreeNode<T>*& copyRoot) {
	destroyTree(copyRoot);
	cout << "���棬���ƶ��������������!!!" << endl;
}

template<class T>
BTreeNode<T>* BTree<T>::FindParent(BTreeNode<T>* root, BTreeNode<T>* node) {

	if (root == nullptr) return nullptr;
	if (root->left == node || root->right == node)
		return root;	     //�ҵ�, ���ظ�����ַ
	BTreeNode <T>* p;
	if ((p = FindParent(root->left, node)) != nullptr)
		return p;	         //�ݹ���������������
	else return FindParent(root->right, node);
}