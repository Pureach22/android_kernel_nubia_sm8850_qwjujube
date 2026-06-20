__int64 __fastcall cam_flash_publish_dev_info(__int64 a1)
{
  __int64 device_priv; // x0

  device_priv = cam_get_device_priv(*(_DWORD *)a1);
  if ( device_priv )
  {
    *(_DWORD *)(a1 + 260) = 2;
    snprintf((char *)(a1 + 4), 0x100u, "%s(camera-flash%u)", "cam-flash", *(_DWORD *)(device_priv + 44));
    *(_QWORD *)(a1 + 264) = 0x100000001LL;
    *(_DWORD *)(a1 + 272) = 1;
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_publish_dev_info",
      2201,
      " Device data is NULL");
    return 4294967274LL;
  }
}
