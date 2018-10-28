#include <iostream>
#include <string>

using namespace std;

enum type {h,w,f,m,o};

int maximum_contacts = 10, current_contacts = 0;

typedef struct contact
{
    type contact_type;
    string name;
    string phone_number;
}contact;

contact contacts_array[10];

bool read_contacts()
{
    int i,j;
    contact temp;
    if(current_contacts == maximum_contacts)
        return false;
        
    contact new_contact;
    string contact_type;
    cout<<"please enter phone number: ";
    cin >> new_contact.phone_number;
    cout<<"please enter name: ";
    cin >> new_contact.name;
    cout<<"type of number (f for fax, h for home, m for mobile, w for work, o for others): ";
    cin >> contact_type;
    
    if(contact_type == "f")
        new_contact.contact_type = f;
    else if(contact_type == "h")
        new_contact.contact_type = h;
    else if(contact_type == "m")
        new_contact.contact_type = m;
    else if(contact_type == "w")
        new_contact.contact_type = w;
    else if(contact_type == "o")
        new_contact.contact_type = o;
        
    contacts_array[current_contacts++] = new_contact;
    for(i=0;i<current_contacts;i++)
    {
        for(j=0;j<current_contacts-i-1;j++)
        {
            if(contacts_array[j].name.compare(contacts_array[j+1].name) > 0)
            {
                temp.name=contacts_array[j].name;
                temp.phone_number=contacts_array[j].phone_number;
                temp.contact_type=contacts_array[j].contact_type;
                
                contacts_array[j].name=contacts_array[j+1].name;
                contacts_array[j].phone_number=contacts_array[j+1].phone_number;
                contacts_array[j].contact_type=contacts_array[j+1].contact_type;
                
                contacts_array[j+1].name=temp.name;
                contacts_array[j+1].phone_number=temp.phone_number;
                contacts_array[j+1].contact_type=temp.contact_type;
            }
        }
    }
    return true;
}

bool del_contacts()
{
    int i;
    size_t found;
    bool found_and_deleted = false;
    string name;
    cout<<"please enter name to delete: ";
    cin>>name;
    for(i=0;i<current_contacts;i++)
    {
        if(found == contacts_array[i].name.find(name))
        {
            for(i=i+1;i<current_contacts-1;i++) 
            {
                contacts_array[i] = contacts_array[i+1];
            }
            current_contacts--;
            found_and_deleted = true;
            break;
        }
    }
    return found_and_deleted;
}

void view()
{
    int i;
    for(i=0;i<current_contacts;i++)
    {
        cout<<contacts_array[i].name<<"\t"<<contacts_array[i].phone_number<<"\t";
        if(contacts_array[i].contact_type == f)
            cout<<"(fax)";
        else if(contacts_array[i].contact_type == h)
            cout<<"(home)";
        else if(contacts_array[i].contact_type == m)
            cout<<"(mobile)";
        else if(contacts_array[i].contact_type == w)
            cout<<"(work)";
        else if(contacts_array[i].contact_type == o)
            cout<<"(others)";
        cout<<"\n";
    }
}

int main()
{
    int choice;
    bool flag = true;
    while(flag)
    {
        cout<<"*** "<<current_contacts<<" contacts entry ***\n";
        cout<<"0 end\n";
        cout<<"1 new contact\n";
        cout<<"2 delete contact\n";
        cout<<"3 show all contacts\n";
        cout<<"9 empty contact memory\n";
        cin>>choice;
        switch(choice)
        {
            case 0:
                flag = false;
                break;
            case 1:
                if(read_contacts() == false)
                    cout<<"contact list full.\n";
                else
                    cout<<"contact stored.\n";
                break;
            case 2:
                if(del_contacts() == false)
                    cout<<"contact not found.\n";
                else
                    cout<<"contact deleted.\n";
                break;
            case 3:
                view();
                break;
            case 9:
                current_contacts = 0;
                cout<<"all contacts deleted.\n";
        }
    }
    return 0;
}
