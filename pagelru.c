#include <stdio.h>
#define MAX_FRAMES 4
#define MAX_PAGES 10
int main() {
    int frames[MAX_FRAMES], pages[MAX_PAGES], counter[MAX_FRAMES];
    int n, m, i, j, page_faults = 0, page_hits = 0, min, replace_index;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
        counter[i] = 0;
    }
    printf("\nReference String\t Page Frames\t Page Faults\n");
    for (i = 0; i < n; i++) {
        printf("   %d\t\t    ", pages[i]);
        int page_found = 0;
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                page_hits++;
                page_found = 1;
                counter[j] = i + 1;
                break;
            }
        }
        if (!page_found) {
            page_faults++;
            min = counter[0];
            replace_index = 0;
            for (j = 1; j < MAX_FRAMES; j++) {
                if (counter[j] < min) {
                    min = counter[j];
                    replace_index = j;
                }
            }
            frames[replace_index] = pages[i];
            counter[replace_index] = i + 1;
            for (j = 0; j < MAX_FRAMES; j++)
                printf("%d ", frames[j]);
            printf("\tPage Fault");
        } else {
            for (j = 0; j < MAX_FRAMES; j++)
                printf("%d ", frames[j]);
            printf("\tPage Hit");
        }
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", page_hits);
    return 0;
}
