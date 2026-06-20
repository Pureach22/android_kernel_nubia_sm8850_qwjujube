__int64 __fastcall dot11f_pack_ie_dh_parameter_element(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w19
  _BYTE *v7; // x20
  int v11; // w8

  if ( !*a2 )
    return 0;
  if ( (unsigned int)(unsigned __int8)a2[3] + 2 > a4 )
    return 268435461;
  v6 = *a5;
  *a3 = -1;
  v7 = a3 + 1;
  *a5 += 2;
  a3[2] = 32;
  ++*a5;
  qdf_mem_copy(a3 + 3, a2 + 1, 2u);
  *a5 += 2;
  qdf_mem_copy(a3 + 5, a2 + 4, (unsigned __int8)a2[3]);
  result = 0;
  v11 = *a5 + (unsigned __int8)a2[3];
  *a5 = v11;
  if ( v7 )
    *v7 = v11 - v6 - 2;
  return result;
}
