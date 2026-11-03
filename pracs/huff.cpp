#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>
 
using namespace std;


class Node{
    public:
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f){
        ch=c;
        freq=f;
        left=nullptr;
        right=nullptr;
    }
};

class Compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->freq>b->freq;
    }
};

class Huffman{
    public:
    Node* root;
    string message;
    int freq_table[256]={0};
    unordered_map<char,int> map;

    Huffman(){
        root=nullptr;
        message="";
    }

    void getter(){
        cout<<"Enter message to be encoded "<<endl;
        cin>>message;
        for(int i=0;i<message.size();i++){
            map[message[i]]++;
        }
    }

    void make_tree(){
        priority_queue<Node*,vector<Node*>, Compare> pq;
        for(auto it=map.begin();it!=map.end();it++){
            Node* t=new Node(it->first,it->second);
            pq.push(t);
        }

        while(pq.size()>1){
            Node* l;
            Node* r;
            Node* parent;
            l=pq.top();
            pq.pop();
            r=pq.top();
            pq.pop();
            parent=new Node('$',l->freq+r->freq);
            parent->left=l;
            parent->right=r;
            pq.push(parent);
            
        }
        root=pq.top();
    }

    void print_codes(){
        //
        vector<Node*> visited;
        queue<pair<Node*,string>> q;
        q.push({root,""});
        //visited.push_back(root);
        
        while(!q.empty()){
            Node* temp=q.front().first;
            string code=q.front().second;
            q.pop();
            if(temp->left==nullptr && temp->right==nullptr){
                cout<<temp->ch<<":"<<code<<endl;
            }
            else{
                if(temp->left!=nullptr){
                    string code1=code+"0";
                    q.push({temp->left,code1});
                }
                if(temp->right!=nullptr){
                    string code2=code+"1";
                    q.push({temp->right,code2});
                }     
            }
        }
    }


};

int main(){
    Huffman h;
    h.getter();
    h.make_tree();
    h.print_codes();
    return 0;
}