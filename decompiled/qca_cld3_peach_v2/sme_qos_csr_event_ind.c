__int64 __fastcall sme_qos_csr_event_ind(
        _QWORD *a1,
        unsigned int a2,
        int a3,
        const void **a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  int v25; // w6
  __int64 result; // x0
  __int64 v27; // x8
  int v28; // w9
  unsigned int v29; // w21
  __int64 v30; // x27
  __int64 v31; // x25
  __int64 v32; // x26
  unsigned int v33; // w6
  __int64 v34; // x19
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x25
  __int64 v38; // x9
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w20
  __int64 v56; // x25
  __int64 v57; // x19
  __int64 v58; // x8
  int v59; // w9
  __int64 v60; // x8
  int v61; // w9
  __int64 v62; // x8
  int v63; // w9
  __int64 v64; // x8
  __int64 v65; // x19
  int v66; // w9
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x20
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 *v93; // x21
  __int64 v94; // x24
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  __int64 v111; // x0
  __int64 v112; // x21
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  _QWORD *v121; // x0
  __int64 v122; // x21
  int v123; // w6
  __int64 v124; // x8
  unsigned int v125; // w22
  __int64 v126; // x21
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  unsigned int v135; // w21
  __int64 v136; // x26
  __int64 v137; // x28
  __int64 v138; // x27
  const char *v139; // x2
  const char *v140; // x3
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  __int64 v149; // x10
  int v150; // w12
  __int64 v151; // x10
  int v152; // w12
  __int64 v153; // x10
  int v154; // w12
  __int64 v155; // x8
  int v156; // w9
  __int64 v157; // x0
  __int64 v158; // x22
  unsigned __int16 *v159; // x8
  __int64 v160; // x27
  __int64 v161; // x25
  __int64 v162; // x0
  unsigned int v163; // w22
  void *v164; // x0
  double v165; // d0
  double v166; // d1
  double v167; // d2
  double v168; // d3
  double v169; // d4
  double v170; // d5
  double v171; // d6
  double v172; // d7
  void *v173; // x23
  double v174; // d0
  double v175; // d1
  double v176; // d2
  double v177; // d3
  double v178; // d4
  double v179; // d5
  double v180; // d6
  double v181; // d7
  int v182; // w8
  _BYTE *v183; // x22
  char v184; // w8
  __int64 v185; // x9
  __int64 v186; // x10
  int v187; // w8
  __int64 v188; // x8
  __int64 v189; // x8
  __int64 v190; // x8
  _QWORD *v191; // x0
  _QWORD *v192; // x11
  __int64 v193; // x8
  __int64 v194; // x9
  __int64 v195; // x8
  __int64 v196; // x10
  __int64 v197; // x8
  __int64 v198; // x8
  __int64 v199; // x8
  int v200; // w6
  __int64 v201; // x8
  int v202; // w9
  unsigned int v203; // w19
  int v204; // w6
  __int64 v205; // x8
  int v206; // w9
  int v207; // w6
  __int64 v208; // x8
  int v209; // w9
  int v210; // w6
  __int64 v211; // x8
  int v212; // w9
  double v213; // d0
  double v214; // d1
  double v215; // d2
  double v216; // d3
  double v217; // d4
  double v218; // d5
  double v219; // d6
  double v220; // d7
  __int64 v221; // x19
  int v222; // w6
  __int64 v223; // x8
  const char *v224; // x2
  int v225; // w6
  __int64 v226; // x8
  int v227; // w9
  unsigned int v228; // w19
  int v229; // w6
  __int64 v230; // x8
  int v231; // w9
  unsigned int v232; // w19
  const char *v233; // x3
  unsigned int v234; // w1
  int v235; // w6
  __int64 v236; // x8
  int v237; // w9
  int v238; // w6
  __int64 v239; // x8
  int v240; // w9
  int v241; // w6
  int v242; // w10
  __int64 v243; // x8
  __int64 v244; // x0
  unsigned int v245; // w21
  __int64 v246; // x20
  double v247; // d0
  double v248; // d1
  double v249; // d2
  double v250; // d3
  double v251; // d4
  double v252; // d5
  double v253; // d6
  double v254; // d7
  __int64 v255; // x0
  unsigned int v256; // w20
  void *v257; // x0
  void *v258; // x22
  char v259; // w8
  __int64 v260; // x8
  int v261; // w9
  __int64 v262; // x8
  int v263; // w9
  __int64 v264; // x8
  int v265; // w9
  int v266; // w9
  __int64 v267; // x21
  __int64 v268; // x24
  __int64 v269; // x22
  unsigned int v270; // w6
  __int64 v271; // x23
  __int64 v272; // x9
  int v273; // w10
  char v274; // w11
  int v275; // w9
  char v276; // w10
  char v277; // w9
  __int64 v278; // x8
  int v279; // w9
  __int64 v280; // x9
  __int64 v281; // x10
  __int64 v282; // x9
  __int64 v283; // x10
  __int64 v284; // x8
  __int64 v285; // x9
  __int64 v286; // x10
  __int64 v287; // x8
  __int64 v288; // x0
  double v289; // d0
  double v290; // d1
  double v291; // d2
  double v292; // d3
  double v293; // d4
  double v294; // d5
  double v295; // d6
  double v296; // d7
  int v297; // w19
  unsigned int v298; // w19
  __int64 v299; // x0
  double v300; // d0
  double v301; // d1
  double v302; // d2
  double v303; // d3
  double v304; // d4
  double v305; // d5
  double v306; // d6
  double v307; // d7
  __int64 v308; // x21
  unsigned __int8 v309; // [xsp+10h] [xbp-30h]
  _QWORD *v310; // [xsp+10h] [xbp-30h]
  __int64 v311; // [xsp+18h] [xbp-28h] BYREF
  __int64 v312; // [xsp+20h] [xbp-20h]
  __int64 v313; // [xsp+28h] [xbp-18h] BYREF
  __int64 v314; // [xsp+30h] [xbp-10h]
  __int64 v315; // [xsp+38h] [xbp-8h]

  v315 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: vdev %d event %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "sme_qos_csr_event_ind",
    (unsigned __int8)a2,
    (unsigned int)a3);
  if ( a3 > 4 )
  {
    if ( a3 <= 8 )
    {
      if ( (unsigned int)(a3 - 5) < 2 )
      {
        v56 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
        if ( *(_BYTE *)(v56 + 2940) != 1 || (*(_BYTE *)(v56 + 3032) & 1) != 0 )
        {
          v57 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
          qdf_mem_set((void *)(v57 + 4), 0x2D8u, 0);
          v58 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
          v59 = *(_DWORD *)(v58 + 8);
          *(_DWORD *)(v58 + 8) = 1;
          *(_DWORD *)(v58 + 12) = v59;
          qdf_mem_set((void *)(v57 + 732), 0x2D8u, 0);
          v60 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
          v61 = *(_DWORD *)(v60 + 736);
          *(_DWORD *)(v60 + 736) = 1;
          *(_DWORD *)(v60 + 740) = v61;
          qdf_mem_set((void *)(v57 + 1460), 0x2D8u, 0);
          v62 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
          v63 = *(_DWORD *)(v62 + 1464);
          *(_DWORD *)(v62 + 1464) = 1;
          *(_DWORD *)(v62 + 1468) = v63;
          qdf_mem_set((void *)(v57 + 2188), 0x2D8u, 0);
          v64 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
          v65 = (__int64)a1;
          v66 = *(_DWORD *)(v64 + 2192);
          *(_DWORD *)(v64 + 2192) = 1;
          *(_DWORD *)(v64 + 2196) = v66;
          *(_BYTE *)(v56 + 2916) = 0;
          sme_ps_uapsd_disable(a1, (unsigned __int8)a2, v67, v68, v69, v70, v71, v72, v73, v74);
          *(_BYTE *)(v56 + 2940) = 0;
          *(_DWORD *)(v56 + 2936) = 0;
          v75 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
          v84 = csr_ll_peek_head(v75 + 2944, 1, v76, v77, v78, v79, v80, v81, v82, v83);
          if ( v84 )
          {
            v93 = (__int64 *)v84;
            do
            {
              v94 = csr_ll_next(v75 + 2944, (__int64)v93, 1, v85, v86, v87, v88, v89, v90, v91, v92);
              qdf_trace_msg(
                0x34u,
                8u,
                "%s: deleting entry from buffered List",
                v95,
                v96,
                v97,
                v98,
                v99,
                v100,
                v101,
                v102,
                "sme_qos_delete_buffered_requests");
              csr_ll_remove_entry(v75 + 2944, v93, 1, v103, v104, v105, v106, v107, v108, v109, v110);
              _qdf_mem_free((__int64)v93);
              v93 = (__int64 *)v94;
            }
            while ( v94 );
          }
          sme_qos_delete_existing_flows(v65, a2, v85, v86, v87, v88, v89, v90, v91, v92);
          v111 = *(_QWORD *)(v56 + 2920);
          if ( v111 )
          {
            _qdf_mem_free(v111);
            *(_QWORD *)(v56 + 2920) = 0;
          }
          result = 0;
          *(_BYTE *)(qword_91F2D8 + 3040LL * (unsigned __int8)a2 + 1) = 0;
          goto LABEL_203;
        }
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: no need for state transition, should already be in handoff state",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "sme_qos_process_disconnect_ev");
        if ( *(_DWORD *)(v56 + 8) != 5
          || *(_DWORD *)(v56 + 736) != 5
          || *(_DWORD *)(v56 + 1464) != 5
          || *(_DWORD *)(v56 + 2192) != 5 )
        {
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: curr_state is not HANDOFF, session %d",
            v141,
            v142,
            v143,
            v144,
            v145,
            v146,
            v147,
            v148,
            "sme_qos_process_disconnect_ev",
            (unsigned __int8)a2);
        }
        goto LABEL_202;
      }
      if ( a3 == 7 )
      {
        v122 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
        v123 = *(_DWORD *)(v122 + 8);
        if ( (unsigned int)(v123 - 2) >= 3 )
        {
          if ( v123 == 5 && *(_BYTE *)(v122 + 3032) == 1 )
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: SME_QOS_CSR_HANDOFF_ASSOC_REQ received in SME_QOS_HANDOFF state with FT in progress",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "sme_qos_process_handoff_assoc_req_ev");
          else
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: On session %d AC %d is in wrong state %d",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "sme_qos_process_handoff_assoc_req_ev",
              (unsigned __int8)a2,
              0);
        }
        else
        {
          v124 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
          *(_DWORD *)(v124 + 8) = 5;
          *(_DWORD *)(v124 + 12) = v123;
        }
        v204 = *(_DWORD *)(v122 + 736);
        if ( (unsigned int)(v204 - 2) >= 3 )
        {
          if ( v204 == 5 && *(_BYTE *)(v122 + 3032) == 1 )
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: SME_QOS_CSR_HANDOFF_ASSOC_REQ received in SME_QOS_HANDOFF state with FT in progress",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "sme_qos_process_handoff_assoc_req_ev");
          else
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: On session %d AC %d is in wrong state %d",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "sme_qos_process_handoff_assoc_req_ev",
              (unsigned __int8)a2,
              1);
        }
        else
        {
          v205 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
          v206 = *(_DWORD *)(v205 + 736);
          *(_DWORD *)(v205 + 736) = 5;
          *(_DWORD *)(v205 + 740) = v206;
        }
        v207 = *(_DWORD *)(v122 + 1464);
        if ( (unsigned int)(v207 - 2) >= 3 )
        {
          if ( v207 == 5 && *(_BYTE *)(v122 + 3032) == 1 )
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: SME_QOS_CSR_HANDOFF_ASSOC_REQ received in SME_QOS_HANDOFF state with FT in progress",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "sme_qos_process_handoff_assoc_req_ev");
          else
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: On session %d AC %d is in wrong state %d",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "sme_qos_process_handoff_assoc_req_ev",
              (unsigned __int8)a2,
              2);
        }
        else
        {
          v208 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
          v209 = *(_DWORD *)(v208 + 1464);
          *(_DWORD *)(v208 + 1464) = 5;
          *(_DWORD *)(v208 + 1468) = v209;
        }
        v210 = *(_DWORD *)(v122 + 2192);
        if ( (unsigned int)(v210 - 2) >= 3 )
        {
          if ( v210 == 5 && *(_BYTE *)(v122 + 3032) == 1 )
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: SME_QOS_CSR_HANDOFF_ASSOC_REQ received in SME_QOS_HANDOFF state with FT in progress",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "sme_qos_process_handoff_assoc_req_ev");
          else
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: On session %d AC %d is in wrong state %d",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "sme_qos_process_handoff_assoc_req_ev",
              (unsigned __int8)a2,
              3);
        }
        else
        {
          v211 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
          v212 = *(_DWORD *)(v211 + 2192);
          *(_DWORD *)(v211 + 2192) = 5;
          *(_DWORD *)(v211 + 2196) = v212;
        }
        if ( (csr_roam_is11r_assoc((__int64)a1, a2) & 1) != 0
          || (unsigned __int8)a2 <= 5u
          && (v221 = a1[2162] + 96LL * (unsigned __int8)a2) != 0
          && wlan_cm_is_roam_sync_in_progress(a1[2703], a2)
          && (csr_roam_is_ese_assoc((__int64)a1, a2) & 1) != 0
          && *(_DWORD *)(v221 + 24) )
        {
          *(_BYTE *)(v122 + 3032) = 1;
        }
        if ( (*(_BYTE *)(v122 + 3032) & 1) == 0 && (csr_roam_is_ese_assoc((__int64)a1, a2) & 1) == 0 )
          *(_BYTE *)(v122 + 2940) = 1;
        *(_BYTE *)(v122 + 2916) = 0;
        sme_ps_uapsd_disable(a1, (unsigned __int8)a2, v213, v214, v215, v216, v217, v218, v219, v220);
        goto LABEL_202;
      }
      v24 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
      v25 = *(_DWORD *)(v24 + 8);
      if ( v25 != 3 )
      {
        if ( v25 == 5 )
        {
          result = 0;
          v27 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
          v28 = *(_DWORD *)(v24 + 12);
          *(_DWORD *)(v27 + 8) = v28;
          *(_DWORD *)(v27 + 12) = 5;
          if ( v28 == 3 )
            *(_DWORD *)(v24 + 8) = 2;
          goto LABEL_109;
        }
        if ( (*(_BYTE *)(v24 + 3032) & 1) == 0 )
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: On session %d AC %d is in wrong state %d",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "sme_qos_process_handoff_success_ev",
            (unsigned __int8)a2,
            0);
      }
      result = 16;
