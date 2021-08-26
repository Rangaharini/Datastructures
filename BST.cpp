#include<iostream>
using namespace std;
#define SPACE 10

struct node{
    int data;
    struct node *left=0,*right=0;
};

struct node* create(int data){
    struct node *temp=new node();
    temp->data=data;
    return temp;
}
struct node *insert(struct node*temp,int key){
    if(temp==0){
        return create(key);
    }
    if(temp->data>key){
        temp->left=insert(temp->left,key);
    }
    if(temp->data<key){
        temp->right=insert(temp->right,key);
    }
    return temp;
}
int displaytree(struct node *node)
{
    if(node==NULL){
        return 0;
    }
    displaytree(node->left);
    cout<<" "<<node->data;
    
    displaytree(node->right);
}
int search (struct node*temp,int key){
    if(temp==0){
        return 0;
    }
    if(temp->data==key){
        return 1;
    }
    if(temp->data>key){
        return search(temp->left,key);
        
    }
      return search(temp->right,key);
    
}
node* minvalue(node*temp){
    node* current=temp;
    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}
struct node* deletenode(node*r ,int v){
    if(r==0){
        return r;
    }
    else if(v < r->data){
        r->left=deletenode(r->left,v);
    }
    else if(v >r->data){
        
        r->right=deletenode(r->right,v);
    }
    else{
        if(r->left==NULL){
            node*temp=r->right;
            delete r;
            return temp;
        }
        else if(r->right == NULL){
            node*temp=r->left;
            delete r;
            return temp;
        }
        else{
            node *temp=minvalue(r->right);
            r->data=temp->data;
            r->right=deletenode(r->right,temp->data);
            
        }
    }
    return r;
}
int height(node * r) {
    if (r == NULL)
      return -1;
    else {
      /* compute the height of each subtree */
      int lheight = height(r -> left);
      int rheight= height(r -> right);

      /* use the larger one */
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }
  void printGivenLevel(node * r, int level) {
    if (r == NULL)
      return;
    else if (level == 0)
      cout <<"\n"<< r -> data << " ";
    else // level > 0  
    {
      printGivenLevel(r -> left, level - 1);
      printGivenLevel(r -> right, level - 1);
    }
  }
  void print2D(node * r, int space) {
    if (r == NULL) // Base case  1
      return;
    space += SPACE; // Increase distance between levels   2
    print2D(r -> right, space); // Process right child first 3 
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5 
      cout << " "; // 5.1  
    cout << r -> data << "\n"; // 6
    print2D(r -> left, space); // Process left child  7
  }
int main()
{
    struct node* root=insert(root,40);
    insert(root,20);
    insert(root,15);
    insert(root,5);
    insert(root,4);
    insert(root,25);
    insert(root,30);
    insert(root,22);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    insert(root,100);
    
    displaytree(root);
    if(search(root,60)){
        cout<<"\nElement found";
    }
    else{
        cout<<"\nElement not found";
    }
    print2D(root, 40);
    deletenode(root,40);
    displaytree(root);
    cout<<"\nRoot is:";
    cout  << root->data;
    int x=height(root);
    cout<<" "<<x;
    printGivenLevel(root,2);
    
    
}






