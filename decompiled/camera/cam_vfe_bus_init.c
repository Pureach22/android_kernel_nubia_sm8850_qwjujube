__int64 __fastcall cam_vfe_bus_init(
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
      return cam_vfe_bus_rd_ver1_init(a3, a4, a5, a6, a7);
    v8 = "Unsupported Bus RD Version 0x%x";
    v9 = a1;
    v10 = 50;
  }
  else if ( a2 )
  {
    v8 = "Unsupported Bus type %d";
    v9 = a2;
    v10 = 55;
  }
  else
  {
    if ( a1 == 12288 )
      return cam_vfe_bus_ver3_init(a3, a4, a5, a6, a7);
    if ( a1 == 0x2000 )
      return cam_vfe_bus_ver2_init(a3, a4, a5, a6, a7);
    v8 = "Unsupported Bus WR Version 0x%x";
    v9 = a1;
    v10 = 37;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    8,
    1,
    "cam_vfe_bus_init",
    v10,
    v8,
    v9);
  return 4294967277LL;
}
