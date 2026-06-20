__int64 sub_4B2908()
{
  __asm { PRFM            #0x12, loc_450F18 }
  return dp_srng_msi_setup();
}
