__int64 __fastcall aead_decrypt(int *a1, __int64 a2, const void *a3, size_t a4, __int64 a5, __int64 a6, __int64 a7)
{
  int v7; // w20
  int v9; // w21
  __int64 v14; // x28
  unsigned __int64 v15; // x22
  __int64 v16; // x23
  __int64 v17; // x8
  size_t v18; // x1
  unsigned int v19; // w19
  __int64 result; // x0
  unsigned __int64 StatusReg; // [xsp+0h] [xbp-80h]
  __int64 v22; // [xsp+8h] [xbp-78h]
  unsigned __int64 v24; // [xsp+18h] [xbp-68h] BYREF
  __int64 v25; // [xsp+20h] [xbp-60h]
  __int64 v26; // [xsp+28h] [xbp-58h]
  __int64 v27; // [xsp+30h] [xbp-50h]
  unsigned __int64 v28; // [xsp+38h] [xbp-48h]
  __int64 v29; // [xsp+40h] [xbp-40h]
  __int64 v30; // [xsp+48h] [xbp-38h]
  __int64 v31; // [xsp+50h] [xbp-30h]
  unsigned __int64 v32; // [xsp+58h] [xbp-28h]
  __int64 v33; // [xsp+60h] [xbp-20h]
  __int64 v34; // [xsp+68h] [xbp-18h]
  __int64 v35; // [xsp+70h] [xbp-10h]
  __int64 v36; // [xsp+78h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a6 )
  {
    result = 4294967274LL;
    goto LABEL_22;
  }
  v7 = *a1;
  v9 = a6;
  LODWORD(v14) = a1[1] + 80;
  v24 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v25 = 0;
  v15 = a4 + (int)v14;
  v16 = _kmalloc_noprof(v15, 2336);
  if ( !v16 )
  {
LABEL_21:
    result = 4294967284LL;
    goto LABEL_22;
  }
  while ( 1 )
  {
    v17 = (int)v14;
    if ( v15 >= (int)v14 )
      v18 = v15 - (int)v14;
    else
      v18 = 0;
    if ( v18 < a4 )
      goto LABEL_20;
    v14 = v16 + (int)v14;
    memcpy((void *)(v16 + v17), a3, a4);
    sg_init_table(&v24, 3);
    LODWORD(v25) = v14 & 0xFFF;
    HIDWORD(v25) = a4;
    LODWORD(v29) = a5 & 0xFFF;
    HIDWORD(v29) = v9;
    v24 = (v24 & 3 | ((unsigned __int64)((v14 << 8 >> 8) + 0x8000000000LL) >> 12 << 6)) - 0x140000000LL;
    v28 = (v28 & 3 | ((unsigned __int64)((a5 << 8 >> 8) + 0x8000000000LL) >> 12 << 6)) - 0x140000000LL;
    v32 = (v32 & 3 | ((unsigned __int64)((a7 << 8 >> 8) + 0x8000000000LL) >> 12 << 6)) - 0x140000000LL;
    LODWORD(v33) = a7 & 0xFFF;
    HIDWORD(v33) = v7;
    if ( v15 >= 0x20 && (v15 & 0xFFFFFFFFFFFFFFF8LL) != 0x20 )
    {
      *(_QWORD *)(v16 + 32) = a1 + 2;
      if ( v15 >= 0x40 && (v15 & 0xFFFFFFFFFFFFFFF8LL) != 0x40 )
      {
        *(_QWORD *)(v16 + 64) = &v24;
        if ( v15 >= 0x48 && (v15 & 0xFFFFFFFFFFFFFFF8LL) != 0x48 )
        {
          *(_QWORD *)(v16 + 72) = &v24;
          if ( (v15 & 0xFFFFFFFFFFFFFFFCLL) != 0x34 )
          {
            *(_DWORD *)(v16 + 52) = v7 + v9;
            if ( (v15 & 0xFFFFFFFFFFFFFFF8LL) != 0x38 )
            {
              *(_QWORD *)(v16 + 56) = a2;
              if ( (v15 & 0xFFFFFFFFFFFFFFFCLL) != 0x30 )
                break;
            }
          }
        }
      }
    }
    __break(1u);
LABEL_20:
    _fortify_panic(17);
    v15 = a4 + (int)v14;
    StatusReg = _ReadStatusReg(SP_EL0);
    v22 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &aead_decrypt__alloc_tag;
    v16 = _kmalloc_noprof(v15, 2336);
    *(_QWORD *)(StatusReg + 80) = v22;
    if ( !v16 )
      goto LABEL_21;
  }
  *(_DWORD *)(v16 + 48) = a4;
  v19 = crypto_aead_decrypt(v16);
  kfree_sensitive(v16);
  result = v19;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
