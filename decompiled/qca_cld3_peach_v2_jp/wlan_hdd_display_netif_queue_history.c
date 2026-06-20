__int64 __fastcall wlan_hdd_display_netif_queue_history(
        const char *a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v10; // x28
  unsigned __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x21
  __int64 v14; // x20
  __int64 v15; // x8
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned __int64 v25; // x24
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x27
  __int64 v35; // x8
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x21
  __int64 v46; // x8
  __int64 v47; // x8
  unsigned int *v48; // x8
  unsigned int v49; // w10
  __int64 v50; // x8
  unsigned int v57; // w9
  __int64 v58; // x25
  unsigned __int64 StatusReg; // x8
  __int64 v60; // x0
  __int64 v61; // x23
  __int64 *v62; // x20
  __int64 v63; // x8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  int *v72; // x19
  __int64 v73; // x26
  __int64 v74; // x21
  _DWORD *v75; // x20
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned int v84; // w23
  __int64 v85; // x24
  int v86; // w4
  int v87; // w20
  char *v88; // x23
  int v89; // w24
  int v90; // w25
  size_t v91; // x19
  int v92; // w26
  int v93; // w0
  int v94; // w26
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  __int64 v103; // x0
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  __int64 *v112; // x19
  __int64 *v113; // x20
  __int64 v114; // x8
  __int64 v115; // x8
  unsigned int *v116; // x8
  unsigned int v117; // w10
  __int64 v118; // x8
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  __int64 v128; // x8
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  unsigned int v138; // w9
  _QWORD *v139; // x1
  __int64 v140; // x9
  unsigned __int64 v141; // x8
  __int64 v142; // x9
  unsigned int *v143; // x9
  unsigned int v144; // w12
  __int64 v145; // x9
  __int64 v147; // x0
  __int64 v148; // x19
  __int64 v149; // x9
  unsigned __int64 v150; // x8
  __int64 v151; // x9
  unsigned int *v152; // x9
  unsigned int v153; // w12
  __int64 v154; // x9
  const char *v156; // x2
  const char *v157; // x3
  unsigned int v158; // w1
  __int64 *v159; // x1
  __int64 v160; // x9
  unsigned __int64 v161; // x8
  __int64 v162; // x9
  unsigned int *v163; // x9
  unsigned int v164; // w12
  __int64 v165; // x9
  __int64 v167; // x0
  __int64 *v168; // x19
  __int64 v169; // x9
  unsigned __int64 v170; // x8
  __int64 v171; // x9
  unsigned int *v172; // x9
  unsigned int v173; // w12
  __int64 v174; // x9
  _QWORD *v176; // x19
  __int64 *v177; // x19
  unsigned int v179; // w9
  unsigned int v181; // w9
  unsigned int v183; // w9
  unsigned int v185; // w9
  unsigned __int64 v186; // [xsp+10h] [xbp-1B0h]
  __int64 v187; // [xsp+18h] [xbp-1A8h]
  __int64 v188; // [xsp+20h] [xbp-1A0h]
  __int64 v189; // [xsp+28h] [xbp-198h]
  const char *v190; // [xsp+30h] [xbp-190h]
  unsigned int v191; // [xsp+3Ch] [xbp-184h]
  __int64 *v192; // [xsp+40h] [xbp-180h] BYREF
  _QWORD s[47]; // [xsp+48h] [xbp-178h] BYREF

  s[45] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: hdd_ctx is null",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "wlan_hdd_display_netif_queue_history");
    goto LABEL_131;
  }
  v10 = a1;
  if ( !a2 )
  {
    memset(s, 0, 0x168u);
    result = _qdf_mem_malloc(0x99Du, "hdd_display_netif_queue_history_compact", 14041);
    if ( !result )
      goto LABEL_131;
    v58 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v10 + 32);
    }
    else
    {
      raw_spin_lock_bh(v10 + 32);
      *((_QWORD *)v10 + 5) |= 1uLL;
    }
    v192 = nullptr;
    v60 = qdf_list_peek_front((_QWORD *)v10 + 6, &v192);
    if ( (_DWORD)v60 || (v159 = v192, v61 = (__int64)(v192 - 1), v192 == &qword_8) )
    {
      v61 = 0;
    }
    else
    {
      v160 = *(__int64 *)((char *)&off_18 + (_QWORD)v192);
      if ( v160 )
      {
        v161 = _ReadStatusReg(SP_EL0);
        ++*(_DWORD *)(v161 + 16);
        v162 = *(_QWORD *)(v160 + 1320);
        v163 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v162);
        do
          v164 = __ldxr(v163);
        while ( __stxr(v164 + 1, v163) );
        v165 = *(_QWORD *)(v161 + 16) - 1LL;
        *(_DWORD *)(v161 + 16) = v165;
        if ( !v165 || !*(_QWORD *)(v161 + 16) )
        {
          v177 = v159;
          preempt_schedule_notrace(v60);
          v159 = v177;
        }
      }
      _X8 = (unsigned int *)(v159 + 6581);
      __asm { PRFM            #0x11, [X8] }
      do
        v181 = __ldxr(_X8);
      while ( __stxr(v181 + 1, _X8) );
      v192 = nullptr;
      v167 = qdf_list_peek_next((_QWORD *)v10 + 6, v159, &v192);
      if ( !(_DWORD)v167 )
      {
        v168 = v192;
        v62 = v192 - 1;
        if ( v192 != &qword_8 )
        {
          v169 = *(__int64 *)((char *)&off_18 + (_QWORD)v192);
          if ( v169 )
          {
            v170 = _ReadStatusReg(SP_EL0);
            ++*(_DWORD *)(v170 + 16);
            v171 = *(_QWORD *)(v169 + 1320);
            v172 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v171);
            do
              v173 = __ldxr(v172);
            while ( __stxr(v173 + 1, v172) );
            v174 = *(_QWORD *)(v170 + 16) - 1LL;
            *(_DWORD *)(v170 + 16) = v174;
            if ( !v174 || !*(_QWORD *)(v170 + 16) )
              preempt_schedule_notrace(v167);
          }
          _X8 = (unsigned int *)(v168 + 6581);
          __asm { PRFM            #0x11, [X8] }
          do
            v185 = __ldxr(_X8);
          while ( __stxr(v185 + 1, _X8) );
        }
LABEL_51:
        v63 = *((_QWORD *)v10 + 5);
        if ( (v63 & 1) != 0 )
        {
          *((_QWORD *)v10 + 5) = v63 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v10 + 32);
          if ( v61 )
            goto LABEL_53;
        }
        else
        {
          raw_spin_unlock(v10 + 32);
          if ( v61 )
          {
LABEL_53:
            v190 = v10;
            v10 = "%d(%d,%d) ";
            v191 = 0;
            v186 = _ReadStatusReg(SP_EL0);
            v187 = v58;
            while ( 1 )
            {
              v72 = (int *)(v61 + 42092);
              v188 = (__int64)v62;
              if ( *(_DWORD *)(v61 + 42092) )
                v73 = jiffies - *(_QWORD *)(v61 + 42112) + *(_QWORD *)(v61 + 42120);
              else
                v73 = *(_QWORD *)(v61 + 42120);
              v74 = v61;
              v75 = (_DWORD *)(v61 + 51764);
              v189 = jiffies - *(_QWORD *)(v61 + 42104);
              qdf_mem_set(s, 0x168u, 0);
              v84 = 0;
              v85 = -17;
              do
              {
                v86 = *(v75 - 1);
                if ( v86 )
                {
                  if ( v84 > 0x168 )
                  {
                    __break(0x5512u);
                    goto LABEL_133;
                  }
                  v84 += snprintf((char *)s + v84, 360LL - v84, "%d(%d,%d) ", v85 + 18, v86, *v75);
                }
                _CF = __CFADD__(v85++, 1);
                v75 += 4;
              }
              while ( !_CF );
              if ( v84 >= 0x168 )
                qdf_trace_msg(
                  0x33u,
                  3u,
                  "%s: log truncated",
                  v76,
                  v77,
                  v78,
                  v79,
                  v80,
                  v81,
                  v82,
                  v83,
                  "hdd_display_netif_queue_history_compact");
              v87 = *v72;
              v88 = (char *)(v58 + (int)v191);
              v89 = *(unsigned __int8 *)(*(_QWORD *)(v74 + 52824) + 8LL);
              v90 = *(_DWORD *)(v74 + 40);
              if ( v191 <= 0x99C )
                v91 = 2461 - v191;
              else
                v91 = 0;
              v92 = jiffies_to_msecs(v73);
              v93 = jiffies_to_msecs(v189);
              v94 = snprintf(v88, v91, "[%d %d] (%d) %u/%ums %s|", v89, v90, v87, v92, v93, (const char *)s);
              hdd_adapter_dev_put_debug(v74, 0x21u, v95, v96, v97, v98, v99, v100, v101, v102);
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (*(_DWORD *)(v186 + 16) & 0xF0000) != 0
                || (*(_DWORD *)(v186 + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(v190 + 32);
                v58 = v187;
                v61 = v188;
                if ( !v188 )
                  goto LABEL_84;
              }
              else
              {
                raw_spin_lock_bh(v190 + 32);
                *((_QWORD *)v190 + 5) |= 1uLL;
                v58 = v187;
                v61 = v188;
                if ( !v188 )
                  goto LABEL_84;
              }
              v192 = nullptr;
              v103 = qdf_list_peek_next((_QWORD *)v190 + 6, (_QWORD *)(v61 + 8), &v192);
              v112 = v192 - 1;
              if ( (_DWORD)v103 )
                v113 = nullptr;
              else
                v113 = v192 - 1;
              if ( (__int64 *)v61 != v113 )
              {
                if ( v113 )
                {
                  v114 = v113[4];
                  if ( v114 )
                  {
                    ++*(_DWORD *)(v186 + 16);
                    v115 = *(_QWORD *)(v114 + 1320);
                    v116 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v115);
                    do
                      v117 = __ldxr(v116);
                    while ( __stxr(v117 + 1, v116) );
                    v118 = *(_QWORD *)(v186 + 16) - 1LL;
                    *(_DWORD *)(v186 + 16) = v118;
                    if ( !v118 || !*(_QWORD *)(v186 + 16) )
                      preempt_schedule_notrace(v103);
                  }
                  _X8 = (unsigned int *)(v113 + 6582);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v138 = __ldxr(_X8);
                  while ( __stxr(v138 + 1, _X8) );
                  goto LABEL_85;
                }
LABEL_84:
                v112 = nullptr;
                goto LABEL_85;
              }
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Validation failed",
                v104,
                v105,
                v106,
                v107,
                v108,
                v109,
                v110,
                v111,
                "hdd_validate_next_adapter");
              hdd_adapter_dev_put_debug(v61, 0x21u, v120, v121, v122, v123, v124, v125, v126, v127);
              v112 = nullptr;
              v61 = 0;
LABEL_85:
              v128 = *((_QWORD *)v190 + 5);
              if ( (v128 & 1) != 0 )
              {
                *((_QWORD *)v190 + 5) = v128 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v190 + 32);
              }
              else
              {
                raw_spin_unlock(v190 + 32);
              }
              v62 = v112;
              v191 += v94;
              if ( !v61 )
              {
                qdf_trace_msg(0x33u, 7u, "STATS |%s", v129, v130, v131, v132, v133, v134, v135, v136, v58);
                if ( v191 >= 0x99D )
                {
                  v156 = "%s: log string truncated";
                  v157 = "hdd_display_netif_queue_history_compact";
                  v158 = 3;
                  goto LABEL_129;
                }
                goto LABEL_130;
              }
            }
          }
        }
        v156 = "STATS |%s";
        v158 = 7;
        v157 = (const char *)v58;
