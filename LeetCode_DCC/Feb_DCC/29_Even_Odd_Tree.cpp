#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int v)
    {
        this->data = v;
        this->left = NULL;
        this->right = NULL;
    }
};

 bool isEvenOddTree(Node* root) {
        int ind=0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            if(ind%2)
            {
                int v=INT_MAX;
                for(int i=0;i<n;i++)
                {
                    if(q.front()->data%2 || q.front()->data>=v) return false;
                    else
                    {
                        if(q.front()->left) q.push(q.front()->left);
                        if(q.front()->right)    q.push(q.front()->right);
                        v=q.front()->data;
                        q.pop();
                    }
                }

            }
            else
            {
                int v=INT_MIN;
                for(int i=0;i<n;i++)
                {
                    if(q.front()->data%2==0 || q.front()->data<=v) return false;
                    else
                    {
                        if(q.front()->left)     q.push(q.front()->left);
                        if(q.front()->right)    q.push(q.front()->right);
                        v=q.front()->data;
                        q.pop();
                    }
                }

            }
            ind++;
            
        }
        return true;
        
    }