
#ifndef BST_h
#define BST_h

struct Node{
    int landing_time = 0;

    Node* left_ptr = nullptr;
    Node* right_ptr = nullptr;
    
};

class BST{
    private:
        Node* root;
        
        Node* insert_node(Node *, int);
        Node* search_node(Node*, int);
        Node* delete_node(Node*, int);
        void traverse_in_order(Node *);
        void destroy(Node*);

        // Big 3
        // Copy Constructor
        Node* BST_copy(Node*);
        
    


    public:
        BST();
    

        // Big 3
        // Copy Constructor
        BST(const BST& root);

        // Overloading Assignment Operator
        BST& operator=(const BST& root);

        // Destructor
        ~BST();


        void insert(int);
        void remove(int);
        bool search(int);
        void print_schedule();
        void display_landing_times();
        int next_available(Node*, int);

        // HELPER MEMBER FUNCTIONS
        bool is_time_conflicting(Node*, int);
        void check_memory_allocation(Node*, int);
        Node* get_in_order_successor(Node*);
        
        

};


#endif