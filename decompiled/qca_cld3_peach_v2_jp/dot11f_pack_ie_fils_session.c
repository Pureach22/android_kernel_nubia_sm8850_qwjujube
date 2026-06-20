__int64 __fastcall dot11f_pack_ie_fils_session(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w19
  _BYTE *v7; // x20
  int v9; // w8

  if ( !*a2 )
    return 0;
  if ( a4 < 8 )
    return 268435461;
  v6 = *a5;
  *a3 = -1;
  v7 = a3 + 1;
  *a5 += 2;
  a3[2] = 4;
  ++*a5;
  qdf_mem_copy(a3 + 3, a2 + 1, 8u);
  result = 0;
  v9 = *a5 + 8;
  *a5 = v9;
  if ( v7 )
    *v7 = v9 - v6 - 2;
  return result;
}
