__int64 __fastcall kgsl_pwrscale_init(_QWORD *a1, __int64 a2)
{
  _BYTE *v4; // x25
  unsigned int v5; // w9
  __int64 v6; // x10
  unsigned int *v7; // x24
  __int64 v8; // x8
  __int64 v9; // x21
  __int64 property; // x0
  __int64 node_by_name; // x0
  __int64 v12; // x22
  __int64 next_child; // x0
  unsigned int v14; // w9
  __int64 v15; // x10
  __int64 v16; // x9
  __int64 v17; // x9
  __int64 v18; // x10
  _QWORD *v19; // x11
  __int64 v20; // x12
  unsigned __int64 v21; // x0
  int v22; // w3
  __int64 result; // x0
  int v24; // w8
  __int64 v25; // x8
  __int64 v26; // x9
  _QWORD *v27; // x11
  __int64 v28; // x12
  const char *v29; // x22
  int v30; // w10
  int v31; // w11
  __int64 v32; // x10
  int v33; // w12
  __int64 v34; // x0
  __int64 v35; // x0
  unsigned __int64 worker; // x0
  __int64 v37; // x21
  unsigned __int64 v38; // x0
  unsigned __int64 v39; // x20
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x23
  __int64 v42; // x9
  unsigned __int64 v43; // x0
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  int v48; // [xsp+Ch] [xbp-24h] BYREF
  _QWORD v49[4]; // [xsp+10h] [xbp-20h] BYREF

  v4 = (char *)a1 + 8660;
  v49[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *((_BYTE *)a1 + 14232) == 1 )
  {
    *((_BYTE *)a1 + 10368) = 1;
    v5 = *((_DWORD *)a1 + 2513);
    a1[1429] = &adreno_tz_data;
    a1[1432] = &kgsl_devfreq_target;
    a1[1433] = kgsl_devfreq_get_dev_status;
    a1[1434] = &kgsl_devfreq_get_cur_freq;
    if ( v5 >= 0x20 )
      goto LABEL_60;
    v6 = a1[1396];
    v7 = (unsigned int *)(a1 + 1143);
    v8 = *((unsigned int *)a1 + 7 * v5 + 2286);
    *((_DWORD *)a1 + 2862) = 10;
    a1[1430] = v8;
    v9 = *(_QWORD *)(v6 + 760);
    property = of_find_property(v9, "qcom,enable-ca-jump", 0);
    v4[3364] = property != 0;
    if ( !property )
      goto LABEL_23;
    *((_DWORD *)a1 + 3008) = 12000;
    of_property_read_variable_u32_array(v9, "qcom,ca-busy-penalty", a1 + 1504, 1, 0);
    *((_DWORD *)a1 + 3007) = 1;
    node_by_name = of_find_node_by_name(v9, "qcom,gpu-pwrlevel-bins");
    if ( node_by_name )
    {
      v12 = node_by_name;
      next_child = of_get_next_child(node_by_name, 0);
      if ( !next_child )
      {
LABEL_23:
        v25 = *((unsigned int *)a1 + 2517);
        if ( (_DWORD)v25 )
        {
          v26 = 0;
          v27 = a1 + 1450;
          while ( v26 != 224 )
          {
            v28 = v7[v26];
            v26 += 7;
            *v27++ = v28;
            if ( 7 * v25 == v26 )
              goto LABEL_27;
          }
          goto LABEL_60;
        }
LABEL_27:
        *((_DWORD *)a1 + 2874) = v25;
        a1[1436] = a1 + 1450;
        if ( (_DWORD)v25 == 1 )
          v29 = "performance";
        else
          v29 = "msm-adreno-tz";
        byte_3B2D5 = of_find_property(*(_QWORD *)(a2 + 760), "qcom,disable-busy-time-burst", 0) != 0;
        if ( v4[3364] == 1 )
        {
          v30 = *((_DWORD *)a1 + 3007);
          v31 = *((_DWORD *)a1 + 3008);
          byte_3B2D6 = 1;
          dword_3B268 = v30;
          dword_3B26C = v31;
        }
        if ( v4[1708] == 1 )
        {
          v32 = a1[1299];
          v33 = *((_DWORD *)a1 + 2595);
          v34 = *(_QWORD *)(a1[1396] + 760LL);
          dword_3B290 = *((_DWORD *)a1 + 2600);
          qword_3B2C0 = v32;
          dword_3B298 = v33;
          if ( !(unsigned int)kgsl_of_property_read_ddrtype(v34, "qcom,bus-accesses", (__int64)&unk_3B294) )
            byte_3B2C8 = 0;
        }
        v35 = alloc_workqueue("%s", &print_fmt_kgsl_reclaim_process[38]);
        a1[1487] = v35;
        if ( v35 )
        {
          worker = kthread_create_worker(0, "kgsl_devfreq_notifier");
          a1[1496] = worker;
          if ( worker >= 0xFFFFFFFFFFFFF001LL )
          {
            result = dev_err(*a1, "Failed to create devfreq notify worker ret: %d\n", worker);
          }
          else
          {
            v37 = a2 + 16;
            v38 = devfreq_add_device(a2 + 16, a1 + 1430, v29, &adreno_tz_data);
            v39 = v38;
            if ( v38 && v38 < 0xFFFFFFFFFFFFF001LL )
            {
              a1[1427] = v38;
              v4[3220] = 1;
              if ( dword_3B290 )
              {
                a1[1444] = &kgsl_busmon_target;
                a1[1445] = kgsl_busmon_get_dev_status;
                *((_DWORD *)a1 + 2898) = *((_DWORD *)a1 + 2517);
                a1[1441] = &adreno_tz_data;
                a1[1446] = kgsl_busmon_get_cur_freq;
                a1[1448] = a1 + 1450;
                a1[1517] = v37;
                a1[1606] = busmon_dev_release;
                dev_set_name(a1 + 1505, "kgsl-busmon");
                a1[1524] = a1;
                if ( (unsigned int)device_register(a1 + 1505) )
                {
                  put_device(a1 + 1505);
                }
                else
                {
                  v40 = *((unsigned int *)a1 + 2517);
                  if ( (_DWORD)v40 )
                  {
                    v41 = 0;
                    while ( v41 != 32 )
                    {
                      v42 = *v7;
                      if ( (_DWORD)v42 )
                      {
                        v49[0] = 0;
                        v49[1] = v42;
                        v49[2] = 0;
                        dev_pm_opp_add_dynamic(a1 + 1505, v49);
                        v40 = *((unsigned int *)a1 + 2517);
                      }
                      ++v41;
                      v7 += 7;
                      if ( v41 >= v40 )
                        goto LABEL_48;
                    }
                    goto LABEL_60;
                  }
LABEL_48:
                  v43 = devfreq_add_device(a1 + 1505, a1 + 1442, "gpubw_mon", 0);
                  if ( v43 && v43 < 0xFFFFFFFFFFFFF001LL )
                  {
                    a1[1619] = v43;
                  }
                  else
                  {
                    dev_err(v37, "Bus scaling not enabled\n");
                    dev_pm_opp_remove_all_dynamic(a1 + 1505);
                    device_unregister(a1 + 1505);
                  }
                }
              }
              if ( (unsigned int)sysfs_create_link(*a1, v39 + 64, "devfreq") )
                __break(0x800u);
              a1[1488] = 0xFFFFFFFE00000LL;
              a1[1489] = a1 + 1489;
              a1[1490] = a1 + 1489;
              a1[1491] = do_devfreq_suspend;
              a1[1492] = 0xFFFFFFFE00000LL;
              a1[1493] = a1 + 1493;
              a1[1494] = a1 + 1493;
              a1[1495] = do_devfreq_resume;
              a1[1500] = 0;
              a1[1501] = 0;
              a1[1497] = a1 + 1497;
              a1[1498] = a1 + 1497;
              v44 = a1[1496];
              a1[1499] = do_devfreq_notify;
              v45 = sched_set_fifo(*(_QWORD *)(v44 + 40));
              result = ktime_get(v45);
              a1[1502] = result + 10000000;
            }
            else
            {
              v47 = *a1;
              v4[3220] = 0;
              result = dev_err(v47, "Failed to add devfreq device for %s governor: %d\n", v29, v39);
            }
          }
        }
        else
        {
          result = dev_err(*a1, "Failed to allocate kgsl devfreq workqueue\n");
          v4[3220] = 0;
        }
        goto LABEL_54;
      }
      v9 = next_child;
      while ( 1 )
      {
        v48 = 0;
        if ( (of_property_read_variable_u32_array(v9, "qcom,speed-bin", &v48, 1, 0) & 0x80000000) == 0
          && v48 == *((_DWORD *)a1 + 3294) )
        {
          break;
        }
        v9 = of_get_next_child(v12, v9);
        if ( !v9 )
          goto LABEL_23;
      }
      LODWORD(v49[0]) = 1;
    }
    else
    {
      LODWORD(v49[0]) = 1;
    }
    of_property_read_variable_u32_array(v9, "qcom,ca-target-pwrlevel", v49, 1, 0);
    v24 = v49[0];
    if ( LODWORD(v49[0]) >= *((_DWORD *)a1 + 2517) )
      v24 = 1;
    *((_DWORD *)a1 + 3007) = v24;
    goto LABEL_23;
  }
  v14 = *((_DWORD *)a1 + 2513);
  *v4 = 1;
  a1[1432] = kgsl_passive_devfreq_target;
  a1[1433] = kgsl_passive_devfreq_get_dev_status;
  a1[1434] = &kgsl_devfreq_get_cur_freq;
  if ( v14 >= 0x20 )
    goto LABEL_60;
  v15 = *((unsigned int *)a1 + 2517);
  v16 = *((unsigned int *)a1 + 7 * v14 + 2286);
  *((_DWORD *)a1 + 2874) = v15;
  a1[1430] = v16;
  if ( (_DWORD)v15 )
  {
    v17 = 0;
    v18 = 28 * v15;
    v19 = a1 + 1450;
    while ( v17 != 896 )
    {
      v20 = *(unsigned int *)((char *)a1 + v17 + 9144);
      v17 += 28;
      *v19++ = v20;
      if ( v18 == v17 )
        goto LABEL_16;
    }
LABEL_60:
    __break(0x5512u);
  }
LABEL_16:
  a1[1436] = a1 + 1450;
  v21 = devfreq_add_device(a2 + 16, a1 + 1430, "msm-adreno-ro", 0);
  v22 = v21;
  a1[1428] = v21;
  if ( v21 && v21 < 0xFFFFFFFFFFFFF001LL )
  {
    result = sysfs_remove_groups(v21 + 64, *(_QWORD *)(*(_QWORD *)(v21 + 856) + 16LL));
  }
  else
  {
    v46 = *a1;
    a1[1428] = 0;
    result = dev_err(v46, "Failed to add devfreq device for %s governor: %d\n", "msm-adreno-ro", v22);
  }
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
