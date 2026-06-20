__int64 __fastcall qcom_tzmem_alloc(_QWORD *a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // x9
  __int64 v7; // x8
  unsigned __int64 *v8; // x20
  unsigned __int64 v9; // x22
  __int64 v10; // x1
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned __int64 v13; // x8
  int v14; // w8
  __int64 result; // x0
  __int64 v16; // x24
  __int64 v17; // x23
  __int64 v18; // x21
  int v19; // w24
  __int64 v20; // x19

  if ( !a2 )
    return 0;
  v6 = 1;
  if ( (a3 & 0x10) == 0 )
    v6 = 2;
  v7 = (a3 & 0x400010) != 0 ? v6 : 0LL;
  v8 = (unsigned __int64 *)_kmalloc_cache_noprof(kmalloc_caches[14 * v7 + 4], a3 | 0x100, 16);
  if ( !v8 )
    return 0;
  v9 = (a2 + 4095) & 0xFFFFFFFFFFFFF000LL;
  while ( 1 )
  {
    v11 = gen_pool_alloc_algo_owner(*a1, v9, *(_QWORD *)(*a1 + 32LL), *(_QWORD *)(*a1 + 40LL), 0);
    if ( v11 )
      break;
    v12 = gen_pool_size(*a1);
    v13 = a1[5];
    if ( v13 && v12 + v9 > v13 )
    {
LABEL_16:
      result = 0;
LABEL_24:
      if ( (unsigned __int64)v8 <= 0xFFFFFFFFFFFFF000LL )
      {
        v20 = result;
        kfree(v8);
        return v20;
      }
      return result;
    }
    v14 = *((_DWORD *)a1 + 6);
    if ( v14 == 2 )
    {
      v10 = a1[4] * v12;
    }
    else
    {
      v10 = v9;
      if ( v14 == 1 )
        goto LABEL_16;
    }
    if ( (unsigned int)qcom_tzmem_pool_add_memory(a1, v10, a3) )
      goto LABEL_16;
  }
  v16 = v11;
  *v8 = v9;
  v8[1] = (unsigned __int64)a1;
  v17 = raw_spin_lock_irqsave(&qcom_tzmem_chunks_lock);
  v18 = v16;
  v19 = radix_tree_insert(&qcom_tzmem_chunks, v16, v8);
  if ( v19 )
    gen_pool_free_owner(*a1, v18, v9, 0);
  else
    v8 = nullptr;
  raw_spin_unlock_irqrestore(&qcom_tzmem_chunks_lock, v17);
  if ( v19 )
    result = 0;
  else
    result = v18;
  if ( v8 )
    goto LABEL_24;
  return result;
}
