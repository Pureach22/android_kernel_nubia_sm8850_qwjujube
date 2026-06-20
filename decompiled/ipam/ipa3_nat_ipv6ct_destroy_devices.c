__int64 ipa3_nat_ipv6ct_destroy_devices()
{
  __int64 result; // x0

  result = ipa3_nat_ipv6ct_destroy_device(ipa3_ctx + 29528);
  if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0xEu )
    return ipa3_nat_ipv6ct_destroy_device(ipa3_ctx + 30080);
  return result;
}
