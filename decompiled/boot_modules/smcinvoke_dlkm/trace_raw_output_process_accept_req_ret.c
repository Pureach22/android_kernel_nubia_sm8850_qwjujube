__int64 __fastcall trace_raw_output_process_accept_req_ret(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "si_comm=%s ac_cbobj_id=0x%016llx ac_txn_id=0x%08x ac_op=0x%08x counts=%u ac_result=%d\n",
      (const char *)(v1 + 8),
      *(_QWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 64),
      *(_DWORD *)(v1 + 68),
      *(_DWORD *)(v1 + 72),
      *(_DWORD *)(v1 + 76));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
