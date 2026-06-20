__int64 __fastcall sub_1D023C(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        double a6,
        double a7,
        int16x8_t a8)
{
  int16x8_t v8; // q22

  return dsi_ctrl_hw_22_reg_dump_to_buffer(a1, a2, a3, a4, a5, COERCE_LONG_DOUBLE(vtrn1q_s16(a8, v8)));
}
