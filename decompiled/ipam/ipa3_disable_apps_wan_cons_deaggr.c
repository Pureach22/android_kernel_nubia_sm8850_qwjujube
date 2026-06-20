__int64 ipa3_disable_apps_wan_cons_deaggr()
{
  if ( !ipa3_ctx )
    return 0xFFFFFFFFLL;
  *(_BYTE *)(ipa3_ctx + 43344) = 1;
  return 0;
}
