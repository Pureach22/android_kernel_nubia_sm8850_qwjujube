__int64 __fastcall sme_roam_start_beacon_req(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  unsigned int started; // w20

  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    started = csr_roam_start_beacon_req(a1, a2 & 0xFFFFFFFFFFFFLL, a3);
    qdf_mutex_release(a1 + 12848);
    return started;
  }
  return result;
}
