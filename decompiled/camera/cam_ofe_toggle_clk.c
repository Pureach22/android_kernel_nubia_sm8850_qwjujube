__int64 __fastcall cam_ofe_toggle_clk(_DWORD *a1, char a2)
{
  __int64 result; // x0
  const char *v4; // x6
  unsigned int v5; // w19

  if ( (a2 & 1) != 0 )
  {
    result = cam_soc_util_clk_enable_default(a1, 0xFFFFFFFF, 5);
  }
  else
  {
    cam_soc_util_clk_disable_default((__int64)a1, 0xFFFFFFFF);
    result = 0;
  }
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    if ( (a2 & 1) != 0 )
      v4 = "Enable";
    else
      v4 = "Disable";
    v5 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_ofe_toggle_clk",
      226,
      "%s OFE clock",
      v4);
    return v5;
  }
  return result;
}
