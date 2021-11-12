//This header file contains the class definitions of all the Defence Personell Involved

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
        void const view_dashboard();    //to view all the information of him in his dashboard

};
