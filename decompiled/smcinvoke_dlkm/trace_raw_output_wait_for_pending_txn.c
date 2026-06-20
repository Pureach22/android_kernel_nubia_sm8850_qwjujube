__int64 __fastcall trace_raw_output_wait_for_pending_txn(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "cb_si_comm=%s cb_context_id=0x%08x cb_u_handle=0x%016llx op=0x%08lx ret=%d\n",
      (const char *)(v1 + 8),
      *(_DWORD *)(*(_QWORD *)(v1 + 56) + 4LL),
      *(_QWORD *)(*(_QWORD *)(v1 + 56) + 8LL),
      *(_QWORD *)(*(_QWORD *)(v1 + 56) + 16LL),
      *(_DWORD *)(v1 + 64));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
