__int64 __fastcall kgsl_iommu_default_map(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x21
  __int64 result; // x0
  __int64 v5; // x20
  __int64 v6; // x1
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x9
  int v9; // w10
  unsigned int v10; // w19
  unsigned __int64 v11; // x2
  unsigned __int64 v12; // x1

  v2 = *(_QWORD **)(a1 + 112);
  if ( (v2[6] & 0x40) != 0 && *(_QWORD *)(a2 + 24) >> 39 <= 0x3FEu )
    return kgsl_iopgtbl_map();
  v5 = v2[17];
  result = kgsl_iommu_map(*(_QWORD *)(a1 + 112), v5, a2);
  if ( !(_DWORD)result )
  {
    v6 = v2[87];
    if ( v6 )
    {
      result = kgsl_iommu_map(v2, v6, a2);
      if ( (_DWORD)result )
      {
        v7 = *(_QWORD *)(a2 + 40);
        if ( v7 )
        {
          v8 = *(_QWORD *)(a2 + 24);
          if ( v8 )
          {
            v9 = *(_DWORD *)(a2 + 48);
            if ( v5 )
            {
              v10 = result;
              if ( (v9 & 1) != 0 )
                v11 = (v7 + 0x1FFF) & 0xFFFFFFFFFFFFF000LL;
              else
                v11 = v7;
              if ( (v8 & 0x1000000000000LL) != 0 )
                v12 = v8 | 0xFFFF000000000000LL;
              else
                v12 = v8;
              iommu_unmap(v5, v12, v11);
              return v10;
            }
          }
        }
      }
    }
  }
  return result;
}
