__int64 __fastcall dbglog_sta_powersave_print_handler(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int *a6)
{
  __int64 result; // x0
  __int64 v7; // x8
  const char *v8; // x8
  const char *v9; // x8
  __int64 v10; // x4
  __int64 v11; // x8
  char **v12; // x8
  int v13; // w9
  char *v14; // x8
  __int64 v15; // x9
  const char *v16; // x9
  unsigned int v17; // w11
  int v18; // w7
  int v19; // w10
  const char *v20; // x11
  __int64 v21; // x4
  unsigned int v22; // w8
  __int64 v23; // x5
  bool v24; // zf
  const char *v25; // x8
  __int64 v26; // x9
  const char *v27; // x4
  const char *v28; // x6

  result = 0;
  if ( a3 <= 4 )
  {
    if ( a3 > 2 )
    {
      if ( a3 == 3 )
      {
        if ( (unsigned __int16)a5 == 5 )
        {
          v17 = a6[4];
          v18 = HIWORD(v17);
          v19 = BYTE1(v17);
          if ( (v17 & 0xFC) != 0 )
          {
            v20 = "RSP_TIMEOUT";
            if ( (unsigned __int8)a6[4] != 4 )
              v20 = "UNKNOWN";
          }
          else
          {
            v20 = off_A2AA48[v17 & 3];
          }
          dbglog_printf(
            a4,
            a2,
            "STA PS poll: queue=%u comp=%u rsp=%u rsp_dur=%u fc=%x qos=%x %s",
            *a6,
            a6[1],
            a6[2],
            a6[3],
            v18,
            v19,
            v20);
        }
      }
      else if ( (unsigned __int16)a5 == 1 )
      {
        v9 = "DISABLED";
        if ( *a6 )
          v9 = "ENABLED";
        dbglog_printf(a4, a2, "STA PS COEX MODE %s", v9);
      }
    }
    else if ( a3 == 1 )
    {
      if ( (unsigned __int16)a5 == 4 )
      {
        v15 = *a6;
        if ( (unsigned int)v15 > 0x35 )
          v16 = "UNKNOWN";
        else
          v16 = off_A2A860[v15];
        if ( a6[3] )
          v28 = "SLEEP";
        else
          v28 = "WAKE";
        dbglog_printf(a4, a2, "PM ARB request flags=%x, last_time=%x %s: %s", a6[1], a6[2], v16, v28);
      }
    }
    else
    {
      if ( a3 != 2 )
        return result;
      if ( (unsigned __int16)a5 == 2 )
      {
        v7 = *a6;
        if ( (unsigned int)v7 >= 3 )
        {
          v24 = (_DWORD)v7 == 3;
          v8 = "AWAKE";
          if ( !v24 )
            v8 = "UNKNOWN";
        }
        else
        {
          v8 = off_A2AA10[v7];
        }
        v26 = a6[1];
        if ( (unsigned int)v26 >= 4 )
        {
          if ( (_DWORD)v26 == 4 )
            v27 = "PSPOLL_UAPSD_BUSY_TIMEOUT";
          else
            v27 = "UNKNOWN";
        }
        else
        {
          v27 = off_A2AA28[v26];
        }
        dbglog_printf(a4, a2, "STA PS: %s %s", v8, v27);
      }
    }
  }
  else if ( a3 <= 6 )
  {
    if ( a3 == 5 )
    {
      if ( (unsigned __int16)a5 == 3 )
      {
        v22 = *a6;
        v21 = a6[1];
        v23 = a6[2];
        v24 = v22 == 0;
        v25 = "DISALLOW";
        if ( !v24 )
          v25 = "ALLOW";
        dbglog_printf(a4, a2, "STA PS-Poll %s flags=%x time=%u", v25, v21, v23);
      }
    }
    else if ( (unsigned __int16)a5 == 2 )
    {
      v11 = *a6;
      v10 = a6[1];
      if ( (unsigned int)v11 > 0xF )
      {
        dbglog_printf(a4, a2, "STA PS SET_PARAM %x => %#x", v11, v10);
      }
      else
      {
        if ( ((16 * v11) | 8uLL) > 0x100 )
        {
          __break(1u);
          return dbglog_ap_powersave_print_handler(0);
        }
        v12 = &(&off_A29ED8)[2 * v11];
        v13 = *((_DWORD *)v12 + 2);
        v14 = *v12;
        if ( v13 )
          dbglog_printf(a4, a2, "STA PS SET_PARAM %s => %u (us)", v14, v10);
        else
          dbglog_printf(a4, a2, "STA PS SET_PARAM %s => %#x", v14, v10);
      }
    }
  }
  else
  {
    switch ( a3 )
    {
      case 7:
        dbglog_printf(a4, a2, "SPEC Poll Timer Started: Beacon time Remaining:%d wakeup interval:%d", *a6, a6[1]);
        break;
      case 8:
        dbglog_printf(a4, a2, "SPEC Poll Timer Stopped");
        break;
      case 1000:
        dbglog_sm_print(
          a4,
          a2,
          a5,
          a6,
          "STA PS",
          dbglog_sta_powersave_print_handler_states,
          13,
          dbglog_sta_powersave_print_handler_events,
          19);
        break;
      default:
        return result;
    }
  }
  return 1;
}
