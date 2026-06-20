__int64 __fastcall cm_fw_roam_sync_propagation(
        __int64 a1,
        unsigned int a2,
        unsigned __int16 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x23
  __int64 session_by_vdev_id; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x25
  __int64 v34; // x0
  __int64 v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x27
  __int64 v45; // x19
  __int64 cm_ctx_fl; // x0
  __int64 first_roam_command; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x22
  unsigned int v57; // w9
  unsigned int v58; // w10
  unsigned int v59; // w9
  unsigned int v60; // w10
  unsigned int v61; // w9
  unsigned int v62; // w10
  unsigned int v63; // w9
  unsigned int v64; // w10
  unsigned int v65; // w28
  _QWORD *v66; // x0
  __int64 v67; // x8
  __int64 v68; // x8
  __int64 v69; // x0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  int v78; // w24
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  int v87; // w9
  unsigned int self_macaddr_from_vdev_id; // w24
  int v90; // w8
  unsigned __int16 *v91; // x8
  unsigned __int16 v92; // w9
  int v93; // w10
  _DWORD *v94; // x8
  int v95; // w9
  unsigned int v96; // w24
  int v97; // w9
  __int64 v98; // x8
  __int64 cmpt_obj; // x0
  __int64 v100; // x0
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  size_t v109; // x2
  char v110; // w8
  size_t v111; // x0
  void *v112; // x0
  size_t v113; // x0
  void *v114; // x0
  size_t v115; // x0
  __int64 v116; // x24
  void *v117; // x0
  size_t v118; // x0
  __int64 v119; // x24
  void *v120; // x0
  unsigned int v121; // w28
  __int64 v122; // x24
  size_t v123; // x0
  __int64 v124; // x0
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  unsigned int v133; // w24
  __int64 v134; // x28
  size_t v135; // x0
  void *v136; // x0
  unsigned int v137; // w8
  size_t v138; // x0
  __int64 v139; // x24
  void *v140; // x0
  __int64 v141; // x0
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  unsigned __int16 *v150; // x24
  __int64 v151; // x24
  size_t v152; // x2
  int v153; // w8
  size_t v154; // x2
  double v155; // d0
  double v156; // d1
  double v157; // d2
  double v158; // d3
  double v159; // d4
  double v160; // d5
  double v161; // d6
  double v162; // d7
  int v163; // w28
  __int64 v164; // x8
  __int64 v165; // x0
  __int64 fils_connection_info; // x0
  const char *v167; // x2
  __int64 v168; // x8
  int v169; // w9
  __int64 v170; // x10
  unsigned __int8 *ie_ptr_from_eid; // x0
  double v172; // d0
  double v173; // d1
  double v174; // d2
  double v175; // d3
  double v176; // d4
  double v177; // d5
  double v178; // d6
  double v179; // d7
  int v180; // w1
  const char *v181; // x2
  _QWORD *v182; // x9
  double updated; // d0
  double v184; // d1
  double v185; // d2
  double v186; // d3
  double v187; // d4
  double v188; // d5
  double v189; // d6
  double v190; // d7
  unsigned int v191; // w0
  double v192; // d0
  double v193; // d1
  double v194; // d2
  double v195; // d3
  double v196; // d4
  double v197; // d5
  double v198; // d6
  double v199; // d7
  const char *v200; // x2
  double v201; // d0
  double v202; // d0
  double v203; // d1
  double v204; // d2
  double v205; // d3
  double v206; // d4
  double v207; // d5
  double v208; // d6
  double v209; // d7
  double v210; // d0
  double v211; // d1
  double v212; // d2
  double v213; // d3
  double v214; // d4
  double v215; // d5
  double v216; // d6
  double v217; // d7
  double v218; // d0
  double v219; // d1
  double v220; // d2
  double v221; // d3
  double v222; // d4
  double v223; // d5
  double v224; // d6
  double v225; // d7
  double v226; // d0
  double v227; // d1
  double v228; // d2
  double v229; // d3
  double v230; // d4
  double v231; // d5
  double v232; // d6
  double v233; // d7
  char tdls_chan_switch_prohibited; // w24
  double v235; // d0
  double v236; // d1
  double v237; // d2
  double v238; // d3
  double v239; // d4
  double v240; // d5
  double v241; // d6
  double v242; // d7
  char tdls_prohibited; // w0
  double v244; // d0
  double v245; // d1
  double v246; // d2
  double v247; // d3
  double v248; // d4
  double v249; // d5
  double v250; // d6
  double v251; // d7
  double v252; // d0
  double v253; // d1
  double v254; // d2
  double v255; // d3
  double v256; // d4
  double v257; // d5
  double v258; // d6
  double v259; // d7
  double v260; // d0
  double v261; // d1
  double v262; // d2
  double v263; // d3
  double v264; // d4
  double v265; // d5
  double v266; // d6
  double v267; // d7
  unsigned int v268; // w0
  char is_mlo_vdev; // w0
  int v270; // w8
  unsigned int v271; // w0
  double v272; // d0
  double v273; // d1
  double v274; // d2
  double v275; // d3
  double v276; // d4
  double v277; // d5
  double v278; // d6
  double v279; // d7
  double v280; // d0
  double v281; // d1
  double v282; // d2
  double v283; // d3
  double v284; // d4
  double v285; // d5
  double v286; // d6
  double v287; // d7
  double v288; // d0
  double v289; // d1
  double v290; // d2
  double v291; // d3
  double v292; // d4
  double v293; // d5
  double v294; // d6
  double v295; // d7
  double v296; // d0
  double v297; // d1
  double v298; // d2
  double v299; // d3
  double v300; // d4
  double v301; // d5
  double v302; // d6
  double v303; // d7
  unsigned int v304; // w0
  int v305[2]; // [xsp+18h] [xbp-58h]
  int v306; // [xsp+18h] [xbp-58h]
  unsigned int v307; // [xsp+24h] [xbp-4Ch]
  __int64 *v308; // [xsp+28h] [xbp-48h]
  bool v309; // [xsp+30h] [xbp-40h] BYREF
  unsigned int v310; // [xsp+34h] [xbp-3Ch] BYREF
  __int64 v311; // [xsp+38h] [xbp-38h] BYREF
  __int64 v312; // [xsp+40h] [xbp-30h]
  unsigned __int64 v313; // [xsp+48h] [xbp-28h]
  __int64 v314; // [xsp+50h] [xbp-20h]
  __int64 v315; // [xsp+58h] [xbp-18h]
  int v316; // [xsp+60h] [xbp-10h] BYREF
  __int16 v317; // [xsp+64h] [xbp-Ch]
  __int64 v318; // [xsp+68h] [xbp-8h]

  v318 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v310 = 0;
  v309 = 0;
  context = _cds_get_context(53, (__int64)"cm_fw_roam_sync_propagation", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( context )
  {
    v23 = (__int64)context;
    session_by_vdev_id = pe_find_session_by_vdev_id((__int64)context, a2, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( session_by_vdev_id )
    {
      v33 = session_by_vdev_id;
      v34 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
      if ( !v34 )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev object is NULL",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "cm_fw_roam_sync_propagation");
        self_macaddr_from_vdev_id = 29;
        goto LABEL_24;
      }
      v44 = *(_QWORD *)(v34 + 216);
      v45 = v34;
      if ( !v44
        || (cm_ctx_fl = cm_get_cm_ctx_fl(
                          v34,
                          (__int64)"cm_fw_roam_sync_propagation",
                          0x4FCu,
                          v36,
                          v37,
                          v38,
                          v39,
                          v40,
                          v41,
                          v42,
                          v43)) == 0 )
      {
        self_macaddr_from_vdev_id = 16;
        goto LABEL_22;
      }
      v308 = (__int64 *)cm_ctx_fl;
      first_roam_command = cm_get_first_roam_command(v45, v36, v37, v38, v39, v40, v41, v42, v43);
      if ( first_roam_command )
      {
        v56 = first_roam_command;
        wlan_rec_debug_log((char *)&off_0 + 1, a2, 0x13u, 0, a3 + 7, 0, 0, 0);
        v314 = 0;
        v315 = 0;
        v312 = 0;
        v313 = 0;
        v311 = 0;
        if ( (is_multi_link_roam(a3) & 1) != 0 )
        {
          mlo_mgr_reset_ap_link_info(v45);
          if ( *((_BYTE *)a3 + 2497) )
          {
            qdf_mem_set(&v311, 0x28u, 0);
            v57 = *((_DWORD *)a3 + 629);
            v58 = *((_DWORD *)a3 + 630);
            LOWORD(v311) = *((_DWORD *)a3 + 628);
            v313 = __PAIR64__(v58, v57);
            mlo_mgr_roam_update_ap_link_info(v45, a3 + 1250, &v311);
            cm_update_link_channel_info(v45, (_DWORD)a3 + 2540);
            if ( *((unsigned __int8 *)a3 + 2497) > 1u )
            {
              qdf_mem_set(&v311, 0x28u, 0);
              v59 = *((_DWORD *)a3 + 642);
              v60 = *((_DWORD *)a3 + 643);
              LOWORD(v311) = *((_DWORD *)a3 + 641);
              v313 = __PAIR64__(v60, v59);
              mlo_mgr_roam_update_ap_link_info(v45, a3 + 1276, &v311);
              cm_update_link_channel_info(v45, (_DWORD)a3 + 2592);
              if ( *((unsigned __int8 *)a3 + 2497) >= 3u )
              {
                qdf_mem_set(&v311, 0x28u, 0);
                v61 = *((_DWORD *)a3 + 655);
                v62 = *((_DWORD *)a3 + 656);
                LOWORD(v311) = *((_DWORD *)a3 + 654);
                v313 = __PAIR64__(v62, v61);
                mlo_mgr_roam_update_ap_link_info(v45, a3 + 1302, &v311);
                cm_update_link_channel_info(v45, (_DWORD)a3 + 2644);
                if ( *((unsigned __int8 *)a3 + 2497) >= 4u )
                {
                  qdf_mem_set(&v311, 0x28u, 0);
                  v63 = *((_DWORD *)a3 + 668);
                  v64 = *((_DWORD *)a3 + 669);
                  LOWORD(v311) = *((_DWORD *)a3 + 667);
                  v313 = __PAIR64__(v64, v63);
                  mlo_mgr_roam_update_ap_link_info(v45, a3 + 1328, &v311);
                  cm_update_link_channel_info(v45, (_DWORD)a3 + 2696);
                  if ( *((unsigned __int8 *)a3 + 2497) > 4u )
                    goto LABEL_137;
                }
              }
            }
          }
        }
        cm_delete_crypto_keys_for_all_links(v45);
        v65 = *(_DWORD *)v56;
        v310 = *(_DWORD *)v56;
        v66 = (_QWORD *)_qdf_mem_malloc(0x180u, "cm_fw_roam_sync_propagation", 1296);
        if ( v66 )
        {
          v67 = *(_QWORD *)(v45 + 216);
          v56 = (__int64)v66;
          if ( v67 )
          {
            v68 = *(_QWORD *)(v67 + 80);
            *v66 = v68;
            if ( v68 )
            {
              v69 = _qdf_mem_malloc(0xC8u, "cm_fill_roam_info", 816);
              *(_QWORD *)(v56 + 152) = v69;
              if ( !v69 )
              {
LABEL_73:
                self_macaddr_from_vdev_id = 2;
LABEL_108:
                v181 = "%s: vdev %d cm_id 0x%x:  fail to prepare rsp";
LABEL_109:
                qdf_trace_msg(
                  0x68u,
                  2u,
                  v181,
                  v70,
                  v71,
                  v72,
                  v73,
                  v74,
                  v75,
                  v76,
                  v77,
                  "cm_fw_roam_sync_propagation",
                  (unsigned __int8)a2,
                  v65);
                goto LABEL_110;
              }
              v78 = *(unsigned __int8 *)(v45 + 168);
              *(_BYTE *)(v56 + 8) = v78;
              if ( (is_multi_link_roam(a3) & 1) != 0 )
              {
                v87 = *(_DWORD *)(a3 + 7);
                *(_WORD *)(v56 + 165) = a3[9];
                *(_DWORD *)(v56 + 161) = v87;
              }
              else
              {
                *(_WORD *)(v56 + 165) = 0;
                *(_DWORD *)(v56 + 161) = 0;
              }
              v90 = *((unsigned __int8 *)a3 + 2497);
              v307 = v65;
              if ( !*((_BYTE *)a3 + 2497) )
                goto LABEL_35;
              if ( *((_DWORD *)a3 + 625) == v78 )
              {
                v91 = a3 + 1250;
LABEL_33:
                v92 = v91[22];
                v93 = *((_DWORD *)v91 + 10);
                v94 = v91 + 6;
                *(_WORD *)(v56 + 20) = v92;
                *(_DWORD *)(v56 + 16) = v93;
LABEL_36:
                *(_DWORD *)(v56 + 56) = *v94;
                v96 = *((unsigned __int8 *)a3 + 20);
                if ( *((_BYTE *)a3 + 20) )
                {
                  v97 = *((unsigned __int8 *)a3 + 21);
                  if ( *((_BYTE *)a3 + 21) )
                  {
                    v98 = 0;
                    while ( (v97 | 0x20) == 0x20 )
                    {
                      if ( v96 - 1 == (_DWORD)v98 )
                        goto LABEL_52;
                      v97 = *((unsigned __int8 *)a3 + v98++ + 22);
                    }
                    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v45, v79, v80, v81, v82, v83, v84, v85, v86);
                    if ( cmpt_obj )
                    {
                      if ( v96 > 0x20 )
                      {
                        LOBYTE(v96) = 0;
                      }
                      else
                      {
                        *(_QWORD *)v305 = cmpt_obj;
                        qdf_mem_copy((void *)(cmpt_obj + 145), (char *)a3 + 21, v96);
                        cmpt_obj = *(_QWORD *)v305;
                      }
                      *(_BYTE *)(cmpt_obj + 178) = v96;
                    }
                  }
                }
LABEL_52:
                v100 = wlan_vdev_mlme_get_cmpt_obj(v45, v79, v80, v81, v82, v83, v84, v85, v86);
                if ( v100 )
                {
                  v109 = *(unsigned __int8 *)(v100 + 178);
                  if ( *(_BYTE *)(v100 + 178) )
                  {
                    *(_BYTE *)(v56 + 22) = v109;
                    qdf_mem_copy((void *)(v56 + 23), (const void *)(v100 + 145), v109);
                    v110 = *(_BYTE *)(v56 + 9);
                    *(_DWORD *)(v56 + 60) = 0;
                    *(_DWORD *)(v56 + 12) = v65;
                    *(_BYTE *)(v56 + 9) = v110 | 4;
                    *(_BYTE *)(v56 + 376) = *((_BYTE *)a3 + 392);
                    v111 = *((unsigned int *)a3 + 72);
                    if ( !(_DWORD)v111 )
                    {
LABEL_57:
                      v113 = *((unsigned int *)a3 + 73);
                      if ( (_DWORD)v113 )
                      {
                        *(_DWORD *)(v56 + 360) = v113;
                        v114 = (void *)_qdf_mem_malloc(v113, "cm_copy_tspec_ie", 527);
                        *(_QWORD *)(v56 + 368) = v114;
                        if ( v114 )
                          qdf_mem_copy(
                            v114,
                            (const void *)(*((_QWORD *)a3 + 37) + *((unsigned int *)a3 + 72)),
                            *(unsigned int *)(v56 + 360));
                      }
                      v115 = a3[1];
                      v311 = 0;
                      v312 = 0;
                      if ( (_DWORD)v115 )
                      {
                        *(_DWORD *)(v56 + 80) = v115;
                        v116 = *a3;
                        v117 = (void *)_qdf_mem_malloc(v115, "cm_populate_connect_ies", 434);
                        *(_QWORD *)(v56 + 88) = v117;
                        if ( !v117 )
                          goto LABEL_106;
                        qdf_mem_copy(v117, (char *)a3 + v116, *(unsigned int *)(v56 + 80));
                      }
                      v118 = a3[1247];
                      if ( a3[1247] )
                      {
                        *(_DWORD *)(v56 + 96) = v118;
                        v119 = a3[1246];
                        v120 = (void *)_qdf_mem_malloc(v118, "cm_populate_connect_ies", 449);
                        *(_QWORD *)(v56 + 104) = v120;
                        if ( !v120 )
                          goto LABEL_106;
                        qdf_mem_copy(v120, (char *)a3 + v119, *(unsigned int *)(v56 + 96));
                      }
                      if ( a3[3] >= 0x19u )
                      {
                        if ( (wlan_vdev_mlme_get_is_mlo_link(*(_QWORD *)v56, *(unsigned __int8 *)(v56 + 8)) & 1) != 0 )
                        {
                          v121 = *(unsigned __int8 *)(v56 + 8);
                          v122 = *(_QWORD *)v56;
                          v317 = 0;
                          v316 = 0;
                          v306 = ((__int64 (__fastcall *)(_QWORD, unsigned __int16 *))mlo_roam_get_link_id)(v121, a3);
                          self_macaddr_from_vdev_id = wlan_get_self_macaddr_from_vdev_id(v122, v121, 1u, &v316);
                          if ( self_macaddr_from_vdev_id )
                          {
LABEL_107:
                            v65 = v310;
                            goto LABEL_108;
                          }
                          v123 = a3[3];
                          if ( (unsigned int)v123 < 0x19 )
                          {
                            v133 = 0;
                            v134 = 0;
                          }
                          else
                          {
                            LODWORD(v311) = a3[3];
                            v124 = _qdf_mem_malloc(v123, "cm_roam_fetch_link_specific_assoc_rsp", 385);
                            v312 = v124;
                            if ( !v124 )
                              goto LABEL_106;
                            self_macaddr_from_vdev_id = util_gen_link_assoc_rsp(
                                                          (unsigned int)a3 + a3[2] + 24,
                                                          (unsigned int)a3[3] - 24,
                                                          1,
                                                          v306,
                                                          v316,
                                                          v124,
                                                          a3[3],
                                                          (__int64)&v311);
                            if ( self_macaddr_from_vdev_id )
                            {
                              _qdf_mem_free(v312);
                              v312 = 0;
                              LODWORD(v311) = 0;
                              qdf_trace_msg(
                                0x68u,
                                2u,
                                "%s: MLO ROAM: link_id:%d vdev:%d Reassoc generation failed %d",
                                v125,
                                v126,
                                v127,
                                v128,
                                v129,
                                v130,
                                v131,
                                v132,
                                "cm_roam_fetch_link_specific_assoc_rsp",
                                (unsigned __int8)v306,
                                v121,
                                self_macaddr_from_vdev_id);
                              goto LABEL_107;
                            }
                            v133 = v311;
                            v134 = v312;
                          }
                        }
                        else
                        {
                          v133 = a3[3];
                          v134 = (__int64)a3 + a3[2];
                        }
                        qdf_trace_msg(
                          0x68u,
                          8u,
                          "%s: vdevid: %d Assoc Rsp",
                          v70,
                          v71,
                          v72,
                          v73,
                          v74,
                          v75,
                          v76,
                          v77,
                          "cm_populate_connect_ies",
                          *(unsigned __int8 *)(v56 + 8));
                        ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(31, 8, v134, v133);
                        v135 = v133 - 24;
                        *(_DWORD *)(v56 + 128) = v135;
                        v136 = (void *)_qdf_mem_malloc(v135, "cm_populate_connect_ies", 485);
                        *(_QWORD *)(v56 + 136) = v136;
                        if ( !v136 )
                        {
                          _qdf_mem_free(v312);
                          goto LABEL_106;
                        }
                        qdf_mem_copy(v136, (const void *)(v134 + 24), *(unsigned int *)(v56 + 128));
                        _qdf_mem_free(v312);
                      }
                      v137 = a3[5];
                      if ( v137 < 0x19 )
                      {
LABEL_82:
                        *(_BYTE *)(v56 + 9) = *(_BYTE *)(v56 + 9) & 0xEF | (16 * (*((_BYTE *)a3 + 2457) & 1));
                        if ( a3[203] )
                        {
                          v141 = _qdf_mem_malloc(0x990u, "cm_fill_fils_ie", 338);
                          *(_QWORD *)(v56 + 144) = v141;
                          if ( v141 )
                          {
                            v150 = (unsigned __int16 *)v141;
                            cds_copy_hlp_info(
                              (int *)((char *)a3 + 393),
                              (int *)((char *)a3 + 399),
                              a3[203],
                              a3 + 204,
                              (__int64)v150 + 379,
                              (__int64)v150 + 385,
                              v150 + 1220,
                              (char *)v150 + 391,
                              v142,
                              v143,
                              v144,
                              v145,
                              v146,
                              v147,
                              v148,
                              v149);
                            v150[1221] = a3[129];
                          }
                        }
                        v151 = *(_QWORD *)(v56 + 152);
                        *(_BYTE *)v151 = *((_DWORD *)a3 + 14);
                        *(_BYTE *)(v151 + 1) = *((_BYTE *)a3 + 2497);
                        v152 = *((unsigned __int8 *)a3 + 100);
                        *(_BYTE *)(v151 + 2) = v152;
                        if ( (_DWORD)v152 )
                          qdf_mem_copy((void *)(v151 + 3), a3 + 34, v152);
                        v153 = *((unsigned __int8 *)a3 + 104);
                        *(_BYTE *)(v151 + 35) = v153;
                        if ( v153 )
                          qdf_mem_copy((void *)(v151 + 36), a3 + 54, *((unsigned int *)a3 + 26));
                        qdf_mem_copy((void *)(v151 + 100), a3 + 130, 8u);
                        *(_WORD *)(v151 + 110) = *((_BYTE *)a3 + 61) & 0xF;
                        *(_BYTE *)(v151 + 108) = (*((_BYTE *)a3 + 61) >> 4) & 3;
                        v154 = *((unsigned int *)a3 + 43);
                        *(_DWORD *)(v151 + 112) = v154;
                        if ( (_DWORD)v154 )
                          qdf_mem_copy((void *)(v151 + 116), a3 + 88, v154);
                        qdf_mem_copy((void *)(v151 + 180), a3 + 120, 0x10u);
                        *(_BYTE *)(v151 + 196) = *((_BYTE *)a3 + 256);
                        v163 = a3[129];
                        *(_WORD *)(v151 + 198) = v163;
                        v164 = *(_QWORD *)(v45 + 216);
                        if ( v164 )
                        {
                          v165 = *(_QWORD *)(v164 + 80);
                          if ( v165 )
                          {
                            fils_connection_info = wlan_cm_get_fils_connection_info(
                                                     v165,
                                                     *(unsigned __int8 *)(v45 + 168));
                            if ( fils_connection_info )
                              *(_DWORD *)(fils_connection_info + 260) = v163;
                            goto LABEL_98;
                          }
                          v167 = "%s: vdev %d cm_id 0x%x: Failed to find psoc";
                        }
                        else
                        {
                          v167 = "%s: vdev %d cm_id 0x%x: Failed to find pdev";
                        }
                        qdf_trace_msg(
                          0x68u,
                          2u,
                          v167,
                          v155,
                          v156,
                          v157,
                          v158,
                          v159,
                          v160,
                          v161,
                          v162,
                          "cm_fils_update_erp_seq_num",
                          *(unsigned __int8 *)(v45 + 168),
                          v307);
LABEL_98:
                        v168 = *(_QWORD *)(v56 + 120);
                        if ( v168 )
                        {
                          v169 = *(_DWORD *)(v56 + 112);
                          if ( v169 )
                          {
                            if ( (*(_BYTE *)(v56 + 9) & 0x10) != 0 )
                              v170 = 4;
                            else
                              v170 = 10;
                            ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(
                                                0x7Fu,
                                                (unsigned __int8 *)(v168 + v170),
                                                (unsigned __int16)v169 - (unsigned __int16)v170);
                            if ( ie_ptr_from_eid )
                            {
                              v180 = (ie_ptr_from_eid[4] >> 3) & 1;
                            }
                            else
                            {
                              qdf_trace_msg(
                                0x68u,
                                8u,
                                "%s: Ext cap is not present, disable btm",
                                v172,
                                v173,
                                v174,
                                v175,
                                v176,
                                v177,
                                v178,
                                v179,
                                "cm_update_assoc_btm_cap");
                              LOBYTE(v180) = 0;
                            }
                            wlan_cm_set_assoc_btm_cap(v45, v180, v172, v173, v174, v175, v176, v177, v178, v179);
                          }
                        }
                        v65 = v310;
                        updated = cm_update_scan_db_on_roam_success(v45, v56 + 8, a3, v310);
                        v191 = cm_csr_connect_rsp(v45, v56, updated, v184, v185, v186, v187, v188, v189, v190);
                        if ( v191 )
                        {
                          self_macaddr_from_vdev_id = v191;
                          v200 = "%s: Roam sync propagation failed, abort roaming";
LABEL_124:
                          qdf_trace_msg(
                            0x68u,
                            2u,
                            v200,
                            v192,
                            v193,
                            v194,
                            v195,
                            v196,
                            v197,
                            v198,
                            v199,
                            "cm_fw_roam_sync_propagation");
                          goto LABEL_110;
                        }
                        cm_process_roam_keys(v45, v56, v310);
                        policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, a2);
                        v201 = mlo_roam_copy_partner_info(v56 + 168, a3, 255, 1);
                        mlo_roam_set_link_id(v45, a3, v201);
                        if ( (*(_BYTE *)(v45 + 60) & 2) == 0 )
                        {
                          cm_inform_dlm_connect_complete(*v308, v56 + 8, v202, v203, v204, v205, v206, v207, v208, v209);
                          wlan_p2p_status_connect(v45, v210, v211, v212, v213, v214, v215, v216, v217);
                          if ( (((__int64 (__fastcall *)(_QWORD))cm_csr_is_ss_wait_for_key)(a2) & 1) == 0 )
                          {
                            qdf_trace_msg(
                              0x68u,
                              8u,
                              "%s: vdev %d cm_id 0x%x: WLAN link up with AP = %02x:%02x:%02x:**:**:%02x",
                              v218,
                              v219,
                              v220,
                              v221,
                              v222,
                              v223,
                              v224,
                              v225,
                              "cm_fw_roam_sync_propagation",
                              (unsigned __int8)a2,
                              v310,
                              *(unsigned __int8 *)(v56 + 16),
                              *(unsigned __int8 *)(v56 + 17),
                              *(unsigned __int8 *)(v56 + 18),
                              *(unsigned __int8 *)(v56 + 21));
                            cm_roam_start_init_on_connect(v44, a2);
                          }
                          wlan_cm_tgt_send_roam_sync_complete_cmd(a1, a2);
                          mlo_roam_update_connected_links(v45, v56 + 8);
                          mlo_set_single_link_ml_roaming(a1, a2, 0);
                        }
                        cm_connect_info(
                          v45,
                          1,
                          (const void *)(v56 + 16),
                          (unsigned __int8 *)(v56 + 22),
                          *(_DWORD *)(v56 + 56));
                        tdls_chan_switch_prohibited = mlme_get_tdls_chan_switch_prohibited(
                                                        v45,
                                                        v226,
                                                        v227,
                                                        v228,
                                                        v229,
                                                        v230,
                                                        v231,
                                                        v232,
                                                        v233);
                        tdls_prohibited = mlme_get_tdls_prohibited(v45, v235, v236, v237, v238, v239, v240, v241, v242);
                        v244 = wlan_tdls_notify_sta_connect(
                                 a2,
                                 tdls_chan_switch_prohibited & 1,
                                 tdls_prohibited & 1,
                                 v45);
                        wlan_cm_update_scan_mlme_info(v45, v56 + 8, v244, v245, v246, v247, v248, v249, v250, v251);
                        cm_update_associated_ch_info(v45, 1, v252, v253, v254, v255, v256, v257, v258, v259);
                        v268 = wlan_sm_dispatch(
                                 v308[9],
                                 0x20u,
                                 0xB00u,
                                 (__int64)a3,
                                 v260,
                                 v261,
                                 v262,
                                 v263,
                                 v264,
                                 v265,
                                 v266,
                                 v267);
                        if ( v268 )
                        {
                          self_macaddr_from_vdev_id = v268;
                          v181 = "%s: vdev %d cm_id 0x%x:  fail to post WLAN_CM_SM_EV_ROAM_DONE";
                          goto LABEL_109;
                        }
                        is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v45, v70, v71, v72, v73, v74, v75, v76, v77);
                        v270 = *(_DWORD *)(v45 + 60);
                        if ( (is_mlo_vdev & 1) == 0 || (v270 & 2) != 0 )
                          goto LABEL_139;
                        v271 = mlo_roam_copy_reassoc_rsp(v45, v56 + 8, *((unsigned int *)a3 + 14));
                        if ( v271 )
                        {
                          self_macaddr_from_vdev_id = v271;
                          qdf_trace_msg(
                            0x68u,
                            2u,
                            "%s: vdev %d cm_id 0x%x:  fail to copy reassoc resp status %d",
                            v272,
                            v273,
                            v274,
                            v275,
                            v276,
                            v277,
                            v278,
                            v279,
                            "cm_fw_roam_sync_propagation",
                            (unsigned __int8)a2,
                            v310,
                            v271);
                          goto LABEL_110;
                        }
LABEL_138:
                        v270 = *(_DWORD *)(v45 + 60);
LABEL_139:
                        if ( (v270 & 2) == 0 )
                          mlo_roam_update_connected_links(v45, v56 + 8);
                        mlme_cm_osif_connect_complete();
                        mlme_cm_osif_roam_complete();
                        lim_set_tpc_power(v23, v33, 0, 0, v280, v281, v282, v283, v284, v285, v286, v287);
                        qdf_trace_msg(
                          0x68u,
                          8u,
                          "%s: vdev %d cm_id 0x%x: ",
                          v288,
                          v289,
                          v290,
                          v291,
                          v292,
                          v293,
                          v294,
                          v295,
                          "cm_fw_roam_sync_propagation",
                          (unsigned __int8)a2,
                          v310);
                        cm_remove_cmd(v308, &v310, v296, v297, v298, v299, v300, v301, v302, v303);
                        wlan_psoc_mlme_get_11be_capab(a1, &v309);
                        if ( !v309
                          || (v304 = policy_mgr_current_connections_update(
                                       a1,
                                       (unsigned __int8)a2,
                                       *(_DWORD *)(v56 + 56),
                                       0xFu,
                                       0),
                              v304 == 11) )
                        {
                          wlan_cm_free_connect_rsp(v56);
                          self_macaddr_from_vdev_id = 0;
                        }
                        else
                        {
                          self_macaddr_from_vdev_id = v304;
                          if ( v304 == 16 )
                          {
                            v200 = "%s: Failed to take next action LFR3_ROAM";
                            goto LABEL_124;
                          }
                          wlan_cm_free_connect_rsp(v56);
                          if ( self_macaddr_from_vdev_id )
                            goto LABEL_111;
                        }
LABEL_22:
                        wlan_objmgr_vdev_release_ref(
                          v45,
                          1u,
                          (unsigned int *)v35,
                          v36,
                          v37,
                          v38,
                          v39,
                          v40,
                          v41,
                          v42,
                          v43);
                        goto LABEL_24;
                      }
                      v138 = v137 - 24;
                      *(_DWORD *)(v56 + 112) = v138;
                      v139 = a3[4];
                      v140 = (void *)_qdf_mem_malloc(v138, "cm_populate_connect_ies", 506);
                      *(_QWORD *)(v56 + 120) = v140;
                      if ( v140 )
                      {
                        qdf_mem_copy(v140, (char *)a3 + v139 + 24, *(unsigned int *)(v56 + 112));
                        goto LABEL_82;
                      }
LABEL_106:
                      self_macaddr_from_vdev_id = 2;
                      goto LABEL_107;
                    }
                    *(_DWORD *)(v56 + 344) = v111;
                    v112 = (void *)_qdf_mem_malloc(v111, "cm_fill_roam_info", 851);
                    *(_QWORD *)(v56 + 352) = v112;
                    if ( v112 )
                    {
                      qdf_mem_copy(v112, *((const void **)a3 + 37), *(unsigned int *)(v56 + 344));
                      goto LABEL_57;
                    }
                    goto LABEL_73;
                  }
                  *(_BYTE *)(v56 + 22) = 0;
                }
                qdf_trace_msg(
                  0x68u,
                  2u,
                  "%s: vdev %d cm_id 0x%x: Failed to get ssid",
                  v101,
                  v102,
                  v103,
                  v104,
                  v105,
                  v106,
                  v107,
                  v108,
                  "cm_fill_roam_info",
                  *(unsigned __int8 *)(v56 + 8),
                  v65);
                self_macaddr_from_vdev_id = 16;
                goto LABEL_108;
              }
              if ( v90 == 1 )
                goto LABEL_35;
              if ( *((_DWORD *)a3 + 638) == v78 )
              {
                v91 = a3 + 1276;
                goto LABEL_33;
              }
              if ( v90 == 2 )
                goto LABEL_35;
              if ( *((_DWORD *)a3 + 651) == v78 )
              {
                v91 = a3 + 1302;
                goto LABEL_33;
              }
              if ( v90 == 3 )
                goto LABEL_35;
              if ( *((_DWORD *)a3 + 664) == v78 )
              {
                v91 = a3 + 1328;
                goto LABEL_33;
              }
              if ( v90 == 4 )
              {
LABEL_35:
                v95 = *(_DWORD *)(a3 + 7);
                *(_WORD *)(v56 + 20) = a3[9];
                v94 = a3 + 32;
                *(_DWORD *)(v56 + 16) = v95;
                goto LABEL_36;
              }
LABEL_137:
              __break(0x5512u);
              goto LABEL_138;
            }
          }
          else
          {
            *v66 = 0;
          }
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: vdev %d cm_id 0x%x: Failed to find psoc",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "cm_fw_roam_sync_propagation",
            (unsigned __int8)a2,
            v65);
          self_macaddr_from_vdev_id = 16;
LABEL_110:
          wlan_cm_free_connect_rsp(v56);
          goto LABEL_111;
        }
        self_macaddr_from_vdev_id = 2;
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: Failed to find roam req from list",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "cm_fw_roam_sync_propagation");
        v35 = 0xFFFFFFFFLL;
        self_macaddr_from_vdev_id = 16;
        v310 = -1;
      }
LABEL_111:
      v182 = *(_QWORD **)(v45 + 1360);
      if ( v182 )
      {
        v35 = v182[278];
        if ( v35 )
        {
          if ( v182[3] == v45 )
            *(_QWORD *)(v35 + 8) &= ~1uLL;
          if ( v182[4] == v45 )
            *(_QWORD *)(v35 + 8) &= ~2uLL;
        }
      }
      goto LABEL_22;
    }
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Session not found for vdev_id: %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "cm_fw_roam_sync_propagation",
      (unsigned __int8)a2);
    self_macaddr_from_vdev_id = 16;
  }
  else
  {
    self_macaddr_from_vdev_id = 16;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return self_macaddr_from_vdev_id;
}
