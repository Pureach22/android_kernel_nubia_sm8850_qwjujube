__int64 __fastcall gen8_swfuse_irqctrl(__int64 a1, char a2)
{
  __int64 v2; // x1

  if ( (a2 & 1) != 0 )
    v2 = 7;
  else
    v2 = 0;
  return kgsl_regmap_write(a1 + 13200, v2);
}
