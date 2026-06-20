__int64 __fastcall wlan_hdd_debugfs_csr_deinit(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 result; // x0

  v1 = a1 + 49152;
  v2 = *(_QWORD *)(a1 + 52344);
  if ( v2 )
  {
    *(_QWORD *)(v1 + 3192) = 0;
    debugfs_remove(v2);
  }
  result = *(_QWORD *)(v1 + 3240);
  if ( result )
  {
    *(_QWORD *)(v1 + 3240) = 0;
    return debugfs_remove(result);
  }
  return result;
}
