__int64 __fastcall sde_hw_lm_setup_color3(__int64 a1, int a2)
{
  int v4; // w0

  v4 = sde_reg_read(a1, 0);
  return sde_reg_write(a1, 0, v4 & 0xC0000000 | a2, "LM_OP_MODE");
}
