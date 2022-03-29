#include <bits/stdc++.h>
using namespace std;

struct Node {
	int value;
	Node *left, *right;
	Node(int v) {
		this->value = v;
		left = right = NULL;
	}
};

Node* init_test_tree() {
	Node* root = new Node(8);
	root->left = new Node(5);
	root->right = new Node(10);
	root->left->left = new Node(1);
	root->left->right = new Node(7);
	root->right->right = new Node(12);
	return root;
}

void preorder(Node* root) {
	if (root == NULL) return;
	cout << root->value << "->";
	preorder(root->left);
	preorder(root->right);
}

void iterative_preorder(Node* root) {
	stack<Node*> st;
	st.push(root);
	while(!st.empty()) {
		Node* cur = st.top(); st.pop();
		if (cur->right) st.push(cur->right);
		if (cur->left) st.push(cur->left);
		cout << cur->value << "->";
	}
}

void inorder(Node* root) {
	if (root == NULL) return;
	inorder(root->left);
	cout << root->value << "->";
	inorder(root->right);
}

void iterative_inorder(Node* root) {
	stack<Node*> st;
	Node* cur = root;
	while(cur || !st.empty()) {
		if (cur) {
			st.push(cur);
			cur = cur->left;
		} else {
			cur = st.top(); st.pop();
			cout << cur->value << "->";
			cur = cur->right;
		}
	}
}

void postorder(Node* root) {
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->value << "->";
}

void iterative_postorder_2_stacks(Node* root) {
	stack<Node*> in;
	stack<int> out;
	in.push(root);
	while(!in.empty()) {
		Node* cur = in.top(); in.pop();
		out.push(cur->value);
		if (cur->left) in.push(cur->left);
		if (cur->right) in.push(cur->right);
	}
	while(!out.empty()) {
		cout << out.top() << "->";
		out.pop();
	}
}

void iterative_postorder_1_stack(Node* root) {
	stack<Node*> st;
	Node* cur = root;
	Node* prev = NULL;
	while(cur || !st.empty()) {
		if (cur) {
			st.push(cur);
			cur = cur->left;
		} else {
			cur = st.top();
			if (cur->right == NULL || cur->right == prev) {
				cout << cur->value << "->";
				st.pop();
				prev = cur;
				cur = NULL;
			} else { //right node hasn't handled yet
				cur = cur->right;
			}
		}
	}
}

int32_t main()
{
	Node* root = init_test_tree();
	preorder(root);
	cout << endl;
	iterative_preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	iterative_inorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	iterative_postorder_2_stacks(root);
	cout << endl;
	iterative_postorder_1_stack(root);
	cout << endl;

	return 0;
}
