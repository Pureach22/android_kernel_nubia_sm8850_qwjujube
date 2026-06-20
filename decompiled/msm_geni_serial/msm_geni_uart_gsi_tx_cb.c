void __fastcall msm_geni_uart_gsi_tx_cb(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x22
  int v3; // w9
  int v4; // w10
  int v5; // w8
  int v6; // w9
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x20

  v1 = *(_QWORD *)(a1 + 32);
  v2 = *(_QWORD *)(v1 + 208);
  ipc_log_string(*(_QWORD *)(v1 + 960), "%s: Start\n", "msm_geni_uart_gsi_tx_cb");
  _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s: Start\n");
  v3 = *(_DWORD *)(v1 + 816);
  *(_DWORD *)(*(_QWORD *)(v1 + 208) + 380LL) += v3;
  v4 = *(unsigned __int8 *)(v1 + 2001);
  v5 = *(_DWORD *)(v1 + 236) + v3;
  *(_DWORD *)(v1 + 236) = v5;
  if ( v4 == 1 )
  {
    *(_BYTE *)(v1 + 2001) = 0;
  }
  else
  {
    geni_se_tx_dma_unprep(v1 + 712, *(_QWORD *)(v1 + 808), *(unsigned int *)(v1 + 816));
    v5 = *(_DWORD *)(v1 + 236);
  }
  v6 = *(_DWORD *)(v1 + 816);
  *(_QWORD *)(v1 + 808) = 0;
  *(_DWORD *)(v1 + 816) = 0;
  *(_DWORD *)(v1 + 236) = v5 + v6;
  complete(v1 + 1296);
  if ( *(_DWORD *)(v2 + 376) == *(_DWORD *)(v2 + 380) )
  {
    v7 = *(_QWORD *)(v1 + 264);
    if ( !v7 || *(_DWORD *)(v1 + 316) != *(__int16 *)(v7 + 74) )
    {
      ipc_log_string(*(_QWORD *)(v1 + 960), "%s.Tx sent out, Power off\n", "msm_geni_uart_gsi_tx_cb");
      _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s.Tx sent out, Power off\n");
      v9 = *(_QWORD *)(v1 + 344);
      if ( *(_DWORD *)(v9 + 480) )
      {
        if ( (*(_WORD *)(v9 + 488) & 7) == 0 )
        {
          *(_QWORD *)(v9 + 520) = ktime_get_mono_fast_ns(v8);
          _pm_runtime_suspend(*(_QWORD *)(v1 + 344), 13);
        }
      }
      else
      {
        ipc_log_string(*(_QWORD *)(v1 + 952), "%s: Usage Count is already 0\n", "msm_geni_serial_power_off");
        _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s: Usage Count is already 0\n");
      }
    }
    uart_write_wakeup(v1);
  }
  else
  {
    queue_work_on(32, *(_QWORD *)(v1 + 1248), v1 + 1152);
    ipc_log_string(*(_QWORD *)(v1 + 960), "%s: End\n", "msm_geni_uart_gsi_tx_cb");
    _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s: End\n");
  }
  ipc_log_string(*(_QWORD *)(v1 + 960), "%s:End\n", "msm_geni_uart_gsi_tx_cb");
  _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s:End\n");
}
