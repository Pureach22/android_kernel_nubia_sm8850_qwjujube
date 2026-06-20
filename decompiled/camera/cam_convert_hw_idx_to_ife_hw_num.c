__int64 __fastcall cam_convert_hw_idx_to_ife_hw_num(unsigned int a1)
{
  unsigned int v1; // w8

  v1 = a1 - g_num_ife_available;
  if ( a1 < g_num_ife_available )
  {
    if ( a1 < 3 )
      return (unsigned int)dword_4514E4[a1];
    return 0;
  }
  if ( g_num_ife_lite_available + g_num_ife_available > a1 )
  {
    if ( v1 < 5 )
      return (unsigned int)dword_4514F0[v1];
    return 0;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_convert_hw_idx_to_ife_hw_num",
    3449,
    "hw idx %d out-of-bounds",
    a1);
  return 0;
}
