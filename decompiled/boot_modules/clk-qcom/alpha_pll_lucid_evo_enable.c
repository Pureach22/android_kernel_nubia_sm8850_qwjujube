__int64 __fastcall alpha_pll_lucid_evo_enable(__int64 a1)
{
  if ( (*(_BYTE *)(a1 - 8) & 0x40) != 0 )
    return 0;
  else
    return alpha_pll_lucid_evo_enable();
}
