__int64 ipa3_update_eth_per_stats()
{
  __int64 v1; // x8

  if ( !*(_DWORD *)(ipa3_ctx + 32256) )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 51432);
    *(_DWORD *)(v1 + 128) = 0;
    *(_DWORD *)(v1 + 136) = 0;
  }
  return 0;
}
