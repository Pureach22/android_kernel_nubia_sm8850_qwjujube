__int64 __fastcall sub_AA86C(long double a1, long double a2, long double a3, float a4)
{
  short float v4; // h15
  short float v5; // h17
  short float v6; // h20

  *(short float *)&a4 = v4 - (short float)(v5 * v6);
  return _bpf_trace_rdev_change_beacon(a1, a2, a3, a4);
}
