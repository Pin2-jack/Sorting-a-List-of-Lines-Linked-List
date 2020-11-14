// Program of little dog Part 2
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;
typedef string BT;

class Node                                          // creates class of nodes or cell.
{
    friend class SList;
    private:
        BT data;
        Node* next;
        Node(BT dt, Node* nxt= nullptr) : data(dt), next(nxt) {}
};

class SList
{
    private:                                        // initializes head pointers
        Node *head = nullptr;
        int cont = 0;                               // initialize the counter
        Node *scan = nullptr;
        Node *after= nullptr;
        char endl = '\n';

    public:
        SList()=default;
        int size()
        {
            return cont;
        }
        bool isempty()
        {
            return cont==0;
        }


        void start(BT value)                        // This will start the link list
        {
            head=new Node(value);
        }


        void loadLinkedListNotSorted()              // loads every line to a list (input file)
        {
            ifstream inputFile;
            inputFile.open("Meow.txt",ios::in);

            ofstream fileOutputConsole;
            fileOutputConsole.open("consoleOutput.txt",ios::out);
            string line="Head";
            string *ptrMyString=NULL;
            start(line);
            cout<<"----------------------------------------------------------------------\n";
            fileOutputConsole<<"----------------------------------------------------------------------\n";
            cout<< "********** Welcome to program 3 LITTLE DOG BY [ PRANAV PATEL] ********** "<<endl;
            cout<< "M.S in Computer Science, Will Graduate in 2021"<<endl;
            cout<< "It's far better to buy a wonderful company at a fair price than a fair company at a wonderful price. ― Warren Buffett"<<endl;
            cout<< "About me : I love Computers and Advance Technology."<<endl;
            fileOutputConsole<< "********** Welcome to program 3 LITTLE DOG BY [ PRANAV PATEL] ********** "<<endl;
            fileOutputConsole<< "M.S in Computer Science, Will Graduate in 2021"<<endl;
            fileOutputConsole<< "It's far better to buy a wonderful company at a fair price than a fair company at a wonderful price. By: Warren Buffett"<<endl;
            fileOutputConsole<< "About me : I love Computers and Advance Technology."<<endl;
            cout<<"----------------------------------------------------------------------\n";
            fileOutputConsole<<"----------------------------------------------------------------------\n";
            while(getline(inputFile, line))                     // load every line in list one by one
            {
                cout<<line<<endl;
                fileOutputConsole<<line<<endl;                  // also print to console output file
                insert(line);
            }
            fileOutputConsole<<"\n\nProgram ran well..............Terminated Successfully\n";
            inputFile.close();
            fileOutputConsole.close();
        }

        void insert(BT value)                       // insert new lines.
        {
            Node* newNode = new Node(value);
            scan=newNode;
            after=head;
            newNode->next=head->next;
            head->next=newNode;
            cont+=1;
        }

        void sortedInsert(struct Node** head_ref, struct Node* new_node)                        // function to sort a list
        {
            struct Node* current;
            if (*head_ref == NULL || (int)((*head_ref)->data).at(0) >= (int)(new_node->data).at(0))
            {
                new_node->next = *head_ref;
                *head_ref = new_node;
            }
            else
            {
                current = *head_ref;
                while (current->next!=NULL &&
                       (int)(current->next->data).at(0) < (int)(new_node->data).at(0))
                {
                    current = current->next;
                }
                new_node->next = current->next;
                current->next = new_node;
            }
        }

        void loadLinkedListSorted()
        {
            Node* head_ref = head;
            Node* sorted=NULL;
            Node* current=head_ref;
            while (current != NULL)
            {
                Node *next = current->next;
                sortedInsert(&sorted, current);
                current = next;

            }
            head_ref = sorted;
            ofstream fileOutputSorted;
            fileOutputSorted.open("finalOutputSorted.txt",ios::out);                            // Created an output file
            Node *temp = sorted;
            temp = temp->next;

            while(temp != NULL)
            {
                fileOutputSorted<<temp->data<<" ";
                temp = temp->next;
            }
            fileOutputSorted.close();
        }




        void print(ostream& out) const              // print the list in a file.
        {
            Node* current=head;
            current=current->next;
            while(current!=nullptr)
            {
                out<<current->data<<endl;
                current=current->next;
            }
        }
        void bye()
        {
            cout<<"\n\nProgram ran well..............Terminated Successfully\n";
        }
};

int main()
{
    ofstream filePrintLinkedList;
    filePrintLinkedList.open("printLinkedList.txt",ios::out);       // create output file.
    SList stringList;
    stringList.loadLinkedListNotSorted();
    stringList.print(filePrintLinkedList);
    stringList.loadLinkedListSorted();
    stringList.bye();
    filePrintLinkedList.close();
    return 0;
}
