__int64 __fastcall qcom_iommu_dma_finalise_sg(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v7; // x19
  int v8; // w22
  __int64 v9; // x9
  int v10; // w8
  __int64 v11; // x24
  unsigned int v12; // w26
  __int64 v13; // x25
  int v14; // w8
  __int64 v15; // x0
  int v16; // w21
  unsigned int v17; // w20
  unsigned int v19; // w8
  __int64 v20; // x24
  __int64 v21; // x26
  unsigned int v22; // w8
  int v23; // w8
  __int64 v24; // x25
  __int64 v25; // x27
  unsigned int v26; // w28
  __int64 v27; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(a1 + 672);
  v7 = a2;
  v8 = 0x10000;
  if ( v4 )
  {
    v9 = *(_QWORD *)(v4 + 8);
    v10 = *(_DWORD *)v4;
    if ( !v9 )
      v9 = -1;
    if ( v10 )
      v8 = v10;
    else
      v8 = 0x10000;
    v27 = v9;
    if ( a3 >= 1 )
      goto LABEL_8;
    return 0;
  }
  v27 = -1;
  if ( a3 < 1 )
    return 0;
LABEL_8:
  v11 = *(_QWORD *)(a2 + 16);
  v12 = *(_DWORD *)(a2 + 24);
  v13 = *(unsigned int *)(a2 + 12);
  v14 = *(_DWORD *)(a2 + 8) + v11;
  *(_QWORD *)(a2 + 16) = a4 + (unsigned int)v11;
  *(_DWORD *)(a2 + 8) = v14;
  *(_DWORD *)(a2 + 12) = v12;
  v15 = sg_next(a2);
  v16 = a3 - 1;
  if ( v16 )
  {
    v19 = v12 + v11;
    v20 = v13 + a4;
    v17 = 1;
    if ( v19 < (unsigned int)v13 )
      v12 = 0;
    do
    {
      v23 = *(_DWORD *)(v15 + 8);
      v24 = *(unsigned int *)(v15 + 12);
      v25 = *(_QWORD *)(v15 + 16);
      v26 = *(_DWORD *)(v15 + 24);
      *(_QWORD *)(v15 + 16) = -1;
      *(_DWORD *)(v15 + 24) = 0;
      *(_DWORD *)(v15 + 8) = v23 + v25;
      *(_DWORD *)(v15 + 12) = v26;
      if ( v12 && !(_DWORD)v25 && (v20 & v27) != 0 && v8 - v12 >= v26 )
      {
        v22 = v26 + v12;
      }
      else
      {
        v21 = v15;
        v7 = sg_next(v7);
        v15 = v21;
        ++v17;
        *(_QWORD *)(v7 + 16) = (unsigned int)v25 + v20;
        v22 = v26;
      }
      *(_DWORD *)(v7 + 24) = v22;
      v20 += v24;
      if ( v26 + (unsigned int)v25 >= (unsigned int)v24 )
        v12 = v22;
      else
        v12 = 0;
      v15 = sg_next(v15);
      --v16;
    }
    while ( v16 );
  }
  else
  {
    return 1;
  }
  return v17;
}
