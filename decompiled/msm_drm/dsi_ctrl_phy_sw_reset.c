__int64 __fastcall dsi_ctrl_phy_sw_reset(__int64 a1)
{
  unsigned int v3; // w8
  int v4; // w0
  int v5; // w1
  int v6; // w2
  int v7; // w5
  void (__fastcall *v8)(_QWORD); // x8
  unsigned int v9; // w20

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", "inv");
    return 4294967274LL;
  }
  if ( *(_DWORD *)(a1 + 1608) == 1 )
    return 0;
  mutex_lock(a1 + 32);
  v3 = *(_DWORD *)(a1 + 1608);
  if ( v3 == 1 )
  {
LABEL_8:
    v8 = *(void (__fastcall **)(_QWORD))(a1 + 8LL * v3 + 384);
    if ( v8 )
    {
      if ( *((_DWORD *)v8 - 1) != 1133867105 )
        __break(0x8228u);
      v8(a1 + 96);
    }
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: PHY soft reset done\n", *(const char **)(a1 + 16));
    v9 = 0;
    goto LABEL_14;
  }
  v4 = sde_evtlog_log(
         sde_dbg_base_evtlog,
         "dsi_ctrl_check_state",
         535,
         -1,
         *(unsigned __int8 *)(a1 + 2584),
         *(_DWORD *)(a1 + 8),
         7,
         0,
         239);
  v7 = *(_DWORD *)(a1 + 1612);
  if ( v7 == 1 )
  {
    v3 = *(_DWORD *)(a1 + 1608);
    if ( v3 >= 3 )
    {
      __break(0x5512u);
      return dsi_ctrl_check_state(v4, v5, v6);
    }
    goto LABEL_8;
  }
  drm_dev_printk(
    0,
    &unk_248D72,
    "*ERROR* [msm-dsi-error]: %s: State error: op=%d: %d\n",
    *(const char **)(a1 + 16),
    7,
    v7);
  v9 = -22;
  drm_dev_printk(
    0,
    &unk_248D72,
    "*ERROR* [msm-dsi-error]: %s: Controller state check failed, rc=%d\n",
    *(const char **)(a1 + 16),
    -22);
LABEL_14:
  mutex_unlock(a1 + 32);
  return v9;
}
