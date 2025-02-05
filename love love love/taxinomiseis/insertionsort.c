#include <stdio.h>
//O(n^2) O(1)

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void insertion_sort(int n, int *x) {
    int i, j;
    for (i = 1 ; i <= n - 1 ; i++) {
        j = i - 1;
        while (j >= 0 && x[j] > x[j+1]) {
            swap(&x[j], &x[j+1]);
                j--;
        }
    }
}
int main() {
    int n = 10;
    int x[10] = {1,2,5,7,3,4,8,1,2};
    insertion_sort(n,x);
    for(int i = 0;i < 10;i++){
        printf("%02d\n", x[i]);
    }
    return 0;
}

// Ιδέα:
// Ξεκινάμε από το δεύτερο στοιχείο της λίστας.
// Συγκρίνουμε το στοιχείο με τα στοιχεία πριν από αυτό και το τοποθετούμε στην κατάλληλη θέση έτσι ώστε τα πρώτα στοιχεία της λίστας να παραμένουν ταξινομημένα.
// Επαναλαμβάνουμε τη διαδικασία για κάθε επόμενο στοιχείο μέχρι να ταξινομηθεί ολόκληρη η λίστα.
// Βήματα:
// Αρχικοποίηση: Ο αλγόριθμος ξεκινά από το δεύτερο στοιχείο (θέση 1) και το θεωρεί ως "μη ταξινομημένο" στοιχείο.
// Σύγκριση και εισαγωγή: Αυτό το στοιχείο συγκρίνεται με τα στοιχεία πριν από αυτό στην ταξινομημένη υπολίστα. Εάν το στοιχείο είναι μικρότερο από κάποιο προηγούμενο στοιχείο, αυτό το στοιχείο "μετακινείται" προς τα δεξιά.
// Εισαγωγή στη σωστή θέση: Όταν βρει τη σωστή θέση του,δλδ την θεση οπου το προηγουμενο στοιχειο ειναι μικροτερο κ το επομενο μεγαλυτερο, τοποθετείται εκεί.
// Επανάληψη: Επαναλαμβάνεται η διαδικασία για τα υπόλοιπα στοιχεία μέχρι να ταξινομηθεί ολόκληρη η λίστα.