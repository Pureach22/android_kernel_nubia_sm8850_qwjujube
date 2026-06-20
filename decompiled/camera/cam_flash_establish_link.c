__int64 __fastcall cam_flash_establish_link(__int64 a1)
{
  __int64 device_priv; // x0
  __int64 v3; // x19
  __int64 v4; // x8

  if ( !a1 )
    return 4294967274LL;
  device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 8));
  if ( device_priv )
  {
    v3 = device_priv;
    mutex_lock(device_priv + 6152);
    if ( *(_DWORD *)a1 )
    {
      *(_DWORD *)(v3 + 6032) = *(_DWORD *)(a1 + 4);
      v4 = *(_QWORD *)(a1 + 24);
    }
    else
    {
      v4 = 0;
      *(_DWORD *)(v3 + 6032) = -1;
    }
    *(_QWORD *)(v3 + 6096) = v4;
    mutex_unlock(v3 + 6152);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_establish_link",
      2223,
      " Device data is NULL");
    return 4294967274LL;
  }
}
