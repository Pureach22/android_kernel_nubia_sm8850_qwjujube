__int64 __fastcall buf_mode_preferred_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x21
  int v7; // w22
  int v8; // w8

  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( iommu_get_domain_for_dev() && (qcom_iommu_get_mappings_configuration() & 0x80000000) != 0 )
    v7 = 0;
  else
    v7 = *(_DWORD *)(v6 + 204);
  if ( (sysfs_streq(a3, "flat") & 1) != 0 )
  {
    v8 = 0;
  }
  else if ( ((unsigned int)sysfs_streq(a3, "tmc-sg") & v7 & 1) != 0 )
  {
    v8 = 1;
  }
  else
  {
    sysfs_streq(a3, "catu");
    if ( (sysfs_streq(a3, "auto") & 1) == 0 )
      return -22;
    v8 = 3;
  }
  *(_DWORD *)(v6 + 208) = v8;
  return a4;
}
