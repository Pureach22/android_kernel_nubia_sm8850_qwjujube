__int64 __fastcall dot11f_pack_ie_link_identifier(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w20
  void *v7; // x19
  _BYTE *v8; // x21
  int v12; // w8

  if ( !*a2 )
    return 0;
  if ( a4 < 0x12 )
    return 268435461;
  v6 = *a5;
  *a3 = 101;
  v7 = a3 + 14;
  v8 = a3 + 1;
  *a5 += 2;
  qdf_mem_copy(a3 + 2, a2 + 1, 6u);
  *a5 += 6;
  qdf_mem_copy(a3 + 8, a2 + 7, 6u);
  *a5 += 6;
  qdf_mem_copy(v7, a2 + 13, 6u);
  result = 0;
  v12 = *a5 + 6;
  *a5 = v12;
  if ( v8 )
    *v8 = v12 - v6 - 2;
  return result;
}
