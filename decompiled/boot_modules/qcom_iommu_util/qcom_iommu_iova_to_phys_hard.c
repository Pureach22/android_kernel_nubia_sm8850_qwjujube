__int64 (__fastcall **__fastcall qcom_iommu_iova_to_phys_hard(__int64 a1, __int64 a2))(__int64, __int64)
{
  __int64 (__fastcall **result)(__int64, __int64); // x0
  __int64 (__fastcall *v5)(__int64, __int64); // x8

  result = (__int64 (__fastcall **)(__int64, __int64))xa_load(&xa_qcom_iommu_ops, *(_QWORD *)(a1 + 8));
  if ( result )
  {
    v5 = *result;
    if ( *result )
    {
      if ( *((_DWORD *)v5 - 1) != 466137285 )
        __break(0x8228u);
      return (__int64 (__fastcall **)(__int64, __int64))v5(a1, a2);
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}
