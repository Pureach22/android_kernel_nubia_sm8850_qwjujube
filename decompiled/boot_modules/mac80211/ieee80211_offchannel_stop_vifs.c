__int64 __fastcall ieee80211_offchannel_stop_vifs(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x21
  int v4; // w8
  __int64 v5; // x20
  unsigned __int64 v12; // x9
  unsigned __int64 v15; // x9

  if ( (*(_BYTE *)(result + 1400) & 1) != 0 )
  {
    v1 = result;
    ieee80211_stop_queues_by_reason(result, 0xFFFF, 6, 0);
    result = ieee80211_flush_queues(v1, 0, 0);
    v2 = *(_QWORD *)(v1 + 4616);
    v3 = v1 + 4616;
    if ( v2 != v1 + 4616 )
    {
      while ( 1 )
      {
        if ( (*(_QWORD *)(v2 + 1632) & 1) != 0 )
        {
          v4 = *(_DWORD *)(v2 + 4720);
          if ( v4 == 6 )
            goto LABEL_11;
          if ( v4 != 10 && v4 != 12 )
            break;
        }
LABEL_5:
        v2 = *(_QWORD *)v2;
        if ( v2 == v3 )
          return result;
      }
      _X8 = (unsigned __int64 *)(v2 + 1632);
      __asm { PRFM            #0x11, [X8] }
      do
        v12 = __ldxr(_X8);
      while ( __stxr(v12 | 2, _X8) );
LABEL_11:
      if ( *(_BYTE *)(v2 + 4856) == 1 )
      {
        _X8 = (unsigned __int64 *)(v2 + 1632);
        __asm { PRFM            #0x11, [X8] }
        do
          v15 = __ldxr(_X8);
        while ( __stxr(v15 | 4, _X8) );
        *(_BYTE *)(v2 + 4856) = 0;
        result = ieee80211_link_info_change_notify(v2, v2 + 3616, 512);
      }
      if ( *(_DWORD *)(v2 + 4720) == 2 && (*(_BYTE *)(v2 + 2477) & 8) != 0 )
      {
        v5 = *(_QWORD *)(v2 + 1616);
        timer_delete_sync(v5 + 5064);
        timer_delete_sync(v2 + 2344);
        timer_delete_sync(v2 + 2304);
        wiphy_work_cancel(*(_QWORD *)(v5 + 72), v5 + 5016);
        if ( (*(_DWORD *)v5 & 2) == 0
          || (*(_DWORD *)v5 &= ~2u, result = ieee80211_hw_config(v5, 16), (*(_QWORD *)(v5 + 96) & 0x200) == 0) )
        {
          result = ieee80211_send_nullfunc(v5, v2, 1);
        }
      }
      goto LABEL_5;
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
