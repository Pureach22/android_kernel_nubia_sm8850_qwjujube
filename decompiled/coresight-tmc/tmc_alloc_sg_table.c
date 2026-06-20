__int64 __fastcall tmc_alloc_sg_table(__int64 a1, unsigned int a2, int a3, int a4, __int64 a5)
{
  __int64 v10; // x0
  _QWORD *v11; // x19
  int v12; // w0
  __int64 v13; // x3
  __int64 v14; // x0
  __int64 v15; // x3
  __int64 v16; // x0
  __int64 v17; // x22
  __int64 v18; // x0

  v10 = _kmalloc_cache_noprof(_kmalloc_cache_node_noprof, 3520, 88);
  v11 = (_QWORD *)v10;
  if ( !v10 )
    return -12;
  *(_DWORD *)(v10 + 64) = a4;
  *(_DWORD *)(v10 + 40) = a3;
  *(_DWORD *)(v10 + 32) = a2;
  *(_QWORD *)v10 = a1;
  v12 = tmc_pages_alloc(v10 + 64, a1, a2, 2, a5);
  if ( v12 )
    goto LABEL_14;
  if ( arm64_use_ng_mappings )
    v13 = 0x68000000000F03LL;
  else
    v13 = 0x68000000000703LL;
  v14 = vmap(v11[10], *((unsigned int *)v11 + 16), 4, v13);
  v11[2] = v14;
  if ( !v14 )
    goto LABEL_13;
  v12 = tmc_pages_alloc(v11 + 5, *v11, 0xFFFFFFFFLL, 1, 0);
  if ( !v12 )
  {
    if ( arm64_use_ng_mappings )
      v15 = 0x68000000000F03LL;
    else
      v15 = 0x68000000000703LL;
    v16 = vmap(v11[7], *((unsigned int *)v11 + 10), 4, v15);
    v11[1] = v16;
    if ( v16 )
    {
      v11[3] = *(_QWORD *)v11[6];
      return (__int64)v11;
    }
LABEL_13:
    v12 = -12;
  }
LABEL_14:
  v17 = v12;
  if ( v11[1] )
    vunmap(v11[1]);
  tmc_pages_free(v11 + 5, *v11, 1);
  v18 = v11[2];
  if ( v18 )
    vunmap(v18);
  tmc_pages_free(v11 + 8, *v11, 2);
  kfree(v11);
  return v17;
}
