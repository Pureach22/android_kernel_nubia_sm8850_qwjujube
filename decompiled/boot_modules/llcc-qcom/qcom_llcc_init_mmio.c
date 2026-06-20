unsigned __int64 __fastcall qcom_llcc_init_mmio(__int64 a1, unsigned __int8 a2, __int64 a3)
{
  unsigned __int64 inited; // x2
  _QWORD v8[41]; // [xsp+8h] [xbp-148h] BYREF

  v8[40] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v8[2], 0, 0x130u);
  HIDWORD(v8[3]) = 32;
  v8[1] = 0x400000020LL;
  BYTE1(v8[17]) = 1;
  inited = devm_platform_ioremap_resource(a1, a2);
  if ( inited <= 0xFFFFFFFFFFFFF000LL )
  {
    v8[0] = a3;
    inited = _devm_regmap_init_mmio_clk(a1 + 16, 0, inited, v8, 0, 0);
  }
  _ReadStatusReg(SP_EL0);
  return inited;
}
