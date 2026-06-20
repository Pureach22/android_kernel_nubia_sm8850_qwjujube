__int64 __fastcall sde_encoder_handle_self_refresh_video_psr(
        __int64 result,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v8; // x9
  __int64 v9; // x9
  __int64 v10; // x8
  __int64 v11; // x9
  int v12; // w0
  int v13; // w5
  _DWORD **v14; // x9
  __int64 v15; // x20
  __int64 v16; // x19
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a2 )
  {
    v8 = *(_QWORD *)(*(_QWORD *)result + 328LL);
    if ( v8 )
    {
      v9 = *(_QWORD *)(v8 + 8);
      if ( v9 )
      {
        if ( *(_DWORD *)(v9 + 4720) == 3 )
          return sde_evtlog_log(
                   sde_dbg_base_evtlog,
                   "sde_encoder_handle_self_refresh_video_psr",
                   6516,
                   -1,
                   13107,
                   -1059143953,
                   a7,
                   a8,
                   vars0);
      }
    }
    v10 = *(_QWORD *)(*(_QWORD *)result + 1360LL);
    v11 = *(_QWORD *)(v10 + 2008);
    if ( !v11 || *(_DWORD *)(v11 + 1568) != 1 )
    {
      if ( v10 )
      {
        if ( !*(_DWORD *)(v10 + 4712) || *(_WORD *)(result + 2608) == 1 )
        {
          v12 = sde_dbg_base_evtlog;
          v13 = *(_DWORD *)(v10 + 4712);
          return sde_evtlog_log(
                   v12,
                   "sde_encoder_handle_self_refresh_video_psr",
                   6528,
                   -1,
                   17476,
                   v13,
                   -1059143953,
                   a8,
                   vars0);
        }
      }
      else if ( *(_WORD *)(result + 2608) == 1 )
      {
        v13 = -22;
        v12 = sde_dbg_base_evtlog;
        return sde_evtlog_log(
                 v12,
                 "sde_encoder_handle_self_refresh_video_psr",
                 6528,
                 -1,
                 17476,
                 v13,
                 -1059143953,
                 a8,
                 vars0);
      }
      v14 = *(_DWORD ***)(result + 2408);
      *(_WORD *)(result + 2608) = 2;
      v15 = result;
      v16 = 1000 * (0x3B9ACA00u / **v14) - 3666666LL;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_encoder_handle_self_refresh_video_psr",
        6536,
        -1,
        SHIDWORD(v16),
        1000 * (0x3B9ACA00u / **v14) - 3666666,
        -1059143953,
        a8,
        vars0);
      return hrtimer_start_range_ns(v15 + 2544, v16, 0, 1);
    }
  }
  return result;
}
