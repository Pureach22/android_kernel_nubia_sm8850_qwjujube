__int64 __fastcall qcom_cc_map(__int64 a1, _QWORD *a2)
{
  unsigned __int64 v4; // x2

  v4 = devm_platform_ioremap_resource(a1, 0);
  if ( v4 <= 0xFFFFFFFFFFFFF000LL )
    return _devm_regmap_init_mmio_clk(a1 + 16, 0, v4, *a2, 0, 0);
  return v4;
}
