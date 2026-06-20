__int64 __fastcall lpass_cdc_load_compander_coeff(
        __int64 a1,
        unsigned __int16 a2,
        unsigned __int16 a3,
        __int64 a4,
        unsigned __int16 a5)
{
  __int64 v8; // x22
  unsigned __int8 *v9; // x23
  unsigned int v10; // t1

  if ( a5 )
  {
    v8 = a5;
    v9 = (unsigned __int8 *)(a4 + 1);
    do
    {
      snd_soc_component_write(a1, a2, *(v9 - 1));
      v10 = *v9;
      v9 += 2;
      snd_soc_component_write(a1, a3, v10);
      --v8;
    }
    while ( v8 );
  }
  return 0;
}
