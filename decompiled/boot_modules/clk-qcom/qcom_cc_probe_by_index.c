__int64 __fastcall qcom_cc_probe_by_index(__int64 a1, __int64 a2, _QWORD *a3)
{
  unsigned __int64 v5; // x0
  unsigned __int64 inited; // x2

  v5 = devm_platform_ioremap_resource(a1, a2);
  if ( v5 <= 0xFFFFFFFFFFFFF000LL )
  {
    inited = _devm_regmap_init_mmio_clk(a1 + 16, 0, v5, *a3, 0, 0);
    if ( inited < 0xFFFFFFFFFFFFF001LL )
      LODWORD(inited) = qcom_cc_really_probe(a1 + 16, a3, inited);
  }
  else
  {
    LODWORD(inited) = -12;
  }
  return (unsigned int)inited;
}
