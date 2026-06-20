void *__fastcall cam_hfi_mini_dump(unsigned int a1, char *dest)
{
  __int64 v3; // x20
  char *v4; // x19
  void *result; // x0
  int v7; // w6

  if ( a1 >= 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      82,
      "Invalid HFI index: %u from hdl:%d",
      a1,
      a1);
    v7 = -22;
  }
  else
  {
    v3 = *(_QWORD *)&g_hfi[2 * a1 + 2];
    if ( v3 )
    {
      v4 = dest + 0x8000;
      memcpy(dest, *(const void **)(v3 + 32), 0x2000u);
      result = memcpy(dest + 0x4000, *(const void **)(v3 + 56), 0x2000u);
      *v4 = *(_BYTE *)(v3 + 1037);
      v4[1] = *(_BYTE *)(v3 + 1036);
      v4[2] = *(_BYTE *)(v3 + 1038);
      return result;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      89,
      "[%s] HFI interface not setup for client hdl: %d",
      byte_3EC,
      a1);
    v7 = -19;
  }
  return (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   0x40000,
                   1,
                   "cam_hfi_mini_dump",
                   130,
                   "Failed to get hfi info rc: %d for hdl: %d",
                   v7,
                   a1);
}
