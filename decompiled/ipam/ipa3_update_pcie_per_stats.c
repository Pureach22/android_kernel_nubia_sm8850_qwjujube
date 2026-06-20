__int64 ipa3_update_pcie_per_stats()
{
  __int64 v1; // x8

  if ( !*(_DWORD *)(ipa3_ctx + 32256) )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 51432);
    *(_DWORD *)(v1 + 36) = 0;
    *(_DWORD *)(v1 + 44) = 0;
    *(_DWORD *)(v1 + 52) = 0;
    *(_QWORD *)(v1 + 60) = 0;
  }
  return 0;
}
