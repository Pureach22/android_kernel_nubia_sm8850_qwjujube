int *__fastcall cp_set_vig_gamut_mode(int *result, __int64 a2)
{
  int v2; // w8

  if ( result )
  {
    if ( a2 )
    {
      if ( !*result )
      {
        v2 = 1;
        goto LABEL_7;
      }
      if ( *result != 1 )
        return result;
    }
    v2 = 0;
LABEL_7:
    *result = v2;
  }
  return result;
}
