__int64 __fastcall ieee80211_mgd_probe_ap_send(__int64 result)
{
  int v1; // w9
  __int64 v2; // x19
  unsigned __int8 v3; // w8
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x1
  __int64 v8; // x0
  int v9; // w9
  int v10; // w8
  __int64 v11; // x20
  __int64 v12; // x1

  if ( *(_WORD *)(result + 5800) )
  {
    __break(0x800u);
    return result;
  }
  v1 = *(_DWORD *)(result + 2472);
  v2 = result;
  v3 = max_probe_tries - 3;
  if ( max_probe_tries - 3 <= 1 )
    v3 = 1;
  if ( v1 >= v3 )
    v4 = 0;
  else
    v4 = result + 4802;
  *(_DWORD *)(result + 2472) = v1 + 1;
  if ( v4 )
  {
    v5 = sta_info_get(result, v4);
    if ( v5 )
      ieee80211_check_fast_rx(v5);
    else
      __break(0x800u);
  }
  v6 = *(_QWORD *)(v2 + 1616);
  if ( (*(_QWORD *)(v6 + 96) & 0x10000) == 0 )
  {
    v7 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD, __int64, _QWORD, _QWORD, _QWORD, int))ieee80211_build_probe_req)(
           v2,
           v2 + 5842,
           v4,
           0xFFFFFFFFLL,
           **(_QWORD **)(*(_QWORD *)(v2 + 4560) + 8LL),
           v2 + 4760,
           *(_QWORD *)(v2 + 4792),
           0,
           0,
           1);
    if ( !v7 )
      goto LABEL_19;
    goto LABEL_18;
  }
  *(_BYTE *)(v2 + 2476) = 0;
  v8 = ((__int64 (__fastcall *)(__int64, __int64, __int64, bool))ieee80211_nullfunc_get)(
         v6,
         v2 + 4720,
         0xFFFFFFFFLL,
         (*(_QWORD *)(v6 + 96) & 0x10000000000LL) == 0);
  if ( v8 )
  {
    v9 = *(_DWORD *)(v8 + 40);
    v7 = v8;
    v10 = v9 | 0x12000;
    *(_DWORD *)(v8 + 40) = v9 | 0x12000;
    if ( (*(_QWORD *)(v6 + 96) & 0x10000) != 0 )
    {
      v10 = v9 | 0x12001;
      *(_DWORD *)(v8 + 40) = v9 | 0x12001;
    }
    if ( (*(_BYTE *)(v2 + 2500) & 2) != 0 )
      *(_DWORD *)(v8 + 40) = v10 | 0x20000000;
LABEL_18:
    ieee80211_tx_skb_tid(v2, v7, 7, 0xFFFFFFFFLL);
  }
LABEL_19:
  v11 = jiffies;
  result = _msecs_to_jiffies((unsigned int)probe_wait_ms);
  v12 = result + v11;
  *(_QWORD *)(v2 + 2464) = result + v11;
  if ( !*(_QWORD *)(v2 + 2272) || v12 - *(_QWORD *)(v2 + 2280) < 0 )
    return mod_timer(v2 + 2264, v12);
  return result;
}
