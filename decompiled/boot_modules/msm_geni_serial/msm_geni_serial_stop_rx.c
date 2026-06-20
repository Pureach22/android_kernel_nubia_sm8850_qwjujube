void __fastcall msm_geni_serial_stop_rx(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x8
  int v4; // w0

  v1 = *(_QWORD *)(a1 + 264);
  if ( v1 && *(_DWORD *)(a1 + 316) == *(__int16 *)(v1 + 74)
    || (v3 = *(_QWORD *)(a1 + 344), !*(_DWORD *)(v3 + 500))
    || (*(_WORD *)(v3 + 488) & 7) != 0 )
  {
    v4 = stop_rx_sequencer(a1);
    if ( v4 )
    {
      ipc_log_string(*(_QWORD *)(a1 + 960), "%s: stop rx failed %d\n", "msm_geni_serial_stop_rx", v4);
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: stop rx failed %d\n");
    }
  }
  else
  {
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s.Device is not in active state.\n", "msm_geni_serial_stop_rx");
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s.Device is not in active state.\n");
    complete(a1 + 1264);
  }
}
