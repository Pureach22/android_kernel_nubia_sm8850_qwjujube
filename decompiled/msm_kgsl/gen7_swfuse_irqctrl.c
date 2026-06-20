__int64 __fastcall gen7_swfuse_irqctrl(__int64 result, char a2)
{
  __int64 v2; // x1

  if ( **(_DWORD **)(result + 14264) >> 1 == 230528 )
  {
    if ( (a2 & 1) != 0 )
      v2 = 7;
    else
      v2 = 0;
    return kgsl_regmap_write(result + 13200, v2);
  }
  return result;
}
