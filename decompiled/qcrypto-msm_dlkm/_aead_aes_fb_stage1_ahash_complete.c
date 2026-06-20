__int64 __fastcall aead_aes_fb_stage1_ahash_complete(_QWORD *a1, unsigned int a2)
{
  unsigned int v2; // w20
  __int64 v4; // x0
  __int64 v5; // x21
  __int64 v6; // x0
  __int64 v7; // x0
  _DWORD *v8; // x8
  __int64 result; // x0
  __int64 v10; // x23
  __int64 v11; // x22
  size_t v12; // x20
  const void *v13; // x21
  size_t v14; // x2
  int v15; // w20
  __int64 v16; // x0
  unsigned __int64 StatusReg; // x24
  __int64 v18; // x25

  v2 = a2;
  if ( !a2 )
  {
    v10 = a1[29];
    v11 = *(_QWORD *)(v10 + 32);
    v12 = *(unsigned int *)(v11 + 220);
    v13 = (const void *)_kmalloc_noprof(v12, 3264);
    if ( v13 )
    {
      while ( 1 )
      {
        scatterwalk_map_and_copy(
          v13,
          a1[54],
          (unsigned int)(*(_DWORD *)(v10 + 52) - *(_DWORD *)(v11 + 220)),
          *(unsigned int *)(v11 + 220),
          0);
        v14 = *(unsigned int *)(v11 + 220);
        if ( v12 >= v14 )
          break;
        _fortify_panic(22);
        StatusReg = _ReadStatusReg(SP_EL0);
        v18 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &aead_aes_fb_stage1_ahash_complete__alloc_tag;
        v12 = *(unsigned int *)(v11 + 220);
        v13 = (const void *)_kmalloc_noprof(v12, 3264);
        *(_QWORD *)(StatusReg + 80) = v18;
        if ( !v13 )
          goto LABEL_18;
      }
      v15 = bcmp(a1 + 31, v13, v14);
      kfree(v13);
      if ( v15 )
      {
        v2 = -74;
      }
      else
      {
        v16 = a1[53];
        *(_QWORD *)(v16 + 48) = aead_aes_fb_stage2_decrypt_complete;
        *(_QWORD *)(v16 + 56) = a1;
        *(_DWORD *)(v16 + 72) = 1024;
        result = crypto_skcipher_decrypt(v16);
        if ( (_DWORD)result == -115 || (_DWORD)result == -16 )
          return result;
        v2 = result;
      }
    }
    else
    {
LABEL_18:
      v2 = -12;
    }
  }
  v4 = a1[53];
  v5 = a1[29];
  if ( v4 )
    kfree_sensitive(v4);
  v6 = a1[30];
  if ( v6 )
    kfree_sensitive(v6);
  v7 = a1[51];
  a1[53] = 0;
  a1[30] = 0;
  kfree(v7);
  v8 = *(_DWORD **)(v5 + 16);
  if ( *(v8 - 1) != 1607364836 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v8)(v5, v2);
}
