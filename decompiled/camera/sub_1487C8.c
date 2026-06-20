__int64 __fastcall sub_1487C8(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        float a5,
        double a6,
        __n128 a7)
{
  short float v7; // h15
  short float v8; // h16

  *(short float *)&a5 = -(short float)(v8 - (short float)(v7 * *(short float *)a7.n128_u16));
  return cam_cpastop_setup_regbase_indices(a1, a2, a3, a4, a5);
}
