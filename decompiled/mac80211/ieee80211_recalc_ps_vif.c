__int64 __fastcall ieee80211_recalc_ps_vif(__int64 result, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  __int64 v4; // x21
  __int64 v5; // x0
  __int64 v6; // x19

  v2 = result + 4096;
  if ( *(_BYTE *)(result + 2496) == 1
    && (*(_BYTE *)(result + 2497) & 1) == 0
    && (*(_BYTE *)(result + 2477) & 8) != 0
    && (*(_BYTE *)(result + 2500) & 2) == 0
    && ((*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(result + 1616) + 72LL) + 100LL) & 2) != 0 || *(_BYTE *)(result + 4179) == 1) )
  {
    v3 = result;
    _rcu_read_lock(result, a2);
    v4 = v3;
    v5 = sta_info_get(v3, v3 + 4802);
    if ( v5 )
      v6 = (*(_QWORD *)(v5 + 216) >> 3) & 1LL;
    else
      LODWORD(v6) = 0;
    _rcu_read_unlock(v5);
    result = v4;
  }
  else
  {
    LODWORD(v6) = 0;
  }
  if ( *(unsigned __int8 *)(v2 + 635) != (_DWORD)v6 )
  {
    *(_BYTE *)(v2 + 635) = v6;
    return ieee80211_vif_cfg_change_notify(result, 0x20000);
  }
  return result;
}
