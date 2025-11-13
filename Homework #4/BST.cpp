#include "BST.h"
#include <iostream>
using namespace std;


BST::BST(){
    root = nullptr;
}

// Big 3
// Copy Constructor
Node* BST::BST_copy(Node* root){
    if (root == nullptr)
    {
        return nullptr;
    }
    else{
        Node* new_node = new Node;
        new_node->landing_time = root->landing_time;
        new_node->left_ptr = BST_copy(root->left_ptr);
        new_node->right_ptr = BST_copy(root->right_ptr);
        return new_node;
    }
}
BST::BST(const BST& other){
    cout << "Performing copy constructor.\n";
    root = BST_copy(other.root);
}

BST& BST::operator=(const BST& rhs){
    if (this == &rhs)
    {
        return *this;
    }
    destroy(root);
    root = nullptr;
    root = BST_copy(rhs.root);
    return *this;
}

BST::~BST(){
    destroy(root);
}

void BST::insert(int landing_time){
    root = insert_node(root, landing_time);
}

Node* BST::insert_node(Node* root, int landing_time){
    if (root == nullptr)
    {
        Node* node = new Node;
        check_memory_allocation(node, landing_time);

        node->landing_time = landing_time;
        node->left_ptr = nullptr;
        node->right_ptr = nullptr;
        return node;

    }
    // if duplicate landing time
    // find next available time
    else if(landing_time == root->landing_time){

        int availableTime = next_available(root, landing_time);
        root = insert_node(root, availableTime);
    }
    else if (landing_time < root->landing_time)
    {
        root->left_ptr = insert_node(root->left_ptr,landing_time);
    }
    else{
        root->right_ptr = insert_node(root->right_ptr,landing_time);
    } 
    return root;
}

void BST::traverse_in_order(Node* root) {
    if (root)
    {
        traverse_in_order(root->left_ptr);
        cout << "|\t" << root->landing_time << "         |\n";
        cout << "----------------------\n";
        traverse_in_order(root->right_ptr);
    }
}

void BST::display_landing_times() {
    traverse_in_order(root);
}

bool BST::search(int landing_time){
    root = search_node(root, landing_time); 
    return root;
}

Node* BST::search_node(Node* root, int landing_time){

    if (root == nullptr)
    {
        return root;
    }
    else if(root->landing_time == landing_time){
        return root;
    }
    else if(landing_time < root->landing_time){
        root = search_node(root->left_ptr, landing_time);
        return root;
    }
    else{
        root = search_node(root->right_ptr, landing_time);
        return root;
    }
    

}
void BST::remove(int landing_time){
    root = delete_node(root, landing_time);
}


Node* BST::delete_node(Node* root, int value_to_delete){
    
    // cannot delete empty node or not found
    if (root == nullptr)
    {
        cout << "Cannot remove " << value_to_delete << ". Not found.\n";
        return root;
    }

    if(value_to_delete < root->landing_time)
    {
        root->left_ptr = delete_node(root->left_ptr, value_to_delete);
    }
    else if(value_to_delete > root->landing_time)
    {
        root->right_ptr = delete_node(root->right_ptr, value_to_delete);
    }
    else{
        cout << "Removing landing time " << value_to_delete << ".\n";
        if(root->left_ptr == nullptr)
        {
            Node* temp_node = root->right_ptr;
            delete root;
            return temp_node;
        }

        if (root->right_ptr == nullptr)
        {
            Node* temp_node = root->left_ptr;
            delete root;
            return temp_node;
        }
        Node* in_order_successor = get_in_order_successor(root);
        root->landing_time = in_order_successor->landing_time;
        root->right_ptr = delete_node(root->right_ptr, in_order_successor->landing_time);
    }
    return root;
}

void BST::destroy(Node* root){
    if (root)
    {
        destroy(root->left_ptr);
        destroy(root->right_ptr);
        delete root;
    }
}

int BST::next_available(Node* root, int requested_time) {
    int five_minute_interval = 5;
    // If the path is null or a smaller time is found, 
    // the current time is available
    if (root == nullptr || requested_time < root->landing_time)
    {
        return requested_time; 
    }
    // If a duplicate is found, try the next time slot 
    else if (requested_time == root->landing_time)
    {
        cout << requested_time << " is a duplicate time slot. Going to increment by 5 to find next available time slot.\n";
        return next_available(root->right_ptr, requested_time + five_minute_interval);
    }
    // Move to the right child as the new landing_time is greater 
    else 
    {
        return next_available(root->right_ptr, requested_time);
    }
}

//==========================================
//        HELPER MEMBER FUNCTIONS          =
//==========================================
bool BST::is_time_conflicting(Node* root, int check_time) {
    if (root == nullptr) {
        return false;
    }

    // if conflict found
    if (root->landing_time == check_time) {
        return true; 
    }

    if (check_time < root->landing_time) {
        return is_time_conflicting(root->left_ptr, check_time);
    } else {
        return is_time_conflicting(root->right_ptr, check_time);
    }
}

void BST::check_memory_allocation(Node* node, int landing_time) {
    if (node == nullptr)
    {
        cout << "Memory allocation not successful.\n";
        EXIT_FAILURE;
    }
    else{
        cout << "Memory allocation successful for " << landing_time << "\n";
        EXIT_SUCCESS;
    }

}

void BST::print_schedule(){
    cout << "---------------------\n";
    cout << "|   Landing Times   |\n";
    cout << "---------------------\n";
    display_landing_times();
}

// Smallest value in the right subtree
Node* BST::get_in_order_successor(Node* root){
    root = root->right_ptr;
    while (root != nullptr && root->left_ptr != nullptr)
    {
        root = root->left_ptr;
    }
    return root;
}
