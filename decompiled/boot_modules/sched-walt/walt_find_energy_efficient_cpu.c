unsigned __int64 __fastcall walt_find_energy_efficient_cpu(
        unsigned __int64 result,
        char *a2,
        _QWORD *a3,
        unsigned __int64 *a4,
        __int64 a5,
        _DWORD *a6,
        _BYTE *a7,
        char *a8)
{
  char *v8; // x15
  _BYTE *v10; // x17
  __int64 v11; // x30
  __int64 v12; // x8
  unsigned __int64 StatusReg; // x11
  _BYTE *v14; // x10
  __int64 v15; // x21
  __int64 v16; // x20
  unsigned int v17; // w24
  int v18; // w23
  unsigned __int64 v19; // x14
  char v20; // w9
  int v21; // w8
  unsigned __int8 *v22; // x8
  unsigned __int64 v23; // x0
  int v25; // w26
  unsigned __int64 *v26; // x8
  int v27; // w8
  unsigned __int64 v28; // x9
  __int64 v29; // x10
  unsigned int v30; // w10
  __int64 v31; // x13
  int v32; // w8
  unsigned __int64 v33; // x9
  unsigned __int64 v34; // x10
  __int64 v35; // x11
  char *v36; // x8
  _BYTE *v37; // x8
  char *v38; // x8
  unsigned __int64 v39; // x24
  _BYTE *v40; // x8
  char v41; // w12
  int v42; // w8
  __int64 v43; // x25
  unsigned int v44; // w28
  unsigned __int64 v45; // x12
  char *v46; // x12
  _BYTE *v47; // x12
  char v48; // w9
  char *v49; // x19
  __int64 lock; // x0
  __int64 v51; // x8
  int v52; // w19
  unsigned int v53; // w28
  __int64 v54; // x19
  int v55; // w8
  __int64 v56; // x28
  unsigned int v57; // w25
  __int64 v58; // x19
  unsigned int v59; // w9
  __int64 v60; // x8
  bool v61; // w25
  char *v62; // x8
  _QWORD *v63; // x8
  __int64 v64; // x22
  bool v65; // zf
  bool v66; // w8
  char *v67; // x13
  __int64 v68; // x8
  _BOOL4 v69; // w9
  _BYTE *v70; // x10
  _BOOL4 v71; // w10
  bool v72; // zf
  unsigned __int64 v73; // x19
  int v74; // w9
  int v75; // w8
  char *v76; // x20
  unsigned __int64 v77; // x23
  unsigned __int64 v78; // x9
  unsigned __int64 v79; // x25
  unsigned __int64 v80; // x9
  int v81; // w8
  unsigned __int64 v82; // x26
  __int64 v83; // x23
  __int64 v84; // x9
  unsigned __int64 v85; // x22
  _QWORD *v86; // x0
  unsigned __int64 v87; // x19
  unsigned int v88; // w24
  __int64 v89; // x8
  unsigned __int64 v90; // x8
  _BYTE *v91; // x9
  unsigned __int64 v92; // x10
  unsigned __int64 v93; // x9
  char v94; // w0
  __int64 v95; // x8
  unsigned __int64 v100; // x10
  unsigned __int64 v102; // x9
  int v103; // w8
  signed __int64 v104; // x13
  signed __int64 v105; // x27
  unsigned __int64 v106; // x12
  __int64 v107; // x9
  unsigned __int64 v108; // x10
  __int64 v109; // x22
  __int64 v110; // x25
  int v111; // w11
  unsigned __int64 v112; // x8
  unsigned __int64 v113; // x24
  _BYTE *v114; // x28
  unsigned __int64 v115; // x19
  __int64 v116; // x8
  __int64 v117; // x19
  _BYTE *v118; // x9
  __int64 v119; // x21
  unsigned __int64 v120; // x0
  bool v121; // cc
  __int64 v122; // x8
  int v123; // w21
  _BYTE *v124; // x9
  unsigned __int64 v125; // x10
  unsigned __int64 v126; // x9
  signed __int64 v127; // x11
  unsigned int v128; // w8
  unsigned int v129; // w11
  unsigned __int64 v130; // x9
  unsigned int v132; // w8
  __int64 v133; // x28
  __int64 v134; // x8
  unsigned int v135; // w19
  __int64 v136; // x0
  int v137; // w0
  int v138; // w9
  unsigned int v139; // w8
  __int64 v140; // x10
  int v141; // w25
  __int64 v142; // x24
  _QWORD *v143; // x19
  _BYTE *v144; // x22
  int v145; // w9
  int v146; // w8
  char v147; // w8
  unsigned __int64 v150; // x10
  unsigned __int64 v153; // x10
  char v154; // w12
  unsigned __int64 v155; // x12
  unsigned __int64 v156; // x12
  __int64 v157; // x13
  unsigned __int64 *v158; // x19
  int v159; // w9
  unsigned __int64 v160; // x19
  unsigned __int64 v161; // x19
  int v162; // w8
  char v163; // w10
  unsigned __int64 v164; // x10
  unsigned __int64 v165; // x10
  _BYTE *v166; // x11
  unsigned __int64 v167; // x13
  unsigned __int64 v168; // x11
  _BYTE *v169; // x12
  unsigned int v170; // w11
  unsigned __int64 v171; // x14
  unsigned __int64 v172; // x12
  unsigned int v173; // w12
  __int64 v174; // x8
  __int64 v175; // x19
  _QWORD *v176; // x10
  __int64 v177; // x9
  unsigned __int64 v178; // x11
  unsigned __int64 v179; // x10
  __int64 v180; // x9
  unsigned int v181; // w10
  unsigned __int64 v182; // x27
  char v183; // w8
  unsigned __int64 v184; // x23
  unsigned int v185; // w26
  unsigned __int64 v186; // x22
  unsigned __int64 v187; // x8
  unsigned __int64 v188; // x25
  unsigned __int64 v189; // x0
  unsigned __int64 v190; // x19
  int v191; // w24
  int v192; // w8
  int v193; // w11
  unsigned __int64 v194; // x10
  _BYTE *v195; // x12
  _BYTE *v196; // x12
  __int64 v197; // x9
  __int64 v198; // x9
  unsigned int v199; // w9
  bool v200; // cf
  _BYTE *v201; // x8
  _BYTE *v202; // x9
  unsigned __int64 v203; // x10
  unsigned __int64 v204; // x8
  unsigned __int64 v205; // x11
  unsigned __int64 v206; // x9
  __int64 v207; // x8
  unsigned __int64 v210; // x10
  unsigned __int64 v213; // x10
  unsigned __int64 v215; // x9
  __int64 v216; // [xsp+30h] [xbp-1C0h]
  int v217; // [xsp+38h] [xbp-1B8h]
  unsigned int v218; // [xsp+48h] [xbp-1A8h]
  _BOOL4 v219; // [xsp+4Ch] [xbp-1A4h]
  unsigned __int64 v220; // [xsp+50h] [xbp-1A0h]
  bool v221; // [xsp+58h] [xbp-198h]
  int v222; // [xsp+5Ch] [xbp-194h]
  __int64 v223; // [xsp+60h] [xbp-190h]
  unsigned int v224; // [xsp+6Ch] [xbp-184h]
  signed int v225; // [xsp+70h] [xbp-180h]
  unsigned __int64 v226; // [xsp+78h] [xbp-178h]
  int v227; // [xsp+80h] [xbp-170h]
  int v228; // [xsp+84h] [xbp-16Ch]
  _BYTE *v229; // [xsp+88h] [xbp-168h]
  char *v230; // [xsp+90h] [xbp-160h]
  _QWORD *v231; // [xsp+98h] [xbp-158h]
  unsigned int v232; // [xsp+A4h] [xbp-14Ch]
  signed __int64 v233; // [xsp+A8h] [xbp-148h]
  unsigned int v234; // [xsp+B0h] [xbp-140h]
  unsigned __int64 *v235; // [xsp+B8h] [xbp-138h]
  unsigned __int64 v236; // [xsp+C0h] [xbp-130h]
  unsigned __int64 v237; // [xsp+C8h] [xbp-128h]
  unsigned int v238; // [xsp+E4h] [xbp-10Ch]
  signed __int64 v239; // [xsp+E8h] [xbp-108h]
  int v240; // [xsp+F4h] [xbp-FCh]
  unsigned int v241; // [xsp+F8h] [xbp-F8h]
  unsigned int v242; // [xsp+100h] [xbp-F0h]
  unsigned int v243; // [xsp+108h] [xbp-E8h]
  int v244; // [xsp+10Ch] [xbp-E4h]
  __int64 v245; // [xsp+110h] [xbp-E0h]
  __int64 v246; // [xsp+118h] [xbp-D8h]
  __int64 v247; // [xsp+120h] [xbp-D0h]
  __int64 v248; // [xsp+128h] [xbp-C8h]
  __int64 v249; // [xsp+130h] [xbp-C0h]
  __int64 v250; // [xsp+138h] [xbp-B8h]
  __int64 v251; // [xsp+140h] [xbp-B0h]
  __int64 v252; // [xsp+148h] [xbp-A8h]
  __int64 v253; // [xsp+150h] [xbp-A0h]
  __int64 v254; // [xsp+158h] [xbp-98h]
  __int64 v255; // [xsp+160h] [xbp-90h]
  __int64 v256; // [xsp+168h] [xbp-88h]
  __int64 v257; // [xsp+170h] [xbp-80h]
  __int64 v258; // [xsp+178h] [xbp-78h]
  __int64 v259; // [xsp+180h] [xbp-70h]
  __int64 v260; // [xsp+188h] [xbp-68h]
  __int64 v261; // [xsp+190h] [xbp-60h]
  __int64 v262; // [xsp+198h] [xbp-58h]
  _QWORD v263[10]; // [xsp+1A0h] [xbp-50h] BYREF

  v224 = (unsigned int)a2;
  v263[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !_cpu_active_mask )
    goto LABEL_232;
  _X16 = (unsigned __int64 *)&_per_cpu_offset;
  v12 = *((_QWORD *)&_per_cpu_offset + __clz(__rbit64(_cpu_active_mask)));
  StatusReg = _ReadStatusReg(SP_EL0);
  v14 = (_BYTE *)(StatusReg + 5184);
  if ( (_UNKNOWN *)StatusReg == &init_task )
    v14 = &vendor_data_pad;
  v15 = *(_QWORD *)((char *)&runqueues + v12 + 3528);
  v16 = *(unsigned int *)(StatusReg + 40);
  v17 = (unsigned int)a4;
  v18 = (int)a3;
  v19 = result;
  memset(v263, 0, 64);
  v261 = 0;
  v262 = 0;
  v20 = v14[188];
  v259 = 0;
  v260 = 0;
  if ( (v20 & 1) != 0 )
  {
    v21 = 1;
  }
  else
  {
    v22 = (unsigned __int8 *)(result + 5184);
    if ( (_UNKNOWN *)result == &init_task )
      v22 = (unsigned __int8 *)&vendor_data_pad;
    v21 = v22[188];
  }
  v222 = v21;
  v236 = result;
  if ( (_UNKNOWN *)result == &init_task )
    v8 = (char *)&vendor_data_pad;
  else
    v8 = (char *)(result + 5184);
  v230 = v8;
  v231 = v8 + 192;
  if ( *((_QWORD *)v8 + 24) )
  {
    v23 = walt_sched_clock(result, (__int64)a2);
    v8 = v230;
    v19 = v236;
    _X16 = (unsigned __int64 *)&_per_cpu_offset;
    if ( v23 > *((_QWORD *)v230 + 25) )
    {
      *((_DWORD *)v230 + 46) = 0;
      *v231 = 0;
      v231[1] = 0;
    }
  }
  v221 = 0;
  if ( *((_DWORD *)v8 + 46) == 1 && (soc_flags & 8) == 0 )
    v25 = 0;
  else
    v25 = *((_DWORD *)v8 + 46);
  if ( (soc_flags & 4) != 0 )
  {
    if ( uclamp_eff_value(v19, 0) )
    {
      v8 = v230;
      v19 = v236;
      v221 = sysctl_sched_min_task_util_for_uclamp < (unsigned int)*((unsigned __int16 *)v230 + 79);
    }
    else
    {
      v19 = v236;
      v8 = v230;
      v221 = 0;
    }
    _X16 = (unsigned __int64 *)&_per_cpu_offset;
  }
  result = v224;
  v10 = &unk_6B000;
  v257 = 0;
  v258 = 0;
  v255 = 0;
  v256 = 0;
  v253 = 0;
  v254 = 0;
  v251 = 0;
  v252 = 0;
  v249 = 0;
  v250 = 0;
  v247 = 0;
  v248 = 0;
  v245 = 0;
  v246 = 0;
  if ( sysctl_sched_many_wakeup_threshold <= v17
    && (_DWORD)v16 != v224
    && ((*(_QWORD *)(*(_QWORD *)(v19 + 1376) + (((unsigned __int64)v224 >> 3) & 0x1FFFFFF8)) >> v224) & 1) != 0
    || !cpu_array )
  {
    goto LABEL_360;
  }
  v26 = (unsigned __int64 *)((char *)&energy_cpus + _ReadStatusReg(TPIDR_EL1));
  *v26 = 0;
  v235 = v26;
  v27 = sched_boost_type;
  if ( !sched_boost_type )
  {
    v33 = *((unsigned int *)v8 + 91);
    if ( (pipeline_nr || sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres && have_heavy_list)
      && (v8[191] & 0xC) != 0
      && (_DWORD)v33 != -1 )
    {
      v34 = v33 >> 6;
      v35 = 1LL << v33;
      if ( (*(_QWORD *)(*(_QWORD *)(v19 + 1376) + 8 * (v33 >> 6)) & (1LL << v33)) != 0
        && (*((_QWORD *)&_cpu_active_mask + v34) & v35) != 0
        && (_cpu_halt_mask[v34] & v35) == 0 )
      {
        if ( (unsigned int)v33 > 0x1F )
          goto LABEL_232;
        v36 = *(char **)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v33) + 3344);
        if ( v36 == (char *)&init_task )
          v37 = &vendor_data_pad;
        else
          v37 = v36 + 5184;
        if ( (v37[191] & 0xC) != 0 )
        {
          result = v224;
          if ( ((*(unsigned __int64 *)((char *)&cpus_for_pipeline + (((unsigned __int64)v224 >> 3) & 0x1FFFFFF8)) >> v224)
              & 1) != 0 )
          {
            if ( v224 > 0x1F )
              goto LABEL_232;
            LODWORD(result) = v224;
            v38 = *(char **)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v224) + 3344);
            LODWORD(v39) = v224;
            v40 = v38 == (char *)&init_task ? &vendor_data_pad : v38 + 5184;
            if ( (v40[191] & 0xC) == 0 )
            {
LABEL_104:
              LODWORD(v260) = 4;
              goto LABEL_357;
            }
          }
          v41 = 0;
          do
          {
            v45 = (unsigned int)(-1LL << v41) & (unsigned int)cpus_for_pipeline;
            if ( !(_DWORD)v45 )
              break;
            v39 = __clz(__rbit64(v45));
            if ( (_DWORD)v33 != (_DWORD)v39 )
            {
              v46 = *(char **)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v39) + 3344);
              v47 = v46 == (char *)&init_task ? &vendor_data_pad : v46 + 5184;
              if ( (v47[191] & 0xC) == 0 )
                goto LABEL_104;
            }
            v41 = v39 + 1;
          }
          while ( v39 < 0x1F );
        }
        else
        {
          LODWORD(result) = v224;
        }
        LODWORD(v39) = *((_DWORD *)v8 + 91);
        goto LABEL_104;
      }
    }
  }
  if ( v224 != -1 && (unsigned __int8)v8[386] >= 0x19u && (unsigned __int8)contiguous_yielding_windows >= 3u )
  {
    v28 = (unsigned __int64)v224 >> 6;
    v29 = 1LL << v224;
    if ( (*(_QWORD *)(*(_QWORD *)(v19 + 1376) + 8 * v28) & (1LL << v224)) != 0
      && (*((_QWORD *)&_cpu_active_mask + v28) & v29) != 0
      && (_cpu_halt_mask[v28] & v29) == 0 )
    {
      LODWORD(v39) = v224;
      LODWORD(v260) = 5;
      goto LABEL_357;
    }
  }
  v30 = num_sched_clusters - 2;
  if ( num_sched_clusters >= 2 )
  {
    if ( v25 >= 2 )
    {
      v30 = 0;
      v217 = 0;
      v31 = (unsigned int)(num_sched_clusters - 1);
      goto LABEL_130;
    }
    if ( sched_boost_type == 1 )
    {
      v31 = (unsigned int)(num_sched_clusters - 1);
      if ( (soc_flags & 0x100) != 0 )
        v30 = 1;
      while ( 1 )
      {
        if ( !*(_DWORD *)(*(_QWORD *)(cpu_array + 8LL * (unsigned int)v31) + 8LL * v30) )
          goto LABEL_232;
        a2 = (char *)__clz(__rbit64(*(unsigned int *)(*(_QWORD *)(cpu_array + 8LL * (unsigned int)v31) + 8LL * v30)));
        v42 = *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + (_QWORD)a2) + 8] + 32LL);
        if ( v42 == max_possible_cluster_id
          || !*((_QWORD *)v8 + 30) && *(int *)(v19 + 148) >= 124 && v42 != min_possible_cluster_id )
        {
LABEL_72:
          v217 = 0;
          goto LABEL_130;
        }
        v43 = v31;
        v44 = v30;
        result = task_fits_capacity_0(v19);
        if ( (result & 1) != 0 )
          break;
        v19 = v236;
        v8 = v230;
        v30 = v44 - 1;
        _X16 = (unsigned __int64 *)&_per_cpu_offset;
        v10 = &unk_6B000;
        v31 = v43;
        if ( (int)(v44 - 1) < 0 )
          goto LABEL_72;
      }
      v8 = v230;
      v217 = 0;
      _X16 = (unsigned __int64 *)&_per_cpu_offset;
      v10 = &unk_6B000;
      v30 = v44;
      v31 = v43;
      goto LABEL_130;
    }
    v48 = v221;
    if ( v25 )
      v48 = 1;
    if ( (v48 & 1) != 0 )
      goto LABEL_84;
    if ( boost_policy )
    {
      result = task_sched_boost_2(v19);
      v27 = sched_boost_type;
      if ( (result & 1) != 0 && boost_policy == 1 )
      {
        v19 = v236;
        v8 = v230;
        _X16 = (unsigned __int64 *)&_per_cpu_offset;
        v10 = &unk_6B000;
        if ( sched_boost_type != 5 && sched_boost_type != 2
          || sysctl_sched_min_task_util_for_boost < (unsigned int)*((unsigned __int16 *)v230 + 79) )
        {
          goto LABEL_84;
        }
      }
      else
      {
        v19 = v236;
        v8 = v230;
        _X16 = (unsigned __int64 *)&_per_cpu_offset;
        v10 = &unk_6B000;
      }
    }
    if ( v27 == 2 || (soc_flags & 0x80) == 0 )
      goto LABEL_90;
    v49 = v8;
    lock = _rcu_read_lock(result);
    v51 = *((_QWORD *)v49 + 30);
    if ( v51 )
    {
      v52 = *(unsigned __int8 *)(v51 + 40);
      result = _rcu_read_unlock(lock);
      if ( v52 == 1 )
      {
        v8 = v230;
        v19 = v236;
        _X16 = (unsigned __int64 *)&_per_cpu_offset;
        v10 = &unk_6B000;
        if ( !*((_DWORD *)v230 + 55) )
        {
          if ( sched_boost_type )
            goto LABEL_90;
          if ( !pipeline_nr )
          {
            v31 = 0;
            v217 = 1;
            if ( !(sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres) )
            {
              v30 = 0;
              goto LABEL_107;
            }
            v30 = 0;
            if ( !have_heavy_list )
            {
LABEL_107:
              if ( (int)v31 < num_sched_clusters - 1 )
              {
                v53 = v30;
                v54 = (unsigned int)v31;
                while ( 1 )
                {
                  if ( !**(_DWORD **)(cpu_array + 8 * v54) )
                    goto LABEL_232;
                  a2 = (char *)__clz(__rbit64(**(unsigned int **)(cpu_array + 8 * v54)));
                  v55 = *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + (_QWORD)a2) + 8] + 32LL);
                  if ( v55 == max_possible_cluster_id
                    || !*((_QWORD *)v8 + 30) && *(int *)(v19 + 148) >= 124 && v55 != min_possible_cluster_id )
                  {
                    break;
                  }
                  result = task_fits_capacity_0(v19);
                  v8 = v230;
                  v19 = v236;
                  v10 = &unk_6B000;
                  _X16 = (unsigned __int64 *)&_per_cpu_offset;
                  if ( (result & 1) != 0 )
                    break;
                  if ( ++v54 >= num_sched_clusters - 1 )
                  {
                    v31 = (unsigned int)v54;
                    v30 = v53;
                    goto LABEL_129;
                  }
                }
                v31 = (unsigned int)v54;
                v30 = v53;
              }
              if ( !(_DWORD)v31
                && *((unsigned __int16 *)v8 + 79) >= 0x34u
                && ((*(_WORD *)(v19 + 1728) & 8) == 0 || !*((_QWORD *)v8 + 30)) )
              {
                v56 = v31;
                v57 = v30;
                result = walt_get_rtg_status(v19);
                if ( (result & 1) != 0
                  || sched_boost_type == 2 && (result = task_sched_boost_2(v236), (result & 1) != 0) )
                {
                  v19 = v236;
                  v8 = v230;
                  _X16 = (unsigned __int64 *)&_per_cpu_offset;
                  v10 = &unk_6B000;
                  v30 = v57;
                  v31 = v56;
                }
                else
                {
                  v19 = v236;
                  _X16 = (unsigned __int64 *)&_per_cpu_offset;
                  v8 = v230;
                  v10 = &unk_6B000;
                  v31 = v56;
                  if ( sysctl_sched_suppress_region2 )
                    v30 = v57;
                  else
                    v30 = 1;
                }
              }
LABEL_129:
              if ( (*(_WORD *)(v19 + 1728) & 8) == 0 )
                goto LABEL_130;
              v32 = v217;
              if ( *((_QWORD *)v8 + 30) )
                v32 = 0;
              goto LABEL_39;
            }
          }
          if ( (v230[191] & 0xC) == 0 )
          {
LABEL_90:
            v31 = 0;
            v30 = 0;
            v217 = 1;
            goto LABEL_107;
          }
        }
