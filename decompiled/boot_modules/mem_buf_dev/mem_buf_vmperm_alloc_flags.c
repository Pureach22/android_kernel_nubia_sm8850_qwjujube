__int64 __fastcall mem_buf_vmperm_alloc_flags(
        __int64 a1,
        int a2,
        void *a3,
        __int64 a4,
        unsigned int a5,
        __int64 a6,
        __int64 a7,
        unsigned int a8)
{
  __int64 v15; // x0
  unsigned __int64 v16; // x19
  __int64 v18; // x1
  int v19; // w8
  __int64 v20; // x0
  unsigned int v21; // w25
  int v22; // w20
  void *v24; // x2
  unsigned int v30; // w8

  v15 = _kmalloc_cache_noprof(kfree, 3520, 184);
  v16 = v15;
  if ( !v15 )
    return -12;
  _mutex_init(v15 + 88, "&vmperm->lock", &mem_buf_vmperm_alloc_flags___key);
  mutex_lock(v16 + 88);
  if ( (unsigned int)mem_buf_vmperm_resize(v16, a5) )
  {
    mutex_unlock(v16 + 88);
LABEL_4:
    kfree(v16);
    return -12;
  }
  mem_buf_vmperm_update_state(v16, a3);
  mutex_unlock(v16 + 88);
  v19 = *(_DWORD *)(a1 + 12);
  *(_QWORD *)(v16 + 64) = a1;
  if ( v19 )
  {
    v20 = *(_QWORD *)a1;
    v21 = 0;
    do
    {
      ++v21;
      *(_QWORD *)(v16 + 72) += *(unsigned int *)(v20 + 12);
      v20 = sg_next(v20, v18);
    }
    while ( v21 < *(_DWORD *)(a1 + 12) );
  }
  *(_DWORD *)(v16 + 16) = a2;
  *(_DWORD *)(v16 + 80) = a8;
  *(_QWORD *)(v16 + 152) = a6;
  *(_QWORD *)(v16 + 160) = a7;
  if ( a8 != -1 )
  {
    raw_spin_lock(&vmperm_xa);
    v22 = _xa_insert(&vmperm_xa, a8, v16, 3264);
    raw_spin_unlock(&vmperm_xa);
    if ( v22 )
    {
      kfree(*(_QWORD *)(v16 + 40));
      kfree(*(_QWORD *)(v16 + 32));
      goto LABEL_4;
    }
    _X0 = *(unsigned int **)(v16 + 160);
    __asm { PRFM            #0x11, [X0] }
    do
      v30 = __ldxr(_X0);
    while ( __stxr(v30 + 1, _X0) );
    if ( !v30 || (((v30 + 1) | v30) & 0x80000000) != 0 )
      refcount_warn_saturate();
  }
  mutex_lock(&vmperm_list_lock);
  v24 = vmperm_list;
  if ( vmperm_list == (_UNKNOWN *)v16 || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)vmperm_list) != &vmperm_list )
  {
    _list_add_valid_or_report(v16, &vmperm_list);
  }
  else
  {
    *(_QWORD *)v16 = vmperm_list;
    *(_QWORD *)(v16 + 8) = &vmperm_list;
    atomic_store(v16, (unsigned __int64 *)&vmperm_list);
    *(_QWORD *)((char *)&unk_8 + (_QWORD)v24) = v16;
  }
  mutex_unlock(&vmperm_list_lock);
  return v16;
}
