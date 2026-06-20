__int64 __fastcall dot11f_pack_ie_igtk(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w19
  _BYTE *v7; // x20
  int v11; // w8

  if ( !*a2 )
    return 0;
  if ( a4 < 0x21 )
    return 268435461;
  v6 = *a5;
  v7 = a3 + 1;
  *a3 = 4;
  *a5 += 2;
  qdf_mem_copy(a3 + 2, a2 + 1, 2u);
  *a5 += 2;
  qdf_mem_copy(a3 + 4, a2 + 3, 6u);
  *a5 += 6;
  a3[10] = a2[9];
  ++*a5;
  qdf_mem_copy(a3 + 11, a2 + 10, 0x18u);
  result = 0;
  v11 = *a5 + 24;
  *a5 = v11;
  if ( v7 )
    *v7 = v11 - v6 - 2;
  return result;
}
