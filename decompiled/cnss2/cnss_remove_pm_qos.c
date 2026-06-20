__int64 __fastcall cnss_remove_pm_qos(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( result )
    return cpu_latency_qos_remove_request(result + 456);
  return result;
}
