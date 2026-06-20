__int64 __fastcall wlan_dp_load_balancer_init(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x19
  char v3; // w9
  int v4; // w22
  int v5; // w8
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x20
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( *(_BYTE *)(result + 222) == 1 )
  {
    v2 = result;
    hif_set_load_balance_enabled_flag(*(_QWORD *)(result + 248));
    *(_DWORD *)(v2 + 2880) = 0;
    *(_QWORD *)(v2 + 2888) = 0;
    if ( qdf_cpumask_empty((_DWORD *)(v2 + 2840)) )
    {
      v3 = 0;
      v4 = 0;
      v5 = _cpu_online_mask;
      do
      {
        v6 = (unsigned int)(-1LL << v3) & v5;
        if ( !(_DWORD)v6 )
          break;
        v7 = __clz(__rbit64(v6));
        if ( !cpu_topology[12 * (unsigned int)v7 + 2] )
        {
          qdf_cpumask_set_cpu((unsigned int)v7, v2 + 2840);
          if ( v4 > 0 )
            break;
          v5 = _cpu_online_mask;
          v4 = 1;
        }
        v3 = v7 + 1;
      }
      while ( v7 < 0x1F );
    }
    qdf_cpumask_copy((_QWORD *)(v2 + 2848), (_QWORD *)(v2 + 2840));
    qdf_cpumask_copy((_QWORD *)(v2 + 2856), (_QWORD *)(v2 + 2840));
    qdf_cpuhp_register(
      (_QWORD *)(v2 + 2928),
      v2,
      (__int64)wlan_dp_lb_cpu_online_cb,
      (__int64)wlan_dp_lb_cpu_before_offline_cb);
    return qdf_trace_msg(
             0x45u,
             5u,
             "%s: default cpus for load balance: %*pbl",
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             "wlan_dp_load_balancer_init",
             nr_cpu_ids,
             v2 + 2840);
  }
  return result;
}
