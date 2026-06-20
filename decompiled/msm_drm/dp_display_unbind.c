__int64 __fastcall dp_display_unbind(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  void (*v3)(void); // x8
  __int64 v4; // x0
  void (*v5)(void); // x8
  __int64 v7; // x0
  void *v8; // x0
  __int64 v9; // x0

  if ( !a1 || a1 == 16 )
  {
    if ( !g_dp_display || (v7 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v7 = 0;
    ipc_log_string(v7, "[e][%-4d]invalid param(s)\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v8 = &unk_261825;
    return printk(v8, "dp_display_unbind");
  }
  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
  {
    if ( !g_dp_display || (v9 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v9 = 0;
    ipc_log_string(v9, "[e][%-4d]Invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v8 = &unk_21CA0C;
    return printk(v8, "dp_display_unbind");
  }
  v2 = *(_QWORD *)(v1 + 144);
  if ( v2 )
  {
    v3 = *(void (**)(void))(v2 + 96);
    if ( *((_DWORD *)v3 - 1) != 1752792964 )
      __break(0x8228u);
    v3();
  }
  v4 = *(_QWORD *)(v1 + 160);
  if ( v4 )
  {
    v5 = *(void (**)(void))(v4 + 40);
    if ( *((_DWORD *)v5 - 1) != 268977780 )
      __break(0x8228u);
    v5();
  }
  sde_hdcp_1x_deinit(*(_QWORD **)(v1 + 272));
  return sde_dp_hdcp2p2_deinit(*(_QWORD *)(v1 + 296));
}
