__int64 __fastcall qcom_dma_common_pages_remap(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v6; // x19
  __int64 v7; // x0
  __int64 v8; // x20
  __int64 *v9; // x10
  __int64 v10; // x11
  unsigned __int64 v11; // x10
  __int64 v12; // x12
  __int64 v13; // x9
  unsigned __int64 v14; // x11

  v6 = (_QWORD *)_kmalloc_cache_noprof(gen_pool_alloc_algo_owner, 3520, 40);
  if ( !v6 )
    return 0;
  v7 = vmap(a1, (unsigned __int64)(a2 + 4095) >> 12, 16, a3);
  if ( !v7 )
  {
    kfree(v6);
    return 0;
  }
  v6[3] = v7;
  v6[4] = a1;
  v8 = v7;
  mutex_lock(&rbtree_lock);
  v9 = root;
  v10 = *root;
  if ( *root )
  {
    v11 = v6[3];
    do
    {
      while ( 1 )
      {
        v13 = v10;
        v14 = *(_QWORD *)(v10 + 24);
        if ( v11 >= v14 )
          break;
        v12 = 16;
        v10 = *(_QWORD *)(v13 + 16);
        if ( !v10 )
          goto LABEL_10;
      }
      if ( v11 <= v14 )
      {
        mutex_unlock(&rbtree_lock);
        __break(0x800u);
        return v8;
      }
      v12 = 8;
      v10 = *(_QWORD *)(v13 + 8);
    }
    while ( v10 );
LABEL_10:
    v9 = (__int64 *)(v13 + v12);
  }
  else
  {
    v13 = 0;
  }
  *v6 = v13;
  v6[1] = 0;
  v6[2] = 0;
  *v9 = (__int64)v6;
  rb_insert_color(v6);
  mutex_unlock(&rbtree_lock);
  return v8;
}
