__int64 __fastcall ufs_qcom_clk_scale_notify(__int64 a1, char a2, __int64 a3, unsigned int a4)
{
  unsigned int v4; // w19
  char v5; // w20
  __int64 v6; // x21
  unsigned __int64 v7; // x23
  __int64 v8; // x22
  __int64 v10; // x0
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x23
  __int64 v14; // x0
  __int64 v15; // x23
  int v16; // w0
  __int64 v17; // x23
  __int64 v18; // x0
  __int64 v19; // x9
  __int64 v21; // x25
  __int64 unlock; // x0
  __int64 v23; // x26
  __int64 v24; // x27
  unsigned int *v25; // x8
  unsigned int v26; // w24
  __int64 lock; // x0
  __int64 updated; // x0
  int v29; // w24
  unsigned __int64 StatusReg; // x22
  __int64 v31; // x24
  void (__fastcall *v32)(__int64, __int64, _QWORD, _QWORD, _QWORD); // x8
  __int64 v33; // x0
  __int64 v34; // t1
  __int64 v35; // x8

  if ( !a1 )
    goto LABEL_48;
  v8 = *(_QWORD *)(a1 + 184);
  v4 = a4;
  v6 = a1;
  v5 = a2;
  if ( (ufshcd_is_hba_active() & 1) == 0 )
  {
    LODWORD(v7) = 0;
    return (unsigned int)v7;
  }
  if ( v4 )
  {
    if ( (v5 & 1) != 0 )
    {
      v10 = raw_spin_lock_irqsave(*(_QWORD *)(*(_QWORD *)(v6 + 56) + 56LL));
      v11 = *(_QWORD *)(v6 + 56);
      *(_QWORD *)(v6 + 2904) = 50;
      raw_spin_unlock_irqrestore(*(_QWORD *)(v11 + 56), v10);
      if ( (*(_BYTE *)(v8 + 632) & 1) == 0 && !*(_DWORD *)(v8 + 708) )
      {
        v12 = *(_QWORD *)(v8 + 472);
        if ( v12 )
        {
          v13 = *(_QWORD *)(v12 + 16);
          v14 = _msecs_to_jiffies(*(unsigned int *)(v8 + 3200));
          queue_delayed_work_on(32, v13, v8 + 528, v14);
        }
      }
      LODWORD(v7) = 0;
    }
    else
    {
      v17 = *(_QWORD *)(v6 + 184);
      v18 = raw_spin_lock_irqsave(*(_QWORD *)(*(_QWORD *)(v6 + 56) + 56LL));
      v19 = *(_QWORD *)(v6 + 56);
      *(_QWORD *)(v6 + 2904) = 10;
      raw_spin_unlock_irqrestore(*(_QWORD *)(v19 + 56), v18);
      if ( v17 != -64 )
        ufs_qcom_cfg_timers(v6, 0);
      LODWORD(v7) = ufs_qcom_core_clk_ctrl(v6, a3);
      if ( (_DWORD)v7 )
        goto LABEL_27;
    }
    if ( v8 != -64 )
    {
      ufs_qcom_cfg_timers(v6, 0);
      ((void (__fastcall *)(__int64))ufs_qcom_icc_update_bw)(v8);
      ufshcd_uic_hibern8_exit(v6);
      goto LABEL_23;
    }
LABEL_27:
    ufshcd_uic_hibern8_exit(v6);
    if ( (v5 & 1) != 0 )
      goto LABEL_24;
    goto LABEL_28;
  }
  if ( *(_BYTE *)(v6 + 4893) == 1 )
  {
    v15 = *(_QWORD *)(v6 + 184);
    while ( *(_DWORD *)(v15 + 3144) )
      usleep_range_state(10000, 20000, 2);
  }
  LODWORD(v7) = ufshcd_uic_hibern8_enter(v6);
  if ( (_DWORD)v7 )
    return (unsigned int)v7;
  if ( (v5 & 1) != 0 )
  {
    ufs_qcom_cfg_timers(v6, 1);
    v16 = ufs_qcom_core_clk_ctrl(v6, a3);
    if ( v16 )
    {
      LODWORD(v7) = v16;
      ufshcd_uic_hibern8_exit(v6);
LABEL_24:
      if ( !*(_QWORD *)(v8 + 656) || *(_BYTE *)(v8 + 664) != 1 )
        return (unsigned int)v7;
      goto LABEL_30;
    }
    goto LABEL_23;
  }
  v21 = *(_QWORD *)(v6 + 184);
  if ( (*(_BYTE *)(v21 + 632) & 1) != 0 )
    goto LABEL_23;
  cancel_delayed_work_sync(v21 + 528);
  if ( *(_QWORD *)(v21 + 728) && *(_BYTE *)(v21 + 3139) == 1 )
    walt_unset_enforce_high_irq_cpus(v21 + 728);
  unlock = sched_set_boost(4294967292LL);
  if ( *(_BYTE *)(v21 + 524) != 1 || (*(_DWORD *)(v21 + 520) = 0, *(int *)(v21 + 648) < 1) )
  {
LABEL_23:
    LODWORD(v7) = 0;
    *(_DWORD *)(v8 + 500) = v5 & 1;
    if ( (v5 & 1) != 0 )
      goto LABEL_24;
LABEL_28:
    if ( !*(_QWORD *)(v8 + 656) || *(_BYTE *)(v8 + 664) != 1 )
      return (unsigned int)v7;
LABEL_30:
    _ReadStatusReg(SP_EL0);
    ipc_log_string();
    return (unsigned int)v7;
  }
  v23 = 0;
  v24 = 0;
  while ( 1 )
  {
    v25 = (unsigned int *)(*(_QWORD *)(v21 + 640) + v23);
    v7 = *v25;
    v26 = v25[2];
    lock = cpus_read_lock(unlock);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask + ((v7 >> 3) & 0x1FFFFFF8)) >> v7) & 1) == 0 )
    {
      unlock = cpus_read_unlock(lock);
LABEL_44:
      *(_BYTE *)(v21 + 524) = 0;
      goto LABEL_45;
    }
    if ( (unsigned int)v7 >= 0x20 )
      break;
    updated = freq_qos_update_request((char *)&qos_min_req + _per_cpu_offset[v7], v26);
    v29 = updated;
    unlock = cpus_read_unlock(updated);
    if ( (v29 & 0x80000000) == 0 )
      goto LABEL_44;
    unlock = dev_err(*(_QWORD *)(v6 + 64), "fail set cpufreq-fmin_def %d\n", v29);
LABEL_45:
    ++v24;
    v23 += 32;
    if ( v24 >= *(int *)(v21 + 648) )
      goto LABEL_23;
  }
  __break(0x5512u);
LABEL_48:
  __break(0x800u);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v31 = qword_17658;
    if ( qword_17658 )
    {
      do
      {
        v32 = *(void (__fastcall **)(__int64, __int64, _QWORD, _QWORD, _QWORD))v31;
        v33 = *(_QWORD *)(v31 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v31 - 4LL) != 1238708801 )
          __break(0x8228u);
        v32(v33, v6, v4, v5 & 1, (unsigned int)v7);
        v34 = *(_QWORD *)(v31 + 24);
        v31 += 24;
      }
      while ( v34 );
    }
    v35 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v35;
    if ( !v35 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace();
  }
  return (unsigned int)v7;
}
