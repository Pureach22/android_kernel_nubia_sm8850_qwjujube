__int64 __fastcall sme_get_tsm_stats(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned int a5)
{
  __int64 result; // x0
  unsigned int tsm_stats; // w20

  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    tsm_stats = csr_get_tsm_stats(a1, a2, a3 & 0xFFFFFFFFFFFFLL, a4, a5);
    qdf_mutex_release(a1 + 12848);
    return tsm_stats;
  }
  return result;
}