LABEL_84:
        v30 = ((unsigned int)soc_flags >> 5) & 1;
        if ( sysctl_sched_asymcap_boost )
        {
          v217 = 0;
          ++v30;
          v31 = 1;
          goto LABEL_130;
        }
        v31 = 1;
        v217 = 0;
        goto LABEL_107;
      }
    }
    else
    {
      result = _rcu_read_unlock(lock);
    }
    v19 = v236;
    v8 = v230;
    v31 = 0;
    v30 = 0;
    v217 = 1;
    _X16 = (unsigned __int64 *)&_per_cpu_offset;
    v10 = &unk_6B000;
    goto LABEL_107;
  }
  v31 = 0;
  v30 = 0;
  v32 = 1;
LABEL_39:
  v217 = v32;
LABEL_130:
  v58 = *((_QWORD *)v8 + 30);
  v59 = __clz(__rbit64(**(unsigned int **)(cpu_array + 8LL * (int)v31)));
  if ( **(_DWORD **)(cpu_array + 8LL * (int)v31) )
    v60 = v59;
  else
    v60 = 32;
  v61 = v58 != 0;
  v223 = v60;
  if ( (unsigned int)v16 <= 0x1F )
  {
    v62 = *(char **)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v16) + 3344);
    v63 = v62 == (char *)&init_task ? &vendor_data_pad : v62 + 5184;
    v64 = v63[30];
    v229 = (_BYTE *)v31;
    v225 = v30;
    _rcu_read_lock(result);
    v65 = !v58 || v64 == 0;
    a2 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
    _X16 = (unsigned __int64 *)"pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
    v66 = !v65;
    HIDWORD(v259) = v222;
    LODWORD(v260) = 0;
    if ( v18 )
    {
      v10 = v229;
      v67 = v230;
      result = v236;
      v8 = (char *)v223;
      if ( !v222 && !v66 && sysctl_sched_sync_hint_enable )
      {
        v68 = 1LL << v16;
        v69 = (**(_QWORD **)(v236 + 1376) & (1LL << v16)) != 0 && (_cpu_active_mask & v68) != 0;
        if ( (((unsigned __int64)_cpu_partial_halt_mask[0] >> v223) & 1) != 0
          && *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v16) + 8] + 32LL) == min_possible_cluster_id )
        {
          goto LABEL_156;
        }
        if ( (unsigned int)v223 >= 0x20 )
          goto LABEL_232;
        v70 = &walt_rq[*((_QWORD *)&_per_cpu_offset + (unsigned int)v223)];
        if ( *(_DWORD *)(*((_QWORD *)v70 + 1) + 32LL) == min_possible_cluster_id
          && (_cpu_partial_halt_mask[0] & v68) != 0 )
        {
LABEL_156:
          v71 = 1;
        }
        else
        {
          v71 = *((_QWORD *)v70 + 79) <= *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v16) + 632];
        }
        if ( v69
          && v71
          && (_cpu_halt_mask[0] & v68) == 0
          && *(unsigned __int8 *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v16) + 8] + 488LL) == 255 )
        {
          LODWORD(v39) = v16;
          LODWORD(v260) = 1;
          goto LABEL_356;
        }
      }
    }
    else
    {
      LODWORD(v10) = (_DWORD)v229;
      v67 = v230;
      result = v236;
      LODWORD(v8) = v223;
    }
    v216 = *(_QWORD *)(v15 + 1808);
    if ( !v216 )
    {
      _rcu_read_unlock(result);
      result = 0xFFFFFFFFLL;
      goto LABEL_360;
    }
    if ( v58 )
      v72 = v25 == 3;
    else
      v72 = 0;
    v73 = *((unsigned __int16 *)v67 + 79);
    HIDWORD(v261) = v225;
    v74 = v72;
    if ( sysctl_sched_many_wakeup_threshold > v17 )
      v75 = -1;
    else
      v75 = v16;
    LOBYTE(v259) = v61;
    v76 = v67;
    HIDWORD(v260) = (_DWORD)v8;
    LODWORD(v261) = (_DWORD)v10;
    v240 = v74;
    LOBYTE(v262) = v74;
    HIDWORD(v262) = v75;
    v77 = uclamp_eff_value(result, 0);
    result = uclamp_eff_value(v236, 1);
    a4 = (unsigned __int64 *)v236;
    if ( v73 <= v77 )
      v78 = v77;
    else
      v78 = v73;
    v79 = *(unsigned int *)(v236 + 40);
    if ( result <= v73 )
      v78 = result;
    v226 = v78;
    v219 = *((_QWORD *)v76 + 30) && *(_DWORD *)(v236 + 148) <= (unsigned int)sysctl_walt_rtg_cfs_boost_prio;
    a7 = v229;
    a2 = (char *)v223;
    v244 = 0;
    if ( (int)v229 >= 1 && v230[272] == 1 )
    {
      v80 = 0x8000000000000000LL;
      v81 = num_sched_clusters - 2;
    }
    else
    {
      v80 = 0;
      v81 = 0x7FFFFFFF;
    }
    v82 = v240 ? 0x8000000000000000LL : v80;
    if ( (unsigned int)v223 < 0x20 )
    {
      v83 = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + (unsigned int)v223) + 8];
      v84 = *(int *)(v83 + 32);
      if ( (unsigned int)v84 <= 3 )
      {
        v220 = v79;
        v239 = v81;
        v233 = v82;
        if ( !sysctl_sched_idle_enough_clust[v84] || !sysctl_sched_cluster_util_thres_pct_clust[v84] )
          goto LABEL_207;
        v85 = _cpu_active_mask & (unsigned int)~LODWORD(_cpu_halt_mask[0]) & *(_QWORD *)(v83 + 24);
        if ( (*(_QWORD *)v236 & 0x400000) != 0 )
        {
          v86 = (_QWORD *)system_32bit_el0_cpumask(result);
          LODWORD(a7) = (_DWORD)v229;
          a2 = (char *)v223;
          a4 = (unsigned __int64 *)v236;
          v85 &= *v86;
        }
        v87 = __clz(__rbit64(v85));
        v88 = v85 ? v87 : 32;
        if ( v88 >= nr_cpu_ids || ((*(_QWORD *)a4[172] >> v88) & 1) == 0 )
          goto LABEL_207;
        result = sched_get_cluster_util_pct(v83);
        v89 = *(unsigned int *)(v83 + 32);
        a7 = v229;
        a2 = (char *)v223;
        a4 = (unsigned __int64 *)v236;
        if ( (unsigned int)v89 > 3 )
          goto LABEL_232;
        if ( (unsigned int)result >= sysctl_sched_cluster_util_thres_pct_clust[v89] )
          goto LABEL_207;
        if ( v88 >= 0x20 )
          goto LABEL_232;
        v90 = (unsigned int)sysctl_sched_idle_enough_clust[v89];
        v91 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v88)];
        v92 = *((_QWORD *)v91 + 5);
        v93 = *((_QWORD *)v91 + 79);
        if ( v92 < v93 )
          v93 = v92;
        if ( v93 < v90
          && (unsigned int)v90 > *((unsigned __int16 *)v230 + 79)
          && (v94 = task_reject_partialhalt_cpu_0(v236, v88),
              a7 = v229,
              a2 = (char *)v223,
              a8 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n",
              a4 = (unsigned __int64 *)v236,
              a6 = &unk_6B000,
              v8 = (char *)&_per_cpu_offset,
              (v94 & 1) == 0)
          && *(_QWORD *)((char *)&arch_freq_scale + *((_QWORD *)&_per_cpu_offset + v88)) <= 0x1C2u )
        {
          a3 = &unk_6B000;
          LODWORD(v260) = 3;
          _X16 = v235;
          __asm { PRFM            #0x11, [X16] }
          do
            v102 = __ldxr(v235);
          while ( __stxr(v102 | (1LL << v87), v235) );
          v10 = walt_rq;
          a2 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
          result = (unsigned __int64)"n";
          v95 = *(unsigned int *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v87) + 8] + 32LL);
          if ( (unsigned int)v95 >= 4 )
            goto LABEL_232;
        }
        else
        {
LABEL_207:
          if ( (((__int64 (__fastcall *)(_QWORD, char *, _QWORD, unsigned __int64 *))select_prev_cpu_fastpath)(
                  (unsigned int)v79,
                  a2,
                  (unsigned int)a7,
                  a4)
              & 1) == 0 )
          {
            _X16 = v235;
            a4 = (unsigned __int64 *)v236;
            a7 = v229;
            v218 = -1;
            v11 = 0xFFFFFFFFLL;
            v232 = -1;
            v8 = (char *)&_per_cpu_offset;
            v10 = walt_rq;
            result = (unsigned __int64)"n";
            a2 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
            a3 = &unk_6B000;
            a6 = &unk_6B000;
            a8 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
            v227 = 0;
            v243 = 0;
            v234 = -1;
            goto LABEL_233;
          }
          a2 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
          a3 = &unk_6B000;
          a6 = &unk_6B000;
          LODWORD(v260) = 2;
          _X16 = v235;
          _X9 = &v235[v79 >> 6];
          __asm { PRFM            #0x11, [X9] }
          do
            v100 = __ldxr(_X9);
          while ( __stxr(v100 | (1LL << v79), _X9) );
          a4 = (unsigned __int64 *)v236;
          a7 = v229;
          v8 = (char *)&_per_cpu_offset;
          v10 = walt_rq;
          result = (unsigned __int64)"n";
          a8 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
          if ( (unsigned int)v79 >= 0x20 )
            goto LABEL_232;
          v95 = *(unsigned int *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v79) + 8] + 32LL);
          if ( (unsigned int)v95 > 3 )
            goto LABEL_232;
        }
        *((_BYTE *)&v244 + v95) = 1;
        v11 = 0xFFFFFFFFLL;
        v232 = -1;
        v227 = 0;
        v218 = -1;
        v234 = -1;
        goto LABEL_332;
      }
    }
  }
