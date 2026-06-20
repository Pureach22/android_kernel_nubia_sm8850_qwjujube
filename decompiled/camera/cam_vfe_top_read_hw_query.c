__int64 __fastcall cam_vfe_top_read_hw_query(__int64 a1, __int64 a2, int a3)
{
  bool v4; // zf
  unsigned int v5; // w2

  v4 = a3 == 0x200000;
  v5 = 0;
  if ( !v4 && a3 != 3145728 )
  {
    if ( a3 == 0x400000 )
    {
      return (unsigned int)cam_vfe_top_ver4_read_hw_query(a1, a2, 0);
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_read_hw_query",
        80,
        "Error! Unsupported Version %x",
        a3);
      return 0;
    }
  }
  return v5;
}
