//This header file contains the class definitions of all the Defence Personell Involved
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

class date   //for storing dates
{
    private:
        unsigned day, month, year;
    public:
        void getter_dob()
        {
            cout<<"Enter the day/month/year separated by space: ";
            cin>>day>>month>>year;
        }
        void display_dob()
        {
            cout<<day<<" - "<<month<<" - "<<year<<endl;
        }
};

class sepoy
{
    private:
        string sepoy_id;   //only for sepoys and hence not inheritable
    protected: 
        string post;
        string name;
        date date_of_birth;    //containership  //age can be calculated by this
        date date_of_joining;   //containership
        string password;        //for storing password

    private:                   //not inheritable information
        string sepoy_section_id;
        string sepoy_company_id;
        string sepoy_platoon_id;

    public:
        void getter_sepoy();    //takes the information input for sepoy
        void change_password();    //allows to change the password
        void view_dashboard() const;    //to view all the information of him in his dashboard
        void login();         //for logging in sepoy using his credentials
};

class lieutinant : public sepoy, public section
{
    private:
        string lieutinent_id;   //every lieutinent has they unique id
        string company_id;     //the company his section is part of
        string section_id;     //the id of the section he is leading
        string platoon_id;     //the platoon his section is part of    (may or maynot be required)
    public:
        void getter_lieutinant();
        void change_password_lieutinant();     //we may/maynot need this one
        void view_dashboard() const;         // to view his info
        void login();                     //may or maynot be required here
        void view_weapons_list() const;
};

class Major : public lieutinant      //head of a company 
{
    private:
        string major_id;
        string company_id;
        string platoon_id;
    public:
        void getter_major();
        void change_password_major();
        void view_dashboard () const;
        void login();
        void view_weapons_list() const;
};

class lieutinant_general : public Major   //head of 
{
    private:
        string lieutinant_general_id;
        string platoon_id;
    public:
        void getter_lie_gen();
        void change_passwd_lie_gen();
        void view_dashboard() const;
        void login();
        void view_weapons_list() const;
};

// he can access all the class using multiple inheritance
class general : public lieutinant_general      //head of army    //can view all the arsenal which army has    //can edit the details of any employee
{
    private:
    public:
        //function that he can do 
            //edit or modify details of any soldier
            //add and remove any soldier
            //view all the arsenal data which army has
            //can view/modify and delete all the info related to war and conflicts
            //add functions accordingly
};


//This header file contains the class -> section -> company -> platoon

class section : public weapon    
{
    protected:
        vector <sepoy> sep;    //contains the list of sepoys
        string section_id;
        string lieutinant_id;
        string weapon_id;    //it may be removed
    public:
        unsigned num_sepoys();    //counts and returns the number of sepoys in a section
        void add_sepoy_to_section(sepoy &);  //adds a sepoys into the section whenever a sepoy is added
        void remove_sepoy_from_section(sepoy &);
        void print_section_info() const;    //displays the information such as weapons and sepoys and lieutinant
        void print_weapon_info();       //prints the weapon information

};

class company : public weapon    //which sections are in which company/platoon is hardcoded.
{
    private:
        vector <section> sec;    //has the list of sections -> section id , lietinant_id, lietunant name
        string company_id;
        string major_id;
        string weapon_id;    //it may be removed 
    public:
        unsigned num_section();
        void print_company_info() const;
        void print_weapon_info();
};
class platoon : public weapon
{
    private:
        vector <company> com;
        //instead of platoon id to be string i was thinking of it as unsigned
        string platoon_id;
        string lieutinant_gen_id;
        string weapon_id;
    public:
        unsigned num_companies();
        void print_platoon_info() const;
        void print_weapon_info();

};

class airman
{
    private:
        string airman_id;   //only for airman and hence not inheritable
    protected: 
        string post;
        string name;
        date date_of_birth;    //containership  //age can be calculated by this
        date date_of_joining;   //containership
        string password;        //for storing password

    private:                   //not inheritable information
        string airman_section_id;
        string airman_company_id;
        string airman_platoon_id;

    public:
        void getter_sepoy();    //takes the information input for airman
        void change_password();    //allows to change the password
        void view_dashboard() const;    //to view all the information of him in his dashboard
        void login();         //for airman in sepoy using his credentials
};

class flight_lieutinant : public airman, public section
{
    private:
        string flight_lieutinent_id;   //every flight lieutinent has they unique id
        string squadron_id;     //the squadron his section is part of
        string section_id;     //the id of the section he is leading
        string command_id;     //the command his section is part of    (may or maynot be required)
    public:
        void getter_flight_lieutinant();
        void change_password_lieutinant();     //we may/maynot need this one
        void view_dashboard() const;         // to view his info
        void login();                     //may or maynot be required here
        void view_weapons_list() const;
};

class Squadron_Leader : public flight_lieutinant      //head of a squadron 
{
    private:
        string squadron_leader_id;
        string squadron_id;
        string command_id;
    public:
        void getter_squadron_leader();
        void change_password_squadron_leader();
        void view_dashboard () const;
        void login();
        void view_weapons_list() const;
};

class Marshall : public Squadron_Leader   //head of command 
{
    private:
        string marshall_id;
        string command_id;
    public:
        void getter_marshall();
        void change_passwd_marshall();
        void view_dashboard() const;
        void login();
        void view_weapons_list() const;
};

// he can access all the class using multiple inheritance
class Chief_Marshall : public Marshall    //head of airforce    //can view all the arsenal which airforce has    //can edit the details of any employee
{
    private:
    public:
        //function that he can do 
            //edit or modify details of any soldier
            //add and remove any soldier
            //view all the arsenal data which army has
            //can view/modify and delete all the info related to war and conflicts
            //add functions accordingly
};


//This header file contains the class -> section -> company -> platoon
class weapon{
	protected:
		string weapon_id;
		string weapon_name;
		int weapon_qty;
};


class section : public weapon    
{
    protected:
        vector <airman> air;    //contains the list of sepoys
        string section_id;
        string flight_lieutinant_id;
        string weapon_id;    //it may be removed
    public:
        unsigned num_sepoys();    //counts and returns the number of sepoys in a section
        void add_airman_to_section(airman &);  //adds a sepoys into the section whenever a sepoy is added
        void remove_airman_from_section(airman &);
        void print_section_info() const;    //displays the information such as weapons and sepoys and lieutinant
        void print_weapon_info();       //prints the weapon information

};

class squadron : public weapon    //which sections are in which company/platoon is hardcoded.
{
    private:
        vector <section> sec;    //has the list of sections -> section id , lietinant_id, lietunant name
        string squadron_id;
        string squadron_leader_id;
        string weapon_id;    //it may be removed 
    public:
        unsigned num_section();
        void print_squadron_info() const;
        void print_weapon_info();
};
class command : public weapon
{
    private:
        vector <squadron> com;
        //instead of platoon id to be string i was thinking of it as unsigned
        string command_id;
        string marshall_id;
        string weapon_id;
    public:
        unsigned num_squadron();
        void print_command_info() const;
        void print_weapon_info();

};



//weapons