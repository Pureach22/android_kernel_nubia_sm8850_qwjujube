__int64 __fastcall kgsl_pwrctrl_close(_QWORD *a1)
{
  unsigned __int64 v1; // x8
  unsigned __int64 v3; // x0
  __int64 v4; // x0
  _QWORD *v5; // x20
  __int64 result; // x0

  v1 = a1[1320];
  a1[1141] = 0;
  if ( v1 <= 0xFFFFFFFFFFFFF000LL )
  {
    dev_pm_qos_remove_request(a1 + 1321);
    dev_pm_qos_remove_notifier(a1[1396] + 16LL, a1 + 1364, 4);
    thermal_cooling_device_unregister(a1[1320]);
  }
  v3 = a1[1370];
  if ( v3 && v3 <= 0xFFFFFFFFFFFFF000LL )
    kthread_destroy_worker(v3);
  if ( a1[1318] )
    dev_pm_qos_remove_request(a1 + 1309);
  _pm_runtime_disable(a1[1396] + 16LL, 1);
  v4 = a1[1128];
  if ( v4 && v4 != a1[1127] )
    dev_pm_domain_detach(v4, 0);
  v5 = a1 + 1127;
  if ( a1[1127] )
  {
    dev_pm_genpd_remove_notifier();
    dev_pm_domain_detach(*v5, 0);
  }
  result = a1[1129];
  if ( result )
    result = dev_pm_domain_detach(result, 0);
  a1[1128] = 0;
  a1[1129] = 0;
  *v5 = 0;
  return result;
}
