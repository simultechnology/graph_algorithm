#include <stdio.h>
#include <string.h>

#define MAX_STATION (10)

typedef struct TAG_STATION {
    char name[256];
    struct TAG_STATION *transactions[MAX_STATION];
} STATION;

void init_station(STATION *station, char* name) {
    int i;
    for (i = 0; i < MAX_STATION; i++) {
        station->transactions[i] = NULL;
    }
    strncpy(station->name, name, sizeof(station->name) - 1);
    station->name[sizeof(station->name) - 1] = '\0';
}

void add_station(STATION* station, STATION* transition) {
    int i;
    for (i = 0; i < MAX_STATION; i++) {
        if (station->transactions[i] == NULL) {
            break;
        }
        if (station->transactions[i] == transition) {
            return;
        }
    }
    if (i == MAX_STATION) {
        return;
    }
    /* 新しい乗り換え駅を登録する */
    station->transactions[i] = transition;
}

void print_station(STATION* station) {
    int i;
    printf("%s : ", station->name);
    for (i = 0; i < MAX_STATION; i++) {
        if (station->transactions[i] == NULL) {
            break;
        }
        printf("->%s ", station->transactions[i]->name);
    }
    printf("\n");
}

int main(void) {
    int i;
    STATION station[6];
    init_station(&station[0], "鎌倉");
    init_station(&station[1], "藤沢");
    init_station(&station[2], "横浜");
    init_station(&station[3], "横須賀");
    init_station(&station[4], "茅ヶ崎");
    init_station(&station[5], "東京");

    /* 鎌倉 */
    add_station(&station[0], &station[3]);
    add_station(&station[0], &station[1]);
    add_station(&station[0], &station[2]);
    /* 藤沢 */
    add_station(&station[1], &station[0]);
    add_station(&station[1], &station[4]);
    add_station(&station[1], &station[2]);
    /* 横浜 */
    add_station(&station[2], &station[1]);
    add_station(&station[2], &station[0]);
    add_station(&station[2], &station[5]);
    /* 横須賀・茅ヶ崎・東京 */
    add_station(&station[3], &station[0]);
    add_station(&station[4], &station[1]);
    add_station(&station[5], &station[2]);

    for (i = 0; i < 6; i++) {
        print_station(&station[i]);
    }
    return 0;
}