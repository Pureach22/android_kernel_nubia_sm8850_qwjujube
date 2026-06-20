__int64 __fastcall wait_for_pde_state(_QWORD *a1, int a2, int a3, unsigned int a4, int a5)
{
  int v5; // w23
  int v10; // w24
  __int64 result; // x0
  _QWORD v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v5 = ((a5 & 7) << 22) | 0x40000000;
  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = 0;
  v10 = (a2 << 15) & 0x200000 | ((a2 & 0x3F) << 7) | v5;
  usleep_range_state(1000, 1500, 2);
  result = regmap_read(*a1, v10 | 0x80000u, (char *)v12 + 4);
  if ( __PAIR64__(HIDWORD(v12[0]), 0) != __PAIR64__(a4, result) )
  {
    usleep_range_state(1000, 1500, 2);
    if ( ((unsigned int)regmap_read(*a1, v10 | 0x80000u, (char *)v12 + 4) || HIDWORD(v12[0]) != a4)
      && ((usleep_range_state(1000, 1500, 2), (unsigned int)regmap_read(*a1, v10 | 0x80000u, (char *)v12 + 4))
       || HIDWORD(v12[0]) != a4)
      && ((usleep_range_state(1000, 1500, 2), (unsigned int)regmap_read(*a1, v10 | 0x80000u, (char *)v12 + 4))
       || HIDWORD(v12[0]) != a4)
      && ((usleep_range_state(1000, 1500, 2), (unsigned int)regmap_read(*a1, v10 | 0x80000u, (char *)v12 + 4))
       || HIDWORD(v12[0]) != a4) )
    {
      regmap_read(*a1, (a3 << 15) & 0x200000 | ((a3 & 0x3F) << 7) | v5 | 0x10u, v12);
      dev_err(
        a1[1],
        "simple amp ps%d request failed, func num %d act_ps %d, cs_valid:%d\n",
        a4,
        a5,
        HIDWORD(v12[0]),
        LODWORD(v12[0]));
      result = 4294967274LL;
    }
    else
    {
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
