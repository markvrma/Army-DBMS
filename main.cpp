
//company a contains sec1 and sec 2
//company b contains sec 3 and sec 4

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;
using std::vector;

//functions used in the program
void add_user(void);

void main_menu();
void add_war_details(void);
void army_field(void);
void sepoy_login(void);
void lieu_login(void);
void major_login();
void general_login(void);
void add_personel(string post_name);
void modify_personel(string post_name);
void delete_personel(string post_name);

void army_personal_dashboard(void);

//functions for airforce
void add_airforce_user();
void airforce_field();
void air_personal_dashboard(void);
void flight_lieu_login();
void squad_leader_login();
void air_chief_marshal_login();
void aircraftman_login();

//common functions
void war_details(void);
void display_war_history();

//sepoy.bin  ||   major.bin
//This header file contains the class definitions of all the Defence Personell Involved
//weapons

//class definitions
class date //for storing dates
{
private:
    unsigned day, month, year;

public:
    void getter_date()
    {
        cout << "Enter the day/month/year separated by space: ";
        cin >> day >> month >> year;
    }
    void display_date()
    {
        cout << day << "-" << month << "-" << year;
    }
};
class cds //Chief of Defence Staff    //only one object should be made
{
    //he can view everything
    void display_personel(); //he can view army /airforce as he chooses
    void display_weapons();  //he can view army/ airforce weapons as he chooses
};

class sepoy
{
private:
    string sepoy_id; //only for sepoys and hence not inheritable
protected:
    string name;
    date date_of_birth;   //containership  //age can be calculated by this
    date date_of_joining; //containership
    string password;      //for storing password

private: //not inheritable information
    string sepoy_section_id;
    // string sepoy_company_id;
    // string sepoy_platoon_id;

public:
    void getter()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Date of Birth:  ";
        date_of_birth.getter_date();
        cout << "Date of Joining: ";
        date_of_joining.getter_date();
    flag1:
        cout << "Set your password:\n";
        cout << "Enter new password: ";
        string pass1, pass2;
        cin >> pass1;
        cout << "Confirm new password: ";
        cin >> pass2;
        if (pass1 == pass2)
        {
            set_password(pass2);
        }
        else
        {
            cout << "\nPassword Not Matched\n";
            goto flag1;
        }
    }

    void getter_sepoy()
    {
        cout << "Enter Sepoy Id: ";
        cin >> sepoy_id;
        getter();
        cout << "Enter Section Id: ";
        cin >> sepoy_section_id;
    }
    void set_password(string pass)
    {
        this->password = pass;
    }
    string get_password()
    {
        return password;
    }
    string ret_sep_id()
    {
        return sepoy_id;
    }
    string ret_sep_name()
    {
        return name;
    }

    void modify() ////////////why it is here?
    {
        cout << "Enter modified Name: ";
        cin >> name;
        cout << "Modified Date of Birth:  ";
        date_of_birth.getter_date();
        cout << "Modified Date of Joining: ";
        date_of_joining.getter_date();
    }
    void modify_sepoy()
    {
        modify();
        cout << "Enter modified section Id: ";
        cin >> sepoy_section_id;
    }
    void display()
    {
        cout << " Name : " << name;
        cout << " Date Of Birth : ";
        date_of_birth.display_date();
        cout << " Date Of Joining : ";
        date_of_joining.display_date();
        cout << " Password : " << password;
    }
    void display_sepoy()
    {
        cout << " Sepoy ID : " << sepoy_id;
        display();
        cout << " Section ID : " << sepoy_section_id;
    }
};

class lieutenant : public sepoy
{
private:
    string lieutenant_id; //every lieutenent has they unique id
    //string company_id;    //the company his section is part of
    string section_id; //the id of the section he is leading
    //string platoon_id;    //the platoon his section is part of    (may or maynot be required)
public:
    void getter_lieutenant()
    {
        cout << "Enter Lieutenent ID: ";
        cin >> lieutenant_id;
        sepoy::getter();
        cout << "Enter Section ID: ";
        cin >> section_id;
    }
    void display_lieutenant()
    {
        cout << "Lieutenant Id: " << lieutenant_id;
        sepoy::display();
        cout << "Section Id: " << section_id;
    }
    string ret_lieu_id()
    {
        return lieutenant_id;
    }

    void modify_lieutenant()
    {
        sepoy::modify();
        cout << "Enter modified section Id: ";
        cin >> this->section_id;
    }
};

class Major : public lieutenant //head of a company
{
private:
    string major_id;
    string company_id;
    // string platoon_id;

public:
    void getter_major()
    {
        cout << "Enter Major Id: ";
        cin >> major_id;
        sepoy::getter();
        cout << "Enter company id: ";
        cin >> company_id;
    }
    void display_major()
    {
        cout << "Major ID: " << major_id;
        sepoy::display();
        cout << " Company Id: " << company_id;
    };

    string ret_maj_id()
    {
        return major_id;
    }
    void modify_major()
    {
        sepoy::modify();
        cout << "Enter modified company Id: ";
        cin >> this->company_id;
    }
};
void add_sepoy_to_section_(sepoy &s) 
{
    ofstream file;
    file.open("section.bin", ios::binary | ios::app);
    if (!file.is_open())
    {
        cout << "File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get(); //////////handle here correctly
        return;
    }
    section_army obj;
    obj.getter_section_army(s);
    int n;
    for (int i = 0; i < n; i++)
    {
        ifstream fl;
        fl.open("sepoy.bin", ios::binary | ios::in);
        if (!fl.is_open())
        {
            cout << "File could not be opened !! Press any Key to exit";
            cin.ignore();
            cin.get(); //////////handle here correctly
            return;
        }
        obj.getter_section_army(s);
        file.write((char *)&obj, sizeof(section_army));
    }
    file.close();
    cin.ignore();
    cin.get();
}
class section_army
{
protected:
    vector<sepoy> sep; //contains the list of sepoys
    string section_id;
    string lieutenant_id;
    unsigned num_gun;
    unsigned num_tank;
    unsigned num_mortar;
    unsigned num_combat_shotgun;

public:
    //unsigned num_sepoys();    //counts and returns the number of sepoys in a section
    //void add_sepoy_to_section(sepoy &);  //adds a sepoys into the section whenever a sepoy is added
    //void remove_sepoy_from_section(sepoy &);

    void getter_section_army(sepoy &s)
    {
        sep.push_back(s);
        cout << "Enter section Id: ";
        cin >> section_id;
        cout << "Enter lieutenant Id: ";
        cin >> lieutenant_id;
        cout << "Enter numbers of guns: ";
        cin >> num_tank;
        cout << "Enter number of tanks: ";
        cin >> num_tank;
        cout << "Enter number of mortars: ";
        cin >> num_mortar;
        cout << "Enter number of combat shotguns: ";
        cin >> num_combat_shotgun;
    }

