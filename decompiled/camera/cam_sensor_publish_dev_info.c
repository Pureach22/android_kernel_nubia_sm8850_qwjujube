__int64 __fastcall cam_sensor_publish_dev_info(__int64 a1)
{
  __int64 device_priv; // x0
  __int64 v3; // x19
  int v4; // w20
  int v5; // w8
  __int64 result; // x0
  int v7; // w9

  if ( !a1 )
    return 4294967274LL;
  device_priv = cam_get_device_priv(*(_DWORD *)a1);
  if ( device_priv )
  {
    v3 = device_priv;
    v4 = 1;
    *(_DWORD *)(a1 + 260) = 1;
    snprintf((char *)(a1 + 4), 0x100u, "%s(%s)", "cam-sensor", (const char *)(device_priv + 7560));
    if ( *(_DWORD *)(v3 + 7616) < 2u && (v4 = *(unsigned __int16 *)(v3 + 7556), (unsigned int)(v4 - 1) > 2) )
    {
      v5 = 2;
      v4 = 2;
      *(_DWORD *)(a1 + 264) = 2;
    }
    else
    {
      *(_DWORD *)(a1 + 264) = v4;
      v5 = *(unsigned __int16 *)(v3 + 7558);
    }
    result = 0;
    v7 = debug_mdl;
    *(_DWORD *)(a1 + 268) = v5;
    *(_DWORD *)(a1 + 272) = 1;
    *(_BYTE *)(a1 + 277) = 1;
    if ( (v7 & 0x1000020) != 0 && !debug_priority )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v7 & 0x1000020,
        4,
        "cam_sensor_publish_dev_info",
        1923,
        "num batched frames %d p_delay is %d",
        *(_DWORD *)(v3 + 7616),
        v4);
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_publish_dev_info",
      1902,
      "Device data is NULL");
    return 4294967274LL;
  }
  return result;
}
