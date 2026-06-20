__int64 __fastcall dp_connector_config_hdr(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 (__fastcall *v4)(__int64, __int64, __int64, __int64); // x9
  __int64 v5; // x3
  __int64 v6; // x2
  __int64 ipc_log_context; // x0
  void *v9; // x0
  __int64 v10; // x0

  if ( !a1 || !a2 || !a3 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_24B695;
LABEL_11:
    printk(v9, "dp_connector_config_hdr");
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(a1 + 2768);
  if ( !v3 )
  {
    v10 = get_ipc_log_context();
    ipc_log_string(v10, "[e][%-4d]invalid dp panel\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_2238C5;
    goto LABEL_11;
  }
  v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a2 + 176);
  v5 = *(unsigned __int8 *)(a3 + 3228);
  v6 = a3 + 3112;
  if ( *((_DWORD *)v4 - 1) != -352580039 )
    __break(0x8229u);
  return v4(a2, v3, v6, v5);
}
