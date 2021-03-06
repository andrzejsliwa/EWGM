#include "game.h"

// http://pages.ripco.net/~jgamble/nw.html

//#define _min(a, b) (d[a]->_z<d[b]->_z?d[a]:d[b])
//#define _max(a, b) (d[a]->_z<d[b]->_z?d[b]:d[a])
#define _min(a,b) ((d[a]->_z<d[b]->_z) ? d[a] : ((d[a]->_z>d[b]->_z) ? d[b] : (d[a] > d[b] ? d[a] : d[b])))
#define _max(a,b) ((d[a]->_z>d[b]->_z) ? d[a] : ((d[a]->_z<d[b]->_z) ? d[b] : (d[a] < d[b] ? d[a] : d[b])))
#define SWAP(x,y) { object_t* a = _min(x,y);object_t* b = _max(x,y); d[x] = a; d[y] = b; }


static void sort0(__UNUSED object_t **d){
}

static void sort2(object_t **d){
  SWAP(0,1);
}

static void sort3(object_t **d){
  SWAP(1,2);
  SWAP(0,2);
  SWAP(0,1);
}

static void sort4(object_t **d){
  SWAP(0,1);
  SWAP(2,3);
  SWAP(0,2);
  SWAP(1,3);
  SWAP(1,2);
}

static void sort5(object_t **d){
  SWAP(0,1);
  SWAP(3,4);
  SWAP(2,4);
  SWAP(2,3);
  SWAP(1,4);
  SWAP(0,3);
  SWAP(0,2);
  SWAP(1,3);
  SWAP(1,2);
}

static void sort6(object_t **d){
  SWAP(1,2);
  SWAP(4,5);
  SWAP(0,2);
  SWAP(3,5);
  SWAP(0,1);
  SWAP(3,4);
  SWAP(2,5);
  SWAP(0,3);
  SWAP(1,4);
  SWAP(2,4);
  SWAP(1,3);
  SWAP(2,3);
}


#if OBJECT_MAX_OBJECTS > 6
static void sort7(object_t **d){
  SWAP(1,2);
  SWAP(3,4);
  SWAP(5,6);
  SWAP(0,2);
  SWAP(3,5);
  SWAP(4,6);
  SWAP(0,1);
  SWAP(4,5);
  SWAP(2,6);
  SWAP(0,4);
  SWAP(1,5);
  SWAP(0,3);
  SWAP(2,5);
  SWAP(1,3);
  SWAP(2,4);
  SWAP(2,3);
}
#endif

#if OBJECT_MAX_OBJECTS > 7
static void sort8(object_t **d){
  SWAP(0,1);
  SWAP(2,3);
  SWAP(4,5);
  SWAP(6,7);
  SWAP(0,2);
  SWAP(1,3);
  SWAP(4,6);
  SWAP(5,7);
  SWAP(1,2);
  SWAP(5,6);
  SWAP(0,4);
  SWAP(3,7);
  SWAP(1,5);
  SWAP(2,6);
  SWAP(1,4);
  SWAP(3,6);
  SWAP(2,4);
  SWAP(3,5);
  SWAP(3,4);
}
#endif

#if OBJECT_MAX_OBJECTS > 8
static void sort9(object_t **d){
  SWAP(0,1);
  SWAP(3,4);
  SWAP(6,7);
  SWAP(1,2);
  SWAP(4,5);
  SWAP(7,8);
  SWAP(0,1);
  SWAP(3,4);
  SWAP(6,7);
  SWAP(2,5);
  SWAP(0,3);
  SWAP(1,4);
  SWAP(5,8);
  SWAP(3,6);
  SWAP(4,7);
  SWAP(2,5);
  SWAP(0,3);
  SWAP(1,4);
  SWAP(5,7);
  SWAP(2,6);
  SWAP(1,3);
  SWAP(4,6);
  SWAP(2,4);
  SWAP(5,6);
  SWAP(2,3);
}
#endif


#if OBJECT_MAX_OBJECTS > 9
static void sort10(object_t **d){
  SWAP(4,9);
  SWAP(3,8);
  SWAP(2,7);
  SWAP(1,6);
  SWAP(0,5);
  SWAP(1,4);
  SWAP(6,9);
  SWAP(0,3);
  SWAP(5,8);
  SWAP(0,2);
  SWAP(3,6);
  SWAP(7,9);
  SWAP(0,1);
  SWAP(2,4);
  SWAP(5,7);
  SWAP(8,9);
  SWAP(1,2);
  SWAP(4,6);
  SWAP(7,8);
  SWAP(3,5);
  SWAP(2,5);
  SWAP(6,8);
  SWAP(1,3);
  SWAP(4,7);
  SWAP(2,3);
  SWAP(6,7);
  SWAP(3,4);
  SWAP(5,6);
  SWAP(4,5);
}
#endif


