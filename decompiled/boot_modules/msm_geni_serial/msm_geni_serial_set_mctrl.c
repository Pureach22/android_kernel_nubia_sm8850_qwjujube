void __fastcall msm_geni_serial_set_mctrl(__int64 a1, int a2)
{
  __int64 v2; // x8
  __int64 v5; // x8
  bool v6; // w8
  unsigned int v7; // w21
  unsigned int *v8; // x1
  int v9; // w3
  int v10; // w8
  __int64 v11; // x0
  unsigned __int64 StatusReg; // x24
  const char *v13; // x6

  v2 = *(_QWORD *)(a1 + 264);
  if ( !v2 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v2 + 74) )
  {
    v5 = *(_QWORD *)(a1 + 344);
    if ( *(_DWORD *)(v5 + 500) )
    {
      if ( (*(_WORD *)(v5 + 488) & 7) == 0 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 960),
          "%s.Device is not in active state, %s: mctrl=0x%x\n",
          "msm_geni_serial_set_mctrl",
          (const char *)(_ReadStatusReg(SP_EL0) + 2320),
          a2);
        _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s.Device is not in active state, %s: mctrl=0x%x\n");
        return;
      }
    }
  }
  v6 = (a2 & 4) == 0;
  if ( (a2 & 4) != 0 )
    v7 = 0;
  else
    v7 = -2147483646;
  v8 = (unsigned int *)(*(_QWORD *)(a1 + 16) + 684LL);
  *(_BYTE *)(a1 + 1008) = v6;
  writel_relaxed(v7, v8);
  __dsb(0xFu);
  if ( *(_BYTE *)(a1 + 1008) == 1 )
  {
    if ( (*(_BYTE *)(a1 + 1036) & 1) == 0 )
    {
      v9 = 21;
      *(_DWORD *)(a1 + 1120) = 21;
LABEL_14:
      ipc_log_string(*(_QWORD *)(a1 + 960), "%s uart_error_code %d", "msm_geni_update_uart_error_code", v9);
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s uart_error_code %d");
    }
  }
  else if ( *(_DWORD *)(a1 + 1120) == 21 && (*(_BYTE *)(a1 + 1036) & 1) == 0 )
  {
    v9 = 0;
    *(_DWORD *)(a1 + 1120) = 0;
    goto LABEL_14;
  }
  v10 = *(unsigned __int8 *)(a1 + 1008);
  v11 = *(_QWORD *)(a1 + 960);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( v10 )
    v13 = "OFF";
  else
    v13 = "ON";
  ipc_log_string(
    v11,
    "%s:%s, mctrl=0x%x, manual_rfr=0x%x, flow=%s\n",
    "msm_geni_serial_set_mctrl",
    (const char *)(StatusReg + 2320),
    a2,
    v7,
    v13);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s:%s, mctrl=0x%x, manual_rfr=0x%x, flow=%s\n");
}
