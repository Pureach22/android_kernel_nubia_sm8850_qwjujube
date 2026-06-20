__int64 __fastcall qcom_pcie_pdc_probe(__int64 a1)
{
  pcie_pdc_base = devm_platform_ioremap_resource(a1, 0);
  if ( !pcie_pdc_base )
    return 4294967290LL;
  d = of_device_get_match_data(a1 + 16);
  if ( d )
    return 0;
  else
    return 4294967274LL;
}
