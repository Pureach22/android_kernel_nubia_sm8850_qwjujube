__int64 __fastcall cam_sensor_power_up(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  __int64 v4; // x1
  int v5; // w0
  unsigned int v6; // w19
  char *i3c_completion; // x2
  __int64 v8; // x8
  int v9; // w0
  unsigned int v10; // w21
  __int64 v11; // x1
  unsigned int v12; // w21
  unsigned int v13; // w19

  if ( !a1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_power_up",
      1982,
      "failed: %pK",
      nullptr);
    return 4294967274LL;
  }
  if ( (*(_BYTE *)(a1 + 7632) & 1) != 0 )
    return 0;
  v3 = *(_QWORD *)(a1 + 3656);
  if ( !v3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_power_up",
      1993,
      "failed: %pK %pK",
      &unk_70,
      nullptr);
    return 4294967274LL;
  }
  if ( *(_BYTE *)(a1 + 7548) == 1
    && (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, __int64))cam_sensor_bob_pwm_mode_switch)(
                       a1 + 32,
                       *(unsigned int *)(a1 + 7544),
                       1) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      32,
      2,
      "cam_sensor_power_up",
      2000,
      "BoB PWM setup failed");
  }
  if ( *(_DWORD *)(a1 + 7596) != 255 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      3,
      "cam_sensor_power_up",
      2006,
      "Setup for Main Camera with csiphy index: %d",
      *(_DWORD *)(*(_QWORD *)(a1 + 3656) + 60LL));
    v4 = *(unsigned int *)(*(_QWORD *)(a1 + 3656) + 60LL);
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    {
      v12 = *(_DWORD *)(*(_QWORD *)(a1 + 3656) + 60LL);
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_util_aon_ops",
        135,
        "Updating Main/Aon operation");
      v4 = v12;
    }
    v5 = ((__int64 (__fastcall *)(__int64, __int64))cam_csiphy_util_update_aon_ops)(1, v4);
    if ( v5 )
    {
      v6 = v5;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_power_up",
        2012,
        "Main camera access operation is not successful rc: %d",
        v5);
      return v6;
    }
  }
  if ( *(_DWORD *)(a1 + 6480) == 4 )
  {
    i3c_completion = cam_sensor_get_i3c_completion(*(_DWORD *)(a1 + 52));
    if ( *(_DWORD *)(a1 + 6480) == 4 )
    {
      v8 = *(_QWORD *)(a1 + 6488);
      if ( v8 )
        *(_BYTE *)(v8 + 17) = 1;
    }
  }
  else
  {
    i3c_completion = nullptr;
  }
  v9 = cam_sensor_core_power_up(v3 + 112, a1 + 32, i3c_completion);
  if ( v9 < 0 )
  {
    v10 = v9;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_power_up",
      2031,
      "core power up failed:%d",
      v9);
  }
  else
  {
    result = camera_io_init(a1 + 6480);
    if ( (result & 0x80000000) == 0 )
      return result;
    v10 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_power_up",
      2037,
      "cci_init failed: rc: %d",
      result);
    if ( (unsigned int)cam_sensor_util_power_down(v3 + 112, a1 + 32) )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_power_up",
        2045,
        "power down failure");
  }
  if ( *(_DWORD *)(a1 + 7596) != 255 )
  {
    v11 = *(unsigned int *)(*(_QWORD *)(a1 + 3656) + 60LL);
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    {
      v13 = *(_DWORD *)(*(_QWORD *)(a1 + 3656) + 60LL);
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_util_aon_ops",
        135,
        "Updating Main/Aon operation");
      v11 = v13;
    }
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64))cam_csiphy_util_update_aon_ops)(0, v11) )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        32,
        1,
        "cam_sensor_power_up",
        2052,
        "Main camera disable CPAS operation is not successful");
  }
  return v10;
}
