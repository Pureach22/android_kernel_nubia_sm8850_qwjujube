__int64 __fastcall cam_flash_apply_request(__int64 a1)
{
  __int64 device_priv; // x0
  __int64 v3; // x19
  __int64 (__fastcall *v4)(__int64, __int64); // x8
  __int64 v5; // x1
  unsigned int v6; // w20

  if ( !a1 )
    return (unsigned int)-22;
  device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 4));
  if ( !device_priv )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_apply_request",
      2298,
      "Device data is NULL");
    return (unsigned int)-22;
  }
  v3 = device_priv;
  mutex_lock(device_priv + 6152);
  v4 = *(__int64 (__fastcall **)(__int64, __int64))(v3 + 6216);
  v5 = *(_QWORD *)(a1 + 8);
  if ( *((_DWORD *)v4 - 1) != 1413211269 )
    __break(0x8228u);
  v6 = v4(v3, v5);
  if ( v6 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_apply_request",
      2306,
      "apply_setting failed with rc=%d",
      v6);
  mutex_unlock(v3 + 6152);
  return v6;
}
