__int64 ipa3_enable_napi_netdev()
{
  __int64 result; // x0

  if ( (*(_BYTE *)(ipa3_ctx + 45390) & 1) != 0 || *(_BYTE *)(ipa3_ctx + 45391) == 1 )
  {
    result = init_dummy_netdev(ipa3_ctx + 45440);
    if ( *(_BYTE *)(ipa3_ctx + 45390) == 1 )
      return netif_napi_add_weight(ipa3_ctx + 45440, ipa3_ctx + 48128, ipa3_lan_poll, 64);
  }
  return result;
}
