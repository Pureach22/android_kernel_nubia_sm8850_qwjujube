__int64 __fastcall sub_2964CC(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        float a7)
{
  short float v7; // h8
  short float v8; // h19

  *(short float *)&a7 = *(short float *)&a5 - (short float)(v7 * v8);
  return cam_sensor_power(a1, a2, a3, a4, a5, a6, a7);
}
