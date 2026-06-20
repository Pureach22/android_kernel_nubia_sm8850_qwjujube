__int64 __fastcall ieee80211_sta_conn_mon_timer(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x8
  __int64 v4; // x0

  if ( *(_WORD *)(result + 3496) )
  {
    __break(0x800u);
  }
  else
  {
    v1 = result;
    v2 = *(_QWORD *)(result - 688);
    if ( *(_BYTE *)(result + 3334) != 1 || *(_BYTE *)(result + 2096) == 1 )
    {
      result = sta_info_get(result - 2304, result + 2498);
      if ( result )
      {
        v3 = *(_QWORD *)(result + 2304);
        if ( v3 - *(_QWORD *)(result + 1760) < 0 )
          v3 = *(_QWORD *)(result + 1760);
        if ( jiffies - (v3 + 7500) < 0 )
        {
          v4 = round_jiffies_up(v3 + 7500);
          return mod_timer(v1, v4);
        }
        else
        {
          return wiphy_work_queue(*(_QWORD *)(v2 + 72), v1 + 80);
        }
      }
    }
  }
  return result;
}
