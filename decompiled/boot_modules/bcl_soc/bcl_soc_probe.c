__int64 __fastcall bcl_soc_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x0
  _QWORD *v4; // x0
  unsigned int v5; // w0
  unsigned __int64 v6; // x0
  __int64 v8; // x8
  unsigned int v9; // w19

  v1 = a1 + 16;
  v3 = devm_kmalloc(a1 + 16, 232, 3520);
  bcl_perph = v3;
  if ( !v3 )
    return 4294967284LL;
  _mutex_init(v3 + 80, "&bcl_perph->state_trans_lock", &bcl_soc_probe___key);
  v4 = (_QWORD *)bcl_perph;
  *(_QWORD *)(bcl_perph + 152) = bcl_read_soc;
  v4[20] = bcl_set_soc;
  v4[25] = bcl_soc_get_trend;
  v4[21] = qti_tz_change_mode;
  v4[4] = 0xFFFFFFFE00000LL;
  *v4 = v1;
  v4[5] = v4 + 5;
  v4[6] = v4 + 5;
  v4[7] = bcl_evaluate_soc;
  v4[1] = battery_supply_callback;
  v5 = power_supply_reg_notifier(v4 + 1);
  if ( (v5 & 0x80000000) != 0 )
  {
    printk(&unk_672F, "bcl_soc", "bcl_soc_probe", v5);
    v8 = bcl_perph;
    v9 = -517;
  }
  else
  {
    v6 = devm_thermal_of_zone_register(v1, 0, bcl_perph, bcl_perph + 144);
    *(_QWORD *)(bcl_perph + 136) = v6;
    if ( v6 < 0xFFFFFFFFFFFFF001LL )
    {
      thermal_zone_device_update(v6, 5);
      queue_work_on(32, system_wq, bcl_perph + 32);
      *(_QWORD *)(a1 + 168) = bcl_perph;
      return 0;
    }
    printk(&unk_678A, "bcl_soc", "bcl_soc_probe", v6);
    v8 = bcl_perph;
    v9 = *(_DWORD *)(bcl_perph + 136);
    *(_QWORD *)(bcl_perph + 136) = 0;
  }
  power_supply_unreg_notifier(v8 + 8);
  flush_work(bcl_perph + 32);
  return v9;
}
