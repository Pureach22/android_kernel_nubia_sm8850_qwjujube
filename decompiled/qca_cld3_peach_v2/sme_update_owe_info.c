__int64 __fastcall sme_update_owe_info(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int updated; // w20

  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    updated = csr_update_owe_info(a1, a2);
    qdf_mutex_release(a1 + 12848);
    return updated;
  }
  return result;
}
