__int64 __fastcall sde_hw_uidle_setup_cntr(__int64 a1, char a2)
{
  int v4; // w9
  int v5; // w8

  v4 = sde_reg_read(a1, 80) & 0xFFFFFEFF;
  if ( (a2 & 1) != 0 )
    v5 = 256;
  else
    v5 = 0;
  return sde_reg_write(a1, 80, v4 | (unsigned int)v5, "UIDLE_GATE_CNTR_CTL");
}
