#include <iostream>
#include <unordered_map>
using namespace std;
class AuthenticationManager {
private:
    int timetolive;
    unordered_map<string, int> tokens;
public:
    AuthenticationManager(int timeToLive) {
        timetolive = timeToLive;
    }
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + timetolive;
    }
    void renew(string tokenId, int currentTime) {
        if (tokens.count(tokenId)&& tokens[tokenId] > currentTime){
            tokens[tokenId] = currentTime + timetolive;
        }
    }
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for(auto &pair : tokens){
            if(pair.second > currentTime){
                count++;
            }
        }
        return count;
    }
};
int main() {
    AuthenticationManager am(5);
    am.generate("token1", 1);
    am.generate("token2", 2);
    cout << "Unexpired tokens at time 3: " << am.countUnexpiredTokens(3) << endl;
    am.renew("token1", 4);
    cout << "Unexpired tokens at time 5: " << am.countUnexpiredTokens(5) << endl;
    cout << "Unexpired tokens at time 7: " << am.countUnexpiredTokens(7) << endl;
    return 0;
}   