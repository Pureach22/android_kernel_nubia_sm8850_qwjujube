__int64 __fastcall ufs_qcom_setup_clocks(__int64 lock, char a2, unsigned int a3)
{
  unsigned int v3; // w19
  __int64 v4; // x22
  __int64 v5; // x27
  __int64 v6; // x21
  __int64 v7; // x23
  char v8; // w27
  char v9; // w24
  unsigned int v10; // w0
  __int64 v11; // x8
  __int64 result; // x0
  unsigned int v13; // w0
  int v14; // w8
  int v15; // w8
  unsigned int v16; // w0
  __int64 v17; // x0
  char v18; // w11
  __int64 v19; // x8
  __int64 v20; // x23
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x23
  __int64 v24; // x23
  __int64 v25; // x23
  __int64 v26; // x23
  __int64 v27; // x23
  int v28; // w0
  __int64 v29; // x25
  __int64 *v30; // x26
  unsigned int v31; // w8
  __int64 v32; // x27
  unsigned int v33; // w23
  unsigned int v34; // w20
  __int64 v35; // x25
  char v36; // w8
  __int64 v37; // x8
  unsigned __int64 v38; // x20
  int updated; // w0
  unsigned __int64 v40; // x8
  bool v41; // cf
  unsigned int v42; // w25
  __int64 v43; // x23
  __int64 v44; // x25
  __int64 v45; // x23
  unsigned int v46; // w0
  __int64 v47; // x23
  __int64 v48; // x8
  __int64 v49; // x23
  unsigned int v50; // w0
  __int64 v51; // x8
  __int64 v52; // x23
  unsigned int v53; // w0
  __int64 unlock; // x0
  __int64 v55; // x28
  unsigned int *v56; // x8
  unsigned __int64 v57; // x26
  unsigned int v58; // w24
  __int64 v59; // x0
  int v60; // w24
  unsigned int v61; // w23
  unsigned int v62; // w19
  unsigned int v63; // w25
  unsigned int v64; // w24
  unsigned __int64 StatusReg; // x23
  unsigned int v66; // w21
  __int64 v67; // x24
  void (__fastcall *v68)(__int64, __int64, _QWORD, __int64, _QWORD); // x8
  __int64 v69; // x0
  __int64 v70; // t1
  __int64 v71; // x8
  char v72; // [xsp+8h] [xbp-8h]
  unsigned int v73; // [xsp+Ch] [xbp-4h]

  if ( lock )
  {
    v4 = *(_QWORD *)(lock + 184);
    v6 = lock;
    if ( !v4 )
      return 0;
    v7 = *(_QWORD *)(v4 + 8);
    v3 = a3;
    v8 = a2;
    if ( a3 != 1 )
    {
      if ( !a3 )
      {
        v9 = a2 & 1;
        if ( (a2 & 1) != 0 )
        {
          ((void (__fastcall *)(_QWORD))ufs_qcom_icc_update_bw)(*(_QWORD *)(lock + 184));
          if ( *(_DWORD *)(v6 + 84) != 2 )
            goto LABEL_9;
          v10 = ufs_qcom_enable_lane_clks(v4);
          if ( !v10 )
          {
            ufs_qcom_phy_set_src_clk_h8_exit(v7);
LABEL_9:
            v11 = *(_QWORD *)(v4 + 688);
            if ( (*(_BYTE *)(v11 + 45) & 1) != 0 )
            {
              result = 0;
              goto LABEL_63;
            }
            v49 = *(_QWORD *)(v11 + 16);
            v50 = clk_prepare(v49);
            if ( v50 )
            {
              v63 = v50;
            }
            else
            {
              result = clk_enable(v49);
              if ( !(_DWORD)result )
              {
                *(_BYTE *)(*(_QWORD *)(v4 + 688) + 45LL) = v9;
                goto LABEL_63;
              }
              v63 = result;
              clk_unprepare(v49);
            }
            dev_err(*(_QWORD *)(v6 + 64), "%s: Fail dev-ref-clk enabled, ret=%d\n", "ufs_qcom_setup_clocks", v63);
            result = v63;
LABEL_63:
            v51 = *(_QWORD *)(v4 + 696);
            if ( (*(_BYTE *)(v51 + 45) & 1) == 0 )
            {
              v52 = *(_QWORD *)(v51 + 16);
              v53 = clk_prepare(v52);
              if ( v53 )
              {
                v64 = v53;
              }
              else
              {
                result = clk_enable(v52);
                if ( !(_DWORD)result )
                {
                  v48 = *(_QWORD *)(v4 + 696);
LABEL_67:
                  *(_BYTE *)(v48 + 45) = v9;
                  v22 = *(_QWORD *)(v4 + 656);
                  if ( !v22 )
                    return result;
                  goto LABEL_88;
                }
                v64 = result;
                clk_unprepare(v52);
              }
              dev_err(*(_QWORD *)(v6 + 64), "%s: Fail core-unipro-clk enabled, ret=%d\n", "ufs_qcom_setup_clocks", v64);
              result = v64;
              v22 = *(_QWORD *)(v4 + 656);
              if ( !v22 )
                return result;
              goto LABEL_88;
            }
LABEL_87:
            v22 = *(_QWORD *)(v4 + 656);
            if ( !v22 )
              return result;
            goto LABEL_88;
          }
          v62 = v10;
          dev_err(*(_QWORD *)(v6 + 64), "%s: enable lane clks failed, ret=%d\n", "ufs_qcom_setup_clocks", v10);
          return v62;
        }
        if ( *(_DWORD *)(lock + 84) != 1 )
        {
          if ( *(_BYTE *)(lock + 4893) == 1 && *(_DWORD *)(v4 + 3144) )
          {
            do
              usleep_range_state(10000, 20000, 2);
            while ( *(_DWORD *)(v4 + 3144) );
          }
          v43 = *(_QWORD *)(*(_QWORD *)(v4 + 696) + 16LL);
          clk_disable(v43);
          clk_unprepare(v43);
          *(_BYTE *)(*(_QWORD *)(v4 + 696) + 45LL) = v9;
          v44 = *(_QWORD *)(v6 + 184);
          v45 = *(_QWORD *)(v44 + 8);
          mutex_lock(v44 + 424);
          if ( *(_BYTE *)(v44 + 419) == 1 )
          {
            v46 = phy_power_off(v45);
            if ( v46 )
            {
              v62 = v46;
              mutex_unlock(v44 + 424);
              dev_err(*(_QWORD *)(v6 + 64), "%s: phy power off failed, ret=%d\n", "ufs_qcom_setup_clocks", v62);
              return v62;
            }
            *(_BYTE *)(v44 + 419) = 0;
          }
          mutex_unlock(v44 + 424);
          ufs_qcom_dev_ref_clk_ctrl(v4, 0);
          v47 = *(_QWORD *)(*(_QWORD *)(v4 + 688) + 16LL);
          clk_disable(v47);
          clk_unprepare(v47);
          v48 = *(_QWORD *)(v4 + 688);
          result = 0;
          goto LABEL_67;
        }
      }
      result = 0;
      v22 = *(_QWORD *)(v4 + 656);
      if ( !v22 )
        return result;
LABEL_88:
      if ( *(_BYTE *)(v4 + 664) == 1 )
      {
        v61 = result;
        ipc_log_string(v22, ",%d,#,%d,%d,%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40), v3, v8 & 1, result);
        return v61;
      }
      return result;
    }
    if ( (a2 & 1) != 0 )
    {
      mutex_lock(v4 + 424);
      if ( (*(_BYTE *)(v4 + 419) & 1) == 0 )
      {
        v13 = phy_power_on(v7);
        if ( v13 )
        {
          v62 = v13;
          mutex_unlock(v4 + 424);
          dev_err(*(_QWORD *)(v6 + 64), "%s: phy power on failed, ret = %d\n", "ufs_qcom_setup_clocks", v62);
          return v62;
        }
        *(_BYTE *)(v4 + 419) = 1;
      }
      mutex_unlock(v4 + 424);
      v14 = *(_DWORD *)(v6 + 2708);
      if ( v14 == 4 || v14 == 1 )
      {
        v15 = *(_DWORD *)(v6 + 2712);
        if ( (v15 == 4 || v15 == 1) && *(_QWORD *)(v4 + 160) && (*(_BYTE *)(v4 + 168) & 1) == 0 )
        {
          v16 = readl_relaxed();
          writel_relaxed(*(_DWORD *)(v4 + 180) | v16, *(_QWORD *)(v4 + 160));
          readl(*(unsigned int **)(v4 + 160));
          usleep_range_state(50, 60, 2);
          *(_BYTE *)(v4 + 168) = 1;
        }
      }
      idle_time_0 += (ktime_get() - idle_start) / 1000000;
      v17 = ktime_get();
      v18 = *(_BYTE *)(v4 + 632);
      idle_time_1 += (v17 - idle_start) / 1000000;
      if ( (v18 & 1) == 0 && !*(_DWORD *)(v4 + 708) )
      {
        v19 = *(_QWORD *)(v4 + 472);
        if ( v19 )
        {
          v20 = *(_QWORD *)(v19 + 16);
          v21 = _msecs_to_jiffies(*(unsigned int *)(v4 + 3200));
          queue_delayed_work_on(32, v20, v4 + 528, v21);
        }
      }
LABEL_86:
      result = 0;
      *(_DWORD *)(v4 + 504) = v8 & 1;
      goto LABEL_87;
    }
    if ( *(_DWORD *)(lock + 84) == 2 )
    {
      ufs_qcom_phy_set_src_clk_h8_enter(*(_QWORD *)(v4 + 8));
      if ( *(_BYTE *)(v4 + 128) == 1 )
      {
        v23 = *(_QWORD *)(v4 + 120);
        if ( v23 )
        {
          clk_disable(*(_QWORD *)(v4 + 120));
          clk_unprepare(v23);
        }
        v24 = *(_QWORD *)(v4 + 104);
        clk_disable(v24);
        clk_unprepare(v24);
        v25 = *(_QWORD *)(v4 + 112);
        if ( v25 )
        {
          clk_disable(*(_QWORD *)(v4 + 112));
          clk_unprepare(v25);
        }
        v26 = *(_QWORD *)(v4 + 96);
        clk_disable(v26);
        clk_unprepare(v26);
        *(_BYTE *)(v4 + 128) = 0;
      }
    }
    v27 = *(_QWORD *)(*(_QWORD *)(v4 + 16) + 64LL);
    v28 = icc_set_bw(*(_QWORD *)(v4 + 136), 0, 0);
    if ( v28 < 0 || (v28 = icc_set_bw(*(_QWORD *)(v4 + 144), 0, 0), v28 < 0) )
      dev_err(v27, "failed to set bandwidth request: %d\n", v28);
    v29 = *(_QWORD *)(v6 + 184);
    v72 = v8;
    v30 = *(__int64 **)(v29 + 472);
    if ( v30 )
    {
      v31 = *((_DWORD *)v30 + 2);
      if ( v31 )
      {
        v32 = *v30;
        v33 = 0;
        v31 = 0;
        do
        {
          v34 = v31;
          flush_work(v32 + 32);
          v31 = v34;
          if ( *(_BYTE *)(v32 + 24) == 1 )
          {
            if ( *(_DWORD *)(v32 + 72) == 0x7FFFFFFF )
            {
              v31 = 0;
            }
            else
            {
              v35 = *(_QWORD *)(v32 + 16);
              v36 = 0;
              while ( 1 )
              {
                v37 = -1LL << v36;
                v38 = (unsigned int)v37 & *(_DWORD *)v32;
                if ( ((unsigned int)v37 & *(_DWORD *)v32) == 0 )
                {
LABEL_51:
                  v31 = 0;
                  *(_BYTE *)(v32 + 24) = 0;
                  *(_DWORD *)(v32 + 72) = 0x7FFFFFFF;
                  goto LABEL_43;
                }
                updated = dev_pm_qos_update_request(v35, 0x7FFFFFFF);
                if ( updated < 0 )
                  break;
                v35 += 80;
                v40 = __clz(__rbit64(v38));
                v41 = v40 >= 0x1F;
                v36 = v40 + 1;
                if ( v41 )
                  goto LABEL_51;
              }
              v42 = updated;
              dev_err(*(_QWORD *)(v6 + 64), "Failed (%d) removing qos grp(%d)\n", updated, v33);
              v31 = v42;
            }
          }
LABEL_43:
          ++v33;
          v32 += 80;
        }
        while ( v33 < *((_DWORD *)v30 + 2) );
        v29 = *(_QWORD *)(v6 + 184);
      }
    }
    else
    {
      v31 = 0;
    }
    v73 = v31;
    if ( (*(_BYTE *)(v29 + 632) & 1) != 0 )
      goto LABEL_85;
    cancel_delayed_work_sync(v29 + 528);
    if ( *(_QWORD *)(v29 + 728) && *(_BYTE *)(v29 + 3139) == 1 )
      walt_unset_enforce_high_irq_cpus(v29 + 728);
    unlock = sched_set_boost(4294967292LL);
    if ( *(_BYTE *)(v29 + 524) != 1 || (*(_DWORD *)(v29 + 520) = 0, *(int *)(v29 + 648) < 1) )
    {
LABEL_85:
      v8 = v72;
      idle_start = ktime_get();
      result = v73;
      if ( v73 )
        goto LABEL_87;
      goto LABEL_86;
    }
    v5 = 0;
    v55 = 0;
    while ( 1 )
    {
      v56 = (unsigned int *)(*(_QWORD *)(v29 + 640) + v5);
      v57 = *v56;
      v58 = v56[2];
      lock = cpus_read_lock(unlock);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask + ((v57 >> 3) & 0x1FFFFFF8)) >> v57) & 1) == 0 )
        break;
      if ( (unsigned int)v57 >= 0x20 )
      {
        __break(0x5512u);
        goto LABEL_104;
      }
      v59 = freq_qos_update_request((char *)&qos_min_req + _per_cpu_offset[v57], v58);
      v60 = v59;
      unlock = cpus_read_unlock(v59);
      if ( (v60 & 0x80000000) == 0 )
        goto LABEL_83;
      unlock = dev_err(*(_QWORD *)(v6 + 64), "fail set cpufreq-fmin_def %d\n", v60);
LABEL_84:
      ++v55;
      v5 += 32;
      if ( v55 >= *(int *)(v29 + 648) )
        goto LABEL_85;
    }
    unlock = cpus_read_unlock(lock);
LABEL_83:
    *(_BYTE *)(v29 + 524) = 0;
    goto LABEL_84;
  }
LABEL_104:
  __break(0x800u);
  StatusReg = _ReadStatusReg(SP_EL0);
  v66 = lock;
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v67 = qword_17608;
    if ( qword_17608 )
    {
      do
      {
        v68 = *(void (__fastcall **)(__int64, __int64, _QWORD, __int64, _QWORD))v67;
        v69 = *(_QWORD *)(v67 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v67 - 4LL) != 1238708801 )
          __break(0x8228u);
        v68(v69, v4, v3, v5 & 1, v66);
        v70 = *(_QWORD *)(v67 + 24);
        v67 += 24;
      }
      while ( v70 );
    }
    v71 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v71;
    if ( !v71 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace();
  }
  return v66;
}
