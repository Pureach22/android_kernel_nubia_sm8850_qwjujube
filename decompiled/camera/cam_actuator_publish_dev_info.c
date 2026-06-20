__int64 __fastcall cam_actuator_publish_dev_info(__int64 a1)
{
  __int64 device_priv; // x0
  const char *v4; // x5
  __int64 v5; // x4

  if ( a1 )
  {
    device_priv = cam_get_device_priv(*(_DWORD *)a1);
    if ( device_priv )
    {
      *(_DWORD *)(a1 + 260) = 3;
      snprintf((char *)(a1 + 4), 0x100u, "%s(camera-actuator%u)", "cam-actuator", *(_DWORD *)(device_priv + 116));
      *(_QWORD *)(a1 + 264) = 0x100000001LL;
      *(_DWORD *)(a1 + 272) = 1;
      return 0;
    }
    v4 = "Device data is NULL";
    v5 = 425;
  }
  else
  {
    v4 = "Invalid Args";
    v5 = 418;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x2000,
    1,
    "cam_actuator_publish_dev_info",
    v5,
    v4);
  return 4294967274LL;
}