LABEL_109:
      v200 = *(_DWORD *)(v24 + 736);
      if ( v200 != 3 )
      {
        if ( v200 == 5 )
        {
          v201 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
          v202 = *(_DWORD *)(v201 + 736);
          *(_DWORD *)(v201 + 736) = *(_DWORD *)(v24 + 740);
          *(_DWORD *)(v201 + 740) = v202;
          result = 0;
          if ( *(_DWORD *)(v24 + 736) == 3 )
            *(_DWORD *)(v24 + 736) = 2;
        }
        else if ( (*(_BYTE *)(v24 + 3032) & 1) == 0 )
        {
          v203 = result;
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: On session %d AC %d is in wrong state %d",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "sme_qos_process_handoff_success_ev",
            (unsigned __int8)a2,
            1);
          result = v203;
        }
      }
      v225 = *(_DWORD *)(v24 + 1464);
      if ( v225 != 3 )
      {
        if ( v225 == 5 )
        {
          v226 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
          v227 = *(_DWORD *)(v226 + 1464);
          *(_DWORD *)(v226 + 1464) = *(_DWORD *)(v24 + 1468);
          *(_DWORD *)(v226 + 1468) = v227;
          result = 0;
          if ( *(_DWORD *)(v24 + 1464) == 3 )
            *(_DWORD *)(v24 + 1464) = 2;
        }
        else if ( (*(_BYTE *)(v24 + 3032) & 1) == 0 )
        {
          v228 = result;
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: On session %d AC %d is in wrong state %d",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "sme_qos_process_handoff_success_ev",
            (unsigned __int8)a2,
            2);
          result = v228;
        }
      }
      v229 = *(_DWORD *)(v24 + 2192);
      if ( v229 == 3 )
        goto LABEL_203;
      if ( v229 != 5 )
      {
        if ( (*(_BYTE *)(v24 + 3032) & 1) == 0 )
        {
          v232 = result;
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: On session %d AC %d is in wrong state %d",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "sme_qos_process_handoff_success_ev",
            (unsigned __int8)a2,
            3);
          result = v232;
        }
        goto LABEL_203;
      }
      v230 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
      v231 = *(_DWORD *)(v230 + 2192);
      *(_DWORD *)(v230 + 2192) = *(_DWORD *)(v24 + 2196);
      *(_DWORD *)(v230 + 2196) = v231;
      if ( *(_DWORD *)(v24 + 2192) == 3 )
      {
        result = 0;
        *(_DWORD *)(v24 + 2192) = 2;
        goto LABEL_203;
      }
      goto LABEL_202;
    }
    if ( a3 == 9 )
      goto LABEL_202;
    if ( a3 != 10 )
    {
      if ( a3 == 11 )
      {
        v36 = (__int64)a1;
LABEL_53:
        sme_qos_delete_existing_flows(v36, a2, v16, v17, v18, v19, v20, v21, v22, v23);
        goto LABEL_202;
      }
      goto LABEL_64;
    }
    goto LABEL_200;
  }
  if ( a3 > 1 )
  {
    if ( a3 != 2 )
    {
      if ( a3 != 3 )
      {
        v29 = 0;
        v30 = -2912;
        v31 = 3040LL * (unsigned __int8)a2;
        v32 = qword_91F2D8 + v31;
        do
        {
          v33 = *(_DWORD *)(v32 + v30 + 2920);
          if ( v33 >= 2 )
          {
            if ( v33 == 5 )
            {
              v34 = v32 + v30;
              v35 = qword_91F2D8 + v31 + v30;
              *(_DWORD *)(v35 + 2924) = *(_DWORD *)(v35 + 2920);
              *(_DWORD *)(v35 + 2920) = 1;
              if ( *(_BYTE *)(v32 + v30 + 3232) == 1 )
                *(_BYTE *)(v34 + 3232) = 0;
              qdf_mem_set((void *)(v34 + 2928), 0x4Cu, 0);
              qdf_mem_set((void *)(v34 + 3080), 0x4Cu, 0);
              qdf_mem_set((void *)(v34 + 3004), 0x4Cu, 0);
              qdf_mem_set((void *)(v34 + 3156), 0x4Cu, 0);
              *(_BYTE *)(v32 + v30 + 2916) = 0;
              *(_WORD *)(v34 + 3233) = 0;
              *(_BYTE *)(v34 + 2917) = 0;
            }
            else
            {
              qdf_trace_msg(
                0x34u,
                2u,
                "%s: On session %d AC %d is in wrong state %d",
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                "sme_qos_process_reassoc_failure_ev",
                (unsigned __int8)a2,
                v29);
            }
          }
          v30 += 728;
          ++v29;
        }
        while ( v30 );
        v36 = (__int64)a1;
        goto LABEL_53;
      }
      if ( (unsigned __int8)a2 >= 6u )
      {
        v139 = "%s: invoked on session %d";
        v140 = "sme_qos_process_reassoc_success_ev";
LABEL_80:
        qdf_trace_msg(0x34u, 2u, v139, v16, v17, v18, v19, v20, v21, v22, v23, v140, (unsigned __int8)a2);
        goto LABEL_170;
      }
      if ( a4 )
      {
        v159 = (unsigned __int16 *)*a4;
        if ( *a4 )
        {
          v160 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
          v161 = a1[2162];
          v310 = a1;
          v162 = *(_QWORD *)(v160 + 2920);
          if ( v162 )
          {
            _qdf_mem_free(v162);
            *(_QWORD *)(v160 + 2920) = 0;
            v159 = (unsigned __int16 *)*a4;
          }
          v163 = *v159 + 2;
          v164 = (void *)_qdf_mem_malloc(*v159 + 2LL, "sme_qos_save_assoc_info", 6063);
          if ( v164 )
          {
            v173 = v164;
            qdf_mem_copy(v164, *a4, v163);
            *(_QWORD *)(v160 + 2920) = v173;
            v182 = 0;
            *(_BYTE *)(v160 + 2916) |= *((_BYTE *)a4 + 8);
          }
          else
          {
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: sme_qos_save_assoc_info() failed",
              v165,
              v166,
              v167,
              v168,
              v169,
              v170,
              v171,
              v172,
              "sme_qos_process_reassoc_success_ev");
            v182 = 2;
          }
          if ( *(_BYTE *)(v160 + 2940) == 1 )
          {
            *(_BYTE *)(v160 + 2940) = 0;
            v244 = a2;
LABEL_201:
            sme_qos_process_buffered_cmd(v244);
            goto LABEL_202;
          }
          if ( *(_BYTE *)(v160 + 3032) == 1 )
          {
            v245 = v182;
            v246 = v161 + 96LL * (unsigned __int8)a2;
            if ( (csr_roam_is11r_assoc((__int64)a1, a2) & 1) != 0 )
            {
              if ( v246 && *(_DWORD *)(v246 + 20) )
                v245 = sme_qos_process_ft_reassoc_rsp_ev(a1, a2);
              else
                qdf_trace_msg(
                  0x34u,
                  8u,
                  "%s: session or RIC data is not present",
                  v247,
                  v248,
                  v249,
                  v250,
                  v251,
                  v252,
                  v253,
                  v254,
                  "sme_qos_process_reassoc_success_ev");
            }
            if ( (csr_roam_is_ese_assoc((__int64)a1, a2) & 1) != 0 && v246 )
            {
              result = v245;
              if ( *(_DWORD *)(v246 + 24) )
                result = sme_qos_ese_process_reassoc_tspec_rsp(a1, a2);
            }
            else
            {
              result = v245;
            }
            *(_BYTE *)(v160 + 3032) = 0;
            *(_BYTE *)(v160 + 2940) = 0;
            goto LABEL_203;
          }
          v267 = 0;
          v268 = 3040LL * (unsigned __int8)a2;
          v269 = -2912;
          *(_BYTE *)(v160 + 1) = 1;
          while ( 1 )
          {
            v270 = *(_DWORD *)(v160 + v269 + 2920);
            if ( v270 >= 2 )
            {
              if ( v270 != 5 )
              {
                v297 = v182;
                qdf_trace_msg(
                  0x34u,
                  2u,
                  "%s: session %d AC %d is in wrong state %d",
                  v174,
                  v175,
                  v176,
                  v177,
                  v178,
                  v179,
                  v180,
                  v181,
                  "sme_qos_process_reassoc_success_ev",
                  (unsigned __int8)a2,
                  (unsigned int)v267);
                v182 = v297;
                goto LABEL_219;
              }
              v313 = 0;
              v314 = 0;
              v311 = 0;
              v312 = 0;
              v271 = v160 + v269;
              v272 = qword_91F2D8 + v268 + v269;
              v273 = *(_DWORD *)(v272 + 2920);
              *(_DWORD *)(v272 + 2920) = *(_DWORD *)(v160 + v269 + 2924);
              *(_DWORD *)(v272 + 2924) = v273;
              if ( *(_BYTE *)(v160 + v269 + 3232) == 1 )
              {
                v274 = *(_BYTE *)(v160 + 2916);
                v275 = 1 << (v267 ^ 3);
                v276 = v274 | v275;
                v277 = v274 & ~(_BYTE)v275;
                if ( *(_BYTE *)(v271 + 3092) )
                  v277 = v276;
                *(_BYTE *)(v160 + 2916) = v277;
                *(_BYTE *)(v271 + 3232) = 0;
                v278 = qword_91F2D8 + v268 + v269;
                v279 = *(_DWORD *)(v278 + 2920);
                *(_DWORD *)(v278 + 2920) = 4;
                *(_DWORD *)(v278 + 2924) = v279;
                v280 = *(_QWORD *)(v271 + 3136);
                v281 = *(_QWORD *)(v271 + 3144);
                *(_QWORD *)(v271 + 2976) = *(_QWORD *)(v271 + 3128);
                LODWORD(v278) = *(_DWORD *)(v271 + 3152);
                *(_QWORD *)(v271 + 2984) = v280;
                v282 = *(_QWORD *)(v271 + 3096);
                *(_QWORD *)(v271 + 2992) = v281;
                v283 = *(_QWORD *)(v271 + 3104);
                *(_DWORD *)(v271 + 3000) = v278;
                v284 = *(_QWORD *)(v271 + 3112);
                *(_QWORD *)(v271 + 2944) = v282;
                v285 = *(_QWORD *)(v271 + 3120);
                *(_QWORD *)(v271 + 2952) = v283;
                v286 = *(_QWORD *)(v271 + 3080);
                *(_QWORD *)(v271 + 2960) = v284;
                v287 = *(_QWORD *)(v271 + 3088);
                *(_QWORD *)(v271 + 2968) = v285;
                *(_QWORD *)(v271 + 2928) = v286;
                *(_QWORD *)(v271 + 2936) = v287;
                qdf_mem_set(&v313, 0x10u, 0);
                HIDWORD(v313) = v267;
                BYTE1(v313) = 2;
                LOBYTE(v313) = a2;
                qdf_mem_set(&v311, 0x10u, 0);
                BYTE1(v311) = 4;
                HIDWORD(v311) = 0;
                LOBYTE(v311) = a2;
                v288 = sme_qos_find_in_flow_list((unsigned int)v311, v312);
                if ( v288 && v267 == *(_DWORD *)(v288 + 28)
                  || (v288 = sme_qos_find_in_flow_list(v311, v312)) != 0 && v267 == *(_DWORD *)(v288 + 28)
                  || (v288 = sme_qos_find_in_flow_list(v311, v312)) != 0 && v267 == *(_DWORD *)(v288 + 28)
                  || (v288 = sme_qos_find_in_flow_list(v311, v312)) != 0 && v267 == *(_DWORD *)(v288 + 28) )
                {
                  *(_BYTE *)(v160 + v269 + 3235) = *(_BYTE *)(v288 + 128);
                }
                if ( (unsigned int)((__int64 (__fastcall *)(_QWORD *, __int64, __int64, void *))sme_qos_find_all_in_flow_list)(
                                     v310,
                                     v313,
                                     v314,
                                     &sme_qos_reassoc_success_ev_fnp) )
                {
                  qdf_trace_msg(
                    0x34u,
                    2u,
                    "%s: no match found for ac = %d",
                    v289,
                    v290,
                    v291,
                    v292,
                    v293,
                    v294,
                    v295,
                    v296,
                    "sme_qos_handle_handoff_state",
                    HIDWORD(v313));
                  v182 = 16;
                }
                else
                {
                  *(_BYTE *)(v160 + v269 + 3235) = 0;
                  qdf_mem_set((void *)(v271 + 3080), 0x4Cu, 0);
                  v182 = 0;
                }
                v268 = 3040LL * (unsigned __int8)a2;
                goto LABEL_219;
              }
            }
            v182 = 0;
LABEL_219:
            v269 += 728;
            ++v267;
            if ( !v269 )
            {
              v298 = v182;
              sme_qos_process_buffered_cmd(a2);
              result = v298;
              goto LABEL_203;
            }
          }
        }
        v224 = "%s: bss_desc is NULL";
      }
      else
      {
        v224 = "%s: event_info is NULL";
      }
      v233 = "sme_qos_process_reassoc_success_ev";
      goto LABEL_168;
    }
    v125 = (unsigned __int8)a2;
    v126 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
    if ( *(_BYTE *)(v126 + 3032) == 1 )
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: no need for state transition, should already be in handoff state",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "sme_qos_process_reassoc_req_ev");
      if ( *(_DWORD *)(v126 + 8) == 5
        && *(_DWORD *)(v126 + 736) == 5
        && *(_DWORD *)(v126 + 1464) == 5
        && *(_DWORD *)(v126 + 2192) == 5 )
      {
        v309 = a2;
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Invoked on session %d",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "sme_qos_process_ft_reassoc_req_ev",
          (unsigned __int8)a2);
        v135 = 0;
        v136 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
        v137 = -2912;
        v138 = 3040LL * v125;
        while ( 1 )
        {
          if ( (v183 = (_BYTE *)(v136 + v137), *(_BYTE *)(v136 + v137 + 3236)) && !v183[3234] || (v183[3233] & 1) != 0 )
          {
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: Copying the currentQos to requestedQos for AC=%d, flow=%d",
              v127,
              v128,
              v129,
              v130,
              v131,
              v132,
              v133,
              v134,
              "sme_qos_process_ft_reassoc_req_ev",
              v135,
              0);
            v185 = *((_QWORD *)v183 + 373);
            v186 = *((_QWORD *)v183 + 374);
            *((_QWORD *)v183 + 391) = *((_QWORD *)v183 + 372);
            *((_QWORD *)v183 + 392) = v185;
            v187 = *((_DWORD *)v183 + 750);
            *((_QWORD *)v183 + 393) = v186;
            *((_DWORD *)v183 + 788) = v187;
            v188 = *((_QWORD *)v183 + 369);
            *((_QWORD *)v183 + 387) = *((_QWORD *)v183 + 368);
            *((_QWORD *)v183 + 388) = v188;
            v189 = *((_QWORD *)v183 + 371);
            *((_QWORD *)v183 + 389) = *((_QWORD *)v183 + 370);
            *((_QWORD *)v183 + 390) = v189;
            v190 = *((_QWORD *)v183 + 367);
            *((_QWORD *)v183 + 385) = *((_QWORD *)v183 + 366);
            *((_QWORD *)v183 + 386) = v190;
            qdf_mem_set(v183 + 2928, 0x4Cu, 0);
            v184 = 0;
          }
          else
          {
            v184 = 1;
          }
          if ( *(_BYTE *)(v136 + v137 + 3237) && !v183[3234] || (v183[3233] & 2) != 0 )
            break;
          if ( (v184 & 1) == 0 )
            goto LABEL_101;
