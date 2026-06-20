__int64 __fastcall wlan_dp_lb_cpu_hotplug_notify(__int64 a1, unsigned int a2, char a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w8
  char v16; // w8
  int v17; // w22
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x21
  __int64 v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // [xsp+0h] [xbp-40h]
  __int64 v38; // [xsp+18h] [xbp-28h]
  __int64 v39; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v40[2]; // [xsp+30h] [xbp-10h] BYREF

  v40[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _qdf_op_protect();
  if ( !(_DWORD)result )
  {
    v15 = *(unsigned __int8 *)(a1 + 2914);
    v40[0] = 0;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: cpu %u cpu_up %d LB_CPU_masks [cur:%*pbl preferred:%*pbl] preferred_mask_change_by_cpuhp %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wlan_dp_lb_update_cpu_mask",
      a2,
      a3 & 1,
      nr_cpu_ids,
      a1 + 2848,
      v15,
      v38,
      0,
      0);
    if ( (a3 & 1) != 0 )
    {
      if ( (unsigned int)qdf_cpumask_test_cpu(a2, a1 + 2848) )
      {
        qdf_cpumask_set_cpu(a2, a1 + 2856);
      }
      else
      {
        if ( !(unsigned int)qdf_cpumask_test_cpu(a2, a1 + 2840) || *(_BYTE *)(a1 + 2914) != 1 )
          goto LABEL_18;
        qdf_cpumask_copy((_QWORD *)(a1 + 2848), (_QWORD *)(a1 + 2840));
        qdf_cpumask_clear((_QWORD *)(a1 + 2856));
        qdf_cpumask_set_cpu(a2, a1 + 2856);
        *(_BYTE *)(a1 + 2914) = 0;
      }
    }
    else
    {
      qdf_cpumask_clear_cpu(a2, a1 + 2856);
      if ( qdf_cpumask_empty((_DWORD *)(a1 + 2856)) )
      {
        qdf_cpumask_set_cpu(a2, (__int64)&v39);
        qdf_cpumask_clear(v40);
        v16 = 0;
        v17 = 0;
        do
        {
          v18 = (unsigned int)(-1LL << v16) & _cpu_online_mask;
          if ( !(_DWORD)v18 )
            break;
          v19 = __clz(__rbit64(v18));
          if ( !(unsigned int)qdf_cpumask_test_cpu(v19, (__int64)&v39)
            && !(unsigned int)qdf_cpumask_test_cpu(v19, a1 + 2864) )
          {
            qdf_cpumask_set_cpu((unsigned int)v19, (__int64)v40);
            if ( v17 == 1 )
              break;
            v17 = 1;
          }
          v16 = v19 + 1;
        }
        while ( v19 < 0x1F );
        v20 = *(unsigned int *)(a1 + 2840);
        if ( (v20 & *(_QWORD *)(a1 + 2848)) != 0 && (v40[0] & v20) == 0 )
          *(_BYTE *)(a1 + 2914) = 1;
        qdf_cpumask_copy((_QWORD *)(a1 + 2848), v40);
        qdf_cpumask_copy((_QWORD *)(a1 + 2856), (_QWORD *)(a1 + 2848));
      }
    }
    wlan_dp_lb_set_default_affinity(a1);
    wlan_dp_lb_handler(a1, v21, v22, v23, v24, v25, v26, v27, v28);
    LODWORD(v37) = *(unsigned __int8 *)(a1 + 2914);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Updated LB_CPU_masks [cur:%*pbl preferred:%*pbl] preferred_mask_change_by_cpuhp %d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wlan_dp_lb_update_cpu_mask",
      nr_cpu_ids,
      a1 + 2856,
      nr_cpu_ids,
      a1 + 2848,
      v37);
LABEL_18:
    result = _qdf_op_unprotect();
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
