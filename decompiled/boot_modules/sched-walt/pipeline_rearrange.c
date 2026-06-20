__int64 __fastcall pipeline_rearrange(__int64 result, int a2)
{
  _QWORD *v2; // x20
  __int64 *v3; // x19
  unsigned __int64 v6; // x11
  __int64 v7; // x15
  unsigned __int64 v8; // x21
  __int64 *v9; // x16
  unsigned __int64 v10; // x8
  __int64 v11; // x11
  unsigned __int64 v12; // x9
  unsigned int v13; // w12
  unsigned __int64 v14; // x14
  unsigned __int64 v15; // x9
  unsigned __int64 v16; // x14
  unsigned __int64 v17; // x11
  __int64 v18; // x9
  char v19; // w11
  unsigned __int64 v20; // x13
  unsigned __int64 v21; // x9
  __int64 v22; // x8
  unsigned __int64 v23; // x12
  __int64 v24; // x1
  __int64 v25; // x4
  unsigned __int64 v26; // x2
  __int64 v27; // x3
  char v28; // w5
  unsigned __int64 v29; // x5
  unsigned __int64 v30; // x5
  unsigned __int64 v31; // x6
  unsigned __int64 v32; // x8
  unsigned __int64 v33; // x10
  unsigned int v34; // w0
  unsigned __int64 v35; // x9
  int v36; // w9
  unsigned int *v37; // x10
  int v38; // w8
  unsigned __int64 v39; // x27
  unsigned int v40; // w23
  __int64 v41; // x0
  unsigned __int64 v42; // x22
  __int64 v43; // x24
  unsigned __int64 v44; // x1
  __int64 v45; // x0
  unsigned int v46; // w3
  unsigned int *v47; // x14
  unsigned __int64 v48; // x14
  unsigned __int64 v49; // x23
  __int64 v50; // x13
  _DWORD *v51; // x14
  _DWORD *v52; // x11
  unsigned __int64 v53; // x10
  unsigned __int64 v54; // x25
  unsigned __int64 v55; // x1
  __int64 v56; // x19
  unsigned __int64 v57; // x8
  unsigned __int64 v58; // x1
  unsigned __int64 v59; // x0
  unsigned __int64 v60; // x8
  unsigned __int64 v61; // x8
  unsigned __int64 v62; // x11
  unsigned __int64 v63; // x13
  __int16 v64; // w10
  int v65; // w8
  unsigned int v66; // w9
  __int64 v67; // x8
  unsigned int v68; // w9
  __int64 v69; // x8
  unsigned int v70; // w9
  __int64 v71; // x8
  int v72; // w10
  __int64 v73; // x9
  int v74; // w10
  __int64 v75; // x9
  int v76; // w10
  __int64 v77; // x9
  int v78; // w8
  unsigned int v79; // w9
  __int64 v80; // x8
  unsigned int v81; // w9
  __int64 v82; // x8
  unsigned int v83; // w9
  __int64 v84; // x8
  int v85; // w10
  __int64 v86; // x9
  int v87; // w10
  __int64 v88; // x9
  int v89; // w10
  __int64 v90; // x9
  char v91; // w0
  unsigned __int64 v93; // x11
  unsigned __int64 v95; // x11
  unsigned __int64 v97; // x10
  unsigned __int64 v103; // x11
  unsigned __int64 v105; // x11
  unsigned __int64 v107; // x10
  unsigned __int64 v110; // x10
  unsigned __int64 v113; // x10
  unsigned __int64 v116; // x10
  unsigned __int64 v119; // x10
  unsigned __int64 v122; // x10
  unsigned __int64 v125; // x10
  unsigned __int64 v128; // x10
  unsigned __int64 v131; // x10
  unsigned __int64 v134; // x10
  unsigned __int64 v137; // x10
  unsigned __int64 v140; // x10
  unsigned __int64 v143; // x10
  __int64 v144; // [xsp+10h] [xbp-60h]
  __int64 v145; // [xsp+18h] [xbp-58h]
  unsigned int v146; // [xsp+20h] [xbp-50h]
  unsigned __int64 v147; // [xsp+28h] [xbp-48h]
  unsigned __int64 v148; // [xsp+30h] [xbp-40h]
  __int64 v149; // [xsp+38h] [xbp-38h]
  __int64 v150; // [xsp+40h] [xbp-30h]
  __int64 v151; // [xsp+48h] [xbp-28h]
  __int64 v152; // [xsp+50h] [xbp-20h]
  __int64 v153; // [xsp+58h] [xbp-18h]
  __int64 v154; // [xsp+60h] [xbp-10h]
  __int64 v155; // [xsp+68h] [xbp-8h]

  v155 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v153 = 0;
  v154 = 0;
  v151 = 0;
  v152 = 0;
  v149 = 0;
  v150 = 0;
  v147 = 0;
  v148 = 0;
  if ( a2 == -1 )
    goto LABEL_155;
  v2 = (_QWORD *)result;
  LODWORD(v3) = a2;
  raw_spin_lock(&heavy_lock);
  v7 = (__int64)&prime_cluster_id;
  v8 = (unsigned __int64)&prime_cluster_id;
  v9 = sched_cluster;
  if ( (_DWORD)v3 != 1 || sysctl_single_thread_pipeline )
    goto LABEL_18;
  v10 = (unsigned int)gold_cluster_id;
  if ( (unsigned int)gold_cluster_id >= 8 )
    goto LABEL_159;
  v6 = (unsigned int)prime_cluster_id;
  _X9 = _cpu_online_mask;
  _X10 = _cpu_online_mask & *(_QWORD *)(sched_cluster[gold_cluster_id] + 24);
  v10 = (unsigned __int64)&prime_cluster_id;
  available_gold_cpus[0] = _X10;
  if ( (unsigned int)prime_cluster_id > 7 )
    goto LABEL_159;
  v11 = (unsigned int)cpus_for_pipeline & _cpu_online_mask & *(_QWORD *)(sched_cluster[prime_cluster_id] + 24);
  available_gold_cpus[0] = cpus_for_pipeline & _X10 & ~_cpu_halt_mask[0];
  _X10 = (unsigned __int64)&prime_cluster_id;
  v6 = v11 & ~_cpu_halt_mask[0];
  v10 = (unsigned __int64)&prime_cluster_id;
  available_prime_cpus[0] = v6;
  have_heavy_list = 0;
  if ( heavy_wts[0] )
  {
    v12 = *(unsigned int *)(heavy_wts[0] + 364);
    _X10 = (unsigned int)++have_heavy_list;
    if ( (_DWORD)v12 != -1 )
    {
      v13 = (unsigned int)v12 >> 6;
      _X10 = (unsigned __int64)available_gold_cpus;
      v14 = *(unsigned __int64 *)((char *)available_gold_cpus + ((v12 >> 3) & 0x1FFFFFF8)) >> v12;
      _X9 = 1LL << v12;
      v6 = v13;
      if ( (v14 & 1) != 0 )
        goto LABEL_160;
      _X10 = (unsigned __int64)&available_prime_cpus[v13];
      __asm { PRFM            #0x11, [X10] }
      do
      {
        v103 = __ldxr((unsigned __int64 *)_X10);
        v6 = v103 & ~_X9;
      }
      while ( __stxr(v6, (unsigned __int64 *)_X10) );
    }
  }
  while ( 1 )
  {
    if ( qword_699A8 )
    {
      v15 = *(unsigned int *)(qword_699A8 + 364);
      _X10 = (unsigned int)(*(_DWORD *)(v10 + 2488) + 1);
      *(_DWORD *)(v10 + 2488) = _X10;
      if ( (_DWORD)v15 != -1 )
      {
        v16 = *(unsigned __int64 *)((char *)available_gold_cpus + ((v15 >> 3) & 0x1FFFFFF8)) >> v15;
        v17 = v15 >> 6;
        v18 = 1LL << v15;
        if ( (v16 & 1) != 0 )
        {
          _X10 = (unsigned __int64)&available_gold_cpus[v17];
          __asm { PRFM            #0x11, [X10] }
          do
          {
            v95 = __ldxr((unsigned __int64 *)_X10);
            v6 = v95 & ~v18;
          }
          while ( __stxr(v6, (unsigned __int64 *)_X10) );
        }
        else
        {
          _X10 = (unsigned __int64)&available_prime_cpus[v17];
          __asm { PRFM            #0x11, [X10] }
          do
          {
            v105 = __ldxr((unsigned __int64 *)_X10);
            v6 = v105 & ~v18;
          }
          while ( __stxr(v6, (unsigned __int64 *)_X10) );
        }
      }
    }
    _X9 = *(_QWORD *)(v7 + 2480);
    if ( _X9 )
    {
      _X9 = *(unsigned int *)(_X9 + 364);
      _X10 = (unsigned int)(*(_DWORD *)(v10 + 2488) + 1);
      *(_DWORD *)(v10 + 2488) = _X10;
      if ( (_DWORD)_X9 != -1 )
      {
        v19 = _X9;
        v20 = *(unsigned __int64 *)((char *)available_gold_cpus + ((_X9 >> 3) & 0x1FFFFFF8)) >> _X9;
        v21 = _X9 >> 6;
        v22 = 1LL << v19;
        if ( (v20 & 1) != 0 )
        {
          _X9 = (unsigned __int64)&available_gold_cpus[v21];
          __asm { PRFM            #0x11, [X9] }
          do
          {
            v97 = __ldxr((unsigned __int64 *)_X9);
            _X10 = v97 & ~v22;
            v6 = __stxr(_X10, (unsigned __int64 *)_X9);
          }
          while ( (_DWORD)v6 );
        }
        else
        {
          _X9 = (unsigned __int64)&available_prime_cpus[v21];
          __asm { PRFM            #0x11, [X9] }
          do
          {
            v107 = __ldxr((unsigned __int64 *)_X9);
            _X10 = v107 & ~v22;
            v6 = __stxr(_X10, (unsigned __int64 *)_X9);
          }
          while ( (_DWORD)v6 );
        }
      }
    }
LABEL_18:
    if ( !*(_QWORD *)(v7 + 2480) )
    {
LABEL_21:
      rearrange_heavy(v2[8], 0);
      goto LABEL_154;
    }
    v10 = *(unsigned int *)v8;
    if ( (unsigned int)v10 > 7 )
      goto LABEL_159;
    if ( (unsigned int)_sw_hweight64(*(unsigned int *)(v9[v10] + 24)) == 1 )
      goto LABEL_21;
    if ( !(_DWORD)v3 )
      goto LABEL_154;
    _X9 = (unsigned __int64)&cluster_head;
    _X10 = cluster_head;
    v10 = (unsigned int)gold_cluster_id;
    v2 = &unk_6B000;
    v3 = sched_cluster;
    if ( (__int64 *)cluster_head != &cluster_head )
    {
      v6 = *(unsigned int *)v8;
      v23 = (unsigned int)walt_scale_demand_divisor;
      v7 = -1;
      v9 = (__int64 *)&_per_cpu_offset;
      do
      {
        v24 = *(unsigned int *)(_X10 + 24);
        if ( (_DWORD)v24 == (_DWORD)v10 || (_DWORD)v24 == (_DWORD)v6 )
        {
          if ( (unsigned int)v24 > 3 )
            goto LABEL_159;
          v25 = *(_QWORD *)(_X10 + 16);
          v26 = 0;
          v27 = 0;
          v28 = 0;
          *(&v151 + v24) = 0;
          *(&v147 + v24) = 0;
          do
          {
            v29 = (unsigned int)(-1LL << v28) & (unsigned int)v25;
            if ( !(_DWORD)v29 )
              break;
            v30 = __clz(__rbit64(v29));
            if ( (((unsigned __int64)cpus_for_pipeline >> v30) & 1) == 0 )
            {
              v31 = (*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v30) + 184]
                   + *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v30) + 152])
                  / v23;
              v27 += v31;
              *(&v151 + v24) = v27;
              if ( v26 <= v31 )
                v26 = v31;
              *(&v147 + v24) = v26;
            }
            _CF = v30 >= 0x1F;
            v28 = v30 + 1;
          }
          while ( !_CF );
        }
        _X10 = *(_QWORD *)_X10;
      }
      while ( (__int64 *)_X10 != &cluster_head );
    }
    if ( (unsigned int)v10 > 7 )
      goto LABEL_159;
    _X9 = *(unsigned int *)v8;
    v32 = *(unsigned int *)(sched_cluster[v10] + 24);
    v33 = __rbit64(v32);
    _ZF = v32 == 0;
    v10 = 32;
    _X10 = __clz(v33);
    v34 = _ZF ? 32 : _X10;
    if ( (unsigned int)_X9 > 7 )
      goto LABEL_159;
    v35 = *(unsigned int *)(sched_cluster[_X9] + 24);
    _ZF = v35 == 0;
    v36 = __clz(__rbit64(v35));
    v37 = (unsigned int *)(heavy_wts[0] - 5184);
    if ( _ZF )
      v38 = 32;
    else
      v38 = v36;
    _X9 = *(unsigned int *)(heavy_wts[0] + 32);
    v146 = v38;
    if ( (_UNKNOWN *)heavy_wts[0] == &vendor_data_pad )
      v37 = (unsigned int *)&init_task;
    v10 = (unsigned int)walt_scale_demand_divisor;
    _X10 = v37[10];
    v6 = (unsigned int)(num_sched_clusters - 1);
    if ( (unsigned int)v6 >= 8 )
      goto LABEL_159;
    v8 = (unsigned int)_X9 / walt_scale_demand_divisor;
    if ( ((*(_QWORD *)(sched_cluster[(unsigned int)v6] + 24 + ((_X10 >> 3) & 0x1FFFFFF8)) >> _X10) & 1) == 0 )
      v8 = (unsigned __int16)(70 * ((unsigned int)v8 % 0x64)) / 0x64u + 70LL * ((unsigned int)v8 / 0x64);
    v3 = (__int64 *)&prime_cluster_id;
    v39 = v147;
    v40 = v34;
    v144 = v151;
    v41 = ((__int64 (*)(void))walt_cpu_energy)();
    v42 = v148;
    v43 = v152;
    v145 = v41;
    v44 = v8 <= v148 ? v148 : v8;
    v45 = ((__int64 (__fastcall *)(_QWORD, unsigned __int64, unsigned __int64))walt_cpu_energy)(v146, v44, v152 + v8);
    v10 = *(unsigned int *)(heavy_wts[0] + 364);
    if ( (v10 & 0x80000000) != 0 )
    {
      v10 = 0;
      v9 = sched_cluster;
      v46 = v40;
    }
    else
    {
      v9 = sched_cluster;
      _X9 = (unsigned int)prime_cluster_id;
      v6 = (unsigned __int64)&prime_cluster_id;
      if ( (unsigned int)prime_cluster_id > 7 )
        goto LABEL_159;
      v46 = v40;
      v10 = (*(_QWORD *)(sched_cluster[prime_cluster_id] + ((v10 >> 3) & 0x1FFFFFF8) + 24) >> v10) & 1LL;
    }
    v6 = qword_699A8;
    _X9 = *(unsigned int *)(qword_699A8 + 364);
    if ( (_X9 & 0x80000000) != 0 )
    {
      _X9 = 0;
    }
    else
    {
      _X10 = (unsigned int)prime_cluster_id;
      if ( (unsigned int)prime_cluster_id > 7 )
        goto LABEL_159;
      _X9 = (*(_QWORD *)(sched_cluster[prime_cluster_id] + ((_X9 >> 3) & 0x1FFFFFF8) + 24) >> _X9) & 1LL;
    }
    _X10 = qword_699B0;
    if ( (*(_DWORD *)(qword_699B0 + 364) & 0x80000000) == 0 && (unsigned int)prime_cluster_id > 7 )
      goto LABEL_159;
    v47 = (unsigned int *)(heavy_wts[0] - 5184);
    if ( (_UNKNOWN *)heavy_wts[0] == &vendor_data_pad )
      v47 = (unsigned int *)&init_task;
    v48 = v47[10];
    v7 = (unsigned int)(num_sched_clusters - 1);
    if ( (unsigned int)v7 >= 8 )
      goto LABEL_159;
    v49 = *(_DWORD *)(heavy_wts[0] + 32) / (unsigned int)walt_scale_demand_divisor;
    v50 = sched_cluster[(unsigned int)v7] + 24;
    if ( ((*(_QWORD *)(v50 + ((v48 >> 3) & 0x1FFFFFF8)) >> v48) & 1) == 0 )
      v49 = (unsigned __int16)(70 * ((unsigned int)v49 % 0x64)) / 0x64u + 70LL * ((unsigned int)v49 / 0x64);
    v51 = (_DWORD *)(qword_699A8 - 5184);
    if ( (_UNKNOWN *)qword_699A8 == &vendor_data_pad )
      v51 = &init_task;
    v8 = *(_DWORD *)(qword_699A8 + 32) / (unsigned int)walt_scale_demand_divisor;
    if ( ((*(_QWORD *)(v50 + (((unsigned __int64)(unsigned int)v51[10] >> 3) & 0x1FFFFFF8)) >> v51[10]) & 1) == 0 )
      v8 = (unsigned __int16)(70 * ((unsigned int)v8 % 0x64)) / 0x64u + 70LL * ((unsigned int)v8 / 0x64);
    v52 = (_DWORD *)(qword_699B0 - 5184);
    if ( (_UNKNOWN *)qword_699B0 == &vendor_data_pad )
      v52 = &init_task;
    v53 = *(_DWORD *)(qword_699B0 + 32) / (unsigned int)walt_scale_demand_divisor;
    if ( ((*(_QWORD *)(v50 + (((unsigned __int64)(unsigned int)v52[10] >> 3) & 0x1FFFFFF8)) >> v52[10]) & 1) != 0 )
      v53 = (unsigned __int16)(100 * ((unsigned int)v53 % 0x46)) / 0x46u + 100LL * ((unsigned int)v53 / 0x46);
    if ( (((unsigned int)_X9 | (unsigned int)v10 ^ 1) & 1) == 0 )
      v49 = (unsigned __int16)(115 * ((unsigned int)v49 % 0x64)) / 0x64u + 115LL * ((unsigned int)v49 / 0x64);
    if ( (((unsigned int)v10 | (unsigned int)_X9 ^ 1) & 1) == 0 )
      v8 = (unsigned __int16)(115 * ((unsigned int)v8 % 0x64)) / 0x64u + 115LL * ((unsigned int)v8 / 0x64);
    v54 = v45 + v145;
    if ( (((unsigned int)v10 | (unsigned int)_X9) & 1) == 0 )
      v49 = (unsigned __int16)(115 * (v49 % 0x64)) / 0x64u + 115 * (v49 / 0x64);
    if ( v53 <= v39 )
      v55 = v39;
    else
      v55 = v53;
    v56 = ((__int64 (__fastcall *)(_QWORD, unsigned __int64, unsigned __int64))walt_cpu_energy)(v46, v55, v53 + v144);
    if ( v49 <= v8 )
      v57 = v8;
    else
      v57 = v49;
    if ( v57 <= v42 )
      v58 = v42;
    else
      v58 = v57;
    v59 = ((__int64 (__fastcall *)(_QWORD, unsigned __int64, unsigned __int64))walt_cpu_energy)(
            v146,
            v58,
            v8 + v43 + v49);
    v2 = &unk_68000;
    v60 = v56 + 95 * (v59 / 0x64);
    v3 = (__int64 *)&prime_cluster_id;
    v61 = v60 + (unsigned __int16)(95 * (v59 % 0x64)) / 0x64u;
    if ( pipeline_rearrange_prev_config == 1 )
      v62 = v54;
    else
      v62 = v61;
    v63 = v62 / 0x64;
    v64 = v62 % 0x64;
    v6 = 94;
    _X10 = (unsigned __int16)(94 * v64) / 0x64u + 94 * v63;
    if ( !_X10 )
      _X10 = -1;
    if ( (pipeline_rearrange_prev_config != 1 || _X10 >= v61)
      && (pipeline_rearrange_prev_config != 2 || v54 >= _X10)
      && (pipeline_rearrange_prev_config || v54 >= v61) )
    {
      break;
    }
    v65 = sysctl_pipeline_force_config;
    v7 = (__int64)&prime_cluster_id;
    v9 = (__int64 *)&prime_cluster_id;
    if ( sysctl_pipeline_force_config )
      goto LABEL_102;
LABEL_103:
    v10 = *(unsigned int *)(qword_699B0 + 364);
    if ( (_DWORD)v10 != -1 )
    {
      _X9 = (unsigned int)prime_cluster_id;
      if ( (unsigned int)prime_cluster_id > 7 )
        goto LABEL_159;
      _X10 = (v10 >> 3) & 0x1FFFFFF8;
      if ( ((*(_QWORD *)(sched_cluster[prime_cluster_id] + _X10 + 24) >> v10) & 1) != 0 )
      {
        v66 = (unsigned int)v10 >> 6;
        v67 = 1LL << v10;
        _X9 = (unsigned __int64 *)&available_prime_cpus[v66];
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v110 = __ldxr(_X9);
          _X10 = v110 | v67;
          v6 = __stxr(_X10, _X9);
        }
        while ( (_DWORD)v6 );
        *(_DWORD *)(qword_699B0 + 364) = -1;
      }
    }
    v10 = *(unsigned int *)(qword_699A8 + 364);
    if ( (_DWORD)v10 != -1 )
    {
      _X9 = (unsigned int)prime_cluster_id;
      if ( (unsigned int)prime_cluster_id > 7 )
        goto LABEL_159;
      _X10 = (v10 >> 3) & 0x1FFFFFF8;
      if ( ((*(_QWORD *)(sched_cluster[prime_cluster_id] + _X10 + 24) >> v10) & 1) != 0 )
      {
        v68 = (unsigned int)v10 >> 6;
        v69 = 1LL << v10;
        _X9 = (unsigned __int64 *)&available_prime_cpus[v68];
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v113 = __ldxr(_X9);
          _X10 = v113 | v69;
          v6 = __stxr(_X10, _X9);
        }
        while ( (_DWORD)v6 );
        *(_DWORD *)(qword_699A8 + 364) = -1;
      }
    }
    v10 = *(unsigned int *)(heavy_wts[0] + 364);
    if ( (_DWORD)v10 == -1 )
      goto LABEL_115;
    _X9 = (unsigned int)gold_cluster_id;
    if ( (unsigned int)gold_cluster_id <= 7 )
    {
      if ( ((*(_QWORD *)(sched_cluster[gold_cluster_id] + ((v10 >> 3) & 0x1FFFFFF8) + 24) >> v10) & 1) != 0 )
      {
        v70 = (unsigned int)v10 >> 6;
        v71 = 1LL << v10;
        _X9 = (unsigned __int64 *)&available_gold_cpus[v70];
        __asm { PRFM            #0x11, [X9] }
        do
          v116 = __ldxr(_X9);
        while ( __stxr(v116 | v71, _X9) );
        *(_DWORD *)(heavy_wts[0] + 364) = -1;
      }
LABEL_115:
      if ( *(_DWORD *)(qword_699B0 + 364) == -1 )
      {
        v72 = __clz(__rbit64(LODWORD(available_gold_cpus[0])));
        if ( !LODWORD(available_gold_cpus[0]) )
          v72 = 32;
        v73 = 1LL << v72;
        *(_DWORD *)(qword_699B0 + 364) = v72;
        _X8 = available_gold_cpus;
        __asm { PRFM            #0x11, [X8] }
        do
          v119 = __ldxr((unsigned __int64 *)available_gold_cpus);
        while ( __stxr(v119 & ~v73, (unsigned __int64 *)available_gold_cpus) );
      }
      if ( *(_DWORD *)(qword_699A8 + 364) == -1 )
      {
        v74 = __clz(__rbit64(LODWORD(available_gold_cpus[0])));
        if ( !LODWORD(available_gold_cpus[0]) )
          v74 = 32;
        v75 = 1LL << v74;
        *(_DWORD *)(qword_699A8 + 364) = v74;
        _X8 = available_gold_cpus;
        __asm { PRFM            #0x11, [X8] }
        do
          v122 = __ldxr((unsigned __int64 *)available_gold_cpus);
        while ( __stxr(v122 & ~v75, (unsigned __int64 *)available_gold_cpus) );
      }
      if ( *(_DWORD *)(heavy_wts[0] + 364) == -1 )
      {
        v76 = __clz(__rbit64(LODWORD(available_prime_cpus[0])));
        if ( !LODWORD(available_prime_cpus[0]) )
          v76 = 32;
        v77 = 1LL << v76;
        *(_DWORD *)(heavy_wts[0] + 364) = v76;
        _X8 = available_prime_cpus;
        __asm { PRFM            #0x11, [X8] }
        do
          v125 = __ldxr((unsigned __int64 *)available_prime_cpus);
        while ( __stxr(v125 & ~v77, (unsigned __int64 *)available_prime_cpus) );
      }
      v78 = 1;
      goto LABEL_153;
    }
LABEL_159:
    __break(0x5512u);
LABEL_160:
    _X10 += 8 * v6;
    __asm { PRFM            #0x11, [X10] }
    do
    {
      v93 = __ldxr((unsigned __int64 *)_X10);
      v6 = v93 & ~_X9;
    }
    while ( __stxr(v6, (unsigned __int64 *)_X10) );
  }
  v91 = should_pipeline_pin_special(v59);
  v65 = sysctl_pipeline_force_config;
  v9 = (__int64 *)&prime_cluster_id;
  v7 = (__int64)&prime_cluster_id;
  if ( (v91 & 1) != 0 && !sysctl_pipeline_force_config )
    goto LABEL_103;
LABEL_102:
  if ( v65 == 1 )
    goto LABEL_103;
  v10 = *(unsigned int *)(qword_699B0 + 364);
  if ( (_DWORD)v10 != -1 )
  {
    _X9 = (unsigned int)prime_cluster_id;
    if ( (unsigned int)prime_cluster_id > 7 )
      goto LABEL_159;
    _X10 = (v10 >> 3) & 0x1FFFFFF8;
    if ( ((*(_QWORD *)(sched_cluster[prime_cluster_id] + _X10 + 24) >> v10) & 1) != 0 )
    {
      v79 = (unsigned int)v10 >> 6;
      v80 = 1LL << v10;
      _X9 = (unsigned __int64 *)&available_prime_cpus[v79];
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v128 = __ldxr(_X9);
        _X10 = v128 | v80;
        v6 = __stxr(_X10, _X9);
      }
      while ( (_DWORD)v6 );
      *(_DWORD *)(qword_699B0 + 364) = -1;
    }
  }
  v10 = *(unsigned int *)(heavy_wts[0] + 364);
  if ( (_DWORD)v10 != -1 )
  {
    _X9 = (unsigned int)gold_cluster_id;
    if ( (unsigned int)gold_cluster_id > 7 )
      goto LABEL_159;
    _X10 = (v10 >> 3) & 0x1FFFFFF8;
    if ( ((*(_QWORD *)(sched_cluster[gold_cluster_id] + _X10 + 24) >> v10) & 1) != 0 )
    {
      v81 = (unsigned int)v10 >> 6;
      v82 = 1LL << v10;
      _X9 = (unsigned __int64 *)&available_gold_cpus[v81];
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v131 = __ldxr(_X9);
        _X10 = v131 | v82;
        v6 = __stxr(_X10, _X9);
      }
      while ( (_DWORD)v6 );
      *(_DWORD *)(heavy_wts[0] + 364) = -1;
    }
  }
  v10 = *(unsigned int *)(qword_699A8 + 364);
  if ( (_DWORD)v10 == -1 )
    goto LABEL_140;
  _X9 = (unsigned int)gold_cluster_id;
  if ( (unsigned int)gold_cluster_id > 7 )
    goto LABEL_159;
  if ( ((*(_QWORD *)(sched_cluster[gold_cluster_id] + ((v10 >> 3) & 0x1FFFFFF8) + 24) >> v10) & 1) != 0 )
  {
    v83 = (unsigned int)v10 >> 6;
    v84 = 1LL << v10;
    _X9 = (unsigned __int64 *)&available_gold_cpus[v83];
    __asm { PRFM            #0x11, [X9] }
    do
      v134 = __ldxr(_X9);
    while ( __stxr(v134 | v84, _X9) );
    *(_DWORD *)(qword_699A8 + 364) = -1;
  }
LABEL_140:
  if ( *(_DWORD *)(qword_699B0 + 364) == -1 )
  {
    v85 = __clz(__rbit64(LODWORD(available_gold_cpus[0])));
    if ( !LODWORD(available_gold_cpus[0]) )
      v85 = 32;
    v86 = 1LL << v85;
    *(_DWORD *)(qword_699B0 + 364) = v85;
    _X8 = available_gold_cpus;
    __asm { PRFM            #0x11, [X8] }
    do
      v137 = __ldxr((unsigned __int64 *)available_gold_cpus);
    while ( __stxr(v137 & ~v86, (unsigned __int64 *)available_gold_cpus) );
  }
  if ( *(_DWORD *)(heavy_wts[0] + 364) == -1 )
  {
    v87 = __clz(__rbit64(LODWORD(available_prime_cpus[0])));
    if ( !LODWORD(available_prime_cpus[0]) )
      v87 = 32;
    v88 = 1LL << v87;
    *(_DWORD *)(heavy_wts[0] + 364) = v87;
    _X8 = available_prime_cpus;
    __asm { PRFM            #0x11, [X8] }
    do
      v140 = __ldxr((unsigned __int64 *)available_prime_cpus);
    while ( __stxr(v140 & ~v88, (unsigned __int64 *)available_prime_cpus) );
  }
  if ( *(_DWORD *)(qword_699A8 + 364) == -1 )
  {
    v89 = __clz(__rbit64(LODWORD(available_prime_cpus[0])));
    if ( !LODWORD(available_prime_cpus[0]) )
      v89 = 32;
    v90 = 1LL << v89;
    *(_DWORD *)(qword_699A8 + 364) = v89;
    _X8 = available_prime_cpus;
    __asm { PRFM            #0x11, [X8] }
    do
      v143 = __ldxr((unsigned __int64 *)available_prime_cpus);
    while ( __stxr(v143 & ~v90, (unsigned __int64 *)available_prime_cpus) );
  }
  v78 = 2;
LABEL_153:
  pipeline_rearrange_prev_config = v78;
LABEL_154:
  result = raw_spin_unlock(&heavy_lock);
LABEL_155:
  _ReadStatusReg(SP_EL0);
  return result;
}
