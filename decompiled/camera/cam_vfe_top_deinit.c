__int64 __fastcall cam_vfe_top_deinit(int a1, __int64 a2)
{
  switch ( a1 )
  {
    case 0x400000:
      return cam_vfe_top_ver4_deinit(a2);
    case 0x300000:
      return ((__int64 (__fastcall *)(__int64))cam_vfe_top_ver3_deinit)(a2);
    case 0x200000:
      return ((__int64 (__fastcall *)(__int64))cam_vfe_top_ver2_deinit)(a2);
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_vfe_top_deinit",
    59,
    "Error! Unsupported Version %x",
    a1);
  return 4294967274LL;
}
