unsigned __int16 *__fastcall qdf_mem_multi_pages_zero(unsigned __int16 *result, char a2)
{
  unsigned __int16 *v2; // x19
  unsigned int v3; // w8
  unsigned __int64 i; // x20
  void **v5; // x20
  unsigned int j; // w21

  v2 = result;
  if ( *((_QWORD *)result + 3) )
  {
    v3 = result[1];
    if ( (a2 & 1) != 0 )
      goto LABEL_3;
  }
  else
  {
    *((_QWORD *)result + 3) = 4096;
    v3 = result[1];
    if ( (a2 & 1) != 0 )
    {
LABEL_3:
      if ( v3 )
      {
        for ( i = 0; i < v3; ++i )
        {
          result = *(unsigned __int16 **)(*((_QWORD *)v2 + 2) + 8 * i);
          if ( result )
          {
            result = (unsigned __int16 *)memset(result, 0, *((unsigned int *)v2 + 6));
            v3 = v2[1];
          }
        }
      }
      return result;
    }
  }
  if ( v3 )
  {
    v5 = *((void ***)result + 1);
    for ( j = 0; j < v3; ++j )
    {
      result = (unsigned __int16 *)*v5;
      if ( *v5 )
      {
        result = (unsigned __int16 *)memset(result, 0, *((unsigned int *)v2 + 6));
        v3 = v2[1];
      }
      v5 += 3;
    }
  }
  return result;
}
