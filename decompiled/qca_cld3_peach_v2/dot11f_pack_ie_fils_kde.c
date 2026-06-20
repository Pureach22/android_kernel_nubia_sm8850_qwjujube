__int64 __fastcall dot11f_pack_ie_fils_kde(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w19
  _BYTE *v7; // x20
  int v11; // w8

  if ( !*a2 )
    return 0;
  if ( (unsigned int)(unsigned __int8)a2[9] + 8 > a4 )
    return 268435461;
  v6 = *a5;
  *a3 = -1;
  v7 = a3 + 1;
  *a5 += 2;
  a3[2] = 7;
  ++*a5;
  qdf_mem_copy(a3 + 3, a2 + 1, 8u);
  *a5 += 8;
  qdf_mem_copy(a3 + 11, a2 + 10, (unsigned __int8)a2[9]);
  result = 0;
  v11 = *a5 + (unsigned __int8)a2[9];
  *a5 = v11;
  if ( v7 )
    *v7 = v11 - v6 - 2;
  return result;
}
