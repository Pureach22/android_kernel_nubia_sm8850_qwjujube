__int64 __fastcall sde_hw_lm_setup_misr(__int64 a1, char a2, unsigned __int8 a3)
{
  __int64 v6; // x2

  sde_reg_write(a1, 784, 1024, "LM_MISR_CTRL");
  __dsb(0xEu);
  if ( (a2 & 1) != 0 )
    v6 = a3 | 0x80000100;
  else
    v6 = 0;
  return sde_reg_write(a1, 784, v6, "LM_MISR_CTRL");
}
