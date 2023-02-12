#include <iostream>

using namespace std;

struct Element
{
    int age;
    int number;
    string name;

    Element* next;
    Element* next_by_name;
    Element* next_by_age;
};
Element* head;

void ADD(string n_name, int n_age, int n_number) {
    if (head == nullptr) {
        head = new Element();
        head->number = n_number;
        head->name = n_name;
        head->age = n_age;
    }

    else {
        Element* p = head;
        Element* n = new Element();

        while (p->next != nullptr && p->next->number < n_number) {  //считаем до нужной позиции
            p = p->next;
        }
        n->next = p->next;
        p->next = n;

        p = head;

        while (p->next_by_age != nullptr && p->next_by_age->age < n_age) {  //считаем до нужной позиции
            p = p->next_by_age;
        }
        n->next_by_age = p->next_by_age;
        p->next_by_age = n;

        p = head;

        while (p->next_by_name != nullptr && p->next_by_name->name < n_name) {  //считаем до нужной позиции
            p = p->next_by_name;
        }
        n->next_by_name = p->next_by_name;
        p->next_by_name = n;

        n->age = n_age;
        n->name = n_name;
        n->number = n_number;
    }

}

void PRINT_AGE()
{
    Element* p = head->next_by_age;
    while (p != nullptr)
    {
        std::cout<< p->number << p->age <<" " << p->name << std::endl;
        p = p->next_by_age;
    }
}
void PRINT()
{
    Element* p = head->next;
    while (p != nullptr)
    {
        std::cout << p->number<<" " << p->age << " " << p->name << std::endl;

        p = p->next;
    }
}
void PRINT_NAME()
{
    Element* p = head->next_by_name;
    while (p != nullptr)
    {
        std::cout << p->number<<" " << p->age << " " << p->name << std::endl;

        p = p->next_by_name;
    }
    
}

Element* middle_age(Element* start, Element* last){
    Element* slow = start;
    Element* fast = start->next_by_age;
    while (fast != last) {
        fast = fast->next_by_age;
            if (fast != last) {
                slow = slow->next_by_age;
                fast = fast->next_by_age;
            }
    }
    return slow;
}



Element* BinSearch_age(int find) {
    Element* left = head;
    Element* p = head;
    while (p->next_by_age != nullptr)
    {
        p = p->next_by_age;
    }
    Element* right = p;
    Element* middl;


    while (left->next_by_age != right) {
        middl = middle_age(left, right);
        if (middl == left) {
            if (left->next_by_age->age == find)
                return left->next_by_age;
            else break;
        }
        if (middl->age >= find) right = middl;
        else left = middl;
    }
    if (right->age == find)
        return right;
    else return nullptr;
}

Element* middle(Element* start, Element* last) {
    Element* slow = start;
    Element* fast = start->next;
    while (fast != last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}



Element* BinSearch(int find) {
    Element* left = head;
    Element* p = head;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    Element* right = p;
    Element* middl;


    while (left->next != right) {
        middl = middle(left, right);
        if (middl == left) {
            if (left->next->number == find)
                return left->next;
            else break;
        }
        if (middl->number >= find) right = middl;
        else left = middl;
    }
    if (right->number == find)
        return right;
    else return nullptr;
}
Element* middle_name(Element* start, Element* last) {
    Element* slow = start;
    Element* fast = start->next;
    while (fast != last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}



Element* BinSearch_name(string find) {
    Element* left = head;
    Element* p = head;
    while (p->next_by_name != nullptr)
    {
        p = p->next_by_name;
    }
    Element* right = p;
    Element* middl;


    while (left->next_by_name != right) {
        middl = middle_name(left, right);
        if (middl == left) {
            if (left->next_by_name->name == find)
                return left->next_by_name;
            else break;
        }
        if (middl->name >= find) right = middl;
        else left = middl;
    }
    if (right->name == find)
        return right;
    else return nullptr;
}
void DeleteElements(int find) {
    Element* deleted;
    Element* p = head;
    Element* a = head;
    Element* n = head;

    while (p->next != NULL)
    {
        if (p->number == find) {
            deleted = p;
            p = p->next;
            head = p;
            delete deleted;
        }
        if (p->next->number == find)
        {
            while (a->next_by_age !=p->next)
                a = a->next_by_age;
            while (n->next_by_name != p->next)
                n = n->next_by_name;
            deleted = p->next;
            p->next = p->next->next;
            a->next_by_age = a->next_by_age->next_by_age;
            n->next_by_name = n->next_by_name->next_by_name;
            delete deleted;

            a = head;
            n = head;
        }
        else
            p = p->next;
    }

}

int main()
{
    
    head = new Element();
    head->next = nullptr;

    ADD("Ангелина", 18, 33);
    ADD("Елизавета", 19, 28);
    ADD("Сережа", 20, 22);
    ADD("Сережа", 16, 20);
    ADD("Сережа", 17, 22);
    ADD("Елизавета", 17, 28);

    PRINT();

    DeleteElements(22);
    cout << endl;

    PRINT_AGE();

    cout << endl;
    
    Element* f;
    f = BinSearch_age(18);
    if(f != nullptr)
    cout << f->number << " " << f->age << " " << f->name;

    cout << endl;

    f = BinSearch(22);
    if (f != nullptr)
        cout << f->number << " " << f->age << " " << f->name;

    cout << endl;

    f = BinSearch_name("Елизавета");
    if (f != nullptr)
        cout << f->number << " " << f->age << " " << f->name;
        
    
}
