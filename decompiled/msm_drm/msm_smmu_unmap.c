__int64 __fastcall msm_smmu_unmap(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v5; // x22

  v5 = *(_QWORD *)(a1 + 40);
  _pm_runtime_resume(*(_QWORD *)(a1 + 8), 4);
  iommu_unmap(*(_QWORD *)(v5 + 24), a2, a4);
  _pm_runtime_idle(*(_QWORD *)(a1 + 8), 4);
  return 0;
}
