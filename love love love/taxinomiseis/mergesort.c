#include <stdio.h>
//O(nlogn) O(n)

void merge(int *x, int l, int m, int r){
    int i, j, k, n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for (i = 0; i < n1; i++){
        left[i] = x[l + i];
    } 
    for (j = 0; j < n2; j++){
        right[j] = x[m + 1 + j];
    } 
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]){
            x[k++] = left[i++];
        }else{
            x[k++] = right[j++];
        }
    }
    while (i < n1){
        x[k++] = left[i++];
    } 
    while (j < n2){
        x[k++] = right[j++];
    } 
}
void merge_sort(int *array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}
int main() {
    int left = 0;
    int right = 9;
    int x[10] = {1,2,5,7,3,4,8,1,2};
    merge_sort(x,left,right);
    for(int i = 0;i < 10;i++){
        printf("%02d\n", x[i]);
    }
    return 0;
}

// Διαίρεση του πίνακα:

// Ο πίνακας χωρίζεται αναδρομικά σε δύο υποπίνακες, μέχρι να φτάσουμε σε υποπίνακες με μέγεθος 1 (οι οποίοι είναι έτοιμοι να θεωρηθούν ταξινομημένοι).
// Αναδρομική Διαίρεση:

// Στην συνάρτηση merge_sort, η μέση θέση του πίνακα υπολογίζεται και καλείται αναδρομικά για την αριστερή και την δεξιά υπολίστα.
// Αυτό συνεχίζεται μέχρι όλες οι υπολίστες να έχουν μόνο ένα στοιχείο.
// Συγχώνευση (Merge):

// Στην συνάρτηση merge, οι δύο υπολίστες συγχωνεύονται σε έναν ενιαίο ταξινομημένο πίνακα.
// Ο πίνακας συγχωνεύεται με την βοήθεια τριών δεικτών: i, j και k για την αριστερή, δεξιά υπολίστα και τον αρχικό πίνακα αντίστοιχα.
// Οι στοιχείες των δύο υπολιστών συγκρίνονται μεταξύ τους και το μικρότερο στοιχείο τοποθετείται στον τελικό πίνακα.
// Συγχώνευση Υπολιστών:

// Αν κάποιο στοιχείο παραμένει στην αριστερή ή δεξιά υπολίστα (ενώ η άλλη υπολίστα έχει εξαντληθεί), τα υπόλοιπα στοιχεία αυτής της υπολίστας αντιγράφονται στον τελικό πίνακα.