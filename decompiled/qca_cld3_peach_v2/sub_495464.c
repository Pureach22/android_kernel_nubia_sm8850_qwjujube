__int64 __fastcall sub_495464(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  _WORD *v8; // x20
  __int64 v9; // d8

  *v8 = HIWORD(a6);
  v8[1] = HIWORD(a7);
  v8[2] = HIWORD(a8);
  v8[3] = HIWORD(v9);
  return sme_set_apf_enable_disable();
}
