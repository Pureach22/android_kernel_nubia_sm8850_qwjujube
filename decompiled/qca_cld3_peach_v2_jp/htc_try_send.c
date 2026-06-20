__int64 __fastcall htc_try_send(__int64 result, _DWORD *a2, __int64 a3)
{
  _BYTE *v3; // x25
  __int64 v6; // x19
  int v7; // w5
  int v8; // w8
  int v9; // w6
  int v10; // w7
  int v11; // w22
  int v12; // w8
  int v13; // w25
  _QWORD *v14; // x22
  _QWORD *v15; // x26
  __int64 v16; // x0
  __int64 v17; // x8
  _DWORD *v18; // x8
  __int64 v19; // x0
  __int64 v20; // x8
  _QWORD *v21; // x9
  __int64 v22; // x0
  __int64 v23; // x8
  _QWORD *v24; // x8
  int v25; // w9
  _QWORD *v26; // x8
  _QWORD *v27; // x8
  int v28; // w8
  int v29; // w9
  unsigned __int64 StatusReg; // x8
  int v31; // w8
  bool v33; // w11
  _QWORD *v34; // x8
  _QWORD **v35; // x8
  int v36; // w9
  _QWORD *v37; // x8
  _QWORD *v38; // x10
  int v39; // w9
  int v41; // w26
  _QWORD *v42; // x8
  __int64 v43; // x9
  _QWORD *v44; // x10
  _QWORD *v45; // x9
  unsigned int v50; // w9
  signed int v51; // w9
  int *v52; // x23
  _QWORD **v53; // x27
  char v54; // w8
  int v55; // w8
  _QWORD *v56; // x8
  int v57; // w10
  _QWORD *v58; // x9
  __int64 v59; // x10
  _QWORD *v60; // x10
  char v61; // w8
  int v62; // w8
  int v63; // w21
  _QWORD *v64; // x8
  _QWORD *v65; // x9
  __int64 v66; // x10
  _QWORD *v67; // x10
  int v68; // w9
  _BOOL4 v69; // w21
  _QWORD **v70; // x28
  int v71; // w27
  unsigned int v72; // w22
  int v73; // w22
  unsigned int v74; // w1
  _DWORD *v75; // x26
  unsigned int v76; // w8
  unsigned int v77; // w9
  int v78; // w26
  int v79; // w8
  int v80; // w8
  int v81; // w1
  int v82; // w8
  _QWORD *v83; // x9
  __int64 v84; // x10
  _QWORD *v85; // x11
  _QWORD *v86; // x10
  unsigned int v89; // w9
  _BYTE *v90; // x23
  int v91; // w24
  unsigned int v92; // w22
  _QWORD **v93; // x28
  int *v94; // x25
  int v95; // w8
  int v96; // w26
  _QWORD *v97; // x26
  __int64 v98; // x8
  _QWORD *v99; // x9
  char v100; // w9
  int v101; // w5
  _QWORD *v102; // x8
  char v103; // w9
  unsigned int v106; // w9
  _QWORD *v107; // x22
  unsigned int v108; // w8
  __int64 v109; // x24
  _DWORD *v110; // x21
  __int64 v111; // x26
  __int64 v112; // x8
  __int64 v113; // x0
  __int64 v114; // x8
  int v115; // w8
  _QWORD *v116; // x8
  _QWORD *v117; // x8
  int v118; // w9
  int v119; // w8
  _QWORD *v120; // x8
  _QWORD *v121; // x10
  __int64 v122; // x9
  _QWORD *v123; // x9
  _QWORD *v124; // x22
  unsigned int v125; // w8
  __int64 v126; // x24
  _DWORD *v127; // x21
  __int64 v128; // x26
  __int64 v129; // x8
  __int64 v130; // x0
  __int64 v131; // x8
  int v132; // w8
  _QWORD *v133; // x8
  _QWORD *v134; // x8
  int v135; // w9
  __int64 v136; // x8
  _QWORD *v137; // x26
  int state; // w22
  __int64 v139; // x8
  _QWORD *v140; // x9
  __int64 v141; // x28
  __int64 v142; // x8
  int *v143; // x8
  int v144; // w8
  int v145; // w9
  char v146; // w10
  __int64 v147; // x8
  int v148; // w8
  int v149; // w24
  int v150; // w21
  int v151; // w0
  unsigned int v154; // w8
  int v155; // w28
  _QWORD *v156; // x8
  int v157; // w8
  __int64 v158; // x8
  _QWORD *v159; // x9
  _QWORD *v160; // x8
  char v161; // w9
  __int64 v162; // x8
  _QWORD *v163; // x8
  int v164; // w9
  unsigned int v167; // w9
  unsigned int v170; // w9
  unsigned int v173; // w9
  unsigned int v176; // w9
  unsigned int v179; // w9
  unsigned int v180; // w8
  int v181; // w9
  int *v182; // x27
  _BYTE *v183; // x26
  int v184; // w8
  int v185; // w22
  unsigned int v186; // w21
  int v187; // w23
  unsigned int v190; // w9
  unsigned __int64 v191; // x8
  _QWORD *v192; // x9
  _QWORD *v193; // x9
  int v194; // w8
  int v195; // w9
  __int64 v196; // x8
  unsigned int v198; // w10
  __int64 v199; // x8
  __int64 v200; // [xsp+0h] [xbp-A0h]
  int *v201; // [xsp+18h] [xbp-88h]
  _QWORD *v202; // [xsp+20h] [xbp-80h]
  _QWORD **v203; // [xsp+28h] [xbp-78h]
  unsigned int *v204; // [xsp+30h] [xbp-70h]
  int free_queue_number; // [xsp+3Ch] [xbp-64h]
  unsigned __int64 v206; // [xsp+40h] [xbp-60h]
  _DWORD *v207; // [xsp+48h] [xbp-58h]
  _QWORD *v208; // [xsp+50h] [xbp-50h] BYREF
  _QWORD **v209; // [xsp+58h] [xbp-48h]
  __int64 v210; // [xsp+60h] [xbp-40h]
  _QWORD *v211; // [xsp+68h] [xbp-38h] BYREF
  _QWORD *v212; // [xsp+70h] [xbp-30h]
  __int64 v213; // [xsp+78h] [xbp-28h]
  _QWORD *v214; // [xsp+80h] [xbp-20h] BYREF
  _QWORD **v215; // [xsp+88h] [xbp-18h] BYREF
  _QWORD v216[2]; // [xsp+90h] [xbp-10h] BYREF

  v3 = &unk_B000;
  v6 = result;
  v216[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v209 = nullptr;
  v210 = 0;
  v208 = nullptr;
  if ( (dword_B0B4 & 0x100) != 0 )
  {
    if ( a3 )
      v7 = *(_DWORD *)(a3 + 16);
    else
      v7 = 0;
    result = qdf_trace_msg(56, 2, "%s: +htc_try_send (Queue:%pK Depth:%d)\n", "htc_try_send", (const void *)a3, v7);
  }
  LODWORD(v210) = 0;
  v208 = &v208;
  v209 = &v208;
  if ( a3 )
  {
    v8 = *(_DWORD *)(a3 + 16);
    if ( !v8 )
    {
      ++*(_DWORD *)(v6 + 3468);
      if ( (dword_B0B4 & 0x100) == 0 )
        goto LABEL_424;
      goto LABEL_42;
    }
    v9 = a2[30];
    v10 = a2[32];
    if ( v9 >= v10 )
      v11 = *(_DWORD *)(a3 + 16);
    else
      v11 = v9 + v8 - v10;
    if ( v11 >= 1 )
    {
      if ( (dword_B0B4 & 0x100) != 0 )
        result = qdf_trace_msg(
                   56,
                   2,
                   "%s: Endpoint %d, TX queue will overflow :%d , Tx Depth:%d, Max:%d\n",
                   "htc_try_send",
                   *a2,
                   v11,
                   v9,
                   v10);
      if ( *((_QWORD *)a2 + 5) )
      {
        v12 = *(_DWORD *)(a3 + 16);
        v13 = v12 - v11;
        if ( v12 - v11 < 0 )
        {
          result = printk(
                     &unk_881311,
                     "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_send.c",
                     1534,
                     "goodPkts >= 0");
        }
        else if ( v12 != v11 )
        {
          v41 = 0;
          do
          {
            v42 = *(_QWORD **)(a3 + 8);
            if ( v42 == (_QWORD *)a3 )
              goto LABEL_75;
            v43 = *v42;
            v44 = (_QWORD *)v42[1];
            if ( v44 )
              *v44 = v43;
            if ( v43 )
              *(_QWORD *)(v43 + 8) = v42[1];
            *v42 = v42;
            v42[1] = v42;
            if ( !v42 )
            {
LABEL_75:
              result = printk(
                         &unk_881311,
                         "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_send.c",
                         1541,
                         "pPacket");
            }
            else
            {
              v45 = v208;
              --*(_DWORD *)(a3 + 16);
              *v42 = v45;
              v42[1] = &v208;
              if ( v45 )
                v45[1] = v42;
              v208 = v42;
              LODWORD(v210) = v210 + 1;
            }
            ++v41;
          }
          while ( v41 < v13 );
        }
        v14 = *(_QWORD **)(a3 + 8);
        if ( v14 != (_QWORD *)a3 )
        {
          do
          {
            v15 = (_QWORD *)v14[1];
            if ( (dword_B0B4 & 0x100) != 0 )
              qdf_trace_msg(56, 2, "%s: Indicating overflowed TX packet: %pK\n", "htc_try_send", v14);
            v16 = v14[12];
            v17 = *(_QWORD *)(v16 + 40);
            if ( v17 )
              *(_QWORD *)(v16 + 40) = v17 + 8;
            skb_pull(v16, 8);
            *((_DWORD *)v14 + 18) &= ~2u;
            v18 = *((_DWORD **)a2 + 5);
            v19 = *((_QWORD *)a2 + 1);
            if ( *(v18 - 1) != -1198954387 )
              __break(0x8228u);
            result = ((__int64 (__fastcall *)(__int64, _QWORD *))v18)(v19, v14);
            if ( (_DWORD)result != 1 )
            {
              v20 = *v14;
              v21 = (_QWORD *)v14[1];
              if ( v21 )
                *v21 = v20;
              if ( v20 )
                *(_QWORD *)(v20 + 8) = v14[1];
              *v14 = v14;
              v14[1] = v14;
              --*(_DWORD *)(a3 + 16);
              v22 = v14[12];
              v23 = *(_QWORD *)(v22 + 40);
              if ( v23 )
                *(_QWORD *)(v22 + 40) = v23 - 8;
              result = skb_push(v22, 8);
              v24 = v208;
              v25 = *((_DWORD *)v14 + 18) | 2;
              *v14 = v208;
              v14[1] = &v208;
              *((_DWORD *)v14 + 18) = v25;
              if ( v24 )
                v24[1] = v14;
              v208 = v14;
              LODWORD(v210) = v210 + 1;
            }
            v14 = v15;
          }
          while ( v15 != (_QWORD *)a3 );
        }
        v3 = &unk_B000;
        if ( (_DWORD)v210 )
          goto LABEL_44;
        ++*(_DWORD *)(v6 + 3472);
        if ( (dword_B0B4 & 0x100) == 0 )
          goto LABEL_424;
LABEL_42:
        result = qdf_trace_msg(56, 2, "%s: -htc_try_send: %d\n", "htc_try_send", 1);
        goto LABEL_424;
      }
    }
    if ( *(_QWORD *)a3 != a3 || *(_QWORD *)(a3 + 8) != a3 )
    {
      *(_QWORD *)(*(_QWORD *)a3 + 8LL) = &v208;
      v26 = v208;
      **(_QWORD **)(a3 + 8) = v208;
      v26[1] = *(_QWORD *)(a3 + 8);
      v27 = *(_QWORD **)a3;
      *(_QWORD *)a3 = a3;
      *(_QWORD *)(a3 + 8) = a3;
      v208 = v27;
    }
    v28 = *(_DWORD *)(a3 + 16);
    v29 = v210;
    *(_DWORD *)(a3 + 16) = 0;
    LODWORD(v210) = v29 + v28;
  }
LABEL_44:
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v6 + 2992);
    v31 = v210;
    if ( !(_DWORD)v210 )
      goto LABEL_61;
  }
  else
  {
    raw_spin_lock_bh(v6 + 2992);
    *(_QWORD *)(v6 + 3000) |= 1uLL;
    v31 = v210;
    if ( !(_DWORD)v210 )
      goto LABEL_61;
  }
  v33 = v208 == &v208 && v209 == &v208;
  if ( *(_BYTE *)(v6 + 3560) == 1 )
  {
    if ( !v33 )
    {
      *v209 = a2 + 26;
      v34 = v208;
      **((_QWORD **)a2 + 14) = v208;
      v34[1] = *((_QWORD *)a2 + 14);
      v35 = v209;
      v208 = &v208;
      v209 = &v208;
      *((_QWORD *)a2 + 14) = v35;
      v31 = v210;
    }
    v36 = a2[30];
    LODWORD(v210) = 0;
    a2[30] = v36 + v31;
    *(_BYTE *)(v6 + 3560) = 0;
  }
  else
  {
    if ( !v33 )
    {
      v208[1] = a2 + 26;
      v37 = *((_QWORD **)a2 + 13);
      *v209 = v37;
      v38 = v208;
      v37[1] = v209;
      v31 = v210;
      *((_QWORD *)a2 + 13) = v38;
    }
    v39 = a2[30];
    LODWORD(v210) = 0;
    v208 = &v208;
    v209 = &v208;
    a2[30] = v39 + v31;
  }