    void print_section_info() //displays the information such as weapons and sepoys and lieutinant
    {
        cout << "Section Id: " << section_id << endl;
        cout << "The sepoy Id of sepoys in this section are:-\n ";
        for (int i = 0; i < sep.size() - 1; i++)
        {
            cout << sep.at(i).ret_sep_id() << "   -->  " << sep.at(i).ret_sep_name() << endl;
        }
        cout << " \nLieutenant Id: " << lieutenant_id << endl;
    }
    void print_section_weapon_info() //prints the weapon information
    {
        cout << "Section Id: " << section_id << endl;
        cout << "The weapons alloted to this section is:-\n";
        cout << "No. of Guns: " << num_gun << endl;
        cout << "No. of Tanks: " << num_tank << endl;
        cout << "No. of Mortars: " << num_mortar << endl;
        cout << "No. of Combat Shotguns: " << num_combat_shotgun << endl;
    }
}sec1,sec2,sec3,sec4;

// // class company
// // {
// // private:
// //     //vector<section_army> sec; //has the list of sections -> section id , lietinant_id, lietunant name
// //     string company_id;
// //     string major_id;

// // public:
// //     //unsigned num_section();
// //     //void getter_company(); //this is a temporary function just to enter initial values
// //     //void print_company_info()
// //     //{
// //         // cout << "Company Id: " << company_id << endl;
// //         // cout << "The sections in this company are:-\n";
// //         // for (int i = 0; i < sec.size() - 1; i++)
// //         // {
// //         //     sec.at(i).print_section_info();
// //         //     cout << endl
// //         //          << endl;
// //         // }
// //         // cout << " \nMajor Id: " << major_id << endl;
// //     //}
// // };

//will changes in the sepoy reflect in the platoon binary file implicitly or do we have to handle it explicitly
// class platoon
// {
// private:
//     vector<company> com;
//     //instead of platoon id to be string i was thinking of it as unsigned
//     string platoon_id;
//     string lieutinant_gen_id;

// public:
//     //unsigned num_companies();
//     void getter_platoon();
//     //temporary input function required
//     void print_platoon_info() const;
// };

// he can access all the class using multiple inheritance
class general : public Major, public section_army //, public company //public platoon //can edit the details of any employee // can modify the war and weapons data
{
private:
    string general_username;

public:
    friend class cds;
    //function that he can do
    //edit or modify details of any soldier
    //add and remove any soldier
    //view all the arsenal data which army has
    //can view/modify and delete all the info related to war and conflicts
    //add functions accordingly
    void getter_general() //temporary for first entry
    {
        cout << "Enter General Username:  ";
        cin >> general_username;
        sepoy::getter();
    }
    void display_general()
    {
        cout << "\nUsername: " << general_username;
        sepoy::display();
    }
    string ret_gene_username() //returns the username of general which is equivalent of sepoy_id for a sepoy
    {
        return general_username;
    }
    string ret_gen_name() ///
    {
        return name;
    }
};

//This header file contains the class -> section -> company -> platoon

//Airforce Personel
//This header file contains the class definitions of all the Air Force Personell Involved

class aircraftman
{
private:
    string aircraftman_id; //only for airman and hence not inheritable
protected:
    string name;
    date date_of_birth;   //containership  //age can be calculated by this
    date date_of_joining; //containership
    string password;      //for storing password

private: //not inheritable information
    string airman_section_id;
    //string airman_squadron_id;
    //string airman_command_id;

public:
    void getter()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Date of Birth:  ";
        date_of_birth.getter_date();
        cout << "Date of Joining: ";
        date_of_joining.getter_date();
    flag1:
        cout << "Set your password:\n";
        cout << "Enter new password: ";
        string pass1, pass2;
        cin >> pass1;
        cout << "Confirm new password: ";
        cin >> pass2;
        if (pass1 == pass2)
        {
            set_password(pass2);
        }
        else
        {
            cout << "\nPassword Not Matched\n";
            goto flag1;
        }
    }
    void getter_aircraftsman() //takes the information input for airman
    {
        cout << "Enter Aircraftman Id: ";
        cin >> aircraftman_id;
        getter();
        cout << "Enter Airman Section Id: ";
        cin >> airman_section_id;
    }

    void display()
    {
        cout << " Name : " << name;
        cout << " Date Of Birth : ";
        date_of_birth.display_date();
        cout << " Date Of Joining : ";
        date_of_joining.display_date();
        cout << " Password : " << password;
    }
    void display_aircraftman()
    {
        cout << "Aircraftman Id: " << aircraftman_id;
        display();
        cout << "Section Id: " << airman_section_id;
    }
    void set_password(string pass)
    {
        this->password = pass;
    }
    string get_password()
    {
        return password;
    }
    string ret_air_id()
    {
        return aircraftman_id;
    }
    string ret_air_name()
    {
        return name;
    }
    void modify()
    {
        cout << "Enter modified Name: ";
        cin >> name;
        cout << "Modified Date of Birth: ";
        date_of_birth.getter_date();
        cout << "Modified Date of Joining: ";
        date_of_joining.getter_date();
    }
    void modify_aircraftman()
    {
        modify();
        cout << "Enter modified section Id: ";
        cin >> this->airman_section_id;
    }
};

class flight_lieutenant : public aircraftman
{
private:
    string flight_lieu_id; //every flight lieutenent has they unique id
    // string squadron_id;    //the squadron his section is part of
    string section_id; //the id of the section he is leading
    // string command_id;     //the command his section is part of    (may or maynot be required)
public:
    void getter_flight_lieutenant()
    {
        cout << "Enter Flight Lieutenent ID: ";
        cin >> flight_lieu_id;
        aircraftman::getter();
        cout << "Enter Section ID: ";
        cin >> section_id;
    }
    void display_flight_lieutenant()
    {
        cout << "Flight Lieutenant Id: " << flight_lieu_id;
        aircraftman::display();
        cout << "Section Id: " << section_id;
    }
    string ret_fli_lieu_id()
    {
        return flight_lieu_id;
    }
    void modify_flight_lieutenant()
    {
        aircraftman::modify();
        cout << "Enter modified section Id: ";
        cin >> this->section_id;
    }
};

class squadron_leader : public flight_lieutenant //head of a squadron
{
private:
    string squadron_leader_id;
    string squadron_id;
    //string command_id;

public:
    void getter_squadron_leader()
    {
        cout << "Enter Squadron leader Id: ";
        cin >> squadron_leader_id;
        aircraftman::display();
        cout << "Enter squadron_id: ";
        cin >> squadron_id;
    }
    void display_sqa_leader()
    {
        cout << "Squadron Leader Id: " << squadron_leader_id;
        aircraftman::display();
        cout << "Squadron Id: " << squadron_id;
    }

    string ret_sqd_id()
    {
        return squadron_leader_id;
    }
    void modify_sqd_leader()
    {
        aircraftman::modify();
        cout << "Enter modified Squadron Id: ";
        cin >> this->squadron_id;
    }
};

