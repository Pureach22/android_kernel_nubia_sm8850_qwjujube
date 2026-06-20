__int64 __fastcall gic_intr_routing_probe(__int64 a1)
{
  __int64 dir; // x0
  int v3; // w0
  int v4; // w21
  __int64 property; // x20
  unsigned int i; // w22
  __int64 result; // x0
  void *v8; // x0
  unsigned __int64 v15; // x10
  __int64 v16; // x0
  unsigned int v17; // w0
  unsigned int v18; // w24
  int v19; // w0
  int v20; // w21
  unsigned int j; // w22
  unsigned __int64 v24; // x10
  __int64 v25; // x0
  unsigned int v26; // w0
  unsigned int v27; // w24
  int v28; // w19
  __int64 v29; // [xsp+8h] [xbp-58h] BYREF
  __int64 v30; // [xsp+10h] [xbp-50h]
  __int64 v31; // [xsp+18h] [xbp-48h]
  __int64 v32; // [xsp+20h] [xbp-40h]
  __int64 v33; // [xsp+28h] [xbp-38h]
  __int64 v34; // [xsp+30h] [xbp-30h]
  __int64 v35; // [xsp+38h] [xbp-28h]
  __int64 v36; // [xsp+40h] [xbp-20h]
  __int64 v37; // [xsp+48h] [xbp-18h]
  __int64 v38; // [xsp+50h] [xbp-10h]
  __int64 v39; // [xsp+58h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dir = debugfs_create_dir("gic_intr_routing", 0);
  debugfs_dir = dir;
  if ( !dir )
    goto LABEL_6;
  if ( (unsigned __int64)debugfs_create_file("cpu_select", 384, dir, *(_QWORD *)(a1 + 760), &cpu_select_fops) >= 0xFFFFFFFFFFFFF001LL )
  {
    debugfs_remove(debugfs_dir);
LABEL_6:
    printk(&unk_806F, "gic_intr_routing_probe");
    result = 4294967284LL;
    goto LABEL_31;
  }
  v3 = of_count_phandle_with_args(*(_QWORD *)(a1 + 760), "qcom,gic-class0-cpus", 0);
  if ( v3 <= 0 )
  {
    v8 = &unk_80D3;
LABEL_19:
    printk(v8, "gic_intr_routing_probe");
    result = 4294967274LL;
    goto LABEL_31;
  }
  v4 = v3;
  property = of_find_property(*(_QWORD *)(a1 + 760), "qcom,gic-runtime-cpu-class-en", 0);
  for ( i = 0; i != v4; ++i )
  {
    v16 = *(_QWORD *)(a1 + 760);
    v37 = 0;
    v38 = 0;
    v35 = 0;
    v36 = 0;
    v33 = 0;
    v34 = 0;
    v31 = 0;
    v32 = 0;
    v29 = 0;
    v30 = 0;
    if ( !(unsigned int)_of_parse_phandle_with_args(v16, "qcom,gic-class0-cpus", 0, 0, i, &v29) )
    {
      if ( v29 )
      {
        v17 = of_cpu_node_to_id();
        if ( (v17 & 0x80000000) == 0 )
        {
          v18 = v17;
          if ( property )
          {
            result = process_cpu_index(*(_QWORD *)(a1 + 760), v17, 0);
            if ( (result & 0x80000000) != 0 )
              goto LABEL_31;
          }
          _X9 = (unsigned __int64 *)&gic_routing_data[(v18 >> 6) + 1];
          __asm { PRFM            #0x11, [X9] }
          do
            v15 = __ldxr(_X9);
          while ( __stxr(v15 | (1LL << v18), _X9) );
        }
      }
    }
  }
  v19 = of_count_phandle_with_args(*(_QWORD *)(a1 + 760), "qcom,gic-class1-cpus", 0);
  if ( v19 < 1 )
  {
    v8 = &unk_81E3;
    goto LABEL_19;
  }
  v20 = v19;
  for ( j = 0; j != v20; ++j )
  {
    v25 = *(_QWORD *)(a1 + 760);
    v37 = 0;
    v38 = 0;
    v35 = 0;
    v36 = 0;
    v33 = 0;
    v34 = 0;
    v31 = 0;
    v32 = 0;
    v29 = 0;
    v30 = 0;
    if ( !(unsigned int)_of_parse_phandle_with_args(v25, "qcom,gic-class1-cpus", 0, 0, j, &v29) )
    {
      if ( v29 )
      {
        v26 = of_cpu_node_to_id();
        if ( (v26 & 0x80000000) == 0 )
        {
          v27 = v26;
          if ( property )
          {
            result = process_cpu_index(*(_QWORD *)(a1 + 760), v26, 1);
            if ( (result & 0x80000000) != 0 )
              goto LABEL_31;
          }
          _X9 = (unsigned __int64 *)&gic_routing_data[(v27 >> 6) + 2];
          __asm { PRFM            #0x11, [X9] }
          do
            v24 = __ldxr(_X9);
          while ( __stxr(v24 | (1LL << v27), _X9) );
        }
      }
    }
  }
  android_rvh_probe_register(&_tracepoint_android_rvh_gic_v3_set_affinity, trace_gic_v3_set_affinity, 0);
  tracepoint_probe_register(&_tracepoint_irq_handler_entry, gic_irq_handler_entry_notifer, 0);
  v28 = _cpuhp_setup_state(
          193,
          "qcom/gic_affinity_setting:online",
          1,
          gic_affinity_cpu_online,
          gic_affinity_cpu_offline,
          0);
  if ( v28 < 0 )
  {
    _cpuhp_remove_state(193, 1);
    printk(&unk_838A, "gic_intr_routing_probe");
  }
  dword_7B48 = v28;
  printk(&unk_83DE, "gic_intr_routing_probe");
  result = 0;
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
