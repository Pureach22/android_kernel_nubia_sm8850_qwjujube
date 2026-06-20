__int64 __fastcall cam_actuator_subdev_ioctl(__int64 a1, int a2, __int64 a3)
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
        mutex_lock(v6 + 3672);
        cam_actuator_shutdown(v6);
        mutex_unlock(v6 + 3672);
        return 0;
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x2000,
          1,
          "cam_actuator_subdev_close_internal",
          33,
          "a_ctrl ptr is NULL");
        return -22;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        2,
        1,
        "cam_actuator_subdev_ioctl",
        80,
        "SD shouldn't come from user space");
      return 0;
    }
  }
  else if ( a2 == -1072146752 )
  {
    v3 = (unsigned int)cam_actuator_driver_cmd(*(_QWORD *)(a1 + 240), a3);
    result = v3;
    if ( (_DWORD)v3 )
    {
      if ( (_DWORD)v3 == -53 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000,
          3,
          "cam_actuator_subdev_ioctl",
          72,
          "Failed for driver_cmd: %d, it has been flushed",
          -53);
        return -53;
      }
      else
      {
        v7 = v3;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000,
          1,
          "cam_actuator_subdev_ioctl",
          75,
          "Failed for driver_cmd: %d",
          v3);
        return v7;
      }
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_subdev_ioctl",
      87,
      "Invalid ioctl cmd: %u",
      a2);
    return -515;
  }
  return result;
}
