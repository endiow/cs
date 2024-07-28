#pragma once

#include <iostream>

using namespace std;

//������ڵ�
struct  ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//������
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
		//�ͷ����нڵ��ڴ�
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
		//��¼ԭ���׽ڵ�
		ListNode* oldHead = head;
		//���½ڵ�����ԭ���׽ڵ�
		head = new ListNode(val);
		head->next = oldHead;
	}

	void addAtTail(int val)
	{
		ListNode* newNode = new ListNode(val);
		ListNode* p = head;
		//head���ھͼӵ���󣬲�������Ϊhead
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
			cout << "ͷ��" << endl;
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
				cout << "�в�" << endl;
				newNode->next = p->next;
				p->next = newNode;
			}
			else
			{
				cout << "β��" << endl;
				addAtTail(val);
			}
		}
	}

	void removeAtHead()
	{
		//����ǿ�����ֱ�ӷ���
		if (!head) return;
		//ɾ�����µ��׽ڵ�
		ListNode* newHead = head->next;
		delete head;
		head = newHead;
	}

	void removeAtTail()
	{
		//����ǿ�����ֱ�ӷ���
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
		//node->nextΪҪɾ����node
		while (index > 1 && node->next)
		{
			node = node->next;
			index--;
		}
		if (index > 1)
		{
			cout << "��������" << endl;
			return;
		}
		else
		{
			//ɾ����βԪ��
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
		//��ָ��������������ָ��պ��ߵ�pos
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

	//�ϲ�������������
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

		// �ϲ��� l1 �� l2 ���ֻ��һ����δ���ϲ��꣬����ֱ�ӽ�����ĩβָ��δ�ϲ����������
		prev->next = l1 == NULL ? l2 : l1;

		return preHead->next;
	}

	//�Զ����¹鲢����
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
		//��ָ�뵽������ĩβʱ����ָ��ָ�������ڵ㼴Ϊ������е㡣
		LinkedList::head = mergeTwoLists(sortList(head, mid), sortList(mid, tail));
	}

};