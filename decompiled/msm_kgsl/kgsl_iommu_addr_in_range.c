bool __fastcall kgsl_iommu_addr_in_range(_QWORD *a1, unsigned __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x8

  v3 = a3 + a2;
  return a2 - 1 < a3 + a2
      && (a1[16] <= a2 && v3 <= a1[17] || a1[20] <= a2 && v3 <= a1[21] || a1[18] <= a2 && v3 <= a1[19]);
}