#if OBJECT_MAX_OBJECTS > 10
static void sort11(object_t **d){
  SWAP(0,1);
  SWAP(2,3);
  SWAP(4,5);
  SWAP(6,7);
  SWAP(8,9);
  SWAP(1,3);
  SWAP(5,7);
  SWAP(0,2);
  SWAP(4,6);
  SWAP(8,10);
  SWAP(1,2);
  SWAP(5,6);
  SWAP(9,10);
  SWAP(0,4);
  SWAP(3,7);
  SWAP(1,5);
  SWAP(6,10);
  SWAP(4,8);
  SWAP(5,9);
  SWAP(2,6);
  SWAP(0,4);
  SWAP(3,8);
  SWAP(1,5);
  SWAP(6,10);
  SWAP(2,3);
  SWAP(8,9);
  SWAP(1,4);
  SWAP(7,10);
  SWAP(3,5);
  SWAP(6,8);
  SWAP(2,4);
  SWAP(7,9);
  SWAP(5,6);
  SWAP(3,4);
  SWAP(7,8);
}
#endif


#if OBJECT_MAX_OBJECTS > 11
static void sort12(object_t **d){
SWAP(0, 1);

SWAP(2, 3);

SWAP(4, 5);

SWAP(6, 7);

SWAP(8, 9);

SWAP(10, 11);

SWAP(1, 3);

SWAP(5, 7);

SWAP(9, 11);

SWAP(0, 2);

SWAP(4, 6);

SWAP(8, 10);

SWAP(1, 2);

SWAP(5, 6);

SWAP(9, 10);

SWAP(1, 5);

SWAP(6, 10);

SWAP(5, 9);

SWAP(2, 6);

SWAP(1, 5);

SWAP(6, 10);

SWAP(0, 4);

SWAP(7, 11);

SWAP(3, 7);

SWAP(4, 8);

SWAP(0, 4);

SWAP(7, 11);

SWAP(1, 4);

SWAP(7, 10);

SWAP(3, 8);

SWAP(2, 3);

SWAP(8, 9);

SWAP(2, 4);

SWAP(7, 9);

SWAP(3, 5);

SWAP(6, 8);

SWAP(3, 4);

SWAP(5, 6);

SWAP(7, 8);
}
#endif

#if OBJECT_MAX_OBJECTS > 12
static void sort13(object_t **d){
SWAP(1, 7);

SWAP(9, 11);

SWAP(3, 4);

SWAP(5, 8);

SWAP(0, 12);

SWAP(2, 6);

SWAP(0, 1);

SWAP(2, 3);

SWAP(4, 6);

SWAP(8, 11);

SWAP(7, 12);

SWAP(5, 9);

SWAP(0, 2);

SWAP(3, 7);

SWAP(10, 11);

SWAP(1, 4);

SWAP(6, 12);

SWAP(7, 8);

SWAP(11, 12);

SWAP(4, 9);

SWAP(6, 10);

SWAP(3, 4);

SWAP(5, 6);

SWAP(8, 9);

SWAP(10, 11);

SWAP(1, 7);

SWAP(2, 6);

SWAP(9, 11);

SWAP(1, 3);

SWAP(4, 7);

SWAP(8, 10);

SWAP(0, 5);

SWAP(2, 5);

SWAP(6, 8);

SWAP(9, 10);

SWAP(1, 2);

SWAP(3, 5);

SWAP(7, 8);

SWAP(4, 6);

SWAP(2, 3);

SWAP(4, 5);

SWAP(6, 7);

SWAP(8, 9);

SWAP(3, 4);

SWAP(5, 6);

}
#endif

#if OBJECT_MAX_OBJECTS > 13
static void sort14(object_t **d){
SWAP(0, 1);

SWAP(2, 3);

SWAP(4, 5);

SWAP(6, 7);

SWAP(8, 9);

SWAP(10, 11);

SWAP(12, 13);

SWAP(0, 2);

SWAP(4, 6);

SWAP(8, 10);

SWAP(1, 3);

SWAP(5, 7);

SWAP(9, 11);

SWAP(0, 4);

SWAP(8, 12);

SWAP(1, 5);

SWAP(9, 13);

SWAP(2, 6);

SWAP(3, 7);

SWAP(0, 8);

SWAP(1, 9);

SWAP(2, 10);

SWAP(3, 11);

SWAP(4, 12);

SWAP(5, 13);

SWAP(5, 10);

SWAP(6, 9);

SWAP(3, 12);

SWAP(7, 11);

SWAP(1, 2);

SWAP(4, 8);

SWAP(1, 4);

SWAP(7, 13);

SWAP(2, 8);

SWAP(2, 4);

SWAP(5, 6);

SWAP(9, 10);

SWAP(11, 13);

SWAP(3, 8);

SWAP(7, 12);

SWAP(6, 8);

SWAP(10, 12);

SWAP(3, 5);

SWAP(7, 9);

SWAP(3, 4);

SWAP(5, 6);

SWAP(7, 8);

SWAP(9, 10);

SWAP(11, 12);

SWAP(6, 7);

SWAP(8, 9);

}
#endif

