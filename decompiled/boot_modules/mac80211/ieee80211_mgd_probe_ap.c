__int64 __fastcall ieee80211_mgd_probe_ap(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  int v4; // w8
  __int64 v5; // x19

  if ( *(_WORD *)(result + 5800) )
  {
    __break(0x800u);
  }
  else if ( (*(_QWORD *)(result + 1632) & 1) != 0 && (*(_BYTE *)(result + 2477) & 8) != 0 )
  {
    v2 = *(_QWORD *)(result + 1616);
    if ( !*(_QWORD *)(v2 + 4976) && !*(_QWORD *)(v2 + 4696) )
    {
      if ( *(_BYTE *)(v2 + 1466) == 1 )
      {
        return ieee80211_reset_ap_probe(result);
      }
      else
      {
        if ( (a2 & 1) != 0 )
        {
          v3 = result;
          ieee80211_cqm_beacon_loss_notify(result + 4720);
          result = v3;
        }
        v4 = *(_DWORD *)(result + 2500);
        *(_DWORD *)(result + 2500) = v4 | 2;
        if ( (v4 & 2) == 0 )
        {
          v5 = result;
          ieee80211_recalc_ps(*(_QWORD *)(result + 1616), a2);
          *(_DWORD *)(v5 + 2472) = 0;
          return ieee80211_mgd_probe_ap_send(v5);
        }
      }
    }
  }
  return result;
}
