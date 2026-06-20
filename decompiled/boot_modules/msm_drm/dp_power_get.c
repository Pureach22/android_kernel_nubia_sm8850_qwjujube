__int64 __fastcall dp_power_get(__int64 *a1, __int64 *a2)
{
  __int64 **v4; // x0
  __int64 **v5; // x19
  __int64 *v6; // x8
  _QWORD *v7; // x20
  __int64 *v8; // x21
  unsigned __int64 v9; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v12; // x0

  if ( a1 && a2 )
  {
    v4 = (__int64 **)_kmalloc_cache_noprof(drm_dp_dpcd_read, 3520, 200);
    v5 = v4;
    if ( v4 )
    {
      v6 = (__int64 *)*a1;
      *v4 = a1;
      v4[1] = a2;
      v4[13] = (__int64 *)dp_power_init;
      v4[14] = (__int64 *)dp_power_deinit;
      v4[2] = v6;
      v4[15] = (__int64 *)&dp_power_clk_enable;
      v4[16] = (__int64 *)dp_power_clk_status;
      v7 = v4 + 9;
      v4[17] = (__int64 *)dp_power_set_pixel_clk_parent;
      v4[18] = (__int64 *)dp_power_park_clocks;
      v8 = v6 + 2;
      v4[19] = (__int64 *)dp_power_clk_get_rate;
      v4[20] = (__int64 *)dp_power_client_init;
      v4[21] = (__int64 *)dp_power_client_deinit;
      v4[22] = (__int64 *)dp_power_mmrm_init;
      v4[23] = (__int64 *)dp_power_edp_panel_set_gpio;
      if ( v6[76] )
      {
        pm_runtime_enable(v6 + 2);
        v5[11] = nullptr;
        v5[12] = v8;
      }
      else
      {
        v9 = devm_regulator_get(v6 + 2, "dp_phy_gdsc");
        v5[11] = (__int64 *)v9;
        if ( v9 >= 0xFFFFFFFFFFFFF001LL )
        {
          v5[11] = nullptr;
          ipc_log_context = get_ipc_log_context(v9);
          StatusReg = _ReadStatusReg(SP_EL0);
          ipc_log_string(
            ipc_log_context,
            "[d][%-4d]Optional GDSC regulator is missing\n",
            *(_DWORD *)(StatusReg + 1800));
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]Optional GDSC regulator is missing\n",
              *(_DWORD *)(StatusReg + 1800));
        }
        v5[12] = nullptr;
      }
    }
    else
    {
      return -12;
    }
  }
  else
  {
    v12 = get_ipc_log_context(a1);
    ipc_log_string(v12, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_power_get");
    return -22;
  }
  return (__int64)v7;
}
