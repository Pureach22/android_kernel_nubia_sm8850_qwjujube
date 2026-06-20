__int64 __fastcall dp_catalog_ctrl_read_hdcp_status(__int64 a1)
{
  __int64 v1; // x1
  __int64 (__fastcall *v2)(__int64, __int64, __int64); // x8
  __int64 v3; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 - 224);
    v2 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
    v3 = a1 - 232;
    if ( *((_DWORD *)v2 - 1) != -1879227436 )
      __break(0x8228u);
    return v2(v3, v1, 164);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_catalog_ctrl_read_hdcp_status");
    return 4294967274LL;
  }
}