LABEL_89:
          v137 += 728;
          ++v135;
          if ( !v137 )
          {
            *(_BYTE *)(v136 + 2916) = 0;
            v299 = csr_ll_peek_head((__int64)&unk_91F2E0, 0, v127, v128, v129, v130, v131, v132, v133, v134);
            if ( v299 )
            {
              v308 = v299;
              do
              {
                if ( *(unsigned __int8 *)(v308 + 16) == v309 )
                {
                  qdf_trace_msg(
                    0x34u,
                    8u,
                    "%s: Changing FlowID %d reason to SETUP and HO renewal to false",
                    v300,
                    v301,
                    v302,
                    v303,
                    v304,
                    v305,
                    v306,
                    v307,
                    "sme_qos_process_ft_reassoc_req_ev",
                    *(unsigned int *)(v308 + 24));
                  *(_DWORD *)(v308 + 20) = 0;
                  *(_BYTE *)(v308 + 128) = 1;
                }
                v308 = csr_ll_next((__int64)&unk_91F2E0, v308, 0, v300, v301, v302, v303, v304, v305, v306, v307);
                result = 0;
              }
              while ( v308 );
              goto LABEL_203;
            }
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: Flow List empty, nothing to update",
              v300,
              v301,
              v302,
              v303,
              v304,
              v305,
              v306,
              v307,
              "sme_qos_process_ft_reassoc_req_ev");
