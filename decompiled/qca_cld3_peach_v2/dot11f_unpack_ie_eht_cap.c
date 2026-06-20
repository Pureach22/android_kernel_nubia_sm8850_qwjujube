__int64 __fastcall dot11f_unpack_ie_eht_cap(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 v8; // x12
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x9
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  unsigned __int8 v13; // w9
  __int64 v14; // x11
  char v15; // w10
  size_t v16; // x2
  __int64 v17; // [xsp+0h] [xbp-20h] BYREF
  __int64 v18; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v19; // [xsp+10h] [xbp-10h] BYREF
  unsigned __int16 v20; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)a4 )
  {
    *(_BYTE *)a4 = 1;
    if ( a3 <= 1u )
      goto LABEL_17;
    v20 = 0;
    v19 = 0;
    v17 = 0;
    v18 = 0;
    qdf_mem_copy(&v20, a2, 2u);
    *(_QWORD *)(a4 + 1) = *(_QWORD *)(a4 + 1) & 0xFFFFFFFFFFFF0000LL | v20 & 1 | v20 & 0xE | v20 & 0x1F0 | v20 & 0xFE00;
    if ( (unsigned __int8)(a3 - 2) <= 3u )
      goto LABEL_17;
    qdf_mem_copy(&v19, a2 + 2, 4u);
    v8 = (unsigned __int64)v19 << 17;
    *(_QWORD *)(a4 + 1) = (*(_QWORD *)(a4 + 1) & 0xFFFE00000080FFFFLL
                         | (v19 << 16) & 0x10000LL
                         | (v19 << 16) & 0x60000LL
                         | (v19 << 16) & 0x380000LL
                         | (v19 << 16) & 0x400000LL
                         | (v19 << 17) & 0x7000000
                         | (v19 << 17) & 0x38000000
                         | v8 & 0x800000000000LL
                         | ((unsigned __int64)((unsigned __int16)v19 >> 13) << 30)
                         | ((unsigned __int64)(HIWORD(v19) & 7) << 33)
                         | ((unsigned __int64)((v19 >> 19) & 7) << 36)
                         | ((unsigned __int64)((v19 >> 22) & 7) << 39)
                         | ((unsigned __int64)((v19 >> 25) & 1) << 42)
                         | ((unsigned __int64)((v19 >> 26) & 1) << 43)
                         | ((unsigned __int64)((v19 >> 27) & 1) << 44)
                         | ((unsigned __int64)((v19 >> 28) & 1) << 45)
                         | ((unsigned __int64)((v19 >> 29) & 1) << 46))
                        + (v8 & 0x1000000000000LL);
    if ( (unsigned __int8)(a3 - 6) <= 3u )
      goto LABEL_17;
    qdf_mem_copy((char *)&v18 + 4, a2 + 6, 4u);
    v9 = *(_QWORD *)(a4 + 9) & 0xFFFFFFFFFFF00000LL | ((unsigned __int64)HIDWORD(v18) >> 12);
    *(_QWORD *)(a4 + 1) = ((unsigned __int64)(BYTE4(v18) >> 4) << 56)
                        | ((unsigned __int64)((HIDWORD(v18) >> 8) & 1) << 60)
                        | ((unsigned __int64)((HIDWORD(v18) >> 9) & 1) << 61)
                        | ((unsigned __int64)((HIDWORD(v18) >> 10) & 1) << 62)
                        | *(_QWORD *)(a4 + 1) & 0xE1FFFFFFFFFFFFLL
                        | ((unsigned __int64)(BYTE4(v18) & 1) << 49)
                        | ((unsigned __int64)((HIDWORD(v18) >> 1) & 1) << 50)
                        | ((unsigned __int64)((HIDWORD(v18) >> 2) & 1) << 51)
                        | ((unsigned __int64)((HIDWORD(v18) >> 3) & 1) << 52)
                        | ((unsigned __int64)HIDWORD(v18) >> 11 << 63);
    *(_QWORD *)(a4 + 9) = v9;
    if ( a3 == 10 )
      goto LABEL_17;
    v10 = a2[10];
    *(_QWORD *)(a4 + 9) = v9 & 0xFFFFFFFFF00FFFFFLL
                        | ((v10 & 1) << 20) & 0xFFFFFFFFF17FFFFFLL
                        | ((unsigned __int64)(((unsigned int)v10 >> 1) & 1) << 21) & 0xFFFFFFFFF17FFFFFLL
                        | ((unsigned __int64)(((unsigned int)v10 >> 2) & 1) << 22) & 0xFFFFFFFFF17FFFFFLL
                        | (((v10 >> 3) & 1) << 23) & 0xFFFFFFFFF1FFFFFFLL
                        | ((unsigned __int64)((unsigned int)v10 >> 4) << 24) & 0xFFFFFFFFF1FFFFFFLL
                        | ((((unsigned int)v10 >> 5) & 7LL) << 25);
    if ( (unsigned __int8)(a3 - 11) <= 3u )
      goto LABEL_17;
    qdf_mem_copy(&v18, a2 + 11, 4u);
    *(_QWORD *)(a4 + 9) = ((unsigned __int64)(unsigned int)v18 << 28) & 0xF0000000000000LL
                        | ((unsigned __int64)(((unsigned int)v18 >> 20) & 0xF) << 48) & 0xF0FFFFFFFFFFFFFFLL
                        | *(_QWORD *)(a4 + 9) & 0xF00000000FFFFFFFLL
                        | (unsigned int)((_DWORD)v18 << 28)
                        | ((unsigned __int64)((unsigned __int8)v18 >> 4) << 32) & 0xF0FFFFFFFFFFFFFFLL
                        | ((unsigned __int64)(((unsigned int)v18 >> 8) & 0xF) << 36) & 0xF0FFFFFFFFFFFFFFLL
                        | ((unsigned __int64)((unsigned __int16)v18 >> 12) << 40) & 0xF0FFFFFFFFFFFFFFLL
                        | ((unsigned __int64)(WORD1(v18) & 0xF) << 44) & 0xF0FFFFFFFFFFFFFFLL
                        | ((unsigned __int64)((unsigned int)v18 >> 28) << 56);
    if ( (unsigned __int8)(a3 - 15) <= 3u
      || (qdf_mem_copy((char *)&v17 + 4, a2 + 15, 4u),
          v11 = *(_QWORD *)(a4 + 17) & 0xFFFFFFFFF0000000LL | ((unsigned __int64)HIDWORD(v17) >> 4),
          *(_QWORD *)(a4 + 9) = *(_QWORD *)(a4 + 9) & 0xFFFFFFFFFFFFFFFLL | ((unsigned __int64)BYTE4(v17) << 60),
          *(_QWORD *)(a4 + 17) = v11,
          (unsigned __int8)(a3 - 19) <= 3u)
      || (qdf_mem_copy(&v17, a2 + 19, 4u),
          v12 = ((unsigned __int64)(unsigned int)v17 << 28) & 0xF0000000000000LL
              | ((unsigned __int64)(((unsigned int)v17 >> 20) & 0xF) << 48) & 0xF0FFFFFFFFFFFFFFLL
              | *(_QWORD *)(a4 + 17) & 0xF00000000FFFFFFFLL
              | (unsigned int)((_DWORD)v17 << 28)
              | ((unsigned __int64)((unsigned __int8)v17 >> 4) << 32) & 0xF0FFFFFFFFFFFFFFLL
              | ((unsigned __int64)(((unsigned int)v17 >> 8) & 0xF) << 36) & 0xF0FFFFFFFFFFFFFFLL
              | ((unsigned __int64)((unsigned __int16)v17 >> 12) << 40) & 0xF0FFFFFFFFFFFFFFLL
              | ((unsigned __int64)(WORD1(v17) & 0xF) << 44) & 0xF0FFFFFFFFFFFFFFLL
              | ((unsigned __int64)((unsigned int)v17 >> 28) << 56),
          *(_QWORD *)(a4 + 17) = v12,
          a3 == 23) )
    {
LABEL_17:
      *(_BYTE *)a4 = 0;
      result = 4;
      goto LABEL_16;
    }
    v13 = a2[23];
    v14 = *(_QWORD *)(a4 + 1);
    v15 = *(_BYTE *)(a4 + 25) & 0xF0 | (v13 >> 4);
    *(_QWORD *)(a4 + 17) = v12 & 0xFFFFFFFFFFFFFFFLL | ((unsigned __int64)v13 << 60);
    *(_BYTE *)(a4 + 25) = v15;
    if ( v14 < 0 )
    {
      v16 = (unsigned __int8)(a3 - 24);
      *(_BYTE *)(a4 + 26) = a3 - 24;
      if ( (unsigned int)v16 >= 0x3F )
      {
        *(_BYTE *)a4 = 0;
        result = 8;
        goto LABEL_16;
      }
      qdf_mem_copy((void *)(a4 + 27), a2 + 24, v16);
    }
    result = 0;
    goto LABEL_16;
  }
  result = 32;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
