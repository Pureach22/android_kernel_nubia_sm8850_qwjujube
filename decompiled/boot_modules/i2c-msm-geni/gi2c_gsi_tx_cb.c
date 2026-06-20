__int64 __fastcall gi2c_gsi_tx_cb(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  unsigned int v11; // w8

  if ( !a1 )
    return printk(&unk_10E45, "gi2c_gsi_tx_cb", a3);
  v3 = *(_QWORD *)(a1 + 32);
  if ( !v3 )
    return printk(&unk_10E45, "gi2c_gsi_tx_cb", a3);
  _X21 = (unsigned int *)(v3 + 1364);
  if ( (*(_BYTE *)(v3 + 9105) & 1) == 0 )
    gi2c_gsi_cb_err();
  __asm { PRFM            #0x11, [X21] }
  do
    v11 = __ldxr(_X21);
  while ( __stxr(v11 + 1, _X21) );
  ipc_log_string(
    *(_QWORD *)(v3 + 5096),
    "%s:tx_cnt:%d gsi_err:%d gi2c_err:%d irq_cnt:%d\n",
    "gi2c_gsi_tx_cb",
    *(_DWORD *)(v3 + 1352),
    *(unsigned __int8 *)(v3 + 9112),
    *(_DWORD *)(v3 + 24),
    *(_DWORD *)(v3 + 1364));
  if ( *(_QWORD *)v3 )
    i2c_trace_log();
  return complete_all(v3 + 1272);
}
