__int64 __fastcall cam_soc_util_get_clk_round_rate(_DWORD *a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x19

  v3 = a3;
  if ( a1 && a3 && a1[217] > a2 )
  {
    if ( a2 >= 0x20 )
    {
      __break(0x5512u);
      JUMPOUT(0x66CCE78);
    }
    return cam_wrapper_clk_round_rate(*(_QWORD *)&a1[2 * a2 + 282], a3);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_clk_round_rate",
      2021,
      "Invalid input params %pK, %d %lu",
      a1,
      a2,
      a3);
  }
  return v3;
}
