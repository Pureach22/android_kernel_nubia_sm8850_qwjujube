__int64 __fastcall stm_register_protocol(__int64 a1)
{
  const char *v2; // x20
  __int64 *v3; // x22
  _QWORD *v4; // x20
  unsigned int v5; // w19
  __int64 policy_node_type; // x0
  _QWORD *v7; // x1

  mutex_lock(&stm_pdrv_mutex);
  v2 = *(const char **)(a1 + 8);
  if ( !v2 || !*v2 )
    v2 = "p_basic";
  v3 = &stm_pdrv_head;
  do
  {
    v3 = (__int64 *)*v3;
    if ( v3 == &stm_pdrv_head )
      goto LABEL_9;
  }
  while ( strcmp(v2, *(const char **)(v3[2] + 8)) );
  if ( v3 )
  {
    v4 = nullptr;
    v5 = -17;
LABEL_17:
    mutex_unlock(&stm_pdrv_mutex);
    kfree(v4);
    return v5;
  }
LABEL_9:
  v4 = (_QWORD *)_kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 32);
  if ( !v4 || *(_QWORD *)(a1 + 56) && (policy_node_type = get_policy_node_type(), (v4[3] = policy_node_type) == 0) )
  {
    v5 = -12;
    goto LABEL_17;
  }
  v7 = (_QWORD *)qword_9C70;
  if ( (_QWORD *)qword_9C70 == v4 || *(__int64 **)qword_9C70 != &stm_pdrv_head )
  {
    _list_add_valid_or_report(v4);
  }
  else
  {
    qword_9C70 = (__int64)v4;
    *v4 = &stm_pdrv_head;
    v4[1] = v7;
    *v7 = v4;
  }
  v4[2] = a1;
  mutex_unlock(&stm_pdrv_mutex);
  return 0;
}
