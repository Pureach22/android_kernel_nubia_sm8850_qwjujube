__int64 __fastcall dot11f_pack_ie_rsn(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  unsigned int v8; // w8
  unsigned int v9; // w8
  unsigned int v10; // w10
  unsigned int v11; // w8
  __int64 result; // x0
  int v13; // w23
  _BYTE *v14; // x24
  int v15; // w8
  char *v16; // x21
  __int64 v17; // x8
  char *v18; // x21
  char *v19; // x21
  char *v20; // x21
  char *v21; // x22
  _WORD v22[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)a2 )
  {
    result = 0;
    goto LABEL_34;
  }
  if ( !*(_BYTE *)(a2 + 4) )
  {
    if ( a4 >= 2 )
      goto LABEL_21;
LABEL_19:
    result = 268435461;
    goto LABEL_34;
  }
  if ( !*(_WORD *)(a2 + 10) )
  {
    if ( a4 >= 6 )
      goto LABEL_21;
    goto LABEL_19;
  }
  v8 = 4 * *(unsigned __int16 *)(a2 + 10);
  if ( !*(_WORD *)(a2 + 36) )
  {
LABEL_17:
    v8 += 8;
LABEL_18:
    if ( v8 <= a4 )
      goto LABEL_21;
    goto LABEL_19;
  }
  v8 += 4 * *(unsigned __int16 *)(a2 + 36) + 10;
  if ( !*(_BYTE *)(a2 + 70) )
    goto LABEL_18;
  if ( !*(_WORD *)(a2 + 74) )
  {
    if ( !*(_BYTE *)(a2 + 140) )
    {
      if ( v8 + 2 <= a4 )
        goto LABEL_21;
      goto LABEL_19;
    }
    goto LABEL_17;
  }
  v9 = v8 + 16 * *(unsigned __int16 *)(a2 + 74);
  v10 = v9 + 4;
  v11 = v9 + 8;
  if ( !*(_BYTE *)(a2 + 140) )
    v11 = v10;
  if ( v11 > a4 )
    goto LABEL_19;
LABEL_21:
  v13 = *a5;
  *a3 = 48;
  v14 = a3 + 1;
  *a5 += 2;
  v22[0] = *(_WORD *)(a2 + 2);
  qdf_mem_copy(a3 + 2, v22, 2u);
  v15 = *a5 + 2;
  *a5 = v15;
  if ( *(_BYTE *)(a2 + 4) )
  {
    qdf_mem_copy(a3 + 4, (const void *)(a2 + 5), 4u);
    v15 = *a5 + 4;
    *a5 = v15;
    if ( *(_WORD *)(a2 + 10) )
    {
      v22[0] = *(_WORD *)(a2 + 10);
      qdf_mem_copy(a3 + 8, v22, 2u);
      v16 = a3 + 10;
      *a5 += 2;
      qdf_mem_copy(v16, (const void *)(a2 + 12), 4 * (unsigned int)*(unsigned __int16 *)(a2 + 10));
      v15 = *a5 + 4 * *(unsigned __int16 *)(a2 + 10);
      *a5 = v15;
      if ( *(_WORD *)(a2 + 36) )
      {
        v17 = *(unsigned __int16 *)(a2 + 10);
        v22[0] = *(_WORD *)(a2 + 36);
        v18 = &v16[4 * v17];
        qdf_mem_copy(v18, v22, 2u);
        v19 = v18 + 2;
        *a5 += 2;
        qdf_mem_copy(v19, (const void *)(a2 + 38), 4 * (unsigned int)*(unsigned __int16 *)(a2 + 36));
        v15 = *a5 + 4 * *(unsigned __int16 *)(a2 + 36);
        *a5 = v15;
        if ( *(_BYTE *)(a2 + 70) )
        {
          v20 = &v19[4 * *(unsigned __int16 *)(a2 + 36)];
          qdf_mem_copy(v20, (const void *)(a2 + 71), 2u);
          v21 = v20 + 2;
          *a5 += 2;
          if ( *(_WORD *)(a2 + 74) )
          {
            v22[0] = *(_WORD *)(a2 + 74);
          }
          else
          {
            if ( !*(_BYTE *)(a2 + 140) )
              goto LABEL_30;
            v22[0] = 0;
          }
          qdf_mem_copy(v20 + 2, v22, 2u);
          v21 = v20 + 4;
          *a5 += 2;
LABEL_30:
          qdf_mem_copy(v21, (const void *)(a2 + 76), 16 * (unsigned int)*(unsigned __int16 *)(a2 + 74));
          v15 = *a5 + 16 * *(unsigned __int16 *)(a2 + 74);
          *a5 = v15;
          if ( *(_BYTE *)(a2 + 140) )
          {
            qdf_mem_copy(&v21[16 * *(unsigned __int16 *)(a2 + 74)], (const void *)(a2 + 141), 4u);
            v15 = *a5 + 4;
            *a5 = v15;
          }
        }
      }
    }
  }
  result = 0;
  if ( v14 )
    *v14 = v15 - v13 - 2;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
