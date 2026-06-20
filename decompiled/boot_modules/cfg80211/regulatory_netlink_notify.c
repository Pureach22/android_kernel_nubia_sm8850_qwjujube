__int64 __fastcall regulatory_netlink_notify(int a1)
{
  raw_spin_lock(&reg_indoor_lock);
  if ( reg_is_indoor_portid != a1 )
    return raw_spin_unlock(&reg_indoor_lock);
  reg_is_indoor = 0;
  reg_is_indoor_portid = 0;
  raw_spin_unlock(&reg_indoor_lock);
  return mod_delayed_work_on(32, system_power_efficient_wq, &reg_check_chans, 15000);
}
