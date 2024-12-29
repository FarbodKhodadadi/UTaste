#include "global.hpp"
#include "main.hpp"

int main(int argc ,char* argv[]){

    //string restaurants_path = argv[1];
    //string districts_path = argv[2];
    vector<Restaurant*> restaurants;
    vector<District*> districts;
    // CsvData Loader(restaurants_path,districts_path);
    // restaurants= Loader.loadRestaurants();
    // districts= Loader.loadDistricts();
    vector<User*> users;
    CommandHandle cmd(restaurants,districts,users);
    string input;

    while(getline(cin,input)){
        try{
                cmd.commandProcess(input);
        }
        catch(const BadReqException& e){
            cerr << e.getMessageBadRequest() << '\n';
        }
        catch(const NotFoundException& e){
            cout << e.getMessageNotFound() << '\n';
        }
        catch(const EmptyException& e){
            cerr << e.getMessageEmpty() << '\n';
        }
        catch(const PermisionException& e){
            cerr << e.getMessagePermission() << '\n';
        }
    }
    for (auto r : restaurants) delete r;
    for (auto d : districts) delete d;
    for (auto u : users) delete u;
    
}