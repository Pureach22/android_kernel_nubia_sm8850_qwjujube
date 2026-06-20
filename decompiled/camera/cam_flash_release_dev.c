__int64 __fastcall cam_flash_release_dev(unsigned int *a1)
{
  __int64 v2; // x0
  unsigned int v3; // w20

  v2 = a1[1506];
  if ( (_DWORD)v2 == 1 )
  {
    return 0;
  }
  else
  {
    v3 = cam_destroy_device_hdl(v2);
    if ( v3 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_release_dev",
        2248,
        "Failed in destroying device handle rc = %d",
        v3);
    a1[1678] = 0;
    *((_QWORD *)a1 + 753) = -1;
    a1[1508] = -1;
  }
  return v3;
}
