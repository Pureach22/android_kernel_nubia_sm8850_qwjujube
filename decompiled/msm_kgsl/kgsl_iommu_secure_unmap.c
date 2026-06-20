__int64 __fastcall kgsl_iommu_secure_unmap(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 result; // x0
  unsigned __int64 v5; // x19
  unsigned __int64 v6; // x1

  v2 = *(_QWORD *)(a2 + 40);
  if ( !v2 )
    return 4294967274LL;
  v3 = *(_QWORD *)(a2 + 24);
  if ( !v3 )
    return 4294967274LL;
  result = *(_QWORD *)(*(_QWORD *)(a1 + 112) + 416LL);
  if ( result )
  {
    if ( (*(_DWORD *)(a2 + 48) & 1) != 0 )
      v5 = (v2 + 0x1FFF) & 0xFFFFFFFFFFFFF000LL;
    else
      v5 = *(_QWORD *)(a2 + 40);
    if ( (v3 & 0x1000000000000LL) != 0 )
      v6 = v3 | 0xFFFF000000000000LL;
    else
      v6 = *(_QWORD *)(a2 + 24);
    if ( iommu_unmap(result, v6, v5) == v5 )
      return 0;
    else
      return 4294967284LL;
  }
  return result;
}
