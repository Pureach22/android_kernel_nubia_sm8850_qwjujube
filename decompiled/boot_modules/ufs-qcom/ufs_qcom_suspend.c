__int64 __usercall ufs_qcom_suspend@<X0>(__int64 lock@<X0>, int a2@<W1>, int a3@<W2>, __int64 a4@<X8>)
{
  unsigned int v4; // w9
  unsigned int v5; // w10
  __int64 v6; // x19
  void *v7; // x20
  __int64 v8; // x22
  __int64 v9; // x23
  __int64 v10; // x24
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x9
  unsigned __int64 v14; // x9
  __int64 v16; // x21
  __int64 v17; // x21
  __int64 v18; // x21
  __int64 v19; // x21
  _QWORD *v20; // x21
  __int64 v21; // x0
  _QWORD *v22; // x21
  int v23; // w22
  int v24; // w8
  int v25; // w8
  int v26; // w8
  __int64 *v27; // x25
  __int64 v28; // x26
  unsigned int v29; // w21
  int v30; // w22
  __int64 v31; // x23
  char v32; // w8
  __int64 v33; // x8
  unsigned __int64 v34; // x22
  int updated; // w0
  unsigned __int64 v36; // x8
  bool v37; // cf
  int v38; // w23
  __int64 v39; // x22
  _QWORD *v40; // x22
  int v41; // w0
  __int64 v42; // x0
  __int64 unlock; // x0
  __int64 v44; // x25
  __int64 v45; // x26
  unsigned int *v46; // x8
  unsigned __int64 v47; // x21
  __int64 v48; // x0
  int v49; // w22
  unsigned __int64 StatusReg; // x25
  __int64 v51; // x26
  __int64 (__fastcall *v52)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD); // x8
  __int64 v53; // x0
  __int64 v54; // t1
  __int64 v55; // x8
  unsigned int v56; // [xsp+10h] [xbp-10h]
  unsigned int v57; // [xsp+14h] [xbp-Ch]
  unsigned int v58; // [xsp+18h] [xbp-8h]
  unsigned int v59; // [xsp+1Ch] [xbp-4h]

  if ( !lock )
    goto LABEL_85;
  if ( !a3 )
    return 0;
  v10 = *(_QWORD *)(lock + 184);
  v6 = lock;
  if ( *(_DWORD *)(lock + 84) == 1 )
  {
    v12 = *(_QWORD *)(*(_QWORD *)(lock + 64) + 592LL);
    if ( v12 )
    {
      if ( v12 <= 0xFFFFFFFFFFFFF000LL )
      {
        v13 = *(_QWORD *)(*(_QWORD *)(v10 + 8) + 96LL);
        if ( v13 )
        {
          if ( v13 <= 0xFFFFFFFFFFFFF000LL )
          {
            v14 = *(_QWORD *)(v13 + 592);
            if ( v14 )
            {
              if ( v14 <= 0xFFFFFFFFFFFFF000LL )
              {
                *(_DWORD *)(v12 + 520) |= 4u;
                *(_DWORD *)(v14 + 520) |= 4u;
              }
            }
          }
        }
      }
    }
  }
  else
  {
    if ( *(_BYTE *)(v10 + 128) == 1 )
    {
      v16 = *(_QWORD *)(v10 + 120);
      if ( v16 )
      {
        clk_disable(*(_QWORD *)(v10 + 120));
        clk_unprepare(v16);
      }
      v17 = *(_QWORD *)(v10 + 104);
      clk_disable(v17);
      clk_unprepare(v17);
      v18 = *(_QWORD *)(v10 + 112);
      if ( v18 )
      {
        clk_disable(*(_QWORD *)(v10 + 112));
        clk_unprepare(v18);
      }
      v19 = *(_QWORD *)(v10 + 96);
      clk_disable(v19);
      clk_unprepare(v19);
      *(_BYTE *)(v10 + 128) = 0;
    }
    v20 = *(_QWORD **)(v10 + 392);
    if ( v20 && !*(_DWORD *)(v6 + 84) && *((_BYTE *)v20 + 17) == 1 )
    {
      LODWORD(v21) = regulator_disable(*v20);
      if ( !(_DWORD)v21 )
      {
        if ( (int)regulator_count_voltages(*v20) < 1 || (LODWORD(v21) = regulator_set_load(*v20, 0), !(_DWORD)v21) )
        {
          LODWORD(v21) = 0;
          *((_BYTE *)v20 + 17) = 0;
        }
      }
    }
    else
    {
      LODWORD(v21) = 0;
    }
    v22 = *(_QWORD **)(v10 + 400);
    if ( v22 )
    {
      if ( *(_DWORD *)(v6 + 80) != 1 && (*(_BYTE *)(v6 + 2624) & 1) == 0 && *((_BYTE *)v22 + 17) == 1 )
      {
        v23 = v21;
        v24 = regulator_disable(*v22);
        LODWORD(v21) = v23;
        if ( !v24 )
        {
          v25 = regulator_count_voltages(*v22);
          LODWORD(v21) = v23;
          if ( v25 < 1 || (v26 = regulator_set_load(*v22, 0), LODWORD(v21) = v23, !v26) )
            *((_BYTE *)v22 + 17) = 0;
        }
      }
    }
    if ( (_DWORD)v21 )
      goto LABEL_52;
    v27 = *(__int64 **)(*(_QWORD *)(v6 + 184) + 472LL);
    if ( v27 && *((_DWORD *)v27 + 2) )
    {
      v28 = *v27;
      v29 = 0;
      LODWORD(v21) = 0;
      do
      {
        v30 = v21;
        flush_work(v28 + 32);
        LODWORD(v21) = v30;
        if ( *(_BYTE *)(v28 + 24) == 1 )
        {
          if ( *(_DWORD *)(v28 + 72) == 0x7FFFFFFF )
          {
            LODWORD(v21) = 0;
          }
          else
          {
            v31 = *(_QWORD *)(v28 + 16);
            v32 = 0;
            while ( 1 )
            {
              v33 = -1LL << v32;
              v34 = (unsigned int)v33 & *(_DWORD *)v28;
              if ( ((unsigned int)v33 & *(_DWORD *)v28) == 0 )
              {
LABEL_47:
                LODWORD(v21) = 0;
                *(_BYTE *)(v28 + 24) = 0;
                *(_DWORD *)(v28 + 72) = 0x7FFFFFFF;
                goto LABEL_39;
              }
              updated = dev_pm_qos_update_request(v31, 0x7FFFFFFF);
              if ( updated < 0 )
                break;
              v31 += 80;
              v36 = __clz(__rbit64(v34));
              v37 = v36 >= 0x1F;
              v32 = v36 + 1;
              if ( v37 )
                goto LABEL_47;
            }
            v38 = updated;
            dev_err(*(_QWORD *)(v6 + 64), "Failed (%d) removing qos grp(%d)\n", updated, v29);
            LODWORD(v21) = v38;
          }
        }
LABEL_39:
        ++v29;
        v28 += 80;
      }
      while ( v29 < *((_DWORD *)v27 + 2) );
      if ( (_DWORD)v21 )
        goto LABEL_52;
    }
  }
  if ( !*(_DWORD *)(v6 + 84) && *(_QWORD *)(v10 + 296) )
  {
    v21 = *(_QWORD *)(*(_QWORD *)(v6 + 184) + 296LL);
    if ( !v21 )
      goto LABEL_52;
    gpiod_set_value_cansleep(v21, 1);
  }
  LODWORD(v21) = 0;
