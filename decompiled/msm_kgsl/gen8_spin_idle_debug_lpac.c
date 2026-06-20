__int64 __fastcall gen8_spin_idle_debug_lpac(_QWORD *a1)
{
  __int64 v2; // x24
  unsigned int v3; // w20
  unsigned int v4; // w21
  unsigned int v5; // w22
  unsigned int v6; // w23
  __int64 v7; // x7
  __int64 v8; // x2

  v2 = a1[1780];
  dev_err(*a1, "LPAC CP initialization failed to idle\n");
  v3 = kgsl_regmap_read(a1 + 1650);
  v4 = kgsl_regmap_read(a1 + 1650);
  v5 = kgsl_regmap_read(a1 + 1650);
  v6 = kgsl_regmap_read(a1 + 1650);
  v7 = (unsigned int)kgsl_regmap_read(a1 + 1650);
  if ( (v2 & 0x200) != 0 )
    v8 = 4;
  else
    v8 = 1;
  dev_err(
    *a1,
    "LPAC rb=%d pos=%X/%X rbbm_status=%8.8X int_0_status=%8.8X global_status=%8.8X\n",
    v8,
    v3,
    v4,
    v5,
    v6,
    v7);
  return kgsl_device_snapshot(a1, 0, 0, 0);
}
