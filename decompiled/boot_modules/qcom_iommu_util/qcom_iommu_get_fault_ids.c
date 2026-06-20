__int64 __fastcall qcom_iommu_get_fault_ids(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 (__fastcall *v5)(__int64, __int64); // x8

  v4 = xa_load(&xa_qcom_iommu_ops, *(_QWORD *)(a1 + 8));
  if ( !v4 )
    return 4294967274LL;
  v5 = *(__int64 (__fastcall **)(__int64, __int64))(v4 + 16);
  if ( !v5 )
    return 4294967274LL;
  if ( *((_DWORD *)v5 - 1) != 1413667238 )
    __break(0x8228u);
  return v5(a1, a2);
}
