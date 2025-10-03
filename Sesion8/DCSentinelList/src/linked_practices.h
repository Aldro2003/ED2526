#ifndef LINKED_PRACTICES_H
#define LINKED_PRACTICES_H
#include <stddef.h>
#include <stdbool.h>

/* ========== 5) DCSentinelList (doble, circular, con nodo centinela)
========== */
struct DCSentinelNode
{
  int key;
  struct DCSentinelNode *prev;
  struct DCSentinelNode *next;
};
struct DCSentinelList
{
  struct DCSentinelNode sentinel; // prev/next apuntan a él mismo sivacía
  size_t size;
};
void DCSL_init(struct DCSentinelList *p_list);
void DCSL_clear(struct DCSentinelList *p_list);
bool DCSL_empty(const struct DCSentinelList *p_list);
size_t DCSL_size(const struct DCSentinelList *p_list);
bool DCSL_push_back(struct DCSentinelList *p_list, int key);
bool DCSL_push_front(struct DCSentinelList *p_list, int key);
bool DCSL_insert_sorted(struct DCSentinelList *p_list, int key);
bool DCSL_pop_front(struct DCSentinelList *p_list, int *out_key);
bool DCSL_pop_back(struct DCSentinelList *p_list, int *out_key);
size_t DCSL_remove_key(struct DCSentinelList *p_list, int key);
struct DCSentinelNode *DCSL_find(const struct DCSentinelList *p_list, int key);

#endif