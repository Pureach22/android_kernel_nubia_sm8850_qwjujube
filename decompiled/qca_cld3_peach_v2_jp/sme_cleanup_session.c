__int64 __fastcall sme_cleanup_session(__int64 a1, unsigned int a2)
{
  __int64 result; // x0

  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    csr_cleanup_vdev_session(a1, a2);
    return qdf_mutex_release(a1 + 12776);
  }
  return result;
}
