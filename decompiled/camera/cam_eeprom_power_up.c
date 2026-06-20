__int64 __fastcall cam_eeprom_power_up(__int64 a1, __int64 a2)
{
  unsigned int v4; // w0
  unsigned int v5; // w19
  const char *v6; // x5
  __int64 v7; // x4
  unsigned int v8; // w0
  char *i3c_completion; // x2
  unsigned int v10; // w0

  v4 = msm_camera_fill_vreg_params(a1 + 88, *(_QWORD *)(a2 + 8), *(unsigned __int16 *)(a2 + 16));
  if ( v4 )
  {
    v5 = v4;
    v6 = "failed to fill power up vreg params rc:%d";
    v7 = 162;
LABEL_10:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_power_up",
      v7,
      v6,
      v5);
    return v5;
  }
  v8 = msm_camera_fill_vreg_params(a1 + 88, *(_QWORD *)(a2 + 24), *(unsigned __int16 *)(a2 + 32));
  if ( v8 )
  {
    v5 = v8;
    v6 = "failed to fill power down vreg params  rc:%d";
    v7 = 173;
    goto LABEL_10;
  }
  *(_QWORD *)a2 = *(_QWORD *)(a1 + 96);
  if ( *(_DWORD *)(a1 + 3664) == 4 )
    i3c_completion = cam_eeprom_get_i3c_completion(*(_DWORD *)(a1 + 108));
  else
    i3c_completion = nullptr;
  v10 = cam_sensor_core_power_up(a2, a1 + 88, i3c_completion);
  if ( v10 )
  {
    v5 = v10;
    v6 = "failed in eeprom power up rc %d";
    v7 = 184;
    goto LABEL_10;
  }
  v5 = camera_io_init(a1 + 3664);
  if ( v5 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_power_up",
      190,
      "cci_init failed");
    if ( (unsigned int)cam_sensor_util_power_down(a2, a1 + 88) )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x10000,
        1,
        "cam_eeprom_power_up",
        197,
        "Power down failure");
  }
  return v5;
}