class section_airforce
{
protected:
    vector<aircraftman> air; //contains the list of aircraftsman
    string aircraftman_id;
    string flight_lieu_id;
    unsigned num_missile;
    unsigned num_fightet_jet;
    unsigned num_mp5_machine_gun;
    unsigned num_attack_helicopter;

public:
    //unsigned num_aircraftman();    //counts and returns the number of aircraftman in a section
    //void add_aircraftman_to_section(sepoy &);  //adds a sepoys into the section whenever a sepoy is added
    //void remove_aircraftman_from_section(sepoy &);
    void print_section_info()
    {
        cout << "Aircraftman ID" << aircraftman_id << endl;
        cout << "The aircraftmen in the section are:-\n";
        for (int i = 0; i < air.size() - 1; i++)
        {
            cout << air.at(i).ret_air_id() << " ---> " << air.at(i).ret_air_name();
            cout << endl;
        }
        cout << " \nFlight Lieutenant Id: " << flight_lieu_id << endl;
    } //displays the information such as weapons and sepoys and lieutinant
      //prints the weapon information
    void print_section_weapon_info()
    {
        cout << "Aircraftman ID" << aircraftman_id << endl;
        cout << "The weapons alloted in the section are:-\n";
        cout << "No. of Missiles: " << num_missile << endl;
        cout << "No. of Fighter Jets: " << num_fightet_jet << endl;
        cout << "No. of Machine Guns: " << num_mp5_machine_gun << endl;
        cout << "No. of Attack Helicopter: " << num_attack_helicopter << endl;
    }
};

class squadron //which sections are in which company/platoon is hardcoded.
{
private:
    vector<section_airforce> sec; //has the list of sections -> section id , lietinant_id, lietunant name
    string squadron_id;
    string squadron_leader_id;
    // string weapon_id;    //it may be removed
public:
    // unsigned num_section();
    void print_squadron_info()
    {
        cout << "Squadron ID" << squadron_id << endl;
        cout << "The Sections in this Squadron are:-\n";
        for (int i = 0; i < sec.size() - 1; i++)
        {
            sec.at(i).print_section_info();
            cout << endl
                 << endl;
        }
        cout << "Squadron Leader ID: " << squadron_leader_id << endl;
    };
    void get_squadron_info();
    // void print_weapon_info();
};
// class command
// {
// private:
//     vector<squadron> com;
//     //instead of platoon id to be string i was thinking of it as unsigned
//     string command_id;
//     string marshall_id;
//     // string weapon_id;
// public:
//     // unsigned num_squadron();
//     void print_command_info() const;
//     void get_command_info();
//     // void print_weapon_info();
// };

class air_chief_marshall : public squadron_leader, public section_airforce, public squadron //public command //head of airforce    //can view all the arsenal which airforce has    //can edit the details of any employee
{
private:
    string air_chief_username;

public:
    friend class cds;
    void getter_air_chief_marshall();
    void display_air_chief_marshall() const;
    //function that he can do
    //edit or modify details of any soldier
    //add and remove any soldier
    //view all the arsenal data which army has
    //can view/modify and delete all the info related to war and conflicts
    //add functions accordingly
    void getter_air_chief()
    {
        cout << "Enter Air Chief Marshal Username:  ";
        cin >> air_chief_username;
        aircraftman::getter();
    }
    void display_air_chief()
    {
        cout << "\nUsername: " << air_chief_username;
        aircraftman::display();
    }
    string ret_air_username()
    {
        return air_chief_username;
    }
    string ret_air_chief_name()
    {
        return name;
    }
};

///////////////war and conflict

class war
{
private:
    date war_start_date;
    date war_end_date;
    string location;
    string opposition; //name of opposing country
    unsigned num_our_casualties;
    unsigned num_thiers_casualties;
    unsigned expenditure;
    string result; //one sentence description
public:
    void getter_war()
    {
        cout << "War Beginning Date: ";
        war_start_date.getter_date();
        cout << "War End Date: ";
        war_end_date.getter_date();
        cout << "Enter the location where the war took place: ";
        cin >> location;
        cout << "Enter the name of country against which war took place: ";
        cin >> opposition;
        cout << "Enter the number of casualties from from our side: ";
        cin >> num_our_casualties;
        cout << "Enter the number of casualties from from opposing side: ";
        cin >> num_our_casualties;
        cout << "Enter our expenditure(in INR): ";
        cin >> expenditure;
        cout << "Enter the result(win/loss): ";
        cin >> result;
    }
    void display_war()
    {
        war_start_date.display_date();
        cout << '\t';
        war_end_date.display_date();
        cout << '\t' << opposition << '\t' << location;
        cout << '\t' << num_our_casualties << '\t' << num_thiers_casualties << '\t' << expenditure << '\t' << result << endl;
    }
};

//main function declaration

void main_menu()
{
    int choice;
    while (true)
    {
        cout << "\n\n\n\t\t\tDEFENCE FORCE DATABASE MANAGEMENT SYSTEM\n\n";
    flag2:
        cout << "OPTIONS\n\n";
        cout << "\n1. Army login";
        cout << "\n2. Air-Force login";
        cout << "\n3. Chief of Defence Staff(CDS) login";
        cout << "\n4. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            army_field();
            break;
        case 2:
            airforce_field();
            break;
        case 3:
            // cds_field();
            break;
        case 4:
            //some goodbye message
            cout << "Goodbye!";
            return;
            break;
        default:
            cout << "Error: Invalid Choice Selection\n\n";
            goto flag2;
        }
    }
}
int main()
{
    main_menu();
}

//for printing section-wise weapon info

//Army login

void army_field()
{
    cout << "\n\t\tMenu\n\n";
    cout << "1. Login to Personal Dashboard\n";
    cout << "2. Section-wise weapon allocation\n";
    cout << "3. War Details\n";
    cout << "4. Exit\n";
    cout << "9. Return to Previous Menu\n";
flag5:
    cout << "\n\nEnter your choice: ";
    char choice;
    cin >> choice;
    switch (choice)
    {
    case '1':
        cout << "\n\nPersonel Dashboard Login\n";
        cout << "--------------------------------\n\n";
        army_personal_dashboard();
        break;
    case '2':
        // print_weapon_info_section_wise();
        break;
    case '3':
        war_details(); //general login dashboard then view history and add war
        break;
    case '4':
        cout << "\nGoodbye!\n";
        exit(0);
        break;
    default:
        cout << "Error: Invalid Choice Selection" << endl;
        goto flag5;
    }
}