#if OBJECT_MAX_OBJECTS > 14
static void sort15(object_t **d){
SWAP(0, 1);

SWAP(2, 3);

SWAP(4, 5);

SWAP(6, 7);

SWAP(8, 9);

SWAP(10, 11);

SWAP(12, 13);

SWAP(0, 2);

SWAP(4, 6);

SWAP(8, 10);

SWAP(12, 14);

SWAP(1, 3);

SWAP(5, 7);

SWAP(9, 11);

SWAP(0, 4);

SWAP(8, 12);

SWAP(1, 5);

SWAP(9, 13);

SWAP(2, 6);

SWAP(10, 14);

SWAP(3, 7);

SWAP(0, 8);

SWAP(1, 9);

SWAP(2, 10);

SWAP(3, 11);

SWAP(4, 12);

SWAP(5, 13);

SWAP(6, 14);

SWAP(5, 10);

SWAP(6, 9);

SWAP(3, 12);

SWAP(13, 14);

SWAP(7, 11);

SWAP(1, 2);

SWAP(4, 8);

SWAP(1, 4);

SWAP(7, 13);

SWAP(2, 8);

SWAP(11, 14);

SWAP(2, 4);

SWAP(5, 6);

SWAP(9, 10);

SWAP(11, 13);

SWAP(3, 8);

SWAP(7, 12);

SWAP(6, 8);

SWAP(10, 12);

SWAP(3, 5);

SWAP(7, 9);

SWAP(3, 4);

SWAP(5, 6);

SWAP(7, 8);

SWAP(9, 10);

SWAP(11, 12);

SWAP(6, 7);

SWAP(8, 9);

}
#endif
#if OBJECT_MAX_OBJECTS > 15
static void sort16(object_t **d){
SWAP(0, 1);

SWAP(2, 3);

SWAP(4, 5);

SWAP(6, 7);

SWAP(8, 9);

SWAP(10, 11);

SWAP(12, 13);

SWAP(14, 15);

SWAP(0, 2);

SWAP(4, 6);

SWAP(8, 10);

SWAP(12, 14);

SWAP(1, 3);

SWAP(5, 7);

SWAP(9, 11);

SWAP(13, 15);

SWAP(0, 4);

SWAP(8, 12);

SWAP(1, 5);

SWAP(9, 13);

SWAP(2, 6);

SWAP(10, 14);

SWAP(3, 7);

SWAP(11, 15);

SWAP(0, 8);

SWAP(1, 9);

SWAP(2, 10);

SWAP(3, 11);

SWAP(4, 12);

SWAP(5, 13);

SWAP(6, 14);

SWAP(7, 15);

SWAP(5, 10);

SWAP(6, 9);

SWAP(3, 12);

SWAP(13, 14);

SWAP(7, 11);

SWAP(1, 2);

SWAP(4, 8);

SWAP(1, 4);

SWAP(7, 13);

SWAP(2, 8);

SWAP(11, 14);

SWAP(2, 4);

SWAP(5, 6);

SWAP(9, 10);

SWAP(11, 13);

SWAP(3, 8);

SWAP(7, 12);

SWAP(6, 8);

SWAP(10, 12);

SWAP(3, 5);

SWAP(7, 9);

SWAP(3, 4);

SWAP(5, 6);

SWAP(7, 8);

SWAP(9, 10);

SWAP(11, 12);

SWAP(6, 7);

SWAP(8, 9);

}
#endif

#if OBJECT_MAX_OBJECTS > 16
static void sort17(object_t **d){
  SWAP(0, 1);

SWAP(2, 3);

SWAP(0, 2);

SWAP(1, 3);

SWAP(1, 2);

SWAP(4, 5);

SWAP(6, 7);

SWAP(4, 6);

SWAP(5, 7);

SWAP(5, 6);

SWAP(0, 4);

SWAP(1, 5);

SWAP(1, 4);

SWAP(2, 6);

SWAP(3, 7);

SWAP(3, 6);

SWAP(2, 4);

SWAP(3, 5);

SWAP(3, 4);

SWAP(8, 9);

SWAP(10, 11);

SWAP(8, 10);

SWAP(9, 11);

SWAP(9, 10);

SWAP(12, 13);

SWAP(15, 16);

SWAP(14, 16);

SWAP(14, 15);

SWAP(12, 15);

SWAP(12, 14);

SWAP(13, 16);

SWAP(13, 15);

SWAP(13, 14);

SWAP(8, 13);

SWAP(8, 12);

SWAP(9, 14);

SWAP(9, 13);

SWAP(9, 12);

SWAP(10, 15);

SWAP(11, 16);

SWAP(11, 15);

SWAP(10, 13);

SWAP(10, 12);

SWAP(11, 14);

SWAP(11, 13);

SWAP(11, 12);

SWAP(0, 9);

SWAP(0, 8);

SWAP(1, 10);

SWAP(1, 9);

SWAP(1, 8);

SWAP(2, 11);

SWAP(3, 12);

SWAP(3, 11);

SWAP(2, 9);

SWAP(2, 8);

SWAP(3, 10);

SWAP(3, 9);

SWAP(3, 8);

SWAP(4, 13);

SWAP(5, 14);

SWAP(5, 13);

SWAP(6, 15);

SWAP(7, 16);

SWAP(7, 15);

SWAP(6, 13);

SWAP(7, 14);

SWAP(7, 13);

SWAP(4, 9);

SWAP(4, 8);

SWAP(5, 10);

SWAP(5, 9);

SWAP(5, 8);

SWAP(6, 11);

SWAP(7, 12);

SWAP(7, 11);

SWAP(6, 9);

SWAP(6, 8);

SWAP(7, 10);

SWAP(7, 9);

 SWAP(7, 8);

}
#endif

