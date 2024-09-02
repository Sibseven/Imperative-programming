#include <stdio.h>
int main(){
	int n,m,p,k,l = 0;
	scanf("%d %d %d %d %d", &n, &m, &p, &k, &l);
    int used_floors = ((p - 1) * l) + k - 1;
	int flats_on_floor = m / used_floors;
	int flats_on_stage = flats_on_floor * l;
	int stage_n, floor_n = 0;
	if (n % flats_on_stage == 0){
		stage_n = n / flats_on_stage;
		floor_n = l;
		printf("%d %d", stage_n, floor_n);
		return 0;
	}
	else {
		stage_n = n / flats_on_stage + 1;
	}
	floor_n = n % flats_on_stage;
	if (floor_n % flats_on_floor == 0){
		floor_n = floor_n / flats_on_floor;
	}
	else {
		floor_n = floor_n / flats_on_floor + 1;
	}
	printf("%d %d", stage_n, floor_n);
	return 0;
}

