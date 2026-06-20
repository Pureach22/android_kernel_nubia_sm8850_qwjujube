__int64 __fastcall sde_hw_pp_connect_external_te(__int64 a1, char a2)
{
  unsigned int v4; // w0
  unsigned int v5; // w21
  int v6; // w22
  unsigned int v7; // w19
  int v8; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a1 )
  {
    v4 = sde_reg_read(a1, 4u);
    v5 = v4 & 0xFFEFFFFF;
    if ( (a2 & 1) != 0 )
      v6 = 0x100000;
    else
      v6 = 0;
    v7 = (v4 >> 20) & 1;
    sde_reg_write(a1, 4u, v5 | v6, "PP_SYNC_CONFIG_VSYNC");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_hw_pp_connect_external_te",
      510,
      -1,
      *(_DWORD *)(a1 + 32) - 1,
      v5 | v6,
      -1059143953,
      v8,
      vars0);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v7;
}