#if OBJECT_MAX_OBJECTS > 17
static void sort18(object_t **d){
SWAP(0, 1);

SWAP(2, 3);

SWAP(0, 2);

SWAP(1, 3);

SWAP(1, 2);

SWAP(4, 5);

SWAP(7, 8);

SWAP(6, 8);

SWAP(6, 7);

SWAP(4, 7);

SWAP(4, 6);

SWAP(5, 8);

SWAP(5, 7);

SWAP(5, 6);

SWAP(0, 5);

SWAP(0, 4);

SWAP(1, 6);

SWAP(1, 5);

SWAP(1, 4);

SWAP(2, 7);

SWAP(3, 8);

SWAP(3, 7);

SWAP(2, 5);

SWAP(2, 4);

SWAP(3, 6);

SWAP(3, 5);

SWAP(3, 4);

SWAP(9, 10);

SWAP(11, 12);

SWAP(9, 11);

SWAP(10, 12);

SWAP(10, 11);

SWAP(13, 14);

SWAP(16, 17);

SWAP(15, 17);

SWAP(15, 16);

SWAP(13, 16);

SWAP(13, 15);

SWAP(14, 17);

SWAP(14, 16);

SWAP(14, 15);

SWAP(9, 14);

SWAP(9, 13);

SWAP(10, 15);

SWAP(10, 14);

SWAP(10, 13);

SWAP(11, 16);

SWAP(12, 17);

SWAP(12, 16);

SWAP(11, 14);

SWAP(11, 13);

SWAP(12, 15);

SWAP(12, 14);

SWAP(12, 13);

SWAP(0, 9);

SWAP(1, 10);

SWAP(1, 9);

SWAP(2, 11);

SWAP(3, 12);

SWAP(3, 11);

SWAP(2, 9);

SWAP(3, 10);

SWAP(3, 9);

SWAP(4, 13);

SWAP(5, 14);

SWAP(5, 13);

SWAP(6, 15);

SWAP(7, 16);

SWAP(8, 17);

SWAP(8, 16);

SWAP(7, 15);

SWAP(8, 15);

SWAP(6, 13);

SWAP(7, 14);

SWAP(8, 14);

SWAP(7, 13);

SWAP(8, 13);

SWAP(4, 9);

SWAP(5, 10);

SWAP(5, 9);

SWAP(6, 11);

SWAP(7, 12);

SWAP(8, 12);

SWAP(7, 11);

SWAP(8, 11);

SWAP(6, 9);

SWAP(7, 10);

SWAP(8, 10);

SWAP(7, 9);

SWAP(8, 9);
}
#endif


#if OBJECT_MAX_OBJECTS > 18
static void sort19(object_t **d){
SWAP(0, 1);
SWAP(2, 3);
SWAP(0, 2);
SWAP(1, 3);
SWAP(1, 2);
SWAP(4, 5);
SWAP(7, 8);
SWAP(6, 8);
SWAP(6, 7);
SWAP(4, 7);
SWAP(4, 6);
SWAP(5, 8);
SWAP(5, 7);
SWAP(5, 6);
SWAP(0, 5);
SWAP(0, 4);
SWAP(1, 6);
SWAP(1, 5);
SWAP(1, 4);
SWAP(2, 7);
SWAP(3, 8);
SWAP(3, 7);
SWAP(2, 5);
SWAP(2, 4);
SWAP(3, 6);
SWAP(3, 5);
SWAP(3, 4);
SWAP(9, 10);
SWAP(12, 13);
SWAP(11, 13);
SWAP(11, 12);
SWAP(9, 12);
SWAP(9, 11);
SWAP(10, 13);
SWAP(10, 12);
SWAP(10, 11);
SWAP(14, 15);
SWAP(17, 18);
SWAP(16, 18);
SWAP(16, 17);
SWAP(14, 17);
SWAP(14, 16);
SWAP(15, 18);
SWAP(15, 17);
SWAP(15, 16);
SWAP(9, 14);
SWAP(10, 15);
SWAP(10, 14);
SWAP(11, 16);
SWAP(12, 17);
SWAP(13, 18);
SWAP(13, 17);
SWAP(12, 16);
SWAP(13, 16);
SWAP(11, 14);
SWAP(12, 15);
SWAP(13, 15);
SWAP(12, 14);
SWAP(13, 14);
SWAP(0, 10);
SWAP(0, 9);
SWAP(1, 11);
SWAP(1, 10);
SWAP(1, 9);
SWAP(2, 12);
SWAP(3, 13);
SWAP(3, 12);
SWAP(2, 10);
SWAP(2, 9);
SWAP(3, 11);
SWAP(3, 10);
SWAP(3, 9);
SWAP(4, 14);
SWAP(5, 15);
SWAP(5, 14);
SWAP(6, 16);
SWAP(7, 17);
SWAP(8, 18);
SWAP(8, 17);
SWAP(7, 16);
SWAP(8, 16);
SWAP(6, 14);
SWAP(7, 15);
SWAP(8, 15);
SWAP(7, 14);
SWAP(8, 14);
SWAP(4, 9);
SWAP(5, 10);
SWAP(5, 9);
SWAP(6, 11);
SWAP(7, 12);
SWAP(8, 13);
SWAP(8, 12);
SWAP(7, 11);
SWAP(8, 11);
SWAP(6, 9);
SWAP(7, 10);
SWAP(8, 10);
SWAP(7, 9);
SWAP(8, 9);
}
#endif

