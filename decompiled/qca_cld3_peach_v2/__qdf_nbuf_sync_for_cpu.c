__int64 __fastcall _qdf_nbuf_sync_for_cpu(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  if ( !*(_QWORD *)(a2 + 40) )
    return qdf_trace_msg(56, 2, "%s: ERROR: NBUF mapped physical address is NULL", "__qdf_nbuf_sync_single_for_cpu");
  result = *(_QWORD *)(a1 + 40);
  if ( (*(_BYTE *)(result + 844) & 0x40) == 0 )
    return _dma_sync_single_for_cpu();
  return result;
}
