__int64 __fastcall kgsl_iommu_map_global(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  if ( *(_QWORD *)(a2 + 24) || (result = kgsl_iommu_reserve_global_gpuaddr(a1, a2), !(_DWORD)result) )
  {
    if ( (*(_BYTE *)(a2 + 72) & 8) != 0 )
      return kgsl_iommu_map(
               *(_QWORD *)(*(_QWORD *)(a1 + 24) + 112LL),
               *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 112LL) + 416LL),
               a2);
    else
      return kgsl_iommu_default_map(*(_QWORD *)(a1 + 16), a2);
  }
  return result;
}