#if OBJECT_MAX_OBJECTS > 19
static void sort20(object_t **d){
SWAP(0, 1);
SWAP(3, 4);
SWAP(2, 4);
SWAP(2, 3);
SWAP(0, 3);
SWAP(0, 2);
SWAP(1, 4);
SWAP(1, 3);
SWAP(1, 2);
SWAP(5, 6);
SWAP(8, 9);
SWAP(7, 9);
SWAP(7, 8);
SWAP(5, 8);
SWAP(5, 7);
SWAP(6, 9);
SWAP(6, 8);
SWAP(6, 7);
SWAP(0, 5);
SWAP(1, 6);
SWAP(1, 5);
SWAP(2, 7);
SWAP(3, 8);
SWAP(4, 9);
SWAP(4, 8);
SWAP(3, 7);
SWAP(4, 7);
SWAP(2, 5);
SWAP(3, 6);
SWAP(4, 6);
SWAP(3, 5);
SWAP(4, 5);
SWAP(10, 11);
SWAP(13, 14);
SWAP(12, 14);
SWAP(12, 13);
SWAP(10, 13);
SWAP(10, 12);
SWAP(11, 14);
SWAP(11, 13);
SWAP(11, 12);
SWAP(15, 16);
SWAP(18, 19);
SWAP(17, 19);
SWAP(17, 18);
SWAP(15, 18);
SWAP(15, 17);
SWAP(16, 19);
SWAP(16, 18);
SWAP(16, 17);
SWAP(10, 15);
SWAP(11, 16);
SWAP(11, 15);
SWAP(12, 17);
SWAP(13, 18);
SWAP(14, 19);
SWAP(14, 18);
SWAP(13, 17);
SWAP(14, 17);
SWAP(12, 15);
SWAP(13, 16);
SWAP(14, 16);
SWAP(13, 15);
SWAP(14, 15);
SWAP(0, 10);
SWAP(1, 11);
SWAP(1, 10);
SWAP(2, 12);
SWAP(3, 13);
SWAP(4, 14);
SWAP(4, 13);
SWAP(3, 12);
SWAP(4, 12);
SWAP(2, 10);
SWAP(3, 11);
SWAP(4, 11);
SWAP(3, 10);
SWAP(4, 10);
SWAP(5, 15);
SWAP(6, 16);
SWAP(6, 15);
SWAP(7, 17);
SWAP(8, 18);
SWAP(9, 19);
SWAP(9, 18);
SWAP(8, 17);
SWAP(9, 17);
SWAP(7, 15);
SWAP(8, 16);
SWAP(9, 16);
SWAP(8, 15);
SWAP(9, 15);
SWAP(5, 10);
SWAP(6, 11);
SWAP(6, 10);
SWAP(7, 12);
SWAP(8, 13);
SWAP(9, 14);
SWAP(9, 13);
SWAP(8, 12);
SWAP(9, 12);
SWAP(7, 10);
SWAP(8, 11);
SWAP(9, 11);
SWAP(8, 10);
SWAP(9, 10);
}
#endif

