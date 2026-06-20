__int64 __fastcall aead_encrypt(int *a1, __int64 a2, const void *a3, size_t a4, __int64 a5, int a6, __int64 a7)
{
  int v13; // w8
  int v14; // w20
  __int64 v15; // x28
  unsigned __int64 v16; // x22
  __int64 v17; // x23
  __int64 v18; // x8
  size_t v19; // x1
  unsigned int v20; // w19
  unsigned __int64 StatusReg; // [xsp+0h] [xbp-80h]
  __int64 v23; // [xsp+8h] [xbp-78h]
  unsigned __int64 v25; // [xsp+18h] [xbp-68h] BYREF
  __int64 v26; // [xsp+20h] [xbp-60h]
  __int64 v27; // [xsp+28h] [xbp-58h]
  __int64 v28; // [xsp+30h] [xbp-50h]
  unsigned __int64 v29; // [xsp+38h] [xbp-48h]
  __int64 v30; // [xsp+40h] [xbp-40h]
  __int64 v31; // [xsp+48h] [xbp-38h]
  __int64 v32; // [xsp+50h] [xbp-30h]
  unsigned __int64 v33; // [xsp+58h] [xbp-28h]
  __int64 v34; // [xsp+60h] [xbp-20h]
  __int64 v35; // [xsp+68h] [xbp-18h]
  __int64 v36; // [xsp+70h] [xbp-10h]
  __int64 v37; // [xsp+78h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *a1;
  v13 = a1[1];
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  LODWORD(v15) = v13 + 80;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v16 = a4 + v13 + 80;
  v17 = _kmalloc_noprof(v16, 2336);
  if ( !v17 )
  {
LABEL_19:
    v20 = -12;
    goto LABEL_20;
  }
  while ( 1 )
  {
    v18 = (int)v15;
    if ( v16 >= (int)v15 )
      v19 = v16 - (int)v15;
    else
      v19 = 0;
    if ( v19 < a4 )
      goto LABEL_18;
    v15 = v17 + (int)v15;
    memcpy((void *)(v17 + v18), a3, a4);
    sg_init_table(&v25, 3);
    LODWORD(v26) = v15 & 0xFFF;
    HIDWORD(v26) = a4;
    LODWORD(v30) = a5 & 0xFFF;
    HIDWORD(v30) = a6;
    v25 = (v25 & 3 | ((unsigned __int64)((v15 << 8 >> 8) + 0x8000000000LL) >> 12 << 6)) - 0x140000000LL;
    v29 = (v29 & 3 | ((unsigned __int64)((a5 << 8 >> 8) + 0x8000000000LL) >> 12 << 6)) - 0x140000000LL;
    v33 = (v33 & 3 | ((unsigned __int64)((a7 << 8 >> 8) + 0x8000000000LL) >> 12 << 6)) - 0x140000000LL;
    LODWORD(v34) = a7 & 0xFFF;
    HIDWORD(v34) = v14;
    if ( v16 >= 0x20 && (v16 & 0xFFFFFFFFFFFFFFF8LL) != 0x20 )
    {
      *(_QWORD *)(v17 + 32) = a1 + 2;
      if ( v16 >= 0x40 && (v16 & 0xFFFFFFFFFFFFFFF8LL) != 0x40 )
      {
        *(_QWORD *)(v17 + 64) = &v25;
        if ( v16 >= 0x48 && (v16 & 0xFFFFFFFFFFFFFFF8LL) != 0x48 )
        {
          *(_QWORD *)(v17 + 72) = &v25;
          if ( (v16 & 0xFFFFFFFFFFFFFFFCLL) != 0x34 )
          {
            *(_DWORD *)(v17 + 52) = a6;
            if ( (v16 & 0xFFFFFFFFFFFFFFF8LL) != 0x38 )
            {
              *(_QWORD *)(v17 + 56) = a2;
              if ( (v16 & 0xFFFFFFFFFFFFFFFCLL) != 0x30 )
                break;
            }
          }
        }
      }
    }
    __break(1u);
LABEL_18:
    _fortify_panic(17);
    v16 = a4 + (int)v15;
    StatusReg = _ReadStatusReg(SP_EL0);
    v23 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v17 = _kmalloc_noprof(v16, 2336);
    *(_QWORD *)(StatusReg + 80) = v23;
    if ( !v17 )
      goto LABEL_19;
  }
  *(_DWORD *)(v17 + 48) = a4;
  v20 = crypto_aead_encrypt(v17);
  kfree_sensitive(v17);
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v20;
}
