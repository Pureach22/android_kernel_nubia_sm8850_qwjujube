__int64 __fastcall ieee80211_tdls_mgmt(
        __int64 a1,
        __int64 a2,
        _WORD *a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        __int64 a8,
        char a9,
        __int64 a10,
        __int64 a11)
{
  __int64 result; // x0
  __int64 v12; // x7
  __int64 v13; // x19
  int v14; // w9
  __int64 v15; // x24
  int v16; // w8
  unsigned int v17; // w19
  __int64 v18; // x20
  _WORD *v19; // x21
  unsigned int v20; // w23
  unsigned int v21; // w24
  unsigned int v22; // w22
  unsigned int v23; // w22
  _WORD *v24; // x25
  unsigned int v25; // w23
  unsigned int v26; // w21
  __int64 v27; // x20
  unsigned __int64 v28; // x26
  __int64 v29; // x26
  int v30; // w9

  if ( (*(_BYTE *)(a1 + 101) & 0x80) == 0 )
    return 4294967201LL;
  if ( *(_DWORD *)(a2 + 7408) != 2 || (*(_BYTE *)(a2 + 5165) & 8) == 0 )
    return 4294967274LL;
  v12 = a10;
  result = 4294967201LL;
  if ( (unsigned __int8)a5 > 2u )
  {
    if ( (unsigned __int8)a5 == 3 )
    {
      ieee80211_tdls_mgmt_teardown(a2, a3, a4, 3, a6, a7, a9 & 1, a10, a11);
      return 0;
    }
    v17 = a7;
    if ( (unsigned __int8)a5 == 10 )
    {
      v18 = a2;
      v19 = a3;
      v20 = a6;
      v21 = a4;
      v22 = a5;
      drv_mgd_protect_tdls_discover(*(_QWORD *)(a2 + 4304), a2 + 2688, a4);
      v12 = a10;
      a5 = v22;
      a3 = v19;
      a4 = v21;
      a6 = v20;
      a2 = v18;
    }
    else if ( (unsigned __int8)a5 != 14 )
    {
      return result;
    }
    return ieee80211_tdls_prep_mgmt_packet(a2, a3, a4, a5, a6, v17, a9 & 1, v12, a11);
  }
  if ( (unsigned __int8)a5 >= 2u )
  {
    v17 = a7;
    if ( (unsigned __int8)a5 != 2 )
      return result;
    return ieee80211_tdls_prep_mgmt_packet(a2, a3, a4, a5, a6, v17, a9 & 1, v12, a11);
  }
  if ( *(_DWORD *)(a2 + 6852) > 1u )
    return result;
  v13 = a2 + 5330;
  v14 = *(unsigned __int16 *)(a2 + 5334);
  v15 = *(_QWORD *)(a2 + 4304);
  v16 = *(_DWORD *)(a2 + 5330);
  if ( v16 | v14 && *(_DWORD *)a3 ^ v16 | (unsigned __int16)a3[2] ^ v14 )
    return 4294967280LL;
  v23 = a5;
  v24 = a3;
  v25 = a4;
  v26 = a6;
  if ( !(_WORD)a7 )
  {
    v27 = a2;
    _rcu_read_lock(4294967201LL, a2);
    v28 = sta_info_get(v27 + 2688, v24);
    _rcu_read_unlock(v28);
    a2 = v27;
    if ( !v28 )
      return 4294967229LL;
  }
  v29 = a2;
  ieee80211_flush_queues(v15, a2 + 2688, 0);
  v30 = *(_DWORD *)v24;
  *(_WORD *)(v13 + 4) = v24[2];
  *(_DWORD *)v13 = v30;
  result = ieee80211_tdls_prep_mgmt_packet(v29, v24, v25, v23, v26, a7, a9 & 1, a10, a11);
  if ( (result & 0x80000000) != 0 )
  {
    *(_WORD *)(v13 + 4) = 0;
    *(_DWORD *)v13 = 0;
    return result;
  }
  wiphy_delayed_work_queue(*(_QWORD *)(*(_QWORD *)(v29 + 4304) + 72LL), v29 + 5336, 3750);
  return 0;
}