#if OBJECT_MAX_OBJECTS > 20
static void sort21(object_t **d){
SWAP(0, 1);
SWAP(3, 4);
SWAP(2, 4);
SWAP(2, 3);
SWAP(0, 3);
SWAP(0, 2);
SWAP(1, 4);
SWAP(1, 3);
SWAP(1, 2);
SWAP(5, 6);
SWAP(8, 9);
SWAP(7, 9);
SWAP(7, 8);
SWAP(5, 8);
SWAP(5, 7);
SWAP(6, 9);
SWAP(6, 8);
SWAP(6, 7);
SWAP(0, 5);
SWAP(1, 6);
SWAP(1, 5);
SWAP(2, 7);
SWAP(3, 8);
SWAP(4, 9);
SWAP(4, 8);
SWAP(3, 7);
SWAP(4, 7);
SWAP(2, 5);
SWAP(3, 6);
SWAP(4, 6);
SWAP(3, 5);
SWAP(4, 5);
SWAP(10, 11);
SWAP(13, 14);
SWAP(12, 14);
SWAP(12, 13);
SWAP(10, 13);
SWAP(10, 12);
SWAP(11, 14);
SWAP(11, 13);
SWAP(11, 12);
SWAP(16, 17);
SWAP(15, 17);
SWAP(15, 16);
SWAP(19, 20);
SWAP(18, 20);
SWAP(18, 19);
SWAP(15, 18);
SWAP(16, 19);
SWAP(17, 20);
SWAP(17, 19);
SWAP(16, 18);
SWAP(17, 18);
SWAP(10, 16);
SWAP(10, 15);
SWAP(11, 17);
SWAP(11, 16);
SWAP(11, 15);
SWAP(12, 18);
SWAP(13, 19);
SWAP(14, 20);
SWAP(14, 19);
SWAP(13, 18);
SWAP(14, 18);
SWAP(12, 15);
SWAP(13, 16);
SWAP(14, 17);
SWAP(14, 16);
SWAP(13, 15);
SWAP(14, 15);
SWAP(0, 11);
SWAP(0, 10);
SWAP(1, 12);
SWAP(1, 11);
SWAP(1, 10);
SWAP(2, 13);
SWAP(3, 14);
SWAP(4, 15);
SWAP(4, 14);
SWAP(3, 13);
SWAP(4, 13);
SWAP(2, 10);
SWAP(3, 11);
SWAP(4, 12);
SWAP(4, 11);
SWAP(3, 10);
SWAP(4, 10);
SWAP(5, 16);
SWAP(6, 17);
SWAP(6, 16);
SWAP(7, 18);
SWAP(8, 19);
SWAP(9, 20);
SWAP(9, 19);
SWAP(8, 18);
SWAP(9, 18);
SWAP(7, 16);
SWAP(8, 17);
SWAP(9, 17);
SWAP(8, 16);
SWAP(9, 16);
SWAP(5, 11);
SWAP(5, 10);
SWAP(6, 12);
SWAP(6, 11);
SWAP(6, 10);
SWAP(7, 13);
SWAP(8, 14);
SWAP(9, 15);
SWAP(9, 14);
SWAP(8, 13);
SWAP(9, 13);
SWAP(7, 10);
SWAP(8, 11);
SWAP(9, 12);
SWAP(9, 11);
SWAP(8, 10);
SWAP(9, 10);
}
#endif

#if OBJECT_MAX_OBJECTS > 21
static void sort22(object_t **d){
SWAP(0, 1);
SWAP(3, 4);
SWAP(2, 4);
SWAP(2, 3);
SWAP(0, 3);
SWAP(0, 2);
SWAP(1, 4);
SWAP(1, 3);
SWAP(1, 2);
SWAP(6, 7);
SWAP(5, 7);
SWAP(5, 6);
SWAP(9, 10);
SWAP(8, 10);
SWAP(8, 9);
SWAP(5, 8);
SWAP(6, 9);
SWAP(7, 10);
SWAP(7, 9);
SWAP(6, 8);
SWAP(7, 8);
SWAP(0, 6);
SWAP(0, 5);
SWAP(1, 7);
SWAP(1, 6);
SWAP(1, 5);
SWAP(2, 8);
SWAP(3, 9);
SWAP(4, 10);
SWAP(4, 9);
SWAP(3, 8);
SWAP(4, 8);
SWAP(2, 5);
SWAP(3, 6);
SWAP(4, 7);
SWAP(4, 6);
SWAP(3, 5);
SWAP(4, 5);
SWAP(11, 12);
SWAP(14, 15);
SWAP(13, 15);
SWAP(13, 14);
SWAP(11, 14);
SWAP(11, 13);
SWAP(12, 15);
SWAP(12, 14);
SWAP(12, 13);
SWAP(17, 18);
SWAP(16, 18);
SWAP(16, 17);
SWAP(20, 21);
SWAP(19, 21);
SWAP(19, 20);
SWAP(16, 19);
SWAP(17, 20);
SWAP(18, 21);
SWAP(18, 20);
SWAP(17, 19);
SWAP(18, 19);
SWAP(11, 17);
SWAP(11, 16);
SWAP(12, 18);
SWAP(12, 17);
SWAP(12, 16);
SWAP(13, 19);
SWAP(14, 20);
SWAP(15, 21);
SWAP(15, 20);
SWAP(14, 19);
SWAP(15, 19);
SWAP(13, 16);
SWAP(14, 17);
SWAP(15, 18);
SWAP(15, 17);
SWAP(14, 16);
SWAP(15, 16);
SWAP(0, 11);
SWAP(1, 12);
SWAP(1, 11);
SWAP(2, 13);
SWAP(3, 14);
SWAP(4, 15);
SWAP(4, 14);
SWAP(3, 13);
SWAP(4, 13);
SWAP(2, 11);
SWAP(3, 12);
SWAP(4, 12);
SWAP(3, 11);
SWAP(4, 11);
SWAP(5, 16);
SWAP(6, 17);
SWAP(7, 18);
SWAP(7, 17);
SWAP(6, 16);
SWAP(7, 16);
SWAP(8, 19);
SWAP(9, 20);
SWAP(10, 21);
SWAP(10, 20);
SWAP(9, 19);
SWAP(10, 19);
SWAP(8, 16);
SWAP(9, 17);
SWAP(10, 18);
SWAP(10, 17);
SWAP(9, 16);
SWAP(10, 16);
SWAP(5, 11);
SWAP(6, 12);
SWAP(7, 13);
SWAP(7, 12);
SWAP(6, 11);
SWAP(7, 11);
SWAP(8, 14);
SWAP(9, 15);
SWAP(10, 15);
SWAP(9, 14);
SWAP(10, 14);
SWAP(8, 11);
SWAP(9, 12);
SWAP(10, 13);
SWAP(10, 12);
SWAP(9, 11);
SWAP(10, 11);
}
#endif

