__int64 __fastcall dot11f_pack_ie_eht_cap(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v7; // w20
  _BYTE *v8; // x21
  int v11; // w8
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)a2 )
  {
    result = 0;
    goto LABEL_11;
  }
  if ( (*(_QWORD *)(a2 + 1) & 0x8000000000000000LL) != 0 )
  {
    if ( (unsigned int)*(unsigned __int8 *)(a2 + 26) + 24 > a4 )
      goto LABEL_4;
  }
  else if ( a4 < 0x18 )
  {
LABEL_4:
    result = 268435461;
    goto LABEL_11;
  }
  v7 = *a5;
  *a3 = -1;
  v8 = a3 + 1;
  *a5 += 2;
  a3[2] = 108;
  ++*a5;
  LOWORD(v12) = *(_QWORD *)(a2 + 1);
  qdf_mem_copy(a3 + 3, &v12, 2u);
  *a5 += 2;
  v12 = ((unsigned int)*(_QWORD *)(a2 + 1) >> 17) & 0x1F80
      | WORD1(*(_QWORD *)(a2 + 1)) & 0x7F
      | (*(_QWORD *)(a2 + 1) >> 17) & 0xFFFFE000;
  qdf_mem_copy(a3 + 5, &v12, 4u);
  *a5 += 4;
  v12 = (*(_QWORD *)(a2 + 1) >> 49) & 0xF | (*(_QWORD *)(a2 + 1) >> 52) & 0xFF0 | (*(_DWORD *)(a2 + 9) << 12);
  qdf_mem_copy(a3 + 9, &v12, 4u);
  *a5 += 4;
  a3[13] = *(_QWORD *)(a2 + 9) >> 20;
  ++*a5;
  v12 = (unsigned int)*(_QWORD *)(a2 + 9) >> 28;
  qdf_mem_copy(a3 + 14, &v12, 4u);
  *a5 += 4;
  v12 = (*(_QWORD *)(a2 + 9) >> 60) | (16 * *(_DWORD *)(a2 + 17));
  qdf_mem_copy(a3 + 18, &v12, 4u);
  *a5 += 4;
  v12 = (unsigned int)*(_QWORD *)(a2 + 17) >> 28;
  qdf_mem_copy(a3 + 22, &v12, 4u);
  *a5 += 4;
  a3[26] = (*(_QWORD *)(a2 + 17) >> 60) | (16 * *(_BYTE *)(a2 + 25));
  v11 = *a5 + 1;
  *a5 = v11;
  if ( (*(_QWORD *)(a2 + 1) & 0x8000000000000000LL) != 0 )
  {
    qdf_mem_copy(a3 + 27, (const void *)(a2 + 27), *(unsigned __int8 *)(a2 + 26));
    v11 = *a5 + *(unsigned __int8 *)(a2 + 26);
    *a5 = v11;
  }
  result = 0;
  if ( v8 )
    *v8 = v11 - v7 - 2;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
