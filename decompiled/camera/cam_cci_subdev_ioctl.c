__int64 __fastcall cam_cci_subdev_ioctl(__int64 a1, int a2, __int64 a3)
{
  if ( a3 )
  {
    if ( a2 == -1072146752 )
    {
      return 0;
    }
    else if ( a2 == -1069001001 )
    {
      return (int)cam_cci_core_cfg(a1, a3);
    }
    else
    {
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_subdev_ioctl",
        69);
      return -515;
    }
  }
  else
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_subdev_ioctl",
      58);
    return -22;
  }
}
