__int64 __fastcall qdf_aes_ctr(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        __int64 a6,
        char a7)
{
  unsigned int *v14; // x0
  unsigned int *v15; // x19
  __int64 result; // x0
  __int64 v17; // x0
  __int64 v18; // x24
  unsigned int v19; // w0
  unsigned int v20; // w20
  unsigned int v21; // w21
  const char *v22; // x4
  _QWORD v23[4]; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v24[5]; // [xsp+28h] [xbp-28h] BYREF

  v24[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v24, 0, 32);
  memset(v23, 0, sizeof(v23));
  if ( a2 > 0x30 || ((1LL << a2) & 0x1000100010000LL) == 0 )
  {
    qdf_trace_msg(56, 2, "%s: Invalid key length: %u", "qdf_aes_ctr", a2);
    result = 4294967274LL;
    goto LABEL_18;
  }
  v14 = (unsigned int *)crypto_alloc_skcipher("ctr(aes)", 0, 128);
  v15 = v14;
  if ( (unsigned __int64)v14 < 0xFFFFFFFFFFFFF001LL )
  {
    v17 = _kmalloc_noprof(*v14 + 80LL, 3264);
    if ( !v17 )
    {
      qdf_trace_msg(56, 2, "%s: Failed to allocate request for ctr(aes)", "qdf_aes_ctr");
      crypto_destroy_tfm(v15, v15 + 2);
      result = 4294967285LL;
      goto LABEL_18;
    }
    v18 = v17;
    *(_QWORD *)(v17 + 64) = v15 + 2;
    v19 = crypto_skcipher_setkey(v15, a1, a2);
    if ( v19 )
    {
      v20 = v19;
      qdf_trace_msg(56, 2, "%s: Set key failed for ctr(aes), ret:%d", "qdf_aes_ctr", -v19);
      kfree_sensitive(v18);
      crypto_destroy_tfm(v15, v15 + 2);
      result = v20;
      goto LABEL_18;
    }
    sg_init_one(v24, a4, a5);
    sg_init_one(v23, a6, a5);
    *(_QWORD *)(v18 + 16) = v24;
    *(_QWORD *)(v18 + 24) = v23;
    *(_DWORD *)v18 = a5;
    *(_QWORD *)(v18 + 8) = a3;
    if ( (a7 & 1) != 0 )
    {
      v21 = crypto_skcipher_encrypt(v18);
      if ( !v21 )
        goto LABEL_17;
    }
    else
    {
      v21 = crypto_skcipher_decrypt(v18);
      if ( !v21 )
      {
LABEL_17:
        kfree_sensitive(v18);
        crypto_destroy_tfm(v15, v15 + 2);
        result = v21;
        goto LABEL_18;
      }
    }
    if ( (a7 & 1) != 0 )
      v22 = "Encryption";
    else
      v22 = "Decryption";
    qdf_trace_msg(56, 2, "%s: %s failed for ctr(aes), ret:%d", "qdf_aes_ctr", v22, -v21);
    goto LABEL_17;
  }
  qdf_trace_msg(56, 2, "%s: Failed to alloc transformation for ctr(aes):%ld", "qdf_aes_ctr", v14);
  result = 4294967285LL;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
