template <typename T>
class Node{

        public:
        T data;
        Node<T> *prev;
        Node<T> *next;

        Node(T element){
                data = element;
                prev = next = nullptr;
        }

        Node(T element, Node<T> *p, Node<T> *p2){
                data = element;
                prev = p;
                next = p2;
        }

        Node(){}

};

