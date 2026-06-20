__int64 __fastcall qcom_sg_attach(__int64 a1, __int64 a2)
{
  __int64 v2; // x24
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 *v6; // x21
  __int64 v7; // x23
  __int64 v8; // x22
  unsigned int v9; // w25
  int v10; // w9
  int v11; // w10
  _QWORD *v13; // x21
  _QWORD *v14; // x1
  _QWORD *v15; // x2

  v2 = *(_QWORD *)(a1 + 112);
  v4 = _kmalloc_cache_noprof(of_dma_configure_id, 3520, 40);
  if ( !v4 )
    return 4294967284LL;
  v5 = _kmalloc_cache_noprof(of_find_property, 3520, 16);
  v6 = (__int64 *)v5;
  if ( !v5 )
  {
LABEL_9:
    kfree(v4);
    return 4294967284LL;
  }
  if ( (unsigned int)sg_alloc_table(v5, *(unsigned int *)(v2 + 92), 3264) )
  {
    kfree(v6);
    goto LABEL_9;
  }
  if ( *(_DWORD *)(v2 + 92) )
  {
    v7 = *(_QWORD *)(v2 + 80);
    v8 = *v6;
    v9 = 0;
    do
    {
      v10 = *(_DWORD *)(v7 + 8);
      v11 = *(_DWORD *)(v7 + 12);
      *(_QWORD *)v8 = *(_QWORD *)v7 & 0xFFFFFFFFFFFFFFFCLL | *(_QWORD *)v8 & 3LL;
      *(_DWORD *)(v8 + 8) = v10;
      *(_DWORD *)(v8 + 12) = v11;
      v8 = sg_next(v8);
      ++v9;
      v7 = sg_next(v7);
    }
    while ( v9 < *(_DWORD *)(v2 + 92) );
  }
  if ( (unsigned __int64)v6 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_9;
  *(_QWORD *)v4 = *(_QWORD *)(a2 + 8);
  *(_QWORD *)(v4 + 8) = v6;
  v13 = (_QWORD *)(v4 + 16);
  *(_QWORD *)(v4 + 16) = v4 + 16;
  *(_QWORD *)(v4 + 24) = v4 + 16;
  *(_BYTE *)(v4 + 32) = 0;
  *(_QWORD *)(a2 + 64) = v4;
  mutex_lock(v2 + 24);
  v14 = (_QWORD *)(v2 + 8);
  v15 = *(_QWORD **)(v2 + 8);
  if ( v15[1] != v2 + 8 || v13 == v14 || v15 == v13 )
  {
    _list_add_valid_or_report(v4 + 16);
  }
  else
  {
    v15[1] = v13;
    *(_QWORD *)(v4 + 16) = v15;
    *(_QWORD *)(v4 + 24) = v14;
    *v14 = v13;
  }
  mutex_unlock(v2 + 24);
  return 0;
}
