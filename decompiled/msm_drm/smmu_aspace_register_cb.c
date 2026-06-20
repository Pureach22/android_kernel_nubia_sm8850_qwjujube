__int64 __fastcall smmu_aspace_register_cb(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v6; // x0
  _QWORD *v7; // x20
  _QWORD *v8; // x21
  _QWORD *v9; // x8
  _QWORD *v10; // x9
  unsigned int v11; // w22
  _QWORD *v13; // x8
  __int64 v14; // x10
  _QWORD *v15; // x1

  if ( !a1 )
    return 4294967274LL;
  if ( *(_BYTE *)(a1 + 268) != 1 )
    return 4294967283LL;
  v6 = (_QWORD *)_kmalloc_cache_noprof(wake_up_process, 3520, 32);
  v7 = v6;
  if ( !v6 )
    return 4294967284LL;
  *v6 = a2;
  v6[1] = a3;
  v8 = v6 + 2;
  v6[2] = v6 + 2;
  v6[3] = v6 + 2;
  mutex_lock(a1 + 320);
  v9 = *(_QWORD **)(a1 + 304);
  v10 = (_QWORD *)(a1 + 304);
  if ( v9 == (_QWORD *)(a1 + 304) )
  {
LABEL_12:
    v13 = (_QWORD *)v7[3];
    if ( (_QWORD *)*v13 == v8 && (v14 = *v8, *(_QWORD **)(*v8 + 8LL) == v8) )
    {
      *(_QWORD *)(v14 + 8) = v13;
      *v13 = v14;
    }
    else
    {
      _list_del_entry_valid_or_report(v7 + 2);
    }
    v15 = *(_QWORD **)(a1 + 312);
    if ( v8 == v10 || v15 == v8 || (_QWORD *)*v15 != v10 )
    {
      _list_add_valid_or_report(v7 + 2, v15);
      v11 = 0;
    }
    else
    {
      v11 = 0;
      *(_QWORD *)(a1 + 312) = v8;
      v7[2] = v10;
      v7[3] = v15;
      *v15 = v8;
    }
  }
  else
  {
    while ( *(v9 - 2) != *v7 || *(v9 - 1) != v7[1] )
    {
      v9 = (_QWORD *)*v9;
      if ( v9 == v10 )
        goto LABEL_12;
    }
    kfree(v7);
    v11 = -17;
  }
  mutex_unlock(a1 + 320);
  return v11;
}
