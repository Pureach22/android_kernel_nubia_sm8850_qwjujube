__int64 __fastcall regulatory_hint_indoor(char a1, int a2)
{
  raw_spin_lock(&reg_indoor_lock);
  reg_is_indoor = a1;
  if ( (a1 & 1) != 0 )
  {
    if ( !reg_is_indoor_portid )
      reg_is_indoor_portid = a2;
    return raw_spin_unlock(&reg_indoor_lock);
  }
  else
  {
    reg_is_indoor_portid = 0;
    raw_spin_unlock(&reg_indoor_lock);
    return mod_delayed_work_on(32, system_power_efficient_wq, &reg_check_chans, 15000);
  }
}
