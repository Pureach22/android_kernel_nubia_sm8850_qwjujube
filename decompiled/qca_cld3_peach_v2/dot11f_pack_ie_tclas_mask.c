__int64 __fastcall dot11f_pack_ie_tclas_mask(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  unsigned int v5; // w8
  __int64 result; // x0
  int v7; // w19
  _BYTE *v8; // x20
  int v9; // w8

  if ( !*a2 )
    return 0;
  if ( a2[1] == 4 )
    v5 = 18;
  else
    v5 = 2;
  if ( v5 > a4 )
    return 268435461;
  v7 = *a5;
  *a3 = -1;
  v8 = a3 + 1;
  *a5 += 2;
  a3[2] = 89;
  ++*a5;
  a3[3] = a2[1];
  ++*a5;
  a3[4] = a2[2];
  v9 = *a5 + 1;
  *a5 = v9;
  if ( a2[1] == 4 )
  {
    qdf_mem_copy(a3 + 5, a2 + 3, 0x10u);
    v9 = *a5 + 16;
    *a5 = v9;
  }
  result = 0;
  if ( v8 )
    *v8 = v9 - v7 - 2;
  return result;
}
