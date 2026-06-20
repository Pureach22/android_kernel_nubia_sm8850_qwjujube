__int64 cpu_ctrl_init()
{
  char v0; // w8
  int v1; // w19
  unsigned __int64 v2; // x9
  unsigned int v3; // w22
  unsigned __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x27
  unsigned __int64 v7; // x8
  __int64 v8; // x21
  __int64 v9; // x19
  int v10; // w28
  unsigned __int64 v11; // x24
  __int64 v12; // x25
  __int64 v13; // x0
  __int64 v14; // x23
  __int64 v15; // x11
  unsigned int v16; // w8
  int *v17; // x11
  int v18; // w12
  int v19; // t1
  __int64 v20; // x11
  int v21; // w12
  void *v22; // x0
  __int64 v23; // x8
  unsigned int v24; // w25
  unsigned int v25; // w24
  __int64 v26; // x9
  unsigned int v27; // w9
  unsigned int *v28; // x10
  unsigned int v29; // w11
  unsigned int v30; // t1
  unsigned int v31; // w12
  unsigned int v32; // w0
  unsigned int v33; // w24
  __int64 v34; // x9
  _QWORD *v35; // x8
  unsigned __int64 v36; // x10
  __int64 v37; // x19
  char v38; // w8
  unsigned int v40; // w19

  if ( cpufreq_cpu_get(0) )
    ((void (*)(void))cpufreq_cpu_put)();
  else
    printk(&unk_EF84, "get_cluster0_last_cpu");
  v0 = 0;
  v1 = 0;
  do
  {
    v4 = (unsigned int)(-1LL << v0) & _cpu_possible_mask;
    if ( !(_DWORD)v4 )
      break;
    v3 = __clz(__rbit64(v4));
    v5 = cpufreq_cpu_get(v3);
    if ( v5 )
    {
      if ( ifas_log_enable )
      {
        v6 = v5;
        printk(&unk_105C5, "cpu_ctrl_init");
        v5 = v6;
      }
      ++v1;
      v2 = 63 - __clz(*(unsigned int *)(v5 + 8));
      if ( *(_DWORD *)(v5 + 8) )
        v3 = v2;
      else
        v3 = 32;
      ((void (*)(void))cpufreq_cpu_put)();
    }
    v0 = v3 + 1;
  }
  while ( v3 + 1 < 0x20 );
  cluster_num = v1;
  if ( v1 )
  {
    cpufreq_dev = (__int64)_kmalloc_noprof(344LL * cluster_num, 3520);
    if ( cpufreq_dev )
    {
      v7 = _cpu_possible_mask;
      if ( _cpu_possible_mask )
      {
        v8 = 0;
        v9 = 0;
        v10 = 0;
        _ReadStatusReg(SP_EL0);
        while ( 1 )
        {
          v11 = __clz(__rbit64(v7));
          v12 = _per_cpu_offset[v11];
          v13 = cpufreq_cpu_get((unsigned int)v11);
          if ( !v13 )
          {
            printk(&unk_F493, "cpu_ctrl_init");
            return 4294967293LL;
          }
          v14 = v13;
          if ( ifas_log_enable )
          {
            printk(&unk_10097, "cpu_ctrl_init");
            v15 = *(_QWORD *)(v14 + 384);
            if ( !v15 )
              goto LABEL_61;
          }
          else
          {
            v15 = *(_QWORD *)(v13 + 384);
            if ( !v15 )
              goto LABEL_61;
          }
          v16 = 0;
          v17 = (int *)(v15 + 8);
          while ( 1 )
          {
            do
            {
              v19 = *v17;
              v17 += 3;
              v18 = v19;
            }
            while ( v19 == -1 );
            if ( v18 == -2 )
              break;
            ++v16;
          }
          if ( !v16 )
          {
LABEL_61:
            printk(&unk_EE07, "cpu_ctrl_init");
            return 4294967277LL;
          }
          v20 = cpufreq_dev + 344 * v9;
          if ( v10 )
            v21 = -6;
          else
            v21 = -8;
          *(_QWORD *)(v20 + 64) = (char *)&qos_req_max + v12;
          *(_QWORD *)(v20 + 72) = (char *)&qos_req_min + v12;
          *(_QWORD *)(v20 + 40) = v14;
          *(_DWORD *)(v20 + 24) = v16 - 1;
          *(_DWORD *)(v20 + 16) = v16 + v21;
          *(_DWORD *)v20 = v10;
          *(_DWORD *)(v20 + 4) = v11;
          v22 = _kmalloc_noprof(4LL * v16, 3264);
          v23 = cpufreq_dev;
          *(_QWORD *)(cpufreq_dev + 344 * v9 + 32) = v22;
          if ( !v22 )
            return 4294967284LL;
          v24 = 0;
          v25 = -1;
          do
          {
            v27 = v25;
            v25 = 0;
            v28 = (unsigned int *)(*(_QWORD *)(v14 + 384) + 8LL);
            while ( 1 )
            {
              do
              {
                v30 = *v28;
                v28 += 3;
                v29 = v30;
              }
              while ( v30 == -1 );
              if ( v29 == -2 )
                break;
              if ( v29 <= v25 )
                v31 = v25;
              else
                v31 = v29;
              if ( v29 < v27 )
                v25 = v31;
            }
            *(_DWORD *)(*(_QWORD *)(v23 + 344 * v9 + 32) + 4LL * v24) = v25;
            if ( v25 )
            {
              if ( ifas_log_enable )
                printk(&unk_FB84, "cpu_ctrl_init");
            }
            else
            {
              printk(&unk_EC6A, "cpu_ctrl_init");
            }
            v23 = cpufreq_dev;
            v26 = cpufreq_dev + 344 * v9;
            ++v24;
          }
          while ( v24 <= *(_DWORD *)(v26 + 24) );
          v32 = freq_qos_add_request(v14 + 144, *(_QWORD *)(v26 + 64), 2, **(unsigned int **)(v26 + 32));
          if ( (v32 & 0x80000000) != 0 )
          {
            v40 = v32;
            printk(&unk_109EC, "cpu_ctrl_init");
            return v40;
          }
          v33 = freq_qos_add_request(
                  v14 + 144,
                  *(_QWORD *)(cpufreq_dev + 344 * v9 + 72),
                  1,
                  *(unsigned int *)(*(_QWORD *)(cpufreq_dev + 344 * v9 + 32)
                                  + 4LL * *(int *)(cpufreq_dev + 344 * v9 + 24)));
          if ( (v33 & 0x80000000) != 0 )
            break;
          v34 = cpufreq_dev + 344 * v9;
          v35 = (_QWORD *)(cpufreq_dev + v8);
          v35[13] = 0;
          v35[14] = 0;
          v35[15] = 0;
          v35[16] = 0;
          v35[17] = 0;
          v35[18] = 0;
          v35[11] = 0;
          v35[12] = 0;
          v35[19] = 0;
          v35[20] = 0;
          v35[21] = 0;
          v35[22] = 0;
          v35[23] = 0;
          v35[24] = 0;
          v35[25] = 0;
          v35[26] = 0;
          v35[33] = 0;
          v35[34] = 0;
          v35[31] = 0;
          v35[32] = 0;
          v35[29] = 0;
          v35[30] = 0;
          v35[27] = 0;
          v35[28] = 0;
          v35[41] = 0;
          v35[42] = 0;
          v35[39] = 0;
          v35[40] = 0;
          v35[37] = 0;
          v35[38] = 0;
          v35[35] = 0;
          v35[36] = 0;
          *(_QWORD *)(v34 + 80) = 0;
          v36 = 63 - __clz(*(unsigned int *)(v14 + 8));
          if ( *(_DWORD *)(v14 + 8) )
            v37 = v36;
          else
            v37 = 32;
          *(_DWORD *)(v34 + 8) = v37;
          cpufreq_cpu_put(v14);
          v38 = v37 + 1;
          if ( (unsigned __int64)(v37 + 1) <= 0x1F )
          {
            v8 = 344LL * ++v10;
            v9 = v10;
            v7 = (unsigned int)(-1LL << v38) & _cpu_possible_mask;
            if ( (_DWORD)v7 )
              continue;
          }
          goto LABEL_55;
        }
        printk(&unk_109EC, "cpu_ctrl_init");
      }
      else
      {
        v33 = 0;
LABEL_55:
        ifas_sysfs_create_file(0, &kobj_attr_cpu_min_freq_limit_cluster0);
        ifas_sysfs_create_file(0, &kobj_attr_cpu_max_freq_limit_cluster0);
        ifas_sysfs_create_file(0, &kobj_attr_cpu_min_freq_limit_cluster1);
        ifas_sysfs_create_file(0, &kobj_attr_cpu_max_freq_limit_cluster1);
        ifas_sysfs_create_file(0, &kobj_attr_cpu_min_freq_limit_cluster2);
        ifas_sysfs_create_file(0, &kobj_attr_cpu_max_freq_limit_cluster2);
        ifas_sysfs_create_file(0, &kobj_attr_cpu_min_freq_limit_cluster3);
        ifas_sysfs_create_file(0, &kobj_attr_cpu_max_freq_limit_cluster3);
        ifas_sysfs_create_file(0, &kobj_attr_cpu_max_freq_ceiling_cluster0);
        ifas_sysfs_create_file(0, &kobj_attr_cpu_max_freq_ceiling_cluster1);
        ifas_sysfs_create_file(0, &kobj_attr_ifas_enable);
      }
      return v33;
    }
    else
    {
      printk(&unk_FA43, "cpu_ctrl_init");
      return 4294967284LL;
    }
  }
  else
  {
    printk(&unk_EF84, "cpu_ctrl_init");
    return 4294967282LL;
  }
}
