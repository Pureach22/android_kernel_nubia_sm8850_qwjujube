__int64 __fastcall cache_allocation_remove(__int64 a1)
{
  cancel_delayed_work_sync(*(_QWORD *)(a1 + 168) + 88LL);
  device_remove_file(a1 + 16, &dev_attr_enable_monitor);
  device_remove_file(a1 + 16, &dev_attr_sampling_time_ms);
  device_remove_file(a1 + 16, &dev_attr_freq_mon_thresh);
  device_remove_file(a1 + 16, &dev_attr_win_count_config);
  device_remove_file(a1 + 16, &dev_attr_bw_mon_ratio_thresh);
  device_remove_file(a1 + 16, &dev_attr_current_governor);
  return device_remove_file(a1 + 16, &dev_attr_available_governors);
}
