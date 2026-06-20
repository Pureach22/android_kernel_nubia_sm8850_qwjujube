void __fastcall msm_geni_serial_flush(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8

  *(_DWORD *)(a1 + 1496) = 1;
  v1 = *(_QWORD *)(a1 + 264);
  if ( v1 && *(_DWORD *)(a1 + 316) == *(__int16 *)(v1 + 74)
    || (v2 = *(_QWORD *)(a1 + 344), !*(_DWORD *)(v2 + 500))
    || (*(_WORD *)(v2 + 488) & 7) != 0 )
  {
    stop_tx_sequencer(a1);
  }
  else
  {
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s.Device is not in active state.\n", "msm_geni_serial_stop_tx");
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s.Device is not in active state.\n");
  }
}
