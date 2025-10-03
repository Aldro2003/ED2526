#ifndef LINKED_PRACTICES_H
#define LINKED_PRACTICES_H
#include <stddef.h>
#include <stdbool.h>

/* ========== 1) SList ordenada (simplemente enlazada, enteros) ==========
 */
struct SNode
{
  int key;
  struct SNode *next;
};
struct SList
{
  struct SNode *head;
  size_t size;
};
void SList_init(struct SList *p_list);
void SList_clear(struct SList *p_list);
size_t SList_size(const struct SList *p_list);
bool SList_empty(const struct SList *p_list);
bool SList_is_sorted(const struct SList *p_list);
struct SNode *SList_find(const struct SList *p_list, int key);
bool SList_insert_in_order(struct SList *p_list, int key);
bool SList_remove_key(struct SList *p_list, int key);
void SList_unique(struct SList *p_list);
void SList_reverse(struct SList *p_list);
void SList_merge_sorted(struct SList *p_dest, struct SList *p_src);

#endif