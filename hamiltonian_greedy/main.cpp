#include <iostream>
#include <vector>

int startingCity(std::vector<int>& distance, std::vector<int>& fuel, int mpg) {
	int size = distance.size();
	int starting_city = 0;
	int fuel_left = 0;
	int cost = 0;
	for (int i = 0; i < size; i++) {
		cost = fuel[i] * mpg - distance[i]; // how much it takes to get to the i-th city
		fuel_left += cost;					// how much fuel the car have after travelling to the i-th city
		if (fuel_left <= 0) {				// if there is no more fuel, that means i + 1 cannot be reached from i
			starting_city = i + 1;			// so starting city cannot be i, so we assume its i + 1 and move to next iteration
			fuel_left = 0;					// reset fuel
		}
	}
	return starting_city;					// return answer
}

int main() {
	std::vector<int> city_distances = {5, 25, 15, 10, 15};
	std::vector<int> fuel = {1, 2, 1, 0, 3};
	int mpg = 10;
	int starting_city = startingCity(city_distances, fuel, mpg);
	std::cout << "The optimal starting city is: " << starting_city << '\n';
	return 0;
}
