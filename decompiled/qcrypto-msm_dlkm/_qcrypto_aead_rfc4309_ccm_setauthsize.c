__int64 __fastcall qcrypto_aead_rfc4309_ccm_setauthsize(__int64 a1, unsigned int a2)
{
  __int64 result; // x0

  result = 4294967274LL;
  if ( a2 <= 0x10 && ((1 << a2) & 0x11100) != 0 )
  {
    *(_DWORD *)(a1 + 228) = a2;
    return 0;
  }
  return result;
}
