__int64 __fastcall cam_sfe_bus_deinit(unsigned int a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x6
  const char *v5; // x5
  __int64 v6; // x4

  v3 = a1;
  if ( a2 == 1 )
  {
    if ( a1 == 4096 )
      return cam_sfe_bus_rd_deinit(a3);
    v5 = "Unsupported Bus RD Version 0x%x";
    v6 = 82;
  }
  else if ( a2 )
  {
    v5 = "Unsupported Bus type %d";
    v3 = a2;
    v6 = 87;
  }
  else
  {
    if ( a1 == 4096 )
      return cam_sfe_bus_wr_deinit(a3);
    v5 = "Unsupported Bus WR Version 0x%x";
    v6 = 71;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    0x40000000,
    1,
    "cam_sfe_bus_deinit",
    v6,
    v5,
    v3);
  return 4294967277LL;
}
