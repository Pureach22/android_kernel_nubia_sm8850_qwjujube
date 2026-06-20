__int64 __fastcall alpha_pll_lucid_evo_disable(__int64 result)
{
  if ( (*(_BYTE *)(result - 8) & 0x40) == 0 )
    return alpha_pll_lucid_evo_disable();
  return result;
}
