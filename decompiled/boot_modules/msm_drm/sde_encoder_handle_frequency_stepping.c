_QWORD *__fastcall sde_encoder_handle_frequency_stepping(
        _QWORD *result,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v8; // x21
  __int64 v9; // x19
  __int64 v11; // x0
  unsigned int v12; // w20
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 vsync_timestamp; // x4
  int v16; // w6
  int v17; // w7
  __int64 v18; // x0
  char v19; // w8
  int v20; // w6
  int v21; // w7
  __int64 v22; // x8
  __int64 v23; // x9
  int v24; // w4
  __int64 v25; // x8
  __int64 v26; // x10
  int v27; // w0
  int v28; // w4
  __int64 v29; // x2
  __int64 v30; // x3
  __int64 v31; // x4
  __int64 v32; // x5
  int v33; // w6
  int v34; // w7
  int v35; // w8
  char v36; // [xsp+0h] [xbp-10h]
  char v37; // [xsp+0h] [xbp-10h]
  char v38; // [xsp+0h] [xbp-10h]

  v8 = *result;
  if ( *(_BYTE *)(*result + 748LL) != 1 )
    return result;
  v9 = (__int64)result;
  if ( !*(_DWORD *)(result[1] + 4688LL) || *(_QWORD **)(v8 + 328) != result )
    return result;
  v11 = sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_encoder_handle_frequency_stepping",
          6552,
          -1,
          *(_DWORD *)(v8 + 3944),
          -1059143953,
          a7,
          a8,
          v36);
  v12 = *(_DWORD *)(v8 + 3944);
  if ( a2 )
  {
    v13 = ktime_get(v11);
    v14 = *(_QWORD *)v9;
    *(_QWORD *)(v9 + 2376) = v13;
    vsync_timestamp = sde_encoder_calc_last_vsync_timestamp(v14);
    *(_QWORD *)(v9 + 2368) = vsync_timestamp;
  }
  else
  {
    v18 = sde_encoder_calc_last_vsync_timestamp(*(_QWORD *)v9);
    v19 = *(_BYTE *)(v9 + 2354);
    vsync_timestamp = v18;
    *(_QWORD *)(v9 + 2368) = v18;
    if ( (v19 & 1) == 0 )
    {
      vsync_timestamp = *(_QWORD *)(v9 + 2384);
      goto LABEL_9;
    }
  }
  *(_QWORD *)(v9 + 2384) = vsync_timestamp;
LABEL_9:
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_phys_update_last_image",
    6425,
    -1,
    vsync_timestamp,
    -1059143953,
    v16,
    v17,
    v37);
  v22 = *(_QWORD *)(v9 + 8);
  *(_BYTE *)(v9 + 2354) = 0;
  v23 = *(_QWORD *)(v9 + 2408);
  v24 = *(_DWORD *)(v22 + 4688);
  *(_DWORD *)(v9 + 2364) = v24;
  v25 = *(_QWORD *)(v22 + 4704);
  if ( a2 && v25 && v23 )
  {
    if ( *(_DWORD *)(v25 + 12) != *(_DWORD *)(v23 + 12) || *(_DWORD *)(v25 + 20) != *(_DWORD *)(v23 + 20) )
    {
      v26 = *(_QWORD *)v9;
      v27 = sde_dbg_base_evtlog;
      *(_QWORD *)(v9 + 2408) = v25;
      if ( v26 )
        v28 = *(_DWORD *)(v26 + 24);
      else
        v28 = -1;
      sde_evtlog_log(
        v27,
        "sde_encoder_phys_update_curr_freq_pattern",
        6448,
        -1,
        v28,
        *(_DWORD *)(v25 + 12),
        *(_DWORD *)(v23 + 12),
        *(_DWORD *)(v25 + 20),
        *(_DWORD *)(v23 + 20));
      v24 = *(_DWORD *)(v9 + 2364);
    }
  }
  else if ( !v23 )
  {
    *(_QWORD *)(v9 + 2408) = v25;
  }
  result = (_QWORD *)sde_evtlog_log(
                       sde_dbg_base_evtlog,
                       "sde_encoder_phys_update_curr_freq_pattern",
                       6454,
                       -1,
                       v24,
                       -1059143953,
                       v20,
                       v21,
                       v38);
  if ( *(_BYTE *)(v8 + 751) == 1 )
  {
    if ( *(_BYTE *)(v9 + 2352) == 1 )
    {
      if ( a2 )
      {
        if ( *(_WORD *)(v9 + 2356) == 1 )
        {
          sde_encoder_handle_collision_prior_EPT(v9);
          result = (_QWORD *)hrtimer_start_range_ns(v9 + 2480, *(_QWORD *)(v9 + 2392), 0, 1);
        }
      }
      v35 = *(unsigned __int16 *)(v9 + 2356);
      if ( v35 != 3 )
      {
        if ( v35 != 2 )
          return result;
        *(_WORD *)(v9 + 2356) = 3;
      }
      sde_encoder_phys_arp_sw_timer_frequency_stepping(v9, 0);
      return (_QWORD *)hrtimer_start_range_ns(v9 + 2480, 0x3B9ACA00 / v12, 0, 1);
    }
    if ( *(_BYTE *)(v9 + 2353) == 1 )
      return (_QWORD *)sde_encoder_phys_arp_sw_timer_frequency_stepping(v9, a2);
  }
  else if ( *(_BYTE *)(v8 + 749) == 1 )
  {
    return (_QWORD *)sde_encoder_handle_self_refresh_video_psr(v9, a2, v29, v30, v31, v32, v33, v34);
  }
  else if ( *(_BYTE *)(v8 + 748) == 1 )
  {
    return (_QWORD *)sde_encoder_handle_collision_prior_EPT(v9);
  }
  return result;
}
