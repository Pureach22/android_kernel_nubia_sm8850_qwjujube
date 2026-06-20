__int64 __fastcall qvadj_probe(__int64 a1)
{
  __int64 regmap; // x0
  __int64 v3; // x20
  __int64 dir; // x21
  __int64 v5; // x0

  pd = devm_kmalloc(a1 + 16, 64, 3520);
  if ( !pd )
    return 4294967284LL;
  regmap = dev_get_regmap(*(_QWORD *)(a1 + 112), 0);
  if ( !regmap )
    return 4294967277LL;
  v3 = regmap;
  dir = debugfs_create_dir("qcom_voltage_adj", 0);
  debugfs_create_file("get_overrides", 256, dir, 0, &qvadj_get_overrides_fops);
  debugfs_create_file("set_overrides", 384, dir, 0, &qvadj_set_overrides_fops);
  v5 = pd;
  *(_QWORD *)(pd + 48) = v3;
  *(_QWORD *)(v5 + 56) = dir;
  _mutex_init();
  *(_QWORD *)(a1 + 168) = pd;
  return 0;
}
