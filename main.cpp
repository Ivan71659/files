#include <iostream>

using namespace std;

class node {
  public: 
    string name;
    string last_name;
    node* next;
    node* prev;

    node(string name, string last_name) {
      this->name = name;
      this->last_name = last_name;
      this->next = nullptr;
      this->prev = nullptr;
    }
};

class list {
  public: 
    node* head;
    node* tail;

    list () {
      head = nullptr;
      tail = nullptr;
    }

    void print () {
      cout << "\n";
      node* current = head;
      while (current != nullptr){
        cout << current->name << " " << current->last_name << "\n";
        current = current->next;
      }
      cout << "\n";
    }

    void add_back (string name,string last_name) {
      node* new_node = new node (name, last_name);

      if(tail == nullptr) { 
         head = new_node;
         tail = new_node;
      }

      else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
      } 
    }

    node* get_node (int position) {
      node* current = head;

      for(int i = 1; i < position; i++){
        current = current->next;
      }

      return current;
    }

    void shuffle (int length) {
      for(int j = 0; j < 204; j++){
        int random1 = 1 + rand() % length;
        int random2 = 1 + rand() % length;

        node* card1 = get_node (random1);
        node* card2 = get_node (random2);

        string name1 = card1->name;
        string last_name1 = card1->last_name;
        string value2 = card2->name;
        string last_value2 = card2->last_name;
        
        card1->name = value2;
        card1->last_name = last_value2;
        card2->name = name1;
        card2->last_name = last_name1;
      }
    }

    void length_first_name () {
      while (true) {
        bool swap = false;
        node* current = head;
        
        while(current->next != nullptr){
          string current_first = current->name;
          string next_first = current->next->name;
          string current_last = current->last_name;
          string next_last = current->next->last_name;
          
          if(current_first.length () > next_first.length ()){
            current->name = next_first;
            current->next->name = current_first;
            current->last_name = next_last;
            current->next->last_name = current_last;
            swap = true;
          }

          current = current->next;
        }

        if(swap == false){
          break;
        }
      }
    }
    
    void length_last_name () {
      while (true) {
        bool swap = false;
        node* current = head;

        while(current->next != nullptr){
          string current_first = current->name;
          string next_first = current->next->name;
          string current_last = current->last_name;
          string next_last = current->next->last_name;

          if(current_last.length () > next_last.length ()){
            current->name = next_first;
            current->next->name = current_first;
            current->last_name = next_last;
            current->next->last_name = current_last;
            swap = true;
          }

          current = current->next;
        }

        if(swap == false){
          break;
        }
      }
    }

    void alphabetical_first_name () {
      while (true) {
        bool swap = false;
        node* current = head;

        while(current->next != nullptr){
          string current_first = current->name;
          string next_first = current->next->name;
          string current_last = current->last_name;
          string next_last = current->next->last_name;

          if(current_first > next_first){
            current->name = next_first;
            current->next->name = current_first;
            current->last_name = next_last;
            current->next->last_name = current_last;
            swap = true;
          }

          current = current->next;
        }

        if(swap == false){
          break;
        }
      }
    }

    void alphabetical_last_name () {
      while (true) {
        bool swap = false;
        node* current = head;

        while(current->next != nullptr){
          string current_first = current->name;
          string next_first = current->next->name;
          string current_last = current->last_name;
          string next_last = current->next->last_name;

          if(current_first > next_last){
            current->name = next_first;
            current->next->name = current_first;
            current->last_name = next_last;
            current->next->last_name = current_last;
            swap = true;
          }

          current = current->next;
        }

        if(swap == false){
          break;
        }
      }
    }
};

int main () {
  list l;

  l.add_back("James", "Brown");
  l.add_back("Laurent", "Qinn");
  l.add_back("Alfie", "Tang");
  l.add_back("John", "Doe");
  l.add_back("John", "Pork");
  l.add_back("Robin", "Dabank");

  while (true) {
    int question1;
    cout << "\n1) Sort alphabetically (last name)👨‍👨‍👦‍👦 \n2) Sort by alphabetical (first name)🩰 \n3) Sort by length (last name)🌡️ \n4) Sort by length🪢\n5) Random order🧑‍🎓\n6) Exit🚷\n";
    cin >> question1;
    
    if(question1 == 1){
      l.alphabetical_last_name();
      l.print();
    }
    if(question1 == 2){
      l.alphabetical_first_name();
      l.print();
    }
    if(question1 == 3){
      l.length_last_name();
      l.print();
    }
    if(question1 == 4){
      l.length_first_name();
      l.print();
    }
    if(question1 == 5){
      l.shuffle(6);
      l.print();
    }
    if(question1 == 6){
      break;
    }
  }

}
