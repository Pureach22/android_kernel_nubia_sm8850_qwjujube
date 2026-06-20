__int64 __fastcall cam_vfe_bus_deinit(int a1, __int64 a2)
{
  if ( a1 == 12288 )
    return cam_vfe_bus_ver3_deinit(a2);
  if ( a1 == 0x2000 )
    return cam_vfe_bus_ver2_deinit(a2);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_vfe_bus_deinit",
    75,
    "Unsupported Bus Version %x",
    a1);
  return 4294967277LL;
}
