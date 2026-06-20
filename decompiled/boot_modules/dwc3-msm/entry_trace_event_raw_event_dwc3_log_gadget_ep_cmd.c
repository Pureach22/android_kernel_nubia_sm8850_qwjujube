__int64 __fastcall entry_trace_event_raw_event_dwc3_log_gadget_ep_cmd(__int64 a1, __int64 a2)
{
  dwc3_dbg_trace_ep_cmd(
    dwc_trace_ipc_log_ctxt,
    *(_QWORD *)(a2 + 8),
    *(_DWORD *)(a2 + 16),
    *(_DWORD **)(a2 + 24),
    *(_DWORD *)(a2 + 32));
  return 0;
}
