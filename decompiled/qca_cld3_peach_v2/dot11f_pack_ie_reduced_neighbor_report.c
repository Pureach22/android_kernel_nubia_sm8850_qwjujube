__int64 __fastcall dot11f_pack_ie_reduced_neighbor_report(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  int v8; // w22
  int v10; // w8
  unsigned int v11; // w9
  void *v12; // x0
  int v13; // w8
  __int64 result; // x0
  char v15; // w8
  int *v16; // x1
  size_t v17; // x2
  int v18; // w21
  unsigned int v19; // w8
  char v20; // w8
  char v21; // w8
  char v22; // w8
  char v23; // w8
  char v24; // w8
  char v25; // w8
  char v26; // w8
  int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)a2 )
  {
    result = 0;
    goto LABEL_38;
  }
  if ( (unsigned __int8)(*(_BYTE *)(a2 + 2) - 1) <= 0xFu )
  {
    if ( dword_B081A4[(unsigned __int8)(*(_BYTE *)(a2 + 2) - 1)] <= a4 )
      goto LABEL_4;
LABEL_12:
    result = 268435461;
    goto LABEL_38;
  }
  if ( a4 < 4 )
    goto LABEL_12;
LABEL_4:
  v8 = *a5;
  *a3 = -55;
  *a5 += 2;
  LOWORD(v27) = *(_WORD *)(a2 + 1);
  qdf_mem_copy(a3 + 2, &v27, 2u);
  *a5 += 2;
  a3[4] = *(_BYTE *)(a2 + 3);
  ++*a5;
  a3[5] = *(_BYTE *)(a2 + 4);
  v10 = *a5 + 1;
  *a5 = v10;
  v11 = *(unsigned __int8 *)(a2 + 2);
  if ( v11 <= 7 )
  {
    if ( *(unsigned __int8 *)(a2 + 2) <= 4u )
    {
      if ( v11 == 1 )
      {
        v21 = *(_BYTE *)(a2 + 8);
        v18 = 1;
        a3[6] = v21;
      }
      else
      {
        if ( v11 != 2 )
          goto LABEL_36;
        a3[6] = *(_BYTE *)(a2 + 8);
        ++*a5;
        v20 = *(_BYTE *)(a2 + 9);
        v18 = 1;
        a3[7] = v20;
      }
    }
    else
    {
      if ( v11 == 5 )
      {
        v12 = a3 + 7;
        a3[6] = *(_BYTE *)(a2 + 8);
        ++*a5;
        v13 = *(_DWORD *)(a2 + 12);
LABEL_31:
        v27 = v13;
        v16 = &v27;
        v17 = 4;
        v18 = 4;
LABEL_32:
        qdf_mem_copy(v12, v16, v17);
        goto LABEL_35;
      }
      if ( v11 != 6 )
      {
        if ( v11 != 7 )
          goto LABEL_36;
        v15 = *(_BYTE *)(a2 + 8);
        v12 = a3 + 7;
        v16 = (int *)(a2 + 9);
        v17 = 6;
        v18 = 6;
        a3[6] = v15;
        ++*a5;
        goto LABEL_32;
      }
      a3[6] = *(_BYTE *)(a2 + 8);
      ++*a5;
      v27 = *(_DWORD *)(a2 + 12);
      qdf_mem_copy(a3 + 7, &v27, 4u);
      *a5 += 4;
      v22 = *(_BYTE *)(a2 + 16);
      v18 = 1;
      a3[11] = v22;
    }
  }
  else if ( *(unsigned __int8 *)(a2 + 2) > 0xBu )
  {
    if ( v11 == 12 )
    {
      a3[6] = *(_BYTE *)(a2 + 8);
      ++*a5;
      qdf_mem_copy(a3 + 7, (const void *)(a2 + 9), 6u);
      *a5 += 6;
      v27 = *(_DWORD *)(a2 + 16);
      qdf_mem_copy(a3 + 13, &v27, 4u);
      *a5 += 4;
      v26 = *(_BYTE *)(a2 + 20);
      v18 = 1;
      a3[17] = v26;
      goto LABEL_35;
    }
    if ( v11 != 13 )
    {
      if ( v11 != 16 )
        goto LABEL_36;
      a3[6] = *(_BYTE *)(a2 + 8);
      ++*a5;
      qdf_mem_copy(a3 + 7, (const void *)(a2 + 9), 6u);
      *a5 += 6;
      v27 = *(_DWORD *)(a2 + 16);
      qdf_mem_copy(a3 + 13, &v27, 4u);
      *a5 += 4;
      a3[17] = *(_BYTE *)(a2 + 20);
      ++*a5;
      a3[18] = *(_BYTE *)(a2 + 21);
      ++*a5;
      a3[19] = *(_BYTE *)(a2 + 22);
      ++*a5;
      if ( (a4 & 0xFFFFFFFE) == 2 )
      {
        result = 4;
        goto LABEL_38;
      }
      v19 = *(_DWORD *)(a2 + 23);
      v12 = a3 + 20;
      v16 = &v27;
      v17 = 2;
      v18 = 2;
      LOWORD(v27) = (v19 >> 4) & 0xFFF0 | v19 & 0xF;
      goto LABEL_32;
    }
    a3[6] = *(_BYTE *)(a2 + 8);
    ++*a5;
    qdf_mem_copy(a3 + 7, (const void *)(a2 + 9), 6u);
    *a5 += 6;
    v27 = *(_DWORD *)(a2 + 16);
    qdf_mem_copy(a3 + 13, &v27, 4u);
    *a5 += 4;
    a3[17] = *(_BYTE *)(a2 + 20);
    ++*a5;
    v24 = *(_BYTE *)(a2 + 21);
    v18 = 1;
    a3[18] = v24;
  }
  else
  {
    if ( v11 == 8 )
    {
      a3[6] = *(_BYTE *)(a2 + 8);
      ++*a5;
      qdf_mem_copy(a3 + 7, (const void *)(a2 + 9), 6u);
      *a5 += 6;
      v25 = *(_BYTE *)(a2 + 15);
      v18 = 1;
      a3[13] = v25;
      goto LABEL_35;
    }
    if ( v11 != 9 )
    {
      if ( v11 != 11 )
        goto LABEL_36;
      a3[6] = *(_BYTE *)(a2 + 8);
      ++*a5;
      qdf_mem_copy(a3 + 7, (const void *)(a2 + 9), 6u);
      v12 = a3 + 13;
      *a5 += 6;
      v13 = *(_DWORD *)(a2 + 16);
      goto LABEL_31;
    }
    a3[6] = *(_BYTE *)(a2 + 8);
    ++*a5;
    qdf_mem_copy(a3 + 7, (const void *)(a2 + 9), 6u);
    *a5 += 6;
    a3[13] = *(_BYTE *)(a2 + 15);
    ++*a5;
    v23 = *(_BYTE *)(a2 + 16);
    v18 = 1;
    a3[14] = v23;
  }
LABEL_35:
  v10 = *a5 + v18;
  *a5 = v10;
LABEL_36:
  result = 0;
  if ( a3 != (_BYTE *)-1LL )
    a3[1] = v10 - v8 - 2;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
