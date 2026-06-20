__int64 __fastcall ieee80211_reserve_tid(__int64 a1, unsigned __int8 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  unsigned int v5; // w21
  _BYTE *v6; // x23
  int v7; // w8
  __int64 v8; // x20
  unsigned int vif_queues; // w0
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v14; // w0
  __int64 result; // x0
  unsigned __int64 v18; // x9
  unsigned __int64 v24; // x10

  v4 = *(_QWORD *)(a1 - 2608);
  if ( (unsigned int)(*(_DWORD *)(v4 + 4720) - 2) >= 3 || (v5 = a2, a2 >= 8u) )
  {
    __break(0x800u);
    return 4294967274LL;
  }
  else
  {
    v6 = (_BYTE *)(a1 - 1356);
    v7 = *(unsigned __int8 *)(a1 - 1356);
    if ( v7 == a2 )
      return 0;
    if ( v7 == 255 )
    {
      v8 = *(_QWORD *)(v4 + 1616);
      vif_queues = ieee80211_get_vif_queues(v8, *(_QWORD *)(a1 - 2608));
      v11 = ieee80211_stop_queues_by_reason(v8, vif_queues, 9, 1);
      v12 = synchronize_net(v11);
      if ( (*(_QWORD *)(v8 + 96) & 0x80) == 0 )
        goto LABEL_7;
      v12 = a1 - 2688;
      _X8 = (unsigned __int64 *)(a1 - 2472);
      while ( 1 )
      {
        __asm { PRFM            #0x11, [X8] }
        do
          v18 = __ldxr(_X8);
        while ( __stxr(v18 | 0x100, _X8) );
        v12 = _ieee80211_stop_tx_ba_session(v12, v5, 1u);
LABEL_7:
        _X8 = (unsigned __int64 *)ieee802_1d_to_ac[v5];
        if ( (unsigned int)_X8 < 4 )
          break;
        __break(0x5512u);
      }
      _ieee80211_flush_queues(v8, v4, 1LL << *((_BYTE *)_X8 + v4 + 5850), 0);
      *v6 = v5;
      v14 = ieee80211_get_vif_queues(v8, v4);
      ieee80211_wake_queues_by_reason(v8, v14, 9, 1);
      result = 0;
      if ( (*(_QWORD *)(v8 + 96) & 0x80) != 0 )
      {
        _X8 = (unsigned __int64 *)(a1 - 2472);
        __asm { PRFM            #0x11, [X8] }
        do
          v24 = __ldxr(_X8);
        while ( __stxr(v24 & 0xFFFFFFFFFFFFFEFFLL, _X8) );
        return 0;
      }
    }
    else
    {
      printk(&unk_BC9F6, v4 + 1640, a3, a4);
      return 4294967182LL;
    }
  }
  return result;
}