LABEL_202:
            result = 0;
            goto LABEL_203;
          }
        }
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Copying the currentQos to requestedQos for AC=%d, flow=%d",
          v127,
          v128,
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          "sme_qos_process_ft_reassoc_req_ev",
          v135,
          1);
        v191 = (_QWORD *)(v136 + v137 + 3004);
        v192 = (_QWORD *)(v136 + v137 + 3156);
        *(_DWORD *)(v136 + v137 + 3228) = *(_DWORD *)(v136 + v137 + 3076);
        v193 = *(_QWORD *)(v136 + v137 + 3060);
        v194 = *(_QWORD *)(v136 + v137 + 3068);
        v192[6] = *(_QWORD *)(v136 + v137 + 3052);
        v192[7] = v193;
        v195 = *(_QWORD *)(v136 + v137 + 3020);
        v196 = *(_QWORD *)(v136 + v137 + 3028);
        v192[8] = v194;
        v192[2] = v195;
        v192[3] = v196;
        v197 = *(_QWORD *)(v136 + v137 + 3044);
        v192[4] = *(_QWORD *)(v136 + v137 + 3036);
        v192[5] = v197;
        v198 = *(_QWORD *)(v136 + v137 + 3012);
        *v192 = *v191;
        v192[1] = v198;
        qdf_mem_set(v191, 0x4Cu, 0);
