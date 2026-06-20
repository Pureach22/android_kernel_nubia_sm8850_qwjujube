__int64 __fastcall dot11f_pack_ie_bw_indication(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w19
  _BYTE *v7; // x20
  int v10; // w8

  if ( !*(_BYTE *)a2 )
    return 0;
  if ( (*(_WORD *)(a2 + 1) & 2 | 4u) > a4 )
    return 268435461;
  v6 = *a5;
  v7 = a3 + 1;
  *a3 = -92;
  *a5 += 2;
  a3[2] = *(_BYTE *)(a2 + 1);
  ++*a5;
  a3[3] = *(_BYTE *)(a2 + 2);
  ++*a5;
  a3[4] = *(_BYTE *)(a2 + 3);
  ++*a5;
  a3[5] = *(_BYTE *)(a2 + 4);
  ++*a5;
  qdf_mem_copy(a3 + 6, (const void *)(a2 + 5), *(_WORD *)(a2 + 1) & 2);
  result = 0;
  v10 = *a5 + (*(_WORD *)(a2 + 1) & 2);
  *a5 = v10;
  if ( v7 )
    *v7 = v10 - v6 - 2;
  return result;
}
