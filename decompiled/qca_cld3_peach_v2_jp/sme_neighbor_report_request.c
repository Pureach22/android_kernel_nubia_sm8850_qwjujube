__int64 __fastcall sme_neighbor_report_request(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  unsigned int v9; // w20

  qdf_trace(52, 0x2Bu, 255, 0);
  if ( *(_BYTE *)(a3 + 35) == 1 )
    return csr_invoke_neighbor_report_request(a2, a3, 0);
  if ( (unsigned int)qdf_mutex_acquire(a1 + 12776) )
    return 16;
  v9 = sme_rrm_neighbor_report_request(a1, a2, a3, a4);
  qdf_mutex_release(a1 + 12776);
  return v9;
}
