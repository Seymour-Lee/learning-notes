#include "shares.h"
#include "utils.h"
#include "router.h"

int main(int argc, char const *argv[]){
    cout<<"in main()"<<endl;

    try{
        // parse args && get conf info
        utils::getConf(argc, argv);
        cout<<global::config_file_name<<" "<<global::stage<<" "<<global::num_routers<<endl;

        // run process:
        // clear env
        utils::cleanEnv();

        // set socket
        int s = utils::initSocket();
        cout<<"init socket s is "<<s<<endl;
        if(s < 0) throw "an error occured while initializing socket";

        // fork child process
        global::pid = fork();
        cout<<"after fork(), global::pid is "<<global::pid<<endl;
        // run self or child
        Router *router = nullptr;
        if(global::pid == 0) router = new Secondary();
        else router = new Primary();
        router->run(global::stage);
    }
    catch(exception& e){
        cout<<"in catch"<<endl;
        cout << e.what() << endl;
    }
    
    return 0;
}