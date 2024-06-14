#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

int main() {
    int frames[MAX_FRAMES], pages[MAX_PAGES];
    int n, m, i, j, page_faults = 0, page_hits = 0, k = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    for (i = 0; i < MAX_FRAMES; i++)
    {
        frames[i] = -1;
    }
    printf("\nReference String Page Frames Page Faults\n");
    for (i = 0; i < n; i++) {
        printf("   %d\t\t    ", pages[i]);
        int page_found = 0;
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                page_hits++;
                page_found = 1;
                break;
            }
        }
        if (!page_found) {
            frames[k] = pages[i];
            k = (k + 1) % MAX_FRAMES;
            page_faults++;
            for (j = 0; j < MAX_FRAMES; j++)
            {
                if(frames[j]==-1)
                {
                    printf(" 0");
                }
                else
                {
                    printf("%d ", frames[j]);
                }
            }
            printf("\tPage fault");
        } else 
        {
            for (j = 0; j < MAX_FRAMES; j++)
            {
                printf("%d ", frames[j]);
            }
            printf("\tPage Hit");
        }
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", page_hits);
    return 0;
}