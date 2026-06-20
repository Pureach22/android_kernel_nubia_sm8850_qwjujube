__int64 __fastcall sub_11368(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  return wcd9378_mbhc_get_impedance(a1, a2, a3, a4 & 0xFFF80000 | (a4 >> 9) & 0x7FFFF);
}
