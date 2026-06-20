__int64 __fastcall ieee80211_offchannel_return(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x22
  int v4; // w8
  __int64 v5; // x21
  __int64 v6; // x23
  __int64 v7; // x0
  unsigned __int64 v14; // x9
  unsigned __int64 v17; // x8

  if ( (*(_BYTE *)(result + 1400) & 1) != 0 )
  {
    v1 = *(_QWORD *)(result + 4616);
    v2 = result;
    v3 = result + 4616;
    while ( v1 != v3 )
    {
      v4 = *(_DWORD *)(v1 + 4720);
      if ( v4 == 6 )
      {
        if ( (*(_QWORD *)(v1 + 1632) & 1) != 0 )
          goto LABEL_9;
      }
      else if ( v4 != 10 )
      {
        _X8 = (unsigned __int64 *)(v1 + 1632);
        __asm { PRFM            #0x11, [X8] }
        do
          v14 = __ldxr(_X8);
        while ( __stxr(v14 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
        if ( (*(_QWORD *)(v1 + 1632) & 1) != 0 )
        {
LABEL_9:
          if ( *(_DWORD *)(v1 + 4720) == 2 && (*(_BYTE *)(v1 + 2477) & 8) != 0 )
          {
            v5 = *(_QWORD *)(v1 + 1616);
            if ( *(_QWORD *)(v5 + 5008) )
            {
              if ( *(int *)(v5 + 8) >= 1 )
              {
                ieee80211_send_nullfunc(*(_QWORD *)(v1 + 1616), v1, 0);
                v6 = jiffies;
                v7 = _msecs_to_jiffies(*(unsigned int *)(v5 + 8));
                mod_timer(v5 + 5064, v7 + v6);
              }
            }
            else
            {
              ieee80211_send_nullfunc(*(_QWORD *)(v1 + 1616), v1, 0);
            }
            ieee80211_sta_reset_beacon_monitor(v1);
            ieee80211_sta_reset_conn_monitor(v1);
          }
          _X9 = (unsigned __int64 *)(v1 + 1632);
          __asm { PRFM            #0x11, [X9] }
          do
            v17 = __ldxr(_X9);
          while ( __stlxr(v17 & 0xFFFFFFFFFFFFFFFBLL, _X9) );
          __dmb(0xBu);
          if ( (v17 & 4) != 0 )
          {
            *(_BYTE *)(v1 + 4856) = 1;
            ieee80211_link_info_change_notify(v1, v1 + 3616, 512);
          }
        }
      }
      v1 = *(_QWORD *)v1;
    }
    return ieee80211_wake_queues_by_reason(v2, 0xFFFF, 6, 0);
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
