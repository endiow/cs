#pragma once

#include <iostream>

using namespace std;

//单链表节点
struct  ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//单链表
class LinkedList
{
public:
	ListNode* head;

	LinkedList()
	{
		head = NULL;
	}

	~LinkedList()
	{
		//释放所有节点内存
		ListNode* cur = head;
		while (cur)
		{
			ListNode* nodeToDelete = cur;
			cur = cur->next;
			delete nodeToDelete;
		}
	}

	void addAtHead(int val)
	{
		//记录原有首节点
		ListNode* oldHead = head;
		//将新节点连到原有首节点
		head = new ListNode(val);
		head->next = oldHead;
	}

	void addAtTail(int val)
	{
		ListNode* newNode = new ListNode(val);
		ListNode* p = head;
		//head存在就加到最后，不存在则为head
		if (p)
		{
			while (p->next)
			{
				p = p->next;
			}
			p->next = newNode;
		}
		else
		{
			p = newNode;
		}
	}

	void insertNode(int pos, int val)
	{
		ListNode* newNode = new ListNode(val);
		ListNode* p = head;
		if (pos == 0)
		{
			cout << "头插" << endl;
			addAtHead(val);
		}
		else
		{
			while (p->next && pos > 1)
			{
				pos--;
				p = p->next;
			}
			if (p->next)
			{
				cout << "中插" << endl;
				newNode->next = p->next;
				p->next = newNode;
			}
			else
			{
				cout << "尾插" << endl;
				addAtTail(val);
			}
		}
	}

	void removeAtHead()
	{
		//如果是空链表，直接返回
		if (!head) return;
		//删除后新的首节点
		ListNode* newHead = head->next;
		delete head;
		head = newHead;
	}

	void removeAtTail()
	{
		//如果是空链表，直接返回
		if (!head) return;
		ListNode* p = head;
		while (p->next->next)
		{
			p = p->next;
		};
		p->next = NULL;
	}

	void deleteNode(int index)
	{
		if (index == 0)
		{
			removeAtHead();
			return;
		}
		ListNode* node = head;
		//node->next为要删除的node
		while (index > 1 && node->next)
		{
			node = node->next;
			index--;
		}
		if (index > 1)
		{
			cout << "索引过大" << endl;
			return;
		}
		else
		{
			//删除队尾元素
			if (node->next->next == NULL)
			{
				removeAtTail();
				return;
			}
			else
			{
				node->next = node->next->next;
			}
		}
	}

	void deletevalNode(ListNode* head, int val)
	{
		if (head->val == val)
		{
			removeAtHead();
			return;
		}
		ListNode* cur = head->next, * pre = head;
		while (cur->val != val && cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
		}
		if (cur->next != NULL)
		{
			pre->next = cur->next;
		}
		else if (cur->next == NULL && cur->val == val)
		{
			removeAtTail();
			return;
		}
		else if (cur->next == NULL && cur->val != val)
		{
			cout << "cound not find val" << endl;
		}
	}

	void reverse()
	{
		ListNode* prev = NULL;
		ListNode* curr = head;
		while (curr != NULL)
		{
			ListNode* temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		head = prev;
	}


	int reTopk(int pos)
	{
		if (!head || pos == 0)
		{
			return -1;
		}
		ListNode* slow = head;
		ListNode* fast = head;
		for (int i = 0; i < pos - 1; i++)
		{
			if (fast->next)
			{
				fast = fast->next;
			}
			else
			{
				cout << "index exceeding the length" << endl;
				return -1;
			}
		}
		//快指针走完整个，慢指针刚好走到pos
		while (fast->next)
		{
			fast = fast->next;
			slow = slow->next;
		}

		return slow->val;
	}

	void print()
	{
		ListNode* cur = head;
		while (cur)
		{
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}

	//合并两个链表（升序）
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode* preHead = new ListNode(-1);

		ListNode* prev = preHead;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				prev->next = l1;
				l1 = l1->next;
			}
			else
			{
				prev->next = l2;
				l2 = l2->next;
			}
			prev = prev->next;
		}

		// 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
		prev->next = l1 == NULL ? l2 : l1;

		return preHead->next;
	}

	//自顶向下归并排序
	ListNode* sortList(ListNode* head, ListNode* tail) 
	{
		if (head == NULL) 
		{
			return head;
		}
		if (head->next == tail) 
		{
			head->next = NULL;
			return head;
		}
		ListNode* slow = head, * fast = head;
		while (fast != tail) 
		{
			slow = slow->next;
			fast = fast->next;
			if (fast != tail) 
			{
				fast = fast->next;
			}
		}
		ListNode* mid = slow;
		//快指针到达链表末尾时，慢指针指向的链表节点即为链表的中点。
		LinkedList::head = mergeTwoLists(sortList(head, mid), sortList(mid, tail));
	}

};