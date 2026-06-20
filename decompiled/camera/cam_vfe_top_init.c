__int64 __fastcall cam_vfe_top_init(int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  switch ( a1 )
  {
    case 0x400000:
      return cam_vfe_top_ver4_init(a2, a3, a4, a5, a6);
    case 0x300000:
      return cam_vfe_top_ver3_init(a2, a3, a4, a5, a6);
    case 0x200000:
      return cam_vfe_top_ver2_init(a2, a3, a4, a5, a6);
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_vfe_top_init",
    36,
    "Error! Unsupported Version %x",
    a1);
  return 4294967274LL;
}
