__int64 __fastcall cam_csiphy_subdev_ioctl(__int64 a1, int a2)
{
  int v2; // w0
  int v3; // w19
  const char *v5; // x3
  __int64 v6; // x4
  __int64 v8; // x19

  if ( !*(_QWORD *)(a1 + 240) )
  {
    v5 = "cam_csiphy_subdev_ioctl";
    v6 = 424;
    goto LABEL_7;
  }
  if ( a2 == 263 )
  {
    if ( (cam_req_mgr_is_shutdown() & 1) == 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        2,
        1,
        "cam_csiphy_subdev_ioctl",
        437,
        "SD shouldn't come from user space");
      return 0;
    }
    v8 = *(_QWORD *)(a1 + 240);
    if ( v8 )
    {
      mutex_lock(v8 + 24);
      cam_csiphy_shutdown(v8);
      mutex_unlock(v8 + 24);
      return 0;
    }
    v5 = "cam_csiphy_subdev_close_internal";
    v6 = 393;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      1,
      v5,
      v6,
      "csiphy_dev ptr is NULL");
    return -22;
  }
  if ( a2 != -1072146752 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_subdev_ioctl",
      444,
      "Wrong ioctl : %d",
      a2);
    return -515;
  }
  v2 = cam_csiphy_core_cfg();
  if ( v2 )
  {
    v3 = v2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_subdev_ioctl",
      433,
      "Failed in configuring the device: %d",
      v2);
    return v3;
  }
  return 0;
}
