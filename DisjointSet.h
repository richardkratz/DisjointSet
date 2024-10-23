#ifndef DISJOINTSET_H
#define	DISJOINTSET_H
#include <vector>
using namespace std;

class DisjointSet {
	private:
	vector<size_t>				id;		// Kopfknoten der Knotenindizes in Vektor der länge n speichern
	vector<size_t>				rank;	// Zweites Array für Rang des Baums des entsprechenden Knotenindex
	
	public:
	// Konstruktoren
	DisjointSet(size_t n) {	
		for(size_t i=0; i < n ; ++i) {
			id.push_back(i);
			rank.push_back(1);
		}
	}
	DisjointSet() {}
	~DisjointSet() {}

	// union-find methoden
	size_t find(size_t x) {
		if (id[x] == x)
			return x;
		else {
			id[x] = id[id[x]];
			return find(id[x]);
		}
	}

	void unite(size_t x, size_t y) {
		size_t i = find(x);
		size_t j = find(y);
		if(rank[i] < rank[j]) {
			rank[j]	+= rank[i];
			id[i]    = j;
		}
		else {
			rank[i] += rank[j];
			id[j]    = i;
		}
	}
	// Hilfsmethode um Container mit entsprechenden Daten zu füllen
	void reset(size_t count) {
		id.clear();
		rank.clear();
		for( size_t i = 0; i < count; ++i ) {
			id.push_back(i); 
			rank.push_back(1);
		}
	}
};
#endif // DISJOINTSET_H