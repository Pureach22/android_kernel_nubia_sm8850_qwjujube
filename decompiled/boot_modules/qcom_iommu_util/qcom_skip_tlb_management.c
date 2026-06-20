__int64 __fastcall qcom_skip_tlb_management(__int64 a1, char a2)
{
  __int64 domain_for_dev; // x0
  __int64 v4; // x20
  __int64 v5; // x0
  _DWORD *v6; // x8

  domain_for_dev = iommu_get_domain_for_dev();
  if ( !domain_for_dev )
    return 4294967274LL;
  v4 = domain_for_dev;
  v5 = xa_load(&xa_qcom_iommu_ops, *(_QWORD *)(domain_for_dev + 8));
  if ( !v5 )
    return 4294967274LL;
  v6 = *(_DWORD **)(v5 + 80);
  if ( !v6 )
    return 4294967274LL;
  if ( *(v6 - 1) != -944838995 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD))v6)(v4, a2 & 1);
  return 0;
}