#if OBJECT_MAX_OBJECTS > 22
static void sort23(object_t **d){
SWAP(0, 1);
SWAP(3, 4);
SWAP(2, 4);
SWAP(2, 3);
SWAP(0, 3);
SWAP(0, 2);
SWAP(1, 4);
SWAP(1, 3);
SWAP(1, 2);
SWAP(6, 7);
SWAP(5, 7);
SWAP(5, 6);
SWAP(9, 10);
SWAP(8, 10);
SWAP(8, 9);
SWAP(5, 8);
SWAP(6, 9);
SWAP(7, 10);
SWAP(7, 9);
SWAP(6, 8);
SWAP(7, 8);
SWAP(0, 6);
SWAP(0, 5);
SWAP(1, 7);
SWAP(1, 6);
SWAP(1, 5);
SWAP(2, 8);
SWAP(3, 9);
SWAP(4, 10);
SWAP(4, 9);
SWAP(3, 8);
SWAP(4, 8);
SWAP(2, 5);
SWAP(3, 6);
SWAP(4, 7);
SWAP(4, 6);
SWAP(3, 5);
SWAP(4, 5);
SWAP(12, 13);
SWAP(11, 13);
SWAP(11, 12);
SWAP(15, 16);
SWAP(14, 16);
SWAP(14, 15);
SWAP(11, 14);
SWAP(12, 15);
SWAP(13, 16);
SWAP(13, 15);
SWAP(12, 14);
SWAP(13, 14);
SWAP(18, 19);
SWAP(17, 19);
SWAP(17, 18);
SWAP(21, 22);
SWAP(20, 22);
SWAP(20, 21);
SWAP(17, 20);
SWAP(18, 21);
SWAP(19, 22);
SWAP(19, 21);
SWAP(18, 20);
SWAP(19, 20);
SWAP(11, 17);
SWAP(12, 18);
SWAP(13, 19);
SWAP(13, 18);
SWAP(12, 17);
SWAP(13, 17);
SWAP(14, 20);
SWAP(15, 21);
SWAP(16, 22);
SWAP(16, 21);
SWAP(15, 20);
SWAP(16, 20);
SWAP(14, 17);
SWAP(15, 18);
SWAP(16, 19);
SWAP(16, 18);
SWAP(15, 17);
SWAP(16, 17);
SWAP(0, 12);
SWAP(0, 11);
SWAP(1, 13);
SWAP(1, 12);
SWAP(1, 11);
SWAP(2, 14);
SWAP(3, 15);
SWAP(4, 16);
SWAP(4, 15);
SWAP(3, 14);
SWAP(4, 14);
SWAP(2, 11);
SWAP(3, 12);
SWAP(4, 13);
SWAP(4, 12);
SWAP(3, 11);
SWAP(4, 11);
SWAP(5, 17);
SWAP(6, 18);
SWAP(7, 19);
SWAP(7, 18);
SWAP(6, 17);
SWAP(7, 17);
SWAP(8, 20);
SWAP(9, 21);
SWAP(10, 22);
SWAP(10, 21);
SWAP(9, 20);
SWAP(10, 20);
SWAP(8, 17);
SWAP(9, 18);
SWAP(10, 19);
SWAP(10, 18);
SWAP(9, 17);
SWAP(10, 17);
SWAP(5, 11);
SWAP(6, 12);
SWAP(7, 13);
SWAP(7, 12);
SWAP(6, 11);
SWAP(7, 11);
SWAP(8, 14);
SWAP(9, 15);
SWAP(10, 16);
SWAP(10, 15);
SWAP(9, 14);
SWAP(10, 14);
SWAP(8, 11);
SWAP(9, 12);
SWAP(10, 13);
SWAP(10, 12);
SWAP(9, 11);
SWAP(10, 11);
}
#endif

