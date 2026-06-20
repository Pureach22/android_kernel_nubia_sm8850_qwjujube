__int64 __fastcall wlan_hdd_pm_qos_add_request(
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
  __int64 result; // x0
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x22
  __int64 cpu_device; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  char v23; // w8
  unsigned __int64 v29; // x8
  unsigned __int64 v31; // x8
  unsigned __int64 v33; // x8
  unsigned __int64 v35; // x8

  if ( !a1 )
    return qdf_trace_msg(
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
             "wlan_hdd_pm_qos_add_request");
  _X19 = (unsigned __int64 *)(a1 + 6792);
  result = (__int64)qdf_cpumask_clear((_QWORD *)(a1 + 6792));
  __asm { PRFM            #0x11, [X19] }
  do
    v29 = __ldxr(_X19);
  while ( __stxr(v29 | 1, _X19) );
  __asm { PRFM            #0x11, [X19] }
  do
    v31 = __ldxr(_X19);
  while ( __stxr(v31 | 2, _X19) );
  __asm { PRFM            #0x11, [X19] }
  do
    v33 = __ldxr(_X19);
  while ( __stxr(v33 | 4, _X19) );
  __asm { PRFM            #0x11, [X19] }
  do
    v35 = __ldxr(_X19);
  while ( __stxr(v35 | 8, _X19) );
  v23 = 0;
  do
  {
    v12 = (unsigned int)(-1LL << v23) & _cpu_present_mask;
    if ( !(_DWORD)v12 )
      break;
    v13 = __clz(__rbit64(v12));
    cpu_device = get_cpu_device((unsigned int)v13);
    dev_pm_qos_add_request(cpu_device, a1 + 4232 + 80LL * (unsigned int)v13, 1, 2000000000);
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: Set qos_cpu_mask %*pb for affine_cores",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               "hdd_pm_qos_add_request",
               nr_cpu_ids,
               _X19);
    v23 = v13 + 1;
  }
  while ( v13 < 0x1F );
  return result;
}
