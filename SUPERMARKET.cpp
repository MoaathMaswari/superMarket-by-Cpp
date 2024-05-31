#include<iostream>
using namespace std;
#include<fstream>

void err(int &num)
{

	while (!(cin>>num) ||cin.peek() != '\n')
{
 
    cout << "   ERROR!! A number must be entered.\n   Enter again : ";

    cin.clear();

   cin.ignore(100,'\n');
   
}
}

void err(float &num)
{
	while (!(cin>>num))
{
 
    cout << " ERROR!! A number must be entered."
            " \n Enter again : ";

    cin.clear();

   cin.ignore(100,'\n');
    
}

}


struct market
{
int p_code;
string p_name;
float p_price;
int quantity;

void display();
void menu();
void add();
void edit();
void delt();
void search();
}start;



void market:: menu()
{int err=0;
system("color 47");
	string choice;
	again:
		system("cls");
		if(err>0)
		cout<<" Invalid Input!\n Please enter number between 1 and 6";
		cout<<" \n\n\n\t\t********************************\n \t\t WELCOME TO QUALITY SUPERMARKET \n \t\t********************************\n";

        cout<<"\n Choose the task wanted\n";
		cout<<"____________________________\n";
		cout<<" (1) Display products\n";
		cout<<" (2) Add product(s)\n";
		cout<<" (3) Edit product(s)\n";
		cout<<" (4) Delete product(s)\n";
		cout<<" (5) Search for product\n";
		cout<<" (6) Exit\n";
		cout<<"____________________________\n";
		cout<<" Enter choice number : ";
		 cin>>choice;


		if(choice=="1")
		display();
		else if(choice=="2")
		add();
		else if(choice=="3")
				edit();
		else if(choice=="4")
			delt();
		else if(choice=="5")
			search();
		else if(choice=="6")
		cout<<" \n\n\n\t\t****** BYE BYE ******\n\n";
		else
		{
		err++;
		goto again;
		}

}



void market::display()
	{system("cls");
		int c;
		string n;
		float p;
		int q;
		int s=0;
		fstream super,tran;
		int ch;

	tran.open("superdata.txt",ios::in);
	if(tran){
		while(!tran.eof()){

		tran>>c>>n>>p>>q;
		if(!tran.eof())
            {
		s++;
            }
		}
	}
            tran.close();
	market sort[s];
	s=0;
m:
		cout<<"\n\n (1) Display pruducts as they are\n";
		cout<<" (2) Sort and display pruducts \n";
		cout<<" your choice : ";
		err(ch);
		if(ch==1)
        {
            system("cls");
            super.open("superdata.txt",ios::in);
            if(super)
            {

	cout<<"\n        These are the existing products\n_____________________________________________\n";
            cout<<"\n   "<<"code"<<"       "<<"name"<<"      "<<"price"<<"       "<<"quantity"<<endl;
            cout<<"______________________________________________\n";
        while(!super.eof())
	{
		super>>c>>n>>p>>q;
		if(!super.eof())
            {
                if(n.length()>=5)
cout<<"     "<<c<<"       "<<n<<"       "<<p<<"           "<<q<<endl;
		       else
 cout<<"     "<<c<<"        "<<n<<"        "<<p<<"           "<<q<<endl;
            }
	}
super.close();
        }
        else
        cout<<" ...There are no products!";

        }
		else if(ch==2)
        {
        	system("cls");

	super.open("superdata.txt",ios::in);
	if(!super)
	cout<<" There are no products to display....\n\n";
	else{
	cout<<"\n        These are the existing products\n_____________________________________________\n";
	cout<<"    code      name      price      quantity\n";

		cout<<"_____________________________________________\n";

	while(!super.eof())
	{
		super>>c>>n>>p>>q;
		if(!super.eof())
            {
		sort[s].p_code=c;
		sort[s].p_name=n;
		sort[s].p_price=p;
		sort[s].quantity=q;
		s++;
            }
	}
	}

super.close();
	int ct;
	string nt;
	float pt;
	int qt;
	for(int m=0;m<s;m++)
    {
     	for(int n=0;n<s-1;n++)
        {
            if(sort[n+1].p_code<sort[n].p_code)
            {
                ct=sort[n].p_code;
                nt=sort[n].p_name;
                pt=sort[n].p_price;
                qt=sort[n].quantity;

                sort[n].p_code=sort[n+1].p_code;
                sort[n].p_name=sort[n+1].p_name;
                sort[n].p_price=sort[n+1].p_price;
                sort[n].quantity=sort[n+1].quantity;

                sort[n+1].p_code=ct;
                sort[n+1].p_name=nt;
                sort[n+1].p_price=pt;
                sort[n+1].quantity=qt;
            }
        }
    }

    for(int m=0;m<s;m++){

        if(sort[m].p_name.length()>=5)
        cout<<"      "<<sort[m].p_code<<"      "<<sort[m].p_name<<"       "<<sort[m].p_price<<"          "<<sort[m].quantity<<endl;
        else
        cout<<"      "<<sort[m].p_code<<"       "<<sort[m].p_name<<"       "<<sort[m].p_price<<"           "<<sort[m].quantity<<endl;

    }
    super.close();
        }
          else
        {
        system("cls");
        cout<<" Wrong input!\n";
        goto m;
        }
        
again:
		int v;
		cout<<"\n\n (1) Back to menu\n (2) Exit\n Your choice : ";
		err(v);
		if(v==1)
		menu();
		else if(v==2)
		exit(0);
		else
		{
		system("cls");
		cout<<" Wrong input!\n\n";
            goto again;


      	}

}




