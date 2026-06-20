__int64 __fastcall sme_modify_add_ie(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  unsigned int v7; // w20

  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    v7 = csr_roam_modify_add_ies(a1, a2, a3);
    qdf_mutex_release(a1 + 12848);
    return v7;
  }
  return result;
}
