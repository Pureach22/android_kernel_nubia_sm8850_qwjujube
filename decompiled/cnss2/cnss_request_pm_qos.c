__int64 __fastcall cnss_request_pm_qos(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  __int64 result; // x0

  v2 = a2;
  result = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( result )
    return cpu_latency_qos_add_request(result + 456, v2);
  return result;
}
