__int64 __fastcall kgsl_iommu_secure_map(__int64 a1, __int64 a2)
{
  return kgsl_iommu_map(*(_QWORD *)(a1 + 112), *(_QWORD *)(*(_QWORD *)(a1 + 112) + 416LL), a2);
}
