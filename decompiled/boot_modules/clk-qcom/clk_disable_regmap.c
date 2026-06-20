__int64 __fastcall clk_disable_regmap(__int64 a1)
{
  __int64 v1; // x2
  __int64 v2; // x3

  v1 = *(unsigned int *)(a1 + 36);
  if ( *(_BYTE *)(a1 + 40) )
    v2 = (unsigned int)v1;
  else
    v2 = 0;
  return regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 + 32), v1, v2, 0, 0, 0);
}
