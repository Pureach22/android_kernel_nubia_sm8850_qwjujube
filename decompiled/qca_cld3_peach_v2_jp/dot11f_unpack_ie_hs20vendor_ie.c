__int64 __fastcall dot11f_unpack_ie_hs20vendor_ie(__int64 a1, unsigned __int8 *a2, char a3, _BYTE *a4)
{
  const void *v5; // x1
  unsigned int v6; // w9
  unsigned int v7; // t1
  int v8; // w9

  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( a3 )
  {
    v7 = *a2;
    v5 = a2 + 1;
    v6 = v7;
    a4[1] = v7;
    if ( a3 == 1 )
      return 0;
    v8 = (v6 >> 1) & 3;
    if ( v8 != 2 && v8 != 1 )
      return 0;
    if ( (unsigned __int8)(a3 - 1) != 1 )
    {
      qdf_mem_copy(a4 + 2, v5, 2u);
      return 0;
    }
  }
  *a4 = 0;
  return 4;
}