LABEL_52:
  v59 = v21;
  if ( a2 != 2
    || (v39 = *(_QWORD *)(v6 + 184),
        ufs_qcom_parse_reg_info(v39, "qcom,vccq-proxy-vote", v39 + 408),
        (v40 = *(_QWORD **)(v39 + 408)) == nullptr)
    || (*((_BYTE *)v40 + 17) & 1) != 0 )
  {
LABEL_59:
    v42 = *(_QWORD *)(v10 + 656);
    if ( !v42 )
      goto LABEL_62;
    goto LABEL_60;
  }
  if ( (int)regulator_count_voltages(*v40) < 1 || (v41 = regulator_set_load(*v40, *((unsigned int *)v40 + 5))) == 0 )
  {
    v41 = regulator_enable(*v40);
    if ( !v41 )
    {
      *((_BYTE *)v40 + 17) = 1;
      goto LABEL_59;
    }
  }
  dev_err(*(_QWORD *)(v6 + 64), "%s: failed enable vccq_proxy err=%d\n", "ufs_qcom_enable_vccq_proxy_vote", v41);
  v42 = *(_QWORD *)(v10 + 656);
  if ( !v42 )
    goto LABEL_62;
LABEL_60:
  if ( *(_BYTE *)(v10 + 664) == 1 )
    ipc_log_string(
      v42,
      ",%d,&,%d,%d,%d,%d,%d,%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40),
      a2,
      *(_DWORD *)(v6 + 88),
      *(_DWORD *)(v6 + 92),
      *(_DWORD *)(v6 + 84),
      *(_DWORD *)(v6 + 80),
      v59);
