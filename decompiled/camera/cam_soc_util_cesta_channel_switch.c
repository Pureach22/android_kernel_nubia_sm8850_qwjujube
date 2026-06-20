__int64 __fastcall cam_soc_util_cesta_channel_switch(unsigned int a1, const char *a2)
{
  __int64 result; // x0
  unsigned int v4; // w21
  unsigned int v5; // w20
  _QWORD v6[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v7[3]; // [xsp+18h] [xbp-18h] BYREF

  v7[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( cam_cesta_crm_dev )
  {
    if ( a1 >= 3 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_cesta_channel_switch",
        660,
        "Invalid client index for camera cesta idx: %d max: %d",
        a1,
        3);
      result = 4294967274LL;
    }
    else
    {
      if ( (debug_mdl & 0x2020000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x2020000,
          4,
          "cam_soc_util_cesta_channel_switch",
          665,
          "CESTA Channel switch : hw client idx %d identifier=%s",
          a1,
          a2);
      v7[0] = 0;
      v7[1] = 0;
      v6[0] = 0;
      v6[1] = 0;
      if ( (debug_bypass_drivers & 8) != 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x20000,
          2,
          "cam_wrapper_crm_write_pwr_states",
          152,
          "Bypass crm write pwr states");
        result = 0;
      }
      else
      {
        if ( clk_rgltr_bus_ops_profiling == 1 )
          ktime_get_real_ts64(v7);
        result = crm_write_pwr_states(cam_cesta_crm_dev, a1);
        if ( clk_rgltr_bus_ops_profiling == 1 )
        {
          v4 = result;
          ktime_get_real_ts64(v6);
          result = v4;
        }
        if ( (_DWORD)result )
        {
          v5 = result;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x20000,
            1,
            "cam_soc_util_cesta_channel_switch",
            672,
            "Failed to trigger cesta channel switch cesta_client_idx: %u rc: %d",
            a1,
            result);
          result = v5;
        }
      }
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_cesta_channel_switch",
      654,
      "camera cesta crm device is null");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
