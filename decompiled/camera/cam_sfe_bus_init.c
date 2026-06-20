__int64 __fastcall cam_sfe_bus_init(
        unsigned int a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  const char *v8; // x5
  __int64 v9; // x6
  __int64 v10; // x4

  if ( a2 == 1 )
  {
    if ( a1 == 4096 )
      return cam_sfe_bus_rd_init(a3, a4, a5, a6, a7);
    v8 = "Unsupported Bus RD Version 0x%x";
    v9 = a1;
    v10 = 44;
  }
  else if ( a2 )
  {
    v8 = "Unsupported Bus type %d";
    v9 = a2;
    v10 = 49;
  }
  else
  {
    if ( a1 == 4096 )
      return cam_sfe_bus_wr_init(a3, a4, a5, a6, a7);
    v8 = "Unsupported Bus WR Version 0x%x";
    v9 = a1;
    v10 = 32;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    0x40000000,
    1,
    "cam_sfe_bus_init",
    v10,
    v8,
    v9);
  return 4294967277LL;
}
