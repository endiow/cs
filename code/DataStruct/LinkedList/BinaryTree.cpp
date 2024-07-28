#include "BinaryTree.h"

template<class T>
BTree<T>::BTree(string str) 
{
	createTree(root, str);
	cout << "报告：创建一颗二叉树，完成！！！" << endl;
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

// 判二叉树空否？
template<class T>
bool BTree<T>::IsEmpty() 
{
	return (root == nullptr) ? true : false;
}

// 计算结点个数
template<class T>
int BTree<T>::Size(BTreeNode<T>* cur) 
{
	if (cur == nullptr)
		return 0;
	else
		return 1 + Size(cur->left) + Size(cur->right);
}

// 获取结点个数
template<class T>
int BTree<T>::getSize() {
	return Size(root);
}

// 取得结点数据
template<class T>
BTreeNode<T>* BTree<T>::getData(T& item, BTreeNode<T>* cur) {
	if (cur == nullptr) return nullptr;
	if (cur->data == item) return cur;
	return getData(item, cur->left) != nullptr ? getData(item, cur->left) : getData(item, cur->right);
}

// 判断item是否在树中
template<class T>
bool BTree<T>::Find(T& item) {
	if (this->getData(item, root) == nullptr) return false;
	else return true;
}

// 求树高度
template<class T>
int BTree<T>::Height(BTreeNode<T>* bt) {
	if (bt == nullptr) return 0;
	else {
		int leftH = Height(bt->left);
		int rightH = Height(bt->right);
		return (leftH > rightH) ? leftH + 1 : rightH + 1;
	}
}

// 获取树高度
template<class T>
int BTree<T>::getHeight() {
	return Height(root);
}

// 获取根 
template<class T>
BTreeNode<T>* BTree<T>::getRoot() {
	if (!root) return nullptr;
	else {
		return this->root;
	}
}

// 析构函数
template<class T>
BTree<T>::~BTree<T>() {
	//cout << "调用析构函数" << endl;
	destroyTree(root);
	cout << "报告，这棵树已经销毁完毕!!!" << endl;
}

// 销毁二叉树 
template<class T>
void BTree<T>::destroyTree(BTreeNode<T>* bt) {
	// 后序遍历删除根为subTree的子树；
	if (bt != nullptr) {
		destroyTree(bt->left);    //删除左子树
		destroyTree(bt->right);   //删除右子树
		delete bt; 			      //删除根结点
	}
}

// 前序遍历
template<class T>
void BTree<T>::preOrderTraversal(BTreeNode<T>* cur, vector<int>& vec) {
	if (cur == nullptr)
		return;
	vec.push_back(cur->data);           // 中
	preOrderTraversal(cur->left, vec);  // 左
	preOrderTraversal(cur->right, vec); // 右
}

// 调用前序遍历，返回vector
template<class T>
vector<T> BTree<T>::preOrder() {
	cout << "获取前序遍历数组...." << endl;
	cout << ">>>>";
	vector<T> resVec;
	preOrderTraversal(root, resVec);
	return resVec;
}

// 中序遍历
template<class T>
void BTree<T>::inOrderTraversal(BTreeNode<T>* cur, vector<int>& vec) {
	if (cur == nullptr)
		return;
	inOrderTraversal(cur->left, vec);  // 左
	vec.push_back(cur->data);          // 中
	inOrderTraversal(cur->right, vec); // 右
}

// 调用中序遍历，返回vector
template<class T>
vector<T> BTree<T>::inOrder() {
	cout << "获取中序遍历数组...." << endl;
	cout << ">>>>";
	vector<T> resVec;
	inOrderTraversal(root, resVec);
	return resVec;
}

// 后序遍历
template<class T>
void BTree<T>::postOrderTraversal(BTreeNode<T>* cur, vector<int>& vec) {
	if (cur == nullptr)
		return;
	postOrderTraversal(cur->left, vec);  // 左
	postOrderTraversal(cur->right, vec); // 右
	vec.push_back(cur->data);            // 中
}

// 调用后序遍历，返回vector
template<class T>
vector<T> BTree<T>::postOrder() {
	cout << "获取后序遍历数组...." << endl;
	cout << ">>>>";
	vector<T> resVec;
	postOrderTraversal(root, resVec);
	return resVec;
}

// 层序遍历
template<class T>
void BTree<T>::levelOrderTraversal(BTreeNode<T>* cur, vector<int>& vec) {
	if (cur == nullptr) return;
	queue<BTreeNode<T>*> Queue;
	BTreeNode<T>* p;
	Queue.push(cur); // 根结点入队列
	while (!Queue.empty()) {
		p = Queue.front();
		//cout << p->data << " ";//输出出队结点的数据
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

// 调用层序遍历，返回vector
template<class T>
vector<T> BTree<T>::levelOrder() {
	cout << "获取层序遍历数组...." << endl;
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
		copyRoot->data = root->data;           //复制根节点
		CopyTree(root->left, copyRoot->left);  //递归复制左子树
		CopyTree(root->right, copyRoot->right);//递归复制左子树
	}
}

template<class T>
void BTree<T>::Copy(BTreeNode<T>*& copyRoot) {
	CopyTree(root, copyRoot);
}

template<class T>
void BTree<T>::destroyCopyTree(BTreeNode<T>*& copyRoot) {
	destroyTree(copyRoot);
	cout << "报告，复制二叉树已销毁完毕!!!" << endl;
}

template<class T>
BTreeNode<T>* BTree<T>::FindParent(BTreeNode<T>* root, BTreeNode<T>* node) {

	if (root == nullptr) return nullptr;
	if (root->left == node || root->right == node)
		return root;	     //找到, 返回父结点地址
	BTreeNode <T>* p;
	if ((p = FindParent(root->left, node)) != nullptr)
		return p;	         //递归在左子树中搜索
	else return FindParent(root->right, node);
}