LABEL_232:
  while ( 2 )
  {
    while ( 2 )
    {
      while ( 2 )
      {
        while ( 2 )
        {
          while ( 2 )
          {
            __break(0x5512u);
LABEL_233:
            v103 = a6[102];
            if ( v103 < 1 )
              goto LABEL_331;
            v104 = v225;
            v105 = 0;
            v106 = v243;
            while ( 1 )
            {
              if ( v243 )
              {
                if ( ((v106 >> v105) & 1) == 0 )
                  goto LABEL_236;
                if ( (unsigned __int64)v105 > 7 )
                  goto LABEL_232;
                v107 = *(_QWORD *)(sched_cluster[v105] + 24) & *(_QWORD *)a4[172];
                v108 = (unsigned int)v105;
                if ( (unsigned int)v105 > 3uLL )
                  goto LABEL_232;
              }
              else
              {
                if ( !(unsigned int)*(_QWORD *)(*(_QWORD *)(a3[50] + 8LL * (int)a7) + 8 * v105) )
                  goto LABEL_232;
                v107 = *(_QWORD *)a4[172] & *(_QWORD *)(*(_QWORD *)(a3[50] + 8LL * (int)a7) + 8 * v105);
                v108 = *(unsigned int *)(*(_QWORD *)&v10[*(_QWORD *)&v8[8
                                                                      * __clz(__rbit64((unsigned int)*(_QWORD *)(*(_QWORD *)(a3[50] + 8LL * (int)a7) + 8 * v105)))]
                                                       + 8]
                                       + 32LL);
                if ( v108 > 3 )
                  goto LABEL_232;
              }
              if ( (*((_BYTE *)&v244 + v108) & 1) != 0 )
                goto LABEL_236;
              v109 = (unsigned int)v107;
              *((_BYTE *)&v244 + v108) = 1;
              if ( (_DWORD)v107 )
              {
                v110 = 0;
                v111 = 0;
                v238 = 0x7FFFFFFF;
                v237 = -1;
                v112 = (unsigned int)v107;
                v241 = -1;
                v242 = -1;
                while ( 1 )
                {
                  v113 = __clz(__rbit64(v112));
                  v114 = &v10[*(_QWORD *)&v8[8 * v113]];
                  v115 = *((_QWORD *)v114 + 79);
                  if ( v113 > 7 )
                    goto LABEL_232;
                  v263[v113] = *((_QWORD *)v114 + 23) + *((_QWORD *)v114 + 19);
                  v116 = 1LL << v113;
                  if ( (*(_QWORD *)(result + 3272) & (1LL << v113)) == 0
                    || (*((_QWORD *)a8 + 466) & v116) != 0
                    || (_DWORD)a7 && (*((_QWORD *)a2 + 465) & v116) != 0 )
                  {
                    goto LABEL_250;
                  }
                  v118 = &v10[*(_QWORD *)&v8[8 * v113]];
                  if ( (*((_QWORD *)v118 + 10) & 2) != 0
                    || (v118[541] & 1) != 0
                    || (walt_enforce_high_irq_cpu_mask & v116) != 0
                    || HIDWORD(v262) == (_DWORD)v113 )
                  {
                    goto LABEL_250;
                  }
                  if ( *((int *)v114 + 146) >= 1 )
                  {
                    if ( *v231 )
                    {
                      v119 = v11;
                      v228 = v111;
                      v120 = walt_sched_clock(result, (__int64)a2);
                      v104 = v225;
                      v106 = v243;
                      _X16 = v235;
                      a4 = (unsigned __int64 *)v236;
                      v111 = v228;
                      a7 = v229;
                      v11 = v119;
                      a8 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
                      a6 = &unk_6B000;
                      a3 = &unk_6B000;
                      a2 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
                      v8 = (char *)&_per_cpu_offset;
                      v121 = v120 > *((_QWORD *)v230 + 25);
                      result = (unsigned __int64)"n";
                      v10 = walt_rq;
                      if ( v121 )
                      {
                        *((_DWORD *)v230 + 46) = 0;
                        v117 = v110;
                        *v231 = 0;
                        v231[1] = 0;
                        goto LABEL_251;
                      }
                    }
                    if ( *((_DWORD *)v230 + 46) != 3 )
                      goto LABEL_250;
                  }
                  if ( *((_DWORD *)a4 + 12) == 512 || *((_DWORD *)a4 + 10) != (_DWORD)v113 )
                    break;
                  v122 = *(_QWORD *)&v8[8 * v113];
                  v123 = v111;
                  if ( !a4[48] )
                    goto LABEL_267;
                  v124 = &v10[v122];
                  v140 = *(_QWORD *)&v10[v122 + 40] - *((unsigned __int16 *)v230 + 79);
                  v125 = (unsigned int)v140 & ~(unsigned int)(v140 >> 63);
LABEL_268:
                  v126 = *((_QWORD *)v124 + 79);
                  v127 = v233;
                  if ( v125 < v126 )
                    v126 = v125;
                  v128 = *(_DWORD *)((char *)&runqueues + v122 + 4);
                  if ( (__int64)(v115 - v126) <= v233 )
                  {
                    v11 = (unsigned int)v11;
                  }
                  else
                  {
                    v127 = v115 - v126;
                    v11 = (unsigned int)v113;
                  }
                  v233 = v127;
                  v129 = v232;
                  v130 = v126 + v226;
                  _CF = v128 >= v232;
                  if ( v128 < v232 )
                    v129 = v128;
                  v232 = v129;
                  if ( _CF )
                    v132 = v234;
                  else
                    v132 = v113;
                  _CF = v115 >= v130;
                  v117 = v115 - v130;
                  v234 = v132;
                  if ( !_CF )
                  {
                    v117 = v110;
                    v111 = v123;
                    goto LABEL_251;
                  }
                  v133 = v11;
                  if ( (unsigned int)available_idle_cpu((unsigned int)v113) )
                  {
                    v8 = (char *)&_per_cpu_offset;
                    v134 = *(_QWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v113) + 4232);
                    if ( v134 )
                      v135 = *(_DWORD *)(v134 + 68);
                    else
                      v135 = 0;
                    v136 = (unsigned int)cpu_l2_sibling[v113];
                    if ( (_DWORD)v136 == -1 )
                    {
                      v138 = 0;
                    }
                    else
                    {
                      v137 = available_idle_cpu(v136);
                      v8 = (char *)&_per_cpu_offset;
                      v138 = v137 != 0;
                    }
                    _X16 = v235;
                    a4 = (unsigned __int64 *)v236;
                    v10 = walt_rq;
                    v104 = v225;
                    v106 = v243;
                    a7 = v229;
                    result = (unsigned __int64)"n";
                    a2 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
                    a3 = &unk_6B000;
                    a6 = &unk_6B000;
                    a8 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
                    v11 = v133;
                    v111 = v123;
                    if ( v123 <= v138 && v135 <= v238 )
                    {
                      if ( v238 != v135 )
                        goto LABEL_301;
                      if ( v242 == (_DWORD)v220 )
                      {
                        v242 = v220;
                      }
                      else if ( (_DWORD)v220 == (_DWORD)v113
                             || *(_QWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v113) + 688) <= v237 )
                      {
LABEL_301:
                        v111 = v138;
                        v238 = v135;
                        v242 = v113;
                        v117 = v110;
                        v237 = *(_QWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v113) + 688);
                        goto LABEL_251;
                      }
                    }
LABEL_250:
                    v117 = v110;
                    goto LABEL_251;
                  }
                  _X16 = v235;
                  a4 = (unsigned __int64 *)v236;
                  v104 = v225;
                  v106 = v243;
                  v8 = (char *)&_per_cpu_offset;
                  a7 = v229;
                  v10 = walt_rq;
                  result = (unsigned __int64)"n";
                  a2 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
                  a3 = &unk_6B000;
                  a6 = &unk_6B000;
                  a8 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
                  v111 = v123;
                  if ( v242 == -1 )
                  {
                    v11 = v133;
                    if ( !v219 )
                    {
                      if ( v117 >= v110 )
                      {
                        v218 = *(_DWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v113) + 56];
                        v242 = -1;
                        v241 = v113;
                        goto LABEL_251;
                      }
LABEL_303:
                      v117 = v110;
                      v242 = -1;
                      goto LABEL_251;
                    }
                    v139 = *(_DWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v113) + 56];
                    if ( v139 > v218 || v139 == v218 && v117 < v110 )
                      goto LABEL_303;
                    v218 = *(_DWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v113) + 56];
                    v242 = -1;
                    v241 = v113;
                  }
                  else
                  {
                    v117 = v110;
                    v11 = v133;
                  }
LABEL_251:
                  v110 = v117;
                  v112 = (-2LL << v113) & v109;
                  if ( !v112 )
                  {
                    if ( v242 == -1 )
                    {
                      v141 = v241;
                      if ( v241 == -1 )
                        goto LABEL_312;
                      _X9 = &_X16[v241 >> 6];
                      __asm { PRFM            #0x11, [X9] }
                      do
                        v153 = __ldxr(_X9);
                      while ( __stxr(v153 | (1LL << v241), _X9) );
                    }
                    else
                    {
                      v141 = v241;
                      _X9 = &_X16[v242 >> 6];
                      __asm { PRFM            #0x11, [X9] }
                      do
                        v150 = __ldxr(_X9);
                      while ( __stxr(v150 | (1LL << v242), _X9) );
                    }
                    goto LABEL_313;
                  }
                }
                v122 = *(_QWORD *)&v8[8 * v113];
                v123 = v111;
LABEL_267:
                v124 = &v10[v122];
                v125 = *(_QWORD *)&v10[v122 + 40];
                goto LABEL_268;
              }
LABEL_312:
              v141 = -1;
LABEL_313:
              if ( v105 >= v104 && *(_DWORD *)_X16 )
                break;
LABEL_321:
              v147 = v240;
              if ( v105 >= v239 )
                v147 = 1;
              if ( (_DWORD)v11 != -1 && (v147 & 1) != 0 )
                goto LABEL_331;
              v103 = a6[102];
LABEL_236:
              if ( ++v105 >= v103 )
                goto LABEL_331;
            }
            if ( a6[102] - 1 == (_DWORD)a7 )
              goto LABEL_331;
            v142 = v11;
            v143 = a3;
            v144 = a7;
            if ( (unsigned int)_sw_hweight64(**(unsigned int **)(a3[50] + 8LL * (int)a7)) == 1 )
            {
              _X16 = v235;
              a4 = (unsigned __int64 *)v236;
              v104 = v225;
              v106 = v243;
              v8 = (char *)&_per_cpu_offset;
              v10 = walt_rq;
              result = (unsigned __int64)"n";
              a2 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
              a3 = v143;
              a6 = &unk_6B000;
              a7 = v144;
              a8 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
              v11 = v142;
              v145 = __clz(__rbit64(**(unsigned int **)(v143[50] + 8LL * (int)v144)));
              if ( **(_DWORD **)(v143[50] + 8LL * (int)v144) )
                v146 = v145;
              else
                v146 = 32;
              if ( v146 != v141 )
                goto LABEL_331;
              goto LABEL_321;
            }
            _X16 = v235;
            a4 = (unsigned __int64 *)v236;
            v8 = (char *)&_per_cpu_offset;
            v10 = walt_rq;
            result = (unsigned __int64)"n";
            a2 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
            a3 = v143;
            a6 = &unk_6B000;
            a7 = v144;
            a8 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
            v11 = v142;
LABEL_331:
            if ( !*(_DWORD *)_X16 )
            {
              if ( (_DWORD)v11 != -1 )
              {
                _X9 = &_X16[(unsigned int)v11 >> 6];
                __asm { PRFM            #0x11, [X9] }
                do
                  v210 = __ldxr(_X9);
                while ( __stxr(v210 | (1LL << v11), _X9) );
                break;
              }
              if ( ((*(_QWORD *)((char *)&_cpu_active_mask + ((v220 >> 3) & 0x1FFFFFF8)) >> v220) & 1) == 0 )
              {
LABEL_450:
                if ( v234 != -1 )
                {
                  _X9 = &_X16[v234 >> 6];
                  __asm { PRFM            #0x11, [X9] }
                  do
                    v213 = __ldxr(_X9);
                  while ( __stxr(v213 | (1LL << v234), _X9) );
                }
                break;
              }
              if ( (unsigned int)v220 <= 0x1F )
              {
                if ( *(_DWORD *)((char *)&runqueues + *(_QWORD *)&v8[8 * v220] + 4) <= 9u )
                {
                  __asm { PRFM            #0x11, [X16] }
                  do
                    v215 = __ldxr(_X16);
                  while ( __stxr(v215 | (1LL << v220), _X16) );
                  break;
                }
                goto LABEL_450;
              }
              continue;
            }
            break;
          }
LABEL_332:
          v154 = 0;
          v243 = 0;
          do
          {
            v155 = (unsigned int)*_X16 & (unsigned __int64)(-1LL << v154);
            if ( !v155 )
              break;
            v156 = __clz(__rbit64(v155));
            v157 = *(char *)(*(_QWORD *)&v10[*(_QWORD *)&v8[8 * v156] + 8] + 488LL);
            if ( (v157 & 0x8000000000000000LL) == 0 )
            {
              if ( (unsigned int)v157 > 3 )
                goto LABEL_232;
              if ( (*((_BYTE *)&v244 + v157) & 1) == 0 )
                v243 |= 1LL << v157;
            }
            _CF = v156 >= 0x1F;
            v154 = v156 + 1;
          }
          while ( !_CF );
          if ( v243 )
          {
            v227 = 1;
            goto LABEL_233;
          }
          v158 = _X16;
          result = _sw_hweight64(*(unsigned int *)_X16);
          if ( !(_DWORD)result )
          {
            LODWORD(v39) = v224;
            goto LABEL_356;
          }
          v159 = __clz(__rbit64(*(unsigned int *)v158));
          if ( *(_DWORD *)v158 )
            LODWORD(v39) = v159;
          else
            LODWORD(v39) = 32;
          if ( (((_DWORD)v260 == 3) & ~v227) != 0 )
            goto LABEL_356;
          if ( (_DWORD)result == 1 )
          {
            v160 = result;
            result = available_idle_cpu((unsigned int)v39);
            if ( (_DWORD)result )
              goto LABEL_356;
            result = v160;
            if ( (_DWORD)v39 == v224 )
              goto LABEL_356;
          }
          if ( v222 )
          {
            v161 = result;
            v162 = available_idle_cpu((unsigned int)v39);
            result = v161;
            if ( v162 )
              goto LABEL_356;
          }
          if ( ((v217 | v227) & 1) == 0 )
          {
            v163 = 0;
            v8 = (char *)&_per_cpu_offset;
            _X16 = (unsigned __int64 *)walt_rq;
            while ( 1 )
            {
              v164 = (unsigned int)(-1LL << v163) & (unsigned int)*v235;
              if ( !(_DWORD)v164 )
                goto LABEL_356;
              if ( (unsigned int)v39 >= 0x20 )
                goto LABEL_232;
              v165 = __clz(__rbit64(v164));
              v166 = &walt_rq[*((_QWORD *)&_per_cpu_offset + (unsigned int)v39)];
              v167 = *((_QWORD *)v166 + 79);
              v168 = *((_QWORD *)v166 + 5);
              v169 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v165)];
              _CF = v167 >= v168;
              v170 = v167 - v168;
              v171 = *((_QWORD *)v169 + 79);
              v172 = *((_QWORD *)v169 + 5);
              if ( !_CF )
                v170 = 0;
              _CF = v171 >= v172;
              v173 = v171 - v172;
              if ( !_CF )
                v173 = 0;
              if ( v170 < v173 )
                LODWORD(v39) = v165;
              v121 = v165 > 0x1E;
              v163 = v165 + 1;
              if ( v121 )
                goto LABEL_356;
            }
          }
          a4 = v235;
          if ( *(_DWORD *)(v236 + 48) == 512 )
            v174 = *((unsigned __int16 *)v230 + 79);
          else
            v174 = 0;
          v175 = v216;
          if ( ((*(_QWORD *)(*(_QWORD *)(v236 + 1376) + (((unsigned __int64)v224 >> 3) & 0x1FFFFFF8)) >> v224) & 1) == 0 )
            goto LABEL_380;
          if ( v224 >= 0x20 )
            continue;
          break;
        }
        v176 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v224)];
        v177 = *(unsigned int *)(v176[1] + 32LL);
        if ( (unsigned int)v177 >= 4 )
          continue;
        break;
      }
      v178 = v176[5];
      v179 = v176[79];
      v180 = (unsigned int)sched_capacity_margin_up[v177];
      if ( v178 >= v179 )
        v178 = v179;
      if ( (v178 + v174) * v180 <= v179 << 10 )
      {
        v182 = walt_compute_energy(v236, v224, v216, v235, v263, 0);
        v181 = v224;
        a4 = v235;
      }
      else
      {
LABEL_380:
        if ( (_DWORD)result == 1 )
          goto LABEL_356;
        v181 = v224;
        v182 = -1;
      }
      v183 = 0;
      v184 = v182;
      v185 = v181;
