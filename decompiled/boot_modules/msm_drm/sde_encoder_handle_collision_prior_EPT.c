__int64 __fastcall sde_encoder_handle_collision_prior_EPT(__int64 *a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x23
  unsigned __int64 v5; // x22
  __int64 result; // x0
  int v7; // w7
  unsigned __int64 v8; // x24
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  int v13; // w6
  int v14; // w7
  __int64 v15; // x8
  bool v16; // w9
  int v17; // w0
  __int64 v18; // x20
  char v19; // [xsp+0h] [xbp-10h]
  char v20; // [xsp+0h] [xbp-10h]

  v2 = 0x3B9ACA00u / *(_DWORD *)(*a1 + 3944);
  v3 = 0x3B9ACA00u / *(_DWORD *)(*a1 + 4812);
  v4 = 1000 * (0x3B9ACA00u / *((_DWORD *)a1 + 591));
  v5 = ktime_get(a1);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "frame_inteval %llu nom %llu avrstep %llu curr %llu last_commit_ept %llu\n",
      v4,
      v2,
      v3,
      v5,
      a1[297]);
  result = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_encoder_handle_collision_prior_EPT",
             6474,
             -1,
             v4,
             v2,
             v3,
             v5,
             a1[297]);
  v8 = a1[297];
  if ( v5 <= v8 + 44000000 )
  {
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_handle_collision_prior_EPT",
      6479,
      -1,
      a1[297],
      SHIDWORD(v8),
      -1059143953,
      v7,
      v19);
    v15 = a1[297];
    if ( v8 - v15 >= 0x29F6300 )
      return hrtimer_cancel(a1 + 318);
    v16 = 0;
    do
    {
      v8 += v4;
      if ( v8 > v5 )
      {
        v17 = sde_encoder_check_collision(a1, v8, v9, v10, v11, v12, v13, v14);
        v15 = a1[297];
        v16 = v17 != 0;
      }
    }
    while ( v8 - v15 < 0x29F6300 );
    if ( v16 )
    {
      _ReadStatusReg(SP_EL0);
      v18 = v8 - (v2 + v3 + v5) - 1000000;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_encoder_handle_collision_prior_EPT",
        6492,
        -1,
        1,
        SHIDWORD(v18),
        v18,
        -1059143953,
        v20);
      return hrtimer_start_range_ns(a1 + 318, v18, 0, 1);
    }
    else
    {
      return hrtimer_cancel(a1 + 318);
    }
  }
  return result;
}
