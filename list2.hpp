#include "node.cpp"
#include "iostream"
#include "typeinfo"
#include <cassert>

template <typename T>
class List{

        private:
	//First element of the list	
        Node<T> *first;
	//Last element of the list
        Node<T> *last;
	//Size of the list
        int index;

        public:
	//Constructor, in which variables are assigned default values
        List(){
                first = last = nullptr;
                index = 0;
        }

/*	~List(){
                Node<T> *tmp_first;
                for(int i = 0; i < index; i++){
                        if(first != nullptr){
                                tmp_first = first->next;
                                delete first;
                                first = tmp_first;
                                index--;
                        }
                }
        }

      ~List(){
                while(first != nullptr)
                        pop_front();
        }
*/
  	//Returns the current value of the variable <index>
	int get_size(){
                return index;
        }

	//Checking whether the list is empty or not
        bool is_empty(){
                return (first == nullptr &&
                        index == 0);
        }

	//A new element is added at the beginning of the list,
	//checking the emptiness of the list. 
	void push_front(T data){
                Node<T> *node = new Node<T>(data);
                node->next = first;
                if(is_empty())
                        last = node;
                else
                        first->prev = node;
                first = node;
                index++;
                print();
        }

	//A new element is added at the beginning of the list,
	//checking the emptiness of the list.
        void push_back(T data){
                Node<T> *node = new Node<T>(data);
                node->prev = last;
                if(is_empty())
                        first = node;
                else
                        last->next = node;
                last = node;
                index++;
                print();
        }

	//Adds a new element to the list and specifies the position of this element in the
	//list, first memorizing the elements of this index and the next index of the current list.
	void insert(T f_data, int ind){
                Node<T> *node, *node2;
                node = first;
                for(int i = 1; i < ind - 1; i++){
                        node = node->next;
                        node2 = node->next;
                }
                Node<T> *new_node = new Node<T>(f_data);
                node->next = new_node;
                new_node->next = node2;
                index++;
        }

	//Returns the first element of the list if the list is not empty,
	//otherwise terminates the program.
	T front(){
  		assert(!is_empty() && "List is still empty!\n");
		return first->data;
  	}

	//Returns the last element of the list if the list is not empty,
	//otherwise terminates the program.
        T back(){
		assert(!is_empty() && "List is still empty!\n");
		return last->data;
        }

	//Deletes the first element of the list(at each next step 
        //assigning the value of the <first> element to a temporary variable).
	void pop_front(){
                Node<T> *node = first->next;
                delete first;
                first = node;
                node->prev = nullptr;
                --index;
                print();
        }

	//Deletes the first element of the list(at each next step 
	//assigning the value of the <last> element to a temporary variable).
        void pop_back(){
                Node<T> *node = last->prev;
                delete last;
                last = node;
                node->next = nullptr;
                --index;
                print();
        }

	//Makes is possible to refer to list elements using the indexing operator.
	//First, an array is created, and the values of the list elements are added to 
	//the list. And returns the value of the element corresponding to the 
	//specified parameter.	
	T operator[](int p_index){
                int *array = new int[p_index];//*****************************************
                Node<T> *tmp_node = first;
                int i = 0;
                while(tmp_node != nullptr){
                        array[i] = tmp_node->data;
                        tmp_node = tmp_node->next;
                        i++;
                }
                return array[p_index];
        }

	//A new list object is created and the elements of the current object are added
	//there in reverse order. And a new object is assigned to the current list object.
        void reverse(){
                List<T> object;
                Node<T> *node = first;
                while(node != nullptr){
                        object.push_front(node->data);
                        node = node->next;
                }
                *this = object;
        }
	
	//Takes an array as an argument and sorts it according to the algorithm <bubble 
	//sort>. This method is called in the original sorting method <bubble sort>.
	void bubble_sort_algorithm(T *arr){
                int n = 0;
                T tmp = 0;
                while(n < index - 1){
                        for(int j = 0; j < index - n - 1; j++){
                                if(arr[j] > arr[j+1]){
                                        tmp = arr[j];
                                        arr[j] = arr[j+1];
                                        arr[j+1] = tmp;
                                }
                        }
                        n++;
                }
        }

	//An array is created into which the values of the list elements are added, and
	//then this array is sorted by calling the <bubble_sort_algorithm> method. Then 
	//elements with nested values are added to the new List object, which are assigned
	//to the current object.
	void bubble_sort(){
                List<T> object;
                Node<T> *node = first;
                int i = 0;
                T array[index];
                while(node != nullptr){
                        array[i] = node->data;
                        node = node->next;
                        ++i;
                }
		bubble_sort_algorithm(array);
                int k = 0;
                while(k < index){
                        object.push_back(array[k]);
                        k++;
                }
                *this = object;
       	}

	//Takes an array as an argument and sorts it according to the algorithm <insertion
        //sort>. This method is called in the original sorting method <insertion sort>.
	void insertion_sort_algorithm(T *arr){
		T tmp = 0;
		int j = 0;
		for(int i = 1; i < index; i++){
			j = i - 1;
			while(j >= 0 && arr[j] > arr[j+1]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				j--;
			}
		}
	}

	//An array is created into which the values of the list elements are added, and
        //then this array is sorted by calling the <insertion_sort_algorithm> method. Then
        //elements with nested values are added to the new List object, which are assigned
        //to the current object.
	void insertion_sort(){
		List<T> object;
		Node<T> *node = first;
		T array[index];
		int i = 0;
		while(node != nullptr){
			array[i] = node->data;
			node = node->next;
			i++;
		}
		insertion_sort_algorithm(array);
		int k = 0;
		while(k < index){
			object.push_back(array[k]);
			k++;
		}
		*this = object;
	}

	//Displays the elements of the current object from the List.
	void print(){
                if(is_empty())
                        std::cout << "List is still empty\n";
                else{
                        Node<T> *tmp = first;
                        std::cout << "List elements are: ";
                        while(tmp){
                                std::cout << tmp->data << " ";
                                tmp = tmp->next;
                        }
                        std::cout << '\n';
                }
        }

};
