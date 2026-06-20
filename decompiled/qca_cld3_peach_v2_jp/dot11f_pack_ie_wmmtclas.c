__int64 __fastcall dot11f_pack_ie_wmmtclas(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  int v5; // w8
  int v6; // w8
  __int64 result; // x0
  int v8; // w19
  _BYTE *v9; // x20
  int v10; // w8
  int v11; // w9
  int *v14; // x21
  void *v15; // x0
  _WORD *v16; // x1
  size_t v17; // x2
  __int16 v18; // w8
  int v19; // w22
  int v20; // w9
  char v23; // w8
  __int16 v24; // w8
  _WORD v27[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)a2 )
  {
    result = 0;
    goto LABEL_32;
  }
  v5 = *(unsigned __int8 *)(a2 + 3);
  if ( *(_BYTE *)(a2 + 3) )
  {
    if ( v5 == 2 )
    {
      if ( a4 < 6 )
        goto LABEL_17;
    }
    else
    {
      if ( v5 == 1 )
      {
        v6 = *(unsigned __int8 *)(a2 + 6);
        if ( v6 == 4 )
        {
          if ( a4 >= 0x14 )
            goto LABEL_19;
        }
        else if ( v6 == 6 )
        {
          if ( a4 >= 0x2C )
            goto LABEL_19;
        }
        else if ( a4 >= 5 )
        {
          goto LABEL_19;
        }
LABEL_17:
        result = 268435461;
        goto LABEL_32;
      }
      if ( a4 < 4 )
        goto LABEL_17;
    }
  }
  else if ( a4 < 0x12 )
  {
    goto LABEL_17;
  }
LABEL_19:
  v8 = *a5;
  *a3 = -35;
  v9 = a3 + 1;
  *a5 += 2;
  a3[2] = 0;
  ++*a5;
  a3[3] = 80;
  ++*a5;
  a3[4] = -14;
  ++*a5;
  a3[5] = 2;
  ++*a5;
  a3[6] = 6;
  ++*a5;
  a3[7] = *(_BYTE *)(a2 + 1);
  ++*a5;
  a3[8] = *(_BYTE *)(a2 + 2);
  ++*a5;
  a3[9] = *(_BYTE *)(a2 + 3);
  ++*a5;
  a3[10] = *(_BYTE *)(a2 + 4);
  v10 = *a5 + 1;
  *a5 = v10;
  v11 = *(unsigned __int8 *)(a2 + 3);
  if ( v11 == 2 )
  {
    v24 = *(_WORD *)(a2 + 6);
    v15 = a3 + 11;
    v16 = v27;
    v17 = 2;
    v19 = 2;
    v14 = a5;
    v27[0] = v24;
LABEL_28:
    qdf_mem_copy(v15, v16, v17);
    goto LABEL_29;
  }
  if ( v11 != 1 )
  {
    if ( *(_BYTE *)(a2 + 3) )
      goto LABEL_30;
    v14 = a5;
    qdf_mem_copy(a3 + 11, (const void *)(a2 + 6), 6u);
    *v14 += 6;
    qdf_mem_copy(a3 + 17, (const void *)(a2 + 12), 6u);
    v15 = a3 + 23;
    v16 = v27;
    v17 = 2;
    *v14 += 6;
    v18 = *(_WORD *)(a2 + 18);
    v19 = 2;
    v27[0] = v18;
    goto LABEL_28;
  }
  a3[11] = *(_BYTE *)(a2 + 6);
  v10 = *a5 + 1;
  *a5 = v10;
  v20 = *(unsigned __int8 *)(a2 + 6);
  if ( v20 == 6 )
  {
    v14 = a5;
    qdf_mem_copy(a3 + 12, (const void *)(a2 + 8), 0xAu);
    *v14 += 10;
    qdf_mem_copy(a3 + 22, (const void *)(a2 + 24), 0xAu);
    *v14 += 10;
    v27[0] = *(_WORD *)(a2 + 40);
    qdf_mem_copy(a3 + 32, v27, 2u);
    *v14 += 2;
    v27[0] = *(_WORD *)(a2 + 42);
    qdf_mem_copy(a3 + 34, v27, 2u);
    v15 = a3 + 36;
    v16 = (_WORD *)(a2 + 44);
    v17 = 3;
    v19 = 3;
    *v14 += 2;
    goto LABEL_28;
  }
  if ( v20 != 4 )
    goto LABEL_30;
  v14 = a5;
  qdf_mem_copy(a3 + 12, (const void *)(a2 + 8), 4u);
  *v14 += 4;
  qdf_mem_copy(a3 + 16, (const void *)(a2 + 12), 4u);
  *v14 += 4;
  v27[0] = *(_WORD *)(a2 + 16);
  qdf_mem_copy(a3 + 20, v27, 2u);
  *v14 += 2;
  v27[0] = *(_WORD *)(a2 + 18);
  qdf_mem_copy(a3 + 22, v27, 2u);
  *v14 += 2;
  a3[24] = *(_BYTE *)(a2 + 20);
  ++*v14;
  a3[25] = *(_BYTE *)(a2 + 21);
  ++*v14;
  v23 = *(_BYTE *)(a2 + 22);
  v19 = 1;
  a3[26] = v23;
LABEL_29:
  v10 = *v14 + v19;
  *v14 = v10;
LABEL_30:
  result = 0;
  if ( v9 )
    *v9 = v10 - v8 - 2;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