LABEL_386:
      v187 = (unsigned int)(-1LL << v183) & *(_DWORD *)a4;
      if ( (_DWORD)v187 )
      {
        v188 = __clz(__rbit64(v187));
        if ( (_DWORD)v188 == v181 )
        {
          LODWORD(v39) = v185;
          v186 = v184;
        }
        else
        {
          v189 = walt_compute_energy(v236, (unsigned int)v188, v175, a4, v263, 0);
          a4 = v235;
          LODWORD(v39) = v188;
          v186 = v189;
          if ( v189 >= v184 )
          {
            if ( v189 != v184 )
              goto LABEL_429;
            v190 = v189;
            v191 = available_idle_cpu((unsigned int)v188);
            result = available_idle_cpu(v185);
            v8 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
            v192 = result;
            if ( (_cpu_partial_halt_mask[0] & (1LL << v188)) != 0 )
            {
              if ( v185 >= 0x20 )
                continue;
              a4 = v235;
              result = v190;
              v193 = min_possible_cluster_id;
              if ( *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v185) + 8] + 32LL) == min_possible_cluster_id )
              {
                v175 = v216;
                v194 = v185;
                v193 = *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v185) + 8] + 32LL);
                goto LABEL_400;
              }
            }
            else
            {
              a4 = v235;
              result = v190;
              v193 = min_possible_cluster_id;
            }
            v175 = v216;
            v195 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v188)];
            if ( *(_DWORD *)(*((_QWORD *)v195 + 1) + 32LL) == v193 )
            {
              v194 = v185;
              _X16 = (unsigned __int64 *)_cpu_partial_halt_mask;
              if ( ((*(unsigned __int64 *)((char *)_cpu_partial_halt_mask + (((unsigned __int64)v185 >> 3) & 0x1FFFFFF8)) >> v185)
                  & 1) != 0 )
                goto LABEL_400;
            }
            if ( v185 >= 0x20 )
              continue;
            if ( *((_QWORD *)v195 + 79) > *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v185) + 632] )
              goto LABEL_429;
            v194 = v185;
