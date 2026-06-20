__int64 __fastcall _bus_lookup_iommu_group(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  __int64 v5; // x20
  __int64 v6; // x0
  int v7; // w0
  __int64 v8; // x8
  _QWORD v9[11]; // [xsp+8h] [xbp-58h] BYREF

  v9[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = iommu_group_get();
  if ( result )
  {
    v5 = result;
    v6 = *(_QWORD *)(a1 + 744);
    memset(v9, 0, 80);
    v7 = _of_parse_phandle_with_args(v6, "qcom,iommu-group", 0, 0, 0, v9);
    v8 = v9[0];
    if ( v7 )
      v8 = 0;
    if ( v8 == *a2 )
    {
      result = 1;
      a2[1] = v5;
    }
    else
    {
      iommu_group_put(v5);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
