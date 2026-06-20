__int64 __fastcall buf_modes_available_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  int v5; // w22
  unsigned int v6; // w21
  __int64 v7; // x20

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( iommu_get_domain_for_dev() && (qcom_iommu_get_mappings_configuration() & 0x80000000) != 0 )
    LOBYTE(v5) = 0;
  else
    v5 = *(_DWORD *)(v4 + 204);
  v6 = sysfs_emit(a3, "%s ", "auto");
  v7 = (int)sysfs_emit_at(a3, v6, "%s ", "flat") + (__int64)(int)v6;
  if ( (v5 & 1) != 0 )
    v7 += (int)sysfs_emit_at(a3, (unsigned int)v7, "%s ", "tmc-sg");
  return v7 + (int)sysfs_emit_at(a3, (unsigned int)v7, "\n");
}
