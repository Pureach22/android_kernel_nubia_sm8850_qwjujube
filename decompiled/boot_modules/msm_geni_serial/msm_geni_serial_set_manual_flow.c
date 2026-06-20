void __fastcall msm_geni_serial_set_manual_flow(char a1, __int64 a2)
{
  unsigned int *v3; // x1
  int v4; // w0
  int v5; // w3
  _QWORD *v6; // x8
  _QWORD *v7; // x22

  v3 = (unsigned int *)(*(_QWORD *)(a2 + 16) + 684LL);
  if ( (a1 & 1) == 0 )
  {
    writel_relaxed(0x80000000, v3);
    _const_udelay(42950);
    writel_relaxed(0x80000002, (unsigned int *)(*(_QWORD *)(a2 + 16) + 684LL));
    __dsb(0xFu);
    ipc_log_string(
      *(_QWORD *)(a2 + 960),
      "%s: Manual Flow Enabled, HW Flow OFF rfr = 0x%x\n",
      "msm_geni_serial_set_manual_flow",
      -2147483646);
    _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s: Manual Flow Enabled, HW Flow OFF rfr = 0x%x\n");
    if ( (*(_BYTE *)(a2 + 1036) & 1) != 0 )
      return;
    v5 = 21;
    v6 = (_QWORD *)(a2 + 960);
    v7 = (_QWORD *)(a2 + 344);
    *(_DWORD *)(a2 + 1120) = 21;
    goto LABEL_7;
  }
  writel_relaxed(0, v3);
  __dsb(0xFu);
  v4 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 16) + 684LL));
  ipc_log_string(
    *(_QWORD *)(a2 + 960),
    "%s: Manual Flow Disabled, HW Flow ON rfr = 0x%x\n",
    "msm_geni_serial_set_manual_flow",
    v4);
  _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s: Manual Flow Disabled, HW Flow ON rfr = 0x%x\n");
  if ( *(_DWORD *)(a2 + 1120) == 21 && (*(_BYTE *)(a2 + 1036) & 1) == 0 )
  {
    v5 = 0;
    v6 = (_QWORD *)(a2 + 960);
    v7 = (_QWORD *)(a2 + 344);
    *(_DWORD *)(a2 + 1120) = 0;
LABEL_7:
    ipc_log_string(*v6, "%s uart_error_code %d", "msm_geni_update_uart_error_code", v5);
    _ftrace_dbg(*v7, "%s uart_error_code %d");
  }
}