void army_personal_dashboard(void)
{

    int ch;
    while (true)
    {
        cout << "\n\t\tMENU\n";
        cout << "\n0. Add user\n";
        cout << "\n1. Sepoy login";
        cout << "\n2. Lieutenant login";
        cout << "\n3. Major login";
        cout << "\n4. General login";
        cout << "\n5. Exit";
        cout << "\n9. Return to Previous menu";
    flag3:
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 0:
            add_user();
            break;
        case 1:
            sepoy_login();
            break;
        case 2:
            lieu_login();
            break;
        case 3:
            major_login();
            break;
        case 4:
            general_login();
        case 5:
            cout << "Goodbye";
            exit(0);
        case 9:
            cout << "Going back to previous menu..." << endl;
            army_field();
            break;
        default:
            cout << "Error: Invalid Choice Selection\n\n";
            goto flag3;
        }
    }
}
void add_user(void)
{
    int choice;
    cout << "\n\t\tSELECT POST: ";
    cout << "\n1. General-Soldier:"; //sepoy
    cout << "\n2. Lieutenant";
    cout << "\n3. Major";
    cout << "\nEnter your Choice: ";
    cin >> choice;
    int n;
    cout << "\nEnter the number of details: ";
    cin >> n;
    if (choice == 1)
    {
        sepoy obj;
        ofstream oFile;
        oFile.open("sepoy.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_sepoy();
            oFile.write((char *)&obj, sizeof(sepoy));
        }
        oFile.close();
        cout << "\n\nsepoy record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 2)
    {
        lieutenant obj;
        ofstream oFile;
        oFile.open("lieu.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_lieutenant();
            oFile.write((char *)&obj, sizeof(lieutenant));
        }
        oFile.close();
        cout << "\n\nlieutinant record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 3)
    {
        Major obj;
        ofstream oFile;
        oFile.open("major.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_major();
            oFile.write((char *)&obj, sizeof(Major));
        }
        oFile.close();
        cout << "\n\nmajor record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 4)
    {
        general obj;
        ofstream oFile;
        oFile.open("general.bin", ios::binary | ios::app);
        obj.getter_general();
        oFile.write((char *)&obj, sizeof(general));
        oFile.close();
        cout << "\n\nmajor record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else
        cout << "\nEnter correct choice" << endl;
}
void sepoy_login(void)
{
    string sepoy_id;
    string password;
    cout << "\nEnter sepoy Id: ";
    cin >> sepoy_id;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file; //read mode
    file.open("sepoy.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get(); //////////handle here correctly
        return;
    }
    file.seekg(0, ios::beg);
    sepoy obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(sepoy)))
    {
        if (obj.ret_sep_id() == sepoy_id && obj.get_password() == password)
        {
            //obj.display_sepoy();
            found = true;
            cout << "OPTIONS\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_sepoy();
                cout << "Enter any key to continue...";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    // change_pass_sepoy(obj.ret_sep_id(), pass1, "Sepoy");
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)&(obj), sizeof(sepoy));
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
            // break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    army_field();
    // if (found)
    // {
    //     string new_password;
    //     cout << "\nWant to change password: ";
    //     char ch;
    //     cin>>ch;
    //     cin >> new_password;
    //     change_pass(sepoy_id, new_password);
    // }
    // else
    // cout << "\nRecords not found!!";
    cin.ignore();
    cin.get();
}
// void change_pass_sepoy(string id, string password)
// {
//     bool found = false;
//     sepoy obj;
//     fstream fl;
//     fl.open("sepoy.bin", ios::binary | ios::in | ios::out);
//     if (!fl.is_open())
//     {
//         cout << "File could not be opened. Press any Key to exit...";
//         cin.ignore();
//         cin.get();
//         return; /////////////////handle here correctly
//     }
//     fl.seekg(0, ios::beg);
//     while (!fl.eof() && found == false)
//     {
//         fl.read((char *)(&obj), sizeof(sepoy));
//         if (obj.ret_sep_id() == id)
//         {
//             obj.set_password(password);
//             int pos = (-1) * static_cast<int>(sizeof(obj));
//             fl.seekp(pos, ios::cur);
//             fl.write((char *)(&obj), sizeof(sepoy));
//             cout << "\n\n\t Record Updated";
//             found = true;
//         }
//     }
//     fl.close();
//     if (found == false)
//         cout << "\n\n Record Not Found ";
//     cin.ignore();
//     cin.get();
// }

//lieutenant login
void lieu_login(void)
{
    string lieu_id;
    string password;
    cout << "\nEnter Lieutenant Id: ";
    cin >> lieu_id;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file; //opening in read mode
    file.open("lieu.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get(); /////handle here correctly
        return;
    }
    file.seekg(0, ios::beg); //setting the file pointer at the beginning of file
    lieutenant obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(lieutenant)))
    {
        if (obj.ret_lieu_id() == lieu_id && obj.get_password() == password)
        {
            //obj.display_sepoy();
            found = true;
            cout << "OPTIONS\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_lieutenant();
                cout << "Enter any key to continue...";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)(&obj), sizeof(lieutenant));
                    //change_pass_sepoy(obj.ret_sep_id(), pass1);
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
            // break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    army_field();
    // if (found)
    // {
    //     string new_password;
    //     cout << "\nWant to change password: ";
    //     char ch;
    //     cin>>ch;
    //     cin >> new_password;
    //     change_pass(sepoy_id, new_password);
    // }
    // else
    // cout << "\nRecords not found!!";
    cin.ignore();
    cin.get();
}
void major_login()
{
    string major_id;
    string password;
    cout << "\nEnter Major ID: ";
    cin >> major_id;
    cout << "\nEnter the password ";
    cin >> password;
    fstream file; //opening in read mode
    file.open("major.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get(); /////handle here correctly
        return;
    }
    file.seekg(0, ios::beg); //setting the file pointer at the beginning of file
    Major obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(Major)))
    {
        if (obj.ret_maj_id() == major_id && obj.get_password() == password)
        {
            //obj.display_sepoy();
            found = true;
            cout << "OPTIONS\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_major();
                cout << "Enter any key to continue...";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)(&obj), sizeof(Major));
                    cout << "\n\n\tRecord Updated\n";
                    //change_pass_sepoy(obj.ret_sep_id(), pass1);
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
            // break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    army_field();
    // if (found)
    // {
    //     string new_password;
    //     cout << "\nWant to change password: ";
    //     char ch;
    //     cin>>ch;
    //     cin >> new_password;
    //     change_pass(sepoy_id, new_password);
    // }
    // else
    // cout << "\nRecords not found!!";
    cin.ignore();
    cin.get();
}

