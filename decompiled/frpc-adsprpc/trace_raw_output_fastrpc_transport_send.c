__int64 __fastcall trace_raw_output_fastrpc_transport_send(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "to cid %d: smq_ctx 0x%llx, ctx 0x%llx, handle 0x%x, sc 0x%x, addr 0x%llx, size %llu\n",
      *(_DWORD *)(v1 + 8),
      *(_QWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 36),
      *(_QWORD *)(v1 + 40),
      *(_QWORD *)(v1 + 48));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