LABEL_101:
        if ( *(_DWORD *)(v136 + v137 + 2920) == 5 )
        {
          v199 = qword_91F2D8 + v138 + v137;
          *(_DWORD *)(v199 + 2924) = *(_DWORD *)(v199 + 2920);
          *(_DWORD *)(v199 + 2920) = 3;
        }
        else
        {
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: FT Reassoc req event in unexpected state %d",
            v127,
            v128,
            v129,
            v130,
            v131,
            v132,
            v133,
            v134,
            "sme_qos_process_ft_reassoc_req_ev");
        }
        goto LABEL_89;
      }
LABEL_79:
      v139 = "%s: curr_state is not HANDOFF, session %d";
      v140 = "sme_qos_process_reassoc_req_ev";
      goto LABEL_80;
    }
    if ( (*(_BYTE *)(v126 + 2940) & 1) != 0 )
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: no need for state transition, should already be in handoff state",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "sme_qos_process_reassoc_req_ev");
      if ( *(_DWORD *)(v126 + 8) != 5
        || *(_DWORD *)(v126 + 736) != 5
        || *(_DWORD *)(v126 + 1464) != 5
        || *(_DWORD *)(v126 + 2192) != 5 )
      {
        goto LABEL_79;
      }
      v157 = csr_ll_peek_head((__int64)&unk_91F2E0, 0, v16, v17, v18, v19, v20, v21, v22, v23);
      if ( !v157 )
      {
        v224 = "%s: Flow List empty, nothing to update";
        v233 = "sme_qos_process_reassoc_req_ev";
        v234 = 8;
        goto LABEL_169;
      }
      v158 = v157;
      do
      {
        if ( *(unsigned __int8 *)(v158 + 16) == (unsigned __int8)a2 )
        {
          qdf_trace_msg(
            0x34u,
            4u,
            "%s: Changing FlowID %d reason toSETUP and HO renewal to true",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "sme_qos_process_reassoc_req_ev",
            *(unsigned int *)(v158 + 24));
          *(_DWORD *)(v158 + 20) = 0;
          *(_BYTE *)(v158 + 128) = 1;
        }
        v158 = csr_ll_next((__int64)&unk_91F2E0, v158, 0, v16, v17, v18, v19, v20, v21, v22, v23);
      }
      while ( v158 );
      v121 = a1;
