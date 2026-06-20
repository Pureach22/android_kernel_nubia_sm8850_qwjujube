__int64 __fastcall msm_geni_serial_get_mctrl(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x8
  unsigned int v4; // w20
  int v5; // w8
  __int64 v6; // x8
  __int64 v7; // x0
  unsigned int v8; // w21

  v1 = *(_QWORD *)(a1 + 264);
  if ( v1 && *(_DWORD *)(a1 + 316) == *(__int16 *)(v1 + 74)
    || (v3 = *(_QWORD *)(a1 + 344), !*(_DWORD *)(v3 + 500))
    || (*(_WORD *)(v3 + 488) & 7) != 0 )
  {
    v4 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 2312LL));
    if ( (v4 & 2) != 0 )
    {
      v6 = *(_QWORD *)(a1 + 264);
      if ( (!v6 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v6 + 74)) && (*(_BYTE *)(a1 + 1036) & 1) == 0 )
      {
        v7 = *(_QWORD *)(a1 + 960);
        *(_DWORD *)(a1 + 1120) = 20;
        ipc_log_string(v7, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 20);
        _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s uart_error_code %d");
      }
      v5 = 320;
    }
    else
    {
      v5 = 352;
    }
    if ( *(_BYTE *)(a1 + 1008) )
      v8 = v5;
    else
      v8 = v5 | 4;
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s: geni_ios:0x%x, mctrl:0x%x\n", "msm_geni_serial_get_mctrl", v4, v8);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: geni_ios:0x%x, mctrl:0x%x\n");
  }
  else
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 960),
      "%s.Device is not in active state, %s\n",
      "msm_geni_serial_get_mctrl",
      (const char *)(_ReadStatusReg(SP_EL0) + 2320));
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s.Device is not in active state, %s\n");
    return 352;
  }
  return v8;
}
