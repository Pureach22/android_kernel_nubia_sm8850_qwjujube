__int64 __fastcall sme_update_add_ie(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  unsigned int updated; // w20

  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    updated = csr_roam_update_add_ies(a1, a2, a3);
    qdf_mutex_release(a1 + 12776);
    return updated;
  }
  return result;
}
