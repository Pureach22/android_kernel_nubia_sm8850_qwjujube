__int64 __fastcall dp_catalog_panel_dhdr_busy(__int64 a1)
{
  unsigned int v1; // w8
  bool v2; // zf
  __int64 v3; // x1
  unsigned int (__fastcall *v4)(__int64, __int64, __int64); // x8
  __int64 v5; // x0
  __int64 v6; // x2
  __int64 ipc_log_context; // x0

  v1 = *(_DWORD *)(a1 + 204);
  if ( v1 >= 2 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]invalid stream_id:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a1 + 204));
    printk(&unk_272496, "dp_catalog_panel_dhdr_busy");
    return 0;
  }
  else
  {
    v2 = v1 == 0;
    v3 = *(_QWORD *)(a1 - 552);
    v4 = *(unsigned int (__fastcall **)(__int64, __int64, __int64))(a1 - 456);
    v5 = a1 - 576;
    if ( v2 )
      v6 = 760;
    else
      v6 = 764;
    if ( *((_DWORD *)v4 - 1) != -1879227436 )
      __break(0x8228u);
    return (v4(v5, v3, v6) >> 1) & 1;
  }
}
