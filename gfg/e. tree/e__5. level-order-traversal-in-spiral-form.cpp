//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> findSpiral(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends




/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
//Q. https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    if(root == NULL) return ans;
    vector<vector<int>> vec;
    vector<int> v;
    queue<Node*> q;
    queue<Node*> n;
    

    q.push(root); //10
    
    while(!q.empty()) {
        
        Node* nod = q.front(); //20
        q.pop();
        
        v.push_back(nod->data);
        
        if(nod->left) n.push(nod->left); //20
        if(nod->right) n.push(nod->right); //30
    
        if(q.empty()) {
            vec.push_back(v);
            v.clear();
            swap(q,n);
        }
    }
    
    bool rev=true;
    
    for(int i=0; i<vec.size(); i++) {
        if(rev) {
            for(int j=vec[i].size()-1; j>=0; j--) {
                ans.push_back(vec[i][j]);
            }
        } else {
            for(int j=0; j<vec[i].size(); j++) {
                ans.push_back(vec[i][j]);
            }
        }
        rev = !rev;
    }
    return ans;
}
