__int64 __fastcall dp_bridge_disable(__int64 a1)
{
  __int64 v2; // x20
  __int64 (__fastcall *v3)(__int64, __int64); // x8
  __int64 v4; // x1
  __int64 result; // x0
  int v6; // w20
  __int64 v7; // x0
  __int64 ipc_log_context; // x0
  void *v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_21CA0C;
    return printk(v9, "dp_bridge_disable");
  }
  if ( !*(_QWORD *)(a1 + 304) )
  {
    v10 = get_ipc_log_context();
    ipc_log_string(v10, "[e][%-4d]Invalid connector\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_2344C7;
    return printk(v9, "dp_bridge_disable");
  }
  if ( !*(_QWORD *)(a1 + 1120) )
  {
    v11 = get_ipc_log_context();
    ipc_log_string(v11, "[e][%-4d]Invalid dp_panel\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_248981;
    return printk(v9, "dp_bridge_disable");
  }
  v2 = *(_QWORD *)(a1 + 312);
  if ( !v2 )
  {
    v12 = get_ipc_log_context();
    ipc_log_string(v12, "[e][%-4d]dp is null\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_218F43;
    return printk(v9, "dp_bridge_disable");
  }
  sde_connector_helper_bridge_disable();
  v3 = *(__int64 (__fastcall **)(__int64, __int64))(v2 + 96);
  v4 = *(_QWORD *)(a1 + 1120);
  if ( *((_DWORD *)v3 - 1) != -1533774139 )
    __break(0x8228u);
  result = v3(v2, v4);
  if ( (_DWORD)result )
  {
    v6 = result;
    v7 = get_ipc_log_context();
    ipc_log_string(
      v7,
      "[e][%-4d][%d] DP display pre disable failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a1 + 296),
      v6);
    return printk(&unk_2456DC, "dp_bridge_disable");
  }
  return result;
}
