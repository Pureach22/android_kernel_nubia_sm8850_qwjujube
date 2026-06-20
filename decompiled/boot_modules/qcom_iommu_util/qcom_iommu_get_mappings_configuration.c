__int64 __fastcall qcom_iommu_get_mappings_configuration(__int64 a1)
{
  __int64 v2; // x0
  __int64 (__fastcall *v3)(_QWORD); // x8

  v2 = xa_load(&xa_qcom_iommu_ops, *(_QWORD *)(a1 + 8));
  if ( !v2 )
    return 4294967274LL;
  v3 = *(__int64 (__fastcall **)(_QWORD))(v2 + 72);
  if ( !v3 )
    return 4294967274LL;
  if ( *((_DWORD *)v3 - 1) != -1985837140 )
    __break(0x8228u);
  return v3(a1);
}
