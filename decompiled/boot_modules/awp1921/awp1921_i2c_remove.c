__int64 awp1921_i2c_remove()
{
  cancel_delayed_work_sync(mAWP1921 + 2096);
  remove_proc_entry("icid", micro_pump_proc_entry);
  remove_proc_entry("enable", micro_pump_proc_entry);
  remove_proc_entry("speed", micro_pump_proc_entry);
  remove_proc_entry("freq", micro_pump_proc_entry);
  remove_proc_entry("reg", micro_pump_proc_entry);
  return remove_proc_entry("driver/micropump", 0);
}
