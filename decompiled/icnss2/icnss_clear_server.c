__int64 __fastcall icnss_clear_server(__int64 a1)
{
  __int64 v3; // x8
  __int64 v4; // x3
  unsigned __int64 v11; // x11
  unsigned __int64 v14; // x10
  unsigned __int64 v17; // x11

  if ( !a1 )
    return 4294967277LL;
  printk("%sicnss2_qmi: QMI Service Disconnected: 0x%lx\n", byte_13289B, *(_QWORD *)(a1 + 1832));
  ipc_log_string(
    icnss_ipc_log_context,
    "%sicnss2_qmi: QMI Service Disconnected: 0x%lx\n",
    (const char *)&unk_12DBF3,
    *(_QWORD *)(a1 + 1832));
  _X9 = (unsigned __int64 *)(a1 + 1832);
  __asm { PRFM            #0x11, [X9] }
  do
    v11 = __ldxr(_X9);
  while ( __stxr(v11 & 0xFFFFFFFFFFFFFFFELL, _X9) );
  _X9 = (unsigned __int64 *)(a1 + 1832);
  __asm { PRFM            #0x11, [X9] }
  do
    v14 = __ldxr(_X9);
  while ( __stxr(v14 | 0x100000, _X9) );
  qmi_handle_release(a1 + 624);
  _X9 = (unsigned __int64 *)(a1 + 1832);
  __asm { PRFM            #0x11, [X9] }
  do
    v17 = __ldxr(_X9);
  while ( __stxr(v17 & 0xFFFFFFFFFFEFFFFFLL, _X9) );
  if ( (qmi_handle_init(a1 + 624, 6182, wlfw_qmi_ops, &wlfw_msg_handlers) & 0x80000000) != 0 )
    goto LABEL_12;
  v3 = *(_QWORD *)(a1 + 304);
  v4 = 3;
  if ( v3 != 25680 && v3 != 26448 && v3 != 30544 )
    v4 = 0;
  if ( (qmi_add_lookup(a1 + 624, 69, 1, v4) & 0x80000000) != 0 )
  {
LABEL_12:
    printk("%sicnss2_qmi: WLFW server registration failed\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2_qmi: WLFW server registration failed\n", (const char *)&unk_12DBF3);
  }
  return 0;
}
