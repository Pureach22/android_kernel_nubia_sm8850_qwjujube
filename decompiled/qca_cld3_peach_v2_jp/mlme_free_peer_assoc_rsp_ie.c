__int64 __fastcall mlme_free_peer_assoc_rsp_ie(
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

  if ( !a1 )
    return qdf_trace_msg(
             0x1Fu,
             8u,
             "%s: peer priv is NULL",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "mlme_free_peer_assoc_rsp_ie");
  result = *(_QWORD *)(a1 + 64);
  if ( result )
  {
    result = _qdf_mem_free(result);
    *(_QWORD *)(a1 + 64) = 0;
    *(_DWORD *)(a1 + 56) = 0;
  }
  return result;
}
