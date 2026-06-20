__int64 __fastcall cam_cpas_subdev_ioctl(__int64 a1, int a2, unsigned int *a3)
{
  __int64 v3; // x8
  __int64 result; // x0

  v3 = *(_QWORD *)(a1 + 240);
  if ( v3 && (*(_BYTE *)(v3 + 852) & 1) != 0 )
  {
    if ( a2 == 263 )
    {
      LODWORD(result) = _cam_cpas_subdev_close();
    }
    else if ( a2 == -1072146752 )
    {
      LODWORD(result) = cam_cpas_subdev_cmd(a1, a3);
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_subdev_ioctl",
        1964,
        "Invalid command %d for CPAS!",
        a2);
      LODWORD(result) = -22;
    }
    return (int)result;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_subdev_ioctl",
      1952,
      "CPAS not initialized");
    return -19;
  }
}
