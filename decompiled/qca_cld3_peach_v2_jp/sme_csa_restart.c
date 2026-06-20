__int64 __fastcall sme_csa_restart(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned int v5; // w20

  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    v5 = csr_csa_restart(a1, a2);
    qdf_mutex_release(a1 + 12776);
    return v5;
  }
  return result;
}
