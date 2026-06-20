__int64 __fastcall kgsl_iommu_svm_range(__int64 a1, _QWORD *a2, _QWORD *a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v5; // x8

  if ( a2 )
  {
    v4 = 160;
    if ( (a4 & 0x100000000LL) == 0 )
      v4 = 144;
    *a2 = *(_QWORD *)(a1 + v4);
  }
  if ( a3 )
  {
    v5 = 168;
    if ( (a4 & 0x100000000LL) == 0 )
      v5 = 152;
    *a3 = *(_QWORD *)(a1 + v5);
  }
  return 0;
}
