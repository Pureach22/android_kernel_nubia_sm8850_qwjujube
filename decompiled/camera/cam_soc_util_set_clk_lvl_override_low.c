__int64 __fastcall cam_soc_util_set_clk_lvl_override_low(__int64 a1, __int64 a2)
{
  if ( (unsigned __int64)(a2 - 10) > 0xFFFFFFFFFFFFFFF6LL )
  {
    if ( *(_BYTE *)(a1 + a2 + 2860) == 1 )
      *(_DWORD *)(a1 + 3284) = a2;
    else
      *(_DWORD *)(a1 + 3284) = 0;
    return 0;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_soc_util_set_clk_lvl_override_low",
      1783,
      "Invalid clk lvl override %d",
      a2);
    return 0;
  }
}
