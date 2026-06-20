_QWORD *__fastcall wlan_hdd_pm_qos_remove_request(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  char v10; // w8
  __int64 v11; // x25
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x22
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  if ( !a1 )
    return (_QWORD *)qdf_trace_msg(
                       0x33u,
                       2u,
                       "%s: hdd_ctx is null",
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       "wlan_hdd_pm_qos_remove_request");
  v10 = 0;
  v11 = a1 + 4208;
  do
  {
    v12 = (unsigned int)(-1LL << v10) & _cpu_present_mask;
    if ( !(_DWORD)v12 )
      break;
    v13 = __clz(__rbit64(v12));
    dev_pm_qos_remove_request(v11 + 80LL * (unsigned int)v13);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Remove dev_pm_qos_request for all cpus: %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "hdd_pm_qos_remove_request",
      (unsigned int)v13);
    v10 = v13 + 1;
  }
  while ( v13 < 0x1F );
  return qdf_cpumask_clear((_QWORD *)(a1 + 6768));
}
