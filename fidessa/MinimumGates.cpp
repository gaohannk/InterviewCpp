/*
 * MinimumGates.cpp
 *
 *  Created on: May 6, 2016
 *      Author: gaohan
 */
/* At an airport you have a timetable for arrivals and departures.
 * You need to determine the minimum number of gates you*d need to provide so that all the planes can be placed at a gate as per their schedule.
 * The arrival and departure times for each plane are presented in two arrays, sorted by arrival time, and you're told the total number of flights for the
 * day. Assume that no planes remain overnight at the airport; all fly in and back out on the same day. Assume that if a plane departs in the same minute as another plane arrives, the arriving plane takes priority (i.e. you'll still need the gate for the departing plane). Write a function that returns
 * the minimum number of gates needed for the schedules you're given.
 * Example:
 * arrQ = {900, 940, 950, 1100,1500,1800}
 * depQ = {910,1200,1120, 1130,1900, 2000}
 * flights = 6
 */
#include <algorithm>
#include <queue>

using namespace std;
class Pair {
public:
	int arr;
	int dep;
	Pair(int a, int b) {
		this->arr = a;
		this->dep = b;
	}
};
class MinimumGates {

public:
	int findMinGates(vector<int> arrQ, vector<int> depQ, int flight) {
		Pair pairs[flight];
		for (int i = 0; i < flight; i++) {
			pairs[i] = new Pair(arrQ[i], depQ[i]);
		}
		sort(pairs, pairs + flight, cmp);
		priority_queue<Pair> pq;
		pq.push(pairs[0]);
		int count = 0;
		for (int i = 1; i < flight; i++) {
			Pair p = pq.top();
			if (arrQ[i] >= p.dep) {
				pq.pop();
				pq.push(pairs[i]);
			} else {
				count++;
				pq.push(pairs[i]);
			}
		}
		return count;
	}
	bool cmp(Pair p1, Pair p2) {
		return (p1.arr < p2.arr);
	}
	bool operator<(Pair p1, Pair p2) {
		return (p1.dep < p2.dep);
	}
};