LABEL_61:
  _X8 = a2 + 69;
  __asm { PRFM            #0x11, [X8] }
  do
  {
    v50 = __ldxr(_X8);
    v51 = v50 + 1;
  }
  while ( __stlxr(v51, _X8) );
  __dmb(0xBu);
  if ( v51 >= 2 )
  {
    __asm { PRFM            #0x11, [X8] }
    do
      v198 = __ldxr(_X8);
    while ( __stxr(v198 - 1, _X8) );
    v199 = *(_QWORD *)(v6 + 3000);
    if ( (v199 & 1) != 0 )
    {
      *(_QWORD *)(v6 + 3000) = v199 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(v6 + 2992);
      if ( (dword_B0B4 & 0x100) == 0 )
        goto LABEL_424;
    }
    else
    {
      result = raw_spin_unlock(v6 + 2992);
      if ( (dword_B0B4 & 0x100) == 0 )
        goto LABEL_424;
    }
    result = qdf_trace_msg(56, 2, "%s: -htc_try_send (busy)\n", "htc_try_send");
    goto LABEL_424;
  }
  if ( (a2[75] & 1) != 0 )
    free_queue_number = 0;
  else
    free_queue_number = (unsigned __int16)hif_get_free_queue_number(*(_QWORD *)v6, *((_BYTE *)a2 + 136));
  v52 = a2 + 30;
  if ( !a2[30] )
    goto LABEL_421;
  v53 = (_QWORD **)(a2 + 26);
  v200 = v6 + 8;
  v203 = (_QWORD **)(a2 + 28);
  v204 = (unsigned int *)(v6 + 3564);
  v206 = _ReadStatusReg(SP_EL0);
  v207 = a2 + 56;
  v201 = a2 + 30;
  v202 = a2 + 26;
  while ( 2 )
  {
    if ( (*((_BYTE *)a2 + 301) & 1) != 0 && (a2[75] & 1) == 0 && !free_queue_number )
    {
      hif_schedule_ce_tasklet();
      goto LABEL_421;
    }
    if ( (a2[75] & 1) == 0 )
    {
      v61 = v3[181];
      v215 = nullptr;
      v216[0] = 0;
      v214 = nullptr;
      if ( (v61 & 1) != 0 )
        qdf_trace_msg(56, 2, "%s: +get_htc_send_packets %d resources\n", "get_htc_send_packets", free_queue_number);
      v62 = *((unsigned __int16 *)a2 + 2);
      v63 = 0;
      v214 = &v214;
      v215 = &v214;
      LODWORD(v216[0]) = 0;
      if ( v62 == 256 )
      {
        v64 = *v203;
        if ( *v203 == v53 )
        {
          v63 = 0;
        }
        else
        {
          v63 = 0;
          do
          {
            v65 = (_QWORD *)v64[1];
            if ( *((_WORD *)v64 + 28) == 12 )
            {
              v66 = *v64;
              if ( v65 )
                *v65 = v66;
              if ( v66 )
                *(_QWORD *)(v66 + 8) = v64[1];
              *v64 = v64;
              v64[1] = v64;
              v67 = v214;
              --*v52;
              *v64 = v67;
              v64[1] = &v214;
              if ( v67 )
                v67[1] = v64;
              v214 = v64;
              v63 = ++LODWORD(v216[0]);
            }
            v64 = v65;
          }
          while ( v65 != v53 );
        }
      }
      v90 = v3;
      if ( v63 )
        v53 = &v214;
      if ( free_queue_number < 1 )
        goto LABEL_274;
      v91 = free_queue_number;
      v92 = 0;
      if ( v63 )
        v93 = &v215;
      else
        v93 = (_QWORD **)(a2 + 28);
      if ( v63 )
        v94 = (int *)v216;
      else
        v94 = a2 + 30;
      while ( 1 )
      {
        if ( v63 )
        {
          if ( (unsigned int)hif_system_pm_state_check(*(_QWORD *)v6) )
            goto LABEL_274;
        }
        else
        {
          v96 = *((unsigned __int16 *)a2 + 2);
          if ( v96 == 768 )
            v92 = 3;
          else
            v92 = 2;
          if ( (unsigned int)hif_rtpm_get(0, v92) )
          {
            if ( (int)v210 >= 1 && (dword_B0B4 & 2) != 0 )
              qdf_trace_msg(56, 2, "%s:  pQueue depth: %d\n", "get_htc_send_packets", v210);
            if ( *v201 )
            {
              v124 = *v203;
              if ( *v203 )
              {
                v125 = *((_DWORD *)v124 + 12);
                if ( v125 <= 8 )
                {
                  v126 = v200 + 328LL * v125;
                  v127 = *(_DWORD **)(v126 + 96);
                  if ( v127 )
                  {
                    v128 = v124[12];
                    v129 = *(_QWORD *)(v128 + 40);
                    if ( v129 )
                      *(_QWORD *)(v128 + 40) = v129 + 8;
                    skb_pull(v128, 8);
                    v130 = *(_QWORD *)(v126 + 8);
                    if ( *(v127 - 1) != 1226475842 )
                      __break(0x8235u);
                    ((void (__fastcall *)(__int64, _QWORD *))v127)(v130, v124);
                    v131 = *(_QWORD *)(v128 + 40);
                    if ( v131 )
                      *(_QWORD *)(v128 + 40) = v131 - 8;
                    skb_push(v128, 8);
                  }
                }
              }
            }
            goto LABEL_274;
          }
          if ( v96 != 768 )
          {
            _X8 = (unsigned int *)(v6 + 3568);
            __asm { PRFM            #0x11, [X8] }
            do
              v106 = __ldxr(_X8);
            while ( __stxr(v106 + 1, _X8) );
          }
          if ( (unsigned int)hif_system_pm_state_check(*(_QWORD *)v6) )
          {
            hif_rtpm_put(4, v92);
            if ( v96 != 768 )
            {
              _X8 = (unsigned int *)(v6 + 3568);
              __asm { PRFM            #0x11, [X8] }
              do
                v179 = __ldxr(_X8);
              while ( __stxr(v179 - 1, _X8) );
            }
            goto LABEL_274;
          }
        }
        v97 = *v93;
        if ( *v93 == v53 )
          goto LABEL_434;
        v98 = *v97;
        v99 = (_QWORD *)v97[1];
        if ( v99 )
          *v99 = v98;
        if ( v98 )
          *(_QWORD *)(v98 + 8) = v97[1];
        *v97 = v97;
        v97[1] = v97;
        if ( !v97 )
        {
LABEL_434:
          if ( !v63 )
          {
            hif_rtpm_put(4, v92);
            if ( (unsigned __int8)v92 == 2 )
            {
              _X8 = (unsigned int *)(v6 + 3568);
              __asm { PRFM            #0x11, [X8] }
              do
                v170 = __ldxr(_X8);
              while ( __stxr(v170 - 1, _X8) );
            }
          }
LABEL_274:
          v3 = v90;
          v52 = a2 + 30;
          v53 = (_QWORD **)(a2 + 26);
          v132 = v216[0];
          if ( LODWORD(v216[0]) && *((_WORD *)a2 + 2) == 256 )
          {
            if ( v214 != &v214 || v215 != &v214 )
            {
              *v215 = v202;
              v133 = v214;
              **v203 = v214;
              v133[1] = *v203;
              v134 = v215;
              v214 = &v214;
              v215 = &v214;
              *v203 = v134;
              v132 = v216[0];
            }
            v135 = *v201;
            LODWORD(v216[0]) = 0;
            *v201 = v135 + v132;
          }
          if ( (v3[181] & 1) != 0 )
            qdf_trace_msg(56, 2, "%s: -get_htc_send_packets\n", "get_htc_send_packets");
          goto LABEL_282;
        }
        v100 = v90[181];
        v101 = *v94 - 1;
        *v94 = v101;
        if ( (v100 & 1) != 0 )
          qdf_trace_msg(56, 2, "%s:  Got packet:%pK , New Queue Depth: %d\n", "get_htc_send_packets", v97, v101);
        v102 = v208;
        *((_BYTE *)v97 + 64) = 0;
        *((_DWORD *)v97 + 15) = 0;
        *v97 = v102;
        v97[1] = &v208;
        if ( v102 )
          v102[1] = v97;
        v103 = *((_BYTE *)v97 + 72);
        v208 = v97;
        LODWORD(v210) = v210 + 1;
        if ( (v103 & 1) != 0 )
        {
          _VF = __OFSUB__(v91--, 1);
          if ( (v91 < 0) ^ _VF | (v91 == 0) )
            goto LABEL_274;
        }
        else
        {
          v95 = ((*(unsigned __int8 *)(v97[12] + 68LL) >> 2) & 1) + 1;
          _VF = __OFSUB__(v91, v95);
          v91 -= v95;
          if ( (v91 < 0) ^ _VF | (v91 == 0) )
            goto LABEL_274;
        }
      }
    }
    v54 = v3[181];
    v215 = nullptr;
    v216[0] = 0;
    v213 = 0;
    v214 = nullptr;
    v211 = nullptr;
    v212 = nullptr;
    if ( (v54 & 1) != 0 )
      qdf_trace_msg(56, 2, "%s: +get_htc_send_packets_credit_based\n", "get_htc_send_packets_credit_based");
    v55 = *((unsigned __int16 *)a2 + 2);
    v214 = &v214;
    v215 = &v214;
    LODWORD(v216[0]) = 0;
    if ( v55 != 256 )
    {
      v68 = 0;
      LODWORD(v213) = 0;
      v211 = &v211;
      v212 = &v211;
      goto LABEL_123;
    }
    v56 = *v203;
    if ( *v203 == v53 )
    {
      LODWORD(v213) = 0;
      v211 = &v211;
      v212 = &v211;
      goto LABEL_246;
    }
    v57 = 0;
    do
    {
      v58 = (_QWORD *)v56[1];
      if ( *((_WORD *)v56 + 28) == 12 )
      {
        v59 = *v56;
        if ( v58 )
          *v58 = v59;
        if ( v59 )
          *(_QWORD *)(v59 + 8) = v56[1];
        *v56 = v56;
        v56[1] = v56;
        v60 = v214;
        --*v52;
        *v56 = v60;
        v56[1] = &v214;
        if ( v60 )
          v60[1] = v56;
        v214 = v56;
        v57 = ++LODWORD(v216[0]);
      }
      v56 = v58;
    }
    while ( v58 != v53 );
    if ( !v57 )
    {
      v119 = *((unsigned __int16 *)a2 + 2);
      v68 = 0;
      v211 = &v211;
      v212 = &v211;
      LODWORD(v213) = 0;
      if ( v119 == 256 )
      {
LABEL_246:
        v120 = *v203;
        if ( *v203 == v53 )
        {
          v68 = 0;
        }
        else
        {
          v68 = 0;
          do
          {
            v121 = (_QWORD *)v120[1];
            if ( *((_WORD *)v120 + 28) == 16 )
            {
              v122 = *v120;
              if ( v121 )
                *v121 = v122;
              if ( v122 )
                *(_QWORD *)(v122 + 8) = v120[1];
              *v120 = v120;
              v120[1] = v120;
              v123 = v211;
              --*v52;
              *v120 = v123;
              v120[1] = &v211;
              if ( v123 )
                v123[1] = v120;
              v211 = v120;
              v68 = v213 + 1;
              LODWORD(v213) = v213 + 1;
            }
            v120 = v121;
          }
          while ( v121 != v53 );
        }
      }
LABEL_123:
      v69 = v68 == 0;
      if ( v68 )
        v70 = &v211;
      else
        v70 = v53;
      v71 = 1;
      goto LABEL_127;
    }
    v71 = 0;
    v69 = 0;
    v70 = &v214;
LABEL_127:
    v72 = 0;
    while ( 1 )
    {
      if ( !v71 )
        goto LABEL_136;
      v73 = *((unsigned __int16 *)a2 + 2);
      v74 = v73 == 768 ? 3 : 2;
      if ( (unsigned int)hif_rtpm_get(0, v74) )
        break;
      if ( v73 == 768 )
      {
        v72 = 3;
LABEL_136:
        if ( !*((_DWORD *)v70 + 4) )
          goto LABEL_171;
        goto LABEL_137;
      }
      _X8 = (unsigned int *)(v6 + 3568);
      __asm { PRFM            #0x11, [X8] }
      do
        v89 = __ldxr(_X8);
      while ( __stxr(v89 + 1, _X8) );
      v72 = 2;
      if ( !*((_DWORD *)v70 + 4) )
      {
LABEL_171:
        if ( v71 )
        {
          hif_rtpm_put(4, v72);
          if ( (unsigned __int8)v72 == 2 )
          {
            _X8 = (unsigned int *)(v6 + 3568);
            __asm { PRFM            #0x11, [X8] }
            do
              v167 = __ldxr(_X8);
            while ( __stxr(v167 - 1, _X8) );
          }
        }
        goto LABEL_237;
      }
LABEL_137:
      v75 = v70[1];
      if ( !v75 )
        goto LABEL_171;
      if ( v69 && (unsigned int)hif_system_pm_state_check(*(_QWORD *)v6) )
      {
        if ( v71 )
        {
          hif_rtpm_put(4, v72);
          if ( (unsigned __int8)v72 == 2 )
          {
            _X8 = (unsigned int *)(v6 + 3568);
            __asm { PRFM            #0x11, [X8] }
            do
              v176 = __ldxr(_X8);
            while ( __stxr(v176 - 1, _X8) );
          }
        }
        goto LABEL_237;
      }
      if ( (v3[181] & 1) != 0 )
        qdf_trace_msg(
          56,
          2,
          "%s:  Got head packet:%pK , Queue Depth: %d\n",
          "get_htc_send_packets_credit_based",
          v75,
          *((_DWORD *)v70 + 4));
      v76 = a2[73];
      v77 = v75[11] + 8;
      if ( v77 <= v76 )
      {
        v78 = 1;
        if ( (v3[181] & 1) == 0 )
          goto LABEL_150;
LABEL_149:
        qdf_trace_msg(56, 2, "%s:  Credits Required:%d   Got:%d\n", "get_htc_send_packets_credit_based", v78, a2[72]);
        goto LABEL_150;
      }
      if ( v77 % v76 )
        v78 = v77 / v76 + 1;
      else
        v78 = v77 / v76;
      if ( (v3[181] & 1) != 0 )
        goto LABEL_149;
LABEL_150:
      v79 = *a2;
      if ( *a2 )
      {
        v80 = a2[72];
        v81 = v80 - v78;
        if ( v80 < v78 )
        {
          if ( v71 )
          {
            hif_rtpm_put(4, v72);
            if ( (unsigned __int8)v72 == 2 )
            {
              _X8 = (unsigned int *)(v6 + 3568);
              __asm { PRFM            #0x11, [X8] }
              do
                v173 = __ldxr(_X8);
              while ( __stxr(v173 - 1, _X8) );
            }
          }
          goto LABEL_237;
        }
        v82 = a2[74];
        a2[72] = v81;
        if ( v81 <= v82 )
        {
          if ( *((_WORD *)a2 + 2) == 256 )
            ((void (__fastcall *)(_QWORD))htc_credit_record)(0);
          LOBYTE(v79) = 1;
        }
        else
        {
          LOBYTE(v79) = 0;
        }
      }
      else
      {
        v78 = 0;
      }
      v83 = v70[1];
      if ( v83 != v70 )
      {
        v84 = *v83;
        v85 = (_QWORD *)v83[1];
        if ( v85 )
          *v85 = v84;
        if ( v84 )
          *(_QWORD *)(v84 + 8) = v83[1];
        *v83 = v83;
        v83[1] = v83;
        if ( v83 )
        {
          --*((_DWORD *)v70 + 4);
          v86 = v208;
          *((_DWORD *)v83 + 15) = v78;
          *((_BYTE *)v83 + 64) = v79;
          *v83 = v86;
          v83[1] = &v208;
          if ( v86 )
            v86[1] = v83;
          v208 = v83;
          LODWORD(v210) = v210 + 1;
        }
      }
    }
    if ( (int)v210 >= 1 && (dword_B0B4 & 2) != 0 )
      qdf_trace_msg(56, 2, "%s:  pQueue depth: %d\n", "get_htc_send_packets_credit_based", v210);
    if ( *((_DWORD *)v70 + 4) )
    {
      v107 = v70[1];
      if ( v107 )
      {
        v108 = *((_DWORD *)v107 + 12);
        if ( v108 <= 8 )
        {
          v109 = v200 + 328LL * v108;
          v110 = *(_DWORD **)(v109 + 96);
          if ( v110 )
          {
            v111 = v107[12];
            v112 = *(_QWORD *)(v111 + 40);
            if ( v112 )
              *(_QWORD *)(v111 + 40) = v112 + 8;
            skb_pull(v111, 8);
            v113 = *(_QWORD *)(v109 + 8);
            if ( *(v110 - 1) != 1226475842 )
              __break(0x8235u);
            ((void (__fastcall *)(__int64, _QWORD *))v110)(v113, v107);
            v114 = *(_QWORD *)(v111 + 40);
            if ( v114 )
              *(_QWORD *)(v111 + 40) = v114 - 8;
            skb_push(v111, 8);
          }
        }
      }
    }
LABEL_237:
    v115 = v216[0];
    v53 = (_QWORD **)(a2 + 26);
    if ( LODWORD(v216[0]) && *((_WORD *)a2 + 2) == 256 )
    {
      if ( v214 != &v214 || v215 != &v214 )
      {
        *v215 = v202;
        v116 = v214;
        **v203 = v214;
        v116[1] = *v203;
        v117 = v215;
        v214 = &v214;
        v215 = &v214;
        *v203 = v117;
        v115 = v216[0];
      }
      v118 = *v52;
      LODWORD(v216[0]) = 0;
      *v52 = v118 + v115;
    }
    if ( (v3[181] & 1) != 0 )
      qdf_trace_msg(56, 2, "%s: -get_htc_send_packets_credit_based\n", "get_htc_send_packets_credit_based");
LABEL_282:
    if ( !(_DWORD)v210 )
      goto LABEL_421;
    if ( (*((_BYTE *)a2 + 301) & 1) == 0 )
    {
      v136 = *(_QWORD *)(v6 + 3000);
      if ( (v136 & 1) != 0 )
      {
        *(_QWORD *)(v6 + 3000) = v136 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v6 + 2992);
      }
      else
      {
        raw_spin_unlock(v6 + 2992);
      }
    }
    hif_get_bus_type(*(_QWORD *)v6);
    if ( (v3[181] & 1) != 0 )
      qdf_trace_msg(56, 2, "%s: +htc_issue_packets: Queue: %pK, Pkts %d\n", "htc_issue_packets", &v208, v210);
    v137 = v209;
    if ( v209 == &v208 )
    {
      v155 = 0;
      if ( (v3[181] & 1) != 0 )
        goto LABEL_330;
    }
    else
    {
      state = 0;
      while ( 1 )
      {
        v139 = *v137;
        v140 = (_QWORD *)v137[1];
        if ( v140 )
          *v140 = v139;
        if ( v139 )
          *(_QWORD *)(v139 + 8) = v137[1];
        *v137 = v137;
        v137[1] = v137;
        if ( !v137 )
        {
LABEL_342:
          v155 = 0;
          if ( (v3[181] & 1) != 0 )
            goto LABEL_330;
          goto LABEL_331;
        }
        v141 = v137[12];
        LODWORD(v210) = v210 - 1;
        if ( !v141 )
          printk(&unk_881311, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_send.c", 796, "netbuf");
        if ( *((_BYTE *)a2 + 300) == 1 )
        {
          v142 = 72;
          if ( (*(_BYTE *)(v141 + 68) & 4) == 0 )
            v142 = 224;
          v143 = *(int **)(v141 + v142);
          if ( !v143 )
          {
            if ( (dword_B0B4 & 1) != 0 )
              qdf_trace_msg(56, 2, "%s: %s Invalid pHtcHdr\n", "htc_issue_packets", "htc_issue_packets");
            printk(&unk_881311, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_send.c", 811, "pHtcHdr");
            a2[72] += *((_DWORD *)v137 + 15);
            goto LABEL_355;
          }
          *v143 = (*((_DWORD *)v137 + 11) << 16)
                | (*((unsigned __int8 *)v137 + 64) << 8)
                | *((unsigned __int8 *)v137 + 48);
          v143[1] = (unsigned __int8)*((_DWORD *)v137 + 17) << 8;
          if ( (unsigned int)_qdf_nbuf_map(*(_QWORD *)(v6 + 3456), v137[12], 1) )
          {
            if ( (dword_B0B4 & 1) != 0 )
              qdf_trace_msg(56, 2, "%s: %s nbuf Map Fail Endpnt %pK\n", "htc_issue_packets", "htc_issue_packets", a2);
            *v137 = &v208;
            v156 = v209;
            v137[1] = v209;
            *v156 = v137;
            v209 = (_QWORD **)v137;
            LODWORD(v210) = v210 + 1;
LABEL_355:
            v155 = 16;
            goto LABEL_372;
          }
          *((_DWORD *)v137 + 18) |= 1u;
        }
        if ( (*((_BYTE *)a2 + 301) & 1) == 0 )
        {
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(v206 + 16) & 0xF0000) != 0
            || (*(_DWORD *)(v206 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v6 + 2992);
          }
          else
          {
            raw_spin_lock_bh(v6 + 2992);
            *(_QWORD *)(v6 + 3000) |= 1uLL;
          }
        }
        *v137 = *(_QWORD *)v207;
        v137[1] = v207;
        if ( *(_QWORD *)v207 )
          *(_QWORD *)(*(_QWORD *)v207 + 8LL) = v137;
        v144 = a2[60];
        v145 = a2[51];
        v146 = *((_BYTE *)a2 + 301);
        *((_QWORD *)a2 + 28) = v137;
        a2[60] = v144 + 1;
        a2[51] = v145 + 1;
        if ( (v146 & 1) == 0 )
        {
          v147 = *(_QWORD *)(v6 + 3000);
          if ( (v147 & 1) != 0 )
          {
            *(_QWORD *)(v6 + 3000) = v147 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v6 + 2992);
          }
          else
          {
            raw_spin_unlock(v6 + 2992);
          }
          hif_send_complete_check(*(_QWORD *)v6, *((unsigned __int8 *)a2 + 136), 0);
        }
        v148 = *((unsigned __int16 *)v137 + 28);
        if ( v148 == 15 )
        {
          state = hif_system_pm_get_state(*(_QWORD *)v6);
          _hif_system_pm_set_state(*(_QWORD *)v6, 2);
          v148 = *((unsigned __int16 *)v137 + 28);
        }
        *((_DWORD *)v137 + 26) = -559038737;
        if ( v148 == 13 )
        {
          v149 = 0;
          v150 = 1;
        }
        else if ( v148 == 14 )
        {
          _X10 = v6 + 3564;
          __asm { PRFM            #0x11, [X10] }
          do
            v154 = __ldxr(v204);
          while ( __stxr(v154 + 1, v204) );
          v150 = 0;
          v149 = 1;
        }
        else
        {
          v150 = 0;
          v149 = 0;
        }
        v151 = hif_send_head(*(_QWORD *)v6, *((_BYTE *)a2 + 136), *a2, *((_DWORD *)v137 + 11) + 8, v141, 0);
        if ( v151 )
          break;
        ++*(_DWORD *)(v6 + 3488);
        ++a2[52];
        if ( v150 )
          hif_rtpm_put(4, 3u);
        v137 = v209;
        if ( v209 == &v208 )
          goto LABEL_342;
      }
      v155 = v151;
      if ( v149 )
        htc_dec_return_htt_runtime_cnt(v6);
      if ( *((_WORD *)v137 + 28) == 15 )
        _hif_system_pm_set_state(*(_QWORD *)v6, state);
      ++*(_DWORD *)(v6 + 3488);
      ++a2[52];
      if ( v155 == 1 )
      {
        if ( *(_BYTE *)(v6 + 3563) == 1 && a2[80] >= 6u )
          hif_print_napi_stats(*(_QWORD *)v6);
      }
      else if ( (dword_B0B4 & 1) != 0 )
      {
        qdf_trace_msg(56, 2, "%s: hif_send Failed status:%d\n", "htc_issue_packets", v155);
      }
      if ( *((_BYTE *)a2 + 300) == 1 )
      {
        _qdf_nbuf_unmap(*(_QWORD *)(v6 + 3456), v137[12], 1);
        *((_DWORD *)v137 + 18) &= ~1u;
      }
      if ( (*((_BYTE *)a2 + 301) & 1) == 0 )
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v206 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v206 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v6 + 2992);
        }
        else
        {
          raw_spin_lock_bh(v6 + 2992);
          *(_QWORD *)(v6 + 3000) |= 1uLL;
        }
      }
      --*(_DWORD *)(v6 + 3488);
      v157 = a2[52] - 1;
      --a2[51];
      a2[52] = v157;
      v158 = *v137;
      v159 = (_QWORD *)v137[1];
      if ( v159 )
        *v159 = v158;
      if ( v158 )
        *(_QWORD *)(v158 + 8) = v137[1];
      *v137 = v137;
      v137[1] = v137;
      --a2[60];
      *v137 = &v208;
      v160 = v209;
      *((_DWORD *)v137 + 26) = 0;
      v137[1] = v160;
      *v160 = v137;
      v161 = *((_BYTE *)a2 + 301);
      v209 = (_QWORD **)v137;
      LODWORD(v210) = v210 + 1;
      if ( (v161 & 1) == 0 )
      {
        v162 = *(_QWORD *)(v6 + 3000);
        if ( (v162 & 1) != 0 )
        {
          *(_QWORD *)(v6 + 3000) = v162 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v6 + 2992);
        }
        else
        {
          raw_spin_unlock(v6 + 2992);
        }
      }
LABEL_372:
      v163 = v209;
      if ( v209 != &v208 )
      {
        v164 = a2[72];
        do
        {
          v137 = v163;
          v163 = (_QWORD *)v163[1];
          v164 += *((_DWORD *)v137 + 15);
          a2[72] = v164;
        }
        while ( v163 != &v208 );
      }
      if ( v155 == 1 && a2[80] < 6u )
      {
        v155 = 1;
        if ( (v3[181] & 1) != 0 )
          goto LABEL_330;
      }
      else
      {
        qdf_trace_msg(61, 4, "failed pkt:0x%pK status:%d endpoint:%d", v137, v155, *a2);
        if ( (v3[181] & 1) == 0 )
          goto LABEL_331;
LABEL_330:
        qdf_trace_msg(56, 2, "%s: -htc_issue_packets\n", "htc_issue_packets");
      }
    }
LABEL_331:
    if ( !v155 )
    {
      if ( a2[80] )
        a2[80] = 0;
      if ( (a2[75] & 1) != 0 )
      {
        if ( (*((_BYTE *)a2 + 301) & 1) == 0 )
        {
LABEL_338:
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(v206 + 16) & 0xF0000) != 0
            || (*(_DWORD *)(v206 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v6 + 2992);
          }
          else
          {
            raw_spin_lock_bh(v6 + 2992);
            *(_QWORD *)(v6 + 3000) |= 1uLL;
          }
        }
      }
      else
      {
        free_queue_number = (unsigned __int16)hif_get_free_queue_number(*(_QWORD *)v6, *((_BYTE *)a2 + 136));
        if ( (*((_BYTE *)a2 + 301) & 1) == 0 )
          goto LABEL_338;
      }
      if ( !*v52 )
        goto LABEL_421;
      continue;
    }
    break;
  }
  if ( v155 == 1 )
  {
    v180 = a2[80];
    if ( v180 <= 5 )
    {
      v181 = a2[81];
      v182 = v52;
      a2[80] = v180 + 1;
      v183 = v3;
      a2[81] = v181 + 1;
      goto LABEL_403;
    }
    v184 = a2[81];
    a2[80] = 0;
    a2[81] = v184 + 1;
  }
  v182 = v52;
  v183 = v3;
  qdf_trace_msg(61, 4, "htc_issue_packets, failed status:%dendpoint:%d, put it back to head ofcallersSendQueue", 1, *a2);
LABEL_403:
  v185 = *((unsigned __int16 *)a2 + 2);
  if ( v185 == 768 )
    v186 = 3;
  else
    v186 = 2;
  if ( (int)v210 >= 1 )
  {
    v187 = v210 + 1;
    do
    {
      hif_rtpm_put(4, v186);
      if ( v185 != 768 )
      {
        _X8 = (unsigned int *)(v6 + 3568);
        __asm { PRFM            #0x11, [X8] }
        do
          v190 = __ldxr(_X8);
        while ( __stxr(v190 - 1, _X8) );
      }
      --v187;
    }
    while ( v187 > 1 );
  }
  v3 = v183;
  if ( (*((_BYTE *)a2 + 301) & 1) == 0 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v191 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v191 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v191 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v6 + 2992);
    }
    else
    {
      raw_spin_lock_bh(v6 + 2992);
      *(_QWORD *)(v6 + 3000) |= 1uLL;
    }
  }
  if ( v208 != &v208 || v209 != &v208 )
  {
    *v209 = v202;
    v192 = v208;
    **v203 = v208;
    v192[1] = *v203;
    v193 = v209;
    v208 = &v208;
    v209 = &v208;
    *v203 = v193;
  }
  v194 = v210;
  v195 = *v182;
  LODWORD(v210) = 0;
  *v182 = v195 + v194;
LABEL_421:
  a2[69] = 0;
  v196 = *(_QWORD *)(v6 + 3000);
  if ( (v196 & 1) != 0 )
  {
    *(_QWORD *)(v6 + 3000) = v196 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(v6 + 2992);
    if ( (v3[181] & 1) != 0 )
LABEL_423:
      result = qdf_trace_msg(56, 2, "%s: -htc_try_send:\n", "htc_try_send");
  }
  else
  {
    result = raw_spin_unlock(v6 + 2992);
    if ( (v3[181] & 1) != 0 )
      goto LABEL_423;
  }
LABEL_424:
  _ReadStatusReg(SP_EL0);
  return result;
}
