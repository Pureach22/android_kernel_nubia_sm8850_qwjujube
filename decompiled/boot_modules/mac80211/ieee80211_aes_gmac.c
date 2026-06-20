__int64 __fastcall ieee80211_aes_gmac(__int64 a1, _QWORD *a2, char *a3, __int64 a4, unsigned __int64 a5, __int64 a6)
{
  __int64 result; // x0
  unsigned int v7; // w23
  int v9; // w19
  unsigned __int64 v14; // x21
  __int64 v15; // x20
  __int64 v16; // x8
  unsigned __int64 v17; // x1
  __int64 v18; // x28
  __int64 v19; // x11
  char v20; // w12
  __int64 v21; // x9
  unsigned int v22; // w9
  unsigned __int64 v23; // x8
  unsigned __int64 *v24; // x10
  __int64 v25; // x9
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x12
  __int64 v28; // x14
  unsigned int v29; // w19
  unsigned __int64 StatusReg; // x27
  __int64 v31; // x28
  __int64 v32; // x0
  unsigned __int64 v33; // [xsp+18h] [xbp-E8h]
  _QWORD *v34; // [xsp+20h] [xbp-E0h]
  char *v35; // [xsp+28h] [xbp-D8h]
  unsigned __int64 *v36; // [xsp+30h] [xbp-D0h]
  char *v37; // [xsp+38h] [xbp-C8h]
  char *v38; // [xsp+38h] [xbp-C8h]
  __int64 v39; // [xsp+40h] [xbp-C0h] BYREF
  __int64 v40; // [xsp+48h] [xbp-B8h]
  unsigned __int64 v41; // [xsp+50h] [xbp-B0h] BYREF
  __int64 v42; // [xsp+58h] [xbp-A8h]
  __int64 v43; // [xsp+60h] [xbp-A0h]
  __int64 v44; // [xsp+68h] [xbp-98h]
  unsigned __int64 v45; // [xsp+70h] [xbp-90h]
  __int64 v46; // [xsp+78h] [xbp-88h]
  __int64 v47; // [xsp+80h] [xbp-80h]
  __int64 v48; // [xsp+88h] [xbp-78h]
  unsigned __int64 v49; // [xsp+90h] [xbp-70h] BYREF
  _QWORD v50[3]; // [xsp+98h] [xbp-68h] BYREF
  __int64 v51; // [xsp+B0h] [xbp-50h] BYREF
  _QWORD v52[3]; // [xsp+B8h] [xbp-48h] BYREF
  __int64 v53; // [xsp+D0h] [xbp-30h] BYREF
  _QWORD v54[5]; // [xsp+D8h] [xbp-28h] BYREF

  v54[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a5 >= 0x10 )
  {
    v7 = *(_DWORD *)(a1 + 4);
    v9 = a5;
    v53 = 0;
    memset(v54, 0, 24);
    v51 = 0;
    memset(v52, 0, sizeof(v52));
    v49 = 0;
    memset(v50, 0, sizeof(v50));
    v47 = 0;
    v48 = 0;
    v45 = 0;
    v46 = 0;
    v43 = 0;
    v44 = 0;
    v41 = 0;
    v42 = 0;
    v39 = 0;
    v40 = 0;
    v14 = (int)(v7 + 116);
    v15 = _kmalloc_noprof(v14, 2336);
    if ( !v15 )
    {
LABEL_24:
      result = 4294967284LL;
      goto LABEL_25;
    }
    while ( 1 )
    {
      v37 = a3;
      v16 = (int)(v7 + 80);
      if ( v14 >= v16 + 16 )
        v17 = v14 - (v16 + 16);
      else
        v17 = 0;
      if ( v17 > 0x13 )
      {
        v18 = v15 + v16;
        v19 = a2[1];
        v20 = *(_WORD *)a2;
        *(_QWORD *)(v15 + v16 + 16) = *a2;
        v21 = v15 + v16 + 16;
        *(_QWORD *)(v21 + 8) = v19;
        LODWORD(v19) = *((_DWORD *)a2 + 4);
        a3 = (char *)v52 + 4;
        a2 = v52;
        v7 = v21 & 0xFFF;
        *(_DWORD *)(v21 + 16) = v19;
        v33 = ((unsigned __int64)((v21 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL;
        if ( (v20 & 0xFC) == 0x80 )
        {
          v34 = v54;
          v35 = (char *)v54 + 4;
          v36 = (unsigned __int64 *)&v53;
          sg_init_table(&v41, 5);
          v42 = v7 | 0x1400000000LL;
          v22 = v18 & 0xFFF;
          v46 = v22 | 0x800000000LL;
          v41 = v41 & 3 | v33;
          v23 = ((unsigned __int64)((v18 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL;
          v49 = v49 & 3 | (((unsigned __int64)(((a4 + 8) << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL);
          LODWORD(v50[0]) = (a4 + 8) & 0xFFF;
          HIDWORD(v50[0]) = v9 - 24;
          v45 = v45 & 3 | v23;
          v24 = (unsigned __int64 *)&v51;
        }
        else
        {
          v35 = (char *)v52 + 4;
          v36 = (unsigned __int64 *)&v51;
          v34 = v52;
          sg_init_table(&v41, 4);
          v42 = v7 | 0x1400000000LL;
          LODWORD(v46) = a4 & 0xFFF;
          HIDWORD(v46) = v9 - 16;
          a3 = (char *)v50 + 4;
          v41 = v41 & 3 | v33;
          v24 = &v49;
          v23 = ((unsigned __int64)((v18 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL;
          a2 = v50;
          v45 = v45 & 3 | (((unsigned __int64)((a4 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL);
          v22 = v18 & 0xFFF;
        }
        *(_DWORD *)a2 = v22;
        v25 = *v24 & 3;
        *(_DWORD *)v34 = a6 & 0xFFF;
        v26 = v25 | v23;
        v27 = *v36;
        v28 = *(_QWORD *)v37;
        LODWORD(v25) = *((_DWORD *)v37 + 2);
        *v24 = v26;
        *(_DWORD *)a3 = 16;
        *(_DWORD *)v35 = 16;
        *v36 = v27 & 3 | (((unsigned __int64)((a6 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL);
        v39 = v28;
        v40 = (unsigned int)v25 | 0x100000000000000LL;
        if ( v14 >= 0x20 && (v14 & 0xFFFFFFFFFFFFFFF8LL) != 0x20 )
        {
          *(_QWORD *)(v15 + 32) = a1 + 8;
          if ( v14 >= 0x40 && (v14 & 0xFFFFFFFFFFFFFFF8LL) != 0x40 )
          {
            *(_QWORD *)(v15 + 64) = &v41;
            if ( v14 >= 0x48 && (v14 & 0xFFFFFFFFFFFFFFF8LL) != 0x48 )
            {
              *(_QWORD *)(v15 + 72) = &v41;
              if ( (v14 & 0xFFFFFFFFFFFFFFFCLL) != 0x34 )
              {
                *(_DWORD *)(v15 + 52) = 0;
                if ( (v14 & 0xFFFFFFFFFFFFFFF8LL) != 0x38 )
                {
                  *(_QWORD *)(v15 + 56) = &v39;
                  if ( (v14 & 0xFFFFFFFFFFFFFFFCLL) != 0x30 )
                  {
                    *(_DWORD *)(v15 + 48) = v9 + 20;
                    v29 = crypto_aead_encrypt(v15);
                    kfree_sensitive(v15);
                    result = v29;
                    goto LABEL_25;
                  }
                }
              }
            }
          }
        }
        __break(1u);
      }
      _fortify_panic(17);
      v38 = a3;
      StatusReg = _ReadStatusReg(SP_EL0);
      v14 = (int)(v7 + 116);
      v31 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &ieee80211_aes_gmac__alloc_tag;
      v32 = _kmalloc_noprof(v14, 2336);
      *(_QWORD *)(StatusReg + 80) = v31;
      a3 = v38;
      v15 = v32;
      if ( !v32 )
        goto LABEL_24;
    }
  }
  result = 4294967274LL;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
