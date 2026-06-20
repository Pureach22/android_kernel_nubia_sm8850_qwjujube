void bcl_evaluate_soc()
{
  __int64 v0; // x0
  unsigned int property; // w0
  int v2; // w20
  __int64 v3; // x8
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(bcl_perph + 136) )
  {
    v4[0] = 0;
    v0 = bcl_read_soc_batt_psy;
    if ( bcl_read_soc_batt_psy || (v0 = power_supply_get_by_name("battery"), (bcl_read_soc_batt_psy = v0) != 0) )
    {
      property = power_supply_get_property(v0, 47, v4);
      if ( property )
      {
        printk(&unk_66E8, "bcl_soc", "bcl_read_soc", property);
        goto LABEL_10;
      }
      v2 = 100 - LODWORD(v4[0]);
    }
    else
    {
      v2 = 0;
    }
    mutex_lock(bcl_perph + 80);
    v3 = bcl_perph;
    if ( *(_BYTE *)(bcl_perph + 128) == 1 && *(_QWORD *)(bcl_perph + 64) <= v2 )
    {
      *(_DWORD *)(bcl_perph + 72) = v2;
      mutex_unlock(v3 + 80);
      thermal_zone_device_update(*(_QWORD *)(bcl_perph + 136), 2);
    }
    else
    {
      mutex_unlock(bcl_perph + 80);
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
}
