__int64 __fastcall devfreq_cdev_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 168);
  result = *(_QWORD *)(v1 + 128);
  if ( result )
  {
    thermal_cooling_device_unregister();
    return dev_pm_qos_remove_request(v1 + 48);
  }
  return result;
}
