__int64 __fastcall wlan_dp_lb_compute_stats_average(__int64 a1, __int64 a2)
{
  unsigned int v2; // w21
  __int64 result; // x0
  __int64 v5; // x1
  __int64 v6; // x25
  __int64 v7; // x21
  __int64 v8; // x0
  char v9; // w8
  int v10; // w19
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x22
  _QWORD *v13; // x1
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x1
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  char v34; // w8
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x23
  __int64 v37; // x19
  char *v38; // x8
  __int64 v39; // x26
  __int64 v40; // x27
  __int64 v41; // x10
  __int64 v42; // x8
  unsigned __int64 v43; // x11
  unsigned __int64 v44; // x9
  unsigned __int64 v45; // x5
  __int64 v46; // x4
  __int64 v47; // x10
  __int64 v48; // x11
  unsigned __int64 v49; // x12
  unsigned __int64 v50; // x13
  unsigned __int64 v51; // x11
  __int64 **v52; // x0
  __int64 v53; // x8
  void (*v54)(void); // x8
  __int64 v55; // [xsp+28h] [xbp-218h] BYREF
  _QWORD v56[32]; // [xsp+30h] [xbp-210h] BYREF
  _QWORD v57[34]; // [xsp+130h] [xbp-110h] BYREF

  v2 = a2;
  v57[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = sched_clock(a1, a2);
  if ( *(_BYTE *)(a1 + 222) != 1 )
    goto LABEL_58;
  v6 = result;
  if ( v2 < 4 )
  {
    wlan_dp_lb_compute_stats_average_tput_level_high_count = 0;
    if ( (unsigned int)++wlan_dp_lb_compute_stats_average_tput_level_low_count >= 6 && (*(_BYTE *)(a1 + 2913) & 1) == 0 )
      result = wlan_dp_lb_set_default_affinity(a1);
  }
  else
  {
    wlan_dp_lb_compute_stats_average_tput_level_low_count = 0;
    ++wlan_dp_lb_compute_stats_average_tput_level_high_count;
  }
  v56[0] = 0;
  v7 = sched_clock(result, v5);
  v8 = *(_QWORD *)(a1 + 248);
  v55 = 0;
  result = hif_affinity_mgr_supported(v8);
  if ( (result & 1) == 0 )
    goto LABEL_27;
  v57[0] = qdf_walt_get_cpus_taken();
  if ( qdf_cpumask_empty(v57) )
  {
    if ( !qdf_cpumask_empty((_DWORD *)(a1 + 2864)) )
      qdf_cpumask_clear((_QWORD *)(a1 + 2864));
    result = qdf_cpumask_equal((_DWORD *)(a1 + 2848), (_DWORD *)(a1 + 2840));
    if ( (result & 1) != 0 )
      goto LABEL_27;
    qdf_cpumask_copy((_QWORD *)(a1 + 2848), (_QWORD *)(a1 + 2840));
  }
  else
  {
    result = qdf_cpumask_equal((_DWORD *)(a1 + 2864), v57);
    if ( (result & 1) != 0 || (unsigned __int64)(v7 - *(_QWORD *)(a1 + 2872)) >= 0x12A05F200LL )
      goto LABEL_27;
    qdf_cpumask_clear(v56);
    v9 = 0;
    v10 = 0;
    do
    {
      v11 = (unsigned int)(-1LL << v9) & _cpu_online_mask;
      if ( !(_DWORD)v11 )
        break;
      v12 = __clz(__rbit64(v11));
      if ( !(unsigned int)qdf_cpumask_test_cpu(v12, (__int64)&v55)
        && !(unsigned int)qdf_cpumask_test_cpu(v12, (__int64)v57) )
      {
        qdf_cpumask_set_cpu((unsigned int)v12, (__int64)v56);
        if ( v10 == 1 )
          break;
        v10 = 1;
      }
      v9 = v12 + 1;
    }
    while ( v12 < 0x1F );
    if ( qdf_cpumask_empty(v56) )
      v13 = v57;
    else
      v13 = v56;
    qdf_cpumask_copy((_QWORD *)(a1 + 2848), v13);
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: Audio taken cpus old:%*pbl new:%*pbl updated_cpumask:%*pbl",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_dp_lb_check_for_cpu_mask_change",
      nr_cpu_ids,
      a1 + 2848);
    qdf_cpumask_copy((_QWORD *)(a1 + 2864), v57);
    *(_QWORD *)(a1 + 2872) = v7;
  }
  qdf_cpumask_copy((_QWORD *)(a1 + 2856), (_QWORD *)(a1 + 2848));
  wlan_dp_lb_set_default_affinity(a1);
  result = wlan_dp_lb_handler(a1);
LABEL_27:
  v22 = *(_QWORD *)(a1 + 2896);
  if ( !v22 )
  {
    *(_QWORD *)(a1 + 2896) = v6;
    *(_QWORD *)(a1 + 2904) = v6;
    goto LABEL_58;
  }
  if ( (unsigned __int64)(v6 - v22) < 0x3B9ACA00 )
    goto LABEL_55;
  v23 = *(_QWORD *)(a1 + 248);
  memset(v57, 0, 256);
  memset(v56, 0, sizeof(v56));
  v24 = ((__int64 (__fastcall *)(__int64, _QWORD *, _QWORD *))hif_get_wlan_rx_time_stats)(v23, v57, v56);
  v34 = 0;
  do
  {
    v35 = (unsigned int)(-1LL << v34) & _cpu_online_mask;
    if ( !(_DWORD)v35 )
      break;
    v36 = __clz(__rbit64(v35));
    v37 = a1 + 1560 + 40LL * (unsigned int)v36;
    v38 = (char *)&kernel_cpustat + _per_cpu_offset[v36];
    v40 = *((_QWORD *)v38 + 3);
    v39 = *((_QWORD *)v38 + 4);
    v24 = sched_clock(v24, v25);
    v41 = *(_QWORD *)v37;
    v42 = v39 + v40;
    if ( *(_QWORD *)v37 - 1LL >= (unsigned __int64)(v39 + v40) )
    {
      if ( v36 > 0x1F )
LABEL_59:
        __break(1u);
      v44 = v57[v36];
    }
    else
    {
      if ( v36 > 0x1F )
        goto LABEL_59;
      v43 = *(_QWORD *)(v37 + 8);
      v44 = v57[v36];
      v45 = v44 - v43;
      if ( v44 >= v43 )
      {
        v46 = v42 - v41;
        if ( v45 > v42 - v41 )
        {
          v24 = qdf_trace_msg(
                  0x45u,
                  8u,
                  "%s: cpu_irq_time %llu wlan_irq_time %llu cpu %d",
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  "wlan_dp_lb_compute_cpu_load_average");
        }
        else
        {
          v47 = v56[v36];
          v48 = v47 - *(_QWORD *)(v37 + 16);
          v49 = v24 - *(_QWORD *)(v37 + 24);
          v50 = 100 * (v48 + v46) / v49;
          if ( *(_BYTE *)(v37 + 36) )
            v50 = 75 * v50 / 0x64 + ((unsigned __int64)*(unsigned __int8 *)(v37 + 36) >> 2);
          *(_BYTE *)(v37 + 36) = v50;
          v51 = 100 * (v48 + v45) / v49;
          if ( *(_BYTE *)(v37 + 37) )
            v51 = 75 * v51 / 0x64 + ((unsigned __int64)*(unsigned __int8 *)(v37 + 37) >> 2);
          *(_BYTE *)(v37 + 37) = v51;
          *(_QWORD *)v37 = v42;
          *(_QWORD *)(v37 + 8) = v44;
          *(_QWORD *)(v37 + 16) = v47;
          *(_QWORD *)(v37 + 24) = v24;
        }
        goto LABEL_31;
      }
    }
    *(_QWORD *)v37 = v42;
    *(_QWORD *)(v37 + 8) = v44;
    *(_DWORD *)(v37 + 32) = v36;
    *(_QWORD *)(v37 + 16) = v56[v36];
    *(_QWORD *)(v37 + 24) = v24;
LABEL_31:
    v34 = v36 + 1;
  }
  while ( v36 < 0x1F );
  v52 = *(__int64 ***)(a1 + 240);
  if ( v52 )
  {
    v53 = **v52;
    if ( v53 )
    {
      v54 = *(void (**)(void))(v53 + 952);
      if ( v54 )
      {
        if ( *((_DWORD *)v54 - 1) != -1106481425 )
          __break(0x8228u);
        v54();
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "cdp_calculate_per_ring_pkt_avg");
  }
  result = dp_fisa_calc_flow_stats_avg(a1);
  *(_QWORD *)(a1 + 2896) = v6;
LABEL_55:
  if ( (unsigned __int64)(v6 - *(_QWORD *)(a1 + 2904)) > 0x12A05F1FFLL
    && (unsigned int)wlan_dp_lb_compute_stats_average_tput_level_high_count >= 6 )
  {
    result = wlan_dp_lb_handler(a1);
  }
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return result;
}
