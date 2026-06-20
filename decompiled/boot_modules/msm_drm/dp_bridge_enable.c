__int64 __fastcall dp_bridge_enable(__int64 a1)
{
  __int64 (*v2)(void); // x8
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  void *v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  int v8; // w20
  __int64 v9; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v5 = &unk_21CA0C;
    return printk(v5, "dp_bridge_enable");
  }
  if ( !*(_QWORD *)(a1 + 304) )
  {
    v6 = get_ipc_log_context();
    ipc_log_string(v6, "[e][%-4d]Invalid connector\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v5 = &unk_2344C7;
    return printk(v5, "dp_bridge_enable");
  }
  if ( !*(_QWORD *)(a1 + 1120) )
  {
    v7 = get_ipc_log_context();
    ipc_log_string(v7, "[e][%-4d]Invalid dp_panel\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v5 = &unk_248981;
    return printk(v5, "dp_bridge_enable");
  }
  v2 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 312) + 88LL);
  if ( *((_DWORD *)v2 - 1) != -1533774139 )
    __break(0x8228u);
  result = v2();
  if ( (_DWORD)result )
  {
    v8 = result;
    v9 = get_ipc_log_context();
    ipc_log_string(
      v9,
      "[e][%-4d][%d] DP display post enable failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a1 + 296),
      v8);
    return printk(&unk_272DD2, "dp_bridge_enable");
  }
  return result;
}
