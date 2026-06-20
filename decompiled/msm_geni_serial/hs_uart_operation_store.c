__int64 __fastcall hs_uart_operation_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w8
  __int64 v7; // x0
  int v8; // w0
  unsigned __int16 v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v10 = 0;
  v6 = kstrtou16(a3, 16, &v10);
  v7 = *(_QWORD *)(v5 + 960);
  if ( v6 )
  {
    ipc_log_string(v7, "%s: Invalid input\n", "hs_uart_operation_store");
    _ftrace_dbg(*(_QWORD *)(v5 + 344), "%s: Invalid input\n");
    a4 = -22;
  }
  else
  {
    ipc_log_string(v7, "%s: cmd: %u\n", "hs_uart_operation_store", v10);
    _ftrace_dbg(*(_QWORD *)(v5 + 344), "%s: cmd: %u\n");
    v8 = msm_geni_serial_ioctl(v5, v10);
    if ( v10 == 21740 || v10 == 21743 || !v8 )
    {
      *(_DWORD *)(v5 + 1340) = v8;
    }
    else
    {
      ipc_log_string(
        *(_QWORD *)(v5 + 960),
        "%s: Can not perform operation cmd: 0x%x ret: %d\n",
        "hs_uart_operation_store",
        v10,
        v8);
      _ftrace_dbg(*(_QWORD *)(v5 + 344), "%s: Can not perform operation cmd: 0x%x ret: %d\n");
      a4 = -22;
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
