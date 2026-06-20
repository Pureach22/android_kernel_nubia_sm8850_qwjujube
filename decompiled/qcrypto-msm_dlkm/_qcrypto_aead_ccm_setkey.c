__int64 __fastcall qcrypto_aead_ccm_setkey(__int64 a1, const void *a2, size_t n)
{
  size_t v3; // x19
  int v5; // w22

  if ( (_DWORD)n == 16 || (_DWORD)n == 32 || (_DWORD)n == 24 && (*(_BYTE *)(*(_QWORD *)(a1 + 64) + 21LL) & 1) != 0 )
  {
    v3 = (unsigned int)n;
    *(_DWORD *)(a1 + 224) = n;
    v5 = n;
    memcpy((void *)(a1 + 160), a2, (unsigned int)n);
    *(_DWORD *)(a1 + 232) = v5;
    memcpy((void *)(a1 + 80), a2, v3);
    return 0;
  }
  else
  {
    *(_DWORD *)(a1 + 224) = 0;
    return 4294967274LL;
  }
}
