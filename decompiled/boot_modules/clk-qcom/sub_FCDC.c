__int64 sub_FCDC()
{
  __asm { PRFM            #0x18, 0x5AEA0 }
  return lucid_evo_calc_pll();
}
