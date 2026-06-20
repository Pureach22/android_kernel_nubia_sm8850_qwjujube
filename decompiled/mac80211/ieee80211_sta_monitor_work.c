void __fastcall ieee80211_sta_monitor_work(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x19
  int v4; // w8

  if ( *(_WORD *)(a2 + 3416) )
  {
    __break(0x800u);
  }
  else if ( (*(_QWORD *)(a2 - 752) & 1) != 0 && (*(_BYTE *)(a2 + 93) & 8) != 0 )
  {
    v2 = *(_QWORD *)(a2 - 768);
    if ( !*(_QWORD *)(v2 + 4976) && !*(_QWORD *)(v2 + 4696) )
    {
      v3 = a2 - 2384;
      if ( *(_BYTE *)(v2 + 1466) == 1 )
      {
        ieee80211_reset_ap_probe(a2 - 2384);
      }
      else
      {
        v4 = *(_DWORD *)(a2 + 116);
        *(_DWORD *)(a2 + 116) = v4 | 2;
        if ( (v4 & 2) == 0 )
        {
          ieee80211_recalc_ps(v2, a2);
          *(_DWORD *)(a2 + 88) = 0;
          ieee80211_mgd_probe_ap_send(v3);
        }
      }
    }
  }
}
