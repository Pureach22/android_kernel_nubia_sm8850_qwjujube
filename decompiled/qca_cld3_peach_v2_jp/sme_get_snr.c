__int64 __fastcall sme_get_snr(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned int snr; // w20

  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    snr = csr_get_snr(a1, a2, a3 & 0xFFFFFFFFFFFFLL, a4);
    qdf_mutex_release(a1 + 12776);
    return snr;
  }
  return result;
}