LABEL_51:
      sme_qos_buffer_existing_flows(v121, a2);
      sme_qos_cleanup_ctrl_blk_for_handoff(a2);
      goto LABEL_202;
    }
    v222 = *(_DWORD *)(v126 + 8);
    if ( (unsigned int)(v222 - 2) >= 3 )
    {
      if ( v222 != 5 )
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: On session %d AC %d is in wrong state %d",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "sme_qos_process_reassoc_req_ev",
          (unsigned __int8)a2,
          0);
    }
    else
    {
      v223 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
      *(_DWORD *)(v223 + 8) = 5;
      *(_DWORD *)(v223 + 12) = v222;
    }
    v235 = *(_DWORD *)(v126 + 736);
    if ( (unsigned int)(v235 - 2) >= 3 )
    {
      if ( v235 != 5 )
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: On session %d AC %d is in wrong state %d",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "sme_qos_process_reassoc_req_ev",
          (unsigned __int8)a2,
          1);
    }
    else
    {
      v236 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
      v237 = *(_DWORD *)(v236 + 736);
      *(_DWORD *)(v236 + 736) = 5;
      *(_DWORD *)(v236 + 740) = v237;
    }
    v238 = *(_DWORD *)(v126 + 1464);
    if ( (unsigned int)(v238 - 2) >= 3 )
    {
      if ( v238 != 5 )
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: On session %d AC %d is in wrong state %d",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "sme_qos_process_reassoc_req_ev",
          (unsigned __int8)a2,
          2);
    }
    else
    {
      v239 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
      v240 = *(_DWORD *)(v239 + 1464);
      *(_DWORD *)(v239 + 1464) = 5;
      *(_DWORD *)(v239 + 1468) = v240;
    }
    v241 = *(_DWORD *)(v126 + 2192);
    if ( (unsigned int)(v241 - 2) >= 3 )
    {
      if ( v241 != 5 )
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: On session %d AC %d is in wrong state %d",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "sme_qos_process_reassoc_req_ev",
          (unsigned __int8)a2,
          3);
      goto LABEL_202;
    }
    v242 = 5;
    v243 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
    result = 0;
