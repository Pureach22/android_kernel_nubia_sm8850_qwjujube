__int64 __fastcall dot11f_unpack_ie_ese_traf_strm_rate_set(__int64 a1, char *a2, char a3, _BYTE *a4)
{
  char v5; // w9
  char v6; // w8
  size_t v7; // x2

  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( a3 )
  {
    v5 = a3 - 1;
    v6 = *a2;
    v7 = (unsigned __int8)(a3 - 1);
    a4[2] = v5;
    a4[1] = v6;
    if ( (unsigned int)v7 < 9 )
    {
      qdf_mem_copy(a4 + 3, a2 + 1, v7);
      return 0;
    }
    else
    {
      *a4 = 0;
      return 8;
    }
  }
  else
  {
    *a4 = 0;
    return 4;
  }
}
