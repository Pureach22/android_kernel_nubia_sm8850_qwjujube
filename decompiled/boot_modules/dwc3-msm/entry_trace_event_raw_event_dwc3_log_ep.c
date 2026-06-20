__int64 __fastcall entry_trace_event_raw_event_dwc3_log_ep(__int64 a1, __int64 a2)
{
  dwc3_dbg_trace_ep(dwc_trace_ipc_log_ctxt, *(_QWORD *)(a2 + 8));
  return 0;
}
