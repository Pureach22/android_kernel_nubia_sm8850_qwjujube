__int64 __fastcall cam_common_evt_inject_generic_command_parser(
        __int64 a1,
        char **stringp,
        unsigned int a3,
        _DWORD *a4)
{
  char *v8; // x0
  char *v9; // x2
  unsigned int v10; // w20
  int v11; // w0
  unsigned int v13; // w19

  v8 = strsep(stringp, ":");
  if ( v8 )
  {
    v9 = v8;
    v10 = 0;
    do
    {
      if ( *(a4 - 1) != -574813269 )
        __break(0x8235u);
      v11 = ((__int64 (__fastcall *)(__int64, _QWORD, char *))a4)(a1, v10, v9);
      if ( v11 )
      {
        v13 = v11;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_common_evt_inject_generic_command_parser",
          643,
          "Parsed Command failed rc: %d",
          v11);
        return v13;
      }
      if ( a3 - 1 == v10 )
        return 0;
      v9 = strsep(stringp, ":");
      ++v10;
    }
    while ( v9 );
    if ( v10 >= a3 )
      return 0;
    goto LABEL_9;
  }
  v10 = 0;
  if ( a3 )
  {
LABEL_9:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_evt_inject_generic_command_parser",
      656,
      "Insufficient parameters passed for total parameters: %u",
      v10);
    return 4294967274LL;
  }
  return 0;
}
