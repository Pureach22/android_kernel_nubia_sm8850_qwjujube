__int64 __fastcall sha_hmac_setkey(unsigned int *a1, const void *a2, unsigned int a3)
{
  unsigned int *v6; // x23
  __int64 v7; // x0
  __int64 v8; // x20
  void *v9; // x0
  void *v10; // x23
  unsigned int v11; // w10
  unsigned int v12; // w0
  unsigned int v13; // w19
  __int64 result; // x0
  unsigned __int64 StatusReg; // x24
  __int64 v16; // x25
  __int64 v17; // x0
  __int64 v18; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v19[3]; // [xsp+10h] [xbp-40h] BYREF
  unsigned __int64 v20; // [xsp+28h] [xbp-28h] BYREF
  __int64 v21; // [xsp+30h] [xbp-20h]
  __int64 v22; // [xsp+38h] [xbp-18h]
  __int64 v23; // [xsp+40h] [xbp-10h]
  __int64 v24; // [xsp+48h] [xbp-8h]

  v6 = a1 + 4;
  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  memset(v19, 0, sizeof(v19));
  v7 = _kmalloc_noprof(a1[2] + 80LL, 3264);
  if ( !v7 )
    goto LABEL_15;
  v8 = v7;
  *(_QWORD *)(v7 + 32) = v6;
  while ( 1 )
  {
    LODWORD(v18) = 0;
    _init_swait_queue_head(v19, "&x->wait", &init_completion___key);
    a1[5] = 0;
    *(_QWORD *)(v8 + 16) = crypto_sha_hmac_ahash_req_complete;
    *(_QWORD *)(v8 + 24) = &v18;
    *(_DWORD *)(v8 + 40) = 1024;
    v9 = (void *)_kmalloc_noprof(a3 + 64, 3520);
    v10 = v9;
    if ( !v9 )
      break;
    if ( a3 + 64 >= (unsigned __int64)a3 )
    {
      memcpy(v9, a2, a3);
      *(_DWORD *)(v8 + 48) = a3;
      LODWORD(v21) = (unsigned __int16)v10 & 0xFF8;
      HIDWORD(v21) = a3;
      v11 = a1[21];
      v20 = ((unsigned __int64)(((__int64)((_QWORD)v10 << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x13FFFFFFELL;
      *(_QWORD *)(v8 + 56) = &v20;
      *(_QWORD *)(v8 + 64) = a1 + 24;
      if ( v11 )
      {
        v12 = sha256_digest(v8);
        if ( v12 == -16 )
        {
LABEL_10:
          v12 = wait_for_completion_interruptible(&v18);
          a1[42] = 0;
          goto LABEL_11;
        }
      }
      else
      {
        v12 = sha1_digest(v8);
        if ( v12 == -16 )
          goto LABEL_10;
      }
      if ( v12 == -115 )
        goto LABEL_10;
LABEL_11:
      v13 = v12;
      kfree_sensitive(v10);
      kfree_sensitive(v8);
      result = v13;
      goto LABEL_16;
    }
    _fortify_panic(17);
    StatusReg = _ReadStatusReg(SP_EL0);
    v16 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &sha_hmac_setkey__alloc_tag;
    v17 = _kmalloc_noprof(a1[2] + 80LL, 3264);
    if ( !v17 )
    {
      *(_QWORD *)(StatusReg + 80) = v16;
      goto LABEL_15;
    }
    v8 = v17;
    *(_QWORD *)(v17 + 32) = v10;
    *(_QWORD *)(StatusReg + 80) = v16;
  }
  kfree_sensitive(v8);
LABEL_15:
  result = 4294967284LL;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
