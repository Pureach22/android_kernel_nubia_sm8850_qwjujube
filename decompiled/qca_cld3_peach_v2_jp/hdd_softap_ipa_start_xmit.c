__int64 hdd_softap_ipa_start_xmit()
{
  ((void (*)(void))hdd_softap_hard_start_xmit)();
  return 0;
}
