__int64 __fastcall qcrypto_aead_setkey(__int64 a1, unsigned __int16 *a2, unsigned int a3)
{
  unsigned int v3; // w8
  size_t v5; // x2
  __int64 v6; // x9
  unsigned int v7; // w8
  char *v8; // x20
  __int64 v9; // x21
  unsigned int *v10; // x19
  size_t v11; // x2
  __int64 v12; // x9
  int v13; // w8
  int v14; // w8
  size_t v16; // [xsp+18h] [xbp+18h]

  if ( a3 >= 4 )
  {
    v3 = *a2;
    if ( v3 >= 4 && v3 <= a3 && (v3 & 0xFFFC) != 4 && a2[1] == 1 )
    {
      v5 = bswap32(*((_DWORD *)a2 + 1));
      *(_DWORD *)(a1 + 224) = v5;
      v6 = (*a2 + 3) & 0x1FFFC;
      v7 = a3 - v6 - v5;
      if ( a3 - (unsigned int)v6 >= (unsigned int)v5 )
      {
        *(_DWORD *)(a1 + 232) = v7;
        if ( (v7 | (unsigned int)v5) <= 0x3F )
        {
          v8 = (char *)a2 + v6;
          v9 = a1;
          *(_QWORD *)(a1 + 80) = 0;
          v10 = (unsigned int *)(a1 + 80);
          *(_QWORD *)(a1 + 128) = 0;
          *(_QWORD *)(a1 + 136) = 0;
          *(_QWORD *)(a1 + 112) = 0;
          *(_QWORD *)(a1 + 120) = 0;
          *(_QWORD *)(a1 + 96) = 0;
          *(_QWORD *)(a1 + 104) = 0;
          *(_QWORD *)(a1 + 88) = 0;
          memcpy((void *)(a1 + 160), (char *)a2 + v6 + v7, v5);
          v11 = v10[38];
          if ( (unsigned int)v11 >= 0x41 && (qcrypto_aead_setkey___already_done_122 & 1) == 0 )
          {
            qcrypto_aead_setkey___already_done_122 = 1;
            v16 = v11;
            _warn_printk(
              "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
              v11,
              "field \"ctx->auth_key\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcrypto.c:3059",
              0x40u);
            v11 = v16;
            __break(0x800u);
          }
          memcpy(v10, v8, v11);
          if ( *(_DWORD *)(v9 + 224) != 24 )
            return 0;
          if ( !*(_QWORD *)(v9 + 240) )
            return 0;
          v12 = *(_QWORD *)(v9 + 248);
          if ( !v12 )
            return 0;
          *(_DWORD *)(v12 + 20) = 0;
          v13 = crypto_ahash_setkey(*(_QWORD *)(v9 + 248), v10, *(unsigned int *)(v9 + 232));
          a1 = v9;
          if ( !v13 )
          {
            *(_DWORD *)(*(_QWORD *)(v9 + 240) + 12LL) = 0;
            v14 = crypto_skcipher_setkey(*(_QWORD *)(v9 + 240), v10 + 20, *(unsigned int *)(v9 + 224));
            a1 = v9;
            if ( !v14 )
              return 0;
          }
        }
      }
    }
  }
  *(_DWORD *)(a1 + 224) = 0;
  return 4294967274LL;
}
