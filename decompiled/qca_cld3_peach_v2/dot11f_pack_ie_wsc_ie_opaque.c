__int64 __fastcall dot11f_pack_ie_wsc_ie_opaque(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w19
  _BYTE *v7; // x20
  int v10; // w8

  if ( !*a2 )
    return 0;
  if ( (unsigned __int8)a2[1] > a4 )
    return 268435461;
  v6 = *a5;
  *a3 = -35;
  v7 = a3 + 1;
  *a5 += 2;
  a3[2] = 0;
  ++*a5;
  a3[3] = 80;
  ++*a5;
  a3[4] = -14;
  ++*a5;
  a3[5] = 4;
  ++*a5;
  qdf_mem_copy(a3 + 6, a2 + 2, (unsigned __int8)a2[1]);
  result = 0;
  v10 = *a5 + (unsigned __int8)a2[1];
  *a5 = v10;
  if ( v7 )
    *v7 = v10 - v6 - 2;
  return result;
}
