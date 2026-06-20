__int64 __fastcall fils_decrypt_assoc_resp(__int64 a1, __int64 a2, __int64 *a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 elem_match; // x0
  __int64 v9; // x10
  __int64 *v10; // x21
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x23
  __int64 result; // x0
  __int64 v14; // x26
  unsigned __int64 v15; // x24
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x9
  __int64 v19; // x10
  unsigned __int64 v20; // x0
  unsigned int *v21; // x20
  unsigned __int64 v22; // x24
  __int64 v23; // x22
  unsigned int v24; // w0
  unsigned int v25; // w19
  __int64 v26; // x0
  __int64 v27; // x25
  unsigned int v28; // w21
  unsigned __int64 v29; // x0
  _QWORD v31[6]; // [xsp+0h] [xbp-E0h] BYREF
  _QWORD v32[5]; // [xsp+30h] [xbp-B0h] BYREF
  __int64 v33; // [xsp+58h] [xbp-88h]
  __int64 v34; // [xsp+60h] [xbp-80h] BYREF
  __int64 v35; // [xsp+68h] [xbp-78h]
  __int64 v36; // [xsp+70h] [xbp-70h] BYREF
  __int64 v37; // [xsp+78h] [xbp-68h]
  __int64 v38; // [xsp+80h] [xbp-60h]
  __int64 v39; // [xsp+88h] [xbp-58h]
  _QWORD v40[4]; // [xsp+90h] [xbp-50h] BYREF
  _QWORD v41[6]; // [xsp+B0h] [xbp-30h] BYREF

  v41[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a3;
  if ( (unsigned __int64)*a3 >= 0x1E )
  {
    LOBYTE(v32[0]) = 4;
    elem_match = cfg80211_find_elem_match(255, a2 + 30, (unsigned int)(v4 - 30), v32, 1, 0);
    if ( elem_match )
    {
      if ( *(_BYTE *)(elem_match + 1) == 9 )
      {
        v9 = *a3;
        v32[0] = a2 + 10;
        v32[1] = a2 + 4;
        v31[0] = 6;
        v31[1] = 6;
        v10 = (__int64 *)(elem_match + 11);
        v32[2] = a4 + 1064;
        v32[3] = a4 + 1048;
        v31[2] = 16;
        v31[3] = 16;
        v11 = a2 + v9 - (elem_match + 11);
        v12 = v11 - 16;
        v32[4] = a2 + 24;
        v31[4] = elem_match + 11 - (a2 + 24);
        if ( v11 >= 0x10 )
        {
          v33 = 0;
          v34 = 0;
          v14 = elem_match;
          v15 = *(_QWORD *)(a4 + 1144);
          memset(v41, 0, 32);
          memset(v40, 0, sizeof(v40));
          v35 = 0;
          v33 = elem_match + 11;
          v17 = *v10;
          v16 = *(_QWORD *)(elem_match + 19);
          v31[5] = v12;
          v36 = v17;
          v37 = v16;
          v18 = *v10;
          v19 = *(_QWORD *)(elem_match + 19);
          LOBYTE(v37) = v16 & 0x7F;
          BYTE4(v37) = BYTE4(v16) & 0x7F;
          v38 = v18;
          v39 = v19;
          v20 = crypto_alloc_skcipher("ctr(aes)", 0, 128);
          v21 = (unsigned int *)v20;
          if ( v20 > 0xFFFFFFFFFFFFF000LL )
            goto LABEL_8;
          v22 = v15 >> 1;
          v23 = a4 + 1080;
          v24 = crypto_skcipher_setkey(v20, v23 + v22, (unsigned int)v22);
          if ( !v24 )
          {
            v26 = _kmalloc_noprof(*v21 + 80LL, 3264);
            if ( !v26 )
            {
              v25 = -12;
              goto LABEL_12;
            }
            v27 = v26;
            *(_QWORD *)(v26 + 64) = v21 + 2;
            sg_init_one(v41, v14 + 27, (unsigned int)v12);
            sg_init_one(v40, v10, (unsigned int)v12);
            *(_QWORD *)(v27 + 16) = v41;
            *(_QWORD *)(v27 + 24) = v40;
            *(_DWORD *)v27 = v12;
            *(_QWORD *)(v27 + 8) = &v36;
            v28 = crypto_skcipher_decrypt(v27);
            kfree_sensitive(v27);
            crypto_destroy_tfm(v21, v21 + 2);
            result = v28;
            if ( v28 )
              goto LABEL_6;
            v29 = crypto_alloc_shash("cmac(aes)", 0, 0);
            v21 = (unsigned int *)v29;
            if ( v29 > 0xFFFFFFFFFFFFF000LL )
            {
LABEL_8:
              result = (unsigned int)v21;
              if ( (_DWORD)v21 )
                goto LABEL_6;
              goto LABEL_9;
            }
            v24 = crypto_shash_setkey(v29, v23, (unsigned int)v22);
            if ( !v24 )
            {
              ((void (__fastcall *)(unsigned int *, _QWORD *, _QWORD *, __int64 *))aes_s2v)(v21, v32, v31, &v34);
              crypto_destroy_tfm(v21, v21 + 2);
              if ( v34 != v38 || v35 != v39 )
                goto LABEL_5;
LABEL_9:
              result = 0;
              *a3 -= 16;
              goto LABEL_6;
            }
          }
          v25 = v24;
LABEL_12:
          crypto_destroy_tfm(v21, v21 + 2);
          result = v25;
          goto LABEL_6;
        }
      }
    }
  }
LABEL_5:
  result = 4294967274LL;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
