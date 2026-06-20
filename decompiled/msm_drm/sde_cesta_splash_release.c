size_t __fastcall sde_cesta_splash_release(size_t result)
{
  int v1; // w20
  __int64 v2; // x22
  int v3; // w21
  __int64 v4; // x24
  int v5; // w6
  int v6; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !(_DWORD)result && cesta_list_0 )
  {
    v1 = *(_DWORD *)(cesta_list_0 + 48);
    if ( !v1 )
      return printk(&unk_221DCE, "sde_cesta_splash_release");
    v2 = *(_QWORD *)(cesta_list_0 + 56);
    v3 = 0;
    while ( 1 )
    {
      v4 = v2 + 120LL * v3;
      if ( !strcmp((const char *)(v4 + 8), "core_clk") )
        break;
      if ( v1 == ++v3 )
        return printk(&unk_221DCE, "sde_cesta_splash_release");
    }
    if ( *(_QWORD *)v4 )
    {
      clk_set_rate(*(_QWORD *)v4, 19200000);
      return sde_evtlog_log(sde_dbg_base_evtlog, "sde_cesta_splash_release", 234, -1, 0, -1059143953, v5, v6, vars0);
    }
    else
    {
      return printk(&unk_221DCE, "sde_cesta_splash_release");
    }
  }
  return result;
}
