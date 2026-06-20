__int64 __fastcall _clk_alpha_pll_update_latch(unsigned int *a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  __int64 result; // x0
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_QWORD *)a1 + 9);
  v3 = *a1;
  v5 = 0;
  regmap_read(v2, v3, &v5);
  regmap_update_bits_base(*((_QWORD *)a1 + 9), *a1, 0x400000, 0x400000, 0, 0, 0);
  _const_udelay(4295);
  if ( (v5 & 0x800000) != 0 )
  {
    result = wait_for_pll(a1, 0x20000000, 0, "update_ack_set");
    if ( (_DWORD)result )
      goto LABEL_8;
    regmap_update_bits_base(*((_QWORD *)a1 + 9), *a1, 0x400000, 0, 0, 0, 0);
  }
  else
  {
    result = wait_for_pll(a1, 0x400000, 1u, "update");
    if ( (_DWORD)result )
      goto LABEL_8;
  }
  result = wait_for_pll(a1, 0x20000000, 1u, "update_ack_clear");
  if ( !(_DWORD)result )
  {
    _const_udelay(42950);
    result = 0;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
