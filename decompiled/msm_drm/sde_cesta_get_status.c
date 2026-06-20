size_t __fastcall sde_cesta_get_status(int *a1, int *a2)
{
  void (*v4)(void); // x8

  if ( !a1 || a1[1] )
    return printk(&unk_25C1E1, "sde_cesta_get_status");
  v4 = *(void (**)(void))(cesta_list_0 + 872);
  if ( v4 )
  {
    if ( *((_DWORD *)v4 - 1) != -1476338332 )
      __break(0x8228u);
    v4();
  }
  return sde_evtlog_log(sde_dbg_base_evtlog, "sde_cesta_get_status", 649, -1, *a1, a1[2], *a2, a2[1], a2[2]);
}
