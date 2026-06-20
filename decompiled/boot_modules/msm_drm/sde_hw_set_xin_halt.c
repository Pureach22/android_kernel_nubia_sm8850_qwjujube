__int64 __fastcall sde_hw_set_xin_halt(__int64 a1, char a2, char a3)
{
  int v6; // w0
  unsigned int v7; // w2
  __int64 result; // x0

  v6 = sde_reg_read(a1, 0x200u);
  if ( (a3 & 1) != 0 )
    v7 = v6 | (1LL << a2);
  else
    v7 = v6 & ~(unsigned int)(1LL << a2);
  result = sde_reg_write(a1, 0x200u, v7, "VBIF_XIN_HALT_CTRL0");
  __dsb(0xEu);
  return result;
}