void market::add()
	{
	system("cls");

	int d=0,i;
	int c;
	string n;
	float p;
	int q;
	again:
		i=d;
		cout<<"\n ****** Adding product ******\n\n";

		cout<<" Enter product code : ";
		err(p_code);
		cout<<" Enter product name : ";
		cin>>p_name;
		cout<<" Enter product price : ";
		err(p_price);
		cout<<" Enter product quantity : ";
		err(quantity);




			fstream super;
			super.open("superdata.txt",ios::in);

			if(!super)
			{
			super.open("superdata.txt",ios::out|ios::app);
			super<<"  "<<p_code<<"   "<<p_name<<"  "<<p_price<<"   "<<quantity<<"\n";
			super.close();
			cout<<"\n\n ...Product added...\n\n";

		    }

		    else
		    {
		    	super>>c>>n>>p>>q;
		    	while(!super.eof())
		    	{
		    		if(c==p_code)
		    		d++;
		    		super>>c>>n>>p>>q;
				}
				super.close();

			if(d>i){
				system("cls");
				cout<<"\n The code you entered is already used!\n";
				cout<<" Enter a unique code...\n";
			goto again;
		}
			else
			{
			super.open("superdata.txt",ios::out|ios::app);
			super<<"  "<<p_code<<"   "<<p_name<<"  "<<p_price<<"   "<<quantity<<"\n";
			super.close();
		}

			cout<<"\n\n ...Product added...\n\n";
			}
			a:
		int v;
		cout<<"\n\n (1) Add another product\n (2) Back to menu\n Your choice : ";
		err(v);
		if(v==1)
		add();
		else if(v==2)
		menu();
		else
		{
		system("cls");
		cout<<" Wrong input!\n\n";
            goto a;


	}
	}




void market::edit()
	{
		remove("superdata1.txt");
		system("cls");
		int c,c1;
		int ch;
		int d=0;
		float p,p1;
		string n,n1;
		int q,q1;


		fstream super,super1,sup;
		super.open("superdata.txt",ios::in);

		if(!super)
		{
	n:
			int ch;
		cout<<" There are no products found...\n";
		cout<<"\n\n (1) Back to menu\n (2) Exit\n Your choice : ";
		err(ch);
		if(ch==1)
		menu();
		else if(ch==2)
		exit(1);
		else
		{
			 system("cls");
		cout<<"\n\n Wrong input!\n\n";
		goto n;
		}
    	}
		else{

			cout<<"\n ****** Editing product*******\n\n";
	cout<<" Enter code of product you want to edit : ";
		err(ch);


		super1.open("superdata1.txt",ios::out|ios::app);
		super>>p_code>>p_name>>p_price>>quantity;

sup.open("superdata.txt",ios::in);

			while(!sup.eof())
			{
				sup>>c1>>n1>>p1>>q1;
				if(c1==ch){
		cout<<"\n Information of product you want to edit \n_________________________________\n";
					cout<<" Product code : "<<c1;
                cout<<"\n Product name : "<<n1;
                cout<<"\n Product price : "<<p1;
                cout<<"\n Product quantity : "<<q1<<endl<<"________________________________\n";
                c1++;
                sup.close();
				}
				

		}

			while(!super.eof())
			{
				if(ch==p_code){

		cout<<" Enter product new code : ";
		err(c);
		cout<<" Enter product new name : ";
		cin>>n;
		cout<<" Enter product new price : ";
		err(p);
		cout<<" Enter product new quantity : ";
		err(q);
		super1<<"  "<<c<<"   "<<n<<"  "<<p<<"   "<<q<<"\n";
		cout<<"\n ...Product edited...\n\n";
		d++;
				}
		
		       else
		       {
		       	super1<<"  "<<p_code<<"   "<<p_name<<"  "<<p_price<<"   "<<quantity<<"\n";
			   }
			   super>>p_code>>p_name>>p_price>>quantity;
		}
		
		super.close();
		super1.close();
		remove("superdata.txt");
		rename("superdata1.txt","superdata.txt");


				if(d==0)
				{
					
					system("cls");
				cout<<" Product not found...!\n\n";
				goto h;
				}
				else 
				{
					h:
		
			z:			int ch;
		cout<<" (1) Edit again \n (2) Back to menu\n Your choice : ";
		err(ch);
				if(ch==1)
		edit();
		else if(ch==2)
		menu();
		else
		{ system("cls");
		cout<<"\n\n Wrong input!\n\n";
		goto z;
		}

				}
       }
       }




