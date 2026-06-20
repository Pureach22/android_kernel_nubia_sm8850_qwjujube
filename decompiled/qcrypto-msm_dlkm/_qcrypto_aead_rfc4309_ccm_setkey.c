__int64 __fastcall qcrypto_aead_rfc4309_ccm_setkey(__int64 a1, _BYTE *a2, unsigned int a3)
{
  bool v3; // cf
  size_t v4; // x2
  __int16 v6; // w8

  v3 = a3 >= 3;
  v4 = a3 - 3;
  if ( !v3 )
    return 4294967274LL;
  v6 = *(_WORD *)&a2[v4];
  *(_BYTE *)(a1 + 238) = a2[v4 + 2];
  *(_WORD *)(a1 + 236) = v6;
  return qcrypto_aead_ccm_setkey(a1, a2, v4);
}
