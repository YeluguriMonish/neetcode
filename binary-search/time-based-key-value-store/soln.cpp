#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
class TimeMap {
public:
  map<string, vector<tuple<int, string>>> time_map;

  TimeMap() {}

  void set(string key, string value, int timestamp) {
    time_map[key].push_back(make_tuple(timestamp, value));
  }

  string get(string key, int timestamp) {

    int low = 0;
    int high = time_map[key].size() - 1;
    int mid = high / 2;
    int largest_timestamp_index = -1;
    if (high == -1) {
      return "";
    }

    while (low <= high) {
      if (std::get<0>(time_map[key][mid]) <= timestamp) {
        if (largest_timestamp_index == -1) {
          largest_timestamp_index = mid;
        } else if (std::get<0>(time_map[key][mid]) >
                   std::get<0>(time_map[key][largest_timestamp_index])) {
          largest_timestamp_index = mid;
        }
      }

      if (std::get<0>(time_map[key][mid]) == timestamp) {
        return std::get<1>(time_map[key][mid]);
      } else if (std::get<0>(time_map[key][mid]) < timestamp) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }

      mid = low + (high - low) / 2;
    }

    if (largest_timestamp_index == -1) {
      return "";
    }
    return std::get<1>(time_map[key][largest_timestamp_index]);
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {

  TimeMap *timeMap = new TimeMap();
  timeMap->set("love", "high", 10);
  timeMap->set("love", "low", 20);
  string res = timeMap->get("love", 5);
  cout << "result: " << res << endl;
}
