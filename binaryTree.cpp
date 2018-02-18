#include <iostream>
#include <queue>
using namespace std;
struct node{
	int data;
	node* lchild;
	node* rchild;
	node* newNode(int v){
		node* Node=new node;
		Node->data=v;
		Node->lchild=Node->rchild=NULL;
		return Node;	
	}
	void search(node* root,int x,int newdata){
		if(root==NULL){
			return;
		}
		if(root->data==x){
			root->data=newdata;
		}
		search(root->lchild,x,newdata);
		search(root->rchild,x,newdata);
	}
	void lineSpace(int rank){
		for(int i=0;i<rank;i++)
			printf("  ");
		 
	} 
	void output(){
		printf("%d\n",this->data);
		
	}
	void preorder(int rank=0){
		lineSpace(rank);
		output(); 
		if(this->lchild!=NULL)
			this->lchild->preorder(rank+1);
		if(this->rchild!=NULL)
			this->rchild->preorder(rank+1);
	}
	void layerorder(){
		queue<node*>q;
		printf("%d ",this->data);
		q.push(this->lchild);
		q.push(this->rchild);
		while(!q.empty()){
			node* t=q.front();
			q.pop();
			if(t!=NULL){
				q.push(t->lchild);
				q.push(t->rchild);
				printf("%d ",t->data);
			}
		}
	}
};
#define MAXN 10000
	int n;
	int postorder[MAXN];
	int inorder[MAXN];
node* createBinTree(int postL,int postR,int inL,int inR){
	if(inL>inR)return NULL;
//	printf("create(%d,%d,%d,%d)\n",postL,postR,inL,inR);
	node* root=new node;
	root->data=postorder[postR];
	int k;
	
	for(k=inL;k<=inR;k++){
		if(inorder[k]==postorder[postR]){
			break;
		}
	}
	int numLeft=k-inL;
	root->lchild=createBinTree(postL,postL+numLeft-1,inL,k-1);
	root->rchild=createBinTree(postL+numLeft,postR-1,k+1,inR);
	return root;
}

int main(){
	freopen("binaryTree.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&postorder[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&inorder[i]);
	}
	node* parent=createBinTree(0,n-1,0,n-1);
	parent->layerorder();
	return 0;
} 
