__int64 __fastcall dsi_ctrl_async_timing_update(__int64 a1, const void *a2)
{
  const char *v4; // x3
  void *v6; // x0
  __int64 v7; // x8
  __int64 (__fastcall *v8)(__int64, __int64); // x9
  void (__fastcall *v9)(__int64, __int64); // x8
  unsigned int v10; // w20

  if ( a1 && a2 )
  {
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
      v6 = memcpy((void *)(a1 + 2592), a2, 0x98u);
      v7 = *(unsigned int *)(a1 + 1608);
      if ( (unsigned int)v7 >= 3 )
        goto LABEL_24;
      v8 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 8 * v7 + 1152);
      if ( v8 )
      {
        if ( *((_DWORD *)v8 - 1) != 1642962683 )
          __break(0x8229u);
        v6 = (void *)v8(a1 + 96, 1);
        LODWORD(v7) = *(_DWORD *)(a1 + 1608);
        if ( (unsigned int)v7 > 2 )
        {
LABEL_24:
          __break(0x5512u);
          return dsi_ctrl_timing_db_update(v6);
        }
      }
      v9 = *(void (__fastcall **)(__int64, __int64))(a1 + 8LL * (unsigned int)v7 + 264);
      if ( v9 )
      {
        if ( *((_DWORD *)v9 - 1) != -1866437525 )
          __break(0x8228u);
        v9(a1 + 96, a1 + 2440);
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
  else
  {
    if ( a1 )
      v4 = *(const char **)(a1 + 16);
    else
      v4 = "inv";
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", v4);
    return 4294967274LL;
  }
}
