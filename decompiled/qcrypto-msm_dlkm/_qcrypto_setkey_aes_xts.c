__int64 __fastcall qcrypto_setkey_aes_xts(__int64 a1, const void *a2, size_t n)
{
  int v3; // w8
  unsigned int v4; // w9
  size_t v6; // [xsp+8h] [xbp-18h]
  const void *v7; // [xsp+10h] [xbp-10h]
  __int64 v8; // [xsp+18h] [xbp-8h]

  v3 = *(_DWORD *)(a1 + 72);
  if ( (v3 & 1) != 0 )
    return 0;
  v4 = (unsigned int)n >> 1;
  if ( (unsigned int)n >> 1 != 16 && v4 != 32 && (v4 != 24 || *(_BYTE *)(*(_QWORD *)(a1 + 64) + 21LL) != 1) )
    return 4294967274LL;
  *(_DWORD *)(a1 + 224) = n;
  if ( (v3 & 2) != 0 )
    return 0;
  if ( a2 )
  {
    n = (unsigned int)n;
    if ( (unsigned int)n >= 0x41 && (qcrypto_setkey_aes_xts___already_done & 1) == 0 )
    {
      v8 = a1;
      qcrypto_setkey_aes_xts___already_done = 1;
      v6 = (unsigned int)n;
      v7 = a2;
      _warn_printk(
        "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
        (unsigned int)n,
        "field \"ctx->enc_key\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcrypto.c:1481",
        0x40u);
      n = v6;
      a2 = v7;
      a1 = v8;
      __break(0x800u);
    }
    memcpy((void *)(a1 + 160), a2, n);
    return 0;
  }
  printk(&unk_12422, "_qcrypto_setkey_aes_xts");
  return 4294967274LL;
}
