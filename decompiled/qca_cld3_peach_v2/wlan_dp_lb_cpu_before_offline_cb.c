__int64 __fastcall wlan_dp_lb_cpu_before_offline_cb(__int64 a1, __int64 a2)
{
  return wlan_dp_lb_cpu_hotplug_notify(a1, a2, 0);
}
