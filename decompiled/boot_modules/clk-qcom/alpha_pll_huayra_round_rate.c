unsigned __int64 __fastcall alpha_pll_huayra_round_rate(__int64 a1, unsigned __int64 a2, _QWORD *a3)
{
  unsigned __int64 result; // x0
  unsigned __int64 v4; // x10
  unsigned __int64 v5; // x9
  unsigned __int64 v6; // x10

  result = a2;
  v4 = (unsigned int)*a3;
  v5 = a2 / v4;
  if ( a2 % v4 )
  {
    v6 = ((a2 % v4) << 16) / v4;
    if ( (v6 & 0x7FFFFFFFFFFF8000LL) != 0 )
      LODWORD(v5) = v5 + 1;
    return 1000
         * ((((unsigned int)v5 - ((v6 & 0xFFFF8000) != 0)) * *a3
           + (((unsigned __int64)(unsigned int)v6 * *a3) >> 16)
           + 999)
          / 0x3E8);
  }
  return result;
}
