__int64 __fastcall qcrypto_cra_aead_aes_sha256_init(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  unsigned __int64 *v4; // x20
  char v5; // w8
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  __int64 v8; // x0
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 32);
  *(_DWORD *)(a1 + 4) = 456;
  if ( v2 == 1032 )
  {
    printk(&unk_122E0, a2);
    return 4294967274LL;
  }
  *(_DWORD *)(a1 + 72) = 0;
  *(_QWORD *)(a1 + 64) = *(_QWORD *)(v2 + 392);
  get_random_bytes(a1 + 144, 16);
  *(_QWORD *)(a1 + 240) = 0;
  v4 = (unsigned __int64 *)(a1 + 240);
  *(_QWORD *)(a1 + 56) = 0;
  *(_QWORD *)(a1 + 40) = a1 + 40;
  *(_QWORD *)(a1 + 48) = a1 + 40;
  v5 = byte_10815;
  *(_DWORD *)(a1 + 76) = 5;
  *(_QWORD *)(a1 + 248) = 0;
  if ( (v5 & 1) == 0 )
  {
    v6 = crypto_alloc_sync_skcipher("cbc(aes)", 0, 0);
    *v4 = v6;
    if ( v6 > 0xFFFFFFFFFFFFF000LL )
    {
LABEL_6:
      *v4 = 0;
      goto LABEL_7;
    }
    v7 = crypto_alloc_ahash("hmac(sha256)", 0, 0);
    *(_QWORD *)(a1 + 248) = v7;
    if ( v7 >= 0xFFFFFFFFFFFFF001LL )
    {
      v8 = *(_QWORD *)(a1 + 240);
      *(_QWORD *)(a1 + 248) = 0;
      crypto_destroy_tfm(v8, v8 + 8);
      goto LABEL_6;
    }
  }
LABEL_7:
  result = 0;
  *(_DWORD *)(a1 + 76) = 3;
  return result;
}