// void change_passwd_general(string usrnme, string password)
// {
//     bool found = false;
//     general obj;
//     fstream fl;
//     fl.open("general.bin", ios::binary | ios::in | ios::out);
//     if (!fl.is_open())
//     {
//         cout << "General Information could not be fetched\n";
//         cout << "Error: File could not be opened.\n";
//         cout << "Press any Key to exit..."; //////
//         cin.ignore();
//         cin.get();
//         return;
//     }
//     fl.seekg(0, ios::beg);
//     while (!fl.eof() && found == false)
//     {
//         fl.read((char *)(&obj), sizeof(general));
//         if (obj.ret_gene_username() == usrnme)
//         {
//             obj.set_password(password);
//             int pos = (-1) * static_cast<int>(sizeof(obj));
//             fl.seekp(pos, ios::cur);
//             fl.write((char *)(&obj), sizeof(general));
//             cout << "\n\n\t Record Updated";
//             found = true;
//         }
//     }
//     fl.close();
//     if (found == false)
//         cout << "\n\n Record Not Found ";
//     cin.ignore();
//     cin.get();
// }
void general_login(void)
{
    cout << "\n\n\tWelcome to General login\n";
    cout << "   ----------------------------------\n\n";
    string general_usrnme;
    string password;
    cout << "\nEnter the username: ";
    cin >> general_usrnme;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file;
    file.open("general.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get();
        return;
    }
    file.seekg(0, ios::beg);
    general obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(general)))
    {
        if (obj.ret_gene_username() == general_usrnme && obj.get_password() == password)
        {
            //obj.general::display_general();
            found = true;
            break;
        }
    }
    if (found)
    {
        char choice;
        cout << "\nSelect an Operation Listed Below:";
        cout << "\na. View your Profile";
        cout << "\nb. Update your Password\n";
        cout << "\n1. Add a Personel";
        cout << "\n2. Modify detail(s) of a Personel: ";
        cout << "\n3. Remove a Personel: ";
        cout << "\n\nEnter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 'a':
            obj.display_general();
            cout << "\n\nEnter any key to continue...";
            cin.get();
            break;
        case 'b':
        {
            cout << "\nEnter your current password: ";
            string pass1;
            cin >> pass1;
            if (pass1 == obj.get_password()) //password is same variable for both sepoy and general
            {
                cout << "Enter the new password: ";
                cin >> pass1;
                obj.set_password(pass1);
                int pos = (-1) * static_cast<int>(sizeof(obj));
                file.seekp(pos, ios::cur);
                file.write((char *)&(obj), sizeof(general));
                // change_passwd_general(obj.ret_gene_username(), pass1);
                cout << "\nPassword Changed Successfully!" << endl;
            }
        }
        break;
        case '1':
        {
            string post_name;
            cout << "\nWhom to add(Sepoy/Lieutenant/Major)";
            cin >> post_name;
            add_personel(post_name);
            break;
        }
        case '2':
        {
            string post_name;
            cout << "\nWhom to add(Sepoy/Lieutenant/Major)";
            cin >> post_name;
            modify_personel(post_name);
            break;
        }
        case '3':
        {
            string post_name;
            cout << "\nWhom to add(Sepoy/Lieutenant/Major)";
            cin >> post_name;
            delete_personel(post_name);
            break;
        }
        default:
            cout << "\nEnter correct choice...";
            break;
        }
    }
    else
        cout << "\nRecord not found!!";
    file.close();
    cin.ignore();
    cin.get();
}
void add_personel(string post_name)
{
    ofstream oFile;
    if (post_name == "Sepoy")
    {
        sepoy obj;
        oFile.open("sepoy.bin", ios::binary | ios::app);
        obj.getter_sepoy();
        oFile.write((char *)&obj, sizeof(sepoy));
    }
    else if (post_name == "Lieutenant")
    {
        lieutenant obj;
        oFile.open("lieu.bin", ios::binary | ios::app);
        obj.getter_lieutenant();
        oFile.write((char *)&obj, sizeof(lieutenant));
    }
    else if (post_name == "Major")
    {
        Major obj;
        oFile.open("major.bin", ios::binary | ios::app);
        obj.getter_major();
        oFile.write((char *)&obj, sizeof(Major));
    }
    else
    {
        cout << "\nEnter correct Post-Name";
    }
    oFile.close();
    cout << "\n\nsepoy record Has Been Created ";
    cin.ignore();
    cin.get();
}
void add_airforce_personel(string post_name)
{
    ofstream oFile;
    if (post_name == "Aircraftman")
    {
        aircraftman obj;
        oFile.open("aircraftman.bin", ios::binary | ios::app);
        obj.getter_aircraftsman();
        oFile.write((char *)&obj, sizeof(aircraftman));
    }
    else if (post_name == "Flight Lieutenant")
    {
        flight_lieutenant obj;
        oFile.open("flight_lieu.bin", ios::binary | ios::app);
        obj.getter_flight_lieutenant();
        oFile.write((char *)&obj, sizeof(flight_lieutenant));
    }
    else if (post_name == "Squadron Leader")
    {
        squadron_leader obj;
        oFile.open("squadron_leader.bin", ios::binary | ios::app);
        obj.getter_squadron_leader();
        oFile.write((char *)&obj, sizeof(Major));
    }
    else
    {
        cout << "\nEnter correct Post-Name";
    }
    oFile.close();
    cout << "\n\nRecord Has Been Created ";
    cin.ignore();
    cin.get();
}
void modify_personel(string post_name)
{
    fstream fl;
    string id;
    cout << "\nEnter the Id:";
    cin >> id;
    bool found = false;
    if (post_name == "Sepoy")
    {
        fl.open("sepoy.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "File could not be opened !! Press any Key to exit";
            cin.ignore();
            cin.get();
            return;
        }
        sepoy obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(sepoy));
            if (obj.ret_sep_id() == id)
            {
                obj.modify_sepoy(); //There is some updation required like officer does not have access to change password of user.
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(sepoy));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
    }
    else if (post_name == "Lieutenant")
    {
        fl.open("lieu.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "File could not be opened !! Press any Key to exit";
            cin.ignore();
            cin.get();
            return;
        }
        lieutenant obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(lieutenant));
            if (obj.ret_lieu_id() == id)
            {
                obj.modify_lieutenant(); //There is some updation required like officer does not have access to change password of user.
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(lieutenant));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
    }
    else if (post_name == "Major")
    {
        fl.open("major.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "File could not be opened !! Press any Key to exit";
            cin.ignore();
            cin.get();
            return;
        }
        Major obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(Major));
            if (obj.ret_maj_id() == id)
            {
                obj.modify_major(); //There is some updation required like officer does not have access to change password of user.
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(Major));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
    }
    else
    {
        cout << "\nInvalid Post-Name...";
        return;
    }
    fl.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
    cin.ignore();
    cin.get();
}

void modify_airforce_personel(string post_name)
{
    fstream fl;
    string id;
    cout << "\nEnter the Id:";
    cin >> id;
    bool found = false;
    if (post_name == "Aircraftman")
    {
        fl.open("aircraftman.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "File could not be opened !! Press any Key to exit";
            cin.ignore();
            cin.get();
            return;
        }
        aircraftman obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(aircraftman));
            if (obj.ret_air_id() == id)
            {
                obj.modify_aircraftman(); //There is some updation required like officer does not have access to change password of user.
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(aircraftman));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
    }
    else if (post_name == "Flight Lieutenant")
    {
        fl.open("flight_lieu.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "File could not be opened !! Press any Key to exit";
            cin.ignore();
            cin.get();
            return;
        }
        flight_lieutenant obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(lieutenant));
            if (obj.ret_fli_lieu_id() == id)
            {
                obj.modify_flight_lieutenant(); //There is some updation required like officer does not have access to change password of user.
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(flight_lieutenant));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
    }
    else if (post_name == "Squadron Leader")
    {
        fl.open("squadron_leader.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "File could not be opened !! Press any Key to exit";
            cin.ignore();
            cin.get();
            return;
        }
        squadron_leader obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(Major));
            if (obj.ret_sqd_id() == id)
            {
                obj.modify_sqd_leader();
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(Major));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
    }
    else
    {
        cout << "\nInvalid Post-Name...";
        return;
    }
    fl.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
    cin.ignore();
    cin.get();
}

