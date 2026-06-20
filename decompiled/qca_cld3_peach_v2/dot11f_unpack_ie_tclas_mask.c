__int64 __fastcall dot11f_unpack_ie_tclas_mask(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3, _BYTE *a4)
{
  int v5; // w9

  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( a3 )
  {
    v5 = *a2;
    a4[1] = v5;
    if ( a3 != 1 )
    {
      a4[2] = a2[1];
      if ( v5 != 4 )
        return 0;
      if ( (unsigned int)a3 - 2 > 0xF )
      {
        qdf_mem_copy(a4 + 3, a2 + 2, 0x10u);
        return 0;
      }
    }
  }
  *a4 = 0;
  return 4;
}