LABEL_129:
        qdf_trace_msg(0x33u, v158, v156, v64, v65, v66, v67, v68, v69, v70, v71, v157);
LABEL_130:
        result = _qdf_mem_free(v58);
        goto LABEL_131;
      }
    }
    v62 = nullptr;
    goto LABEL_51;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v11 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v11 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v11 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 32);
  }
  else
  {
LABEL_133:
    raw_spin_lock_bh(v10 + 32);
    *((_QWORD *)v10 + 5) |= 1uLL;
  }
  s[0] = 0;
  v12 = qdf_list_peek_front((_QWORD *)v10 + 6, s);
  if ( (_DWORD)v12 || (v139 = (_QWORD *)s[0], v13 = s[0] - 8LL, s[0] == 8) )
  {
    v13 = 0;
LABEL_9:
    v14 = 0;
    goto LABEL_10;
  }
  v140 = *(__int64 *)((char *)&off_18 + s[0]);
  if ( v140 )
  {
    v141 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v141 + 16);
    v142 = *(_QWORD *)(v140 + 1320);
    v143 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v142);
    do
      v144 = __ldxr(v143);
    while ( __stxr(v144 + 1, v143) );
    v145 = *(_QWORD *)(v141 + 16) - 1LL;
    *(_DWORD *)(v141 + 16) = v145;
    if ( !v145 || !*(_QWORD *)(v141 + 16) )
    {
      v176 = v139;
      preempt_schedule_notrace(v12);
      v139 = v176;
    }
  }
  _X8 = (unsigned int *)v139 + 13163;
  __asm { PRFM            #0x11, [X8] }
  do
    v179 = __ldxr(_X8);
  while ( __stxr(v179 + 1, _X8) );
  s[0] = 0;
  v147 = qdf_list_peek_next((_QWORD *)v10 + 6, v139, s);
  if ( (_DWORD)v147 )
    goto LABEL_9;
  v148 = s[0];
  v14 = s[0] - 8LL;
  if ( s[0] != 8 )
  {
    v149 = *(__int64 *)((char *)&off_18 + s[0]);
    if ( v149 )
    {
      v150 = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(v150 + 16);
      v151 = *(_QWORD *)(v149 + 1320);
      v152 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v151);
      do
        v153 = __ldxr(v152);
      while ( __stxr(v153 + 1, v152) );
      v154 = *(_QWORD *)(v150 + 16) - 1LL;
      *(_DWORD *)(v150 + 16) = v154;
      if ( !v154 || !*(_QWORD *)(v150 + 16) )
        preempt_schedule_notrace(v147);
    }
    _X8 = (unsigned int *)(v148 + 52652);
    __asm { PRFM            #0x11, [X8] }
    do
      v183 = __ldxr(_X8);
    while ( __stxr(v183 + 1, _X8) );
  }
LABEL_10:
  v15 = *((_QWORD *)v10 + 5);
  if ( (v15 & 1) != 0 )
  {
    *((_QWORD *)v10 + 5) = v15 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(v10 + 32);
    if ( v13 )
      goto LABEL_12;
  }
  else
  {
    result = raw_spin_unlock(v10 + 32);
    if ( v13 )
    {
LABEL_12:
      v25 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( *(unsigned __int8 *)(*(_QWORD *)(v13 + 52824) + 8LL) != 255 )
          wlan_hdd_display_adapter_netif_queue_stats(v13);
        hdd_adapter_dev_put_debug(v13, 0x22u, v17, v18, v19, v20, v21, v22, v23, v24);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v25 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v25 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v10 + 32);
          if ( v14 )
            goto LABEL_22;
LABEL_14:
          v34 = 0;
          v13 = 0;
          v35 = *((_QWORD *)v10 + 5);
          if ( (v35 & 1) == 0 )
            goto LABEL_15;
LABEL_35:
          *((_QWORD *)v10 + 5) = v35 & 0xFFFFFFFFFFFFFFFELL;
          result = raw_spin_unlock_bh(v10 + 32);
          v14 = v34;
          if ( !v13 )
            break;
        }
        else
        {
          raw_spin_lock_bh(v10 + 32);
          *((_QWORD *)v10 + 5) |= 1uLL;
          if ( !v14 )
            goto LABEL_14;
LABEL_22:
          s[0] = 0;
          v36 = qdf_list_peek_next((_QWORD *)v10 + 6, (_QWORD *)(v14 + 8), s);
          v34 = s[0] - 8LL;
          if ( (_DWORD)v36 )
            v45 = 0;
          else
            v45 = s[0] - 8LL;
          if ( v14 == v45 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Validation failed",
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              "hdd_validate_next_adapter");
            hdd_adapter_dev_put_debug(v14, 0x22u, v26, v27, v28, v29, v30, v31, v32, v33);
            goto LABEL_14;
          }
          if ( v45 )
          {
            v46 = *(_QWORD *)(v45 + 32);
            if ( v46 )
            {
              ++*(_DWORD *)(v25 + 16);
              v47 = *(_QWORD *)(v46 + 1320);
              v48 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v47);
              do
                v49 = __ldxr(v48);
              while ( __stxr(v49 + 1, v48) );
              v50 = *(_QWORD *)(v25 + 16) - 1LL;
              *(_DWORD *)(v25 + 16) = v50;
              if ( !v50 || !*(_QWORD *)(v25 + 16) )
                preempt_schedule_notrace(v36);
            }
            _X8 = (unsigned int *)(v45 + 52660);
            __asm { PRFM            #0x11, [X8] }
            do
              v57 = __ldxr(_X8);
            while ( __stxr(v57 + 1, _X8) );
          }
          else
          {
            v34 = 0;
          }
          v13 = v14;
          v35 = *((_QWORD *)v10 + 5);
          if ( (v35 & 1) != 0 )
            goto LABEL_35;
LABEL_15:
          result = raw_spin_unlock(v10 + 32);
          v14 = v34;
          if ( !v13 )
            break;
        }
      }
    }
  }
LABEL_131:
  _ReadStatusReg(SP_EL0);
  return result;
}
