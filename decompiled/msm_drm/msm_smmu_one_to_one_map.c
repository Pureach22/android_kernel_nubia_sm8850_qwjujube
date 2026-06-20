__int64 __fastcall msm_smmu_one_to_one_map(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, __int64 a5)
{
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x1
  unsigned int v9; // w19

  v5 = *(_QWORD *)(a1 + 40);
  if ( !v5 )
    return 4294967277LL;
  v6 = *(_QWORD *)(v5 + 24);
  if ( !v6 )
    return 4294967277LL;
  result = iommu_map(v6, a2, a3, a4, a5, 2080);
  if ( (_DWORD)result )
  {
    v9 = result;
    printk(&unk_2305BE, v8);
    return v9;
  }
  return result;
}
