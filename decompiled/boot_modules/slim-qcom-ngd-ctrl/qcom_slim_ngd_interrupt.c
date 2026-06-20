__int64 __fastcall qcom_slim_ngd_interrupt(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v4; // x21
  unsigned int v5; // w20
  int v6; // w8
  int v8; // w8
  __int64 v9; // x0

  v2 = *(_QWORD *)(a2 + 928);
  v4 = *(_QWORD *)(*(_QWORD *)(a2 + 1960) + 8LL);
  if ( *(_DWORD *)(v2 + 500) != 2 || (*(_WORD *)(v2 + 488) & 7) != 0 )
  {
    v5 = readl(v4 + 20);
    if ( (v5 & 0x2E000000) != 0 )
    {
      _slimbus_dbg();
      v6 = *(_DWORD *)(a2 + 5476);
      if ( v6 >= 2 )
      {
        printk(&unk_CC6F, v5);
        ipc_log_string(*(_QWORD *)(a2 + 5488), "Error Interrupt received 0x%x\n", v5);
        if ( *(_DWORD *)(a2 + 5476) )
          goto LABEL_7;
        goto LABEL_6;
      }
      if ( !v6 )
LABEL_6:
        ipc_log_string(*(_QWORD *)(a2 + 5496), "Error Interrupt received 0x%x\n", v5);
    }
LABEL_7:
    writel(v5, v4 + 24);
    return 1;
  }
  _slimbus_dbg();
  v8 = *(_DWORD *)(a2 + 5476);
  if ( v8 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(a2 + 5488), "Slimbus is in suspend state %d\n", *(unsigned __int8 *)(a2 + 5508));
    v8 = *(_DWORD *)(a2 + 5476);
  }
  if ( !v8 )
    ipc_log_string(*(_QWORD *)(a2 + 5496), "Slimbus is in suspend state %d\n", *(unsigned __int8 *)(a2 + 5508));
  if ( (qcom_slim_ngd_interrupt___print_once & 1) == 0 )
  {
    v9 = *(_QWORD *)(a2 + 1968);
    qcom_slim_ngd_interrupt___print_once = 1;
    dev_warn(v9, "Interrupt received while suspended\n");
  }
  return 0;
}
