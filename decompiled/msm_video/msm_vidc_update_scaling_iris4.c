__int64 __fastcall msm_vidc_update_scaling_iris4(__int64 a1, int a2, int a3)
{
  unsigned int v3; // w8
  unsigned int v4; // w11
  int v5; // w12
  unsigned int v6; // w6
  unsigned int v7; // w7
  unsigned int v8; // w10
  unsigned int v9; // w13
  unsigned int v10; // w8
  unsigned int v11; // w10
  __int64 v12; // x4
  unsigned int v13; // w5
  bool v14; // cf
  void *v15; // x8

  v3 = *(_DWORD *)(a1 + 1904);
  v4 = *(_DWORD *)(a1 + 1908);
  v5 = 32 * a3;
  v6 = *(_DWORD *)(a1 + 392);
  v7 = *(_DWORD *)(a1 + 396);
  v8 = v3 / (32 * a2);
  *(_QWORD *)(a1 + 1896) = 0;
  v9 = v4 / (32 * a3);
  if ( v8 * 32 * a2 >= v3 )
    v10 = v3 / (32 * a2);
  else
    v10 = v8 + 1;
  if ( v9 * v5 >= v4 )
    v11 = v4 / (32 * a3);
  else
    v11 = v9 + 1;
  if ( v10 >= v11 )
    v10 = v11;
  v12 = 32 * a2 * v10;
  v13 = v5 * v10;
  *(_DWORD *)(a1 + 1904) = v12;
  v14 = (unsigned int)v12 >= v6 || v13 >= v7;
  *(_DWORD *)(a1 + 1908) = v13;
  if ( v14 )
  {
    if ( !a1 || (msm_vidc_debug & 2) == 0 )
      return 4294967274LL;
    v15 = &unk_8B1CF;
  }
  else
  {
    if ( (unsigned int)v12 >= v6 >> 3 && v13 >= v7 >> 3 )
      return 0;
    if ( !a1 || (msm_vidc_debug & 2) == 0 )
      return 4294967274LL;
    v15 = &unk_80E5C;
  }
  printk(v15, "high", a1 + 340, "msm_vidc_update_scaling_iris4", v12);
  return 4294967274LL;
}