void delete_personel(string post_name)
{
    string id;
    cout << "Enter the Id: ";
    cin >> id;
    ifstream iFile;
    ofstream oFile;
    oFile.open("temp.bin", ios::binary | ios::out);
    oFile.seekp(0, ios::beg);
    if (post_name == "Sepoy")
    {
        iFile.open("sepoy.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "File could not be opened... Press any Key to exit...";
            cin.ignore();
            cin.get();
            return;
        }
        iFile.seekg(0, ios::beg);
        sepoy obj;
        while (iFile.read((char *)(&obj), sizeof(sepoy)))
        {
            if (obj.ret_sep_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(sepoy));
            }
        }
        oFile.close();
        iFile.close();
        remove("sepoy.bin");
        rename("temp.bin", "sepoy.bin");
    }
    else if (post_name == "Lieutenant")
    {
        iFile.open("lieu.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "File could not be opened... Press any Key to exit...";
            cin.ignore();
            cin.get();
            return;
        }
        iFile.seekg(0, ios::beg);
        lieutenant obj;
        while (iFile.read((char *)(&obj), sizeof(lieutenant)))
        {
            if (obj.ret_lieu_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(lieutenant));
            }
        }
        oFile.close();
        iFile.close();
        remove("lieu.bin");
        rename("temp.bin", "lieu.bin");
    }
    else if (post_name == "Major")
    {
        iFile.open("major.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "File could not be opened... Press any Key to exit...";
            cin.ignore();
            cin.get();
            return;
        }
        iFile.seekg(0, ios::beg);
        Major obj;
        while (iFile.read((char *)(&obj), sizeof(Major)))
        {
            if (obj.ret_maj_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(Major));
            }
        }
        oFile.close();
        iFile.close();
        remove("major.bin");
        rename("temp.bin", "major.bin");
    }
    else
    {
        cout << "\nInvalid Post.....";
        return;
    }
    cout << "\n\n\tRecord Deleted ..";
    cin.ignore();
    cin.get();
}

// void delete_airforce_personel(string post_name)
// {
//     string id;
//     cout << "Enter the Id: ";
//     cin >> id;
//     ifstream iFile;
//     ofstream oFile;
//     oFile.open("temp.bin", ios::binary | ios::out);
//     oFile.seekp(0, ios::beg);
//     if (post_name == "Sepoy")
//     {
//         iFile.open("sepoy.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         sepoy obj;
//         while (iFile.read((char *)(&obj), sizeof(sepoy)))
//         {
//             if (obj.ret_sep_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(sepoy));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("sepoy.bin");
//         rename("temp.bin", "sepoy.bin");
//     }
//     else if (post_name == "Lieutenant")
//     {
//         iFile.open("lieu.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         lieutenant obj;
//         while (iFile.read((char *)(&obj), sizeof(lieutenant)))
//         {
//             if (obj.ret_lieu_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(lieutenant));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("lieu.bin");
//         rename("temp.bin", "lieu.bin");
//     }
//     else if (post_name == "Major")
//     {
//         iFile.open("major.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         Major obj;
//         while (iFile.read((char *)(&obj), sizeof(Major)))
//         {
//             if (obj.ret_maj_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(Major));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("major.bin");
//         rename("temp.bin", "major.bin");
//     }
//     else
//     {
//         cout << "\nInvalid Post.....";
//         return;
//     }
//     cout << "\n\n\tRecord Deleted ..";
//     cin.ignore();
//     cin.get();
// }
void add_war_details(void)
{
    ofstream file;
    file.open("war.bin", ios::binary | ios::app);
    if (!file.is_open())
    {
        cout << "File could not be opened... Press any Key to exit...";
        cin.ignore();
        cin.get();
        return;
    }
    int n;
    war obj;
    cout << "\nHow many Details you want to enter: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        obj.getter_war();
        file.write((char *)&obj, sizeof(war));
    }
    file.close();
    cin.ignore();
    cin.get();
}
void war_details(void)
{
    string username;
    string password;
    cout << "\nEnter Username: ";
    cin >> username;
    cout << "\nEnter Password: ";
    cin >> password;
    ifstream file;
    file.open("general.bin", ios::binary | ios::in);
    if (!file.is_open())
    {
        cout << "File could not be opened... Press any Key to exit...";
        cin.ignore();
        cin.get();
        return;
    }
    file.seekg(0, ios::beg);
    general obj;
    bool found = false;
    while (!file.eof() && found == false)
    {
        file.read((char *)&obj, sizeof(general));
        if (obj.ret_gene_username() == username && obj.ret_gene_username() == password)
        {
            found = true;
            obj.display_general();
            break;
        }
    }
    file.close();
    if (found)
    {
        int choice;
        cout << "\nChoose the Below Options: ";
        cout << "\n1. View War History";
        cout << "\n2. Add War Details";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            ifstream fl;
            fl.open("war.bin", ios::binary | ios::in);
            if (!fl.is_open())
            {
                cout << "File could not be opened... Press any Key to exit...";
                cin.ignore();
                cin.get();
                return;
            }
            war obj;
            fl.seekg(0, ios::beg);
            while (fl.read((char *)&obj, sizeof(war)))
            {
                obj.display_war();
            }
            fl.close();
            cin.ignore();
            cin.get();
        }
        break;
        case 2:
        {
            ofstream fl;
            fl.open("war.bin", ios::binary | ios::app);
            if (!fl.is_open())
            {
                cout << "File could not be opened... Press any Key to exit...";
                cin.ignore();
                cin.get();
                return;
            }
            war obj;
            int n;
            cout << "\nEnter the number of details: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                obj.getter_war();
                fl.write((char *)&obj, sizeof(war));
            }
            fl.close();
            cin.get();
            cin.ignore();
        }
        break;
        default:
            cout << "\nEnter correct choice:";
            break;
        }
    }
}

// void delete_personel(string post_name)
// {
//     string id;
//     cout << "Enter the Id: ";
//     cin >> id;
//     ifstream iFile;
//     ofstream oFile;
//     oFile.open("temp.bin", ios::binary | ios::out);
//     oFile.seekp(0, ios::beg);
//     if (post_name == "Sepoy")
//     {
//         iFile.open("sepoy.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         sepoy obj;
//         while (iFile.read((char *)(&obj), sizeof(sepoy)))
//         {
//             if (obj.ret_sep_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(sepoy));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("sepoy.bin");
//         rename("temp.bin", "sepoy.bin");
//     }
//     else if (post_name == "Lieutenant")
//     {
//         iFile.open("lieu.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         lieutenant obj;
//         while (iFile.read((char *)(&obj), sizeof(lieutenant)))
//         {
//             if (obj.ret_lieu_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(lieutenant));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("lieu.bin");
//         rename("temp.bin", "lieu.bin");
//     }
//     else if (post_name == "Major")
//     {
//         iFile.open("major.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         Major obj;
//         while (iFile.read((char *)(&obj), sizeof(Major)))
//         {
//             if (obj.ret_maj_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(Major));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("major.bin");
//         rename("temp.bin", "major.bin");
//     }
//     else
//     {
//         cout << "\nInvalid Post.....";
//         return;
//     }
//     cout << "\n\n\tRecord Deleted ..";
//     cin.ignore();
//     cin.get();
// }