#if OBJECT_MAX_OBJECTS > 23
static void sort24(object_t **d){
SWAP(1, 2);
SWAP(0, 2);
SWAP(0, 1);
SWAP(4, 5);
SWAP(3, 5);
SWAP(3, 4);
SWAP(0, 3);
SWAP(1, 4);
SWAP(2, 5);
SWAP(2, 4);
SWAP(1, 3);
SWAP(2, 3);
SWAP(7, 8);
SWAP(6, 8);
SWAP(6, 7);
SWAP(10, 11);
SWAP(9, 11);
SWAP(9, 10);
SWAP(6, 9);
SWAP(7, 10);
SWAP(8, 11);
SWAP(8, 10);
SWAP(7, 9);
SWAP(8, 9);
SWAP(0, 6);
SWAP(1, 7);
SWAP(2, 8);
SWAP(2, 7);
SWAP(1, 6);
SWAP(2, 6);
SWAP(3, 9);
SWAP(4, 10);
SWAP(5, 11);
SWAP(5, 10);
SWAP(4, 9);
SWAP(5, 9);
SWAP(3, 6);
SWAP(4, 7);
SWAP(5, 8);
SWAP(5, 7);
SWAP(4, 6);
SWAP(5, 6);
SWAP(13, 14);
SWAP(12, 14);
SWAP(12, 13);
SWAP(16, 17);
SWAP(15, 17);
SWAP(15, 16);
SWAP(12, 15);
SWAP(13, 16);
SWAP(14, 17);
SWAP(14, 16);
SWAP(13, 15);
SWAP(14, 15);
SWAP(19, 20);
SWAP(18, 20);
SWAP(18, 19);
SWAP(22, 23);
SWAP(21, 23);
SWAP(21, 22);
SWAP(18, 21);
SWAP(19, 22);
SWAP(20, 23);
SWAP(20, 22);
SWAP(19, 21);
SWAP(20, 21);
SWAP(12, 18);
SWAP(13, 19);
SWAP(14, 20);
SWAP(14, 19);
SWAP(13, 18);
SWAP(14, 18);
SWAP(15, 21);
SWAP(16, 22);
SWAP(17, 23);
SWAP(17, 22);
SWAP(16, 21);
SWAP(17, 21);
SWAP(15, 18);
SWAP(16, 19);
SWAP(17, 20);
SWAP(17, 19);
SWAP(16, 18);
SWAP(17, 18);
SWAP(0, 12);
SWAP(1, 13);
SWAP(2, 14);
SWAP(2, 13);
SWAP(1, 12);
SWAP(2, 12);
SWAP(3, 15);
SWAP(4, 16);
SWAP(5, 17);
SWAP(5, 16);
SWAP(4, 15);
SWAP(5, 15);
SWAP(3, 12);
SWAP(4, 13);
SWAP(5, 14);
SWAP(5, 13);
SWAP(4, 12);
SWAP(5, 12);
SWAP(6, 18);
SWAP(7, 19);
SWAP(8, 20);
SWAP(8, 19);
SWAP(7, 18);
SWAP(8, 18);
SWAP(9, 21);
SWAP(10, 22);
SWAP(11, 23);
SWAP(11, 22);
SWAP(10, 21);
SWAP(11, 21);
SWAP(9, 18);
SWAP(10, 19);
SWAP(11, 20);
SWAP(11, 19);
SWAP(10, 18);
SWAP(11, 18);
SWAP(6, 12);
SWAP(7, 13);
SWAP(8, 14);
SWAP(8, 13);
SWAP(7, 12);
SWAP(8, 12);
SWAP(9, 15);
SWAP(10, 16);
SWAP(11, 17);
SWAP(11, 16);
SWAP(10, 15);
SWAP(11, 15);
SWAP(9, 12);
SWAP(10, 13);
SWAP(11, 14);
SWAP(11, 13);
SWAP(10, 12);
SWAP(11, 12);
}
#endif

static void(*sort_zs[OBJECT_MAX_OBJECTS+1])(object_t**) = {
  sort0,
  sort0,
  sort2,
  sort3,
  sort4,
  sort5,
  sort6,
#if OBJECT_MAX_OBJECTS > 6
  sort7,
#endif
#if OBJECT_MAX_OBJECTS > 7
  sort8,
#endif
#if OBJECT_MAX_OBJECTS > 8
  sort9,
#endif
#if OBJECT_MAX_OBJECTS > 9
  sort10,
#endif
#if OBJECT_MAX_OBJECTS > 10
  sort11,
#endif
#if OBJECT_MAX_OBJECTS > 11
  sort12,
#endif
#if OBJECT_MAX_OBJECTS > 12
  sort13,
#endif
#if OBJECT_MAX_OBJECTS > 13
  sort14,
#endif
#if OBJECT_MAX_OBJECTS > 14
  sort15,
#endif
#if OBJECT_MAX_OBJECTS > 15
  sort16,
#endif
#if OBJECT_MAX_OBJECTS > 16
  sort17,
#endif
#if OBJECT_MAX_OBJECTS > 17
  sort18,
#endif
#if OBJECT_MAX_OBJECTS > 18
  sort19,
#endif
#if OBJECT_MAX_OBJECTS > 19
  sort20,
#endif
#if OBJECT_MAX_OBJECTS > 20
  sort21,
#endif
#if OBJECT_MAX_OBJECTS > 21
  sort22,
#endif
#if OBJECT_MAX_OBJECTS > 22
  sort23,
#endif
#if OBJECT_MAX_OBJECTS > 23
  sort24,
#endif
};


void
sort_z(int16_t count, object_t **d)
{
#ifdef DEBUG
  if (count > OBJECT_MAX_OBJECTS) {
    PANIC("sort_z: out of bounds");
  }
#endif
  sort_zs[count](d);
}