LABEL_215:
    v266 = *(_DWORD *)(v243 + 2192);
    *(_DWORD *)(v243 + 2192) = v242;
    *(_DWORD *)(v243 + 2196) = v266;
    goto LABEL_203;
  }
  if ( a3 )
  {
    if ( a3 != 1 )
    {
LABEL_64:
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: On Session %d Unknown Event %d received from CSR",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "sme_qos_csr_event_ind",
        (unsigned __int8)a2,
        (unsigned int)a3);
LABEL_170:
      result = 16;
      goto LABEL_203;
    }
    v37 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
    if ( (*(_DWORD *)(v37 + 8) != 1
       || *(_DWORD *)(v37 + 736) != 1
       || *(_DWORD *)(v37 + 1464) != 1
       || *(_DWORD *)(v37 + 2192) != 1)
      && *(_BYTE *)(v37 + 2940) != 1 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: wrong state: BE %d, BK %d, VI %d, VO %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "sme_qos_process_assoc_complete_ev");
      goto LABEL_170;
    }
    if ( a4 )
    {
      if ( *a4 )
      {
        v38 = *(_QWORD *)(v37 + 2920);
        if ( v38 )
        {
          if ( csr_is_bssid_match((const void *)(v38 + 2), (__int64)*a4 + 2) )
          {
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: assoc with the same BSS, no update needed",
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              "sme_qos_process_assoc_complete_ev");
            v55 = 16;
LABEL_198:
            v259 = *(_BYTE *)(v37 + 2940);
            *(_BYTE *)(v37 + 1) = 1;
            if ( (v259 & 1) != 0 )
            {
              *(_BYTE *)(v37 + 2940) = 0;
LABEL_200:
              v244 = a2;
              goto LABEL_201;
            }
            if ( *(_DWORD *)(v37 + 8) == 1 )
            {
              v260 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
              v261 = *(_DWORD *)(v260 + 8);
              *(_DWORD *)(v260 + 8) = 2;
              *(_DWORD *)(v260 + 12) = v261;
            }
            else
            {
              qdf_trace_msg(
                0x34u,
                2u,
                "%s: On session %d AC %d is in wrong state %d",
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                "sme_qos_process_assoc_complete_ev",
                (unsigned __int8)a2,
                0);
            }
            if ( *(_DWORD *)(v37 + 736) == 1 )
            {
              v262 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
              v263 = *(_DWORD *)(v262 + 736);
              *(_DWORD *)(v262 + 736) = 2;
              *(_DWORD *)(v262 + 740) = v263;
            }
            else
            {
              qdf_trace_msg(
                0x34u,
                2u,
                "%s: On session %d AC %d is in wrong state %d",
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                "sme_qos_process_assoc_complete_ev",
                (unsigned __int8)a2,
                1);
            }
            if ( *(_DWORD *)(v37 + 1464) == 1 )
            {
              v264 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
              v265 = *(_DWORD *)(v264 + 1464);
              *(_DWORD *)(v264 + 1464) = 2;
              *(_DWORD *)(v264 + 1468) = v265;
            }
            else
            {
              qdf_trace_msg(
                0x34u,
                2u,
                "%s: On session %d AC %d is in wrong state %d",
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                "sme_qos_process_assoc_complete_ev",
                (unsigned __int8)a2,
                2);
            }
            if ( *(_DWORD *)(v37 + 2192) != 1 )
            {
              qdf_trace_msg(
                0x34u,
                2u,
                "%s: On session %d AC %d is in wrong state %d",
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                "sme_qos_process_assoc_complete_ev",
                (unsigned __int8)a2,
                3);
              result = v55;
              goto LABEL_203;
            }
            v242 = 2;
            v243 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
            result = v55;
            goto LABEL_215;
          }
          v255 = *(_QWORD *)(v37 + 2920);
          if ( v255 )
          {
            _qdf_mem_free(v255);
            *(_QWORD *)(v37 + 2920) = 0;
          }
        }
        v256 = *(unsigned __int16 *)*a4 + 2;
        v257 = (void *)_qdf_mem_malloc(*(unsigned __int16 *)*a4 + 2LL, "sme_qos_save_assoc_info", 6063);
        if ( v257 )
        {
          v258 = v257;
          qdf_mem_copy(v257, *a4, v256);
          *(_QWORD *)(v37 + 2920) = v258;
          v55 = 0;
          *(_BYTE *)(v37 + 2916) |= *((_BYTE *)a4 + 8);
        }
        else
        {
          v55 = 2;
        }
        goto LABEL_198;
      }
      v224 = "%s: bss_desc is NULL";
    }
    else
    {
      v224 = "%s: pEvent_info is NULL";
    }
    v233 = "sme_qos_process_assoc_complete_ev";
