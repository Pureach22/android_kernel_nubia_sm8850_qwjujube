unsigned __int64 __fastcall rearrange_heavy(unsigned __int64 result, char a2)
{
  __int64 v4; // x10
  _BOOL4 v5; // w13
  _DWORD *v6; // x10
  _DWORD *v7; // x12
  _DWORD *v8; // x16
  unsigned int v9; // w17
  int v10; // w12
  unsigned __int64 v11; // x2
  _DWORD *v12; // x9
  char *v13; // x13
  unsigned int v14; // w9
  unsigned __int64 v15; // x9
  __int64 v16; // x19
  char v17; // w25
  unsigned __int64 v18; // x20
  unsigned __int64 v19; // x28
  unsigned int v20; // w9
  unsigned int v21; // w8
  __int64 v22; // x9
  unsigned int v23; // w9
  __int64 v24; // x8
  unsigned int v25; // w9
  unsigned int v26; // w8
  __int64 v27; // x9
  unsigned __int64 v30; // x9
  unsigned __int64 v33; // x11
  unsigned __int64 v36; // x8
  unsigned __int64 v42; // x11
  unsigned __int64 v45; // x8
  int v46; // w12
  unsigned int v47; // w14
  __int64 v48; // x9
  int v49; // w10
  __int64 v50; // x8
  __int64 *v51; // x6
  __int64 v52; // x4
  __int64 v53; // x5
  unsigned int *v54; // x6
  unsigned __int64 v55; // x6
  unsigned __int64 v56; // x5
  char *v57; // x19
  char *v58; // x0
  unsigned int v59; // w9
  __int64 v60; // x1
  char v61; // w21
  __int64 v62; // x20
  __int64 v63; // [xsp+0h] [xbp-30h] BYREF
  char *v64; // [xsp+8h] [xbp-28h] BYREF
  char v65[8]; // [xsp+10h] [xbp-20h] BYREF
  unsigned __int64 v66; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v67[2]; // [xsp+20h] [xbp-10h] BYREF

  v67[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v63 = 0;
  v64 = nullptr;
  v67[0] = 0;
  v66 = 0;
  if ( sched_boost_type )
    goto LABEL_106;
  if ( !pipeline_nr )
  {
    _ZF = !(sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres) || have_heavy_list == 0;
    if ( _ZF )
      goto LABEL_106;
  }
  if ( sysctl_single_thread_pipeline || num_sched_clusters < 2 )
    goto LABEL_106;
  if ( pipeline_special_task )
  {
    v4 = soc_flags & 0x800 | qword_699B0;
    v5 = v4 != 0;
    if ( v4 )
    {
      v6 = &init_task;
      v7 = (_DWORD *)(pipeline_special_task + 5184);
      if ( (_UNKNOWN *)pipeline_special_task == &init_task )
        v7 = &vendor_data_pad;
      v8 = v7 - 1296;
      if ( v7 == (_DWORD *)&vendor_data_pad )
        v8 = &init_task;
      v9 = v7[8];
      v10 = num_sched_clusters - 1;
      if ( (unsigned int)(num_sched_clusters - 1) >= 8 )
LABEL_109:
        __break(0x5512u);
      v11 = v9 / walt_scale_demand_divisor;
      if ( ((*(_QWORD *)(sched_cluster[v10] + (((unsigned __int64)(unsigned int)v8[10] >> 3) & 0x1FFFFFF8) + 24) >> v8[10])
          & 1) != 0 )
        v11 = (unsigned __int16)(100 * ((unsigned int)v11 % 0x46)) / 0x46u + 100LL * ((unsigned int)v11 / 0x46);
      if ( v11 < (unsigned int)sysctl_pipeline_special_task_util_thres && (soc_flags & 0x800) != 0 )
        goto LABEL_106;
      if ( have_heavy_list >= 3 )
      {
        if ( v5 )
        {
          if ( (_UNKNOWN *)pipeline_special_task == &init_task )
            v12 = &vendor_data_pad;
          else
            v12 = (_DWORD *)(pipeline_special_task + 5184);
          v13 = (char *)(v12 - 1296);
          _ZF = v12 == (_DWORD *)&vendor_data_pad;
          v14 = v12[8];
          if ( !_ZF )
            v6 = v13;
          v15 = v14 / walt_scale_demand_divisor;
          if ( ((*(_QWORD *)(sched_cluster[v10] + (((unsigned __int64)(unsigned int)v6[10] >> 3) & 0x1FFFFFF8) + 24) >> v6[10])
              & 1) != 0 )
            v15 = (unsigned __int16)(100 * ((unsigned int)v15 % 0x46)) / 0x46u + 100LL * ((unsigned int)v15 / 0x46);
          if ( v15 < (unsigned int)sysctl_pipeline_special_task_util_thres )
            goto LABEL_106;
        }
        goto LABEL_71;
      }
LABEL_35:
      v16 = 0;
      v17 = 0;
      while ( 1 )
      {
        result = heavy_wts[v16];
        if ( result )
        {
          v18 = *(unsigned int *)(result + 364);
          if ( (v18 & 0x80000000) != 0 )
          {
            v23 = __clz(__rbit64(LODWORD(available_gold_cpus[0])));
            if ( !LODWORD(available_gold_cpus[0]) )
              v23 = 32;
            if ( v23 < nr_cpu_ids )
            {
              v24 = 1LL << v23;
              *(_DWORD *)(result + 364) = v23;
              _X11 = available_gold_cpus;
              __asm { PRFM            #0x11, [X11] }
              do
                v30 = __ldxr((unsigned __int64 *)available_gold_cpus);
              while ( __stxr(v30 & ~v24, (unsigned __int64 *)available_gold_cpus) );
            }
          }
          else
          {
            if ( (unsigned int)prime_cluster_id > 7 )
              goto LABEL_109;
            v19 = v18 >> 6;
            if ( (*(_QWORD *)(sched_cluster[prime_cluster_id] + 8 * (v18 >> 6) + 24) & (1LL << v18)) != 0
              && (result = ((__int64 (*)(void))is_prime_worthy)(), (result & 1) == 0) )
            {
              v25 = __clz(__rbit64(LODWORD(available_gold_cpus[0])));
              if ( LODWORD(available_gold_cpus[0]) )
                v26 = v25;
              else
                v26 = 32;
              if ( v26 < nr_cpu_ids )
              {
                _X10 = (unsigned __int64 *)&available_prime_cpus[v19];
                __asm { PRFM            #0x11, [X10] }
                do
                  v33 = __ldxr(_X10);
                while ( __stxr(v33 | (1LL << v18), _X10) );
                v27 = 1LL << v26;
                *(_DWORD *)(heavy_wts[v16] + 364) = v26;
                _X11 = available_gold_cpus;
                __asm { PRFM            #0x11, [X11] }
                do
                  v36 = __ldxr((unsigned __int64 *)available_gold_cpus);
                while ( __stxr(v36 & ~v27, (unsigned __int64 *)available_gold_cpus) );
              }
            }
            else
            {
              if ( (unsigned int)gold_cluster_id > 7 )
                goto LABEL_109;
              if ( !(((*(_QWORD *)(sched_cluster[gold_cluster_id] + 8 * v19 + 24) & (1LL << v18)) == 0) | v17 & 1) )
              {
                result = is_prime_worthy(heavy_wts[v16]);
                if ( (result & 1) != 0
                  && ((v20 = __clz(__rbit64(LODWORD(available_prime_cpus[0]))), LODWORD(available_prime_cpus[0]))
                    ? (v21 = v20)
                    : (v21 = 32),
                      v21 < nr_cpu_ids) )
                {
                  _X10 = (unsigned __int64 *)&available_gold_cpus[v19];
                  __asm { PRFM            #0x11, [X10] }
                  do
                    v42 = __ldxr(_X10);
                  while ( __stxr(v42 | (1LL << v18), _X10) );
                  v22 = 1LL << v21;
                  *(_DWORD *)(heavy_wts[v16] + 364) = v21;
                  _X11 = available_prime_cpus;
                  __asm { PRFM            #0x11, [X11] }
                  do
                    v45 = __ldxr((unsigned __int64 *)available_prime_cpus);
                  while ( __stxr(v45 & ~v22, (unsigned __int64 *)available_prime_cpus) );
                  v17 = 1;
                }
                else
                {
                  v17 = 0;
                }
              }
            }
          }
        }
        if ( ++v16 == 3 )
          goto LABEL_106;
      }
    }
    if ( have_heavy_list < 3 )
      goto LABEL_35;
  }
  else if ( have_heavy_list <= 2 )
  {
    goto LABEL_35;
  }
LABEL_71:
  if ( (a2 & 1) != 0 )
  {
    delay_rearrange_last_rearrange_ns_1 = result;
  }
  else
  {
    if ( delay_rearrange_last_rearrange_ns_1
      && delay_rearrange_last_rearrange_ns_1
       + (unsigned int)dword_DAF0 * (unsigned __int64)(unsigned int)sched_ravg_window > result )
    {
      goto LABEL_106;
    }
    delay_rearrange_last_rearrange_ns_1 = result;
    if ( (soc_flags & 0x200) == 0 )
      goto LABEL_106;
  }
  v46 = max_possible_cluster_id;
  v47 = walt_scale_demand_divisor;
  v48 = 0;
  v49 = 0;
  v50 = (unsigned int)(num_sched_clusters - 1);
  result = 1374389535;
  do
  {
    v52 = heavy_wts[v48];
    if ( v52 )
    {
      v53 = *(unsigned int *)(v52 + 364);
      if ( (v53 & 0x80000000) == 0 )
      {
        if ( (unsigned int)v53 >= 0x20 )
          goto LABEL_109;
        if ( *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v53) + 8] + 32LL) == v46 )
        {
          v51 = (__int64 *)&v64;
LABEL_75:
          *v51 = v52;
          goto LABEL_76;
        }
        if ( (_UNKNOWN *)v52 == &vendor_data_pad )
          v54 = (unsigned int *)&init_task;
        else
          v54 = (unsigned int *)(v52 - 5184);
        v55 = v54[10];
        if ( (unsigned int)v50 >= 8 )
          goto LABEL_109;
        v56 = *(_DWORD *)(v52 + 32) / v47;
        if ( ((*(_QWORD *)(sched_cluster[v50] + ((v55 >> 3) & 0x1FFFFFF8) + 24) >> v55) & 1) != 0 )
        {
          if ( v56 > v49 )
            goto LABEL_89;
        }
        else
        {
          v56 = (unsigned __int16)(70 * ((unsigned int)v56 % 0x64)) / 0x64u + 70LL * ((unsigned int)v56 / 0x64);
          if ( v56 > v49 )
          {
LABEL_89:
            v51 = &v63;
            v49 = v56;
            goto LABEL_75;
          }
        }
      }
    }
LABEL_76:
    ++v48;
  }
  while ( v48 != 3 );
  v57 = v64;
  if ( v64 )
  {
    ((void (__fastcall *)(char *, char *, _QWORD *, __int64))pipeline_demand)(v64, v65, v67, 5243);
    if ( v57 == (char *)&vendor_data_pad )
      v58 = (char *)&init_task;
    else
      v58 = v57 - 5184;
    v59 = 63 - __clz(*(unsigned int *)(*(_QWORD *)cpu_array + 8LL * (num_sched_clusters - 2)));
    if ( *(_DWORD *)(*(_QWORD *)cpu_array + 8LL * (num_sched_clusters - 2)) )
      v60 = v59;
    else
      v60 = 32;
    result = task_fits_capacity_1(v58, v60);
    v61 = result;
    v62 = v63;
    if ( v63 )
LABEL_98:
      result = ((__int64 (__fastcall *)(__int64, char *, unsigned __int64 *))pipeline_demand)(v62, v65, &v66);
  }
  else
  {
    v61 = 1;
    v62 = v63;
    if ( v63 )
      goto LABEL_98;
  }
  if ( !pipeline_swap_util_th || (v61 & 1) != 0 && v67[0] + (unsigned __int64)(unsigned int)pipeline_swap_util_th < v66 )
    result = swap_pipeline_with_prime_locked(v57, v62);
LABEL_106:
  _ReadStatusReg(SP_EL0);
  return result;
}
