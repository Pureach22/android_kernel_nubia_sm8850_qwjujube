__int64 __fastcall fils_encrypt_assoc_req(__int64 a1, __int64 a2)
{
  _WORD *v4; // x21
  int v5; // w10
  _WORD *v6; // x19
  __int64 v7; // x8
  __int64 elem_match; // x0
  __int64 v9; // x10
  _QWORD *v10; // x21
  __int64 v11; // x9
  __int64 v12; // x25
  __int64 v13; // x8
  __int64 v14; // x19
  unsigned __int64 v15; // x23
  unsigned __int64 v16; // x0
  unsigned __int64 v17; // x22
  unsigned __int64 v18; // x23
  __int64 v19; // x24
  int v20; // w0
  int v21; // w20
  __int64 v23; // x20
  __int64 v24; // x8
  unsigned __int64 v25; // x0
  unsigned int *v26; // x21
  __int64 v27; // x0
  __int64 v28; // x23
  _QWORD v29[6]; // [xsp+8h] [xbp-B8h] BYREF
  _QWORD v30[6]; // [xsp+38h] [xbp-88h] BYREF
  _QWORD v31[4]; // [xsp+68h] [xbp-58h] BYREF
  _QWORD v32[4]; // [xsp+88h] [xbp-38h] BYREF
  __int64 v33; // [xsp+A8h] [xbp-18h] BYREF
  __int64 v34; // [xsp+B0h] [xbp-10h]
  __int64 v35; // [xsp+B8h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_WORD **)(a1 + 224);
  v5 = *(_DWORD *)(a1 + 112);
  v6 = v4 + 12;
  v7 = 14;
  if ( (*v4 & 0xFC) == 0x20 )
    v7 = 17;
  LOBYTE(v30[0]) = 4;
  elem_match = cfg80211_find_elem_match(255, &v4[v7], (unsigned int)(v5 - v7 * 2), v30, 1, 0);
  if ( elem_match && *(_BYTE *)(elem_match + 1) == 9 )
  {
    v9 = *(unsigned int *)(a1 + 112);
    v30[0] = v4 + 5;
    v30[1] = v4 + 2;
    v29[0] = 6;
    v29[1] = 6;
    v10 = (_QWORD *)(elem_match + 11);
    v30[2] = a2 + 1048;
    v30[3] = a2 + 1064;
    v11 = *(_QWORD *)(a1 + 224);
    v29[2] = 16;
    v29[3] = 16;
    v12 = elem_match;
    v13 = elem_match + 11 - (_QWORD)v6;
    v30[4] = v6;
    v14 = v11 + v9 - (elem_match + 11);
    v29[4] = v13;
    skb_put(a1, 16);
    v15 = *(_QWORD *)(a2 + 1144);
    v33 = 0;
    v34 = 0;
    memset(v32, 0, sizeof(v32));
    memset(v31, 0, sizeof(v31));
    v30[5] = v10;
    v29[5] = v14;
    v16 = crypto_alloc_shash("cmac(aes)", 0, 0);
    v17 = v16;
    if ( v16 < 0xFFFFFFFFFFFFF001LL )
    {
      v18 = v15 >> 1;
      v19 = a2 + 1080;
      v20 = crypto_shash_setkey(v16, a2 + 1080, (unsigned int)v18);
      if ( v20 )
      {
        v21 = v20;
        crypto_destroy_tfm(v17, v17 + 8);
        LODWORD(v17) = v21;
      }
      else
      {
        ((void (__fastcall *)(unsigned __int64, _QWORD *, _QWORD *, __int64 *))aes_s2v)(v17, v30, v29, &v33);
        crypto_destroy_tfm(v17, v17 + 8);
        v23 = kmemdup_noprof(v10, v14, 3264);
        if ( v23 )
        {
          v24 = v34;
          *v10 = v33;
          v10[1] = v24;
          LOBYTE(v34) = v34 & 0x7F;
          BYTE4(v34) &= ~0x80u;
          v25 = crypto_alloc_skcipher("ctr(aes)", 0, 128);
          v26 = (unsigned int *)v25;
          if ( v25 < 0xFFFFFFFFFFFFF001LL )
          {
            LODWORD(v17) = crypto_skcipher_setkey(v25, v19 + v18, (unsigned int)v18);
            if ( !(_DWORD)v17 )
            {
              v27 = _kmalloc_noprof(*v26 + 80LL, 3264);
              if ( v27 )
              {
                v28 = v27;
                *(_QWORD *)(v27 + 64) = v26 + 2;
                sg_init_one(v32, v23, (unsigned int)v14);
                sg_init_one(v31, v12 + 27, (unsigned int)v14);
                *(_QWORD *)(v28 + 16) = v32;
                *(_QWORD *)(v28 + 24) = v31;
                *(_DWORD *)v28 = v14;
                *(_QWORD *)(v28 + 8) = &v33;
                LODWORD(v17) = crypto_skcipher_encrypt(v28);
                kfree_sensitive(v28);
              }
              else
              {
                LODWORD(v17) = -12;
              }
            }
            kfree(v23);
            crypto_destroy_tfm(v26, v26 + 2);
          }
          else
          {
            kfree(v23);
            LODWORD(v17) = (_DWORD)v26;
          }
        }
        else
        {
          LODWORD(v17) = -12;
        }
      }
    }
  }
  else
  {
    LODWORD(v17) = -22;
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v17;
}
