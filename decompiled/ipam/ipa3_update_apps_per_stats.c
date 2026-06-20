__int64 ipa3_update_apps_per_stats()
{
  _DWORD *v0; // x8

  if ( *(_DWORD *)(ipa3_ctx + 32256) <= 1u )
  {
    v0 = *(_DWORD **)(ipa3_ctx + 51432);
    v0[3] = 0;
    v0[5] = 0;
    v0[7] = 0;
  }
  return 0;
}
