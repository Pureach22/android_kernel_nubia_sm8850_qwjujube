__int64 __fastcall dms_del_server(__int64 a1)
{
  unsigned __int64 v9; // x10

  _X8 = (unsigned __int64 *)(a1 + 904);
  __asm { PRFM            #0x11, [X8] }
  do
    v9 = __ldxr(_X8);
  while ( __stxr(v9 & 0xFFFFFFFFFFBFFFFFLL, _X8) );
  printk("%sicnss2_qmi: QMI DMS service disconnected, state: 0x%lx\n", byte_13289B, *(_QWORD *)(a1 + 904));
  return ipc_log_string(
           icnss_ipc_log_context,
           "%sicnss2_qmi: QMI DMS service disconnected, state: 0x%lx\n",
           (const char *)&unk_12DBF3,
           *(_QWORD *)(a1 + 904));
}
