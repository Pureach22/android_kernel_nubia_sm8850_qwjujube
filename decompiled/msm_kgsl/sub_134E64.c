__int64 __fastcall sub_134E64(double a1, double a2, __int64 a3, __int64 a4)
{
  __int64 v4; // d24

  *(double *)(a4 - 344) = a2;
  *(_QWORD *)(a4 - 336) = v4;
  return kgsl_iommu_get_ttbr0();
}
