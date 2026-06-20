__int64 __fastcall dp_bridge_mode_set(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  void (__fastcall *v5)(_QWORD); // x8
  __int64 (__fastcall *v6)(__int64, __int64); // x8
  __int64 v7; // x1
  __int64 ipc_log_context; // x0
  void *v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0

  if ( !a1 || !a2 || !a3 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v10 = &unk_21CA0C;
    return printk(v10, "dp_bridge_mode_set");
  }
  if ( !a1[38] )
  {
    v11 = get_ipc_log_context();
    ipc_log_string(v11, "[e][%-4d]Invalid connector\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v10 = &unk_2344C7;
    return printk(v10, "dp_bridge_mode_set");
  }
  if ( !a1[140] )
  {
    v12 = get_ipc_log_context();
    ipc_log_string(v12, "[e][%-4d]Invalid dp_panel\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v10 = &unk_248981;
    return printk(v10, "dp_bridge_mode_set");
  }
  v4 = a1[39];
  v5 = *(void (__fastcall **)(_QWORD))(v4 + 272);
  if ( *((_DWORD *)v5 - 1) != 271107547 )
    __break(0x8228u);
  v5(v4);
  v6 = *(__int64 (__fastcall **)(__int64, __int64))(v4 + 304);
  v7 = a1[140];
  if ( *((_DWORD *)v6 - 1) != -250558756 )
    __break(0x8228u);
  return v6(v4, v7);
}
