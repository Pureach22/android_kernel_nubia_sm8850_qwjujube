__int64 __fastcall aead_aes_fb_stage1_encrypt_complete(__int64 a1, unsigned int a2)
{
  __int64 v2; // x21
  size_t v3; // x2
  __int64 v6; // x22
  __int64 v7; // x0
  __int64 v8; // x21
  __int64 v9; // x0
  __int64 v10; // x0
  _DWORD *v11; // x8
  __int64 result; // x0
  __int64 v13; // x0
  size_t v14; // x23

  v2 = *(_QWORD *)(a1 + 232);
  v3 = *(unsigned int *)(a1 + 72);
  v6 = *(_QWORD *)(v2 + 32);
  if ( (unsigned int)v3 >= 0x11 && (aead_aes_fb_stage1_encrypt_complete___already_done & 1) == 0 )
  {
    aead_aes_fb_stage1_encrypt_complete___already_done = 1;
    v14 = v3;
    _warn_printk(
      "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
      v3,
      "field \"ctx->iv\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcrypto.c:3277",
      0x10u);
    v3 = v14;
    __break(0x800u);
  }
  memcpy((void *)(v6 + 136), *(const void **)(a1 + 408), v3);
  if ( !a2 )
  {
    v13 = *(_QWORD *)(a1 + 240);
    *(_QWORD *)(v13 + 16) = aead_aes_fb_stage2_ahash_complete;
    *(_QWORD *)(v13 + 24) = a1;
    *(_DWORD *)(v13 + 40) = 1024;
    result = crypto_ahash_digest(v13);
    if ( (_DWORD)result == -115 )
      return result;
    a2 = result;
    if ( (_DWORD)result == -16 )
      return result;
    if ( !(_DWORD)result )
      scatterwalk_map_and_copy(
        a1 + 248,
        *(_QWORD *)(a1 + 440),
        *(unsigned int *)(v2 + 52),
        *(unsigned int *)(v6 + 220),
        1);
  }
  v7 = *(_QWORD *)(a1 + 424);
  v8 = *(_QWORD *)(a1 + 232);
  if ( v7 )
    kfree_sensitive(v7);
  v9 = *(_QWORD *)(a1 + 240);
  if ( v9 )
    kfree_sensitive(v9);
  v10 = *(_QWORD *)(a1 + 408);
  *(_QWORD *)(a1 + 424) = 0;
  *(_QWORD *)(a1 + 240) = 0;
  kfree(v10);
  v11 = *(_DWORD **)(v8 + 16);
  if ( *(v11 - 1) != 1607364836 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v11)(v8, a2);
}