LABEL_400:
            if ( ((*(unsigned __int64 *)((char *)_cpu_partial_halt_mask + ((v194 >> 3) & 0x1FFFFFF8)) >> v194) & 1) == 0
              || *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v188) + 8] + 32LL) != v193 )
            {
              if ( v185 >= 0x20 )
                continue;
              v196 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v194)];
              if ( (*(_DWORD *)(*((_QWORD *)v196 + 1) + 32LL) != v193 || (_cpu_partial_halt_mask[0] & (1LL << v188)) == 0)
                && *((_QWORD *)v196 + 79) > *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v188) + 632] )
              {
                goto LABEL_418;
              }
            }
            if ( v192 )
            {
              if ( v185 >= 0x20 )
                continue;
              v197 = *(_QWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v194) + 4232);
              if ( !v197 || *(_DWORD *)(v197 + 68) < 2u )
                goto LABEL_429;
            }
            if ( v191 )
            {
              v198 = *(_QWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v188) + 4232);
              if ( v198 )
              {
                v199 = *(_DWORD *)(v198 + 68);
                if ( v192 )
                  v200 = v199 >= 2;
                else
                  v200 = 0;
                if ( v200 )
                  LODWORD(v39) = v185;
                else
                  LODWORD(v39) = v188;
                goto LABEL_430;
              }
