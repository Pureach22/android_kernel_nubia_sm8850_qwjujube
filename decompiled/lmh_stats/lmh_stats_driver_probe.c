__int64 __fastcall lmh_stats_driver_probe(__int64 a1)
{
  __int64 driver_data; // x21
  __int64 v3; // x0
  __int64 v4; // x19
  __int64 v5; // x0
  int v6; // w0
  unsigned __int64 v7; // x8
  __int64 v8; // x24
  unsigned __int64 v9; // x23
  __int64 cpu_device; // x0
  __int64 v11; // x24
  __int64 result; // x0
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x22
  __int64 v16; // x8
  unsigned int v17; // w25
  int *v18; // x8
  int v19; // w9
  int v20; // t1
  __int64 v21; // x0
  __int64 v22; // x8
  unsigned int v23; // w0
  __int64 v24; // x23
  unsigned int matched; // w0
  int v26; // w8
  unsigned int (*v27)(void); // x8
  unsigned int v28; // w20
  __int64 v29; // x8
  unsigned int v30; // w19
  __int64 v31; // [xsp+8h] [xbp-58h] BYREF
  __int64 v32; // [xsp+10h] [xbp-50h]
  __int64 v33; // [xsp+18h] [xbp-48h]
  __int64 v34; // [xsp+20h] [xbp-40h]
  __int64 v35; // [xsp+28h] [xbp-38h]
  __int64 v36; // [xsp+30h] [xbp-30h]
  __int64 v37; // [xsp+38h] [xbp-28h]
  __int64 v38; // [xsp+40h] [xbp-20h]
  __int64 v39; // [xsp+48h] [xbp-18h]
  __int64 v40; // [xsp+50h] [xbp-10h]
  __int64 v41; // [xsp+58h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  driver_data = cpufreq_get_driver_data();
  v3 = devm_kmalloc(a1 + 16, 184, 3520);
  if ( !v3 )
  {
    result = 4294967284LL;
    goto LABEL_34;
  }
  v4 = v3;
  v5 = *(_QWORD *)(a1 + 760);
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v6 = _of_parse_phandle_with_args(v5, "qcom,cpu", 0, 0, 0, &v31);
  v7 = _cpu_possible_mask;
  if ( v6 )
    v8 = 0;
  else
    v8 = v31;
  if ( _cpu_possible_mask )
  {
    while ( 1 )
    {
      v9 = __clz(__rbit64(v7));
      cpu_device = get_cpu_device((unsigned int)v9);
      if ( cpu_device )
      {
        if ( *(_QWORD *)(cpu_device + 744) == v8 )
          break;
      }
      if ( v9 < 0x1F )
      {
        v7 = (unsigned int)(-2LL << v9) & _cpu_possible_mask;
        if ( ((unsigned int)(-2LL << v9) & _cpu_possible_mask) != 0 )
          continue;
      }
      v11 = cpu_device;
      goto LABEL_13;
    }
    v11 = cpu_device;
  }
  else
  {
    v11 = 0;
LABEL_13:
    LODWORD(v9) = 32;
  }
  v13 = cpufreq_cpu_get((unsigned int)v9);
  if ( v13 )
  {
    *(_QWORD *)(v4 + 120) = v13;
    v15 = v13;
    v16 = *(_QWORD *)(v13 + 384);
    if ( !v16 )
      goto LABEL_35;
    v17 = 0;
    v18 = (int *)(v16 + 8);
    while ( 1 )
    {
      do
      {
        v20 = *v18;
        v18 += 3;
        v19 = v20;
      }
      while ( v20 == -1 );
      if ( v19 == -2 )
        break;
      ++v17;
    }
    if ( v17 && (v21 = devm_kmalloc(a1 + 16, 16 * v17, 3520), (*(_QWORD *)(v4 + 128) = v21) != 0) )
    {
      v22 = v21 + 8LL * v17;
      *(_DWORD *)(v4 + 160) = v17;
      *(_QWORD *)(v4 + 136) = v22;
      *(_QWORD *)(v4 + 144) = v22 + 4LL * v17;
      kobject_init(v4, &lmh_ktype);
      v23 = kobject_add(v4, kernel_kobj, "lmh_stats_%d", v9);
      if ( !v23 )
      {
        v24 = *(_QWORD *)(v11 + 744);
        v39 = 0;
        v40 = 0;
        v37 = 0;
        v38 = 0;
        v35 = 0;
        v36 = 0;
        v33 = 0;
        v34 = 0;
        v31 = 0;
        v32 = 0;
        if ( (unsigned int)_of_parse_phandle_with_args(v24, "clocks", "#clock-cells", 0xFFFFFFFFLL, 0, &v31)
          && ((matched = of_property_match_string(v24, "power-domain-names", "perf"), (matched & 0x80000000) != 0)
           || (unsigned int)_of_parse_phandle_with_args(
                              v24,
                              "power-domains",
                              "#power-domain-cells",
                              0xFFFFFFFFLL,
                              matched,
                              &v31)) )
        {
          v26 = -22;
        }
        else
        {
          v26 = HIDWORD(v32);
        }
        *(_DWORD *)(v4 + 176) = v26;
        *(_QWORD *)(v4 + 96) = lmh_scmi_limit_notify_cb;
        v27 = *(unsigned int (**)(void))(*(_QWORD *)(*(_QWORD *)(driver_data + 928) + 48LL) + 16LL);
        if ( *((_DWORD *)v27 - 1) != -1725305667 )
          __break(0x8228u);
        if ( v27() )
          printk(&unk_6E64, *(unsigned int *)(v4 + 176));
        cpufreq_cpu_put(v15);
        result = 0;
        *(_QWORD *)(a1 + 168) = v4;
        goto LABEL_34;
      }
      v28 = v23;
      kobject_put(v4);
      printk(&unk_6EF4, (unsigned int)v9);
      result = v28;
    }
    else
    {
LABEL_35:
      printk(&unk_6F2E, v14);
      result = 4294967284LL;
    }
  }
  else
  {
    printk(&unk_6DD0, (unsigned int)v9);
    result = 4294966779LL;
  }
  v29 = *(_QWORD *)(v4 + 120);
  if ( v29 )
  {
    v30 = result;
    cpufreq_cpu_put(v29);
    result = v30;
  }
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
