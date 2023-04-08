/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

private: 
    map<Node*, Node*> has;
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        if(has.find(node) == has.end()){
            has[node] = new Node(node->val);
            for(auto i : node -> neighbors){
                has[node]->neighbors.push_back(cloneGraph(i));
            }
        }
        return has[node];
    }
};