#ifndef LINKED_PRACTICES_H
#define LINKED_PRACTICES_H
#include <stddef.h>
#include <stdbool.h>

/* ========== 4) DCList doblemente circular con cursor (playlist)
========== */
struct DCNode
{
  char data[64];
  struct DCNode *prev;
  struct DCNode *next;
};
struct DCList
{
  struct DCNode *current; // NULL si vacía; si no, lista circular
  size_t size;
};
void DCList_init(struct DCList *p_list);
void DCList_clear(struct DCList *p_list);
size_t DCList_size(const struct DCList *p_list);
bool DCList_empty(const struct DCList *p_list);
const char *DCList_current(const struct DCList *p_list);
void DCList_next(struct DCList *p_list);
void DCList_prev(struct DCList *p_list);
void DCList_next_k(struct DCList *p_list, size_t k);
void DCList_prev_k(struct DCList *p_list, size_t k);
bool DCList_insert_after_current(struct DCList *p_list, const char
                                                            text[]);
bool DCList_insert_before_current(struct DCList *p_list, const char
                                                             text[]);
bool DCList_insert_in_order(struct DCList *p_list, const char
                                                       text[]);
bool DCList_erase_current(struct DCList *p_list);

#endif