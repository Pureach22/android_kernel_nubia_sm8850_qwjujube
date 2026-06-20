__int64 __fastcall dot11f_pack_ie_he_cap(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  unsigned int v8; // w8
  __int64 result; // x0
  int v10; // w22
  unsigned int v12; // w23
  _BYTE *v13; // x23
  char *v14; // x21
  char *v15; // x21
  unsigned __int64 v16; // x8
  char *v17; // x21
  char *v18; // x21
  int v19; // w8
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a2 )
  {
    v8 = ((*(_QWORD *)(a2 + 1) >> 51) & 4) + ((*(_QWORD *)(a2 + 1) >> 50) & 4) + 21;
    if ( (*(_BYTE *)(a2 + 14) & 4) != 0 )
      v8 += *(unsigned __int8 *)(a2 + 32);
    if ( v8 <= a4 )
    {
      v10 = *a5;
      *a3 = -1;
      *a5 += 2;
      a3[2] = 35;
      ++*a5;
      v20 = *(_QWORD *)(a2 + 1);
      qdf_mem_copy(a3 + 3, &v20, 4u);
      v12 = a4 & 0xFFFFFFFE;
      *a5 += 4;
      if ( v12 == 4 )
        goto LABEL_14;
      LOWORD(v20) = HIDWORD(*(_QWORD *)(a2 + 1)) & 0x7F | (*(_QWORD *)(a2 + 1) >> 33) & 0xFF80;
      qdf_mem_copy(a3 + 7, &v20, 2u);
      *a5 += 2;
      v20 = (*(_QWORD *)(a2 + 1) >> 49) | (*(_DWORD *)(a2 + 9) << 15);
      qdf_mem_copy(a3 + 9, &v20, 4u);
      *a5 += 4;
      v20 = ((unsigned int)*(_QWORD *)(a2 + 9) >> 19) & 0x7E0
          | ((unsigned int)*(_QWORD *)(a2 + 9) >> 17) & 0x1F
          | (*(_QWORD *)(a2 + 9) >> 19) & 0xFFFFF800;
      qdf_mem_copy(a3 + 13, &v20, 4u);
      *a5 += 4;
      if ( v12 == 14 )
      {
LABEL_14:
        result = 4;
      }
      else
      {
        v13 = a3 + 1;
        LOWORD(v20) = (*(_QWORD *)(a2 + 9) >> 51) & 0x1FFF
                    | ((*(_BYTE *)(a2 + 17) & 1) << 13) & 0x3FFF
                    | (((*(_BYTE *)(a2 + 17) >> 1) & 3) << 14);
        qdf_mem_copy(a3 + 17, &v20, 2u);
        *a5 += 2;
        a3[19] = *(_BYTE *)(a2 + 18);
        ++*a5;
        LOWORD(v20) = *(_WORD *)(a2 + 20);
        qdf_mem_copy(a3 + 20, &v20, 2u);
        *a5 += 2;
        LOWORD(v20) = *(_WORD *)(a2 + 22);
        qdf_mem_copy(a3 + 22, &v20, 2u);
        v14 = a3 + 24;
        *a5 += 2;
        qdf_mem_copy(v14, (const void *)(a2 + 24), (*(_QWORD *)(a2 + 1) >> 51) & 2LL);
        *a5 += (*(_QWORD *)(a2 + 1) >> 51) & 2;
        v15 = &v14[(*(_QWORD *)(a2 + 1) >> 51) & 2LL];
        qdf_mem_copy(v15, (const void *)(a2 + 26), (*(_QWORD *)(a2 + 1) >> 51) & 2LL);
        *a5 += (*(_QWORD *)(a2 + 1) >> 51) & 2;
        v16 = *(_QWORD *)(a2 + 1);
        v17 = &v15[(v16 >> 51) & 2];
        qdf_mem_copy(v17, (const void *)(a2 + 28), (v16 >> 52) & 2);
        *a5 += (*(_QWORD *)(a2 + 1) >> 52) & 2;
        v18 = &v17[(*(_QWORD *)(a2 + 1) >> 52) & 2LL];
        qdf_mem_copy(v18, (const void *)(a2 + 30), (*(_QWORD *)(a2 + 1) >> 52) & 2LL);
        v19 = ((*(_QWORD *)(a2 + 1) >> 52) & 2) + *a5;
        *a5 = v19;
        if ( (*(_BYTE *)(a2 + 14) & 4) != 0 )
        {
          qdf_mem_copy(&v18[(*(_QWORD *)(a2 + 1) >> 52) & 2LL], (const void *)(a2 + 33), *(unsigned __int8 *)(a2 + 32));
          v19 = *a5 + *(unsigned __int8 *)(a2 + 32);
          *a5 = v19;
        }
        result = 0;
        if ( v13 )
          *v13 = v19 - v10 - 2;
      }
    }
    else
    {
      result = 268435461;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
