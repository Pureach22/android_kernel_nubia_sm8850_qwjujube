__int64 __fastcall dp_ctrl_configure_source_link_params(__int64 a1, char a2)
{
  __int64 (*v4)(void); // x8
  __int64 v5; // x0
  __int64 (*v6)(void); // x8
  __int64 v7; // x0
  __int64 v8; // x0
  void (*v9)(void); // x8
  void (*v10)(void); // x9
  void (*v11)(void); // x8
  void (*v12)(void); // x9
  void (*v13)(void); // x9
  __int64 (*v14)(void); // x8
  __int64 ipc_log_context; // x0
  void *v17; // x0
  __int64 v18; // x0

  v4 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 160) + 56LL);
  if ( *((_DWORD *)v4 - 1) != -1927405339 )
    __break(0x8228u);
  v5 = v4();
  if ( (v5 & 1) == 0 )
  {
    ipc_log_context = get_ipc_log_context(v5);
    ipc_log_string(ipc_log_context, "[w][%-4d]DP link clocks are off\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v17 = &unk_248566;
    return printk(v17, "dp_ctrl_configure_source_link_params");
  }
  v6 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 160) + 56LL);
  if ( *((_DWORD *)v6 - 1) != -1927405339 )
    __break(0x8228u);
  v7 = v6();
  if ( (v7 & 1) == 0 )
  {
    v18 = get_ipc_log_context(v7);
    ipc_log_string(v18, "[w][%-4d]DP core clocks are off\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v17 = &unk_267C9E;
    return printk(v17, "dp_ctrl_configure_source_link_params");
  }
  v8 = *(_QWORD *)(a1 + 176);
  if ( (a2 & 1) != 0 )
  {
    v9 = *(void (**)(void))(v8 + 72);
    if ( *((_DWORD *)v9 - 1) != 546923245 )
      __break(0x8228u);
    v9();
    v10 = *(void (**)(void))(*(_QWORD *)(a1 + 176) + 80LL);
    if ( *((_DWORD *)v10 - 1) != 289804815 )
      __break(0x8229u);
    v10();
    v11 = *(void (**)(void))(*(_QWORD *)(a1 + 176) + 192LL);
    if ( *((_DWORD *)v11 - 1) != 289804815 )
      __break(0x8228u);
    v11();
    v12 = *(void (**)(void))(*(_QWORD *)(a1 + 176) + 64LL);
    if ( *((_DWORD *)v12 - 1) != 289804815 )
      __break(0x8229u);
    v12();
    v13 = *(void (**)(void))(*(_QWORD *)(a1 + 176) + 248LL);
    if ( *((_DWORD *)v13 - 1) != 289804815 )
      __break(0x8229u);
    v13();
    v14 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 176) + 88LL);
  }
  else
  {
    v14 = *(__int64 (**)(void))(v8 + 88);
  }
  if ( *((_DWORD *)v14 - 1) != 289804815 )
    __break(0x8228u);
  return v14();
}
