__int64 __fastcall gi3c_gsi_tx_cb(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v5; // x19
  unsigned int v13; // w9

  if ( !a1 )
    return printk(&unk_14F8D, "gi3c_gsi_tx_cb", a3, a4);
  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
    return printk(&unk_14F8D, "gi3c_gsi_tx_cb", a3, a4);
  v5 = *(_QWORD *)(v4 + 24);
  gi3c_gsi_cb_err();
  _X8 = (unsigned int *)(v5 + 11944);
  __asm { PRFM            #0x11, [X8] }
  do
    v13 = __ldxr(_X8);
  while ( __stxr(v13 + 1, _X8) );
  ipc_log_string(
    *(_QWORD *)(v5 + 2528),
    "%s rnw:%d irq_cnt:%d\n",
    "gi3c_gsi_tx_cb",
    *(_DWORD *)(v5 + 21272),
    *(_DWORD *)(v5 + 11944));
  if ( *(_QWORD *)(v5 + 8) )
    i3c_trace_log();
  return complete_all(v5 + 2552);
}
