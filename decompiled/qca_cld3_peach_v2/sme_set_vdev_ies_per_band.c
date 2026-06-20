__int64 __fastcall sme_set_vdev_ies_per_band(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0

  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    csr_set_vdev_ies_per_band(a1, a2, a3);
    return qdf_mutex_release(a1 + 12848);
  }
  return result;
}
