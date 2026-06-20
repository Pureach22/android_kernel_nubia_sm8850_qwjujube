__int64 __fastcall _qdf_mempool_init(__int64 a1, __int64 *a2, int a3, __int64 a4, int a5)
{
  __int64 v9; // x8
  __int64 v11; // x24
  __int64 v12; // x25
  _BOOL4 v14; // w26
  __int64 v15; // x0
  __int64 v16; // x23
  unsigned __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x11
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 v22; // x12
  unsigned __int64 StatusReg; // x21
  __int64 v24; // x22

  if ( (prealloc_disabled & 1) != 0 )
  {
    v9 = _kmalloc_cache_noprof(wcnss_check_pool_lists, 3264, 64);
    if ( !v9 )
      return 2;
    *(_QWORD *)(v9 + 48) = 0;
    *(_QWORD *)(v9 + 56) = 0;
    *(_QWORD *)(v9 + 32) = 0;
    *(_QWORD *)(v9 + 40) = 0;
    *(_QWORD *)(v9 + 16) = 0;
    *(_QWORD *)(v9 + 24) = 0;
    *(_QWORD *)v9 = 0;
    *(_QWORD *)(v9 + 8) = a4;
    *(_DWORD *)(v9 + 4) = a5;
    *(_DWORD *)(v9 + 52) = a3;
    *a2 = v9;
    return 0;
  }
  v11 = a1 + 80;
  if ( *(_QWORD *)(a1 + 80) )
  {
    v12 = 0;
    while ( v12 != 63 )
    {
      if ( !*(_QWORD *)(a1 + 88 + 8 * v12++) )
      {
        v14 = (unsigned __int64)(v12 - 1) < 0x3F;
        goto LABEL_10;
      }
    }
    return 4294967284LL;
  }
  LODWORD(v12) = 0;
  v14 = 1;
LABEL_10:
  v15 = _kmalloc_cache_noprof(wcnss_check_pool_lists, 3264, 64);
  v16 = v15;
  if ( !v14 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v24 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &_qdf_mempool_init__alloc_tag_6;
    v18 = _kmalloc_noprof(*(unsigned int *)(v15 + 24), 3520);
    *(_QWORD *)(StatusReg + 80) = v24;
    *(_QWORD *)(v16 + 16) = v18;
    if ( v18 )
      goto LABEL_13;
    goto LABEL_19;
  }
  *(_QWORD *)(v11 + 8LL * (unsigned int)v12) = v15;
  if ( !v15 )
    return 4294967284LL;
  *(_QWORD *)(v15 + 48) = 0;
  *(_QWORD *)(v15 + 56) = 0;
  v17 = (a4 + 63) & 0xFFFFFFFFFFFFFFC0LL;
  *(_QWORD *)(v15 + 32) = 0;
  *(_QWORD *)(v15 + 40) = 0;
  *(_QWORD *)(v15 + 8) = v17;
  *(_QWORD *)(v15 + 16) = 0;
  *(_QWORD *)(v15 + 24) = 0;
  *(_DWORD *)v15 = v12;
  *(_DWORD *)(v15 + 4) = a5;
  *(_DWORD *)(v15 + 24) = (v17 * a3) | 0x3F;
  v18 = _kmalloc_noprof(*(unsigned int *)(v15 + 24), 3520);
  *(_QWORD *)(v16 + 16) = v18;
  if ( !v18 )
  {
LABEL_19:
    kfree(v16);
    *(_QWORD *)(v11 + 8LL * (unsigned int)v12) = 0;
    return 4294967284LL;
  }
LABEL_13:
  *(_QWORD *)(v16 + 32) = 0;
  *(_DWORD *)(v16 + 48) = 0;
  *(_QWORD *)(v16 + 40) = v16 + 32;
  if ( a3 >= 1 )
  {
    v19 = *(_QWORD *)(v16 + 8);
    v20 = 0;
    v21 = (v18 & 0x38) + v18;
    do
    {
      *(_QWORD *)(v19 * v20 + v21) = 0;
      **(_QWORD **)(v16 + 40) = v21 + *(_QWORD *)(v16 + 8) * v20;
      v19 = *(_QWORD *)(v16 + 8);
      v22 = v21 + v19 * v20++;
      *(_QWORD *)(v16 + 40) = v22;
    }
    while ( a3 != v20 );
  }
  *(_DWORD *)(v16 + 56) = a3;
  *a2 = v16;
  return 0;
}
