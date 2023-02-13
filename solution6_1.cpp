#include <iostream>
#include <memory>

using namespace std;

struct node
{
  node(int val): key_value(val), left(nullptr), right(nullptr) {}
  int key_value;
  unique_ptr<node> left;
  unique_ptr<node> right;
};

class btree
{
    unique_ptr<node> root;
    public:
        btree(): root(nullptr){};
        //~btree();
 
        void insert(int key){
            return insert(key, root);
        }
        unique_ptr<node>& search(int key){
            return search(key, root);
        }
        void destroy_tree(){
            return destroy_tree(root);
        }
 
    private:
        void destroy_tree(unique_ptr<node>& leaf){
            if(leaf){
                destroy_tree(leaf->left);
                destroy_tree(leaf->right);
                leaf.release();
            }
            
        };
        void insert(int key, unique_ptr<node>& leaf){
            if(leaf){
                key < leaf->key_value ? insert(key, leaf->left) : insert(key, leaf->right);
            } else {
                leaf = make_unique<node>(key);
            }
        };
        unique_ptr<node>& search(int key, unique_ptr<node>& leaf){
            if (not root){
                return root;
            }
            if(key == leaf->key_value){
                return leaf;
            } else if (key < leaf->key_value){
                return search(key, leaf->left);
            } else {
                return search(key, leaf->right);
            }
        }
};

int main(){
    auto tree{make_unique<btree>()};
    tree->insert(1);
    tree->insert(3);
    cout<< (tree->search(3))->key_value <<endl;


    return 0;
}