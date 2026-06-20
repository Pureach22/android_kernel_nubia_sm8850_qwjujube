__int64 __fastcall qcom_cc_probe(__int64 a1, _QWORD *a2)
{
  unsigned __int64 inited; // x2

  inited = devm_platform_ioremap_resource(a1, 0);
  if ( inited <= 0xFFFFFFFFFFFFF000LL )
    inited = _devm_regmap_init_mmio_clk(a1 + 16, 0, inited, *a2, 0, 0);
  if ( inited < 0xFFFFFFFFFFFFF001LL )
    LODWORD(inited) = qcom_cc_really_probe(a1 + 16, a2, inited);
  return (unsigned int)inited;
}
