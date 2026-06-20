__int64 __fastcall qcrypto_aes_skcipher_init(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v4; // x20
  __int64 v5; // x8
  unsigned __int64 v6; // x0
  __int64 v7; // x8
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 32);
  v4 = a1 + 40;
  if ( byte_1081D != 1 )
  {
    v6 = crypto_alloc_sync_skcipher(v2 + 56, 0, 384);
    *(_QWORD *)(a1 + 240) = v6;
    if ( v6 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_11E6A, v2 + 56);
      result = *(unsigned int *)(a1 + 240);
      *(_QWORD *)(a1 + 240) = 0;
      return result;
    }
    v7 = *(_QWORD *)(a1 + 32);
    *(_DWORD *)a1 = 456;
    if ( v7 != 104 )
    {
      *(_DWORD *)(a1 + 72) = 0;
      v5 = *(_QWORD *)(v7 + 1320);
      goto LABEL_7;
    }
LABEL_9:
    printk(&unk_122E0, a2);
    return 4294967274LL;
  }
  *(_QWORD *)(a1 + 240) = 0;
  *(_DWORD *)a1 = 456;
  if ( v2 == 104 )
    goto LABEL_9;
  *(_DWORD *)(a1 + 72) = 0;
  v5 = *(_QWORD *)(v2 + 1320);
LABEL_7:
  *(_QWORD *)(a1 + 64) = v5;
  get_random_bytes(a1 + 144, 16);
  result = 0;
  *(_QWORD *)(a1 + 56) = 0;
  *(_QWORD *)(a1 + 40) = a1 + 40;
  *(_QWORD *)(a1 + 48) = v4;
  *(_DWORD *)(a1 + 76) = 5;
  return result;
}
