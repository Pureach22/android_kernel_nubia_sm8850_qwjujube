__int64 __fastcall dot11f_pack_ie_supp_channels(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w19
  _BYTE *v7; // x20
  int v10; // w8

  if ( !*a2 )
    return 0;
  if ( a4 < 2 * (unsigned int)(unsigned __int8)a2[1] )
    return 268435461;
  v6 = *a5;
  v7 = a3 + 1;
  *a3 = 36;
  *a5 += 2;
  qdf_mem_copy(a3 + 2, a2 + 2, 2 * (unsigned int)(unsigned __int8)a2[1]);
  result = 0;
  v10 = *a5 + 2 * (unsigned __int8)a2[1];
  *a5 = v10;
  if ( v7 )
    *v7 = v10 - v6 - 2;
  return result;
}
