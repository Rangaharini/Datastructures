#include<iostream>
#include<math.h>
using namespace std;
class Minheap{
    public:
    int *arr;
    int capacity;
    int heap_size;
    Minheap(int cap){
        heap_size=0;
        capacity=cap;
        arr=new int [cap];
    }
    void swap(int &x,int &y){
        int temp=x;
        x=y;
        y=temp;
    }
    int parent(int i){
        return (i-2)/2;
    }
    int left(int i){
        return (2*i+1);
    }
    int right(int i){
        return (2*i+2);
    }
    
    void Minheapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && arr[l] < arr[i])
      smallest = l;
    if (r < heap_size && arr[r] < arr[smallest])
      smallest = r;
    if (smallest != i) {
      swap( arr[i],arr[smallest]);
      Minheapify(smallest);
    }
  }
     void insert(int key){
        int i;
        if(heap_size==capacity){
            cout<<"Overflow";
        }
            heap_size++;
            i=heap_size-1;
            arr[i]=key;
            for(i=heap_size/2-1;i>=0;i--){
                Minheapify(i);
            }
    } 
        
        void decrease(int i,int val){
        arr[i]=val;
        while(i!=0 && arr[i]<arr[parent(i)]){
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
    }
   
    
    
    int extract(){
            if(heap_size<0){
                cout<<"empty";
            }
            if(heap_size==1){
                heap_size--;
                return arr[0];
            }
            int root=arr[0];
           
            arr[0]=arr[heap_size-1];
            heap_size--;
            Minheapify(0);
            return root;
    }
        
     void deleteusingindex(int i){
        decrease(i,-1);
        extract();
        
        }
    void print(){
        int i;
            for( i=0;i<heap_size;i++)
            {
                cout<<arr[i]<<":"<<i<<endl;
            }
        }
        int height() {
         return ceil(log2(heap_size + 1)) - 1;
        }
    int search(int num){
        int i;
            if(arr[0]==num){
                return -1;
            }
            for(i=1;i<heap_size;i++){
                if(arr[i]==num){
                    return i;
                }
            }
            return 0;
        
    }
    void deletionn(int num){
        int i;
        if(arr[0]==num){
            i=0;
            goto del;
        }
        i=search(num);
        if(i){
            del:
                swap(arr[i],arr[heap_size-1]);
                heap_size--;
                for(i=0;i<heap_size/2-1;i++) //for(i=heap_size/2-1;i>=0;i--)
                {
                    Minheapify(i);
                }
        }
        else{
            cout<<"\n not found"<<endl;
        }
    }

};


int main(){
    Minheap obj(10);
    obj.insert(10);
    obj.insert(5);
    obj.insert(7);
    obj.insert(25);
    obj.insert(2);
    obj.print();
    cout<<"---------------------"<<endl;
    int a=obj.search(2);
    if(a==-1){
        cout<<"found at index:0"<<endl;
    }
    else if(a){
        cout<<"found at index:"<<a<<endl;
    }
    else{
        cout<<"not found";
    }
    
    cout<<"-----------------------"; 
    obj.deletionn(2);
    cout<<"-----------------------"<<endl; 
    obj.print();
   
    
    obj.deleteusingindex(1);
    cout<<"-----------------------"<<endl; 
    obj.print();
    
    
    cout<<"-----------------------"<<endl; 
    
    cout<<"\nHeight: "<<obj.height()<<endl;
    
    obj.extract();
     cout<<"-----------------------"<<endl; 
     obj.print();
   
}

    


