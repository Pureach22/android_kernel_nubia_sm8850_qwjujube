__int64 __fastcall cam_tpg_subdev_ioctl(__int64 a1, int a2, __int64 a3)
{
  __int64 v3; // x19

  v3 = *(_QWORD *)(a1 + 240);
  if ( a2 == 263 )
  {
    if ( (cam_req_mgr_is_shutdown() & 1) != 0 )
    {
      mutex_lock(v3 + 24);
      cam_tpg_shutdown(v3);
      mutex_unlock(v3 + 24);
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        2,
        1,
        "cam_tpg_subdev_ioctl",
        59,
        "SD shouldn't come from user space");
    }
    return 0;
  }
  else if ( a2 == -1072146752 )
  {
    return (int)cam_tpg_core_cfg(*(_QWORD *)(a1 + 240), a3);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "cam_tpg_subdev_ioctl",
      67,
      "Wrong ioctl : %d",
      a2);
    return -515;
  }
}
