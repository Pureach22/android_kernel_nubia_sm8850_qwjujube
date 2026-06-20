__int64 __fastcall entry_trace_event_raw_event_dwc3_log_event(__int64 a1, __int64 a2)
{
  dwc3_dbg_trace_event(dwc_trace_ipc_log_ctxt, *(_DWORD *)(a2 + 8), *(_QWORD *)(a2 + 16));
  return 0;
}
