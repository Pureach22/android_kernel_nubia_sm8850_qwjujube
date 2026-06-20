__int64 __fastcall dp_catalog_ctrl_reset(__int64 a1)
{
  __int64 v1; // x20
  __int64 (__fastcall *v2)(__int64, __int64, __int64); // x8
  __int64 v3; // x21
  __int64 v5; // x0
  int v6; // w0
  _DWORD *v7; // x8
  int v8; // w22
  _DWORD *v9; // x8
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 - 224);
    v2 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
    v3 = a1 - 232;
    v5 = a1 - 232;
    if ( *((_DWORD *)v2 - 1) != -1879227436 )
      __break(0x8228u);
    v6 = v2(v5, v1, 16);
    v7 = *(_DWORD **)(a1 - 104);
    v8 = v6;
    if ( *(v7 - 1) != -626862723 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v7)(v3, v1, 16, v6 | 1u);
    usleep_range_state(1000, 1010, 2);
    v9 = *(_DWORD **)(a1 - 104);
    if ( *(v9 - 1) != -626862723 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v9)(v3, v1, 16, v8 & 0xFFFFFFFE);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_ctrl_reset");
  }
}