LABEL_62:
  while ( 1 )
  {
    v9 = *(_QWORD *)(v6 + 184);
    if ( (*(_BYTE *)(v9 + 632) & 1) != 0 )
      break;
    cancel_delayed_work_sync(v9 + 528);
    if ( *(_QWORD *)(v9 + 728) && *(_BYTE *)(v9 + 3139) == 1 )
      walt_unset_enforce_high_irq_cpus(v9 + 728);
    unlock = sched_set_boost(4294967292LL);
    if ( *(_BYTE *)(v9 + 524) != 1 )
      break;
    *(_DWORD *)(v9 + 520) = 0;
    if ( *(int *)(v9 + 648) < 1 )
      break;
    v44 = 0;
    v45 = 0;
    v7 = &qos_min_req;
    while ( 1 )
    {
      v46 = (unsigned int *)(*(_QWORD *)(v9 + 640) + v44);
      v47 = *v46;
      v8 = v46[2];
      lock = cpus_read_lock(unlock);
      a4 = *(_QWORD *)((char *)&_cpu_online_mask + ((v47 >> 3) & 0x1FFFFFF8)) >> v47;
      if ( (a4 & 1) == 0 )
      {
        unlock = cpus_read_unlock(lock);
LABEL_74:
        *(_BYTE *)(v9 + 524) = 0;
        goto LABEL_75;
      }
      if ( (unsigned int)v47 >= 0x20 )
        break;
      v48 = freq_qos_update_request((char *)&qos_min_req + _per_cpu_offset[v47], (unsigned int)v8);
      v49 = v48;
      unlock = cpus_read_unlock(v48);
      if ( (v49 & 0x80000000) == 0 )
        goto LABEL_74;
      unlock = dev_err(*(_QWORD *)(v6 + 64), "fail set cpufreq-fmin_def %d\n", v49);
LABEL_75:
      ++v45;
      v44 += 32;
      if ( v45 >= *(int *)(v9 + 648) )
        goto LABEL_76;
    }
    __break(0x5512u);
LABEL_85:
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v57 = v5;
      v58 = v4;
      v56 = a4;
      ++*(_DWORD *)(StatusReg + 16);
      v51 = qword_17748;
      if ( qword_17748 )
      {
        do
        {
          v52 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))v51;
          v53 = *(_QWORD *)(v51 + 8);
          if ( *(_DWORD *)(*(_QWORD *)v51 - 4LL) != -291122989 )
            __break(0x8228u);
          lock = v52(v53, v8, (unsigned int)v7, v56, (unsigned int)v9, v58, v57, v59);
          v54 = *(_QWORD *)(v51 + 24);
          v51 += 24;
        }
        while ( v54 );
      }
      v55 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v55;
      if ( !v55 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(lock);
    }
  }
LABEL_76:
  if ( (*(_BYTE *)(*(_QWORD *)(v10 + 16) + 3001LL) & 1) != 0 )
    qcom_ice_suspend(*(_QWORD *)(v10 + 152));
  return v59;
}