LABEL_418:
              LODWORD(v39) = v188;
              goto LABEL_430;
            }
            if ( v185 == v224 || v192 )
            {
LABEL_429:
              LODWORD(v39) = v185;
              goto LABEL_430;
            }
            if ( v185 >= 0x20 )
              continue;
            v201 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v194)];
            v202 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v188)];
            v203 = *((_QWORD *)v201 + 5);
            v204 = *((_QWORD *)v201 + 79);
            v205 = *((_QWORD *)v202 + 5);
            v206 = *((_QWORD *)v202 + 79);
            if ( v203 < v204 )
              v204 = v203;
            if ( v205 < v206 )
              v206 = v205;
            if ( v204 <= v206 )
              LODWORD(v39) = v185;
            else
              LODWORD(v39) = v188;
LABEL_430:
            v186 = v184;
          }
          v181 = v224;
        }
        v183 = v188 + 1;
        v184 = v186;
        v185 = v39;
        if ( v188 >= 0x1F )
          goto LABEL_433;
        goto LABEL_386;
      }
      break;
    }
    LODWORD(v39) = v185;
    v186 = v184;
LABEL_433:
    result = available_idle_cpu((unsigned int)v39);
    if ( !(_DWORD)result )
    {
      if ( v182 == -1 )
        goto LABEL_356;
      goto LABEL_440;
    }
    if ( (unsigned int)v39 > 0x1F )
      continue;
    break;
  }
  v207 = *(_QWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + (unsigned int)v39) + 4232);
  if ( !v207 || v182 == -1 || *(_DWORD *)(v207 + 68) < 2u )
    goto LABEL_356;
LABEL_440:
  if ( (_DWORD)v39 != v224 && v182 - v186 <= v182 >> 5 )
  {
    result = check_for_higher_capacity_0(v224, v223);
    if ( (result & 1) == 0 )
      LODWORD(v39) = v224;
  }
LABEL_356:
  _rcu_read_unlock(result);
  LODWORD(result) = v224;
LABEL_357:
  if ( (unsigned int)v39 <= 7 )
    result = (unsigned int)v39;
  else
    result = (unsigned int)result;
LABEL_360:
  _ReadStatusReg(SP_EL0);
  return result;
}
