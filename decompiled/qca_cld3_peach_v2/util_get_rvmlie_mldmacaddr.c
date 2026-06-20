__int64 __fastcall util_get_rvmlie_mldmacaddr(unsigned __int8 *a1, unsigned __int64 a2, void *a3, _BYTE *a4)
{
  __int64 result; // x0
  __int16 v9; // w8

  result = 29;
  if ( a1 && a2 && a3 && a4 )
  {
    *a4 = 0;
    qdf_mem_set(a3, 6u, 0);
    if ( a2 >= 5 && *a1 == 255 && a1[2] == 107 && (v9 = *(_WORD *)(a1 + 3), (v9 & 7) == 2) )
    {
      if ( a2 == 5 )
      {
        return 27;
      }
      else if ( (v9 & 0x10) != 0 )
      {
        result = 27;
        if ( a2 >= 0xC && a1[5] >= 7u )
        {
          qdf_mem_copy(a3, a1 + 6, 6u);
          *a4 = 1;
          return 0;
        }
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return 4;
    }
  }
  return result;
}
