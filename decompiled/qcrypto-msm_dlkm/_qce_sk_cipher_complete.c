__int64 __fastcall qce_sk_cipher_complete(unsigned int *a1, __int64 a2, void *src, int a4)
{
  __int64 v4; // x9
  int v5; // w8
  _QWORD *v6; // x24
  __int64 v7; // x19
  __int64 v10; // x23
  size_t v11; // x22
  __int64 v12; // x8
  int v13; // w11
  __int64 v14; // x0
  int v15; // w21
  int v16; // w26
  __int64 v17; // x21
  _QWORD *v18; // x25
  __int64 v19; // x23
  __int64 v20; // x24
  unsigned int v21; // w22
  __int64 v22; // x0
  void *v24; // x25

  v4 = *((_QWORD *)a1 + 15);
  v5 = *(_DWORD *)(v4 + 236);
  if ( v5 )
  {
    v6 = *((_QWORD **)a1 + 8);
    v7 = *(_QWORD *)(v4 + 240);
    v10 = v6[7];
    while ( *(unsigned int **)(v7 + 16) != a1 + 8 )
    {
      --v5;
      v7 += 40;
      if ( !v5 )
        return printk(&unk_12936, a2);
    }
    if ( v7 )
    {
      if ( src )
      {
        v11 = *(unsigned int *)(v6[3] - 16LL);
        if ( (unsigned int)v11 >= 0x11 && (qce_sk_cipher_complete___already_done & 1) == 0 )
        {
          qce_sk_cipher_complete___already_done = 1;
          v24 = src;
          _warn_printk(
            "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
            v11,
            "field \"ctx->iv\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcrypto.c:1830",
            0x10u);
          src = v24;
          __break(0x800u);
        }
        memcpy(v6 + 17, src, v11);
      }
      v12 = 26;
      if ( a4 )
      {
        v13 = -6;
      }
      else
      {
        v12 = 25;
        v13 = 0;
      }
      ++qcrypto_stat[v12];
      *(_DWORD *)(v7 + 32) = v13;
      if ( *(_BYTE *)(v10 + 25) != 1 )
        return req_done(v7);
      v14 = *((_QWORD *)a1 + 29);
      v15 = *a1;
      *((_QWORD *)a1 + 2) = *((_QWORD *)a1 + 28);
      *((_QWORD *)a1 + 3) = v14;
      if ( v14 && v15 >= 1 )
      {
        v16 = 0;
        do
        {
          ++v16;
          v15 -= *(_DWORD *)(v14 + 12);
          v14 = sg_next(v14);
        }
        while ( v15 >= 1 && v14 );
        v17 = *a1;
        v18 = a1 + 76;
        if ( v16 )
        {
          v19 = *((_QWORD *)a1 + 38);
          v20 = *((_QWORD *)a1 + 3);
          v21 = 0;
          do
          {
            v22 = sg_copy_from_buffer(v20, 1, v19, v17);
            v19 += v22;
            v17 -= v22;
            v21 += v22;
            --v16;
            v20 = sg_next(v20);
          }
          while ( v16 );
          if ( *a1 == v21 )
            goto LABEL_27;
          goto LABEL_31;
        }
        v21 = 0;
        if ( (_DWORD)v17 )
LABEL_31:
          printk(&unk_12B4A, v21);
      }
      else
      {
        v21 = 0;
        v18 = a1 + 76;
        if ( v15 )
          goto LABEL_31;
      }
LABEL_27:
      kfree_sensitive(*v18);
      return req_done(v7);
    }
  }
  return printk(&unk_12936, a2);
}
