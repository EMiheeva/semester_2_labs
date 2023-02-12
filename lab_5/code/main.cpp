#include <iostream>
#include <fstream>
#include <sstream>
struct Elem
{
    int data;       
    Elem* left;     
    Elem* right;
    Elem* parent;
};
////////////////////////////////////////////////////
Elem* MAKE(int data, Elem* p)
{
    Elem* q = new Elem;           
    q->data = data; 
    q->left = nullptr;
    q->right = nullptr;
    q->parent = p;
    return q;
}
/////////////////////////////////////////////////
void ADD(int data, Elem*& root)
{
    if (root == nullptr) {
        root = MAKE(data, nullptr);
        return;
    }
    Elem* v = root;
    while ((data < v->data && v->left != nullptr) || (data > v->data && v->right != nullptr))
        if (data < v->data)
            v = v->left;
        else
            v = v->right;
    if (data == v->data)
        return;
    Elem* u = MAKE(data, v);
    if (data < v->data)
        v->left = u;
    else
        v->right = u;
}
//////////////////////////////////////////////
void PASS(Elem* v)
{
    if (v == nullptr)
        return;
    
    PASS(v->left);
    
    std::cout << v->data << std::endl;
    
    PASS(v->right);

}
/////////////////////////////////////////////
Elem* SEARCH(int data, Elem* v)     
{
    if (v == nullptr)
        return v;
    if (v->data == data)
        return v;
    if (data < v->data)
        return SEARCH(data, v->left);
    else
        return SEARCH(data, v->right);
}
/////////////////////////////////////////////
int DEEP(Elem* v, int digit)
{	
	int deep = 1;
	Elem* p = SEARCH(digit, v);
	
	if ( p != nullptr)
	{
		if(v->data == digit)
			return deep;
			
			while (v->data != digit)
			{	
				if (v->data < digit)
					v = v->right;
				
				else
					v = v->left;
				deep++;
			}
			return deep;
		}
		else
			return deep = 0;
}
//////////////////////////////////
void DELETE(int data, Elem*& root)
{
    
    Elem* u = SEARCH(data, root);
    if (u == nullptr)
        return;

    if (u->left == nullptr && u->right == nullptr && u == root)
    {
        delete root;
        root = nullptr;
        return;
    }

    if (u->left == nullptr && u->right != nullptr && u == root) 
    {
        Elem* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }
   
    if (u->left != nullptr && u->right == nullptr && u == root) 
    {
        Elem* t = u->left;
        while (t->right != nullptr)
            t = t->right;
        u->data = t->data;
        u = t;
    }

    if (u->left != nullptr && u->right != nullptr)
    {
        Elem* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }
    Elem* t;
    if (u->left == nullptr)
        t = u->right;
    else
        t = u->left;
    if (u->parent->left == u)
        u->parent->left = t;
    else
        u->parent->right = t;
    if (t != nullptr)
        t->parent = u->parent;
    delete u;
}
///////////////////////////////////////
void CLEAR(Elem*& v)
{
    if (v == nullptr)
        return;
    CLEAR(v->left);
    CLEAR(v->right);
    delete v;
    v = nullptr;
}
///////////////////////////////////////
int main()
{	
    Elem* root = nullptr;
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	
	if (!in.is_open())
	{
		std::cout << "File not found" << std::endl;
		return -1;
	}
	char symbol;
	int digit;
	while (!in.eof())
	{
		in >> symbol;
		if (symbol == '+')
		{	
			in >> digit;
			ADD(digit, root);
		}
		
		if (symbol == '-')
		{
			in >> digit;
			DELETE(digit, root);
		}
		
		if (symbol == 'E')
			break;
		
		if (symbol == '?') 
		{
			in >> digit;
			if ((DEEP(root, digit))==0)
			{
				out << "n";
				std::cout << "n";
			}
			else
			{
				out << (DEEP(root, digit));
				std::cout << (DEEP(root, digit));
			}
		}
	}
	return 0;
}			