void market::delt()
{
	system("cls");
	remove("superdata1.txt");

	int ch;
	cout<<"\n ****** Deleting product*******\n\n";
		cout<<" Enter code of product you want to delete : ";
		err(ch);

		int c,c1;
		int d=0;
		float p,p1;
		string n,n1;
		int q,q1;
		fstream super,super1,sup;

		super.open("superdata.txt",ios::in);

		sup.open("superdata.txt",ios::in);
		while(!sup.eof())
			{
				sup>>c1>>n1>>p1>>q1;
				if(c1==ch){
		cout<<"\n Information of product you want to delete \n_________________________________\n";
					cout<<" Product code : "<<c1;
                cout<<"\n Product name : "<<n1;
                cout<<"\n Product price : "<<p1;
                cout<<"\n Product quantity : "<<q1<<endl<<"________________________________\n";
                c1++;
                sup.close();
				}

		}

		if(!super)
		{
		cout<<" There are no products found...!\n";
    	}
		else{

		super1.open("superdata1.txt",ios::out|ios::app);
		super>>p_code>>p_name>>p_price>>quantity;

			while(!super.eof())
			{
				if(ch==p_code){
                    char gh;
                    cout<<" Enter \" y \" to delete product \n If not enter anything else : " ;
                cin>> gh;
                if(gh=='y'){
                    cout<<"\n ...Product deleted...\n\n";
                    d++;
                }
                else{
                    d=-1;
                    goto j;
                    }

		}

		       else
		       {
		           j:
		       	super1<<"  "<<p_code<<"   "<<p_name<<"  "<<p_price<<"   "<<quantity<<"\n";
			   }
			   super>>p_code>>p_name>>p_price>>quantity;
		}

		super.close();
		super1.close();
		remove("superdata.txt");
		rename("superdata1.txt","superdata.txt");


				if(d==0){
                        system("cls");
				cout<<"\n Product not found...!\n\n";
				}
				else if(d==-1)
                    cout<<"\n Deleting canceled...\n\n";
        z:
        int ch;
		cout<<" (1) Delete again\n (2) Back to menu\n Your choice : ";
		err(ch);
				if(ch==1)
		delt();
		else if(ch==2)
		menu();
		else
		{ system("cls");
		cout<<"\n\n Wrong input!\n\n";
		goto z;
		}


				}
}






void market::search()
	{

		system("cls");
		int g=0;
		int c;
		int ch;
		string pn;
		int pc;
		int q;
		float p;
		string n;
		fstream super,tran;

		super.open("superdata.txt",ios::in);
		if(!super)
		cout<<" There are no products...!\n";
		else{
again:
g:
			cout<<"\n ****** Searching for product *******\n\n";
			cout<<" (1) Search by code\n (2) search by name\n Your choice : ";
			err(ch);
			if(ch==1){
                    system("cls");
			cout<<" Enter code of product you want to search for : ";
		err(pc);
		}
		else if(ch==2){
                system("cls");
		cout<<" Enter name of product you want to search for : ";
		cin>>pn;
	}
	else
	{
		system("cls");
	cout<<" Wrong input!\n";
	goto g;
	}

int s=0;

	tran.open("superdata.txt",ios::in);
		while(!tran.eof()){

		tran>>c>>n>>p>>q;
		if(!tran.eof())
            {
		s++;
            }
		}
            tran.close();
	market sup[s];
	s=0;
		while(!super.eof()){

		super>>c>>n>>p>>q;
		if(!super.eof())
            {
		sup[s].p_code=c;
		sup[s].p_name=n;
		sup[s].p_price=p;
		sup[s].quantity=q;
		s++;
            }
		}
			super.close();
			for(int i=0;i<s;i++)
            {
        if(sup[i].p_code==pc||sup[i].p_name==pn)
            {
                cout<<"\n Product code : "<<sup[i].p_code<<endl;
                cout<<" Product name : "<<sup[i].p_name<<endl;
                cout<<" Product price : "<<sup[i].p_price<<endl;
                cout<<" Product quantity : "<<sup[i].quantity<<endl;
                g++;
                break;
                }
            }
		}
		if(g==0)
            {
                system("cls");
            cout<<" Product not found...\n";
		    }
		int v;
		cout<<"\n\n (1) Search for another product\n (2) Back to menu\n Your choice : ";
		err(v);
		if(v==1)
		search();
		else if(v==2)
		menu();
		else
		{
		system("cls");
            goto again;
		}

	}


int main()
{
	start.menu();
}

