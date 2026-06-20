__int64 ipa_gsi_map_unmap_gsi_msi_addr()
{
  __int64 result; // x0
  __int64 v1; // x1
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0

  result = ipa3_iommu_map(
             (const void *)qword_1F7820,
             *(_QWORD *)(ipa3_ctx + 51248) & 0xFFFFFFFFFFFFF000LL,
             *(_QWORD *)(ipa3_ctx + 51248) & 0xFFFFFFFFFFFFF000LL,
             4096,
             0x13u);
  if ( (_DWORD)result )
  {
    printk(&unk_3DDC9B, "ipa_gsi_map_unmap_gsi_msi_addr");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d iommu mapping failed for gsi_msi_addr\n", "ipa_gsi_map_unmap_gsi_msi_addr", 7879);
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
        ipc_log_string(v4, "ipa %s:%d iommu mapping failed for gsi_msi_addr\n", "ipa_gsi_map_unmap_gsi_msi_addr", 7879);
    }
    v5 = printk(&unk_3AED39, v1);
    __break(0x800u);
    return ipa3_teardown_apps_pipes(v5);
  }
  return result;
}
