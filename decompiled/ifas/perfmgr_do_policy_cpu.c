int *__fastcall perfmgr_do_policy_cpu(int *result)
{
  int *v1; // x19
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x8
  unsigned __int64 v5; // x20
  __int64 v6; // x0
  const char *v7; // x2
  __int64 v8; // x1
  __int64 v9; // x21
  __int64 v10; // x22
  unsigned __int64 v11; // x23
  __int64 v12; // x0
  int v13; // w8
  int v14; // w9
  unsigned int v15; // w9
  __int64 v16; // x22
  __int64 v17; // x0
  __int64 v18; // x0
  __int128 v19; // q0
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x10
  __int64 v24; // x11
  __int64 v25; // x0
  unsigned __int64 v26; // x22
  int v27; // w8
  unsigned int v28; // w8
  _DWORD *v29; // x27
  unsigned __int64 *v30; // x24
  int v31; // w9
  unsigned __int64 v32; // x2
  __int64 v33; // x1
  __int64 v34; // x0
  unsigned int v35; // w8
  unsigned __int64 v36; // x28
  unsigned __int64 v37; // x8
  _BOOL4 v38; // w9
  unsigned int v39; // w24
  bool v40; // w23
  __int64 v41; // x8
  signed __int64 v42; // x2
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x22
  __int64 v47; // x0
  char v48; // w8
  unsigned int v49; // w21
  int v50; // w0
  __int64 v51; // x8
  int v52; // w11
  __int64 v53; // x0
  __int64 v54; // x1
  int v55; // w8
  unsigned int v56; // w27
  int v57; // w0
  __int64 v58; // x8

  if ( !result )
    return result;
  v1 = result;
  if ( saved_connected_pid != *result )
    saved_connected_pid = *result;
  v2 = cancel_delayed_work(&maxfreq_release_work);
  v3 = ktime_get(v2);
  v4 = v3 - *((_QWORD *)v1 + 1);
  v5 = v4 / 1000;
  if ( v4 <= 2999999 )
  {
    v6 = (unsigned int)*v1;
    v7 = "drop_frame_usecs64";
    v8 = (unsigned int)v5;
    return (int *)ifas_systrace_c(v6, v8, v7);
  }
  v9 = v3;
  v10 = *((_QWORD *)v1 + 14);
  v11 = *((_QWORD *)v1 + 15);
  v12 = (unsigned int)*v1;
  *((_QWORD *)v1 + 1) = v9;
  ifas_systrace_c(v12, (unsigned int)v5, "frame_usecs64");
  ifas_systrace_c((unsigned int)*v1, (unsigned int)v10, "gpu_frame_usecs64");
  if ( ifas_log_enable )
    printk(&unk_10567, "perfmgr_do_policy_cpu");
  v13 = delay_num_frame;
  if ( delay_num_frame <= 119 )
  {
    v13 = 120;
    delay_num_frame = 120;
  }
  v14 = v1[16];
  if ( v14 < 28 )
    goto LABEL_11;
  if ( v14 > 89 )
  {
    switch ( v14 )
    {
      case 90:
        v15 = 11111;
        goto LABEL_12;
      case 120:
        v15 = 8333;
        goto LABEL_12;
      case 144:
        v15 = 6944;
        goto LABEL_12;
    }
LABEL_44:
    v15 = 0xF4240u / v14;
    goto LABEL_12;
  }
  if ( v14 != 30 )
  {
    if ( v14 == 60 )
    {
      v15 = 16666;
      goto LABEL_12;
    }
    goto LABEL_44;
  }
LABEL_11:
  v15 = 33333;
LABEL_12:
  v16 = cpufreq_wq;
  v17 = _msecs_to_jiffies((unsigned int)((int)(v15 * v13) / 100000));
  v18 = queue_delayed_work_on(32, v16, &maxfreq_release_work, v17);
  result = (int *)update_cpu_loading_locked(v18);
  if ( !v1[16] )
  {
    v20 = (unsigned int)v1[19];
    if ( (int)v20 <= 4 )
    {
      if ( (unsigned int)v20 >= 5 )
      {
        __break(0x5512u);
        *(_OWORD *)&STACK[0xBA80] = v19;
        JUMPOUT(0x8B34);
      }
      *(_QWORD *)&v1[2 * v20 + 6] = v5;
      ++v1[19];
      return result;
    }
  }
  v21 = *((_QWORD *)v1 + 4);
  v22 = *((_QWORD *)v1 + 5);
  v23 = *((_QWORD *)v1 + 6);
  v24 = *((_QWORD *)v1 + 7);
  v25 = (unsigned int)*v1;
  *((_QWORD *)v1 + 7) = v5;
  *((_QWORD *)v1 + 3) = v21;
  *((_QWORD *)v1 + 4) = v22;
  *((_QWORD *)v1 + 5) = v23;
  *((_QWORD *)v1 + 6) = v24;
  v26 = v5 + (int)v22 + (int)v21 + (int)v23 + (int)v24;
  ifas_systrace_c(v25, (unsigned int)v26, "frame_unit_usecs64");
  if ( ifas_log_enable )
    printk(&unk_FCBE, "perfmgr_do_policy_cpu");
  v27 = fixed_target_fps;
  if ( fixed_target_fps > 0 )
  {
    if ( (unsigned int)fixed_target_fps <= 0x1D )
    {
      v27 = 60;
      fixed_target_fps = 60;
    }
    goto LABEL_47;
  }
  v28 = v1[16];
  if ( v28 )
  {
    v29 = v1 + 19;
    v30 = (unsigned __int64 *)(v1 + 20);
    v31 = v1[19] + 1;
    v32 = *((_QWORD *)v1 + 10) + v5;
    v1[19] = v31;
    *((_QWORD *)v1 + 10) = v32;
    if ( v31 != 30 )
      goto LABEL_48;
    if ( ifas_log_enable )
    {
      printk(&unk_F3EE, "calulate_fps");
      v32 = *v30;
    }
  }
  else
  {
    v30 = (unsigned __int64 *)(v1 + 20);
    v29 = v1 + 19;
    LODWORD(v32) = 6 * (v1[6] + v1[20] + v1[8] + v1[10] + v1[12] + v1[14]);
  }
  v27 = 165;
  *v29 = 0;
  *v30 = 0;
  if ( (unsigned int)(165 * v32 - 26000000) >= 0x895440 )
  {
    v27 = 144;
    if ( (unsigned int)(144 * v32 - 26000000) >= 0x895440 )
    {
      v27 = 120;
      if ( (unsigned int)(120 * v32 - 25000000) >= 0xC65D40 )
      {
        v27 = 90;
        if ( (unsigned int)(90 * v32 - 28000000) >= 0xD59F80 )
        {
          v27 = 60;
          if ( (unsigned int)(60 * v32 - 28000000) >= 0xB71B01 )
          {
            v33 = 30;
            if ( (unsigned int)(30 * v32 - 28000000) >= 0x7A1201 )
            {
              if ( !ifas_log_enable )
                goto LABEL_46;
              printk(&unk_10193, 30);
              v33 = 0xFFFFFFFFLL;
              if ( !ifas_log_enable )
                goto LABEL_46;
            }
            else if ( !ifas_log_enable )
            {
LABEL_46:
              v27 = 60;
              goto LABEL_47;
            }
            printk(&unk_F80E, v33);
            goto LABEL_46;
          }
        }
      }
    }
  }
LABEL_47:
  v28 = target_scaling * v27 / 100;
  v1[16] = v28;
LABEL_48:
  if ( last_targetfps == v28 )
  {
    if ( !ifas_log_enable )
      goto LABEL_50;
  }
  else
  {
    printk(&unk_107F2, (unsigned int)*v1);
    v28 = v1[16];
    last_targetfps = v28;
    if ( !ifas_log_enable )
      goto LABEL_50;
  }
  printk(&unk_EAC7, "perfmgr_do_policy_cpu");
  v28 = v1[16];
LABEL_50:
  ifas_systrace_c((unsigned int)*v1, v28, "target_fps");
  v34 = (unsigned int)v1[16];
  if ( !ifas_detect_cpu_jank )
  {
    v41 = (int)v34;
    v42 = v5 * (int)v34;
    if ( v42 > 1000 * single_frame_boost )
      goto LABEL_66;
    v40 = 1;
    v39 = 1;
    goto LABEL_75;
  }
  if ( (int)v34 < 28 )
    goto LABEL_52;
  if ( (int)v34 <= 89 )
  {
    if ( (_DWORD)v34 == 30 )
    {
LABEL_52:
      v35 = 33333;
      goto LABEL_53;
    }
    if ( (_DWORD)v34 == 60 )
    {
      v35 = 16666;
      goto LABEL_53;
    }
  }
  else
  {
    switch ( (_DWORD)v34 )
    {
      case 0x5A:
        v35 = 11111;
        goto LABEL_53;
      case 0x78:
        v35 = 8333;
        goto LABEL_53;
      case 0x90:
        v35 = 6944;
        goto LABEL_53;
    }
  }
  v35 = 0xF4240 / (unsigned int)v34;
LABEL_53:
  v36 = v35;
  v37 = 5LL * v35;
  v38 = v26 < v37;
  if ( v11 < v37 )
    v38 = 1;
  if ( (__int64)v11 < (__int64)v26 )
    v38 = 1;
  v39 = v26 >= v37 && v38;
  v40 = v5 >= v36;
  ifas_systrace_c((unsigned int)*v1, v5 >= v36, "is_cpu_jank");
  ifas_systrace_c((unsigned int)*v1, v39, "is_cpu_unit_jank");
  v34 = (unsigned int)v1[16];
  v41 = (int)v34;
  v42 = v5 * (int)v34;
  if ( v42 > 1000 * single_frame_boost )
  {
    if ( v5 < v36 )
    {
      if ( ifas_log_enable )
        printk(&unk_1034A, "perfmgr_do_policy_cpu");
      v6 = (unsigned int)*v1;
      v7 = "cpubranch";
      v8 = 4294967288LL;
      return (int *)ifas_systrace_c(v6, v8, v7);
    }
LABEL_66:
    do_maxfreq_release(v34);
    if ( ifas_log_enable )
      printk(&unk_ED88, "perfmgr_do_policy_cpu");
    v6 = (unsigned int)*v1;
    v7 = "cpubranch";
    v8 = 8;
    return (int *)ifas_systrace_c(v6, v8, v7);
  }
LABEL_75:
  if ( v42 > 1000 * single_frame_up )
  {
    v43 = *((_QWORD *)v1 + 2);
    jank_happened = 1;
    v44 = (unsigned int)*v1;
    v45 = (unsigned __int128)((v9 - v43) * (__int128)0x20C49BA5E353F7CFLL) >> 64;
    v1[17] = 0;
    *((_QWORD *)v1 + 2) = v9;
    v46 = (v45 >> 7) + ((unsigned __int64)v45 >> 63);
    ifas_systrace_c(v44, 1, "jank_happened");
    ifas_systrace_c((unsigned int)*v1, (unsigned int)v1[17], "rescue_keep_count");
    ifas_systrace_c((unsigned int)*v1, (unsigned int)v46, "frame_jank_usecs64");
    v47 = v1[16];
    v48 = !v40;
    if ( v46 * v47 >= 1000000 * jank_frame_delta )
      v48 = 1;
    if ( (v48 & 1) != 0 )
    {
      if ( ifas_log_enable )
        printk(&unk_F5EC, "perfmgr_do_policy_cpu");
      v6 = (unsigned int)*v1;
      v7 = "cpubranch";
      v8 = 4294967292LL;
    }
    else
    {
      if ( load_reset )
      {
        v49 = (1u >> load_scaling_x) * load_scaling_y;
        v50 = frame_time(v47);
        v51 = (int)(v50 + v50 * v49);
        *((_QWORD *)v1 + 7) = v51;
        *((_QWORD *)v1 + 20) = v51;
      }
      do_cpu_maxfreq_step_up();
      if ( ifas_log_enable )
        printk(&unk_103B6, "perfmgr_do_policy_cpu");
      v6 = (unsigned int)*v1;
      v7 = "cpubranch";
      v8 = 4;
    }
    return (int *)ifas_systrace_c(v6, v8, v7);
  }
  if ( (__int64)(v41 * v26) >= 1000 * scaling_b + 5000000 )
  {
    if ( (__int64)(v41 * v26) <= 1000 * scaling_a + 5000000 )
    {
      if ( ifas_log_enable )
        printk(&unk_10824, "perfmgr_do_policy_cpu");
      v6 = (unsigned int)*v1;
      v7 = "cpubranch";
      v8 = 3;
    }
    else
    {
      if ( load_reset )
      {
        v56 = (1u >> load_scaling_x) * load_scaling_y;
        v57 = frame_time(v34);
        v58 = (int)(v57 + v57 * v56);
        *((_QWORD *)v1 + 7) = v58;
        *((_QWORD *)v1 + 20) = v58;
      }
      if ( v39 )
      {
        do_cpu_maxfreq_step_up();
        if ( ifas_log_enable )
          printk(&unk_EB1A, "perfmgr_do_policy_cpu");
        v6 = (unsigned int)*v1;
        v7 = "cpubranch";
        v8 = 5;
      }
      else
      {
        if ( ifas_log_enable )
          printk(&unk_FFDA, "perfmgr_do_policy_cpu");
        v6 = (unsigned int)*v1;
        v7 = "cpubranch";
        v8 = 4294967291LL;
      }
    }
    return (int *)ifas_systrace_c(v6, v8, v7);
  }
  v52 = normal_frame_keep_count;
  v53 = (unsigned int)*v1;
  v54 = (unsigned int)(v1[17] + 1);
  if ( jank_happened )
    v55 = jank_frame_keep_count;
  else
    v55 = 0;
  v1[17] = v54;
  v1[18] = v52 + v55;
  ifas_systrace_c(v53, v54, "rescue_keep_count");
  result = (int *)ifas_systrace_c((unsigned int)*v1, (unsigned int)v1[18], "rescue_keep_total_count");
  if ( v1[17] >= v1[18] && (v9 - perfmgr_do_policy_cpu_last_limit_time) * v1[16] > 1000000 * scaling_c )
  {
    jank_happened = 0;
    v1[17] = 0;
    do_cpu_maxfreq_step_down(result);
    perfmgr_do_policy_cpu_last_limit_time = v9;
    if ( ifas_log_enable )
      printk(&unk_FDFA, "perfmgr_do_policy_cpu");
    ifas_systrace_c((unsigned int)*v1, 1, "cpubranch");
    ifas_systrace_c((unsigned int)*v1, (unsigned __int8)jank_happened, "jank_happened");
    v6 = (unsigned int)*v1;
    v8 = (unsigned int)v1[17];
    v7 = "rescue_keep_count";
    return (int *)ifas_systrace_c(v6, v8, v7);
  }
  return result;
}
