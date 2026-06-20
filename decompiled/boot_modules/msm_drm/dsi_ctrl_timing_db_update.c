__int64 __fastcall dsi_ctrl_timing_db_update(__int64 a1, char a2, unsigned int a3)
{
  __int64 v7; // x0
  __int64 v8; // x8
  _DWORD *v9; // x8
  unsigned int v10; // w20

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid dsi_ctrl\n", "inv");
    return 4294967274LL;
  }
  if ( *(_DWORD *)(a1 + 1608) == 1 )
    return 0;
  mutex_lock(a1 + 32);
  if ( *(_DWORD *)(a1 + 1608) == 1
    || (sde_evtlog_log(
          sde_dbg_base_evtlog,
          "dsi_ctrl_check_state",
          535,
          -1,
          *(unsigned __int8 *)(a1 + 2584),
          *(_DWORD *)(a1 + 8),
          8,
          1,
          239),
        *(_DWORD *)(a1 + 1620) == 1) )
  {
    if ( a3 >= 0x7D1 )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: Programmable fetch time check failed, pf_time_in_us=%u\n",
        *(const char **)(a1 + 16),
        a3);
      a3 = 2000;
    }
    v7 = usleep_range_state(a3, a3 + 10, 2);
    v8 = *(unsigned int *)(a1 + 1608);
    if ( (unsigned int)v8 >= 3 )
    {
      __break(0x5512u);
      return dsi_ctrl_timing_setup(v7);
    }
    v9 = *(_DWORD **)(a1 + 8 * v8 + 1152);
    if ( v9 )
    {
      if ( *(v9 - 1) != 1642962683 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v9)(a1 + 96, a2 & 1);
    }
    v10 = 0;
  }
  else
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: Unexpected engine state vid_state=%d\n",
      *(const char **)(a1 + 16),
      1);
    v10 = -22;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: Controller state check failed, rc=%d\n",
      *(const char **)(a1 + 16),
      -22);
  }
  mutex_unlock(a1 + 32);
  return v10;
}
