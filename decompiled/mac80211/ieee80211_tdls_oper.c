__int64 __fastcall ieee80211_tdls_oper(__int64 a1, __int64 a2, unsigned __int16 *a3, unsigned int a4)
{
  __int64 result; // x0
  __int64 v6; // x21
  __int64 v7; // x20
  __int64 v8; // x22
  unsigned __int64 v9; // x20
  _DWORD **v10; // x9
  __int64 v11; // x8
  unsigned __int64 v12; // x0
  int v13; // w10
  __int64 v14; // x9
  __int64 v15; // x19
  unsigned __int64 v22; // x9

  if ( (*(_BYTE *)(a1 + 101) & 0x80) == 0 )
    return 4294967201LL;
  if ( *(_DWORD *)(a2 + 7408) != 2 )
    return 4294967274LL;
  if ( a4 < 3 )
    return 4294967201LL;
  v6 = a2 + 5330;
  if ( a4 != 4 )
  {
    if ( a4 == 3 )
    {
      if ( (*(_BYTE *)(a2 + 8326) & 1) != 0 )
        return 4294967280LL;
      v8 = a2;
      v12 = sta_info_get(a2 + 2688, a3);
      if ( !v12 )
        return 4294967229LL;
      v9 = v12;
      iee80211_tdls_recalc_chanctx(v8 + 2688, v12);
      iee80211_tdls_recalc_ht_protection(v8 + 2688, v9);
      goto LABEL_26;
    }
    return 4294967201LL;
  }
  v7 = *(_QWORD *)(a2 + 4304);
  v8 = a2;
  tasklet_kill(v7 + 2384);
  ieee80211_flush_queues(v7, v8 + 2688, 0);
  v9 = (unsigned int)sta_info_destroy_addr(v8 + 2688, a3);
  iee80211_tdls_recalc_ht_protection(v8 + 2688, 0);
  v10 = *(_DWORD ***)(v8 + 8328);
  v11 = v8;
  if ( !v10 )
  {
LABEL_14:
    result = (unsigned int)v9;
    if ( (_DWORD)v9 )
      return result;
    goto LABEL_21;
  }
  if ( **v10 < 6u )
  {
    ((void (__fastcall *)(_QWORD, _DWORD **))ieee80211_recalc_chanctx_chantype)(*(_QWORD *)(v8 + 4304), v10 - 19);
    v11 = v8;
    goto LABEL_14;
  }
  __break(0x5512u);
LABEL_26:
  _X8 = (unsigned __int64 *)(v9 + 216);
  __asm { PRFM            #0x11, [X8] }
  do
    v22 = __ldxr(_X8);
  while ( __stxr(v22 | 0x1000, _X8) );
  v13 = *(unsigned __int16 *)(v8 + 5334);
  v11 = v8;
  if ( !(*(_DWORD *)v6 | v13) || *(_DWORD *)a3 ^ *(_DWORD *)v6 | a3[2] ^ v13 )
    __break(0x800u);
LABEL_21:
  v14 = *(_QWORD *)(v11 + 4304);
  if ( !(*(_DWORD *)a3 ^ *(_DWORD *)v6 | a3[2] ^ *(unsigned __int16 *)(v11 + 5334)) )
  {
    v15 = v11;
    wiphy_delayed_work_cancel(*(_QWORD *)(v14 + 72), v11 + 5336);
    v14 = *(_QWORD *)(v15 + 4304);
    v11 = v15;
    *(_WORD *)(v6 + 4) = 0;
    *(_DWORD *)v6 = 0;
  }
  wiphy_work_queue(*(_QWORD *)(v14 + 72), v11 + 7096);
  return 0;
}
