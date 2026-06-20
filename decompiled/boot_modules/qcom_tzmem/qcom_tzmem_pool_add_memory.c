__int64 __fastcall qcom_tzmem_pool_add_memory(_QWORD *a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // x9
  __int64 v7; // x8
  _QWORD *v8; // x20
  __int64 v9; // x0
  unsigned __int64 v10; // x1
  __int64 v11; // x0
  unsigned int v12; // w0
  unsigned int v13; // w19
  __int64 result; // x0
  unsigned int v15; // w19
  __int64 v16; // x0
  _QWORD *v17; // x2
  _QWORD *v18; // x1
  __int64 v19; // x9

  v6 = 1;
  if ( (a3 & 0x10) == 0 )
    v6 = 2;
  if ( (a3 & 0x400010) != 0 )
    v7 = v6;
  else
    v7 = 0;
  v8 = (_QWORD *)_kmalloc_cache_noprof(kmalloc_caches[14 * v7 + 6], a3 | 0x100, 48);
  if ( !v8 )
    return 4294967284LL;
  v9 = qcom_tzmem_dev;
  v10 = (a2 + 4095) & 0xFFFFFFFFFFFFF000LL;
  v8[4] = v10;
  v11 = dma_alloc_attrs(v9, v10, v8 + 3, a3, (a3 >> 5) & 0x100);
  v8[2] = v11;
  if ( v11 )
  {
    v12 = gen_pool_add_owner(*a1, v11, v8[3], a2, 0xFFFFFFFFLL, 0);
    if ( v12 )
    {
      v13 = v12;
      dma_free_attrs(qcom_tzmem_dev, v8[4], v8[2], v8[3], 0);
      result = v13;
      if ( (unsigned __int64)v8 > 0xFFFFFFFFFFFFF000LL )
        return result;
LABEL_12:
      v15 = result;
      kfree(v8);
      return v15;
    }
    v16 = raw_spin_lock_irqsave(a1 + 6);
    v17 = a1 + 1;
    v18 = (_QWORD *)a1[2];
    v19 = v16;
    if ( v8 == a1 + 1 || v18 == v8 || (_QWORD *)*v18 != v17 )
    {
      _list_add_valid_or_report(v8, v18);
    }
    else
    {
      a1[2] = v8;
      *v8 = v17;
      v8[1] = v18;
      *v18 = v8;
    }
    raw_spin_unlock_irqrestore(a1 + 6, v19);
    return 0;
  }
  else
  {
    result = 4294967284LL;
    if ( (unsigned __int64)v8 <= 0xFFFFFFFFFFFFF000LL )
      goto LABEL_12;
  }
  return result;
}
