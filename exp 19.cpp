#include <stdio.h>

typedef struct {
    int weight;
    int value;
} Item;

void knapsack(Item items[], int n, int W) {
    double ratio[n];
    for (int i = 0; i < n; i++)
        ratio[i] = (double)items[i].value / items[i].weight;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                double temp_ratio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp_ratio;

                Item temp_item = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp_item;
            }
        }
    }

    int cur_weight = 0;
    double final_value = 0.0;

    for (int i = 0; i < n; i++) {
        if (cur_weight + items[i].weight <= W) {
            cur_weight += items[i].weight;
            final_value += items[i].value;
        } else {
            int remain = W - cur_weight;
            final_value += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", final_value);
}

int main() {
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    int n = sizeof(items) / sizeof(items[0]);
    knapsack(items, n, W);
    return 0;
}

