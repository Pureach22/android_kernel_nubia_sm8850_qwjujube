__int64 __fastcall kgsl_iommu_default_unmap(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x9
  unsigned __int64 v3; // x8
  _QWORD *v4; // x21
  __int64 v6; // x0
  __int64 v7; // x20
  unsigned __int64 v8; // x19
  __int64 v9; // x0
  int v10; // w20
  unsigned __int64 v11; // x8
  __int64 v12; // x0
  unsigned __int64 v13; // x19
  unsigned __int64 v14; // x1
  int v15; // w8

  v2 = *(_QWORD *)(a2 + 40);
  if ( !v2 )
    return 4294967274LL;
  v3 = *(_QWORD *)(a2 + 24);
  if ( !v3 )
    return 4294967274LL;
  v4 = *(_QWORD **)(a1 + 112);
  if ( v3 >> 39 <= 0x3FE && (v4[6] & 0x40) != 0 )
    return iopgtbl_unmap();
  v6 = v4[17];
  if ( v6 )
  {
    v7 = a2;
    if ( (*(_DWORD *)(a2 + 48) & 1) != 0 )
      v8 = (v2 + 0x1FFF) & 0xFFFFFFFFFFFFF000LL;
    else
      v8 = *(_QWORD *)(a2 + 40);
    if ( (v3 & 0x1000000000000LL) != 0 )
      v3 |= 0xFFFF000000000000LL;
    v9 = iommu_unmap(v6, v3, v8);
    v2 = *(_QWORD *)(v7 + 40);
    a2 = v7;
    if ( v9 == v8 )
      v10 = 0;
    else
      v10 = -12;
    if ( v2 )
    {
      v11 = *(_QWORD *)(a2 + 24);
      if ( v11 )
        goto LABEL_18;
    }
  }
  else
  {
    v10 = 0;
    v11 = *(_QWORD *)(a2 + 24);
    if ( v11 )
    {
LABEL_18:
      v12 = v4[87];
      if ( v12 )
      {
        if ( (*(_DWORD *)(a2 + 48) & 1) != 0 )
          v13 = (v2 + 0x1FFF) & 0xFFFFFFFFFFFFF000LL;
        else
          v13 = v2;
        if ( (v11 & 0x1000000000000LL) != 0 )
          v14 = v11 | 0xFFFF000000000000LL;
        else
          v14 = v11;
        if ( iommu_unmap(v12, v14, v13) == v13 )
          v15 = 0;
        else
          v15 = -12;
      }
      else
      {
        v15 = 0;
      }
      return v15 | (unsigned int)v10;
    }
  }
  v15 = -22;
  return v15 | (unsigned int)v10;
}
