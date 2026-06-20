__int64 __fastcall cam_sensor_subdev_ioctl(__int64 a1, int a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 result; // x0
  __int64 v6; // x19
  int v7; // w19

  if ( a2 == 263 )
  {
    if ( (cam_req_mgr_is_shutdown() & 1) != 0 )
    {
      v6 = *(_QWORD *)(a1 + 240);
      if ( v6 )
      {
        mutex_lock(v6 + 3608);
        cam_sensor_shutdown(v6);
        mutex_unlock(v6 + 3608);
        return 0;
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          32,
          1,
          "cam_sensor_subdev_close_internal",
          32,
          "s_ctrl ptr is NULL");
        return -22;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        2,
        1,
        "cam_sensor_subdev_ioctl",
        77,
        "SD shouldn't come from user space");
      return 0;
    }
  }
  else if ( a2 == -1072146752 )
  {
    v3 = (unsigned int)cam_sensor_driver_cmd(*(_QWORD *)(a1 + 240), a3);
    result = v3;
    if ( (_DWORD)v3 )
    {
      if ( (_DWORD)v3 == -19 )
      {
        return -19;
      }
      else if ( (_DWORD)v3 == -53 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          32,
          3,
          "cam_sensor_subdev_ioctl",
          69,
          "Failed in Driver cmd: %d, it has been flushed",
          -53);
        return -53;
      }
      else
      {
        v7 = v3;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          32,
          1,
          "cam_sensor_subdev_ioctl",
          72,
          "Failed in Driver cmd: %d",
          v3);
        return v7;
      }
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_subdev_ioctl",
      84,
      "Invalid ioctl cmd: %d",
      a2);
    return -515;
  }
  return result;
}
