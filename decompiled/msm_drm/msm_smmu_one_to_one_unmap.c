__int64 __fastcall msm_smmu_one_to_one_unmap(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x1

  v3 = *(_QWORD *)(a1 + 40);
  if ( !v3 )
    return 4294967277LL;
  v4 = *(_QWORD *)(v3 + 24);
  if ( !v4 )
    return 4294967277LL;
  if ( (unsigned int)iommu_unmap(v4, a2, a3) != a3 )
    printk(&unk_278CE4, v5);
  return 0;
}
