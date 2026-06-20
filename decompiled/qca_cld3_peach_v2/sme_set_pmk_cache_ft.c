__int64 __fastcall sme_set_pmk_cache_ft(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v7; // w20

  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    v7 = csr_set_pmk_cache_ft(a1, a2, a3);
    qdf_mutex_release(a1 + 12848);
    return v7;
  }
  return result;
}
