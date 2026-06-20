__int64 __fastcall qcom_soc_wdt_probe(__int64 a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x20
  __int64 resource_byname; // x0
  __int64 v5; // x0

  v2 = devm_kmalloc(a1 + 16, 1008, 3520);
  if ( !v2 )
    return 4294967284LL;
  v3 = (_QWORD *)v2;
  resource_byname = platform_get_resource_byname(a1, 512, "wdt-base");
  if ( !resource_byname )
    return 4294967277LL;
  v5 = devm_ioremap_resource(a1 + 16, resource_byname);
  *v3 = v5;
  if ( v5 )
  {
    v3[2] = &qcom_soc_wdt_ops;
    return qcom_wdt_register(a1, v3, "msm-watchdog");
  }
  else
  {
    dev_err(a1 + 16, "%s cannot map wdog register space\n", "qcom_soc_wdt_probe");
    return 4294967290LL;
  }
}
