__int64 __fastcall wcd_usbss_regmap_init(__int64 a1, __int64 a2)
{
  return _devm_regmap_init(a1, &regmap_bus_config, a1, a2, 0, 0);
}
