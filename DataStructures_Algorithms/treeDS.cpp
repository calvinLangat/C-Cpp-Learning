#include<iostream>


class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int find_sum(Node* root);
int search(int arr[], int target, int size);
int binary_search(int arr[], int target, int size);
int main(){

    Node a = Node(2);
    Node b = Node(3);
    Node c = Node(4);
    Node d = Node(5);
    Node e = Node(6);
    Node f = Node(7);

    a.left = &b;
    a.right = &c;

    b.left = &d;
    b.right = &e;

    c.right = &f;
    std::cout << "The total of the tree is "<< find_sum(&a) << "\n";

    int arr[8] = {-2, 3, 4, 7, 8, 9, 11, 13};
    int target = 3;
    int size = sizeof(arr)/sizeof(arr[0]);
    std::cout << "The location of " << target << " using linear search is " << search(arr, target, size) << "\n";
    std::cout << "The location of " << target << " using binary search is " << binary_search(arr, target, size) << "\n";
    return 0;
}


// Recursively add the nodes
int find_sum(Node* root){
    if (root == nullptr){
        return 0;
    }
    else{
        return root->data + find_sum(root->left) + find_sum(root->right);
    }
}

int search(int arr[], int target, int size)
{
    for (int i = 0; i < size; i++){
        if (arr[i] == target){
            return i;
        }
    }

    return -1;
    
}

int binary_search(int arr[], int target, int size)
{
    int left = 0;
    int right = size - 1;

    while (left <= right){
        int mid = (left + right)/2;
        if (arr[mid] == target){
            return mid;
        }
        else if (target < arr[mid]){
            right = mid -1;
        }
        else
            left = mid + 1;
        }
    
    return -1;
}
