__int64 __fastcall dot11f_pack_ie_wpa(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  int v8; // w8
  int v9; // w8
  unsigned int v10; // w10
  unsigned int v11; // w8
  __int64 result; // x0
  int v13; // w22
  _BYTE *v14; // x23
  int v15; // w8
  char *v16; // x21
  __int64 v17; // x8
  char *v18; // x21
  char *v19; // x21
  __int64 v20; // x8
  _WORD v21[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)a2 )
  {
    result = 0;
    goto LABEL_22;
  }
  if ( *(_BYTE *)(a2 + 4) )
  {
    if ( *(_WORD *)(a2 + 10) )
    {
      v8 = 4 * *(unsigned __int16 *)(a2 + 10);
      if ( *(_WORD *)(a2 + 28) )
      {
        v9 = v8 + 4 * *(unsigned __int16 *)(a2 + 28);
        v10 = v9 + 10;
        v11 = v9 + 12;
        if ( !*(_WORD *)(a2 + 46) )
          v11 = v10;
        if ( v11 <= a4 )
          goto LABEL_15;
LABEL_13:
        result = 268435461;
        goto LABEL_22;
      }
      if ( v8 + 8 > a4 )
        goto LABEL_13;
    }
    else if ( a4 < 6 )
    {
      goto LABEL_13;
    }
  }
  else if ( a4 < 2 )
  {
    goto LABEL_13;
  }
LABEL_15:
  v13 = *a5;
  *a3 = -35;
  v14 = a3 + 1;
  *a5 += 2;
  a3[2] = 0;
  ++*a5;
  a3[3] = 80;
  ++*a5;
  a3[4] = -14;
  ++*a5;
  a3[5] = 1;
  ++*a5;
  v21[0] = *(_WORD *)(a2 + 2);
  qdf_mem_copy(a3 + 6, v21, 2u);
  v15 = *a5 + 2;
  *a5 = v15;
  if ( *(_BYTE *)(a2 + 4) )
  {
    qdf_mem_copy(a3 + 8, (const void *)(a2 + 5), 4u);
    v15 = *a5 + 4;
    *a5 = v15;
    if ( *(_WORD *)(a2 + 10) )
    {
      v21[0] = *(_WORD *)(a2 + 10);
      qdf_mem_copy(a3 + 12, v21, 2u);
      v16 = a3 + 14;
      *a5 += 2;
      qdf_mem_copy(v16, (const void *)(a2 + 12), 4 * (unsigned int)*(unsigned __int16 *)(a2 + 10));
      v15 = *a5 + 4 * *(unsigned __int16 *)(a2 + 10);
      *a5 = v15;
      if ( *(_WORD *)(a2 + 28) )
      {
        v17 = *(unsigned __int16 *)(a2 + 10);
        v21[0] = *(_WORD *)(a2 + 28);
        v18 = &v16[4 * v17];
        qdf_mem_copy(v18, v21, 2u);
        v19 = v18 + 2;
        *a5 += 2;
        qdf_mem_copy(v19, (const void *)(a2 + 30), 4 * (unsigned int)*(unsigned __int16 *)(a2 + 28));
        v15 = *a5 + 4 * *(unsigned __int16 *)(a2 + 28);
        *a5 = v15;
        if ( *(_WORD *)(a2 + 46) )
        {
          v20 = *(unsigned __int16 *)(a2 + 28);
          v21[0] = *(_WORD *)(a2 + 46);
          qdf_mem_copy(&v19[4 * v20], v21, 2u);
          v15 = *a5 + 2;
          *a5 = v15;
        }
      }
    }
  }
  result = 0;
  if ( v14 )
    *v14 = v15 - v13 - 2;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
