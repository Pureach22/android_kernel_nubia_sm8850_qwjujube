__int64 __fastcall sme_roam_csa_ie_request(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        unsigned int a6,
        unsigned int a7,
        unsigned int a8)
{
  __int64 result; // x0
  unsigned int v17; // w19

  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    v17 = csr_roam_send_chan_sw_ie_request(a1, a2 & 0xFFFFFFFFFFFFLL, a3, a4, a5, a6, a7, a8);
    qdf_mutex_release(a1 + 12776);
    return v17;
  }
  return result;
}
