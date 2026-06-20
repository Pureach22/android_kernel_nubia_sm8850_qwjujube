__int64 __fastcall qcom_iommu_dma_prepare_map_sg(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v4; // x8
  int v5; // w19
  __int64 v7; // x23
  __int64 v8; // x21
  __int64 v9; // x22
  __int64 v10; // x8
  unsigned int v11; // w10
  __int64 v12; // x11
  __int64 v13; // x9
  __int64 v14; // x10
  __int64 v15; // x12
  __int64 v16; // x9
  unsigned __int64 v17; // x10
  __int64 v18; // x9

  v4 = *(_QWORD *)(a1 + 672);
  v5 = a4;
  if ( v4 )
  {
    v7 = *(_QWORD *)(v4 + 8);
    if ( v7 )
    {
      if ( a4 >= 1 )
        goto LABEL_4;
      return 0;
    }
  }
  v7 = -1;
  if ( a4 < 1 )
    return 0;
LABEL_4:
  v8 = 0;
  v9 = 0;
  do
  {
    v10 = v9;
    v9 = a3;
    v11 = *(_DWORD *)(a3 + 8);
    v12 = *(unsigned int *)(a3 + 12);
    v13 = (*(_DWORD *)(a2 + 32) - 1) & v11;
    *(_DWORD *)(a3 + 24) = v12;
    *(_QWORD *)(a3 + 16) = v13;
    *(_DWORD *)(a3 + 8) = v11 - v13;
    v14 = *(_QWORD *)(a2 + 32);
    v15 = -v14;
    v16 = v12 + v14 + v13;
    v17 = (v7 + 1 - v8) & v7;
    v18 = (v16 - 1) & v15;
    *(_DWORD *)(a3 + 12) = v18;
    if ( v17 && v17 < v18 - 1 )
    {
      v8 += v17;
      *(_DWORD *)(v10 + 12) += v17;
    }
    v8 += v18;
    --v5;
    a3 = sg_next(a3);
  }
  while ( v5 );
  return v8;
}
