__int64 __fastcall dot11f_unpack_ie_cf_params(__int64 a1, _BYTE *a2, char a3, _BYTE *a4)
{
  int v5; // w20

  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( !a3 || (a4[1] = *a2, a3 == 1) )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    v5 = a3 & 0xFE;
    a4[2] = a2[1];
    if ( v5 == 2 )
    {
      *a4 = 0;
      return 4;
    }
    else
    {
      qdf_mem_copy(a4 + 4, a2 + 2, 2u);
      if ( v5 == 4 )
      {
        *a4 = 0;
        return 4;
      }
      else
      {
        qdf_mem_copy(a4 + 6, a2 + 4, 2u);
        return 0;
      }
    }
  }
}
