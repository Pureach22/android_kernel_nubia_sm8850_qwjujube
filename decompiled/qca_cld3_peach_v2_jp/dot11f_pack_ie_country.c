__int64 __fastcall dot11f_pack_ie_country(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v7; // w22
  void *v8; // x21
  _BYTE *v9; // x23
  int v12; // w8

  if ( !*a2 )
    return 0;
  if ( 3 * (unsigned int)(unsigned __int8)a2[7] + 6 > a4 )
    return 268435461;
  v7 = *a5;
  *a3 = 7;
  v8 = a3 + 5;
  v9 = a3 + 1;
  *a5 += 2;
  qdf_mem_copy(a3 + 2, a2 + 1, 3u);
  *a5 += 3;
  qdf_mem_copy(v8, a2 + 4, 3u);
  v12 = *a5 + 3;
  *a5 = v12;
  if ( a2[7] )
  {
    qdf_mem_copy(a3 + 8, a2 + 8, 3 * (unsigned int)(unsigned __int8)a2[7]);
    v12 = 3 * (unsigned __int8)a2[7] + *a5;
    *a5 = v12;
  }
  result = 0;
  if ( v9 )
    *v9 = v12 - v7 - 2;
  return result;
}
