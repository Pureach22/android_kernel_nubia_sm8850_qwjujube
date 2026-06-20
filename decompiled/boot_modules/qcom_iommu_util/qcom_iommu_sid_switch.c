__int64 __fastcall qcom_iommu_sid_switch(__int64 a1, unsigned int a2)
{
  __int64 domain_for_dev; // x0
  __int64 v5; // x0
  _DWORD *v6; // x8

  domain_for_dev = iommu_get_domain_for_dev();
  if ( !domain_for_dev )
    return 4294967274LL;
  v5 = xa_load(&xa_qcom_iommu_ops, *(_QWORD *)(domain_for_dev + 8));
  if ( !v5 )
    return 4294967274LL;
  v6 = *(_DWORD **)(v5 + 8);
  if ( !v6 )
    return 4294967274LL;
  if ( *(v6 - 1) != -2019386717 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v6)(a1, a2);
}
