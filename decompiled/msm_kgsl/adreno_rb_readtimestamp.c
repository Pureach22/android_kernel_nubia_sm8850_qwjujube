__int64 __fastcall adreno_rb_readtimestamp(__int64 a1, __int64 a2, int a3, _DWORD *a4)
{
  int v5; // w8
  __int64 v6; // x0
  __int64 v7; // x2

  if ( a3 == 3 )
  {
    *a4 = *(_DWORD *)(a2 + 36);
    return 0;
  }
  v5 = *(_DWORD *)(a2 + 28) + 813;
  if ( a3 == 2 )
  {
    v6 = *(_QWORD *)(a1 + 40);
    v7 = 40LL * v5 + 8;
    goto LABEL_7;
  }
  if ( a3 == 1 )
  {
    v6 = *(_QWORD *)(a1 + 40);
    v7 = 40LL * v5;
LABEL_7:
    kgsl_sharedmem_readl(v6, a4, v7);
    return 0;
  }
  *a4 = 0;
  return 4294967274LL;
}
