unsigned int *__fastcall cp_set_pa_mode(unsigned int *result, __int64 a2, int a3)
{
  unsigned int v4; // w8
  unsigned int v10; // w8

  if ( result )
  {
    if ( a2 )
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v4 = __ldxr(result);
      while ( __stxr(v4 | a3, result) );
    }
    else
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v10 = __ldxr(result);
      while ( __stxr(v10 & ~a3, result) );
    }
  }
  return result;
}
