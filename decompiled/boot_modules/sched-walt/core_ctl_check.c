__int64 __fastcall core_ctl_check(__int64 result, unsigned int a2)
{
  __int64 v3; // x20
  char v4; // w9
  int v5; // w8
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x21
  char *v8; // x24
  _BYTE *v9; // x9
  __int64 v10; // x0
  unsigned __int64 v11; // x8
  __int64 v12; // x25
  unsigned int v13; // w22
  unsigned int v14; // w24
  __int64 v15; // x4
  _DWORD *v16; // x3
  char v17; // w11
  _DWORD *v18; // x19
  unsigned int v19; // w23
  __int64 v20; // x8
  bool v21; // cf
  __int64 v22; // x10
  unsigned __int64 v23; // x11
  char *v24; // x24
  unsigned int v25; // w24
  char v26; // w10
  __int64 v27; // x8
  unsigned __int64 v28; // x10
  unsigned __int64 v29; // x10
  __int64 v30; // x11
  __int64 v31; // x9
  int v32; // w10
  unsigned __int64 v33; // x6
  char *v34; // x5
  char v35; // w11
  int v36; // w9
  unsigned __int64 v37; // x11
  unsigned __int64 v38; // x11
  char v39; // w10
  int v40; // w20
  __int64 v41; // x9
  unsigned __int64 v42; // x10
  unsigned __int64 v43; // x10
  char v44; // w11
  unsigned int v45; // w19
  unsigned __int64 v46; // x11
  unsigned __int64 v47; // x11
  int v48; // w10
  unsigned int v49; // w11
  __int64 v50; // x8
  __int64 v51; // x21
  __int64 v52; // x11
  _DWORD *v53; // x25
  unsigned int v54; // w0
  __int64 v55; // x8
  unsigned int v56; // w8
  int v57; // w0
  _QWORD **v58; // x9
  _DWORD *v59; // x30
  _QWORD *v60; // x10
  int v61; // w8
  unsigned __int64 v62; // x11
  unsigned __int64 v63; // x15
  unsigned __int64 v64; // x13
  unsigned __int64 v65; // x15
  unsigned __int64 v66; // x16
  unsigned int v67; // w17
  int v68; // w16
  unsigned int v69; // w24
  __int64 v70; // x13
  __int64 v71; // x9
  char v72; // w11
  int v73; // w10
  __int64 v74; // x8
  unsigned __int64 v75; // x11
  unsigned __int64 v76; // x11
  __int64 v77; // x12
  __int64 v78; // x12
  bool v79; // zf
  int v80; // w13
  __int64 v81; // x13
  char *v82; // x14
  char v83; // w16
  int v84; // w15
  int v85; // w13
  __int64 v86; // x14
  unsigned __int64 v87; // x16
  unsigned __int64 v88; // x16
  char v89; // w11
  unsigned __int64 v90; // x11
  unsigned __int64 v91; // x11
  __int64 v92; // x12
  bool v93; // cc
  char v94; // w11
  unsigned __int64 v95; // x10
  __int64 updated; // x0
  unsigned __int64 v97; // x22
  int v98; // w21
  char *v99; // x20
  __int64 lock; // x0
  __int64 v101; // x20
  __int64 v102; // [xsp+30h] [xbp-90h]
  unsigned int v103; // [xsp+3Ch] [xbp-84h]
  __int64 v104; // [xsp+40h] [xbp-80h]
  unsigned int v105; // [xsp+54h] [xbp-6Ch]
  char *v106; // [xsp+58h] [xbp-68h]
  unsigned __int64 v107; // [xsp+60h] [xbp-60h]
  unsigned __int64 v108; // [xsp+68h] [xbp-58h]
  unsigned __int64 v109; // [xsp+70h] [xbp-50h]
  __int64 v110; // [xsp+78h] [xbp-48h]
  unsigned int v111; // [xsp+84h] [xbp-3Ch]
  int v112; // [xsp+88h] [xbp-38h] BYREF
  __int64 v113; // [xsp+8Ch] [xbp-34h]
  __int64 v114; // [xsp+94h] [xbp-2Ch]
  __int64 v115; // [xsp+9Ch] [xbp-24h]
  __int64 v116; // [xsp+A4h] [xbp-1Ch]
  int v117; // [xsp+ACh] [xbp-14h]
  __int64 v118; // [xsp+B0h] [xbp-10h]

  v118 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( initialized == 1 )
  {
    if ( (assist_params_initialized & 1) != 0 )
    {
      if ( core_ctl_check_timestamp != result )
      {
        v104 = result;
        core_ctl_check_timestamp = result;
        v3 = raw_spin_lock_irqsave(&state_lock);
        v4 = 0;
        v5 = _cpu_possible_mask;
        do
        {
          v6 = (unsigned int)(-1LL << v4) & v5;
          if ( !(_DWORD)v6 )
            break;
          v7 = __clz(__rbit64(v6));
          v8 = (char *)&cpu_state + *((_QWORD *)&_per_cpu_offset + v7);
          v9 = *((_BYTE **)v8 + 2);
          if ( v9 && *v9 == 1 )
          {
            *((_DWORD *)v8 + 1) = ((__int64 (__fastcall *)(_QWORD))sched_get_cpu_util_pct)((unsigned int)v7);
            v5 = _cpu_possible_mask;
          }
          v4 = v7 + 1;
        }
        while ( v7 < 0x1F );
        v103 = a2;
        v10 = raw_spin_unlock_irqrestore(&state_lock, v3);
        nr_stats = ((__int64 (__fastcall *)(__int64))sched_get_nr_running_avg)(v10);
        v102 = raw_spin_lock_irqsave(&state_lock);
        v11 = (unsigned int)num_clusters;
        if ( num_clusters )
        {
          v12 = 0;
          v13 = 0;
          v14 = 0;
          _ReadStatusReg(SP_EL0);
          while ( 1 )
          {
            if ( v12 == 4 )
              goto LABEL_143;
            v15 = 304 * v12;
            if ( 304 * v12 == 1216 )
              goto LABEL_143;
            v16 = (_DWORD *)((char *)&cluster_state + v15);
            if ( *((_BYTE *)&cluster_state + 304 * v12) == 1 )
            {
              if ( (unsigned __int64)(v15 - 960) < 0xFFFFFFFFFFFFFB40LL
                || (unsigned __int64)(304 * v12 - 960) < 0xFFFFFFFFFFFFFB40LL )
              {
                goto LABEL_143;
              }
              v17 = 0;
              v18 = (_DWORD *)((char *)&cluster_state + 304 * v12 + 256);
              v19 = 0;
              v20 = (unsigned int)*v18;
              while ( ((-1LL << v17) & v20) != 0 )
              {
                v22 = _cpu_partial_halt_mask;
                v23 = __clz(__rbit64((-1LL << v17) & v20));
                if ( (((unsigned __int64)_cpu_partial_halt_mask >> v23) & 1) == 0 )
                  v19 += *(_DWORD *)(nr_stats + 20LL * (unsigned int)v23);
                v21 = v23 >= 0x1F;
                v17 = v23 + 1;
                if ( v21 )
                  goto LABEL_25;
              }
              v22 = _cpu_partial_halt_mask;
LABEL_25:
              v111 = v14;
              if ( (v22 & v20) != 0 )
              {
                v24 = (char *)&cluster_state + v15;
                if ( v19 >= (unsigned int)_sw_hweight64(v20 & ~(_cpu_halt_mask | v22)) )
                  v19 -= _sw_hweight64(*v18 & ~((unsigned int)_cpu_partial_halt_mask | (unsigned int)_cpu_halt_mask));
                v16 = v24;
                v15 = 304 * v12;
              }
              if ( (unsigned __int64)(304 * v12 - 953) < 0xFFFFFFFFFFFFFB3FLL )
                goto LABEL_143;
              v25 = 0;
              v26 = 0;
              v27 = nr_stats;
              do
              {
                v28 = *((unsigned int *)&cluster_state + 76 * v12 + 66) & (unsigned __int64)(-1LL << v26);
                if ( !v28 )
                  break;
                v29 = __clz(__rbit64(v28));
                v30 = nr_stats + 20LL * (unsigned int)v29;
                v21 = v29 >= 0x1F;
                v26 = v29 + 1;
                v25 += *(_DWORD *)(v30 + 4);
              }
              while ( !v21 );
              if ( (unsigned __int64)(v15 - 944) < 0xFFFFFFFFFFFFFB40LL
                || (unsigned __int64)(v15 - 1077) < 0xFFFFFFFFFFFFFB3FLL )
              {
                goto LABEL_143;
              }
              v31 = 304 * v12;
              v32 = v25 <= v16[68] ? 0 : v25;
              v33 = v31 - 1136;
              v16[35] = v32 + v19;
              if ( (unsigned __int64)(v31 - 1136) < 0xFFFFFFFFFFFFFB40LL )
                goto LABEL_143;
              v34 = (char *)&cluster_state + v31;
              v35 = 0;
              v36 = 0;
              do
              {
                v37 = *((unsigned int *)v34 + 20) & (unsigned __int64)(-1LL << v35);
                if ( !v37 )
                  break;
                v38 = __clz(__rbit64(v37));
                if ( (((unsigned __int64)_cpu_partial_halt_mask >> v38) & 1) == 0
                  && v36 <= *(_DWORD *)(v27 + 20LL * (unsigned int)v38 + 8) )
                {
                  v36 = *(_DWORD *)(v27 + 20LL * (unsigned int)v38 + 8);
                }
                v21 = v38 >= 0x1F;
                v35 = v38 + 1;
              }
              while ( !v21 );
              if ( (unsigned __int64)(v15 - 1120) < 0xFFFFFFFFFFFFFB40LL )
                goto LABEL_143;
              v16[24] = v36;
              if ( (unsigned __int64)(304 * v12 - 937) < 0xFFFFFFFFFFFFFB3FLL )
                goto LABEL_143;
              v39 = 0;
              v40 = 0;
              v41 = *((unsigned int *)&cluster_state + 76 * v12 + 70);
              do
              {
                v42 = (-1LL << v39) & v41;
                if ( !v42 )
                  break;
                v43 = __clz(__rbit64(v42));
                if ( (((unsigned __int64)_cpu_partial_halt_mask >> v43) & 1) == 0 )
                  v40 += *(_DWORD *)(v27 + 20LL * (unsigned int)v43);
                v21 = v43 >= 0x1F;
                v39 = v43 + 1;
              }
              while ( !v21 );
              if ( (unsigned __int64)(304 * v12 - 928) < 0xFFFFFFFFFFFFFB40LL )
                goto LABEL_143;
              v44 = 0;
              v45 = 0;
              do
              {
                v46 = *((unsigned int *)&cluster_state + 76 * v12 + 72) & (unsigned __int64)(-1LL << v44);
                if ( !v46 )
                  break;
                v47 = __clz(__rbit64(v46));
                if ( (((unsigned __int64)_cpu_partial_halt_mask >> v47) & 1) == 0 )
                  v45 += *(_DWORD *)(v27 + 20LL * (unsigned int)v47 + 4);
                v21 = v47 >= 0x1F;
                v44 = v47 + 1;
              }
              while ( !v21 );
              if ( (unsigned __int64)(v15 - 921) < 0xFFFFFFFFFFFFFB3FLL )
                goto LABEL_143;
              v48 = 0;
              if ( v45 <= v16[74] )
                v49 = 0;
              else
                v49 = v45;
              v105 = v49;
              if ( !v12 )
              {
                if ( num_clusters )
                {
                  v78 = 0;
                  v48 = 0;
                  while ( v78 != 4 )
                  {
                    v81 = 304 * v78;
                    if ( (unsigned __int64)(304 * v78 - 1149) < 0xFFFFFFFFFFFFFB3FLL
                      || (unsigned __int64)(v81 - 1136) < 0xFFFFFFFFFFFFFB40LL )
                    {
                      break;
                    }
                    v82 = (char *)&cluster_state + v81;
                    v83 = 0;
                    v84 = 0;
                    v85 = *(_DWORD *)((char *)&cluster_state + v81 + 68);
                    v86 = *((unsigned int *)v82 + 20);
                    do
                    {
                      v87 = v86 & (-1LL << v83);
                      if ( !v87 )
                        break;
                      v88 = __clz(__rbit64(v87));
                      if ( (((unsigned __int64)_cpu_partial_halt_mask >> v88) & 1) == 0 )
                        v84 += *(_DWORD *)(v27 + 20LL * (unsigned int)v88 + 12);
                      v21 = v88 >= 0x1F;
                      v83 = v88 + 1;
                    }
                    while ( !v21 );
                    v79 = v78++ == 0;
                    v80 = (v84 / 100 - v85) & ~((v84 / 100 - v85) >> 31);
                    if ( v79 )
                      v80 = v84 / 100;
                    v48 += v80;
                    if ( v78 == num_clusters )
                      goto LABEL_64;
                  }
LABEL_143:
                  __break(1u);
LABEL_144:
                  __break(0x5512u);
                }
                v48 = 0;
              }
LABEL_64:
              v108 = v15 - 1120;
              v109 = v15 - 944;
              v106 = v34;
              v107 = v33;
              v110 = v12;
              if ( (unsigned __int64)(v15 - 969) < 0xFFFFFFFFFFFFFB3FLL )
                goto LABEL_143;
              v50 = _cpu_partial_halt_mask;
              v51 = v15;
              v52 = _cpu_halt_mask;
              v16[62] = v48;
              v53 = v16;
              v54 = _sw_hweight64(v41 & ~(v50 | v52));
              if ( (unsigned __int64)(v51 - 937) < 0xFFFFFFFFFFFFFB3FLL )
                goto LABEL_143;
              v55 = (unsigned int)v53[70];
              if ( (cpus_paused_by_us & v55) != 0
                || (cpus_part_paused_by_us & v55) != 0
                || (v56 = v105 + v40 - v54, v105 + v40 <= v54) )
              {
                if ( (unsigned __int64)(v51 - 1117) < 0xFFFFFFFFFFFFFB3FLL )
                  goto LABEL_143;
                v56 = 0;
              }
              else if ( (unsigned __int64)(v51 - 1117) < 0xFFFFFFFFFFFFFB3FLL )
              {
                goto LABEL_143;
              }
              v53[25] = v56;
              if ( (unsigned __int64)(v51 - 1136) < 0xFFFFFFFFFFFFFB40LL )
                goto LABEL_143;
              v57 = _sw_hweight64(v53[20] & ~((unsigned int)_cpu_partial_halt_mask | (unsigned int)_cpu_halt_mask));
              if ( (unsigned __int64)(v51 - 1149) < 0xFFFFFFFFFFFFFB3FLL )
                goto LABEL_143;
              v53[17] = v57;
              if ( (unsigned __int64)(v51 - 1097) < 0xFFFFFFFFFFFFFB3FLL )
                goto LABEL_143;
              v58 = (_QWORD **)(v53 + 30);
              v59 = v53;
              v12 = v110;
              v60 = *v58;
              v61 = 0;
              if ( *v58 != v58 )
              {
                v62 = (unsigned int)(v57 - 1);
                if ( !v57 )
                  v62 = 0;
                v63 = v51 + 4 * v62;
                v64 = v63 + 20;
                v65 = v63 + 44;
                do
                {
                  v66 = *((unsigned int *)v60 - 4);
                  if ( ((*(unsigned __int64 *)((char *)&_cpu_partial_halt_mask + ((v66 >> 3) & 0x1FFFFFF8)) >> v66) & 1) != 0 )
                  {
                    *((_BYTE *)v60 - 24) = 0;
                  }
                  else
                  {
                    if ( v62 > 5 )
                      goto LABEL_144;
                    if ( v64 > 0x4BF )
                      goto LABEL_143;
                    v67 = *((_DWORD *)v60 - 5);
                    if ( v67 >= v59[v62 + 5] )
                      goto LABEL_89;
                    if ( (unsigned int)v66 >= 0x20 )
                      goto LABEL_144;
                    if ( (walt_rq[*((_QWORD *)&_per_cpu_offset + v66) + 541] & 1) != 0
                      || (((unsigned __int64)walt_enforce_high_irq_cpu_mask >> v66) & 1) != 0 )
                    {
LABEL_89:
                      v68 = 1;
                      *((_BYTE *)v60 - 24) = 1;
                    }
                    else
                    {
                      if ( v65 > 0x4BF )
                        goto LABEL_143;
                      if ( v67 >= v59[v62 + 11] )
                      {
                        v68 = *((unsigned __int8 *)v60 - 24);
                      }
                      else
                      {
                        v68 = 0;
                        *((_BYTE *)v60 - 24) = 0;
                      }
                    }
                    v61 += v68;
                  }
                  v60 = (_QWORD *)*v60;
                }
                while ( v60 != v58 );
              }
              if ( (unsigned __int64)(v51 - 1113) < 0xFFFFFFFFFFFFFB3FLL )
                goto LABEL_143;
              v59[26] = v61;
              if ( (unsigned __int64)(v51 - 1072) < 0xFFFFFFFFFFFFFB40LL
                || v109 < 0xFFFFFFFFFFFFFB40LL
                || v108 < 0xFFFFFFFFFFFFFB40LL
                || (unsigned __int64)(v51 - 1117) < 0xFFFFFFFFFFFFFB3FLL )
              {
                goto LABEL_143;
              }
              if ( v110 )
              {
                v69 = v111;
                if ( v107 < 0xFFFFFFFFFFFFFB40LL )
                  goto LABEL_143;
                v70 = v51;
                v71 = nr_stats;
                v72 = 0;
                v73 = 0;
                v74 = *((unsigned int *)v106 + 20);
                do
                {
                  v75 = v74 & (-1LL << v72);
                  if ( !v75 )
                    break;
                  v76 = __clz(__rbit64(v75));
                  v77 = 20LL * (unsigned int)v76;
                  v21 = v76 >= 0x1F;
                  v72 = v76 + 1;
                  v73 += *(_DWORD *)(nr_stats + v77);
                }
                while ( !v21 );
              }
              else
              {
                v69 = v111;
                if ( v107 < 0xFFFFFFFFFFFFFB40LL )
                  goto LABEL_143;
                v70 = v51;
                v71 = nr_stats;
                v89 = 0;
                v73 = 0;
                v74 = *((unsigned int *)v106 + 20);
                do
                {
                  v90 = v74 & (-1LL << v89);
                  if ( !v90 )
                    break;
                  v91 = __clz(__rbit64(v90));
                  v92 = nr_stats + 20LL * (unsigned int)v91;
                  v93 = v91 > 0x1E;
                  v89 = v91 + 1;
                  v73 += *(_DWORD *)(v92 + 4);
                }
                while ( !v93 );
              }
              if ( (unsigned __int64)(v70 - 1109) < 0xFFFFFFFFFFFFFB3FLL )
                goto LABEL_143;
              v94 = 0;
              v14 = v73 + v69;
              v59[27] = v73;
              do
              {
                if ( (v74 & (-1LL << v94)) == 0 )
                  break;
                v95 = __clz(__rbit64(v74 & (-1LL << v94)));
                v13 += *(_DWORD *)(v71 + 20LL * (unsigned int)v95 + 16);
                v94 = v95 + 1;
              }
              while ( v95 < 0x1F );
              v11 = (unsigned int)num_clusters;
            }
            if ( ++v12 >= v11 )
              goto LABEL_132;
          }
        }
        v14 = 0;
        v13 = 0;
LABEL_132:
        raw_spin_unlock_irqrestore(&state_lock, v102);
        last_nr_big = v14;
        ((void (__fastcall *)(__int64, _QWORD))walt_rotation_checkpoint)(v104, v13);
        updated = smart_freq_update_reason_common(v104, v14, v103);
        if ( num_clusters )
        {
          v97 = 0;
          v98 = 0;
          v99 = (char *)&cluster_state;
          do
          {
            if ( !v99 )
              break;
            updated = eval_need(v99);
            ++v97;
            v98 |= updated & 1;
            v99 += 304;
          }
          while ( v97 < (unsigned int)num_clusters );
          if ( v98 )
            updated = do_core_ctl(updated);
        }
        v117 = 0;
        v116 = 0;
        v115 = 0;
        v114 = 0;
        v113 = 0;
        lock = _rcu_read_lock(updated);
        v101 = qword_67ED0;
        _rcu_read_unlock(lock);
        if ( v101 )
        {
          v112 = last_nr_big;
          ((void (__fastcall *)(int *))walt_fill_ta_data)(&v112);
          atomic_notifier_call_chain(&core_ctl_notifier, 0, &v112);
        }
        result = sbt_ctl_check(v103);
      }
    }
    else
    {
      result = core_ctl_check_masks_set();
      assist_params_initialized = result & 1;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