LABEL_168:
    v234 = 2;
LABEL_169:
    qdf_trace_msg(0x34u, v234, v224, v16, v17, v18, v19, v20, v21, v22, v23, v233);
    goto LABEL_170;
  }
  v112 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
  if ( (*(_BYTE *)(v112 + 2940) & 1) != 0 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: No need for state transition, should already be in handoff state",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "sme_qos_process_join_req_ev");
    if ( *(_DWORD *)(v112 + 8) != 5
      || *(_DWORD *)(v112 + 736) != 5
      || *(_DWORD *)(v112 + 1464) != 5
      || *(_DWORD *)(v112 + 2192) != 5 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: curr_state is not HANDOFF, session %d",
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        v119,
        v120,
        "sme_qos_process_join_req_ev",
        (unsigned __int8)a2);
    }
    v121 = a1;
    goto LABEL_51;
  }
  v149 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
  v150 = *(_DWORD *)(v149 + 8);
  *(_DWORD *)(v149 + 8) = 1;
  *(_DWORD *)(v149 + 12) = v150;
  v151 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
  v152 = *(_DWORD *)(v151 + 736);
  *(_DWORD *)(v151 + 736) = 1;
  *(_DWORD *)(v151 + 740) = v152;
  v153 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
  v154 = *(_DWORD *)(v153 + 1464);
  *(_DWORD *)(v153 + 1464) = 1;
  *(_DWORD *)(v153 + 1468) = v154;
  v155 = qword_91F2D8 + 3040LL * (unsigned __int8)a2;
  v156 = *(_DWORD *)(v155 + 2192);
  *(_DWORD *)(v155 + 2192) = 1;
  *(_DWORD *)(v155 + 2196) = v156;
  result = *(_QWORD *)(v112 + 2920);
  if ( result )
  {
    _qdf_mem_free(result);
    result = 0;
    *(_QWORD *)(v112 + 2920) = 0;
  }
LABEL_203:
  _ReadStatusReg(SP_EL0);
  return result;
}
