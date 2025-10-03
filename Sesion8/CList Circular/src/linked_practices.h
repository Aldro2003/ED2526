#ifndef LINKED_PRACTICES_H
#define LINKED_PRACTICES_H
#include <stddef.h>
#include <stdbool.h>
/* ========== 2) CList circular (simplemente enlazada, cola RR) ==========
 */
struct CNode
{
  int value;
  struct CNode *next;
};
struct CList
{
  struct CNode *last; // NULL si vacía; si no, last->next es el primero
  size_t size;
};
void CList_init(struct CList *p_clist);
void CList_clear(struct CList *p_clist);
size_t CList_size(const struct CList *p_clist);
bool CList_empty(const struct CList *p_clist);
struct CNode *CList_first_node(const struct CList *p_clist);
int CList_first_value(const struct CList *p_clist, bool *p_ok);
bool CList_enqueue_back(struct CList *p_clist, int value);
bool CList_dequeue_front(struct CList *p_clist, int *p_out_value);
void CList_rotate(struct CList *p_clist);
void CList_rotate_k(struct CList *p_clist, size_t k);
void CList_concat(struct CList *p_a, struct CList *p_b);

#endif