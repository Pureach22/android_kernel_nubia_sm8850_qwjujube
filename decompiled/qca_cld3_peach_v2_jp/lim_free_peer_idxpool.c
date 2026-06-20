__int64 __fastcall lim_free_peer_idxpool(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0

  if ( !*(_QWORD *)(a1 + 16) )
    return qdf_trace_msg(0x35u, 8u, "%s: vdev is null", a2, a3, a4, a5, a6, a7, a8, a9, "lim_free_peer_idxpool");
  result = *(_QWORD *)(a1 + 7240);
  if ( result )
  {
    result = _qdf_mem_free(result);
    *(_QWORD *)(a1 + 7240) = 0;
  }
  return result;
}
