__int64 __fastcall dp_mon_reap_timer_handler(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  unsigned int multiplier; // w0

  v1 = *(_QWORD *)(a1 + 20056);
  dp_service_mon_rings(a1, 0x40u);
  v2 = jiffies;
  multiplier = qdf_timer_get_multiplier();
  return mod_timer(v1 + 264, v2 + 2LL * multiplier);
}
