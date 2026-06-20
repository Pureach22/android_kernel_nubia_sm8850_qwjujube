__int64 __fastcall ieee80211_reset_ap_probe(__int64 result)
{
  int v1; // w8
  __int64 v2; // x20
  __int64 v3; // x19
  __int64 v4; // x1
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0

  v1 = *(_DWORD *)(result + 2500);
  if ( (v1 & 2) != 0 )
  {
    v2 = *(_QWORD *)(result + 1616);
    v3 = result;
    *(_DWORD *)(result + 2500) = v1 & 0xFFFFFFFD;
    ieee80211_run_deferred_scan(v2);
    result = ieee80211_recalc_ps(v2, v4);
    v5 = *(_QWORD *)(v3 + 1616);
    if ( (*(_QWORD *)(v5 + 96) & 0x20000) == 0 )
    {
      if ( (*(_BYTE *)(v3 + 5872) & 1) == 0 && (*(_QWORD *)(v5 + 96) & 0x20000) == 0 )
      {
        v6 = round_jiffies_up(*(_QWORD *)(v3 + 2456) + jiffies);
        mod_timer(v3 + 2344, v6);
      }
      v7 = round_jiffies_up(jiffies + 7500LL);
      return mod_timer(v3 + 2304, v7);
    }
  }
  return result;
}
