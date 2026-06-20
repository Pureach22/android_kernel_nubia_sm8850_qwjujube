__int64 __fastcall ieee80211_run_deferred_scan(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x21
  __int64 v3; // x19
  __int64 *v4; // x8
  unsigned __int64 v5; // x11
  __int64 v6; // x12
  bool v7; // cf
  __int64 v8; // x19
  __int64 v9; // x0

  if ( *(_QWORD *)(result + 4752) && !*(_QWORD *)(result + 4696) )
  {
    v1 = *(_QWORD *)(result + 4968);
    v2 = result;
    v3 = *(_QWORD *)(v1 + 1616);
    result = ieee80211_is_radar_required(v3);
    if ( (result & 1) == 0 )
      goto LABEL_15;
    result = regulatory_pre_cac_allowed(*(_QWORD *)(v3 + 72));
    if ( (result & 1) == 0 )
      return result;
    v4 = *(__int64 **)(v3 + 4616);
    if ( v4 == (__int64 *)(v3 + 4616) )
    {
LABEL_15:
      if ( *(_QWORD *)(v2 + 5264) == v2 + 5264 && (*(_DWORD *)(v1 + 4720) != 2 || (*(_BYTE *)(v1 + 2500) & 2) == 0) )
      {
        v8 = *(_QWORD *)(v2 + 72);
        v9 = round_jiffies_relative(0);
        return wiphy_delayed_work_queue(v8, v2 + 4896, v9);
      }
    }
    else
    {
LABEL_7:
      v5 = 0;
      v6 = 57;
      while ( *((_WORD *)v4 + 744) && ((*((unsigned __int16 *)v4 + 744) >> v5) & 1) == 0 || (v4[v6] & 1) == 0 )
      {
        if ( *((_WORD *)v4 + 744) )
        {
          v7 = v5++ >= 0xE;
          v6 += 9;
          if ( !v7 )
            continue;
        }
        v4 = (__int64 *)*v4;
        if ( v4 != (__int64 *)(v3 + 4616) )
          goto LABEL_7;
        goto LABEL_15;
      }
    }
  }
  return result;
}
