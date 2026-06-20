__int64 reg_check_channels()
{
  return mod_delayed_work_on(32, system_power_efficient_wq, &reg_check_chans, 15000);
}
