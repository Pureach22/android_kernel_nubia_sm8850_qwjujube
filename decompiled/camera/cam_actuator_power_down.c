__int64 __fastcall cam_actuator_power_down(__int64 a1)
{
  int v2; // w0
  unsigned int v3; // w19
  const char *v5; // x5
  __int64 v6; // x4

  if ( !a1 )
  {
    v5 = "failed: a_ctrl %pK";
    v6 = 135;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_power_down",
      v6,
      v5,
      0);
    return 4294967274LL;
  }
  if ( *(_QWORD *)(a1 + 3392) == -8 )
  {
    v5 = "failed: power_info %pK";
    v6 = 145;
    goto LABEL_7;
  }
  v2 = cam_sensor_util_power_down(*(_QWORD *)(a1 + 3392) + 8LL, a1 + 96);
  if ( v2 )
  {
    v3 = v2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_power_down",
      150,
      "power down the core is failed:%d",
      v2);
    return v3;
  }
  else
  {
    camera_io_release(a1 + 32);
    return 0;
  }
}
