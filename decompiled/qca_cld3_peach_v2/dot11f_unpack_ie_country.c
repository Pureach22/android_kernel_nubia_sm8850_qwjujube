__int64 __fastcall dot11f_unpack_ie_country(__int64 a1, __int64 a2, unsigned __int8 a3, _BYTE *a4)
{
  size_t v8; // x2

  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( a3 <= 2u || (qdf_mem_copy(a4 + 1, (const void *)a2, 3u), (unsigned __int8)(a3 - 3) <= 2u) )
  {
    *a4 = 0;
    return 4;
  }
  else
  {
    qdf_mem_copy(a4 + 4, (const void *)(a2 + 3), 3u);
    if ( a3 == 6 )
    {
      a4[7] = 0;
      return 0;
    }
    else
    {
      v8 = (unsigned __int8)(a3 - 6);
      a4[7] = (unsigned __int8)(a3 - 6) / 3u;
      if ( (unsigned int)v8 < 0xF1 )
      {
        qdf_mem_copy(a4 + 8, (const void *)(a2 + 6), v8);
        return 0;
      }
      else
      {
        *a4 = 0;
        return 8;
      }
    }
  }
}
