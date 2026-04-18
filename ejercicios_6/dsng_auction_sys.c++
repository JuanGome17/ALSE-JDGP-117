#include <iostream>
#include <unordered_map>
using namespace std;
class AuctionSystem {
private:
    unordered_map<int, unordered_map<int, int>> bids;
public:
    AuctionSystem() {
    }
    void addBid(int userId, int itemId, int bidAmount) {
        bids[itemId][userId] = bidAmount;
    }
    void updateBid(int userId, int itemId, int newAmount) {
        if (bids.count(itemId) && bids[itemId].count(userId)) {
            bids[itemId][userId] = newAmount;
        }
    }
    void removeBid(int userId, int itemId) {
        if (bids.count(itemId)) {
            bids[itemId].erase(userId);
        }
    }
    int getHighestBidder(int itemId) {
        if (!bids.count(itemId) || bids[itemId].empty()) {
            return -1;
        }
        int maxBid = -1;
        int bestUser = -1;
        for (auto &pair : bids[itemId]) {
            if (pair.second > maxBid) {
                maxBid = pair.second;
                bestUser = pair.first;
            }
        }
        return bestUser;
    }
};
int main() {
    AuctionSystem auction;
    auction.addBid(1, 100, 50);
    auction.addBid(2, 100, 60);
    cout << "Highest bidder for item 100: " << auction.getHighestBidder(100) << endl; // Should print 2
    auction.updateBid(1, 100, 70);
    cout << "Highest bidder for item 100: " << auction.getHighestBidder(100) << endl; // Should print 1
    auction.removeBid(1, 100);
    cout << "Highest bidder for item 100: " << auction.getHighestBidder(100) << endl; // Should print 2
    return 0;
}