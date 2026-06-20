__int64 __fastcall qcrypto_setkey_aes(__int64 a1, const void *a2, size_t n)
{
  int v3; // w8
  __int64 v5; // x8

  v3 = *(_DWORD *)(a1 + 72);
  if ( (v3 & 1) != 0 )
    return 0;
  if ( (_DWORD)n != 16 && (_DWORD)n != 32 )
  {
    if ( (_DWORD)n != 24 )
      return 4294967274LL;
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 64) + 21LL) & 1) == 0 )
    {
      v5 = *(_QWORD *)(a1 + 240);
      if ( v5 )
      {
        *(_DWORD *)(a1 + 224) = 24;
        *(_DWORD *)(v5 + 12) &= 0xFFF000FF;
        *(_DWORD *)(*(_QWORD *)(a1 + 240) + 12LL) |= *(_DWORD *)(a1 + 12) & 0xFFF00;
        return crypto_skcipher_setkey(*(_QWORD *)(a1 + 240), a2, 24);
      }
      return 4294967274LL;
    }
  }
  *(_DWORD *)(a1 + 224) = n;
  if ( (v3 & 2) == 0 )
  {
    if ( a2 )
    {
      memcpy((void *)(a1 + 160), a2, (unsigned int)n);
      return 0;
    }
    printk(&unk_12422, "_qcrypto_setkey_aes");
    return 4294967274LL;
  }
  return 0;
}
