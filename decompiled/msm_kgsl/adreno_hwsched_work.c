__int64 __fastcall adreno_hwsched_work(__int64 a1)
{
  __int64 v1; // x23
  __int64 v3; // x2
  __int64 v4; // x3
  unsigned int v5; // w22
  _QWORD *v6; // x27
  __int64 *v7; // x19
  unsigned int *v8; // x26
  __int64 v9; // x1
  __int64 v10; // x0
  __int64 v11; // x2
  unsigned int v12; // w27
  __int64 v13; // x19
  int v14; // w22
  _QWORD *v15; // x22
  _QWORD *v16; // x19
  __int64 v17; // x24
  __int64 v18; // x1
  unsigned int v19; // w8
  unsigned int v20; // w9
  _QWORD *v21; // x8
  _QWORD *v22; // x9
  unsigned int v23; // w8
  unsigned int v24; // w9
  unsigned int v25; // w8
  __int64 v27; // x21
  unsigned __int64 v33; // x3
  unsigned __int64 v35; // x22
  int v36; // w21
  __int64 v37; // x21
  __int64 *v39; // x19
  unsigned int *v40; // x26
  __int64 v41; // x2
  __int64 v42; // x1
  __int64 fault_cmdobj; // x24
  unsigned __int64 v44; // x25
  __int64 v45; // x24
  __int64 v46; // x8
  __int64 *active_cmdobj; // x0
  __int64 v48; // x23
  __int64 v49; // x8
  __int64 v50; // x24
  __int64 v51; // x0
  __int64 v52; // x0
  unsigned int v54; // w8
  unsigned int v55; // t1
  unsigned int v56; // w19
  unsigned int v58; // w9
  unsigned int v60; // w8
  unsigned int v61; // w19
  unsigned int v63; // w9
  unsigned int v65; // w8
  __int64 v66; // x0
  _QWORD *v67; // x23
  _QWORD *v68; // x27
  __int64 v69; // x24
  __int64 *v70; // x27
  __int64 v71; // t1
  __int64 v72; // x1
  __int64 v74; // x19
  unsigned int v76; // w8
  unsigned int v77; // w23
  unsigned int v79; // w9
  unsigned int v80; // w8
  const char *v81; // x2
  __int64 v82; // x8
  __int64 v83; // x0
  __int64 v84; // x8
  void (__fastcall *v86)(_QWORD); // x8
  __int64 v87; // x8
  int v88; // w3
  __int64 v89; // x1
  __int64 v90; // x0
  __int64 v91; // x24
  void (__fastcall *v92)(__int64, __int64); // x8
  __int64 *v93; // x26
  __int64 v94; // x25
  __int64 v95; // x8
  _QWORD *v96; // x25
  __int64 v97; // x25
  __int64 v98; // x19
  __int64 v99; // x1
  unsigned int v100; // w23
  __int64 (__fastcall *v101)(_QWORD); // x8
  unsigned int v103; // w8
  unsigned int v104; // w8
  _DWORD *v105; // x8
  unsigned __int64 v108; // x8
  unsigned __int64 v110; // x9
  unsigned __int64 v112; // x9
  unsigned __int64 v114; // x9
  int v116; // w8
  unsigned __int64 v119; // x9
  unsigned __int64 v122; // x9
  int v124; // w8
  _DWORD *v125; // x8
  __int64 v126; // x8
  void (__fastcall *v128)(_QWORD); // x8
  __int64 result; // x0
  unsigned __int64 v131; // x9
  unsigned __int64 v133; // x9
  int v135; // w8
  unsigned __int64 v138; // x9
  unsigned __int64 v141; // x9
  unsigned __int64 v144; // x9
  unsigned __int64 v147; // x9
  unsigned __int64 v150; // x9
  __int64 v151; // [xsp+10h] [xbp-B0h]
  __int64 *v152; // [xsp+10h] [xbp-B0h]
  char v153; // [xsp+1Ch] [xbp-A4h]
  __int64 v154; // [xsp+20h] [xbp-A0h]
  __int64 v155; // [xsp+20h] [xbp-A0h]
  __int64 v156; // [xsp+30h] [xbp-90h]
  __int64 v157; // [xsp+38h] [xbp-88h]
  __int64 v158; // [xsp+38h] [xbp-88h]
  unsigned int *v159; // [xsp+38h] [xbp-88h]
  char v160; // [xsp+38h] [xbp-88h]
  int v161; // [xsp+44h] [xbp-7Ch] BYREF
  _QWORD v162[15]; // [xsp+48h] [xbp-78h] BYREF

  v1 = a1 - 1960;
  v162[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a1 - 1960);
  __dmb(9u);
  v5 = *(_DWORD *)(a1 + 40);
  if ( !v5 )
  {
    v15 = *(_QWORD **)(a1 - 1640);
    if ( v15 == (_QWORD *)(a1 - 1640) )
    {
LABEL_37:
      kgsl_process_event_groups(a1 - 24408);
      v27 = 0;
      _X19 = (unsigned __int64 *)(a1 - 1896);
      do
      {
        _X9 = _X19 + 16;
        memset(v162, 0, 104);
        __asm { PRFM            #0x11, [X9] }
        do
          v33 = __ldxr(_X9);
        while ( __stlxr(0, _X9) );
        __dmb(0xBu);
        __asm { PRFM            #0x11, [X19] }
        do
          v35 = __ldxr(_X19);
        while ( __stlxr(0, _X19) );
        __dmb(0xBu);
        hwsched_handle_jobs_list(a1 - 24408, (unsigned int)v27, v162, v33);
        hwsched_handle_jobs_list(a1 - 24408, (unsigned int)v27++, v162, v35);
        ++_X19;
      }
      while ( v27 != 16 );
      v36 = *(_DWORD *)(a1 - 1904);
      rt_mutex_lock(a1 - 13320);
      if ( v36 )
      {
        kgsl_pwrscale_update(a1 - 24408);
        v37 = jiffies;
        *(_QWORD *)(a1 - 10264) = _msecs_to_jiffies(*(_QWORD *)(a1 - 14328)) + v37;
        mod_timer(a1 - 15616);
      }
      else
      {
        _X21 = (unsigned __int64 *)(a1 - 1912);
        __asm { PRFM            #0x11, [X21] }
        do
          v108 = __ldxr(_X21);
        while ( __stlxr(v108 & 0xFFFFFFFFFFFFFFFDLL, _X21) );
        __dmb(0xBu);
        if ( (v108 & 2) != 0 )
          complete_all(a1 - 1608);
        if ( (*_X21 & 1) != 0 )
        {
          adreno_active_count_put(a1 - 24408);
          __asm { PRFM            #0x11, [X21] }
          do
            v110 = __ldxr(_X21);
          while ( __stxr(v110 & 0xFFFFFFFFFFFFFFFELL, _X21) );
        }
      }
      rt_mutex_unlock(a1 - 13320);
      goto LABEL_264;
    }
    while ( 1 )
    {
      v16 = (_QWORD *)*v15;
      v17 = *(v15 - 1);
      v18 = *(_QWORD *)(v17 + 8);
      if ( (*(_BYTE *)(v17 + 16) & 4) != 0 )
      {
        v19 = *(_DWORD *)(v17 + 20);
        v20 = *(_DWORD *)(*(_QWORD *)(v18 + 1648) + 16LL);
        if ( v19 == v20
          || (v19 <= v20 || ((v19 - v20) & 0x80000000) != 0)
          && ((v23 = v19 ^ 0x80000000, v24 = v20 ^ 0x80000000, _CF = v23 >= v24, v25 = v23 - v24, v25 != 0 && _CF)
            ? (_CF = v25 >= 0x80000001)
            : (_CF = 1),
              _CF) )
        {
          adreno_hwsched_hw_syncobj_destroy(*(v15 - 1), v18, v3, v4);
LABEL_26:
          v21 = (_QWORD *)v15[1];
          if ( (_QWORD *)*v21 == v15 && (v22 = (_QWORD *)*v15, *(_QWORD **)(*v15 + 8LL) == v15) )
          {
            v22[1] = v21;
            *v21 = v22;
          }
          else
          {
            _list_del_entry_valid_or_report(v15);
          }
          *v15 = v15;
          v15[1] = v15;
          kmem_cache_free(obj_cache, v15 - 1);
          --*(_DWORD *)(a1 - 1904);
        }
      }
      else if ( (kgsl_check_timestamp(a1 - 24408, v18, *(unsigned int *)(v17 + 20)) & 1) != 0 )
      {
        adreno_hwsched_retire_cmdobj(a1 - 3504, v17);
        goto LABEL_26;
      }
      v15 = v16;
      if ( v16 == (_QWORD *)(a1 - 1640) )
        goto LABEL_37;
    }
  }
  if ( (unsigned int)mutex_trylock(a1 - 112) )
  {
    if ( !wait_for_completion_timeout(a1 - 40, 1250) )
    {
      dev_err(*(_QWORD *)(a1 - 24408), "suspend recovery gate timeout\n");
      kthread_queue_work(*(_QWORD *)(a1 - 8), a1);
LABEL_263:
      mutex_unlock(a1 - 112);
      goto LABEL_264;
    }
    rt_mutex_lock(a1 - 13320);
    if ( *(_DWORD *)(a1 - 13288) != 2 )
    {
LABEL_262:
      kthread_queue_work(*(_QWORD *)(a1 - 8), a1);
      rt_mutex_unlock(a1 - 13320);
      goto LABEL_263;
    }
    if ( (v5 & 8) != 0
      && (adreno_gx_is_on(a1 - 24408) & 1) != 0
      && *(_DWORD *)(**(_QWORD **)(*(_QWORD *)(a1 - 10144) + 40LL) + 24LL) <= 0xFFFFFFFD )
    {
      kgsl_regmap_write(a1 - 11208, 0);
    }
    v6 = (_QWORD *)(a1 - 1912);
    if ( (*(_QWORD *)(a1 - 1912) & 4) == 0 )
    {
      v7 = (__int64 *)(a1 - 1568);
      v8 = *(unsigned int **)(a1 - 1616);
      v156 = *(_QWORD *)(*(_QWORD *)(a1 - 10144) + 40LL);
      if ( *(_QWORD *)(a1 - 1568) )
        srcu_notifier_call_chain(a1 - 10984, 2, 0);
      if ( (v5 & 8) != 0 )
        *(_DWORD *)(a1 - 968) = 2;
      v9 = v8[2];
      v10 = a1 - 24408;
      v11 = v8[4];
      if ( v8[8] == 630 )
      {
        print_fault_syncobj(v10, v9, v11);
        gmu_core_fault_snapshot(a1 - 24408, 0);
        v12 = 0;
        v13 = 0;
        v14 = -110;
        goto LABEL_251;
      }
      fault_cmdobj = get_fault_cmdobj(v10, v9, v11);
      v44 = get_fault_cmdobj(a1 - 24408, v8[5], v8[7]);
      if ( (v5 & 8) != 0 && !fault_cmdobj )
        fault_cmdobj = get_active_cmdobj(a1 - 24408);
      v154 = fault_cmdobj;
      if ( fault_cmdobj )
      {
        v45 = *(_QWORD *)fault_cmdobj;
        *(_QWORD *)(v45 + 80) = v8[3];
        goto LABEL_59;
      }
      v52 = *v7;
      if ( !*v7 || *(_DWORD *)(*(_QWORD *)(v52 + 8) + 4LL) != v8[2] )
      {
        v13 = 0;
LABEL_109:
        v153 = 1;
        goto LABEL_110;
      }
      v45 = *v7;
      v55 = *(_DWORD *)(v52 + 32);
      _X0 = v52 + 32;
      v54 = v55;
      *(_QWORD *)(_X0 + 48) = v8[3];
      if ( v55 )
      {
        do
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v58 = __ldxr((unsigned int *)_X0);
          while ( v58 == v54 && __stxr(v54 + 1, (unsigned int *)_X0) );
          v56 = v54;
          if ( v58 == v54 )
            break;
          v56 = 0;
          v54 = v58;
        }
        while ( v58 );
      }
      else
      {
        v56 = 0;
      }
      if ( (((v56 + 1) | v56) & 0x80000000) != 0 )
      {
        refcount_warn_saturate(_X0, 0);
        if ( !v56 )
          goto LABEL_107;
      }
      else if ( !v56 )
      {
LABEL_107:
        v13 = 0;
LABEL_108:
        fault_cmdobj = v154;
        goto LABEL_109;
      }
LABEL_59:
      v13 = v45;
      if ( v45 )
      {
        v46 = *(_QWORD *)(v45 + 8);
        fault_cmdobj = v154;
        if ( v46 )
        {
          _X8 = (unsigned __int64 *)(v46 + 32);
          __asm { PRFM            #0x11, [X8] }
          do
            v122 = __ldxr(_X8);
          while ( __stxr(v122 | 0x10000, _X8) );
        }
        v153 = 0;
LABEL_110:
        do_fault_header(a1 - 24408, v13, v5);
        if ( (v5 & 8) == 0 || v44 )
        {
LABEL_164:
          if ( !(fault_cmdobj | v44) )
          {
            v90 = a1 - 24408;
            if ( (v5 & 0x20) != 0 )
              gmu_core_fault_snapshot(v90, 0);
            else
              kgsl_device_snapshot(v90, 0, 0, 0);
            adreno_gpufault_stats(a1 - 24408, 0, 0, v5);
            v14 = 0;
            v12 = 0;
            *(_DWORD *)(a1 - 968) = 2;
LABEL_251:
            if ( !v13 )
            {
              v125 = *(_DWORD **)(v156 + 144);
              if ( v125 )
              {
                if ( *(v125 - 1) != -1942818466 )
                  __break(0x8228u);
                v14 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v125)(a1 - 24408, 0, v12);
              }
            }
LABEL_256:
            memset(*(void **)(a1 - 1616), 0, 0x400u);
            *(_DWORD *)(a1 - 968) = 0;
            if ( v14 )
            {
              v126 = *(_QWORD *)(*(_QWORD *)(a1 - 10144) + 40LL);
              if ( *(_QWORD *)(v126 + 136) )
              {
                _X19 = (unsigned __int64 *)(a1 - 10168);
                __asm { PRFM            #0x11, [X19] }
                do
                  v131 = __ldxr(_X19);
                while ( __stxr(v131 | 0x40000, _X19) );
                v128 = *(void (__fastcall **)(_QWORD))(v126 + 136);
                if ( *((_DWORD *)v128 - 1) != -83892780 )
                  __break(0x8228u);
                v128(a1 - 24408);
                __asm { PRFM            #0x11, [X19] }
                do
                  v133 = __ldxr(_X19);
                while ( __stxr(v133 & 0xFFFFFFFFFFFBFFFFLL, _X19) );
              }
            }
            goto LABEL_262;
          }
          if ( fault_cmdobj )
            v89 = *(_QWORD *)(v13 + 8);
          else
            v89 = 0;
          if ( v44 )
          {
            v91 = *(_QWORD *)v44;
            *(_QWORD *)(v91 + 80) = v8[6];
            v44 = *(_QWORD *)(v91 + 8);
            v92 = *(void (__fastcall **)(__int64, __int64))(v156 + 288);
            if ( v92 )
            {
              v159 = v8;
              v93 = *(__int64 **)(v91 + 8);
              v94 = v89;
              if ( *((_DWORD *)v92 - 1) != -1245822001 )
                __break(0x8228u);
              v92(a1 - 24408, v91);
              v89 = v94;
              v44 = (unsigned __int64)v93;
              v8 = v159;
            }
            if ( v91 )
            {
              v95 = *(_QWORD *)(v91 + 8);
              if ( v95 )
              {
                _X8 = (unsigned __int64 *)(v95 + 32);
                __asm { PRFM            #0x11, [X8] }
                do
                  v150 = __ldxr(_X8);
                while ( __stxr(v150 | 0x10000, _X8) );
              }
              v160 = 0;
LABEL_182:
              v155 = v89;
              kgsl_device_snapshot(a1 - 24408, v89, v44, 0);
              adreno_gpufault_stats(a1 - 24408, v13, v91, v5);
              v152 = (__int64 *)v44;
              if ( (v153 & 1) != 0 )
              {
                v96 = v6;
                v14 = 0;
                v12 = 0;
                if ( (v160 & 1) != 0 )
                  goto LABEL_251;
LABEL_184:
                if ( (*v96 & 0x20) != 0 )
                {
                  v97 = (__int64)v152;
                  _X8 = (unsigned __int64 *)(v91 + 56);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v141 = __ldxr(_X8);
                  while ( __stxr(v141 | 0x100, _X8) );
                  v98 = v1;
                  if ( !v152 )
                    goto LABEL_214;
                }
                else
                {
                  kgsl_sharedmem_writel(
                    *(_QWORD *)(a1 - 24368),
                    40LL * *(unsigned int *)(*(_QWORD *)(v91 + 8) + 4LL),
                    *(unsigned int *)(v91 + 20));
                  kgsl_sharedmem_writel(
                    *(_QWORD *)(a1 - 24368),
                    40LL * *(unsigned int *)(*(_QWORD *)(v91 + 8) + 4LL) + 8,
                    *(unsigned int *)(v91 + 20));
                  v97 = (__int64)v152;
                  v98 = v1;
                  if ( !v152 )
                    goto LABEL_214;
                }
                if ( (*(_DWORD *)(v97 + 200) & 0x10000200) != 0
                  || (v104 = v8[8], v104 == 603)
                  || v104 == 621
                  || (context_is_throttled(a1 - 24408, v97) & 1) != 0 )
                {
                  v100 = 1;
LABEL_215:
                  v105 = *(_DWORD **)(v156 + 144);
                  if ( v105 )
                  {
                    if ( *(v105 - 1) != -1942818466 )
                      __break(0x8228u);
                    v14 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v105)(a1 - 24408, v97, v100);
                  }
                  if ( v100 )
                    adreno_drawctxt_set_guilty(a1 - 24408, v97);
                  _X0 = (unsigned int *)(v91 + 32);
                  __asm { PRFM            #0x11, [X0] }
                  do
                    v135 = __ldxr(_X0);
                  while ( __stlxr(v135 - 1, _X0) );
                  v1 = v98;
                  if ( v135 == 1 )
                  {
                    __dmb(9u);
                    kgsl_drawobj_destroy_object(_X0);
                  }
                  else if ( v135 <= 0 )
                  {
                    refcount_warn_saturate(_X0, 3);
                  }
                  goto LABEL_256;
                }
LABEL_214:
                v100 = 0;
                goto LABEL_215;
              }
              if ( (*v6 & 0x20) != 0 )
              {
                _X8 = (unsigned __int64 *)(v13 + 56);
                __asm { PRFM            #0x11, [X8] }
                do
                  v144 = __ldxr(_X8);
                while ( __stxr(v144 | 0x100, _X8) );
                v99 = v155;
                if ( v155 )
                {
LABEL_189:
                  v96 = v6;
                  if ( (*(_DWORD *)(v99 + 200) & 0x10000200) != 0
                    || (v103 = v8[8], v103 == 603)
                    || v103 == 621
                    || (context_is_throttled(a1 - 24408, v155) & 1) != 0 )
                  {
                    v12 = 1;
                    goto LABEL_197;
                  }
LABEL_196:
                  v12 = 0;
LABEL_197:
                  v101 = *(__int64 (__fastcall **)(_QWORD))(v156 + 144);
                  if ( v101 )
                  {
                    if ( *((_DWORD *)v101 - 1) != -1942818466 )
                      __break(0x8228u);
                    v14 = v101(a1 - 24408);
                  }
                  else
                  {
                    v14 = 0;
                  }
                  if ( v12 )
                    adreno_drawctxt_set_guilty(a1 - 24408, v155);
                  _X0 = (unsigned int *)(v13 + 32);
                  __asm { PRFM            #0x11, [X0] }
                  do
                    v124 = __ldxr(_X0);
                  while ( __stlxr(v124 - 1, _X0) );
                  if ( v124 == 1 )
                  {
                    __dmb(9u);
                    kgsl_drawobj_destroy_object(_X0);
                    if ( (v160 & 1) != 0 )
                      goto LABEL_251;
                  }
                  else if ( v124 <= 0 )
                  {
                    refcount_warn_saturate(_X0, 3);
                    if ( (v160 & 1) != 0 )
                      goto LABEL_251;
                  }
                  else if ( (v160 & 1) != 0 )
                  {
                    goto LABEL_251;
                  }
                  goto LABEL_184;
                }
              }
              else
              {
                kgsl_sharedmem_writel(
                  *(_QWORD *)(a1 - 24368),
                  40LL * *(unsigned int *)(*(_QWORD *)(v13 + 8) + 4LL),
                  *(unsigned int *)(v13 + 20));
                kgsl_sharedmem_writel(
                  *(_QWORD *)(a1 - 24368),
                  40LL * *(unsigned int *)(*(_QWORD *)(v13 + 8) + 4LL) + 8,
                  *(unsigned int *)(v13 + 20));
                v99 = v155;
                if ( v155 )
                  goto LABEL_189;
              }
              v96 = v6;
              goto LABEL_196;
            }
          }
          else
          {
            v91 = 0;
          }
          v160 = 1;
          goto LABEL_182;
        }
        v151 = v13;
        v158 = v1;
        v67 = *(_QWORD **)(a1 - 1640);
        v161 = 0;
        LODWORD(v162[0]) = 0;
        if ( v67 != (_QWORD *)(a1 - 1640) )
        {
          v44 = 0;
          do
          {
            v68 = v67;
            v67 = (_QWORD *)*v67;
            v71 = *(v68 - 1);
            v70 = v68 - 1;
            v69 = v71;
            v72 = *(_QWORD *)(v71 + 8);
            if ( v72 )
            {
              if ( (*(_BYTE *)(v72 + 203) & 0x20) != 0 )
              {
                kgsl_readtimestamp(a1 - 24408, v72, 1, v162);
                kgsl_readtimestamp(a1 - 24408, *(_QWORD *)(v69 + 8), 2, &v161);
                if ( LODWORD(v162[0]) )
                {
                  if ( !v44 && LODWORD(v162[0]) != v161 )
                    v44 = (unsigned __int64)v70;
                }
              }
            }
          }
          while ( v67 != (_QWORD *)(a1 - 1640) );
          if ( !v44 )
          {
            v1 = v158;
            v6 = (_QWORD *)(a1 - 1912);
            fault_cmdobj = v154;
LABEL_163:
            v13 = v151;
            goto LABEL_164;
          }
          v74 = *(_QWORD *)v44;
          _X0 = (unsigned int *)(*(_QWORD *)v44 + 32LL);
          v76 = *_X0;
          v6 = (_QWORD *)(a1 - 1912);
          fault_cmdobj = v154;
          if ( *_X0 )
          {
            do
            {
              __asm { PRFM            #0x11, [X0] }
              do
                v79 = __ldxr(_X0);
              while ( v79 == v76 && __stxr(v76 + 1, _X0) );
              v77 = v76;
              if ( v79 == v76 )
                break;
              v77 = 0;
              v76 = v79;
            }
            while ( v79 );
          }
          else
          {
            v77 = 0;
          }
          if ( (((v77 + 1) | v77) & 0x80000000) != 0 )
          {
            refcount_warn_saturate(_X0, 0);
            if ( v77 )
            {
LABEL_137:
              _X8 = (unsigned __int64 *)(v74 + 56);
              __asm { PRFM            #0x11, [X8] }
              do
                v147 = __ldxr(_X8);
              while ( __stxr(v147 | 0x10, _X8) );
              goto LABEL_162;
            }
          }
          else if ( v77 )
          {
            goto LABEL_137;
          }
        }
        v44 = 0;
LABEL_162:
        v1 = v158;
        goto LABEL_163;
      }
      goto LABEL_108;
    }
    v39 = (__int64 *)(a1 - 1568);
    v40 = *(unsigned int **)(a1 - 1616);
    if ( *(_QWORD *)(a1 - 1568) )
      srcu_notifier_call_chain(a1 - 10984, 2, 0);
    v41 = v40[3];
    v42 = v40[1];
    if ( v40[4] == 630 )
    {
      print_fault_syncobj(a1 - 24408, v42, v41);
      gmu_core_fault_snapshot(a1 - 24408, 0);
      goto LABEL_148;
    }
    v157 = v1;
    active_cmdobj = (__int64 *)get_fault_cmdobj(a1 - 24408, v42, v41);
    if ( active_cmdobj || (v5 & 8) != 0 && (active_cmdobj = (__int64 *)get_active_cmdobj(a1 - 24408)) != nullptr )
    {
      v48 = *active_cmdobj;
    }
    else
    {
      v48 = *v39;
      if ( !*v39 || *(_DWORD *)(*(_QWORD *)(v48 + 8) + 4LL) != v40[1] )
        goto LABEL_144;
      _X0 = (unsigned int *)(v48 + 32);
      v60 = *(_DWORD *)(v48 + 32);
      if ( v60 )
      {
        do
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v63 = __ldxr(_X0);
          while ( v63 == v60 && __stxr(v60 + 1, _X0) );
          v61 = v60;
          if ( v63 == v60 )
            break;
          v61 = 0;
          v60 = v63;
        }
        while ( v63 );
      }
      else
      {
        v61 = 0;
      }
      if ( (((v61 + 1) | v61) & 0x80000000) != 0 )
      {
        refcount_warn_saturate(_X0, 0);
        if ( !v61 )
          goto LABEL_144;
      }
      else if ( !v61 )
      {
        goto LABEL_144;
      }
    }
    if ( v48 )
    {
      v49 = *(_QWORD *)(v48 + 8);
      if ( v49 )
      {
        _X8 = (unsigned __int64 *)(v49 + 32);
        __asm { PRFM            #0x11, [X8] }
        do
          v119 = __ldxr(_X8);
        while ( __stxr(v119 | 0x10000, _X8) );
      }
      adreno_gpufault_stats(a1 - 24408, v48, 0, v5);
      v50 = *(_QWORD *)(v48 + 8);
      do_fault_header(a1 - 24408, v48, v5);
      v51 = kgsl_device_snapshot(a1 - 24408, v50, 0, 0);
      if ( (*v6 & 0x20) != 0 )
      {
        _X8 = (unsigned __int64 *)(v48 + 56);
        __asm { PRFM            #0x11, [X8] }
        do
          v138 = __ldxr(_X8);
        while ( __stxr(v138 | 0x100, _X8) );
      }
      else
      {
        kgsl_sharedmem_writel(
          *(_QWORD *)(a1 - 24368),
          40LL * *(unsigned int *)(*(_QWORD *)(v48 + 8) + 4LL),
          *(unsigned int *)(v48 + 20));
        v51 = kgsl_sharedmem_writel(
                *(_QWORD *)(a1 - 24368),
                40LL * *(unsigned int *)(*(_QWORD *)(v48 + 8) + 4LL) + 8,
                *(unsigned int *)(v48 + 20));
      }
      if ( (*(_DWORD *)(v50 + 200) & 0x10000200) == 0 )
      {
        v65 = v40[4];
        if ( v65 != 603 && v65 != 621 )
        {
          v66 = ktime_get(v51);
          if ( v66 - *(_QWORD *)(v50 + 264) >= 2001000000 )
          {
            *(_QWORD *)(v50 + 264) = ktime_get(v66);
            *(_DWORD *)(v50 + 256) = 1;
            goto LABEL_95;
          }
          v80 = *(_DWORD *)(v50 + 256) + 1;
          *(_DWORD *)(v50 + 256) = v80;
          if ( v80 < 4 )
            goto LABEL_95;
          if ( v50 )
          {
            v82 = *(_QWORD *)(v50 + 24);
            if ( v82 )
              v81 = (const char *)(v82 + 16);
            else
              v81 = "unknown";
          }
          else
          {
            v81 = "unknown";
            v82 = 0x183560000F4F68LL;
          }
          v87 = *(_QWORD *)(v82 + 8);
          if ( v87 )
            v88 = *(_DWORD *)(v87 + 112);
          else
            v88 = 0;
          dev_err(
            *(_QWORD *)(a1 - 24408),
            "%s[%d]: gpu fault threshold exceeded %d faults in %d msecs\n",
            v81,
            v88,
            3,
            2000);
        }
      }
      adreno_drawctxt_set_guilty(a1 - 24408, v50);
LABEL_95:
      _X0 = (unsigned int *)(v48 + 32);
      __asm { PRFM            #0x11, [X0] }
      do
        v116 = __ldxr(_X0);
      while ( __stlxr(v116 - 1, _X0) );
      v1 = v157;
      if ( v116 == 1 )
      {
        __dmb(9u);
        kgsl_drawobj_destroy_object(_X0);
      }
      else if ( v116 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
      goto LABEL_148;
    }
LABEL_144:
    adreno_gpufault_stats(a1 - 24408, 0, 0, v5);
    v83 = a1 - 24408;
    if ( (v5 & 0x20) != 0 )
      gmu_core_fault_snapshot(v83, 0);
    else
      kgsl_device_snapshot(v83, 0, 0, 0);
    v1 = v157;
LABEL_148:
    memset(*(void **)(a1 - 1616), 0, 0x400u);
    v84 = *(_QWORD *)(*(_QWORD *)(a1 - 10144) + 40LL);
    if ( *(_QWORD *)(v84 + 136) )
    {
      _X19 = (unsigned __int64 *)(a1 - 10168);
      __asm { PRFM            #0x11, [X19] }
      do
        v112 = __ldxr(_X19);
      while ( __stxr(v112 | 0x40000, _X19) );
      v86 = *(void (__fastcall **)(_QWORD))(v84 + 136);
      if ( *((_DWORD *)v86 - 1) != -83892780 )
        __break(0x8228u);
      v86(a1 - 24408);
      __asm { PRFM            #0x11, [X19] }
      do
        v114 = __ldxr(_X19);
      while ( __stxr(v114 & 0xFFFFFFFFFFFBFFFFLL, _X19) );
    }
    goto LABEL_262;
  }
LABEL_264:
  result = mutex_unlock(v1);
  _ReadStatusReg(SP_EL0);
  return result;
}
