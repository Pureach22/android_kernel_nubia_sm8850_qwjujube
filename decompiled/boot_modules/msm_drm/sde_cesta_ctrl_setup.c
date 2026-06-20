__int64 __fastcall sde_cesta_ctrl_setup(
        int *a1,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  void (*v10)(void); // x8
  int v11; // w4
  int v12; // w5
  char v14; // [xsp+0h] [xbp-40h]

  if ( !a1 || a1[1] )
    return printk(&unk_213914, "sde_cesta_ctrl_setup");
  v10 = *(void (**)(void))(cesta_list_0 + 856);
  if ( v10 )
  {
    if ( *((_DWORD *)v10 - 1) != 1168570274 )
      __break(0x8228u);
    v10();
  }
  v11 = *a1;
  v12 = a1[2];
  if ( a2 )
    return sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_cesta_ctrl_setup",
             255,
             -1,
             v11,
             v12,
             *a2,
             *((_DWORD *)a2 + 1),
             a2[8]);
  else
    return sde_evtlog_log(sde_dbg_base_evtlog, "sde_cesta_ctrl_setup", 257, -1, v11, v12, -1059143953, a8, v14);
}
