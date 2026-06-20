__int64 __fastcall qcom_tzmem_pool_new(__int64 *a1)
{
  int v1; // w8
  __int64 result; // x0
  unsigned __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 v8; // x1
  int v9; // w0
  int v10; // w19
  __int64 v11; // x19

  v1 = *((_DWORD *)a1 + 2);
  if ( v1 != 3 )
  {
    if ( v1 == 2 )
    {
      if ( !a1[2] )
        return -22;
    }
    else if ( v1 != 1 || !*a1 )
    {
      return -22;
    }
  }
  v4 = _kmalloc_cache_noprof(kfree, 3520, 56);
  if ( !v4 )
    return -12;
  v5 = gen_pool_create(12, 0xFFFFFFFFLL);
  *(_QWORD *)v4 = v5;
  if ( !v5 )
  {
    result = -12;
    if ( v4 > 0xFFFFFFFFFFFFF000LL )
      return result;
    goto LABEL_15;
  }
  gen_pool_set_algo(v5, &gen_pool_best_fit, 0);
  v6 = a1[2];
  v7 = a1[3];
  *(_DWORD *)(v4 + 24) = *((_DWORD *)a1 + 2);
  *(_QWORD *)(v4 + 32) = v6;
  *(_QWORD *)(v4 + 40) = v7;
  *(_QWORD *)(v4 + 8) = v4 + 8;
  *(_QWORD *)(v4 + 16) = v4 + 8;
  v8 = *a1;
  *(_DWORD *)(v4 + 48) = 0;
  if ( !v8 )
    return v4;
  v9 = qcom_tzmem_pool_add_memory(v4, v8, 3264);
  if ( !v9 )
    return v4;
  v10 = v9;
  gen_pool_destroy(*(_QWORD *)v4);
  result = v10;
  if ( v4 <= 0xFFFFFFFFFFFFF000LL )
  {
LABEL_15:
    v11 = result;
    kfree(v4);
    return v11;
  }
  return result;
}
