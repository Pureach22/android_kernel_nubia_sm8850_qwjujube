__int64 __fastcall sme_update_rnr_ie(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int updated; // w20

  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    updated = csr_roam_update_rnr_ies(a1, a2);
    qdf_mutex_release(a1 + 12848);
    csr_update_beacon(a1);
    return updated;
  }
  return result;
}
