__int64 __fastcall kgsl_iommu_destroy_pagetable(__int64 a1)
{
  qcom_free_io_pgtable_ops(*(_QWORD *)(a1 + 200));
  return kfree(a1);
}
