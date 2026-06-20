__int64 __fastcall cam_packet_util_validate_cmd_desc(int *a1)
{
  unsigned int v1; // w7
  unsigned int v2; // w9
  int v3; // w8

  if ( a1 )
  {
    v2 = a1[2];
    v1 = a1[3];
    v3 = *a1;
    if ( v1 <= v2 && v3 > 0 )
      return 0;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_packet_util_validate_cmd_desc",
      49,
      "invalid cmd arg %d %d %d %d",
      a1[1],
      v1,
      v3,
      v2);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_packet_util_validate_cmd_desc",
      41,
      "Invalid cmd desc");
  }
  return 4294967274LL;
}
