_DWORD *__fastcall qce_ahash_complete(__int64 a1, void *src, _DWORD *a3, int a4)
{
  __int64 v4; // x9
  int v5; // w8
  __int64 v6; // x10
  __int64 v7; // x20
  __int64 v12; // x11
  __int64 v13; // x25
  size_t v14; // x24
  __int64 v15; // x8
  int v16; // w9
  __int64 v17; // x8
  int v18; // w11
  __int64 v19; // x0
  __int64 v21; // x1

  v4 = *(_QWORD *)(a1 + 120);
  v5 = *(_DWORD *)(v4 + 236);
  if ( !v5 )
    return (_DWORD *)printk(&unk_12936, src);
  v6 = *(_QWORD *)(a1 + 32);
  v7 = *(_QWORD *)(v4 + 240);
  v12 = *(_QWORD *)(v6 + 24);
  v13 = *(_QWORD *)(v6 + 56);
  v14 = *(unsigned int *)(v12 - 8);
  while ( *(_QWORD *)(v7 + 16) != a1 )
  {
    --v5;
    v7 += 40;
    if ( !v5 )
      return (_DWORD *)printk(&unk_12936, src);
  }
  if ( !v7 )
    return (_DWORD *)printk(&unk_12936, src);
  if ( src )
  {
    if ( (unsigned int)v14 >= 0x21 && (qce_ahash_complete___already_done & 1) == 0 )
    {
      v21 = *(unsigned int *)(v12 - 8);
      qce_ahash_complete___already_done = 1;
      _warn_printk(
        "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
        v21,
        "field \"rctx->digest\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcrypto.c:1771",
        0x20u);
      __break(0x800u);
    }
    memcpy((void *)(a1 + 456), src, v14);
    if ( *(_BYTE *)(a1 + 225) )
      memcpy(*(void **)(a1 + 64), src, v14);
  }
  if ( a3 )
  {
    *(_DWORD *)(a1 + 200) = *a3;
    *(_DWORD *)(a1 + 204) = a3[1];
    *(_DWORD *)(a1 + 208) = a3[2];
    *(_DWORD *)(a1 + 212) = a3[3];
  }
  v15 = *(_QWORD *)(a1 + 128);
  v16 = *(_DWORD *)(a1 + 136);
  *(_WORD *)(a1 + 224) = 0;
  *(_QWORD *)(a1 + 56) = v15;
  if ( a4 )
    v17 = 32;
  else
    v17 = 31;
  *(_DWORD *)(a1 + 48) = v16;
  if ( a4 )
    v18 = -6;
  else
    v18 = 0;
  ++qcrypto_stat[v17];
  *(_DWORD *)(v7 + 32) = v18;
  if ( *(_BYTE *)(v13 + 25) == 1 )
  {
    v19 = *(_QWORD *)(a1 + 184);
    *(_QWORD *)(a1 + 56) = *(_QWORD *)(a1 + 144);
    kfree(v19);
  }
  return req_done((_DWORD *)v7);
}