void delete_airforce_personel(string post_name)
{
    string id;
    cout << "Enter the Id: ";
    cin >> id;
    ifstream iFile;
    ofstream oFile;
    oFile.open("temp.bin", ios::binary | ios::out);
    oFile.seekp(0, ios::beg);
    if (post_name == "Aircraftman")
    {
        iFile.open("aircraftman.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "File could not be opened... Press any Key to exit...";
            cin.ignore();
            cin.get();
            return;
        }
        iFile.seekg(0, ios::beg);
        sepoy obj;
        while (iFile.read((char *)(&obj), sizeof(aircraftman)))
        {
            if (obj.ret_sep_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(aircraftman));
            }
        }
        oFile.close();
        iFile.close();
        remove("aircraftman.bin");
        rename("temp.bin", "aircraftman.bin");
    }
    else if (post_name == "Flight Lieutenant")
    {
        iFile.open("flight_lieu.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "File could not be opened... Press any Key to exit...";
            cin.ignore();
            cin.get();
            return;
        }
        iFile.seekg(0, ios::beg);
        flight_lieutenant obj;
        while (iFile.read((char *)(&obj), sizeof(flight_lieutenant)))
        {
            if (obj.ret_fli_lieu_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(flight_lieutenant));
            }
        }
        oFile.close();
        iFile.close();
        remove("flight_lieu.bin");
        rename("temp.bin", "flight_lieu.bin");
    }
    else if (post_name == "squadron_leader")
    {
        iFile.open("squadron_leader.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "File could not be opened... Press any Key to exit...";
            cin.ignore();
            cin.get();
            return;
        }
        iFile.seekg(0, ios::beg);
        Major obj;
        while (iFile.read((char *)(&obj), sizeof(squadron_leader)))
        {
            if (obj.ret_maj_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(squadron_leader));
            }
        }
        oFile.close();
        iFile.close();
        remove("major.bin");
        rename("temp.bin", "major.bin");
    }
    else
    {
        cout << "\nInvalid Post.....";
        return;
    }
    cout << "\n\n\tRecord Deleted ..";
    cin.ignore();
    cin.get();
}
// {
//     ofstream fl;
//     fl.open("war.bin", ios::binary | ios::app);
//     if (!fl.is_open())
//     {
//         cout << "File could not be opened... Press any Key to exit...";
//         cin.ignore();
//         cin.get();
//         return;
//     }
//     war obj;
//     obj.getter_war();
//     fl.write((char *)&obj, sizeof(war));
//     fl.close();
//     cin.ignore();
//     cin.get();
// }
// break;
// default:
// cout << "\nEnter correct choice...";
// break;
// }
// }
// }

void airforce_field()
{
    cout << "\n\t\tMenu\n\n";
    cout << "1. Login to Personal Dashboard\n";
    cout << "2. Section-wise weapon allocation\n";
    cout << "3. War Details\n";
    cout << "4. Exit\n";
    cout << "9. Return to Previous Menu\n";
flag5:
    cout << "\n\nEnter your choice: ";
    char choice;
    cin >> choice;
    switch (choice)
    {
    case '1':
        cout << "\n\nArmy Personal Dashboard Login\n";
        cout << "--------------------------------\n\n";
        air_personal_dashboard();
        break;
    case '2':
        //
        break;
    case '3':
        war_details(); //general login dashboard then view history and add war
        break;
    case '4':
        cout << "\nGoodbye!\n";
        exit(0);
        break;
    default:
        cout << "Error: Invalid Choice Selection" << endl;
        goto flag5;
    }
}

void air_personal_dashboard(void)
{
    char ch;
    while (true)
    {
        cout << "\n\t\tMENU\n";
        cout << "\n1. Aircraftman login";
        cout << "\n2. Flight Lieutenant login";
        cout << "\n3. Squadron Leader login";
        cout << "\n4. Airforce Cheif Marshal login";
        cout << "\n5. Exit";
        cout << "\n9. Return to Previous menu";
    flag6:
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            aircraftman_login();
            break;
        case '2':
            flight_lieu_login();
            break;
        case '3':
            squad_leader_login();
            break;
        case '4':
            air_chief_marshal_login();
        case '5':
            cout << "Goodbye";
            exit(0);
        case '9':
            cout << "Going back to previous menu..." << endl;
            airforce_field();
            break;
        default:
            cout << "Error: Invalid Choice Selection\n\n";
            goto flag6;
        }
    }
}

void add_airforce_user(void)
{
    int choice;
    cout << "\n\t\tSELECT POST: ";
    cout << "\n1. Aircraftman:";
    cout << "\n2. Flight Lieutenant";
    cout << "\n3. Squadron Leader";
    cout << "\n4. Air Chief Marshall";
    cout << "\nEnter your Choice: ";
    cin >> choice;
    int n;
    cout << "\nEnter the number of details: ";
    cin >> n;
    if (choice == 1)
    {
        aircraftman obj;
        ofstream oFile;
        oFile.open("aircraftman.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_aircraftsman();
            oFile.write((char *)&obj, sizeof(aircraftman));
        }
        oFile.close();
        cout << "\n\nAircraftman record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 2)
    {
        flight_lieutenant obj;
        ofstream oFile;
        oFile.open("flight_lieu.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_flight_lieutenant();
            oFile.write((char *)&obj, sizeof(flight_lieutenant));
        }
        oFile.close();
        cout << "\n\nflight lieutinant record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 3)
    {
        squadron_leader obj;
        ofstream oFile;
        oFile.open("squadron_leader.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_squadron_leader();
            oFile.write((char *)&obj, sizeof(squadron_leader));
        }
        oFile.close();
        cout << "\nSquadron Leader record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 4)
    {
        air_chief_marshall obj;
        ofstream oFile;
        oFile.open("airchief.bin", ios::binary | ios::app);
        obj.getter_air_chief();
        oFile.write((char *)&obj, sizeof(air_chief_marshall));
        oFile.close();
        cout << "\nAir Cheif Marshal record has Been Created\n ";
        cin.ignore();
        cin.get();
    }
    else
        cout << "\nEnter correct choice" << endl;
}

void aircraftman_login(void)
{
    string aircraftman_id;
    string password;
    cout << "\nEnter aircraftman Id: ";
    cin >> aircraftman_id;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file; //read mode
    file.open("aircraftman.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get(); //////////handle here correctly
        return;
    }
    file.seekg(0, ios::beg);
    aircraftman obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(aircraftman)))
    {
        if (obj.ret_air_id() == aircraftman_id && obj.get_password() == password)
        {
            //obj.display_sepoy();
            found = true;
            cout << "OPTIONS\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_aircraftman();
                cout << "Enter any key to continue...";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    // change_pass_sepoy(obj.ret_sep_id(), pass1, "Sepoy");
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)&(obj), sizeof(aircraftman));
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
            // break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    airforce_field();
    // if (found)
    // {
    //     string new_password;
    //     cout << "\nWant to change password: ";
    //     char ch;
    //     cin>>ch;
    //     cin >> new_password;
    //     change_pass(sepoy_id, new_password);
    // }
    // else
    // cout << "\nRecords not found!!";
    cin.ignore();
    cin.get();
}

void flight_lieu_login()
{
    string flight_lieu_id;
    string password;
    cout << "\nEnter Flight Lieutenant Id: ";
    cin >> flight_lieu_id;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file; //opening in read mode
    file.open("flight_lieu.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get(); /////handle here correctly
        return;
    }
    file.seekg(0, ios::beg); //setting the file pointer at the beginning of file
    flight_lieutenant obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(flight_lieutenant)))
    {
        if (obj.ret_fli_lieu_id() == flight_lieu_id && obj.get_password() == password)
        {
            //obj.display_sepoy();
            found = true;
            cout << "OPTIONS\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_flight_lieutenant();
                cout << "Enter any key to continue...";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)(&obj), sizeof(flight_lieutenant));
                    //change_pass_sepoy(obj.ret_sep_id(), pass1);
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
            // break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    army_field();
    // if (found)
    // {
    //     string new_password;
    //     cout << "\nWant to change password: ";
    //     char ch;
    //     cin>>ch;
    //     cin >> new_password;
    //     change_pass(sepoy_id, new_password);
    // }
    // else
    // cout << "\nRecords not found!!";
    cin.ignore();
    cin.get();
}

