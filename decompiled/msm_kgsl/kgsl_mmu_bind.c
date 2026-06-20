__int64 __fastcall kgsl_mmu_bind(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 result; // x0

  v2 = *(_QWORD *)(a2 + 152);
  result = kgsl_iommu_bind(v2, a1 - 16);
  if ( (_DWORD)result != -517 )
  {
    if ( (_DWORD)result )
    {
      *(_QWORD *)(v2 + 88) = &kgsl_nommu_ops;
      *(_DWORD *)(v2 + 64) = 1;
      return 0;
    }
  }
  return result;
}
