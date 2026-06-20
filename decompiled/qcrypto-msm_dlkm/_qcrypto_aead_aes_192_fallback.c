__int64 __fastcall qcrypto_aead_aes_192_fallback(__int64 a1, char a2)
{
  __int64 v2; // x26
  size_t v3; // x22
  unsigned int *v5; // x21
  __int64 v6; // x0
  __int64 v7; // x20
  __int64 v8; // x23
  __int64 v9; // x0
  __int64 v10; // x21
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x25
  __int64 v14; // x0
  int v15; // w8
  __int64 v16; // x23
  int v17; // w9
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x10
  __int64 v21; // x27
  int v22; // w9
  __int64 v23; // x24
  int v24; // w8
  __int64 v25; // x9
  unsigned int v26; // w22
  size_t v27; // x2
  __int64 v28; // x0
  __int64 v29; // x9
  __int64 v30; // x0
  const void *v31; // x23
  size_t v32; // x2
  __int64 v33; // x0
  size_t v34; // x22
  unsigned __int64 StatusReg; // x21
  __int64 v36; // x23
  unsigned int *v37; // x24
  __int64 v38; // x0

  v2 = *(_QWORD *)(a1 + 32);
  LOBYTE(v3) = a2;
  *(_QWORD *)(a1 + 488) = 0;
  v5 = *(unsigned int **)(v2 + 232);
  v6 = _kmalloc_noprof(*v5 + 80LL, 3264);
  if ( !v6 )
    return (unsigned int)-12;
  v7 = v6;
  *(_QWORD *)(v6 + 64) = v5 + 2;
  while ( 1 )
  {
    v8 = *(_QWORD *)(v2 + 240);
    v9 = _kmalloc_noprof(*(unsigned int *)(v8 + 8) + 80LL, 3264);
    if ( !v9 )
    {
      v26 = -22;
      v10 = v7;
      goto LABEL_30;
    }
    v10 = v9;
    *(_QWORD *)(v9 + 32) = v8 + 16;
    v11 = *(_QWORD *)(a1 + 64);
    v12 = *(unsigned int *)(a1 + 48);
    *(_QWORD *)(a1 + 504) = v7;
    *(_QWORD *)(a1 + 312) = a1;
    *(_QWORD *)(a1 + 320) = v9;
    v13 = scatterwalk_ffwd(a1 + 360, v11, v12);
    v14 = scatterwalk_ffwd(a1 + 424, *(_QWORD *)(a1 + 72), *(unsigned int *)(a1 + 48));
    v15 = *(_DWORD *)(a1 + 52);
    v16 = v14;
    if ( (v3 & 1) == 0 )
      v15 -= *(_DWORD *)(v2 + 220);
    v17 = *(_DWORD *)(a1 + 48);
    *(_QWORD *)(a1 + 512) = v13;
    *(_QWORD *)(a1 + 520) = v14;
    *(_DWORD *)(a1 + 528) = v15;
    *(_DWORD *)(a1 + 496) = v17 + v15;
    *(_DWORD *)(a1 + 152) = *(_DWORD *)(*(_QWORD *)(v2 + 24) - 16LL);
    v18 = kmemdup_noprof(*(_QWORD *)(a1 + 56), *(unsigned int *)(a1 + 152), 2080);
    *(_QWORD *)(a1 + 488) = v18;
    if ( !v18 )
    {
      v26 = -22;
      goto LABEL_29;
    }
    v19 = *(_QWORD *)(a1 + 520);
    v20 = *(_QWORD *)(a1 + 512);
    v21 = a1 + 80;
    v22 = *(_DWORD *)(a1 + 528);
    v23 = a1 + 328;
    *(_QWORD *)(v7 + 8) = v18;
    *(_QWORD *)(v7 + 16) = v20;
    *(_QWORD *)(v7 + 24) = v19;
    v24 = *(_DWORD *)(a1 + 496);
    *(_DWORD *)v7 = v22;
    if ( (v3 & 1) != 0 )
    {
      v25 = *(_QWORD *)(a1 + 72);
      *(_DWORD *)(v10 + 48) = v24;
      *(_QWORD *)(v7 + 48) = aead_aes_fb_stage1_encrypt_complete;
      *(_QWORD *)(v7 + 56) = v21;
      *(_QWORD *)(v10 + 56) = v25;
      *(_QWORD *)(v10 + 64) = v23;
      *(_DWORD *)(v7 + 72) = 1024;
      v26 = crypto_skcipher_encrypt(v7);
      if ( !v26 )
      {
        v27 = *(unsigned int *)(a1 + 152);
        if ( (unsigned int)v27 >= 0x11 && (qcrypto_aead_aes_192_fallback___already_done & 1) == 0 )
        {
          qcrypto_aead_aes_192_fallback___already_done = 1;
          v34 = v27;
          _warn_printk(
            "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
            v27,
            "field \"ctx->iv\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcrypto.c:3358",
            0x10u);
          v27 = v34;
          __break(0x800u);
        }
        memcpy((void *)(v2 + 136), *(const void **)(a1 + 488), v27);
        v28 = *(_QWORD *)(a1 + 320);
        *(_QWORD *)(v28 + 16) = aead_aes_fb_stage2_ahash_complete;
        *(_QWORD *)(v28 + 24) = v21;
        *(_DWORD *)(v28 + 40) = 1024;
        v26 = crypto_ahash_digest(v28);
        if ( !v26 )
        {
          scatterwalk_map_and_copy(a1 + 328, v16, *(unsigned int *)(a1 + 52), *(unsigned int *)(v2 + 220), 1);
          goto LABEL_29;
        }
      }
LABEL_15:
      if ( v26 == -115 )
        return v26;
LABEL_16:
      if ( v26 == -16 )
        return v26;
LABEL_29:
      kfree_sensitive(v7);
LABEL_30:
      kfree_sensitive(v10);
      kfree(*(_QWORD *)(a1 + 488));
      return v26;
    }
    v29 = *(_QWORD *)(a1 + 64);
    *(_DWORD *)(v10 + 48) = v24;
    *(_QWORD *)(v10 + 16) = aead_aes_fb_stage1_ahash_complete;
    *(_QWORD *)(v10 + 24) = v21;
    *(_QWORD *)(v10 + 56) = v29;
    *(_QWORD *)(v10 + 64) = v23;
    *(_DWORD *)(v10 + 40) = 1024;
    v26 = crypto_ahash_digest(v10);
    if ( v26 )
      goto LABEL_15;
    v3 = *(unsigned int *)(v2 + 220);
    v30 = _kmalloc_noprof(v3, 3264);
    v31 = (const void *)v30;
    if ( !v30 )
    {
      v26 = -12;
      goto LABEL_29;
    }
    scatterwalk_map_and_copy(
      v30,
      v13,
      (unsigned int)(*(_DWORD *)(a1 + 52) - *(_DWORD *)(v2 + 220)),
      *(unsigned int *)(v2 + 220),
      0);
    v32 = *(unsigned int *)(v2 + 220);
    if ( v3 >= v32 )
      break;
    _fortify_panic(22);
    StatusReg = _ReadStatusReg(SP_EL0);
    v36 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &qcrypto_aead_aes_192_fallback__alloc_tag;
    v37 = *(unsigned int **)(v2 + 232);
    v38 = _kmalloc_noprof(*v37 + 80LL, 3264);
    if ( !v38 )
    {
      *(_QWORD *)(StatusReg + 80) = v36;
      return (unsigned int)-12;
    }
    v7 = v38;
    *(_QWORD *)(v38 + 64) = v37 + 2;
    *(_QWORD *)(StatusReg + 80) = v36;
  }
  if ( bcmp((const void *)(a1 + 328), v31, v32) )
  {
    v26 = -74;
  }
  else
  {
    v33 = *(_QWORD *)(a1 + 504);
    *(_QWORD *)(v33 + 48) = aead_aes_fb_stage2_decrypt_complete;
    *(_QWORD *)(v33 + 56) = v21;
    *(_DWORD *)(v33 + 72) = 1024;
    v26 = crypto_skcipher_decrypt(v33);
  }
  kfree(v31);
  if ( v26 != -115 )
    goto LABEL_16;
  return v26;
}
