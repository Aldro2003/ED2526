#ifndef LINKED_PRACTICES_H
#define LINKED_PRACTICES_H
#include <stddef.h>
#include <stdbool.h>
/* ========== 3) DList doble (deque genérico) ========== */
struct DNode
{
  int key;
  char value[64];
  struct DNode *prev;
  struct DNode *next;
};
struct DList
{
  struct DNode *head;
  struct DNode *tail;
  size_t size;
};
void DList_init(struct DList *p_list);
void DList_clear(struct DList *p_list);
size_t DList_size(const struct DList *p_list);
bool DList_empty(const struct DList *p_list);
struct DNode *DList_find_first(const struct DList *p_list, int key);
bool DList_push_front(struct DList *p_list, int key, const char value[]);
bool DList_push_back(struct DList *p_list, int key, const char value[]);
bool DList_insert_before(struct DList *p_list, struct DNode *pos, int key, const char value[]);
bool DList_insert_after(struct DList *p_list, struct DNode *pos, int key, const char value[]);
bool DList_erase_node(struct DList *p_list, struct DNode *node);
size_t DList_remove_key(struct DList *p_list, int key);
void DList_reverse(struct DList *p_list);
void DList_split_half(struct DList *p_src, struct DList *p_front,
                      struct DList *p_back);
void DList_splice_range(struct DList *p_dest, struct DNode *dest_pos_exclusive,
                        struct DList *p_src, struct DNode *first,
                        struct DNode *last_inclusive);

#endif