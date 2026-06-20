__int64 __fastcall ipa_smmu_store_sgt(__int64 *a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x21
  _QWORD **v6; // x8
  _QWORD *v7; // x22
  __int64 *v8; // x0
  unsigned int v9; // w23
  __int64 v10; // x8
  __int64 v11; // x10
  __int64 v12; // x11

  if ( !a2 )
    return 0;
  v4 = _kmalloc_cache_noprof(kfree, 3520, 16);
  *a1 = v4;
  if ( !v4 )
    return 4294967284LL;
  v5 = *(unsigned int *)(a2 + 8);
  *(_QWORD *)*a1 = _kmalloc_noprof(32 * v5, 3520);
  v6 = (_QWORD **)*a1;
  v7 = *(_QWORD **)*a1;
  if ( !v7 )
  {
    kfree(*a1);
    *a1 = 0;
    return 4294967284LL;
  }
  if ( *(_DWORD *)(a2 + 8) )
  {
    v8 = *(__int64 **)a2;
    v9 = 0;
    do
    {
      v10 = v8[3];
      ++v9;
      v11 = *v8;
      v12 = v8[1];
      v7[2] = v8[2];
      v7[3] = v10;
      *v7 = v11;
      v7[1] = v12;
      v7 += 4;
      v8 = (__int64 *)sg_next();
    }
    while ( v9 < *(_DWORD *)(a2 + 8) );
    v6 = (_QWORD **)*a1;
  }
  *((_DWORD *)v6 + 2) = v5;
  *(_DWORD *)(*a1 + 12) = *(_DWORD *)(a2 + 12);
  return 0;
}
