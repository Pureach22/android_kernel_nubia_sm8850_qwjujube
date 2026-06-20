__int64 __fastcall dp_bridge_post_disable(__int64 a1)
{
  __int64 v2; // x20
  __int64 (__fastcall *v3)(_QWORD); // x8
  int v4; // w0
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  __int64 v6; // x1
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  void *v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  int v12; // w20
  __int64 v13; // x0
  int v14; // w20
  __int64 v15; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_21CA0C;
    return printk(v9, "dp_bridge_post_disable");
  }
  if ( !*(_QWORD *)(a1 + 304) )
  {
    v10 = get_ipc_log_context();
    ipc_log_string(v10, "[e][%-4d]Invalid connector\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_2344C7;
    return printk(v9, "dp_bridge_post_disable");
  }
  if ( !*(_QWORD *)(a1 + 1120) )
  {
    v11 = get_ipc_log_context();
    ipc_log_string(v11, "[e][%-4d]Invalid dp_panel\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_248981;
    return printk(v9, "dp_bridge_post_disable");
  }
  v2 = *(_QWORD *)(a1 + 312);
  v3 = *(__int64 (__fastcall **)(_QWORD))(v2 + 104);
  if ( *((_DWORD *)v3 - 1) != -1533774139 )
    __break(0x8228u);
  v4 = v3(v2);
  if ( v4 )
  {
    v12 = v4;
    v13 = get_ipc_log_context();
    ipc_log_string(
      v13,
      "[e][%-4d][%d] DP display disable failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a1 + 296),
      v12);
    v9 = &unk_26F8B3;
    return printk(v9, "dp_bridge_post_disable");
  }
  v5 = *(__int64 (__fastcall **)(__int64, __int64))(v2 + 144);
  v6 = *(_QWORD *)(a1 + 1120);
  if ( *((_DWORD *)v5 - 1) != -1533774139 )
    __break(0x8228u);
  result = v5(v2, v6);
  if ( (_DWORD)result )
  {
    v14 = result;
    v15 = get_ipc_log_context();
    ipc_log_string(
      v15,
      "[e][%-4d][%d] DP display unprepare failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a1 + 296),
      v14);
    v9 = &unk_2118F3;
    return printk(v9, "dp_bridge_post_disable");
  }
  return result;
}
