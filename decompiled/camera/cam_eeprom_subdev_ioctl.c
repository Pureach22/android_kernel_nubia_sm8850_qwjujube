__int64 __fastcall cam_eeprom_subdev_ioctl(__int64 a1, int a2, __int64 a3)
{
  int v3; // w0
  int v4; // w19
  __int64 v7; // x19

  if ( a2 == 263 )
  {
    if ( (cam_req_mgr_is_shutdown() & 1) != 0 )
    {
      v7 = *(_QWORD *)(a1 + 240);
      if ( !v7 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x10000,
          1,
          "cam_eeprom_subdev_close_internal",
          33,
          "e_ctrl ptr is NULL");
        return -22;
      }
      mutex_lock(v7 + 40);
      cam_eeprom_shutdown(v7);
      mutex_unlock(v7 + 40);
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        2,
        1,
        "cam_eeprom_subdev_ioctl",
        72,
        "SD shouldn't come from user space");
    }
  }
  else
  {
    if ( a2 != -1072146752 )
      return -515;
    v3 = cam_eeprom_driver_cmd(*(_QWORD *)(a1 + 240), a3);
    if ( v3 )
    {
      v4 = v3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x10000,
        1,
        "cam_eeprom_subdev_ioctl",
        68,
        "Failed in Driver cmd: %d",
        v3);
      return v4;
    }
  }
  return 0;
}
