#include<bits/stdc++.h>

#define SZ 1234567
#define MOD7 10000007
#define MOD9 1000000009
#define pb push_back
#define pob pop_back
#define mp make_pair
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a,, min(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define loop(i, a, b) for(ll i=a; i<b; i++)
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

struct ListNode {
	ll val;
	ListNode *next;
};

ListNode* createLinkedList(ll n){
	ListNode *list = new ListNode;
	ListNode *head = list;
	for(ll i=1; i<=n; i++){
		list->val = i*10;
		if(i != n){
			list->next = new ListNode;
			list = list->next;
		}
		else{
			list->next = NULL;
		}
	}
	return head;
}

void printList(ListNode *head){
	ListNode *tmp = head;
	while(tmp != NULL){
		cout<<tmp->val<<" ";
		tmp = tmp->next;
	}
	cout<<endl;
}

ll calculateLength(ListNode *head){
	ListNode *tmp = head;
	ll listLength = 0;
	while(tmp != NULL){
		tmp = tmp->next;
		listLength++;
	}
	return listLength;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ListNode *head  = createLinkedList(10);
	cout<<calculateLength(head)<<endl;
	printList(head);
		
	return 0;
}
