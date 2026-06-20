__int64 __fastcall _tcs_buffer_write(__int64 a1, int a2, int a3, __int64 a4)
{
  int *v4; // x11
  int v5; // w10
  unsigned int v10; // w23
  unsigned int v11; // w24
  unsigned int v12; // w27
  unsigned int *v13; // x25
  unsigned int v14; // w28
  int v15; // w8
  int *v16; // x9
  unsigned int v17; // w26
  int v18; // w8
  int *v19; // x9
  int *v20; // x8
  int v21; // w11
  int *v22; // x11
  int v23; // w10
  int *v24; // x11
  int v25; // w10
  int v26; // w0
  int *v27; // x11
  int v28; // w10
  int v30; // [xsp+1Ch] [xbp-4h]

  v4 = *(int **)(a1 + 1664);
  v5 = *(_DWORD *)(a1 + 40);
  if ( !v5 )
    v5 = *v4;
  v30 = *(_DWORD *)(a4 + 4);
  v10 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 32) + v4[7] + (unsigned int)(v5 * a2)));
  if ( *(_DWORD *)(a4 + 8) )
  {
    v11 = 0;
    v12 = 0;
    _ReadStatusReg(SP_EL0);
    do
    {
      v13 = (unsigned int *)(*(_QWORD *)(a4 + 16) + 12LL * (int)v11);
      v14 = v13[2];
      v15 = *(_DWORD *)(a1 + 40);
      v16 = *(int **)(a1 + 1664);
      if ( v14 | v30 )
        v17 = 65800;
      else
        v17 = 65544;
      if ( !v15 )
        v15 = *v16;
      writel_relaxed(v17, *(_QWORD *)(a1 + 32) + v16[11] + (unsigned int)(v15 * a2) + (unsigned int)(v16[1] * a3));
      v18 = *(_DWORD *)(a1 + 40);
      v19 = *(int **)(a1 + 1664);
      if ( !v18 )
        v18 = *v19;
      writel_relaxed(*v13, *(_QWORD *)(a1 + 32) + v19[12] + (unsigned int)(v18 * a2) + (unsigned int)(v19[1] * a3));
      v20 = *(int **)(a1 + 1664);
      v21 = *(_DWORD *)(a1 + 40);
      if ( !v21 )
        v21 = *v20;
      writel_relaxed(v13[1], *(_QWORD *)(a1 + 32) + v20[13] + (unsigned int)(v21 * a2) + (unsigned int)(v20[1] * a3));
      v12 |= 1LL << a3;
      v10 |= v14 << a3;
      ipc_log_string(
        *(_QWORD *)(a1 + 1672),
        "TCS write: m=%d n=%d msgid=%#x addr=%#x data=%#x wait=%d",
        a2,
        a3,
        v17,
        *v13,
        v13[1],
        v13[2]);
      ++v11;
      ++a3;
    }
    while ( v11 < *(_DWORD *)(a4 + 8) );
  }
  else
  {
    v12 = 0;
  }
  v22 = *(int **)(a1 + 1664);
  v23 = *(_DWORD *)(a1 + 40);
  if ( !v23 )
    v23 = *v22;
  writel_relaxed(v10, *(_QWORD *)(a1 + 32) + v22[7] + (unsigned int)(v23 * a2));
  v24 = *(int **)(a1 + 1664);
  v25 = *(_DWORD *)(a1 + 40);
  if ( !v25 )
    v25 = *v24;
  v26 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 32) + v24[10] + (unsigned int)(v25 * a2)));
  v27 = *(int **)(a1 + 1664);
  v28 = *(_DWORD *)(a1 + 40);
  if ( !v28 )
    v28 = *v27;
  return writel_relaxed(v26 | v12, *(_QWORD *)(a1 + 32) + v27[10] + (unsigned int)(v28 * a2));
}
