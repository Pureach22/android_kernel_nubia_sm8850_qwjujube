__int64 __fastcall msm_gem_smmu_address_space_get(__int64 a1, unsigned int a2)
{
  __int64 v4; // x8
  __int64 v5; // x8
  _DWORD *v6; // x9
  __int64 result; // x0
  __int64 v8; // x8

  if ( (iommu_present(&platform_bus_type) & 1) == 0 )
    return -19;
  if ( !a1 )
    return -22;
  v4 = *(_QWORD *)(a1 + 56);
  if ( !v4 )
    return -22;
  v5 = *(_QWORD *)(v4 + 8);
  if ( !v5 || !*(_QWORD *)v5 )
    return -22;
  v6 = *(_DWORD **)(*(_QWORD *)v5 + 232LL);
  result = -22;
  if ( v6 )
  {
    if ( *(v6 - 1) != 1756296100 )
      __break(0x8229u);
    v8 = ((__int64 (__fastcall *)(__int64, _QWORD))v6)(v5, a2);
    result = -22;
    if ( v8 )
      return v8;
  }
  return result;
}