// void change_pass_sepoy(string id, string password)
// {
//     bool found = false;
//     sepoy obj;
//     fstream fl;
//     fl.open("sepoy.bin", ios::binary | ios::in | ios::out);
//     if (!fl.is_open())
//     {
//         cout << "File could not be opened. Press any Key to exit...";
//         cin.ignore();
//         cin.get();
//         return; /////////////////handle here correctly
//     }
//     fl.seekg(0, ios::beg);
//     while (!fl.eof() && found == false)
//     {
//         fl.read((char *)(&obj), sizeof(sepoy));
//         if (obj.ret_sep_id() == id)
//         {
//             obj.set_password(password);
//             int pos = (-1) * static_cast<int>(sizeof(obj));
//             fl.seekp(pos, ios::cur);
//             fl.write((char *)(&obj), sizeof(sepoy));
//             cout << "\n\n\t Record Updated";
//             found = true;
//         }
//     }
//     fl.close();
//     if (found == false)
//         cout << "\n\n Record Not Found ";
//     cin.ignore();
//     cin.get();
// }

void squad_leader_login()
{
    string squadron_leader_id;
    string password;
    cout << "\nEnter Squadron Leader ID: ";
    cin >> squadron_leader_id;
    cout << "\nEnter the password ";
    cin >> password;
    fstream file; //opening in read mode
    file.open("squadron_leader.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get(); /////handle here correctly
        return;
    }
    file.seekg(0, ios::beg); //setting the file pointer at the beginning of file
    squadron_leader obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(squadron_leader)))
    {
        if (obj.ret_sqd_id() == squadron_leader_id && obj.get_password() == password)
        {
            //obj.display_sepoy();
            found = true;
            cout << "OPTIONS\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_sqa_leader();
                cout << "Enter any key to continue...";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)(&obj), sizeof(squadron_leader));
                    cout << "\n\n\tRecord Updated\n";
                    //change_pass_sepoy(obj.ret_sep_id(), pass1);
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
            // break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    airforce_field();
    // if (found)
    // {
    //     string new_password;
    //     cout << "\nWant to change password: ";
    //     char ch;
    //     cin>>ch;
    //     cin >> new_password;
    //     change_pass(sepoy_id, new_password);
    // }
    // else
    // cout << "\nRecords not found!!";
    cin.ignore();
    cin.get();
}

void air_chief_marshal_login(void)
{
    cout << "\n\n\tWelcome to Air Chief Marshal login\n";
    cout << "   ----------------------------------\n\n";
    string air_cheif_usrnme;
    string password;
    cout << "\nEnter the username: ";
    cin >> air_cheif_usrnme;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file;
    file.open("airchief.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get();
        return;
    }
    file.seekg(0, ios::beg);
    air_chief_marshall obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(air_chief_marshall)))
    {
        if (obj.ret_air_username() == air_cheif_usrnme && obj.get_password() == password)
        {
            //obj.air_chief_marshall::display_air_chief_marshall(); ////////obj.display_general
            found = true;
            break;
        }
    }
    if (found)
    {
        char choice;
        cout << "\nSelect an Operation Listed Below:";
        cout << "\na. View your Profile";
        cout << "\nb. Update your Password\n";
        cout << "\n1. Add a Personel";
        cout << "\n2. Modify detail(s) of a Personel: ";
        cout << "\n3. Remove a Personel: ";
        cout << "\n\nEnter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 'a':
            obj.display_air_chief();
            cout << "\n\nEnter any key to continue...";
            cin.get();
            break;
        case 'b':
        {
            cout << "\nEnter your current password: ";
            string pass1;
            cin >> pass1;
            if (pass1 == obj.get_password()) //password is same variable for both sepoy and general
            {
                cout << "Enter the new password: ";
                cin >> pass1;
                obj.set_password(pass1);
                int pos = (-1) * static_cast<int>(sizeof(obj));
                file.seekp(pos, ios::cur);
                file.write((char *)&(obj), sizeof(air_chief_marshall));
                // change_passwd_general(obj.ret_gene_username(), pass1);
                cout << "\nPassword Changed Successfully!" << endl;
            }
        }
        break;
        case '1':
        {
            string post_name;
            cout << "\nWhom to add(Aircraftman/Flight Lieutenant/Squadron Leader)";
            cin >> post_name;
            add_airforce_personel(post_name);
            break;
        }
        case '2':
        {
            string post_name;
            cout << "\nWhom to modify(Aircraftman/Flight Lieutenant/Squadron Leader)";
            cin >> post_name;
            modify_airforce_personel(post_name);
            break;
        }
        case '3':
        {
            string post_name;
            cout << "\nWhom to remove(Aircraftman/Flight Lieutenant/Squadron Leader)";
            cin >> post_name;
            delete_airforce_personel(post_name);
            break;
        }
        default:
            cout << "\nEnter correct choice...";
            break;
        }
    }
    else
        cout << "\nRecord not found!!";
    file.close();
    cin.ignore();
    cin.get();
}

// void change_passwd_general(string usrnme, string password)
// {
//     bool found = false;
//     general obj;
//     fstream fl;
//     fl.open("general.bin", ios::binary | ios::in | ios::out);
//     if (!fl.is_open())
//     {
//         cout << "General Information could not be fetched\n";
//         cout << "Error: File could not be opened.\n";
//         cout << "Press any Key to exit..."; //////
//         cin.ignore();
//         cin.get();
//         return;
//     }
//     fl.seekg(0, ios::beg);
//     while (!fl.eof() && found == false)
//     {
//         fl.read((char *)(&obj), sizeof(general));
//         if (obj.ret_gene_username() == usrnme)
//         {
//             obj.set_password(password);
//             int pos = (-1) * static_cast<int>(sizeof(obj));
//             fl.seekp(pos, ios::cur);
//             fl.write((char *)(&obj), sizeof(general));
//             cout << "\n\n\t Record Updated";
//             found = true;
//         }
//     }
//     fl.close();
//     if (found == false)
//         cout << "\n\n Record Not Found ";
//     cin.ignore();
//     cin.get();
// }
