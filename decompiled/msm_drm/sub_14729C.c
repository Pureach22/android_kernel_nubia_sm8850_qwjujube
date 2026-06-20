__int64 __fastcall sub_14729C(long double a1, long double a2, float a3)
{
  short float v3; // h16
  short float v4; // h30

  *(short float *)&a3 = -(short float)(v4 - (short float)(*(short float *)&a3 * v3));
  return log_sde_reg_write(a1, a2, a3);
}
