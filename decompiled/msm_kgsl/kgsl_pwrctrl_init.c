__int64 __fastcall kgsl_pwrctrl_init(_QWORD *a1)
{
  unsigned __int64 v1; // x27
  __int64 v2; // x20
  __int64 property; // x21
  __int64 string; // x0
  const char *v6; // x22
  _QWORD *v7; // x26
  unsigned __int64 v8; // x0
  __int64 inited; // x0
  unsigned __int64 v10; // x21
  __int64 v11; // x23
  _QWORD *v12; // x22
  unsigned __int64 v13; // x8
  __int64 v14; // x1
  unsigned int v15; // w8
  int v16; // w21
  __int64 v17; // x8
  __int64 v18; // x1
  __int64 v19; // x8
  unsigned int v20; // w21
  __int64 v21; // x0
  const char *v22; // x22
  int v23; // w0
  unsigned __int64 v24; // x0
  __int64 v25; // x0
  unsigned int v26; // w21
  __int64 v27; // x0
  int v28; // w0
  int v29; // w0
  unsigned __int64 worker; // x0
  __int64 v31; // x21
  int v32; // w0
  unsigned __int64 v33; // x0
  unsigned int v35; // w20
  unsigned int v36; // w23
  int v37; // w21
  unsigned __int64 v38; // x8

  v2 = a1[1396];
  *((_DWORD *)a1 + 2280) = 0;
  property = of_find_property(*(_QWORD *)(v2 + 760), "clock-names", 0);
  string = of_prop_next_string(property, 0);
  if ( string )
  {
    v6 = (const char *)string;
    v7 = a1 + 1105;
    while ( 1 )
    {
      v1 = 0;
      while ( v7[v1] || strcmp(clocks[v1], v6) || !strcmp(v6, "apb_pclk") )
      {
        if ( ++v1 == 19 )
          goto LABEL_3;
      }
      v8 = devm_clk_get(v2 + 16, v6);
      v7[v1] = v8;
      if ( v8 > 0xFFFFFFFFFFFFF000LL )
        break;
      if ( !strcmp(v6, "isense_clk") )
        *((_DWORD *)a1 + 2280) = v1;
LABEL_3:
      v6 = (const char *)of_prop_next_string(property, v6);
      if ( !v6 )
        goto LABEL_12;
    }
    v26 = v8;
    dev_err(v2 + 16, "Couldn't get clock: %s (%d)\n", v6, v8);
    v7[v1] = 0;
    return v26;
  }
LABEL_12:
  if ( *((_DWORD *)a1 + 2280)
    && (of_property_read_variable_u32_array(*(_QWORD *)(v2 + 760), "qcom,isense-clk-on-level", (char *)a1 + 9124, 1, 0)
      & 0x80000000) != 0 )
  {
    dev_err(v2 + 16, "Couldn't get isense clock on level\n");
    return (unsigned int)-6;
  }
  if ( !a1[1105] )
    a1[1105] = a1[1106];
  if ( (of_property_read_variable_u32_array(
          *(_QWORD *)(v2 + 760),
          "qcom,gpu-bimc-interface-clk-freq",
          (char *)a1 + 10444,
          1,
          0)
      & 0x80000000) == 0 )
    a1[1124] = devm_clk_get(v2 + 16, "bimc_gpu_clk");
  if ( !*((_DWORD *)a1 + 2517) )
  {
    dev_err(*a1, "No power levels are defined\n");
    return (unsigned int)-22;
  }
  _mutex_init(a1 + 1377, "&pwr->mutex", &kgsl_pwrctrl_init___key);
  inited = _init_waitqueue_head(a1 + 1393, "&device->active_cnt_wq", &kgsl_pwrctrl_init___key_10);
  if ( *((_DWORD *)a1 + 2517) )
  {
    v10 = 0;
    v11 = 9144;
    v12 = a1 + 1105;
    while ( v10 != 32 )
    {
      v14 = *(unsigned int *)((char *)a1 + v11);
      if ( (int)v14 < 1 )
      {
        inited = (unsigned int)v14;
      }
      else
      {
        inited = clk_round_rate(a1[1105], v14);
        if ( *(_DWORD *)((char *)a1 + v11) > (unsigned int)inited )
          goto LABEL_23;
      }
      *(_DWORD *)((char *)a1 + v11) = inited;
LABEL_23:
      v13 = *((unsigned int *)a1 + 2517);
      ++v10;
      v11 += 28;
      if ( v10 >= v13 )
      {
        v15 = v13 - 1;
        if ( v15 > 0x1F )
          break;
        clk_set_rate(a1[1105], *((unsigned int *)a1 + 7 * v15 + 2286));
        inited = clk_round_rate(a1[1111], 19200000);
        v16 = inited;
        if ( (int)inited >= 1 && (inited = clk_set_rate(a1[1111], inited & 0x7FFFFFFF), (_DWORD)inited) )
        {
          inited = _warn_printk("%s set freq %d failed:%d\n", "rbbmtimer_clk", v16, inited);
          __break(0x800u);
          v17 = *((unsigned int *)a1 + 2280);
          if ( (_DWORD)v17 )
            goto LABEL_32;
        }
        else
        {
          v17 = *((unsigned int *)a1 + 2280);
          if ( (_DWORD)v17 )
          {
LABEL_32:
            if ( (unsigned int)v17 >= 0x13 )
              break;
            v18 = *((_DWORD *)a1 + 2281) >= *((_DWORD *)a1 + 2517) - 1 ? 200000000LL : 19200000LL;
            inited = clk_round_rate(v12[v17], v18);
            v19 = *((unsigned int *)a1 + 2280);
            if ( (unsigned int)v19 > 0x12 )
              break;
            v20 = inited;
            v21 = v12[v19];
            v22 = clocks[v19];
            v23 = clk_set_rate(v21, v20);
            if ( v23 )
            {
              _warn_printk("%s set freq %d failed:%d\n", v22, v20, v23);
              __break(0x800u);
            }
          }
        }
        if ( of_find_property(*(_QWORD *)(v2 + 760), "vddcx-supply", 0)
          || (of_property_match_string(*(_QWORD *)(v2 + 760), "power-domain-names", "cx") & 0x80000000) == 0 )
        {
          kgsl_pwrctrl_probe_cx_gdsc(a1, v2);
        }
        if ( of_find_property(*(_QWORD *)(v2 + 760), "vdd-supply", 0)
          || (of_property_match_string(*(_QWORD *)(v2 + 760), "power-domain-names", "gx") & 0x80000000) == 0 )
        {
          kgsl_pwrctrl_probe_gx_gdsc((__int64)a1, v2);
        }
        if ( of_find_property(*(_QWORD *)(v2 + 760), "vdd-parent-supply", 0) )
        {
          v24 = devm_regulator_get(v2 + 16, "vdd-parent");
          a1[1130] = v24;
          if ( v24 >= 0xFFFFFFFFFFFFF001LL )
          {
            dev_err(*a1, "Failed to get vdd-parent regulator:%ld\n", v24);
            return (unsigned int)-19;
          }
          if ( (of_property_read_variable_u32_array(*(_QWORD *)(v2 + 760), "vdd-parent-min-corner", a1 + 1131, 1, 0)
              & 0x80000000) != 0 )
          {
            dev_err(*a1, "vdd-parent-min-corner not found\n");
            return (unsigned int)-19;
          }
        }
        *((_DWORD *)a1 + 2270) = 0;
        _init_swait_queue_head(a1 + 1136, "&x->wait", &init_completion___key_5);
        complete_all(a1 + 1135);
        v25 = a1[1125];
        if ( v25 )
        {
          a1[1132] = &kgsl_cx_gdsc_event;
          v26 = devm_regulator_register_notifier(v25, a1 + 1132);
          if ( v26 )
            goto LABEL_65;
LABEL_53:
          *((_DWORD *)a1 + 2512) = 0;
          v28 = dev_pm_qos_add_request(v2 + 16, a1 + 1309, 4, 0x7FFFFFFF);
          if ( v28 < 0 )
            dev_err(*a1, "PM QoS sysfs thermal request failed:%d\n", v28);
          a1[1364] = pmqos_max_notifier_call;
          v29 = dev_pm_qos_add_notifier(v2 + 16, a1 + 1364, 4);
          if ( v29 )
            dev_err(*a1, "Unable to register notifier call for PMQOS updates: %d\n", v29);
          worker = kthread_create_worker(0, "kgsl_cooling_worker");
          a1[1370] = worker;
          if ( worker >= 0xFFFFFFFFFFFFF001LL )
          {
            v35 = worker;
            dev_err(*a1, "Failed to create cooling worker: %d\n", worker);
            v26 = v35;
          }
          else
          {
            a1[1375] = 0;
            a1[1374] = 0;
            a1[1371] = a1 + 1371;
            a1[1372] = a1 + 1371;
            a1[1373] = kgsl_set_thermal_constraint;
            sched_set_fifo(*(_QWORD *)(worker + 40));
            v31 = *(_QWORD *)(v2 + 760);
            v32 = dev_pm_qos_add_request(a1[1396] + 16LL, a1 + 1321, 4, 0x7FFFFFFF);
            if ( v32 )
            {
              v36 = v32;
              dev_err(*a1, "Unable to register thermal cooling device: %d\n", v32);
            }
            else
            {
              v33 = thermal_of_cooling_device_register(v31, "kgsl", a1, kgsl_cooling_ops);
              a1[1320] = v33;
              if ( v33 < 0xFFFFFFFFFFFFF001LL
                || (dev_pm_qos_remove_request(a1 + 1321),
                    v37 = *((_DWORD *)a1 + 2640),
                    dev_err(*a1, "Unable to register thermal cooling device: %d\n", v37),
                    (v36 = v37) == 0) )
              {
                a1[1141] = 0;
                *((_DWORD *)a1 + 2737) = 255;
                pm_runtime_enable(v2 + 16);
                return 0;
              }
            }
            dev_pm_qos_remove_notifier(v2 + 16, a1 + 1364, 4);
            v26 = v36;
          }
        }
        else
        {
          v27 = a1[1127];
          if ( !v27 )
            goto LABEL_53;
          a1[1132] = &kgsl_cx_gdsc_event;
          v26 = dev_pm_genpd_add_notifier(v27, a1 + 1132);
          if ( !v26 )
            goto LABEL_53;
LABEL_65:
          dev_err(v2 + 16, "Failed to register gdsc notifier: %d\n", v26);
        }
        v38 = a1[1370];
        if ( v38 && v38 <= 0xFFFFFFFFFFFFF000LL )
          kthread_destroy_worker(a1[1370]);
        if ( a1[1318] )
          dev_pm_qos_remove_request(a1 + 1309);
        return v26;
      }
    }
  }
  __break(0x5512u);
  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v1);
  return pmqos_max_notifier_call(inited);
}
