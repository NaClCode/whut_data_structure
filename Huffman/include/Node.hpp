# ifndef __NODE__
# define __NODE__
class Node{
    public:
        Node(int data, int weight);
        Node();
        int data;
        int parent, left, right;
        int weight;
        void setNode(int data, int weight);
        void setNode(int weight, int left, int right);
        void print();
};
# endif