#include <stdio.h>
int main() {
	int arr[] = {7, 2, 9, 3, 1, 8, 6, 4};
	int len = 8, outerIdx, innerIdx, elementAtOuterIdx = 0, i;
	for (outerIdx = 1; outerIdx < len; outerIdx++) {
		elementAtOuterIdx = arr[outerIdx];
		for (innerIdx = outerIdx; innerIdx > 0; innerIdx--) {
			if (arr[innerIdx - 1] > elementAtOuterIdx) {
				arr[innerIdx] = arr[innerIdx - 1];
				arr[innerIdx - 1] = elementAtOuterIdx;
			}
		}
	}
	for(i = 0; i < len; i++) {
		printf(" %d", arr[print]);
	}
}