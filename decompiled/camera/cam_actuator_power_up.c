__int64 __fastcall cam_actuator_power_up(__int64 a1)
{
  __int64 v1; // x22
  __int64 v3; // x1
  unsigned int v4; // w0
  unsigned int v5; // w0
  unsigned int v6; // w19
  const char *v7; // x5
  __int64 v8; // x4
  unsigned int v9; // w0
  char *i3c_completion; // x2
  unsigned int v11; // w0
  const char *v13; // x5
  __int64 v14; // x4

  v1 = *(_QWORD *)(a1 + 3392);
  v3 = *(_QWORD *)(v1 + 16);
  if ( !v3 )
  {
    if ( *(_QWORD *)(v1 + 32) )
    {
      v3 = 0;
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x2000,
        3,
        "cam_actuator_power_up",
        70,
        "Using default power settings");
      v4 = cam_actuator_construct_default_power_setting(v1 + 8);
      if ( (v4 & 0x80000000) != 0 )
      {
        v6 = v4;
        v13 = "Construct default actuator power setting failed.";
        v14 = 74;
LABEL_18:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x2000,
          1,
          "cam_actuator_power_up",
          v14,
          v13);
        return v6;
      }
      v3 = *(_QWORD *)(v1 + 16);
    }
  }
  v5 = msm_camera_fill_vreg_params(a1 + 96, v3, *(unsigned __int16 *)(v1 + 24));
  if ( v5 )
  {
    v6 = v5;
    v7 = "failed to fill vreg params for power up rc:%d";
    v8 = 86;
LABEL_15:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_power_up",
      v8,
      v7,
      v6);
    return v6;
  }
  v9 = msm_camera_fill_vreg_params(a1 + 96, *(_QWORD *)(v1 + 32), *(unsigned __int16 *)(v1 + 40));
  if ( v9 )
  {
    v6 = v9;
    v7 = "failed to fill vreg params power down rc:%d";
    v8 = 97;
    goto LABEL_15;
  }
  *(_QWORD *)(v1 + 8) = *(_QWORD *)(a1 + 104);
  if ( *(_DWORD *)(a1 + 32) == 4 )
    i3c_completion = cam_actuator_get_i3c_completion(*(_DWORD *)(a1 + 116));
  else
    i3c_completion = nullptr;
  v11 = cam_sensor_core_power_up(v1 + 8, a1 + 96, i3c_completion);
  if ( v11 )
  {
    v6 = v11;
    v7 = "failed in actuator power up rc %d";
    v8 = 109;
    goto LABEL_15;
  }
  v6 = camera_io_init(a1 + 32);
  if ( (v6 & 0x80000000) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_power_up",
      115,
      "cci init failed: rc: %d",
      v6);
    if ( (unsigned int)cam_sensor_util_power_down(v1 + 8, a1 + 96) )
    {
      v13 = "Power down failure";
      v14 = 122;
      goto LABEL_18;
    }
  }
  return v6;
}
