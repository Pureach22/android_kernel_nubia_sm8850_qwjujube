unsigned __int64 __fastcall register_qcom_iommu_ops(__int64 a1)
{
  unsigned __int64 v1; // x8
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x19

  v1 = xa_store(&xa_qcom_iommu_ops, a1 + 328, a1, 3264);
  result = 0;
  if ( v1 >= 0xFFFFFFFFFFFFC006LL && (v1 & 3) == 2 )
  {
    v3 = v1;
    printk(&unk_11B47);
    return v3 >> 2;
  }
  return result;
}
