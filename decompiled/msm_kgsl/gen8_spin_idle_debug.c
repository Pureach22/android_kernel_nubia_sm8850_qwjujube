__int64 __fastcall gen8_spin_idle_debug(_QWORD *a1, const char *a2)
{
  int v3; // w20
  int v4; // w21
  int v5; // w22
  int v6; // w23
  int v7; // w0
  __int64 v8; // x9
  int v9; // w2

  dev_err(*a1, a2);
  v3 = kgsl_regmap_read(a1 + 1650);
  v4 = kgsl_regmap_read(a1 + 1650);
  v5 = kgsl_regmap_read(a1 + 1650);
  v6 = kgsl_regmap_read(a1 + 1650);
  v7 = kgsl_regmap_read(a1 + 1650);
  v8 = a1[2455];
  if ( v8 )
    v9 = *(_DWORD *)(v8 + 28);
  else
    v9 = -1;
  dev_err(*a1, "rb=%d pos=%X/%X rbbm_status=%8.8X int_0_status=%8.8X global_status=%8.8X\n", v9, v3, v4, v5, v6, v7);
  return kgsl_device_snapshot(a1, 0, 0, 0);
}
