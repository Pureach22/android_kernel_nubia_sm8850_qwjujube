__int64 __fastcall dot11f_pack_ie_time_advertisement(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w19
  _BYTE *v7; // x20
  int v11; // w8

  if ( !*a2 )
    return 0;
  if ( a4 < 0x10 )
    return 268435461;
  v6 = *a5;
  v7 = a3 + 1;
  *a3 = 69;
  *a5 += 2;
  a3[2] = a2[1];
  ++*a5;
  qdf_mem_copy(a3 + 3, a2 + 2, 0xAu);
  *a5 += 10;
  qdf_mem_copy(a3 + 13, a2 + 12, 5u);
  result = 0;
  v11 = *a5 + 5;
  *a5 = v11;
  if ( v7 )
    *v7 = v11 - v6 - 2;
  return result;
}
