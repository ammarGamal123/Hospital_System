#include <iostream>


using namespace std;
#define endl '\n'

const int MAX_QUEUE = 5;
const int MAX_SPECS = 20;

string specs[MAX_SPECS][MAX_QUEUE];
int current;


void Hospital_System ();


bool is_spec_empty(int spec){
    for (int i = 0; i < MAX_QUEUE; i++){
        if (specs[spec][i].empty()) {
            return true;
        }
    }
    return false;
}


void push_front(int spec , const string &name) {
    for (int i = 4; i > 0; i--) {
        specs[spec][i] = specs[spec][i - 1];
    }
    specs[spec][0] = name;

    current++;
}
void push_back(int spec ,const string &name){
    specs[spec][current]=name;
    current++;
}
void Add_new_patient(){
    int spec;
    string name;
    bool status;
    cout << "Enter Specialization , name , status : ";
    cin >> spec >> name >> status;
    if (!is_spec_empty(spec)){
        cout << "Sorry the specialization is filled with people , please try to come in another time" << endl;
    }
    else {
        if (status) {
            push_front(spec , name);
        }
        else {
            push_back(spec , name);
        }
    }
    Hospital_System();
}

void Print_all_patient() {
    for (int i = 0; i < MAX_SPECS; i++) {
        bool found = false;
        for (int j = 0; j < MAX_QUEUE; j++){
            if (!specs[i][j].empty()){
                found = 1;
            }
        }
        if (found){
            cout << "specialization " << i + 1 << ":";
            for (int j = 0; j < MAX_QUEUE; j++){
                cout << specs[i][j] << " ";
            }
            cout << endl;
        }
    }
    Hospital_System();
}
bool empty (int spec){
    for (int i = 0;i < MAX_QUEUE; i++){
        if (!specs[spec][i].empty())
            return true;
    }
    return false;
}

void Pickup_Patient (int spec) {
    for (int i = 0; i < MAX_QUEUE - 1; ++i) {
        specs[spec][i] = specs[spec][i + 1];
    }
    specs[spec][MAX_QUEUE - 1] = "";
    if (current)
        current--;
}

void Get_next_patient(){
    int spec;
    cin >> spec;
    if (!empty(spec)){
        cout << "Sorry Dr, There is No Patient come next time please!" << endl;
    }
    cout << "Dear" << specs[spec][0] << " Please Go to the Doctor." << endl;

    Pickup_Patient (spec);

    Hospital_System();
}

void Hospital_System (){
    cout << "\n\n\t\t\tWelcome To My Hospital System Project" << endl;
    cout << "\t\t\t*************************************\n\n" << endl;
    cout << "Please Enter your choice from the menu:" << endl
         << "1)  Add new patient" << endl
         << "2)  Print all patient" << endl // Done
         << "3)  Get next patient" << endl
         << "4)  Exit" << endl;

    int choice;
    cin >> choice;



    if (choice >= 1 && choice <= 4) {
        if (choice == 1) Add_new_patient();
        else if (choice == 2) Print_all_patient();
        else if (choice == 3) Get_next_patient();
        else return;
    }
    else {
        cout << "Invalid choice , please try again " << endl;
        Hospital_System();
    }
}

int main() {
    Hospital_System();
    return 0;
}
