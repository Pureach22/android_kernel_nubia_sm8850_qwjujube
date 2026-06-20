__int64 __fastcall dp_bridge_pre_enable(__int64 a1)
{
  _QWORD *v2; // x20
  __int64 (__fastcall *v3)(_QWORD); // x8
  int v4; // w0
  _DWORD *v5; // x8
  __int64 v6; // x1
  int v7; // w0
  _DWORD *v8; // x8
  __int64 v9; // x1
  _DWORD *v10; // x8
  __int64 v11; // x1
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  void *v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  int v17; // w20
  __int64 v18; // x0
  int v19; // w20
  __int64 v20; // x0
  int v21; // w20
  __int64 v22; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v14 = &unk_21CA0C;
    return printk(v14, "dp_bridge_pre_enable");
  }
  if ( !*(_QWORD *)(a1 + 304) )
  {
    v15 = get_ipc_log_context();
    ipc_log_string(v15, "[e][%-4d]Invalid connector\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v14 = &unk_2344C7;
    return printk(v14, "dp_bridge_pre_enable");
  }
  if ( !*(_QWORD *)(a1 + 1120) )
  {
    v16 = get_ipc_log_context();
    ipc_log_string(v16, "[e][%-4d]Invalid dp_panel\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v14 = &unk_248981;
    return printk(v14, "dp_bridge_pre_enable");
  }
  v2 = *(_QWORD **)(a1 + 312);
  v3 = (__int64 (__fastcall *)(_QWORD))v2[14];
  if ( *((_DWORD *)v3 - 1) != -723972362 )
    __break(0x8228u);
  v4 = v3(v2);
  if ( v4 )
  {
    v17 = v4;
    v18 = get_ipc_log_context();
    ipc_log_string(
      v18,
      "[e][%-4d][%d] failed to perform a mode set, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a1 + 296),
      v17);
    v14 = &unk_21FFB1;
    return printk(v14, "dp_bridge_pre_enable");
  }
  v5 = (_DWORD *)v2[17];
  v6 = *(_QWORD *)(a1 + 1120);
  if ( *(v5 - 1) != -1533774139 )
    __break(0x8228u);
  v7 = ((__int64 (__fastcall *)(_QWORD *, __int64))v5)(v2, v6);
  if ( v7 )
  {
    v19 = v7;
    v20 = get_ipc_log_context();
    ipc_log_string(
      v20,
      "[e][%-4d][%d] DP display prepare failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a1 + 296),
      v19);
    v14 = &unk_252DF9;
    return printk(v14, "dp_bridge_pre_enable");
  }
  v8 = (_DWORD *)v2[33];
  v9 = *(_QWORD *)(a1 + 1120);
  if ( *(v8 - 1) != -133057824 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD *, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))v8)(v2, v9, 0, 0, 0, 0, 0);
  v10 = (_DWORD *)v2[10];
  v11 = *(_QWORD *)(a1 + 1120);
  if ( *(v10 - 1) != -1533774139 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(_QWORD *, __int64))v10)(v2, v11);
  if ( (_DWORD)result )
  {
    v21 = result;
    v22 = get_ipc_log_context();
    ipc_log_string(
      v22,
      "[e][%-4d][%d] DP display enable failed, rc=%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a1 + 296),
      v21);
    v14 = &unk_230FDA;
    return printk(v14, "dp_bridge_pre_enable");
  }
  return result;
}
