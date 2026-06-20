__int64 ipa3_lan_poll()
{
  return ipa3_lan_rx_poll(*(unsigned int *)(ipa3_ctx + 32040), 64);
}
