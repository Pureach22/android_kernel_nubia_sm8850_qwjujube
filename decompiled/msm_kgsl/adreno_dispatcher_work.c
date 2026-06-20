__int64 __fastcall adreno_dispatcher_work(__int64 a1)
{
  unsigned __int64 v2; // x24
  __int64 v3; // x26
  int v4; // w0
  __int64 v5; // x21
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x9
  const char *v9; // x2
  __int64 v10; // x10
  __int64 v11; // x10
  int v12; // w3
  unsigned int v19; // w9
  __int64 v20; // x22
  unsigned int v21; // w21
  int v22; // w8
  __int64 v23; // x8
  __int64 v24; // x1
  __int64 v25; // x1
  char v26; // w24
  int *v27; // x8
  int v28; // w0
  void (__fastcall *v29)(_QWORD); // x8
  __int64 v30; // x20
  unsigned __int64 v34; // x3
  unsigned __int64 v36; // x21
  int v37; // w9
  __int64 v38; // x1
  int v39; // w26
  __int64 v40; // x20
  __int64 v41; // x22
  __int64 v42; // x23
  __int64 v43; // x8
  __int64 v44; // x8
  char v45; // w23
  __int64 v46; // x25
  __int64 v47; // x1
  __int64 v48; // x3
  __int64 v49; // x0
  _DWORD *v50; // x8
  __int64 v51; // x8
  void (__fastcall *v52)(__int64, __int64); // x8
  int v54; // w25
  int v55; // w8
  int v56; // w21
  __int64 v57; // x20
  __int64 result; // x0
  unsigned __int64 v61; // x8
  unsigned int v63; // w8
  unsigned __int64 v65; // x9
  __int64 v66; // [xsp+18h] [xbp-78h]
  __int64 v67; // [xsp+18h] [xbp-78h]
  __int64 v68[14]; // [xsp+20h] [xbp-70h] BYREF

  v68[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v66 = *(_QWORD *)(*(_QWORD *)(a1 - 10144) + 40LL);
  mutex_lock(a1 - 4648);
  if ( *(_DWORD *)(a1 - 4776) )
  {
    v2 = 0;
    v3 = a1 - 10056;
    while ( 1 )
    {
      if ( v2 == 5 )
        goto LABEL_134;
      v4 = adreno_dispatch_retire_drawqueue(a1 - 24408, v3 + 208);
      if ( (v3 == -208 || *(_DWORD *)(v3 + 1236) != *(_DWORD *)(v3 + 1240))
        && v3 == *(_QWORD *)(v3 - 1320LL * *(int *)(v3 + 28) + 5288) )
      {
        if ( !v4 )
        {
          v6 = *(unsigned int *)(v3 + 1236);
          if ( (unsigned int)v6 >= 0x80 )
            goto LABEL_134;
          v7 = *(_QWORD *)(v3 + 8 * v6 + 208);
          if ( (__int64)(jiffies - *(_QWORD *)(v3 + 1248)) < 0 )
            goto LABEL_9;
          if ( *(_BYTE *)(a1 - 4736) != 1 )
            goto LABEL_9;
          if ( (*(_QWORD *)(a1 - 10168) & 0x1000) != 0 )
            goto LABEL_9;
          v8 = *(_QWORD *)(v7 + 8);
          if ( (*(_BYTE *)(v8 + 201) & 2) != 0 )
            goto LABEL_9;
          if ( v8 )
          {
            v10 = *(_QWORD *)(v8 + 24);
            if ( v10 )
              v9 = (const char *)(v10 + 16);
            else
              v9 = "unknown";
          }
          else
          {
            v9 = "unknown";
            v10 = 0x183560000F4F68LL;
          }
          v11 = *(_QWORD *)(v10 + 8);
          if ( v11 )
            v12 = *(_DWORD *)(v11 + 112);
          else
            v12 = 0;
          dev_err(
            *(_QWORD *)(a1 - 24408),
            "%s[%d]: gpu timeout ctx %u ts %u\n",
            v9,
            v12,
            *(_DWORD *)(v8 + 4),
            *(_DWORD *)(v7 + 20));
          _X8 = (unsigned int *)(a1 + 40);
          __asm { PRFM            #0x11, [X8] }
          do
            v19 = __ldxr(_X8);
          while ( __stxr(v19 | 4, _X8) );
          __dmb(0xAu);
        }
        v5 = jiffies;
        *(_QWORD *)(v3 + 1248) = _msecs_to_jiffies((unsigned int)adreno_drawobj_timeout) + v5;
      }
LABEL_9:
      if ( *(_DWORD *)(a1 - 4512) )
      {
        ++v2;
        v3 += 1320;
        if ( v2 < *(unsigned int *)(a1 - 4776) )
          continue;
      }
      break;
    }
  }
  kgsl_process_event_groups(a1 - 24408);
  v68[0] = 0;
  v20 = *(_QWORD *)(*(_QWORD *)(a1 - 10144) + 40LL);
  __dmb(9u);
  v21 = *(_DWORD *)(a1 + 40);
  if ( v21 )
  {
    if ( !(unsigned int)mutex_trylock(a1 - 112) )
      goto LABEL_120;
    if ( !wait_for_completion_timeout(a1 - 40, 1250) )
    {
      dev_err(*(_QWORD *)(a1 - 24408), "suspend recovery gate timeout\n");
      kthread_queue_work(*(_QWORD *)(a1 - 8), a1);
      mutex_unlock(a1 - 112);
      goto LABEL_120;
    }
    rt_mutex_lock(a1 - 13320);
    v22 = *(_DWORD *)(a1 - 13288);
    if ( v22 == 2 || v22 == 32 )
    {
      if ( (gmu_core_isenabled(a1 - 24408) & 1) != 0 )
      {
        v23 = **(_QWORD **)(*(_QWORD *)(a1 - 10144) + 40LL);
        v24 = *(unsigned int *)(v23 + 72);
        if ( (unsigned int)v24 <= 0xFFFFFFFD )
        {
          gmu_core_regwrite(a1 - 24408, v24, 0xFFFFFFFFLL);
          v23 = **(_QWORD **)(*(_QWORD *)(a1 - 10144) + 40LL);
        }
        v25 = *(unsigned int *)(v23 + 76);
        if ( (unsigned int)v25 <= 0xFFFFFFFD )
          gmu_core_regwrite(a1 - 24408, v25, 0xFFFFFFFFLL);
      }
      v26 = adreno_gx_is_on(a1 - 24408);
      if ( (v21 & 8) == 0 && (v26 & 1) != 0 && (adreno_smmu_is_stalled(a1 - 24408) & 1) != 0 )
      {
        rt_mutex_unlock(a1 - 13320);
        mutex_unlock(a1 - 112);
        dev_err(*(_QWORD *)(a1 - 24408), "SMMU is stalled without a pagefault\n");
        goto LABEL_120;
      }
      timer_delete_sync(a1 - 4592);
      if ( (*(_QWORD *)(a1 - 10168) & 0x200) != 0 )
        timer_delete_sync(a1 - 3904);
      if ( (v26 & 1) != 0 )
      {
        adreno_readreg64(a1 - 24408, 0, 1u, v68);
        v27 = *(int **)(a1 - 10144);
        if ( *(_DWORD *)(**((_QWORD **)v27 + 5) + 24LL) > 0xFFFFFFFD )
        {
          v28 = 0;
        }
        else
        {
          v28 = kgsl_regmap_read(a1 - 11208);
          v27 = *(int **)(a1 - 10144);
        }
        v37 = *v27;
        if ( (unsigned int)(*v27 - 600) > 0xFFFFFF9B || v37 == 203264 || (unsigned int)(v37 - 703) >= 0xFFFFFF99 )
          v38 = v28 | 3u;
        else
          v38 = 0;
        if ( *(_DWORD *)(**((_QWORD **)v27 + 5) + 24LL) <= 0xFFFFFFFD )
          kgsl_regmap_write(a1 - 11208, v38);
      }
      v67 = v20;
      if ( *(int *)(a1 - 4776) < 1 )
      {
        v40 = 0;
        v41 = 0;
        v46 = 0;
        v45 = 1;
        if ( (v26 & 1) == 0 )
          goto LABEL_82;
      }
      else
      {
        v39 = 0;
        v40 = 0;
        v41 = 0;
        v42 = a1 - 10056;
        do
        {
          adreno_dispatch_retire_drawqueue(a1 - 24408, v42 + 208);
          if ( v68[0] == *(_QWORD *)(*(_QWORD *)(v42 + 8) + 24LL) )
          {
            v43 = *(_QWORD *)(a1 - 4768);
            v41 = v42 + 208;
            v40 = v42;
            if ( v42 != v43 )
            {
              *(_QWORD *)(a1 - 4752) = v43;
              *(_QWORD *)(a1 - 4768) = v42;
            }
          }
          ++v39;
          v42 += 1320;
        }
        while ( v39 < *(_DWORD *)(a1 - 4776) );
        if ( v41 )
        {
          v44 = *(unsigned int *)(v41 + 1028);
          if ( (_DWORD)v44 == *(_DWORD *)(v41 + 1032) )
          {
            v45 = 0;
            v46 = 0;
            if ( (v26 & 1) == 0 )
              goto LABEL_82;
            goto LABEL_81;
          }
          if ( (unsigned int)v44 > 0x7F )
LABEL_134:
            __break(0x5512u);
          v46 = *(_QWORD *)(v41 + 8 * v44);
          v45 = 0;
          if ( (v26 & 1) == 0 )
          {
LABEL_82:
            if ( (*(_QWORD *)(a1 - 24296) & 2) == 0 && *(_BYTE *)(a1 - 4735) == 1 )
              gmu_core_dev_cooperative_reset(a1 - 24408);
            if ( (v21 & 0x80) != 0 )
              goto LABEL_98;
            if ( v46 )
            {
              if ( (*(_QWORD *)(v46 + 72) & 0x80000000) != 0 )
                goto LABEL_98;
              adreno_fault_header(a1 - 24408, v40, v46, v21);
              v47 = *(_QWORD *)(v46 + 8);
              if ( (*(_BYTE *)(v47 + 202) & 4) != 0 )
                goto LABEL_98;
              v48 = (v21 >> 5) & 1;
              v49 = a1 - 24408;
            }
            else
            {
              adreno_fault_header(a1 - 24408, v40, 0, v21);
              v49 = a1 - 24408;
              if ( (v21 & 0x20) != 0 )
              {
                gmu_core_fault_snapshot(v49, 0);
LABEL_98:
                adreno_gpufault_stats(a1 - 24408, v46, 0, v21);
                if ( (v21 & 2) != 0 )
                {
                  v50 = *(_DWORD **)(v67 + 112);
                  if ( v50 )
                  {
                    if ( *(v50 - 1) != 1163613936 )
                      __break(0x8228u);
                    ((void (__fastcall *)(__int64, _QWORD))v50)(a1 - 24408, 0);
                  }
                }
                if ( (v21 & 8) != 0 )
                {
                  v51 = *(_QWORD *)(a1 - 24320);
                  if ( v51 )
                  {
                    v52 = *(void (__fastcall **)(__int64, __int64))(v51 + 32);
                    if ( v52 )
                    {
                      if ( *((_DWORD *)v52 - 1) != -1954538307 )
                        __break(0x8228u);
                      v52(a1 - 24352, 1);
                    }
                  }
                }
                _X24 = (unsigned int *)(a1 - 3996);
                *(_DWORD *)(a1 - 4512) = 0;
                *(_BYTE *)(a1 - 13464) = 0;
                __dmb(9u);
                v54 = *(_DWORD *)(a1 - 3996);
                *(_DWORD *)(a1 - 3996) = 0;
                __dmb(0xAu);
                if ( v40 )
                {
                  kgsl_sharedmem_writel(
                    *(_QWORD *)(a1 - 24368),
                    40LL * *(int *)(v40 + 28) + 32520,
                    *(unsigned int *)(v40 + 36));
                  kgsl_sharedmem_writel(
                    *(_QWORD *)(a1 - 24368),
                    40LL * *(int *)(v40 + 28) + 32528,
                    *(unsigned int *)(v40 + 36));
                  kgsl_process_event_group(a1 - 24408, v40 + 40);
                }
                if ( (unsigned int)adreno_reset(a1 - 24408, v21) )
                {
                  __break(0x800u);
                }
                else
                {
                  *(_DWORD *)(a1 + 40) = 0;
                  __dmb(0xAu);
                  rt_mutex_unlock(a1 - 13320);
                  mutex_unlock(a1 - 112);
                  if ( (v45 & 1) == 0 )
                    recover_dispatch_q(a1 - 24408, v41, v21, LODWORD(v68[0]));
                  v55 = *(_DWORD *)(a1 - 4776);
                  if ( v55 >= 1 )
                  {
                    v56 = 0;
                    v57 = a1 - 9848;
                    do
                    {
                      if ( v57 != v41 )
                      {
                        recover_dispatch_q(a1 - 24408, v57, 0, LODWORD(v68[0]));
                        v55 = *(_DWORD *)(a1 - 4776);
                      }
                      ++v56;
                      v57 += 1320;
                    }
                    while ( v56 < v55 );
                  }
                }
                __asm { PRFM            #0x11, [X24] }
                do
                  v63 = __ldxr(_X24);
                while ( __stxr(v63 + v54, _X24) );
                goto LABEL_120;
              }
              v47 = 0;
              v48 = 0;
            }
            kgsl_device_snapshot(v49, v47, 0, v48);
            goto LABEL_98;
          }
        }
        else
        {
          v46 = 0;
          v45 = 1;
          if ( (v26 & 1) == 0 )
            goto LABEL_82;
        }
      }
LABEL_81:
      adreno_readreg64(a1 - 24408, 8u, 9u, v68);
      goto LABEL_82;
    }
    rt_mutex_unlock(a1 - 13320);
    mutex_unlock(a1 - 112);
  }
  v29 = *(void (__fastcall **)(_QWORD))(v66 + 88);
  if ( v29 )
  {
    if ( *((_DWORD *)v29 - 1) != 994519391 )
      __break(0x8228u);
    v29(a1 - 24408);
  }
  __dmb(9u);
  if ( !*(_DWORD *)(a1 + 40) )
  {
    v30 = 0;
    _X22 = (unsigned __int64 *)(a1 - 4504);
    do
    {
      _X9 = _X22 + 16;
      memset(v68, 0, 104);
      __asm { PRFM            #0x11, [X9] }
      do
        v34 = __ldxr(_X9);
      while ( __stlxr(0, _X9) );
      __dmb(0xBu);
      __asm { PRFM            #0x11, [X22] }
      do
        v36 = __ldxr(_X22);
      while ( __stlxr(0, _X22) );
      __dmb(0xBu);
      dispatcher_handle_jobs_list(a1 - 24408, (unsigned int)v30, v68, v34);
      dispatcher_handle_jobs_list(a1 - 24408, (unsigned int)v30++, v68, v36);
      ++_X22;
    }
    while ( v30 != 16 );
  }
LABEL_120:
  if ( *(_DWORD *)(a1 - 4512) )
  {
    dispatcher_update_timers(a1 - 24408);
  }
  else
  {
    rt_mutex_lock(a1 - 13320);
    _X21 = (unsigned __int64 *)(a1 - 4600);
    __asm { PRFM            #0x11, [X21] }
    do
      v61 = __ldxr(_X21);
    while ( __stlxr(v61 & 0xFFFFFFFFFFFFFFFDLL, _X21) );
    __dmb(0xBu);
    if ( (v61 & 2) != 0 )
      complete_all(a1 - 4152);
    if ( (*(_QWORD *)(a1 - 10168) & 0x200) != 0
      && *(_DWORD *)(a1 - 13468)
      && *(_BYTE *)(a1 - 13464)
      && !*(_DWORD *)(a1 - 8824) )
    {
      kgsl_bus_update(a1 - 24408, 3);
    }
    if ( (*_X21 & 1) != 0 )
    {
      adreno_active_count_put(a1 - 24408);
      __asm { PRFM            #0x11, [X21] }
      do
        v65 = __ldxr(_X21);
      while ( __stxr(v65 & 0xFFFFFFFFFFFFFFFELL, _X21) );
    }
    rt_mutex_unlock(a1 - 13320);
  }
  result = mutex_unlock(a1 - 4648);
  _ReadStatusReg(SP_EL0);
  return result;
}
