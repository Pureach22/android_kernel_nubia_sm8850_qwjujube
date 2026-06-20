__int64 __fastcall dp_panel_read_sink_sts(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x0
  __int64 ipc_log_context; // x0
  int v7; // w20
  __int64 v8; // x0

  if ( !a1 || !a2 || !a3 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_panel_read_sink_sts");
    return 4294967274LL;
  }
  v4 = drm_dp_dpcd_read(*(_QWORD *)(*(_QWORD *)(a1 + 1192) + 24LL), 8194, a2, a3);
  if ( (_DWORD)v4 != a3 )
  {
    v7 = v4;
    v8 = get_ipc_log_context(v4);
    ipc_log_string(
      v8,
      "[e][%-4d]dpcd sink sts fail rlen:%d size:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v7,
      a3);
    printk(&unk_2647A6, "dp_panel_read_sink_sts");
    return 4294967274LL;
  }
  return 0;
}
