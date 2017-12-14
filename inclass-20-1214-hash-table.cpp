#include <stdio.h>
#include <string.h>
#define MOD 101
int hash1(char *s) {
	int ans = 0;
	for(char *c=s; *c != '\0'; c++) {
		ans += (int)*c;
	}
	return ans % MOD;
}
char names[100][12] = {"Jacob", "Mason", "William", "Jayden", "Noah", "Michael", "Ethan", "Alexander", "Aiden", "Daniel", "Anthony", "Matthew", "Elijah", "Joshua", "Liam", "Andrew", "James", "David", "Benjamin", "Logan", "Christopher", "Joseph", "Jackson", "Gabriel", "Ryan", "Samuel", "John", "Nathan", "Lucas", "Christian", "Jonathan", "Caleb", "Dylan", "Landon", "Isaac", "Gavin", "Brayden", "Tyler", "Luke", "Evan", "Carter", "Nicholas", "Isaiah", "Owen", "Jack", "Jordan", "Brandon", "Wyatt", "Julian", "Aaron", "Sophia", "Isabella", "Emma", "Olivia", "Ava", "Emily", "Abigail", "Madison", "Mia", "Chloe", "Elizabeth", "Ella", "Addison", "Natalie", "Lily", "Grace", "Samantha", "Avery", "Sofia", "Aubrey", "Brooklyn", "Lillian", "Victoria", "Evelyn", "Hannah", "Alexis", "Charlotte", "Zoey", "Leah", "Amelia", "Zoe", "Hailey", "Layla", "Gabriella", "Nevaeh", "Kaylee", "Alyssa", "Anna", "Sarah", "Allison", "Savannah", "Ashley", "Audrey", "Taylor", "Brianna", "Aaliyah", "Riley", "Camila", "Khloe", "Claire"};
int main() {
	int table[MOD];
	int count;
	
	memset(table, 0, sizeof(table));
	count = 0;
	printf("idx  name          ori  new   all     avg\n");
	for(int q=0; q<100; q++) {
		printf("%3d  %-12s  %3d", q, names[q], hash1(names[q]));
		int res = hash1(names[q]);
		while(table[res]) {
			count++;
			res++;
			res %= MOD;
		}
		count++;
		table[res] = 1;
		printf("  %3d  %4d  %6.3lf\n", res, count, (double)count/(q+1));
	}
	printf("-----------------------------------------\n");
	printf("idx  name          ori  new   all     avg\n");
	count = 0;
	memset(table, 0, sizeof(table));
	for(int q=0; q<100; q++) {
		printf("%3d  %-12s  %3d", q, names[q], hash1(names[q]));
		long long res = hash1(names[q]);
		for(long long  w=1; table[res] && w<MOD; w++) {
			count++;
			res += w*w-(w-1)*(w-1);
			res %= MOD;
		}
		count++;
		if(table[res]) {
			printf("  %3d  %4d  %6.3lf\n", -1, count, (double)count/(q+1));
		} else {
			table[res] = 1;
			printf("  %3I64d  %4d  %6.3lf\n", res, count, (double)count/(q+1));
		}
	}
}
