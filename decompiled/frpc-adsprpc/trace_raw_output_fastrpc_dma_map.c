__int64 __fastcall trace_raw_output_fastrpc_dma_map(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "cid %d, fd %d, phys 0x%llx, size %zu (len %zu), attr 0x%x, flags 0x%x\n",
      *(_DWORD *)(v1 + 8),
      *(_DWORD *)(v1 + 12),
      *(_QWORD *)(v1 + 16),
      *(_QWORD *)(v1 + 24),
      *(_QWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 40),
      *(_DWORD *)(v1 + 44));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
