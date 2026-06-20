__int64 __fastcall dot11f_pack_ie_wapi(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  int v6; // w8
  int v7; // w10
  unsigned int v8; // w8
  unsigned int v9; // w10
  __int64 result; // x0
  int v11; // w22
  char *v12; // x21
  _BYTE *v13; // x23
  char *v16; // x21
  char *v17; // x21
  int v18; // w8
  _WORD v19[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a2 )
  {
    v6 = 4 * (*(unsigned __int16 *)(a2 + 22) + *(unsigned __int16 *)(a2 + 4));
    v7 = v6 + 16 * *(unsigned __int16 *)(a2 + 46);
    v8 = v6 + 12;
    v9 = v7 + 14;
    if ( *(_WORD *)(a2 + 46) )
      v8 = v9;
    if ( v8 <= a4 )
    {
      v11 = *a5;
      *a3 = 68;
      v12 = a3 + 6;
      v13 = a3 + 1;
      *a5 += 2;
      v19[0] = *(_WORD *)(a2 + 2);
      qdf_mem_copy(a3 + 2, v19, 2u);
      *a5 += 2;
      v19[0] = *(_WORD *)(a2 + 4);
      qdf_mem_copy(a3 + 4, v19, 2u);
      *a5 += 2;
      qdf_mem_copy(v12, (const void *)(a2 + 6), 4 * (unsigned int)*(unsigned __int16 *)(a2 + 4));
      *a5 += 4 * *(unsigned __int16 *)(a2 + 4);
      v16 = &v12[4 * *(unsigned __int16 *)(a2 + 4)];
      v19[0] = *(_WORD *)(a2 + 22);
      qdf_mem_copy(v16, v19, 2u);
      v16 += 2;
      *a5 += 2;
      qdf_mem_copy(v16, (const void *)(a2 + 24), 4 * (unsigned int)*(unsigned __int16 *)(a2 + 22));
      *a5 += 4 * *(unsigned __int16 *)(a2 + 22);
      v17 = &v16[4 * *(unsigned __int16 *)(a2 + 22)];
      qdf_mem_copy(v17, (const void *)(a2 + 40), 4u);
      *a5 += 4;
      v19[0] = *(_WORD *)(a2 + 44);
      qdf_mem_copy(v17 + 4, v19, 2u);
      v18 = *a5 + 2;
      *a5 = v18;
      if ( *(_WORD *)(a2 + 46) )
      {
        v19[0] = *(_WORD *)(a2 + 46);
        qdf_mem_copy(v17 + 6, v19, 2u);
        *a5 += 2;
        qdf_mem_copy(v17 + 8, (const void *)(a2 + 48), 16 * (unsigned int)*(unsigned __int16 *)(a2 + 46));
        v18 = *a5 + 16 * *(unsigned __int16 *)(a2 + 46);
        *a5 = v18;
      }
      result = 0;
      if ( v13 )
        *v13 = v18 - v11 - 2;
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
