__int64 __fastcall qdf_crypto_aes_gmac(
        __int64 a1,
        unsigned __int16 a2,
        __int64 a3,
        int a4,
        __int64 a5,
        unsigned __int16 a6,
        __int64 a7)
{
  unsigned __int64 v14; // x0
  unsigned __int64 v15; // x19
  unsigned int v16; // w26
  unsigned int v17; // w0
  unsigned int v18; // w0
  _QWORD *v19; // x24
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x26
  __int64 v24; // x27
  unsigned __int64 v25; // [xsp+8h] [xbp-88h] BYREF
  __int64 v26; // [xsp+10h] [xbp-80h]
  __int64 v27; // [xsp+18h] [xbp-78h]
  __int64 v28; // [xsp+20h] [xbp-70h]
  unsigned __int64 v29; // [xsp+28h] [xbp-68h]
  __int64 v30; // [xsp+30h] [xbp-60h]
  __int64 v31; // [xsp+38h] [xbp-58h]
  __int64 v32; // [xsp+40h] [xbp-50h]
  unsigned __int64 v33; // [xsp+48h] [xbp-48h]
  __int64 v34; // [xsp+50h] [xbp-40h]
  __int64 v35; // [xsp+58h] [xbp-38h]
  __int64 v36; // [xsp+60h] [xbp-30h]
  unsigned __int64 v37; // [xsp+68h] [xbp-28h]
  __int64 v38; // [xsp+70h] [xbp-20h]
  __int64 v39; // [xsp+78h] [xbp-18h]
  __int64 v40; // [xsp+80h] [xbp-10h]
  __int64 v41; // [xsp+88h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v14 = crypto_alloc_aead("gcm(aes)", 0, 128);
  v15 = v14;
  if ( v14 >= 0xFFFFFFFFFFFFF001LL )
  {
    qdf_trace_msg(56, 2, "%s: crypto_alloc_aead failed (%d)", "qdf_crypto_aes_gmac", v14);
    v16 = v15;
    goto LABEL_12;
  }
  v17 = crypto_aead_setkey(v14, a1, a2);
  if ( v17 )
  {
    v16 = v17;
    qdf_trace_msg(56, 2, "crypto_aead_setkey failed (%d)", v17);
  }
  else
  {
    v18 = crypto_aead_setauthsize(v15, 16);
    if ( !v18 )
    {
      v21 = _qdf_mem_malloc((unsigned __int16)(*(_WORD *)(v15 + 4) + 116), "qdf_crypto_aes_gmac", 705);
      v19 = (_QWORD *)v21;
      if ( v21 )
      {
        v22 = v21 + *(unsigned int *)(v15 + 4);
        v23 = v22 + 96;
        v24 = v22 + 80;
        qdf_mem_copy(v22 + 96, a4, 0x14u);
        sg_init_table(&v25, 4);
        v26 = v23 & 0xFFF | 0x1400000000LL;
        v25 = (v25 & 3 | ((unsigned __int64)((v23 << 8 >> 8) + 0x8000000000LL) >> 12 << 6)) - 0x140000000LL;
        v29 = (v29 & 3 | ((unsigned __int64)((a5 << 8 >> 8) + 0x8000000000LL) >> 12 << 6)) - 0x140000000LL;
        LODWORD(v30) = a5 & 0xFFF;
        HIDWORD(v30) = a6;
        v33 = (v33 & 3 | ((unsigned __int64)((v24 << 8 >> 8) + 0x8000000000LL) >> 12 << 6)) - 0x140000000LL;
        v34 = v24 & 0xFFF | 0x1000000000LL;
        v37 = (v37 & 3 | ((unsigned __int64)((a7 << 8 >> 8) + 0x8000000000LL) >> 12 << 6)) - 0x140000000LL;
        v38 = a7 & 0xFFF | 0x1000000000LL;
        v19[4] = v15 + 8;
        v19[8] = &v25;
        v19[9] = &v25;
        v19[7] = a3;
        v19[6] = (unsigned int)a6 + 36;
        crypto_aead_encrypt(v19);
        v16 = 0;
      }
      else
      {
        v16 = -12;
      }
      goto LABEL_8;
    }
    v16 = v18;
    qdf_trace_msg(56, 2, "crypto_aead_setauthsize failed (%d)", v18);
  }
  v19 = nullptr;
LABEL_8:
  if ( v15 )
    crypto_destroy_tfm(v15, v15 + 8);
  if ( v19 )
    _qdf_mem_free(v19);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v16;
}
