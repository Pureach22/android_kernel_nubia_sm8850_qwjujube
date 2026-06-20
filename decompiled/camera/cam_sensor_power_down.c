__int64 __fastcall cam_sensor_power_down(__int64 a1)
{
  __int64 v1; // x22
  unsigned int v3; // w20
  __int64 v4; // x8
  unsigned int v5; // w0
  __int64 v6; // x1
  unsigned int v7; // w0
  unsigned int v8; // w21
  int v9; // w0
  unsigned int v11; // w21

  if ( a1 )
  {
    v1 = a1 + 4096;
    if ( (*(_BYTE *)(a1 + 7632) & 1) != 0 )
    {
      return 0;
    }
    else
    {
      v4 = *(_QWORD *)(a1 + 3656);
      if ( v4 == -112 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          32,
          1,
          "cam_sensor_power_down",
          2083,
          "failed: %s power_info %pK",
          (const char *)(a1 + 7560),
          nullptr);
        v3 = -22;
      }
      else
      {
        v5 = cam_sensor_util_power_down(v4 + 112, a1 + 32);
        if ( (v5 & 0x80000000) != 0 )
        {
          v3 = v5;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            32,
            1,
            "cam_sensor_power_down",
            2089,
            "%s core power down failed:%d",
            (const char *)(a1 + 7560),
            v5);
        }
        else
        {
          v3 = 0;
        }
      }
      if ( *(_DWORD *)(a1 + 7596) != 255 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          32,
          3,
          "cam_sensor_power_down",
          2097,
          "Setup for AON FW with csiphy index: %d",
          *(_DWORD *)(*(_QWORD *)(a1 + 3656) + 60LL));
        v6 = *(unsigned int *)(*(_QWORD *)(a1 + 3656) + 60LL);
        if ( (debug_mdl & 0x20) != 0 && !debug_priority )
        {
          v11 = *(_DWORD *)(*(_QWORD *)(a1 + 3656) + 60LL);
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x20,
            4,
            "cam_sensor_util_aon_ops",
            135,
            "Updating Main/Aon operation");
          v6 = v11;
        }
        v7 = ((__int64 (__fastcall *)(_QWORD, __int64))cam_csiphy_util_update_aon_ops)(0, v6);
        if ( v7 )
        {
          v8 = v7;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            32,
            1,
            "cam_sensor_power_down",
            2102,
            "Main camera disable CPAS operation failed ret: %d",
            v7);
          v3 = v8;
        }
      }
      if ( *(_BYTE *)(v1 + 3452) == 1 )
      {
        v9 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))cam_sensor_bob_pwm_mode_switch)(
               a1 + 32,
               *(unsigned int *)(a1 + 7544),
               0);
        if ( v9 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            32,
            2,
            "cam_sensor_power_down",
            2113,
            "%s BoB PWM setup failed ret: %d",
            (const char *)(a1 + 7560),
            v9);
      }
      camera_io_release(a1 + 6480);
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_power_down",
      2065,
      "failed: s_ctrl %pK",
      nullptr);
    return (unsigned int)-22;
  }
  return v3;
}
