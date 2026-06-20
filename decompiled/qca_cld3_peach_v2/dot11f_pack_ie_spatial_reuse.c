__int64 __fastcall dot11f_pack_ie_spatial_reuse(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  int v5; // w9
  unsigned int v6; // w8
  __int64 result; // x0
  int v8; // w19
  _BYTE *v9; // x20
  int v10; // w8

  if ( !*a2 )
    return 0;
  if ( (a2[1] & 8) != 0 )
    v5 = 20;
  else
    v5 = 2;
  if ( (a2[1] & 4) != 0 )
    v6 = v5;
  else
    v6 = 1;
  if ( v6 > a4 )
    return 268435461;
  v8 = *a5;
  *a3 = -1;
  v9 = a3 + 1;
  *a5 += 2;
  a3[2] = 39;
  ++*a5;
  a3[3] = a2[1];
  v10 = *a5 + 1;
  *a5 = v10;
  if ( (a2[1] & 4) != 0 )
  {
    a3[4] = a2[2];
    v10 = *a5 + 1;
    *a5 = v10;
    if ( (a2[1] & 8) != 0 )
    {
      a3[5] = a2[3];
      ++*a5;
      a3[6] = a2[4];
      ++*a5;
      qdf_mem_copy(a3 + 7, a2 + 5, 8u);
      *a5 += 8;
      qdf_mem_copy(a3 + 15, a2 + 13, 8u);
      v10 = *a5 + 8;
      *a5 = v10;
    }
  }
  result = 0;
  if ( v9 )
    *v9 = v10 - v8 - 2;
  return result;
}
