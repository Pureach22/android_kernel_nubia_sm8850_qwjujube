__int64 __fastcall sde_encoder_rc_restart_delayed(__int64 result, int a2)
{
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 v5; // x9
  __int64 v6; // x9
  unsigned int v7; // w21
  __int64 v8; // x8
  __int64 v9; // x8
  unsigned int v10; // w6
  unsigned int v11; // w5
  char v12; // w24
  unsigned int v13; // w8
  __int64 v14; // x25
  __int64 v15; // x0
  int v16; // w4
  int v17; // w4
  char v18; // [xsp+0h] [xbp-20h]

  if ( (*(_BYTE *)(result + 4920) & 1) != 0 )
    return result;
  v2 = *(_QWORD *)(result + 328);
  v3 = result;
  if ( v2 && (v5 = *(_QWORD *)(v2 + 8)) != 0 )
  {
    v6 = *(_QWORD *)(v5 + 2512);
    v7 = 58;
    if ( v6 )
    {
      if ( (unsigned int)*(_QWORD *)(v6 + 1472) - 1 < 2 )
        v7 = 1;
      else
        v7 = 58;
    }
  }
  else
  {
    v7 = 58;
  }
  if ( *(_BYTE *)(result + 749) == 1 )
  {
    if ( result && v2 && (v8 = *(_QWORD *)(v2 + 8)) != 0 )
    {
      v9 = *(_QWORD *)(v8 + 4704);
      if ( v9 && *(_BYTE *)(v9 + 28) == 1 )
      {
        v10 = *(_DWORD *)(result + 3944);
        v11 = **(_DWORD **)v9;
        v7 = (v10 + 999) / v10 + (v11 + 999999) / v11;
        if ( v7 < 0x97 )
        {
          v12 = (v10 + 999) / v10 + (v11 + 999999) / v11;
          if ( v7 <= 0x19 )
          {
            v7 = 26;
            result = sde_evtlog_log(
                       sde_dbg_base_evtlog,
                       "_sde_encoder_vrr_min_idle_time",
                       2831,
                       -1,
                       26,
                       v11,
                       v10,
                       60333,
                       239);
            v12 = 26;
          }
        }
        else
        {
          result = sde_evtlog_log(
                     sde_dbg_base_evtlog,
                     "_sde_encoder_vrr_min_idle_time",
                     2827,
                     -1,
                     v11,
                     v10,
                     60333,
                     -1059143953,
                     v18);
          v7 = 150;
          v12 = -106;
        }
        goto LABEL_22;
      }
    }
    else
    {
      result = printk(&unk_23F3C0, "_sde_encoder_vrr_min_idle_time");
    }
    v7 = 0;
  }
  v12 = 0;
LABEL_22:
  v13 = *(_DWORD *)(*(_QWORD *)(v3 + 1360) + 160LL);
  if ( v13 >= 0x11 )
  {
    __break(0x5512u);
    return sde_encoder_cancel_delayed_work(result);
  }
  else
  {
    v14 = *(_QWORD *)(*(_QWORD *)v3 + 56LL) + 80LL * v13;
    v15 = _msecs_to_jiffies(v7);
    kthread_mod_delayed_work(v14 + 1152, v3 + 944, v15);
    if ( v3 )
      v16 = *(_DWORD *)(v3 + 24);
    else
      v16 = -1;
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "sde_encoder_rc_restart_delayed",
               2874,
               -1,
               v16,
               a2,
               *(_DWORD *)(v3 + 888),
               v7,
               v12);
    if ( (_drm_debug & 4) != 0 )
    {
      if ( v3 )
        v17 = *(_DWORD *)(v3 + 24);
      else
        v17 = -1;
      return _drm_dev_dbg(0, 0, 0, "enc%d sw_event:%d, work scheduled\n", v17, a2);
    }
  }
  return result;
}
