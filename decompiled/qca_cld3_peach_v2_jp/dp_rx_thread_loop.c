__int64 __fastcall dp_rx_thread_loop(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x1
  unsigned __int64 current_comm; // x22
  unsigned int v12; // w20
  unsigned int current_pid; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned __int64 StatusReg; // x24
  unsigned __int64 v31; // x0
  unsigned int v32; // w27
  unsigned __int64 v33; // x28
  unsigned int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x0
  unsigned int v52; // w27
  __int64 v53; // x0
  __int64 v54; // x1
  __int64 v55; // x8
  __int64 **v56; // x28
  __int64 v57; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x27
  __int64 v67; // x8
  __int64 v68; // x9
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  int v77; // w22
  __int64 v78; // x8
  __int64 v79; // x8
  _DWORD *v80; // x8
  __int64 v81; // x1
  unsigned int (*v82)(void); // x8
  __int64 v83; // x22
  __int64 v84; // x0
  __int64 v85; // x8
  __int64 v86; // x9
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  unsigned int v95; // w27
  __int64 context; // x0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  __int64 v105; // x28
  _DWORD *v106; // x8
  __int64 v107; // x0
  __int64 v108; // x27
  __int64 j; // x22
  int v110; // w8
  __int64 v111; // x8
  unsigned __int8 *v112; // x28
  __int64 v113; // x8
  __int64 v114; // x8
  unsigned int *v115; // x8
  unsigned int v116; // w10
  __int64 v117; // x8
  unsigned __int64 v120; // x9
  int v121; // w9
  unsigned __int64 v124; // x12
  unsigned __int64 v127; // x8
  unsigned __int64 v128; // x0
  unsigned int v129; // w27
  unsigned __int64 v130; // x28
  unsigned int v131; // w0
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  __int64 v140; // x1
  unsigned __int64 v141; // x0
  unsigned int v142; // w27
  unsigned __int64 v143; // x28
  unsigned int v144; // w0
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  __int64 i; // x22
  __int64 v154; // x8
  __int64 v155; // x8
  unsigned int *v156; // x8
  unsigned int v157; // w10
  __int64 v158; // x8
  unsigned __int64 v165; // x9
  unsigned __int64 v168; // x8
  unsigned __int64 v171; // x8
  unsigned __int64 v172; // x0
  unsigned int v173; // w20
  unsigned __int64 v174; // x21
  unsigned int v175; // w0
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  __int64 v184; // x1
  __int64 v186; // [xsp+0h] [xbp-50h]
  int v187; // [xsp+10h] [xbp-40h]
  _QWORD v188[5]; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v189[2]; // [xsp+40h] [xbp-10h] BYREF

  v189[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    qdf_get_current_task();
    qdf_set_user_nice();
    qdf_set_wake_up_idle(1);
    qdf_event_set((__int64)(a1 + 16), v10);
    current_comm = qdf_get_current_comm();
    v12 = *a1;
    v186 = (__int64)(a1 + 96);
    current_pid = qdf_get_current_pid();
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: starting rx_thread (%s) id %d pid %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "dp_rx_thread_loop",
      current_comm,
      v12,
      current_pid);
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      qdf_trace_msg(0x45u, 8u, "%s: sleeping", v22, v23, v24, v25, v26, v27, v28, v29, "dp_rx_thread_loop", v186);
      if ( (*((_QWORD *)a1 + 53) & 2) != 0 || (*((_QWORD *)a1 + 53) & 4) != 0 || (*((_QWORD *)a1 + 53) & 0x10) != 0 )
      {
        v52 = 0;
      }
      else
      {
        memset(v188, 0, sizeof(v188));
        init_wait_entry(v188, 0);
        while ( 1 )
        {
          v51 = prepare_to_wait_event(a1 + 1136, v188, 1);
          if ( (*((_QWORD *)a1 + 53) & 2) != 0 || (*((_QWORD *)a1 + 53) & 4) != 0 || (*((_QWORD *)a1 + 53) & 0x10) != 0 )
            break;
          v52 = v51;
          if ( v51 )
            goto LABEL_15;
          schedule();
        }
        finish_wait(a1 + 1136, v188);
        v52 = 0;
      }
LABEL_15:
      qdf_trace_msg(0x45u, 8u, "%s: woken up", v43, v44, v45, v46, v47, v48, v49, v50, "dp_rx_thread_loop");
      v53 = qdf_status_from_os_return(v52);
      if ( (_DWORD)v53 == 48 )
        break;
      _X8 = (unsigned __int64 *)(a1 + 424);
      __asm { PRFM            #0x11, [X8] }
      do
        v165 = __ldxr(_X8);
      while ( __stxr(v165 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
      do
      {
        _X8 = (unsigned __int64 *)(a1 + 424);
        __asm { PRFM            #0x11, [X8] }
        do
          v124 = __ldxr(_X8);
        while ( __stlxr(v124 & 0xFFFFFFFFFFFEFFFFLL, _X8) );
        __dmb(0xBu);
        v187 = v124;
        if ( (v124 & 0x10000) != 0 )
        {
          _X9 = (unsigned __int64 *)(a1 + 424);
          __asm { PRFM            #0x11, [X9] }
          do
            v171 = __ldxr(_X9);
          while ( __stlxr(v171 & 0xFFFFFFFFFFFFFFFBLL, _X9) );
          __dmb(0xBu);
          if ( (v171 & 4) != 0 )
            v53 = qdf_event_set((__int64)(a1 + 56), v54);
          for ( i = 3904; i != 3952; i += 8 )
          {
            v154 = *(_QWORD *)&a1[i];
            if ( v154 )
            {
              ++*(_DWORD *)(StatusReg + 16);
              v155 = *(_QWORD *)(v154 + 1320);
              v156 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v155);
              do
                v157 = __ldxr(v156);
              while ( __stxr(v157 - 1, v156) );
              v158 = *(_QWORD *)(StatusReg + 16) - 1LL;
              *(_DWORD *)(StatusReg + 16) = v158;
              if ( !v158 || !*(_QWORD *)(StatusReg + 16) )
                v53 = preempt_schedule_notrace(v53);
              *(_QWORD *)&a1[i] = 0;
              ++*((_DWORD *)a1 + 140);
            }
          }
          v31 = qdf_get_current_comm();
          v32 = *a1;
          v33 = v31;
          v34 = qdf_get_current_pid();
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: shutting down (%s) id %d pid %d",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "dp_rx_thread_sub_loop",
            v33,
            v32,
            v34);
          goto LABEL_4;
        }
        v55 = *((_QWORD *)a1 + 87);
        v188[0] = 0;
        v189[0] = 0;
        v56 = **(__int64 ****)(v55 + 8);
        if ( v56 )
        {
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: enter: qlen  %u",
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            "dp_rx_thread_process_nbufq",
            *((unsigned int *)a1 + 114));
          v57 = skb_dequeue(a1 + 440);
          if ( v57 )
          {
            v66 = v57;
            if ( (*(_BYTE *)(v57 + 75) & 0xFE) != 0 )
            {
              v67 = *(_QWORD *)(v57 + 216) + *(unsigned int *)(v57 + 212);
              v68 = *(_QWORD *)(v67 + 8);
              *(_QWORD *)(v67 + 8) = 0;
              *(_QWORD *)v57 = v68;
            }
            qdf_trace_msg(
              0x45u,
              8u,
              "%s: Dequeued %pK nbuf_list",
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              "dp_rx_tm_thread_dequeue",
              v57);
            v77 = *(unsigned __int8 *)(v66 + 75)
                + *(unsigned __int16 *)(*(_QWORD *)(v66 + 216) + *(unsigned int *)(v66 + 212) + 6LL);
            *((_DWORD *)a1 + 127) += v77;
            v78 = *(unsigned int *)(StatusReg + 40);
            if ( (unsigned int)v78 > 0x1F )
LABEL_104:
              __break(0x5512u);
            while ( 1 )
            {
              *(_DWORD *)&a1[4 * v78 + 564] += v77;
              if ( *v56 )
              {
                v79 = **v56;
                if ( v79 )
                {
                  v80 = *(_DWORD **)(v79 + 744);
                  if ( v80 )
                  {
                    v81 = *(unsigned __int16 *)(v66 + 86);
                    if ( *(v80 - 1) != 1263778316 )
                      __break(0x8228u);
                    ((void (__fastcall *)(__int64 **, __int64, _QWORD *, _QWORD *))v80)(v56, v81, v188, v189);
                  }
                }
              }
              else
              {
                qdf_trace_msg(
                  0x89u,
                  8u,
                  "%s: Invalid Instance:",
                  v69,
                  v70,
                  v71,
                  v72,
                  v73,
                  v74,
                  v75,
                  v76,
                  "cdp_get_os_rx_handles_from_vdev");
              }
              qdf_trace_msg(
                0x45u,
                8u,
                "%s: rx_thread %pK sending packet %pK to stack",
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                v75,
                v76,
                "dp_rx_thread_process_nbufq",
                a1,
                v66);
              v82 = (unsigned int (*)(void))v188[0];
              if ( !v188[0] || !v189[0] )
                goto LABEL_37;
              if ( *(_DWORD *)(v188[0] - 4LL) != 424933381 )
                __break(0x8228u);
              if ( !v82() )
              {
                *((_DWORD *)a1 + 128) += v77;
              }
              else
              {
LABEL_37:
                *((_DWORD *)a1 + 135) += v77;
                do
                {
                  v83 = *(_QWORD *)v66;
                  _qdf_nbuf_free(v66);
                  v66 = v83;
                }
                while ( v83 );
              }
              v84 = skb_dequeue(a1 + 440);
              if ( !v84 )
                break;
              v66 = v84;
              if ( (*(_BYTE *)(v84 + 75) & 0xFE) != 0 )
              {
                v85 = *(_QWORD *)(v84 + 216) + *(unsigned int *)(v84 + 212);
                v86 = *(_QWORD *)(v85 + 8);
                *(_QWORD *)(v85 + 8) = 0;
                *(_QWORD *)v84 = v86;
              }
              qdf_trace_msg(
                0x45u,
                8u,
                "%s: Dequeued %pK nbuf_list",
                v58,
                v59,
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                "dp_rx_tm_thread_dequeue",
                v84);
              v77 = *(unsigned __int8 *)(v66 + 75)
                  + *(unsigned __int16 *)(*(_QWORD *)(v66 + 216) + *(unsigned int *)(v66 + 212) + 6LL);
              *((_DWORD *)a1 + 127) += v77;
              v78 = *(unsigned int *)(StatusReg + 40);
              if ( (unsigned int)v78 >= 0x20 )
                goto LABEL_104;
            }
          }
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: Dequeued %pK nbuf_list",
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            "dp_rx_tm_thread_dequeue",
            0);
          v53 = qdf_trace_msg(
                  0x45u,
                  8u,
                  "%s: exit: qlen  %u",
                  v87,
                  v88,
                  v89,
                  v90,
                  v91,
                  v92,
                  v93,
                  v94,
                  "dp_rx_thread_process_nbufq",
                  *((unsigned int *)a1 + 114));
        }
        else
        {
          v53 = qdf_trace_msg(
                  0x45u,
                  2u,
                  "%s: invalid soc!",
                  v22,
                  v23,
                  v24,
                  v25,
                  v26,
                  v27,
                  v28,
                  v29,
                  "dp_rx_thread_process_nbufq");
        }
        if ( (*((_QWORD *)a1 + 53) & 0x10LL) != 0 )
          v95 = 1;
        else
          v95 = *((_DWORD *)a1 + 104);
        if ( v95 )
        {
          context = dp_get_context();
          if ( context )
          {
            v105 = context;
            qdf_trace_msg(
              0x45u,
              8u,
              "%s: flushing packets for thread %u",
              v97,
              v98,
              v99,
              v100,
              v101,
              v102,
              v103,
              v104,
              "dp_rx_thread_gro_flush",
              *a1);
            *(_DWORD *)(StatusReg + 16) += 512;
            v106 = *(_DWORD **)(v105 + 448);
            if ( *(v106 - 1) != -889664236 )
              __break(0x8228u);
            v107 = ((__int64 (__fastcall *)(unsigned __int8 *, _QWORD))v106)(a1 + 704, v95);
            v53 = local_bh_enable_2(v107);
            ++*((_DWORD *)a1 + 129);
          }
          else
          {
            v53 = qdf_trace_msg(
                    0x45u,
                    2u,
                    "%s: DP context is NULL",
                    v97,
                    v98,
                    v99,
                    v100,
                    v101,
                    v102,
                    v103,
                    v104,
                    "dp_rx_thread_gro_flush");
          }
          *((_DWORD *)a1 + 104) = 0;
        }
        v108 = (__int64)(a1 + 176);
        for ( j = 0; j != 6; ++j )
        {
          v111 = 1LL << j;
          _X10 = (unsigned __int64 *)(a1 + 432);
          __asm { PRFM            #0x11, [X10] }
          do
            v120 = __ldxr(_X10);
          while ( __stlxr(v120 & ~v111, _X10) );
          __dmb(0xBu);
          if ( (v120 & v111) != 0 )
          {
            v112 = &a1[8 * j];
            v113 = *((_QWORD *)v112 + 488);
            if ( v113 )
            {
              ++*(_DWORD *)(StatusReg + 16);
              v114 = *(_QWORD *)(v113 + 1320);
              v115 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v114);
              do
                v116 = __ldxr(v115);
              while ( __stxr(v116 - 1, v115) );
              v117 = *(_QWORD *)(StatusReg + 16) - 1LL;
              *(_DWORD *)(StatusReg + 16) = v117;
              if ( !v117 || !*(_QWORD *)(StatusReg + 16) )
                preempt_schedule_notrace(v53);
              v110 = *((_DWORD *)a1 + 140);
              *((_QWORD *)v112 + 488) = 0;
              *((_DWORD *)a1 + 140) = v110 + 1;
            }
            v53 = qdf_event_set(v108, v54);
          }
          v108 += 40;
        }
        _X9 = (unsigned __int64 *)(a1 + 424);
        __asm { PRFM            #0x11, [X9] }
        do
          v127 = __ldxr(_X9);
        while ( __stlxr(v127 & 0xFFFFFFFFFFFFFFEFLL, _X9) );
        __dmb(0xBu);
        if ( (v127 & 0x10) == 0 )
          break;
        v121 = *((_DWORD *)a1 + 114);
        ++*((_DWORD *)a1 + 130);
      }
      while ( v121 );
      _X9 = (unsigned __int64 *)(a1 + 424);
      __asm { PRFM            #0x11, [X9] }
      do
        v168 = __ldxr(_X9);
      while ( __stlxr(v168 & 0xFFFFFFFFFFFFFFFBLL, _X9) );
      __dmb(0xBu);
      if ( (v168 & 4) != 0 )
      {
        v128 = qdf_get_current_comm();
        v129 = *a1;
        v130 = v128;
        v131 = qdf_get_current_pid();
        qdf_trace_msg(
          0x45u,
          8u,
          "%s: received suspend ind (%s) id %d pid %d",
          v132,
          v133,
          v134,
          v135,
          v136,
          v137,
          v138,
          v139,
          "dp_rx_thread_sub_loop",
          v130,
          v129,
          v131);
        qdf_event_set((__int64)(a1 + 56), v140);
        v141 = qdf_get_current_comm();
        v142 = *a1;
        v143 = v141;
        v144 = qdf_get_current_pid();
        qdf_trace_msg(
          0x45u,
          8u,
          "%s: waiting for resume (%s) id %d pid %d",
          v145,
          v146,
          v147,
          v148,
          v149,
          v150,
          v151,
          v152,
          "dp_rx_thread_sub_loop",
          v143,
          v142,
          v144);
        qdf_wait_single_event(v186, 0);
      }
LABEL_4:
      ;
    }
    while ( (v187 & 0x10000) == 0 );
    v172 = qdf_get_current_comm();
    v173 = *a1;
    v174 = v172;
    v175 = qdf_get_current_pid();
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: exiting (%s) id %d pid %d",
      v176,
      v177,
      v178,
      v179,
      v180,
      v181,
      v182,
      v183,
      "dp_rx_thread_loop",
      v174,
      v173,
      v175);
    qdf_event_set((__int64)(a1 + 136), v184);
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: bad Args passed", a2, a3, a4, a5, a6, a7, a8, a9, "dp_rx_thread_loop");
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
