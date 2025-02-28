#include <iostream>

using namespace std;

int main(){

    int quant;
    int choice;
    // Quantity that we have
    int Qrooms = 0, Qpasta =0, Qburger =0, Qnoodles = 0, Qshake = 0, Qchicken = 0;
    // Quantity that we sold
    int Srooms = 0, Spasta = 0 , Sburger = 0, Snoodles=0, Sshake = 0, Schicken=0;
    // the total price
    int Total_rooms = 0, Total_pasta =0, Total_burger =0,Total_noodles =0, Total_shake=0,Total_chicken=0;

    cout <<"\n\t Quantity of items we have";
    cout <<"\n Rooms avaliable: ";
    cin >> Qrooms;
    cout << "\n Quantity of pasta: ";
    cin >> Qpasta;
    cout << "\n Qauntity of burger : ";
    cin >> Qburger;
    cout << "\n Qauntity of noodles : ";
    cin >> Qnoodles;
    cout << "\n Qauntity of shake : ";
    cin >> Qshake;
    cout << "\n Qauntity of Chicken-role : ";
    cin >> Qchicken;

    m:
    cout << "\n\t\t\t Please select from the given menu options ";
    cout <<"\n\n 1) Rooms";
    cout <<"\n 2) Pasta";
    cout <<"\n 3) Burger";
    cout <<"\n 4) Noodles";
    cout <<"\n 5) Shake ";
    cout <<"\n 6) Chicken-roll ";
    cout <<"\n 7) Information regarding slaes and collection ";
    cout <<"\n 8) Exit";

    cout << "\n\n Please Enter your choice! ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            cout << "Enter the number of rooms that you want:";
            cin >> quant;
            if(Qrooms-Srooms >=quant)
            {
                Srooms= Srooms+quant;
                Total_rooms = (Total_rooms + quant)*1200;
                cout << "\n\n\t\t" << quant << " room/rooms have been aloted to you!";
            }else 
            {
                cout <<"\n\t Only " << Qrooms-Srooms << " Rooms remaining in hotel " ;
            }
            break;
        
        case 2:
            cout << "Enter Pasta Quantity : ";
            cin >> quant;
            if(Qpasta-Spasta >=quant)
            {
                Spasta= Spasta+quant;
                Total_pasta = (Total_pasta + quant)*250;
                cout << "\n\n\t\t" << quant << " pasta is the order!";
            }else 
            {
                cout <<"\n\t Only " << Qpasta-Spasta<< " Pasta remaining in hotel " ;
            }
            break;
        case 3:
            cout << "Enter Burger Quantity : ";
            cin >> quant;
            if(Qburger-Sburger >=quant)
            {
                Sburger= Sburger+quant;
                Total_burger = (Total_burger + quant)*120;
                cout << "\n\n\t\t" << quant << " burger is the order!";
            }else 
            {
                cout <<"\n\t Only " << Qburger-Sburger<< " Burger remaining in hotel " ;
            }
            break;
        case 4:
            cout << "Enter Noodles Quantity : ";
            cin >> quant;
            if(Qnoodles-Snoodles >=quant)
            {
                Snoodles= Snoodles+quant;
                Total_noodles = (Total_noodles + quant)*140;
                cout << "\n\n\t\t" << quant << " noodles is the order!";
            }else 
            {
                cout <<"\n\t Only " << Qnoodles - Snoodles<< " Noodles remaining in hotel " ;
            }
            break;
        case 5:
            cout << "Enter Shakes Quantity : ";
            cin >> quant;
            if(Qshake - Sshake >=quant)
            {
                Sshake= Sshake+quant;
                Total_shake = (Total_shake + quant)*120;
                cout << "\n\n\t\t" << quant << " Shakes is the order!";
            }else 
            {
                cout <<"\n\t Only " << Qshake - Sshake<< " Shakes remaining in hotel " ;
            }
            break;
        case 6:
            cout << "Enter Chicken-roll Quantity : ";
            cin >> quant;
            if(Qchicken - Schicken >=quant)
            {
                Schicken= Schicken+quant;
                Total_chicken = (Total_chicken + quant)*150;
                cout << "\n\n\t\t" << quant << " Chicken is the order!";
            }else 
            {
                cout <<"\n\t Only " << Qchicken - Schicken << " Chicken-roll remaining in hotel " ;
            }
            break;

        case 7:
            cout <<"\n\t\tDetails of sales and collectoins " ;
            cout <<"\n\n Number of rooms we had : " << Qrooms;
            cout <<"\n\n Number of rooms we give for rent : " << Srooms;
            cout <<"\n\n Remaining rooms : " << Qrooms-Srooms;
            cout <<"\n\n Total rooms collection for the day : " << Total_rooms;
            
            cout <<"\n\n Number of Pastas we had : " << Qpasta;
            cout <<"\n\n Number of Pastas we sold : " << Spasta;
            cout <<"\n\n Remaining Pastas : " << Qpasta-Spasta;
            cout <<"\n\n Total Pasta collection for the day : " << Total_pasta;

            cout <<"\n\n Number of Burgers we had : " << Qburger;
            cout <<"\n\n Number of Burgers we sold : " << Sburger;
            cout <<"\n\n Remaining Burgers : " << Qburger-Sburger;
            cout <<"\n\n Total Burger collection for the day : " << Total_burger;

            cout <<"\n\n Number of Noodles we had : " << Qnoodles;
            cout <<"\n\n Number of Noodles we sold : " << Snoodles;
            cout <<"\n\n Remaining Noodles : " << Qnoodles-Snoodles;
            cout <<"\n\n Total Noodle collection for the day : " << Total_noodles;

            cout <<"\n\n Number of Shakes we had : " << Qshake;
            cout <<"\n\n Number of Shakes we sold : " << Sshake;
            cout <<"\n\n Remaining Shakes : " << Qshake-Sshake;
            cout <<"\n\n Total Shakes collection for the day : " << Total_shake;

            cout <<"\n\n Number of chicken-roll we had : " << Qchicken;
            cout <<"\n\n Number of Chicken-roll we sold : " << Schicken;
            cout <<"\n\n Remaining Chicken-roll : " << Qchicken-Schicken;
            cout <<"\n\n Total Chicken-roll collection for the day : " << Total_chicken;

            cout << "\n\n\n Total Collection for the day: " << Total_rooms+Total_burger+Total_pasta+Total_noodles+Total_shake+Total_chicken;
            
        case 8:
            exit(0);
        default:
            cout << "\n Please select the numbers mentioned above!";
    }
    cout << endl;

    goto m;

}