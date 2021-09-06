#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *left,*right;
    node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
};
struct node *create()
{
    int data;
    struct node *newnode;
    cout << "\nEnter the data:";
    cin >>data;
    newnode=(struct node *)malloc(sizeof(struct node));
    
    if(data==-1){
        return 0;
    }
    newnode->data=data;
    cout <<"\nEnter  left node of "<<data;
    newnode->left=create();
    
    cout <<"\nenter right node of"<<data;
    newnode->right=create();
     return newnode;
}
void preorder(struct node*node)
{
    if(node==0)
    {
       return ; 
    }
        
    cout<<node->data <<" ";
    
   preorder(node->left);
    
    preorder(node->right);
}
void postorder(struct node *node)
{
    if (node==0)
    {
        return ; 
    }
       
    
    postorder(node->left);
    
    postorder(node->right);
  
    cout << node->data <<" ";
    
}
void inorder(struct node *node)
{
    if(node==0)
    {
        return ;
    }
    
     inorder(node->left);
    
    cout << node->data<<" ";
    
     inorder(node->right);
}

int main()
{
    int choice;
	struct node *root=create();
	while(1)
    {
        
        cout<<"1.Inorder"<<endl;
        cout<<"2.Preorder"<<endl;
        cout<<"3.postorder"<<endl;
        
        std::cin>>choice;
        switch(choice)
        {
            case 1:cout<<"Inorder Traversal\n";
                    inorder(root);
                    cout<<endl;
                    break;
            case 2:cout<<"Preorder Traversal\n";
                    preorder(root); 
                    cout<<endl;
                    break;
            case 3:cout<<"Postorder Traversal\n";
                    postorder(root); 
                    cout<<endl;
                    break;

            default:exit(0);
        }
    }
	
}