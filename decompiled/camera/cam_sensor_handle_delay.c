__int64 __fastcall cam_sensor_handle_delay(_WORD **a1, __int16 a2, __int64 a3, int a4, _DWORD *a5, __int64 a6)
{
  _WORD *v6; // x9
  unsigned int v7; // w8

  if ( !a6 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_handle_delay",
      201,
      "Invalid list ptr");
    return (unsigned int)-22;
  }
  if ( !a4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_handle_delay",
      232,
      "Delay Rxed Before any buffer: %d",
      0);
    return (unsigned int)-22;
  }
  v6 = *a1;
  if ( (a2 & 0xFFFE) == 2 )
  {
    *(_WORD *)(a6 - 52) = *v6;
    v6 = *a1;
  }
  v7 = 0;
  *a1 = v6 + 4;
  *a5 += 8;
  return v7;
}
