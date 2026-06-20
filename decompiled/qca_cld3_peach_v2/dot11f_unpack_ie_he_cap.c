__int64 __fastcall dot11f_unpack_ie_he_cap(__int64 a1, char *a2, int a3, __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 v8; // x12
  unsigned __int64 v9; // x9
  int v10; // w8
  int v11; // w21
  size_t v12; // x2
  char *v13; // x20
  __int64 v14; // x8
  int v15; // w21
  char *v16; // x20
  unsigned __int64 v17; // x9
  size_t v18; // x2
  int v19; // w21
  char *v20; // x20
  __int64 v21; // x8
  unsigned __int8 v22; // w21
  char *v23; // x20
  __int64 v24; // x8
  size_t v25; // x2
  unsigned __int16 v26; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int16 v28[2]; // [xsp+10h] [xbp-10h] BYREF
  int v29; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+18h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)a4 )
  {
    *(_BYTE *)a4 = 1;
    if ( (unsigned __int8)a3 <= 3u )
      goto LABEL_21;
    v29 = 0;
    v28[0] = 0;
    v27 = 0;
    v26 = 0;
    qdf_mem_copy(&v29, a2, 4u);
    *(_QWORD *)(a4 + 1) = v29 & 1
                        | ((unsigned __int64)*(unsigned int *)(a4 + 5) << 32)
                        | v29 & 0x1E
                        | v29 & 0x7FE0
                        | v29 & 0x1F8000
                        | v29 & 0x7E00000
                        | v29 & 0xF8000000;
    if ( (a3 & 0xFE) == 4 )
      goto LABEL_21;
    qdf_mem_copy(v28, a2 + 4, 2u);
    *(_QWORD *)(a4 + 1) = (((unsigned __int64)((v28[0] >> 10) & 1) << 43)
                         | ((unsigned __int64)((v28[0] >> 11) & 1) << 44)
                         | ((unsigned __int64)((v28[0] >> 12) & 1) << 45)
                         | ((unsigned __int64)((v28[0] >> 13) & 1) << 46))
                        & 0xFFFEFFFFFFFFFFFFLL
                        | *(_QWORD *)(a4 + 1) & 0xFFFE0080FFFFFFFFLL
                        | ((unsigned __int64)(v28[0] & 1) << 32) & 0xFFFEFFFFFFFFFFFFLL
                        | ((unsigned __int64)((v28[0] >> 1) & 1) << 33) & 0xFFFEFFFFFFFFFFFFLL
                        | ((unsigned __int64)((v28[0] >> 2) & 1) << 34) & 0xFFFEFFFFFFFFFFFFLL
                        | ((unsigned __int64)((v28[0] >> 3) & 1) << 35) & 0xFFFEFFFFFFFFFFFFLL
                        | (((unsigned __int64)(v28[0] >> 14) << 47)
                         | ((unsigned __int64)((v28[0] >> 4) & 1) << 36)
                         | ((unsigned __int64)((v28[0] >> 5) & 1) << 37)
                         | ((unsigned __int64)((v28[0] >> 6) & 1) << 38)
                         | ((unsigned __int64)((v28[0] >> 7) & 7) << 40))
                        & 0xFFFEFFFFFFFFFFFFLL
                        | ((unsigned __int64)((v28[0] & 0x8000) != 0) << 48);
    if ( (unsigned __int8)(a3 - 6) <= 3u )
      goto LABEL_21;
    qdf_mem_copy((char *)&v27 + 4, a2 + 6, 4u);
    v8 = (unsigned __int64)HIDWORD(v27) >> 14;
    v9 = ((unsigned __int64)((HIDWORD(v27) >> 4) & 1) << 53)
       | ((unsigned __int64)((HIDWORD(v27) >> 5) & 1) << 54)
       | ((unsigned __int64)((HIDWORD(v27) >> 6) & 1) << 55)
       | ((unsigned __int64)((HIDWORD(v27) >> 7) & 1) << 56)
       | ((unsigned __int64)((HIDWORD(v27) >> 8) & 0xF) << 57)
       | ((unsigned __int64)((HIDWORD(v27) >> 12) & 1) << 61)
       | ((unsigned __int64)((HIDWORD(v27) >> 13) & 1) << 62)
       | *(_QWORD *)(a4 + 1) & 0x1FFFFFFFFFFFFLL
       | ((unsigned __int64)(BYTE4(v27) & 1) << 49)
       | ((unsigned __int64)((HIDWORD(v27) >> 1) & 1) << 50)
       | ((unsigned __int64)((HIDWORD(v27) >> 2) & 1) << 51)
       | ((unsigned __int64)((HIDWORD(v27) >> 3) & 1) << 52);
    *(_QWORD *)(a4 + 9) = *(_QWORD *)(a4 + 9) & 0xFFFFFFFFFFFE0000LL | ((unsigned __int64)HIDWORD(v27) >> 15);
    *(_QWORD *)(a4 + 1) = v9 + (v8 << 63);
    if ( (unsigned __int8)(a3 - 10) <= 3u )
      goto LABEL_21;
    qdf_mem_copy(&v27, a2 + 10, 4u);
    *(_QWORD *)(a4 + 9) = (*(_QWORD *)(a4 + 9) & 0xFFF8000000C1FFFFLL
                         | ((_DWORD)v27 << 17) & 0x20000LL
                         | ((_DWORD)v27 << 17) & 0x3C0000LL
                         | ((_DWORD)v27 << 19) & 0x3F000000
                         | ((((unsigned __int64)(unsigned int)v27 >> 30) & 1) << 49) & 0xFFFBFFFFFFFFFFFFLL
                         | ((((unsigned __int64)(unsigned int)v27 >> 11) & 7) << 30)
                         | ((unsigned __int64)(((unsigned int)v27 >> 14) & 1) << 33)
                         | ((unsigned __int64)(((unsigned int)v27 >> 15) & 1) << 34)
                         | ((unsigned __int64)(WORD1(v27) & 1) << 35)
                         | ((unsigned __int64)(((unsigned int)v27 >> 17) & 1) << 36)
                         | ((unsigned __int64)(((unsigned int)v27 >> 18) & 7) << 37)
                         | ((unsigned __int64)(((unsigned int)v27 >> 21) & 1) << 40)
                         | ((unsigned __int64)(((unsigned int)v27 >> 22) & 1) << 41)
                         | ((unsigned __int64)(((unsigned int)v27 >> 23) & 1) << 42)
                         | ((unsigned __int64)(BYTE3(v27) & 1) << 43)
                         | ((unsigned __int64)(((unsigned int)v27 >> 25) & 1) << 44)
                         | ((unsigned __int64)(((unsigned int)v27 >> 26) & 1) << 45)
                         | ((unsigned __int64)(((unsigned int)v27 >> 27) & 7) << 46))
                        + (((unsigned __int64)(unsigned int)v27 << 19) & 0x4000000000000LL);
    if ( (a3 & 0xFE) == 0xE )
      goto LABEL_21;
    qdf_mem_copy(&v26, a2 + 14, 2u);
    v10 = *(_BYTE *)(a4 + 17) & 0xF8 | (v26 >> 13);
    *(_QWORD *)(a4 + 9) = (((unsigned __int64)((v26 >> 4) & 1) << 55)
                         | ((unsigned __int64)((v26 >> 5) & 1) << 56)
                         | ((unsigned __int64)((unsigned __int8)v26 >> 6) << 57)
                         | ((unsigned __int64)(HIBYTE(v26) & 1) << 59)
                         | ((unsigned __int64)((v26 >> 9) & 1) << 60)
                         | ((unsigned __int64)((v26 >> 10) & 1) << 61)
                         | ((unsigned __int64)((v26 >> 11) & 1) << 62)
                         | *(_QWORD *)(a4 + 9) & 0x7FFFFFFFFFFFFLL
                         | ((unsigned __int64)(v26 & 1) << 51)
                         | ((unsigned __int64)((v26 >> 1) & 1) << 52)
                         | ((unsigned __int64)((v26 >> 2) & 1) << 53)
                         | ((unsigned __int64)((v26 >> 3) & 1) << 54))
                        + ((unsigned __int64)(v26 >> 12) << 63);
    *(_BYTE *)(a4 + 17) = v10;
    if ( (unsigned __int8)a3 == 16 )
      goto LABEL_21;
    *(_BYTE *)(a4 + 18) = a2[16];
    if ( (unsigned __int8)(a3 - 17) <= 1u )
      goto LABEL_21;
    qdf_mem_copy((void *)(a4 + 20), a2 + 17, 2u);
    if ( (unsigned __int8)(a3 - 19) <= 1u )
      goto LABEL_21;
    qdf_mem_copy((void *)(a4 + 22), a2 + 19, 2u);
    v11 = a3 - 21;
    v12 = (*(_QWORD *)(a4 + 1) >> 51) & 2LL;
    if ( (unsigned int)v12 > (unsigned __int8)v11 )
      goto LABEL_21;
    v13 = a2 + 21;
    qdf_mem_copy((void *)(a4 + 24), v13, v12);
    v14 = *(_QWORD *)(a4 + 1) >> 51;
    v15 = v11 - (v14 & 2);
    if ( ((unsigned __int8)v14 & 2u) > (unsigned __int8)v15 )
      goto LABEL_21;
    v16 = &v13[v14 & 2];
    qdf_mem_copy((void *)(a4 + 26), v16, v14 & 2);
    v17 = *(_QWORD *)(a4 + 1);
    v18 = (v17 >> 52) & 2;
    v19 = v15 - ((v17 >> 51) & 2);
    if ( (unsigned int)v18 > (unsigned __int8)v19
      || (v20 = &v16[(v17 >> 51) & 2],
          qdf_mem_copy((void *)(a4 + 28), v20, v18),
          v21 = *(_QWORD *)(a4 + 1) >> 52,
          v22 = v19 - (v21 & 2),
          ((unsigned __int8)v21 & 2u) > v22) )
    {
LABEL_21:
      *(_BYTE *)a4 = 0;
      result = 4;
      goto LABEL_20;
    }
    v23 = &v20[v21 & 2];
    qdf_mem_copy((void *)(a4 + 30), v23, v21 & 2);
    if ( (*(_BYTE *)(a4 + 14) & 4) != 0 )
    {
      v24 = *(_QWORD *)(a4 + 1) >> 52;
      v25 = (unsigned __int8)(v22 - (v24 & 2));
      *(_BYTE *)(a4 + 32) = v22 - (v24 & 2);
      if ( (unsigned int)v25 >= 0x1A )
      {
        *(_BYTE *)a4 = 0;
        result = 8;
        goto LABEL_20;
      }
      qdf_mem_copy((void *)(a4 + 33), &v23[v24 & 2], v25);
    }
    result = 0;
    goto LABEL_20;
  }
  result = 32;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
