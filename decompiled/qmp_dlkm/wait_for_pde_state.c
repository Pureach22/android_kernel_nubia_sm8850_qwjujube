__int64 __fastcall wait_for_pde_state(_QWORD *a1, unsigned int a2, int a3)
{
  unsigned int v6; // w22
  __int64 result; // x0
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v6 = ((a3 & 7) << 22) | 0x40080100;
  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  usleep_range_state(1000, 1500, 2);
  result = regmap_read(*a1, v6, (char *)v8 + 4);
  if ( __PAIR64__(HIDWORD(v8[0]), 0) != __PAIR64__(a2, result) )
  {
    usleep_range_state(1000, 1500, 2);
    if ( ((unsigned int)regmap_read(*a1, v6, (char *)v8 + 4) || HIDWORD(v8[0]) != a2)
      && ((usleep_range_state(1000, 1500, 2), (unsigned int)regmap_read(*a1, v6, (char *)v8 + 4)) || HIDWORD(v8[0]) != a2)
      && ((usleep_range_state(1000, 1500, 2), (unsigned int)regmap_read(*a1, v6, (char *)v8 + 4)) || HIDWORD(v8[0]) != a2)
      && ((usleep_range_state(1000, 1500, 2), (unsigned int)regmap_read(*a1, v6, (char *)v8 + 4)) || HIDWORD(v8[0]) != a2) )
    {
      regmap_read(*a1, ((a3 & 7) << 22) | 0x40000190u, v8);
      dev_err(
        a1[1],
        "qmp ps%d request failed, func num %d act_ps %d, cs_valid:%d\n",
        a2,
        a3,
        HIDWORD(v8[0]),
        LODWORD(v8[0]));
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
