__int64 __fastcall qcom_iommu_set_secure_vmid(__int64 a1, unsigned int a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x8

  v4 = xa_load(&xa_qcom_iommu_ops, *(_QWORD *)(a1 + 8));
  if ( !v4 )
    return 4294967274LL;
  v5 = *(_DWORD **)(v4 + 40);
  if ( !v5 )
    return 4294967274LL;
  if ( *(v5 - 1) != -1886448810 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v5)(a1, a2);
}
