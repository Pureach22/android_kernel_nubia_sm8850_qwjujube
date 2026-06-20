__int64 __fastcall hal_construct_srng_shadow_regs(
        __int64 a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 i; // x20
  __int64 v11; // x24
  unsigned int v12; // w21

  for ( i = 0; i != 29; ++i )
  {
    if ( i != 10 && (i & 0x1E) != 8 )
    {
      v11 = *(_QWORD *)(a1 + 74256) + 36 * i;
      if ( !*(_BYTE *)(v11 + 20) )
      {
        if ( *(_WORD *)(v11 + 4) )
        {
          v12 = 0;
          do
            hal_set_one_shadow_config(a1, i, v12++, a2, a3, a4, a5, a6, a7, a8, a9);
          while ( v12 < *(unsigned __int16 *)(v11 + 4) );
        }
      }
    }
  }
  return 0;
}
