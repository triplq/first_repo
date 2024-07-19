#include "golova.h"

int main() {
    try
    {
        session sql(mysql, "db=soci_db user=soci_dev1 password=98_+20Lok23");
//        cout << "choose:\n";
//        int answer{4};
//        while(true)
//        {
//            cout << "1.enter as a admin \t 2.enter as a user\t 3.exit\n";
//            cin >> answer;
//            if(answer == 1)
//                admin(sql);
////            else if(answer == 2)
////                user(sql);
//            else if(answer == 3)
//                return 0;
//        }

        insert_into_flights(sql);

//        int n;
//        sql << "SELECT count(flight_id) FROM flights WHERE seats = 30", into(n);
//        int flights_id[n];
    }
    catch(const exception& e)
    {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }
}
