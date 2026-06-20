__int64 __fastcall dot11f_pack_ie_ese_traf_strm_rate_set(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  int v5; // w19
  _BYTE *v6; // x20
  __int64 result; // x0
  int v10; // w8

  if ( !*a2 )
    return 0;
  if ( (unsigned __int8)a2[2] >= a4 )
    return 268435461;
  v5 = *a5;
  *a3 = -35;
  v6 = a3 + 1;
  *a5 += 2;
  a3[2] = 0;
  ++*a5;
  a3[3] = 64;
  ++*a5;
  a3[4] = -106;
  ++*a5;
  a3[5] = 8;
  ++*a5;
  a3[6] = a2[1];
  ++*a5;
  qdf_mem_copy(a3 + 7, a2 + 3, (unsigned __int8)a2[2]);
  result = 0;
  v10 = *a5 + (unsigned __int8)a2[2];
  *a5 = v10;
  if ( v6 )
    *v6 = v10 - v5 - 2;
  return result;
}
