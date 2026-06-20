__int64 __fastcall gsi_common_rx_cb(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  unsigned __int8 *v7; // x19
  void (*v8)(void); // x8

  if ( !a1 )
    return printk(&unk_13EA3, "gsi_common_rx_cb", a3, a4, a5, a6, a7);
  v7 = *(unsigned __int8 **)(a1 + 32);
  if ( !v7 )
    return printk(&unk_13EA3, "gsi_common_rx_cb", a3, a4, a5, a6, a7);
  v8 = *((void (**)(void))v7 + 2309);
  if ( *((_DWORD *)v8 - 1) != 251140989 )
    __break(0x8228u);
  v8();
  return ipc_log_string(*((_QWORD *)v7 + 2310), "%s: protocol:%d\n", "gsi_common_rx_cb", *v7);
}
