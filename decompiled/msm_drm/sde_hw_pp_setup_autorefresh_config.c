__int64 __fastcall sde_hw_pp_setup_autorefresh_config(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  unsigned int v3; // w19
  int v5; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  v2 = -22;
  if ( a1 && a2 )
  {
    if ( *(_BYTE *)a2 == 1 )
      v3 = *(_DWORD *)(a2 + 4) | 0x80000000;
    else
      v3 = 0;
    sde_reg_write(a1, 0x30u, v3, "PP_AUTOREFRESH_CONFIG");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_hw_pp_setup_autorefresh_config",
      228,
      -1,
      *(_DWORD *)(a1 + 32) - 1,
      v3,
      -1059143953,
      v5,
      vars0);
    return 0;
  }
  return v2;
}
