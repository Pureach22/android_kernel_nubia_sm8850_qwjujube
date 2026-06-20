void ipa3_disable_napi_netdev()
{
  __int64 v0; // x0

  if ( *(_BYTE *)(ipa3_ctx + 45390) == 1 )
  {
    v0 = _netif_napi_del(ipa3_ctx + 48128);
    synchronize_net(v0);
  }
}
