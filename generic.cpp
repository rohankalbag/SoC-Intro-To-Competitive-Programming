//header files
#include <bits/stdc++.h>
using namespace std;
 
//@author: Rohan Rajesh Kalbag
 
//type definitions
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int,int> mii;
typedef vector<long long int> vll;
typedef priority_queue<int> pqi;
typedef priority_queue<int, std::vector<int>, std::greater<int>> pqd;
 
//definitions
#define pb push_back
#define sz size()
#define ff first
#define ss second
#define pi 3.14159265359
#define endl '\n'
 
//custom classes go here
template <typename T> struct unionfind{
    int initsize;
    vector<int> rind;
    vector<int> sizes;
    map<T,int> hashtable;
    vector<T> objs;
 
    unionfind(vector<T> objects){
        // objects must have distinct values
        int n = objects.size();
        initsize = n;
        for(int i=0;i<n;i++){
            rind.push_back(i);
            (hashtable)[objects[i]] = i;
            sizes.push_back(1);
            objs.push_back(objects[i]);
        }
    }
 
    T find(T obj2){
        /*  takes in an object that was passed in objects during creation returns the root object
            also implements path compression technique
        */
        int ind = (hashtable)[obj2];
        int root = ind;
        while(root != (rind)[root]){
            root = (rind)[root];
        }
        while(ind != root){
            int parent = (rind)[ind];
            (rind)[ind] = root;
            ind = parent;
        }
        return (objs)[root];
    }
 
    bool connected(T obj1, T obj2){
        // check if two objects are connected
        return(find(obj1) == find(obj2));
    }
 
    int compSize(T obj1){
        // return number of components in the group containing obj1
        return (sizes)[(hashtable)[find(obj1)]];
    }
 
    int noofcomponents(){
        //O(1)
        // total number of groups
        return initsize;
    }
 
    void unify(T obj1, T obj2){
        //  unify two objects if they are not connected
        if(connected(obj1,obj2))
            return;
        int ind1 = (hashtable)[find(obj1)];
        int ind2 = (hashtable)[find(obj2)];
        if((sizes)[ind1] < (sizes)[ind2]){
            (sizes)[ind2] += (sizes)[ind1];
            (rind)[ind1] = ind2;
            (sizes)[ind1] = 0;
        }
        else{
            (sizes)[ind1] += (sizes)[ind2];
            (rind)[ind2] = ind1;
            (sizes)[ind2] = 0;
        }
 
        initsize-=1;
    }
};
 
struct trie{
    //trie data structure
 
    struct trienode{
        //has support for lowercase strings
        trienode * children[26];
        bool isLeaf;
 
        trienode(){
            isLeaf = false;
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
        }
 
        ~trienode(){
            for(int i=0;i<26;i++){
                delete(children[i]);
            }
        }
    };
 
    trienode* root;
 
    trie(){
        root = new trienode;
    }
 
    string to_lowercase(string s){
        //convert string to lowercase
        transform(s.begin(),s.end(),s.begin(),::tolower);
        return s;
    }
 
    void insert(string s){
        //inserts the lowercase word in the trie
        s = to_lowercase(s);
        trienode * n = root;
        for(int i=0; i<(int)s.size();i++){
            int index = s[i] - 'a';
            if(n->children[index]){
                n = n->children[index];
            }
            else{
                n->children[index] = new trienode;
                n = n->children[index];
            }
        }
        n->isLeaf = true;
    }
 
    bool search(string s){
        //checks if lowercase exists in the tree
        s = to_lowercase(s);
        trienode * n = root;
        for(int i=0;i<(int)s.size();i++){
            int index = s[i] - 'a';
            if(n->children[index]){
                n = n->children[index];
            }
            else{
                return false;
            }
        }
        return (n->isLeaf);
    }
 
    void alphabetical(){
        //print all words in alphabetical order
        preorder(root);
        cout<<endl;
    }
 
    void preorder(trienode * n, string s = ""){
        //preorder traversal of all the words in alphabetical order
        if(n == nullptr)
            return;
        else{
            for(int i=0;i<26;i++){
                if(n->children[i]!=nullptr){
                    if(n->children[i]->isLeaf){
                        s.push_back(char(i+97));
                        cout<<s<<endl;
                    }
                    else{
                        string t = s;
                        t.push_back(char(i+97));
                        preorder(n->children[i], t);
                    }
                }
            }
        }
    }
};
 
void testcase(){
    //code for a specific testcase
    //make sure to include cin.ignore() incase a string needs to be inputted after an int
    //getline(cin, s); to get a line as string
}
 
int main(){
    //driver code
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    cin.ignore();
    while(t--){
        testcase();
    }
}