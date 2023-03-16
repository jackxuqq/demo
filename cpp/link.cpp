#include <iostream>

struct Node {
	int val;
	Node* next;
};

Node* makeLink(){
	vector<int> arr = {1,2,3,4,5}
	Node * pre = NULL;
	for (int i = arr.size()-1; i>=0; i--){
		Node *item = new Node(); 
		item->val = arr[i];
		item->next = pre;
	       	pre = item;
	}
	return pre;
}

Node* procLink(Node * head, int m, int n){
	//step1: get link1 tail
	Node * tail1 = NULL;
	int i = 0;
	for (Node* p=head;p!=NULL;p=p.Next){
		i++;
		if (i == m-1){
			tail = p;
			break;
		}
	}

	//step2: get link2
	Node* link2 = tail->next;
	Node* link3 = NULL;
	int j = 0;
	for (Node* p=link2; p!=NULL;p=p->Next){
		j++;
		if (m+j == n){
			link3 = p->next;
			p->next = NULL;
			break;
		}
	}

	//step3: revert link2
	Node *  pre = NULL;
	for (Node* p=link2;p!=NULL;){
		Node* tmp = p->next;
		p->next = pre;
		pre=p;
		p=tmp;
	}

	//step4: join link1\2\3
	tail->next = pre;
	link2->next = link3;
	return head;	
}

void printLink(Node* head){
	for(Node *p = head; p!= NULL;p=p->next){
		printf("%d\n", p->val);
	}
}

int main(){
	//make link input
	makeLink();

	//revert part link
	procLink();

	//print link
	printLink();
	return 0;
}
