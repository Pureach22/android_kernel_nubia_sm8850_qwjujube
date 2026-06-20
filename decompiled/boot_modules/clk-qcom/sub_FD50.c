__int64 sub_FD50()
{
  __asm { PRFM            #0x18, 0x5AF14 }
  return lucid_evo_calc_pll_out();
}
