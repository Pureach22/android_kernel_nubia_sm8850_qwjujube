__int64 __fastcall util_get_bvmlie_mldmacaddr(unsigned __int8 *a1, unsigned __int64 a2, void *a3)
{
  __int64 result; // x0
  unsigned __int8 *v7; // x21

  result = 29;
  if ( a1 && a2 && a3 )
  {
    v7 = a1;
    qdf_mem_set(a3, 6u, 0);
    if ( a2 >= 5 && *v7 == 255 && v7[2] == 107 && (*(_WORD *)(v7 + 3) & 7) == 0 )
    {
      if ( a2 >= 0xC && v7[5] >= 7u )
      {
        qdf_mem_copy(a3, v7 + 6, 6u);
        return 0;
      }
      else
      {
        return 27;
      }
    }
    else
    {
      return 4;
    }
  }
  return result;
}
