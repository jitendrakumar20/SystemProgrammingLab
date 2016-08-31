

typedef struct pqueue *PQUEUE;
extern PQUEUE initialize(PQUEUE Q);
extern int isEmpty(PQUEUE Q);
extern int Insert(PQUEUE Q, int x);
extern int extractMax(PQUEUE Q, int *x);
extern void destroy(PQUEUE Q); 