__int64 __fastcall a5xx_spin_idle_debug(_QWORD *a1, const char *a2)
{
  int v3; // w20
  int v4; // w21
  int v5; // w22
  int v6; // w23
  int v7; // w24
  int v8; // w25

  dev_err(*a1, a2);
  v3 = kgsl_regmap_read(a1 + 1650);
  v4 = kgsl_regmap_read(a1 + 1650);
  v5 = kgsl_regmap_read(a1 + 1650);
  v6 = kgsl_regmap_read(a1 + 1650);
  v7 = kgsl_regmap_read(a1 + 1650);
  v8 = kgsl_regmap_read(a1 + 1650);
  dev_err(
    *a1,
    "rb=%d pos=%X/%X rbbm_status=%8.8X/%8.8X int_0_status=%8.8X\n",
    *(_DWORD *)(a1[2455] + 28LL),
    v3,
    v4,
    v5,
    v6,
    v7);
  dev_err(*a1, " hwfault=%8.8X\n", v8);
  return kgsl_device_snapshot(a1, 0, 0, 0);
}
