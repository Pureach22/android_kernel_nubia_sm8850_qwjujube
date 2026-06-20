__int64 __fastcall ieee80211_dynamic_ps_disable_work(__int64 a1, __int64 a2)
{
  int v3; // w8

  v3 = *(_DWORD *)(a2 - 5040);
  if ( (v3 & 2) != 0 )
  {
    *(_DWORD *)(a2 - 5040) = v3 & 0xFFFFFFFD;
    ieee80211_hw_config(a2 - 5040, 16);
  }
  return ieee80211_wake_queues_by_reason(a2 - 5040, 0xFFFF, 1, 0);
}
