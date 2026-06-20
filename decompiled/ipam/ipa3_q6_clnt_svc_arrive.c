__int64 ipa3_q6_clnt_svc_arrive()
{
  __int64 result; // x0
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 is_apq; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned __int16 smem_restr_bytes; // w0
  __int64 *v18; // x9
  int v19; // w19
  int v20; // w24
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 ep_mapping; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  int v29; // w0
  __int64 v30; // x8
  __int64 *v31; // x10
  int v32; // w12
  int v33; // w12
  int v34; // w12
  __int64 v35; // x11
  __int64 v36; // x11
  __int64 v37; // x11
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x0
  __int64 v83; // x0
  __int64 v84; // x0
  __int64 v85; // x0
  __int64 v86; // x1
  __int64 v87; // x0
  __int64 v88; // x1
  int v89; // w19
  __int64 v90; // x0
  __int64 v91; // x0
  __int64 v92; // x0
  __int64 v93; // x0
  __int64 v94; // x0
  __int64 v95; // x0
  __int64 v96; // x0
  __int64 v97; // x0
  __int64 v98; // x0
  __int64 v99; // x0
  __int64 v100; // x0
  __int64 v101; // x0
  __int64 v102; // x0
  __int64 v103; // x0
  __int64 v104; // x0
  __int64 v105; // x0
  __int64 v106; // x0
  __int64 v107; // x0
  __int64 v108; // x0
  __int64 v109; // x0
  __int64 v110; // x0
  __int64 v111; // x0
  __int64 v112; // x0
  __int64 v113; // x0
  __int64 v114; // x0
  __int64 v115; // x0
  __int64 v116; // x0
  __int64 v117; // x0
  __int64 v118; // x0
  __int64 v119; // x0
  __int64 v120; // x0
  __int64 v121; // x0
  __int64 v122; // x0
  __int64 v123; // x0
  __int64 v124; // x0
  __int64 v125; // x0
  __int64 v126; // x0
  __int64 v127; // x0
  __int64 v128; // x0
  __int64 v129; // x0
  __int64 v130; // x0
  __int64 v131; // x0
  __int64 v132; // x0
  __int64 v133; // x0
  __int64 v134; // x0
  __int64 v135; // x0
  __int64 v136; // x0
  __int64 v137; // x0
  __int64 v138; // x0
  __int64 v139; // x0
  __int64 v140; // x0
  __int64 v141; // x0
  __int64 v142; // x0
  __int64 v143; // x0
  __int64 v144; // x0
  __int64 v145; // x0
  __int64 v146; // x0
  __int64 v147; // x0
  __int64 v148; // x0
  __int64 v149; // x0
  __int64 v150; // x0
  __int64 v151; // x0
  __int64 v152; // x0
  __int64 v153; // x0
  __int64 v154; // x0
  __int64 v155; // x0
  __int64 v156; // x0
  __int64 v157; // x0
  __int64 v158; // x0
  __int64 v159; // x0
  __int64 v160; // x0
  __int64 v161; // x0
  __int64 v162; // x0
  __int64 v163; // x0
  __int64 v164; // x0
  __int64 v165; // x0
  __int64 v166; // x0
  __int64 v167; // x0
  __int64 v168; // x0
  __int64 v169; // x0
  __int64 v170; // x0
  __int64 v171; // x0
  __int64 v172; // x0
  __int64 v173; // x0
  __int64 v174; // x0
  __int64 v175; // x0
  __int64 v176; // x0
  __int64 v177; // x0
  __int64 v178; // x0
  __int64 v179; // x0
  __int64 v180; // x0
  __int64 v181; // x0
  __int64 v182; // x0
  __int64 v183; // x0
  __int64 v184; // x0
  __int64 v185; // x0
  __int64 v186; // x0
  __int64 v187; // x0
  __int64 v188; // x0
  __int64 v189; // x0
  __int64 v190; // x0
  __int64 v191; // x0
  __int64 v192; // x0
  __int64 v193; // x0
  __int64 v194; // x0
  __int64 v195; // x0
  __int64 v196; // x0
  __int64 v197; // x0
  __int64 v198; // x0
  __int64 v199; // x0
  __int64 v200; // x0
  __int64 v201; // x0
  __int64 v202; // x0
  __int64 v203; // x0
  __int64 v204; // x0
  __int64 v205; // x0
  __int64 v206; // x0
  __int64 ipc_logbuf; // x0
  __int64 v208; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v210; // x0
  __int64 v211; // x0
  __int64 v212; // x0
  __int64 v213; // x0
  __int64 v214; // x0
  __int64 v215; // x0
  __int64 v216; // x0
  __int64 v217; // x0
  __int64 v218; // x0
  __int64 v219; // x0
  __int64 v220; // x0
  __int64 v221; // x0
  __int64 v222; // x0
  __int64 v223; // x0
  __int64 v224; // x0
  __int64 v225; // x0
  __int64 v226; // x0
  __int64 v227; // x0
  int v228; // [xsp+4h] [xbp-11Ch] BYREF
  __int64 v229; // [xsp+8h] [xbp-118h] BYREF
  void *v230; // [xsp+10h] [xbp-110h]
  __int64 v231; // [xsp+18h] [xbp-108h] BYREF
  void *v232; // [xsp+20h] [xbp-100h]
  _QWORD v233[3]; // [xsp+28h] [xbp-F8h] BYREF
  __int64 v234; // [xsp+40h] [xbp-E0h] BYREF
  __int64 v235; // [xsp+48h] [xbp-D8h]
  __int64 v236; // [xsp+50h] [xbp-D0h]
  __int64 v237; // [xsp+58h] [xbp-C8h]
  __int64 v238; // [xsp+60h] [xbp-C0h]
  __int64 v239; // [xsp+68h] [xbp-B8h]
  __int64 v240; // [xsp+70h] [xbp-B0h]
  __int64 v241; // [xsp+78h] [xbp-A8h]
  __int64 v242; // [xsp+80h] [xbp-A0h]
  __int64 v243; // [xsp+88h] [xbp-98h]
  __int64 v244; // [xsp+90h] [xbp-90h]
  __int64 v245; // [xsp+98h] [xbp-88h]
  __int64 v246; // [xsp+A0h] [xbp-80h]
  __int64 v247; // [xsp+A8h] [xbp-78h]
  __int64 v248; // [xsp+B0h] [xbp-70h]
  __int64 v249; // [xsp+B8h] [xbp-68h]
  __int64 v250; // [xsp+C0h] [xbp-60h]
  __int64 v251; // [xsp+C8h] [xbp-58h]
  __int64 v252; // [xsp+D0h] [xbp-50h]
  __int64 v253; // [xsp+D8h] [xbp-48h]
  __int64 v254; // [xsp+E0h] [xbp-40h]
  __int64 v255; // [xsp+E8h] [xbp-38h]
  __int64 v256; // [xsp+F0h] [xbp-30h]
  __int64 v257; // [xsp+F8h] [xbp-28h]
  __int64 v258; // [xsp+100h] [xbp-20h]
  __int64 v259; // [xsp+108h] [xbp-18h]
  __int64 v260; // [xsp+110h] [xbp-10h]
  __int64 v261; // [xsp+118h] [xbp-8h]

  v261 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v228 = 0;
  if ( !ipa_q6_clnt )
  {
    v206 = printk(&unk_3CD10F, "ipa3_q6_clnt_svc_arrive");
    ipc_logbuf = ipa3_get_ipc_logbuf(v206);
    if ( ipc_logbuf )
    {
      v208 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(
                     v208,
                     "ipa-wan %s:%d Invalid q6 clnt.Ignore sending ind.\n",
                     "ipa3_q6_clnt_svc_arrive",
                     2069);
    }
    result = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( result )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(
                 ipc_logbuf_low,
                 "ipa-wan %s:%d Invalid q6 clnt.Ignore sending ind.\n",
                 "ipa3_q6_clnt_svc_arrive",
                 2069);
    }
    goto LABEL_13;
  }
  result = kernel_connect(*(_QWORD *)ipa_q6_clnt, ipa3_qmi_ctx + 28876, 12, 0);
  if ( (result & 0x80000000) != 0 )
  {
    v9 = printk(&unk_3D61AE, "ipa3_q6_clnt_svc_arrive");
    v10 = ipa3_get_ipc_logbuf(v9);
    if ( v10 )
    {
      v11 = ipa3_get_ipc_logbuf(v10);
      v10 = ipc_log_string(v11, "ipa-wan %s:%d Couldnt connect Server\n", "ipa3_q6_clnt_svc_arrive", 2079);
    }
    result = ipa3_get_ipc_logbuf_low(v10);
    if ( result )
    {
      v12 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(v12, "ipa-wan %s:%d Couldnt connect Server\n", "ipa3_q6_clnt_svc_arrive", 2079);
    }
    goto LABEL_13;
  }
  if ( send_qmi_init_q6 != 1 )
    goto LABEL_13;
  v1 = ipa3_get_ipc_logbuf(result);
  if ( v1 )
  {
    v2 = ipa3_get_ipc_logbuf(v1);
    v1 = ipc_log_string(v2, "ipa-wan %s:%d Q6 QMI service available now\n", "ipa3_q6_clnt_svc_arrive", 2086);
  }
  v3 = ipa3_get_ipc_logbuf_low(v1);
  if ( v3 )
  {
    v4 = ipa3_get_ipc_logbuf_low(v3);
    v3 = ipc_log_string(v4, "ipa-wan %s:%d Q6 QMI service available now\n", "ipa3_q6_clnt_svc_arrive", 2086);
  }
  is_apq = ipa3_is_apq(v3);
  if ( (is_apq & 1) != 0 )
  {
    ipa3_qmi_modem_init_fin = 1;
    v6 = ipa3_get_ipc_logbuf(is_apq);
    if ( v6 )
    {
      v7 = ipa3_get_ipc_logbuf(v6);
      v6 = ipc_log_string(
             v7,
             "ipa-wan %s:%d QMI-client complete, ipa3_qmi_modem_init_fin : %d\n",
             "ipa3_q6_clnt_svc_arrive",
             2090,
             (unsigned __int8)ipa3_qmi_modem_init_fin);
    }
    result = ipa3_get_ipc_logbuf_low(v6);
    if ( result )
    {
      v8 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(
                 v8,
                 "ipa-wan %s:%d QMI-client complete, ipa3_qmi_modem_init_fin : %d\n",
                 "ipa3_q6_clnt_svc_arrive",
                 2090,
                 (unsigned __int8)ipa3_qmi_modem_init_fin);
    }
    goto LABEL_13;
  }
  v13 = ipa3_get_ipc_logbuf(is_apq);
  if ( v13 )
  {
    v14 = ipa3_get_ipc_logbuf(v13);
    v13 = ipc_log_string(
            v14,
            "ipa-wan %s:%d send ipa3_qmi_init_modem_send_sync_msg to modem\n",
            "ipa3_q6_clnt_svc_arrive",
            2095);
  }
  v15 = ipa3_get_ipc_logbuf_low(v13);
  if ( v15 )
  {
    v16 = ipa3_get_ipc_logbuf_low(v15);
    v15 = ipc_log_string(
            v16,
            "ipa-wan %s:%d send ipa3_qmi_init_modem_send_sync_msg to modem\n",
            "ipa3_q6_clnt_svc_arrive",
            2095);
  }
  v259 = 0;
  v260 = 0;
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
  v243 = 0;
  v244 = 0;
  v241 = 0;
  v242 = 0;
  v239 = 0;
  v240 = 0;
  v237 = 0;
  v238 = 0;
  v236 = 0;
  v231 = 0;
  v232 = nullptr;
  v229 = 0;
  v230 = nullptr;
  smem_restr_bytes = ipa3_get_smem_restr_bytes(v15);
  v234 = 0;
  v235 = 0;
  v18 = *(__int64 **)(ipa3_ctx + 34176);
  v236 = 0;
  v237 = 0;
  v238 = 0;
  v239 = 0;
  v240 = 0;
  v241 = 0;
  v242 = 0;
  v243 = 0;
  v244 = 0;
  v245 = 0;
  v246 = 0;
  v247 = 0;
  v248 = 0;
  v249 = 0;
  v250 = 0;
  v251 = 0;
  v252 = 0;
  v253 = 0;
  v254 = 0;
  v255 = 0;
  v256 = 0;
  v257 = 0;
  v258 = 0;
  v259 = 0;
  v260 = 0;
  v19 = smem_restr_bytes;
  v20 = smem_restr_bytes - 1;
  memset(v233, 0, sizeof(v233));
  LOBYTE(v234) = 1;
  HIDWORD(v234) = ipa_wan_platform;
  LOBYTE(v235) = *(_DWORD *)(*v18 + 144) != 0;
  HIDWORD(v235) = *(_DWORD *)(*v18 + 140) + smem_restr_bytes;
  v21 = *v18;
  BYTE4(v236) = 1;
  LODWORD(v236) = *(_DWORD *)(v21 + 140) + v20 + *(_DWORD *)(v21 + 144);
  LODWORD(v237) = *(_DWORD *)(*v18 + 84) + smem_restr_bytes;
  v22 = *v18;
  LOBYTE(v238) = 1;
  HIDWORD(v237) = *(_DWORD *)(v22 + 60);
  HIDWORD(v238) = *(_DWORD *)(*v18 + 128) + smem_restr_bytes;
  v23 = *v18;
  BYTE4(v239) = 1;
  LODWORD(v239) = *(_DWORD *)(v23 + 104);
  LODWORD(v23) = *(_DWORD *)(*v18 + 16);
  BYTE4(v240) = 1;
  LODWORD(v240) = v23 + smem_restr_bytes;
  LODWORD(v241) = *(_DWORD *)(*v18 + 40) + smem_restr_bytes;
  BYTE4(v241) = *(_DWORD *)(*v18 + 200) != 0;
  LODWORD(v242) = *(_DWORD *)(*v18 + 196) + smem_restr_bytes;
  HIDWORD(v242) = *(_DWORD *)(*v18 + 200);
  ep_mapping = ipa_get_ep_mapping(35);
  if ( (_DWORD)ep_mapping == -1 )
  {
    v25 = ipa3_get_ipc_logbuf(ep_mapping);
    if ( v25 )
    {
      v26 = ipa3_get_ipc_logbuf(v25);
      v25 = ipc_log_string(v26, "ipa-wan %s:%d APPS_WAN_CONS is not valid\n", "ipa3_qmi_init_modem_send_sync_msg", 641);
    }
    v27 = ipa3_get_ipc_logbuf_low(v25);
    if ( v27 )
    {
      v28 = ipa3_get_ipc_logbuf_low(v27);
      ipc_log_string(v28, "ipa-wan %s:%d APPS_WAN_CONS is not valid\n", "ipa3_qmi_init_modem_send_sync_msg", 641);
    }
    v29 = 0;
    LOBYTE(v243) = 0;
  }
  else
  {
    LOBYTE(v243) = 1;
    v29 = ipa_get_ep_mapping(35);
  }
  HIDWORD(v243) = v29;
  v30 = *(_QWORD *)(ipa3_ctx + 34176);
  BYTE2(v244) = *(_DWORD *)(*(_QWORD *)v30 + 164LL) != 0;
  HIDWORD(v244) = *(_DWORD *)(*(_QWORD *)v30 + 160LL) + v19;
  LODWORD(v245) = *(_DWORD *)(*(_QWORD *)v30 + 160LL) + v20 + *(_DWORD *)(*(_QWORD *)v30 + 164LL);
  BYTE4(v245) = *(_DWORD *)(*(_QWORD *)v30 + 192LL) != 0;
  LODWORD(v246) = *(_DWORD *)(*(_QWORD *)v30 + 192LL) + v19;
  HIDWORD(v246) = *(_DWORD *)(*(_QWORD *)v30 + 188LL) + v20 + *(_DWORD *)(*(_QWORD *)v30 + 192LL);
  if ( (ipa3_ctx_get_flag(3) & 1) != 0 )
  {
    v31 = *(__int64 **)(ipa3_ctx + 34176);
  }
  else
  {
    LOBYTE(v247) = 1;
    v31 = *(__int64 **)(ipa3_ctx + 34176);
    HIDWORD(v247) = *(_DWORD *)(*v31 + 72) + v19;
    v32 = *(_DWORD *)(*v31 + 60);
    BYTE4(v248) = 1;
    LODWORD(v248) = v32;
    LODWORD(v249) = *(_DWORD *)(*v31 + 116) + v19;
    v33 = *(_DWORD *)(*v31 + 104);
    LOBYTE(v250) = 1;
    HIDWORD(v249) = v33;
    v34 = *(_DWORD *)(*v31 + 4);
    LOBYTE(v251) = 1;
    HIDWORD(v250) = v34 + v19;
    HIDWORD(v251) = *(_DWORD *)(*v31 + 28) + v19;
  }
  LOBYTE(v252) = 1;
  v35 = *v31;
  LOBYTE(v253) = 1;
  HIDWORD(v252) = *(_DWORD *)(v35 + 296) + v19;
  v36 = *v31;
  LOBYTE(v254) = 1;
  HIDWORD(v253) = *(_DWORD *)(v36 + 300);
  v37 = *v31;
  LOBYTE(v255) = 1;
  HIDWORD(v254) = *(_DWORD *)(v37 + 368) + v19;
  HIDWORD(v255) = *(_DWORD *)(*v31 + 372);
  if ( *(_DWORD *)(ipa3_ctx + 32256) != 2 )
  {
    BYTE4(v259) = 1;
    HIDWORD(v260) = 2048;
    LODWORD(v260) = *(_QWORD *)(ipa3_ctx + 51424);
  }
  v38 = ipa3_uc_loaded_check();
  LOBYTE(v256) = 1;
  LOBYTE(v244) = (_DWORD)v38 != 0;
  BYTE1(v244) = (_DWORD)v38 != 0;
  v39 = **(_QWORD **)(ipa3_ctx + 34176);
  WORD2(v257) = -448;
  LOBYTE(v258) = 1;
  HIDWORD(v256) = *(_DWORD *)(v39 + 320);
  LODWORD(v257) = 3056;
  LODWORD(v259) = *(_DWORD *)(ipa3_ctx + 51440);
  v40 = ipa3_get_ipc_logbuf(v38);
  if ( v40 )
  {
    v95 = ipa3_get_ipc_logbuf(v40);
    v96 = ipc_log_string(
            v95,
            "ipa-wan %s:%d hw_flt stats: hw_filter_start_address = %u",
            "ipa3_qmi_init_modem_send_sync_msg",
            727,
            HIDWORD(v256));
    v41 = ipa3_get_ipc_logbuf_low(v96);
    if ( !v41 )
    {
LABEL_36:
      v42 = ipa3_get_ipc_logbuf(v41);
      if ( !v42 )
        goto LABEL_37;
      goto LABEL_89;
    }
  }
  else
  {
    v41 = ipa3_get_ipc_logbuf_low(0);
    if ( !v41 )
      goto LABEL_36;
  }
  v97 = ipa3_get_ipc_logbuf_low(v41);
  v98 = ipc_log_string(
          v97,
          "ipa-wan %s:%d hw_flt stats: hw_filter_start_address = %u",
          "ipa3_qmi_init_modem_send_sync_msg",
          727,
          HIDWORD(v256));
  v42 = ipa3_get_ipc_logbuf(v98);
  if ( !v42 )
  {
LABEL_37:
    v43 = ipa3_get_ipc_logbuf_low(v42);
    if ( !v43 )
      goto LABEL_38;
    goto LABEL_90;
  }
LABEL_89:
  v99 = ipa3_get_ipc_logbuf(v42);
  v100 = ipc_log_string(
           v99,
           "ipa-wan %s:%d hw_flt stats: hw_filter_stats_size = %u",
           "ipa3_qmi_init_modem_send_sync_msg",
           728,
           v257);
  v43 = ipa3_get_ipc_logbuf_low(v100);
  if ( !v43 )
  {
LABEL_38:
    v44 = ipa3_get_ipc_logbuf(v43);
    if ( !v44 )
      goto LABEL_39;
    goto LABEL_91;
  }
LABEL_90:
  v101 = ipa3_get_ipc_logbuf_low(v43);
  v102 = ipc_log_string(
           v101,
           "ipa-wan %s:%d hw_flt stats: hw_filter_stats_size = %u",
           "ipa3_qmi_init_modem_send_sync_msg",
           728,
           v257);
  v44 = ipa3_get_ipc_logbuf(v102);
  if ( !v44 )
  {
LABEL_39:
    v45 = ipa3_get_ipc_logbuf_low(v44);
    if ( !v45 )
      goto LABEL_40;
    goto LABEL_92;
  }
LABEL_91:
  v103 = ipa3_get_ipc_logbuf(v44);
  v104 = ipc_log_string(
           v103,
           "ipa-wan %s:%d hw_flt stats: hw_filter_stats_start_index  = %u",
           "ipa3_qmi_init_modem_send_sync_msg",
           729,
           BYTE4(v257));
  v45 = ipa3_get_ipc_logbuf_low(v104);
  if ( !v45 )
  {
LABEL_40:
    v46 = ipa3_get_ipc_logbuf(v45);
    if ( !v46 )
      goto LABEL_41;
    goto LABEL_93;
  }
LABEL_92:
  v105 = ipa3_get_ipc_logbuf_low(v45);
  v106 = ipc_log_string(
           v105,
           "ipa-wan %s:%d hw_flt stats: hw_filter_stats_start_index  = %u",
           "ipa3_qmi_init_modem_send_sync_msg",
           729,
           BYTE4(v257));
  v46 = ipa3_get_ipc_logbuf(v106);
  if ( !v46 )
  {
LABEL_41:
    v47 = ipa3_get_ipc_logbuf_low(v46);
    if ( !v47 )
      goto LABEL_42;
    goto LABEL_94;
  }
LABEL_93:
  v107 = ipa3_get_ipc_logbuf(v46);
  v108 = ipc_log_string(
           v107,
           "ipa-wan %s:%d platform_type %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           730,
           HIDWORD(v234));
  v47 = ipa3_get_ipc_logbuf_low(v108);
  if ( !v47 )
  {
LABEL_42:
    v48 = ipa3_get_ipc_logbuf(v47);
    if ( !v48 )
      goto LABEL_43;
    goto LABEL_95;
  }
LABEL_94:
  v109 = ipa3_get_ipc_logbuf_low(v47);
  v110 = ipc_log_string(
           v109,
           "ipa-wan %s:%d platform_type %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           730,
           HIDWORD(v234));
  v48 = ipa3_get_ipc_logbuf(v110);
  if ( !v48 )
  {
LABEL_43:
    v49 = ipa3_get_ipc_logbuf_low(v48);
    if ( !v49 )
      goto LABEL_44;
    goto LABEL_96;
  }
LABEL_95:
  v111 = ipa3_get_ipc_logbuf(v48);
  v112 = ipc_log_string(
           v111,
           "ipa-wan %s:%d hdr_tbl_info.modem_offset_start %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           732,
           HIDWORD(v235));
  v49 = ipa3_get_ipc_logbuf_low(v112);
  if ( !v49 )
  {
LABEL_44:
    v50 = ipa3_get_ipc_logbuf(v49);
    if ( !v50 )
      goto LABEL_45;
    goto LABEL_97;
  }
LABEL_96:
  v113 = ipa3_get_ipc_logbuf_low(v49);
  v114 = ipc_log_string(
           v113,
           "ipa-wan %s:%d hdr_tbl_info.modem_offset_start %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           732,
           HIDWORD(v235));
  v50 = ipa3_get_ipc_logbuf(v114);
  if ( !v50 )
  {
LABEL_45:
    v51 = ipa3_get_ipc_logbuf_low(v50);
    if ( !v51 )
      goto LABEL_46;
    goto LABEL_98;
  }
LABEL_97:
  v115 = ipa3_get_ipc_logbuf(v50);
  v116 = ipc_log_string(
           v115,
           "ipa-wan %s:%d hdr_tbl_info.modem_offset_end %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           734,
           v236);
  v51 = ipa3_get_ipc_logbuf_low(v116);
  if ( !v51 )
  {
LABEL_46:
    v52 = ipa3_get_ipc_logbuf(v51);
    if ( !v52 )
      goto LABEL_47;
    goto LABEL_99;
  }
LABEL_98:
  v117 = ipa3_get_ipc_logbuf_low(v51);
  v118 = ipc_log_string(
           v117,
           "ipa-wan %s:%d hdr_tbl_info.modem_offset_end %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           734,
           v236);
  v52 = ipa3_get_ipc_logbuf(v118);
  if ( !v52 )
  {
LABEL_47:
    v53 = ipa3_get_ipc_logbuf_low(v52);
    if ( !v53 )
      goto LABEL_48;
    goto LABEL_100;
  }
LABEL_99:
  v119 = ipa3_get_ipc_logbuf(v52);
  v120 = ipc_log_string(
           v119,
           "ipa-wan %s:%d v4_route_tbl_info.route_tbl_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           736,
           v237);
  v53 = ipa3_get_ipc_logbuf_low(v120);
  if ( !v53 )
  {
LABEL_48:
    v54 = ipa3_get_ipc_logbuf(v53);
    if ( !v54 )
      goto LABEL_49;
    goto LABEL_101;
  }
LABEL_100:
  v121 = ipa3_get_ipc_logbuf_low(v53);
  v122 = ipc_log_string(
           v121,
           "ipa-wan %s:%d v4_route_tbl_info.route_tbl_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           736,
           v237);
  v54 = ipa3_get_ipc_logbuf(v122);
  if ( !v54 )
  {
LABEL_49:
    v55 = ipa3_get_ipc_logbuf_low(v54);
    if ( !v55 )
      goto LABEL_50;
    goto LABEL_102;
  }
LABEL_101:
  v123 = ipa3_get_ipc_logbuf(v54);
  v124 = ipc_log_string(
           v123,
           "ipa-wan %s:%d v4_route_tbl_info.num_indices %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           738,
           HIDWORD(v237));
  v55 = ipa3_get_ipc_logbuf_low(v124);
  if ( !v55 )
  {
LABEL_50:
    v56 = ipa3_get_ipc_logbuf(v55);
    if ( !v56 )
      goto LABEL_51;
    goto LABEL_103;
  }
LABEL_102:
  v125 = ipa3_get_ipc_logbuf_low(v55);
  v126 = ipc_log_string(
           v125,
           "ipa-wan %s:%d v4_route_tbl_info.num_indices %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           738,
           HIDWORD(v237));
  v56 = ipa3_get_ipc_logbuf(v126);
  if ( !v56 )
  {
LABEL_51:
    v57 = ipa3_get_ipc_logbuf_low(v56);
    if ( !v57 )
      goto LABEL_52;
    goto LABEL_104;
  }
LABEL_103:
  v127 = ipa3_get_ipc_logbuf(v56);
  v128 = ipc_log_string(
           v127,
           "ipa-wan %s:%d v6_route_tbl_info.route_tbl_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           740,
           HIDWORD(v238));
  v57 = ipa3_get_ipc_logbuf_low(v128);
  if ( !v57 )
  {
LABEL_52:
    v58 = ipa3_get_ipc_logbuf(v57);
    if ( !v58 )
      goto LABEL_53;
    goto LABEL_105;
  }
LABEL_104:
  v129 = ipa3_get_ipc_logbuf_low(v57);
  v130 = ipc_log_string(
           v129,
           "ipa-wan %s:%d v6_route_tbl_info.route_tbl_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           740,
           HIDWORD(v238));
  v58 = ipa3_get_ipc_logbuf(v130);
  if ( !v58 )
  {
LABEL_53:
    v59 = ipa3_get_ipc_logbuf_low(v58);
    if ( !v59 )
      goto LABEL_54;
    goto LABEL_106;
  }
LABEL_105:
  v131 = ipa3_get_ipc_logbuf(v58);
  v132 = ipc_log_string(
           v131,
           "ipa-wan %s:%d v6_route_tbl_info.num_indices %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           742,
           v239);
  v59 = ipa3_get_ipc_logbuf_low(v132);
  if ( !v59 )
  {
LABEL_54:
    v60 = ipa3_get_ipc_logbuf(v59);
    if ( !v60 )
      goto LABEL_55;
    goto LABEL_107;
  }
LABEL_106:
  v133 = ipa3_get_ipc_logbuf_low(v59);
  v134 = ipc_log_string(
           v133,
           "ipa-wan %s:%d v6_route_tbl_info.num_indices %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           742,
           v239);
  v60 = ipa3_get_ipc_logbuf(v134);
  if ( !v60 )
  {
LABEL_55:
    v61 = ipa3_get_ipc_logbuf_low(v60);
    if ( !v61 )
      goto LABEL_56;
    goto LABEL_108;
  }
LABEL_107:
  v135 = ipa3_get_ipc_logbuf(v60);
  v136 = ipc_log_string(
           v135,
           "ipa-wan %s:%d v4_filter_tbl_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           744,
           v240);
  v61 = ipa3_get_ipc_logbuf_low(v136);
  if ( !v61 )
  {
LABEL_56:
    v62 = ipa3_get_ipc_logbuf(v61);
    if ( !v62 )
      goto LABEL_57;
    goto LABEL_109;
  }
LABEL_108:
  v137 = ipa3_get_ipc_logbuf_low(v61);
  v138 = ipc_log_string(
           v137,
           "ipa-wan %s:%d v4_filter_tbl_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           744,
           v240);
  v62 = ipa3_get_ipc_logbuf(v138);
  if ( !v62 )
  {
LABEL_57:
    v63 = ipa3_get_ipc_logbuf_low(v62);
    if ( !v63 )
      goto LABEL_58;
    goto LABEL_110;
  }
LABEL_109:
  v139 = ipa3_get_ipc_logbuf(v62);
  v140 = ipc_log_string(
           v139,
           "ipa-wan %s:%d v6_filter_tbl_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           746,
           v241);
  v63 = ipa3_get_ipc_logbuf_low(v140);
  if ( !v63 )
  {
LABEL_58:
    v64 = ipa3_get_ipc_logbuf(v63);
    if ( !v64 )
      goto LABEL_59;
    goto LABEL_111;
  }
LABEL_110:
  v141 = ipa3_get_ipc_logbuf_low(v63);
  v142 = ipc_log_string(
           v141,
           "ipa-wan %s:%d v6_filter_tbl_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           746,
           v241);
  v64 = ipa3_get_ipc_logbuf(v142);
  if ( !v64 )
  {
LABEL_59:
    v65 = ipa3_get_ipc_logbuf_low(v64);
    if ( !v65 )
      goto LABEL_60;
    goto LABEL_112;
  }
LABEL_111:
  v143 = ipa3_get_ipc_logbuf(v64);
  v144 = ipc_log_string(
           v143,
           "ipa-wan %s:%d modem_mem_info.block_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           748,
           v242);
  v65 = ipa3_get_ipc_logbuf_low(v144);
  if ( !v65 )
  {
LABEL_60:
    v66 = ipa3_get_ipc_logbuf(v65);
    if ( !v66 )
      goto LABEL_61;
    goto LABEL_113;
  }
LABEL_112:
  v145 = ipa3_get_ipc_logbuf_low(v65);
  v146 = ipc_log_string(
           v145,
           "ipa-wan %s:%d modem_mem_info.block_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           748,
           v242);
  v66 = ipa3_get_ipc_logbuf(v146);
  if ( !v66 )
  {
LABEL_61:
    v67 = ipa3_get_ipc_logbuf_low(v66);
    if ( !v67 )
      goto LABEL_62;
    goto LABEL_114;
  }
LABEL_113:
  v147 = ipa3_get_ipc_logbuf(v66);
  v148 = ipc_log_string(
           v147,
           "ipa-wan %s:%d modem_mem_info.size %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           750,
           HIDWORD(v242));
  v67 = ipa3_get_ipc_logbuf_low(v148);
  if ( !v67 )
  {
LABEL_62:
    v68 = ipa3_get_ipc_logbuf(v67);
    if ( !v68 )
      goto LABEL_63;
    goto LABEL_115;
  }
LABEL_114:
  v149 = ipa3_get_ipc_logbuf_low(v67);
  v150 = ipc_log_string(
           v149,
           "ipa-wan %s:%d modem_mem_info.size %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           750,
           HIDWORD(v242));
  v68 = ipa3_get_ipc_logbuf(v150);
  if ( !v68 )
  {
LABEL_63:
    v69 = ipa3_get_ipc_logbuf_low(v68);
    if ( !v69 )
      goto LABEL_64;
    goto LABEL_116;
  }
LABEL_115:
  v151 = ipa3_get_ipc_logbuf(v68);
  v152 = ipc_log_string(
           v151,
           "ipa-wan %s:%d ctrl_comm_dest_end_pt %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           752,
           HIDWORD(v243));
  v69 = ipa3_get_ipc_logbuf_low(v152);
  if ( !v69 )
  {
LABEL_64:
    v70 = ipa3_get_ipc_logbuf(v69);
    if ( !v70 )
      goto LABEL_65;
    goto LABEL_117;
  }
LABEL_116:
  v153 = ipa3_get_ipc_logbuf_low(v69);
  v154 = ipc_log_string(
           v153,
           "ipa-wan %s:%d ctrl_comm_dest_end_pt %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           752,
           HIDWORD(v243));
  v70 = ipa3_get_ipc_logbuf(v154);
  if ( !v70 )
  {
LABEL_65:
    v71 = ipa3_get_ipc_logbuf_low(v70);
    if ( !v71 )
      goto LABEL_66;
    goto LABEL_118;
  }
LABEL_117:
  v155 = ipa3_get_ipc_logbuf(v70);
  v156 = ipc_log_string(v155, "ipa-wan %s:%d is_ssr_bootup %d\n", "ipa3_qmi_init_modem_send_sync_msg", 754, BYTE1(v244));
  v71 = ipa3_get_ipc_logbuf_low(v156);
  if ( !v71 )
  {
LABEL_66:
    v72 = ipa3_get_ipc_logbuf(v71);
    if ( !v72 )
      goto LABEL_67;
    goto LABEL_119;
  }
LABEL_118:
  v157 = ipa3_get_ipc_logbuf_low(v71);
  v158 = ipc_log_string(v157, "ipa-wan %s:%d is_ssr_bootup %d\n", "ipa3_qmi_init_modem_send_sync_msg", 754, BYTE1(v244));
  v72 = ipa3_get_ipc_logbuf(v158);
  if ( !v72 )
  {
LABEL_67:
    v73 = ipa3_get_ipc_logbuf_low(v72);
    if ( !v73 )
      goto LABEL_68;
    goto LABEL_120;
  }
LABEL_119:
  v159 = ipa3_get_ipc_logbuf(v72);
  v160 = ipc_log_string(
           v159,
           "ipa-wan %s:%d v4_hash_route_tbl_info.route_tbl_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           756,
           HIDWORD(v247));
  v73 = ipa3_get_ipc_logbuf_low(v160);
  if ( !v73 )
  {
LABEL_68:
    v74 = ipa3_get_ipc_logbuf(v73);
    if ( !v74 )
      goto LABEL_69;
    goto LABEL_121;
  }
LABEL_120:
  v161 = ipa3_get_ipc_logbuf_low(v73);
  v162 = ipc_log_string(
           v161,
           "ipa-wan %s:%d v4_hash_route_tbl_info.route_tbl_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           756,
           HIDWORD(v247));
  v74 = ipa3_get_ipc_logbuf(v162);
  if ( !v74 )
  {
LABEL_69:
    v75 = ipa3_get_ipc_logbuf_low(v74);
    if ( !v75 )
      goto LABEL_70;
    goto LABEL_122;
  }
LABEL_121:
  v163 = ipa3_get_ipc_logbuf(v74);
  v164 = ipc_log_string(
           v163,
           "ipa-wan %s:%d v4_hash_route_tbl_info.num_indices %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           758,
           v248);
  v75 = ipa3_get_ipc_logbuf_low(v164);
  if ( !v75 )
  {
LABEL_70:
    v76 = ipa3_get_ipc_logbuf(v75);
    if ( !v76 )
      goto LABEL_71;
    goto LABEL_123;
  }
LABEL_122:
  v165 = ipa3_get_ipc_logbuf_low(v75);
  v166 = ipc_log_string(
           v165,
           "ipa-wan %s:%d v4_hash_route_tbl_info.num_indices %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           758,
           v248);
  v76 = ipa3_get_ipc_logbuf(v166);
  if ( !v76 )
  {
LABEL_71:
    v77 = ipa3_get_ipc_logbuf_low(v76);
    if ( !v77 )
      goto LABEL_72;
    goto LABEL_124;
  }
LABEL_123:
  v167 = ipa3_get_ipc_logbuf(v76);
  v168 = ipc_log_string(
           v167,
           "ipa-wan %s:%d v6_hash_route_tbl_info.route_tbl_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           760,
           v249);
  v77 = ipa3_get_ipc_logbuf_low(v168);
  if ( !v77 )
  {
LABEL_72:
    v78 = ipa3_get_ipc_logbuf(v77);
    if ( !v78 )
      goto LABEL_73;
    goto LABEL_125;
  }
LABEL_124:
  v169 = ipa3_get_ipc_logbuf_low(v77);
  v170 = ipc_log_string(
           v169,
           "ipa-wan %s:%d v6_hash_route_tbl_info.route_tbl_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           760,
           v249);
  v78 = ipa3_get_ipc_logbuf(v170);
  if ( !v78 )
  {
LABEL_73:
    v79 = ipa3_get_ipc_logbuf_low(v78);
    if ( !v79 )
      goto LABEL_74;
    goto LABEL_126;
  }
LABEL_125:
  v171 = ipa3_get_ipc_logbuf(v78);
  v172 = ipc_log_string(
           v171,
           "ipa-wan %s:%d v6_hash_route_tbl_info.num_indices %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           762,
           HIDWORD(v249));
  v79 = ipa3_get_ipc_logbuf_low(v172);
  if ( !v79 )
  {
LABEL_74:
    v80 = ipa3_get_ipc_logbuf(v79);
    if ( !v80 )
      goto LABEL_75;
    goto LABEL_127;
  }
LABEL_126:
  v173 = ipa3_get_ipc_logbuf_low(v79);
  v174 = ipc_log_string(
           v173,
           "ipa-wan %s:%d v6_hash_route_tbl_info.num_indices %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           762,
           HIDWORD(v249));
  v80 = ipa3_get_ipc_logbuf(v174);
  if ( !v80 )
  {
LABEL_75:
    v81 = ipa3_get_ipc_logbuf_low(v80);
    if ( !v81 )
      goto LABEL_76;
    goto LABEL_128;
  }
LABEL_127:
  v175 = ipa3_get_ipc_logbuf(v80);
  v176 = ipc_log_string(
           v175,
           "ipa-wan %s:%d v4_hash_filter_tbl_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           764,
           HIDWORD(v250));
  v81 = ipa3_get_ipc_logbuf_low(v176);
  if ( !v81 )
  {
LABEL_76:
    v82 = ipa3_get_ipc_logbuf(v81);
    if ( !v82 )
      goto LABEL_77;
    goto LABEL_129;
  }
LABEL_128:
  v177 = ipa3_get_ipc_logbuf_low(v81);
  v178 = ipc_log_string(
           v177,
           "ipa-wan %s:%d v4_hash_filter_tbl_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           764,
           HIDWORD(v250));
  v82 = ipa3_get_ipc_logbuf(v178);
  if ( !v82 )
  {
LABEL_77:
    v83 = ipa3_get_ipc_logbuf_low(v82);
    if ( !v83 )
      goto LABEL_78;
    goto LABEL_130;
  }
LABEL_129:
  v179 = ipa3_get_ipc_logbuf(v82);
  v180 = ipc_log_string(
           v179,
           "ipa-wan %s:%d v6_hash_filter_tbl_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           766,
           HIDWORD(v251));
  v83 = ipa3_get_ipc_logbuf_low(v180);
  if ( !v83 )
  {
LABEL_78:
    v84 = ipa3_get_ipc_logbuf(v83);
    if ( !v84 )
      goto LABEL_79;
    goto LABEL_131;
  }
LABEL_130:
  v181 = ipa3_get_ipc_logbuf_low(v83);
  v182 = ipc_log_string(
           v181,
           "ipa-wan %s:%d v6_hash_filter_tbl_start_addr %d\n",
           "ipa3_qmi_init_modem_send_sync_msg",
           766,
           HIDWORD(v251));
  v84 = ipa3_get_ipc_logbuf(v182);
  if ( !v84 )
  {
LABEL_79:
    v85 = ipa3_get_ipc_logbuf_low(v84);
    if ( !v85 )
      goto LABEL_81;
    goto LABEL_80;
  }
LABEL_131:
  v183 = ipa3_get_ipc_logbuf(v84);
  v184 = ipc_log_string(v183, "ipa-wan %s:%d ipa_smem_info.size %d\n", "ipa3_qmi_init_modem_send_sync_msg", 768, v259);
  v85 = ipa3_get_ipc_logbuf_low(v184);
  if ( v85 )
  {
LABEL_80:
    v87 = ipa3_get_ipc_logbuf_low(v85);
    ipc_log_string(v87, "ipa-wan %s:%d ipa_smem_info.size %d\n", "ipa3_qmi_init_modem_send_sync_msg", 768, v259);
  }
LABEL_81:
  HIDWORD(v231) = 197;
  LOWORD(v231) = 33;
  v232 = &ipa3_init_modem_driver_req_msg_data_v01_ei;
  HIDWORD(v229) = 25;
  LOWORD(v229) = 33;
  v230 = &ipa3_init_modem_driver_resp_msg_data_v01_ei;
  printk(&unk_3AA370, v86);
  if ( !ipa_q6_clnt )
  {
    if ( !*(_DWORD *)(ipa3_ctx + 45216) )
      goto LABEL_173;
LABEL_178:
    v215 = printk(&unk_3E9EB0, "ipa3_q6_clnt_svc_arrive");
    v216 = ipa3_get_ipc_logbuf(v215);
    if ( v216 )
    {
      v217 = ipa3_get_ipc_logbuf(v216);
      v216 = ipc_log_string(
               v217,
               "ipa-wan %s:%d ipa3_qmi_init_modem_send_sync_msg failed due to SSR!\n",
               "ipa3_q6_clnt_svc_arrive",
               2100);
    }
    v218 = ipa3_get_ipc_logbuf_low(v216);
    if ( v218 )
    {
      v219 = ipa3_get_ipc_logbuf_low(v218);
      ipc_log_string(
        v219,
        "ipa-wan %s:%d ipa3_qmi_init_modem_send_sync_msg failed due to SSR!\n",
        "ipa3_q6_clnt_svc_arrive",
        2100);
    }
    mutex_lock(&ipa3_qmi_lock);
    if ( ipa_q6_clnt )
    {
      qmi_handle_release(ipa_q6_clnt);
      vfree(ipa_q6_clnt);
      ipa_q6_clnt = 0;
    }
    mutex_unlock(&ipa3_qmi_lock);
    v220 = printk(&unk_3F59C2, "ipa3_q6_clnt_svc_arrive");
    v221 = ipa3_get_ipc_logbuf(v220);
    if ( v221 )
    {
      v222 = ipa3_get_ipc_logbuf(v221);
      v221 = ipc_log_string(v222, "ipa-wan %s:%d Exit from service arrive fun\n", "ipa3_q6_clnt_svc_arrive", 2109);
    }
    result = ipa3_get_ipc_logbuf_low(v221);
    if ( result )
    {
      v223 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(v223, "ipa-wan %s:%d Exit from service arrive fun\n", "ipa3_q6_clnt_svc_arrive", 2109);
    }
    goto LABEL_13;
  }
  v89 = ipa3_qmi_send_req_wait(
          ipa_q6_clnt,
          (unsigned __int16 *)&v231,
          (__int64)&v234,
          (__int64)&v229,
          (__int64)v233,
          0x2710u);
  if ( v89 < 0 )
  {
    v90 = printk(&unk_3CCE82, "ipa3_qmi_init_modem_send_sync_msg");
    v91 = ipa3_get_ipc_logbuf(v90);
    if ( v91 )
    {
      v92 = ipa3_get_ipc_logbuf(v91);
      v91 = ipc_log_string(
              v92,
              "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
              "ipa3_qmi_init_modem_send_sync_msg",
              789,
              33,
              v89);
    }
    v93 = ipa3_get_ipc_logbuf_low(v91);
    if ( v93 )
    {
      v94 = ipa3_get_ipc_logbuf_low(v93);
      v93 = ipc_log_string(
              v94,
              "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
              "ipa3_qmi_init_modem_send_sync_msg",
              789,
              33,
              v89);
    }
  }
  else
  {
    printk(&unk_3B2B1B, v88);
    v93 = ipa3_check_qmi_response(
            (unsigned int)v89,
            33,
            LOWORD(v233[0]),
            WORD1(v233[0]),
            "ipa_init_modem_driver_resp_msg_v01");
    v89 = v93;
  }
  if ( v89 > -20 )
  {
    if ( v89 == -19 || v89 == -5 )
      goto LABEL_178;
  }
  else if ( v89 == -104 || v89 == -102 )
  {
    goto LABEL_178;
  }
  if ( *(_DWORD *)(ipa3_ctx + 45216) )
    goto LABEL_178;
  if ( v89 )
  {
LABEL_173:
    v210 = printk(&unk_3F2AD7, "ipa3_q6_clnt_svc_arrive");
    v211 = ipa3_get_ipc_logbuf(v210);
    if ( v211 )
    {
      v212 = ipa3_get_ipc_logbuf(v211);
      v211 = ipc_log_string(
               v212,
               "ipa-wan %s:%d ipa3_qmi_init_modem_send_sync_msg failed\n",
               "ipa3_q6_clnt_svc_arrive",
               2114);
    }
    v213 = ipa3_get_ipc_logbuf_low(v211);
    if ( v213 )
    {
      v214 = ipa3_get_ipc_logbuf_low(v213);
      ipc_log_string(v214, "ipa-wan %s:%d ipa3_qmi_init_modem_send_sync_msg failed\n", "ipa3_q6_clnt_svc_arrive", 2114);
    }
    __break(0x800u);
    goto LABEL_178;
  }
  ipa3_qmi_modem_init_fin = 1;
  if ( *(_BYTE *)(ipa3_ctx + 43308) == 1 && ipa3_modem_init_cmplt == 1 )
  {
    v185 = ipa3_get_ipc_logbuf(v93);
    if ( v185 )
    {
      v186 = ipa3_get_ipc_logbuf(v185);
      v185 = ipc_log_string(
               v186,
               "ipa-wan %s:%d load uc related registers (%d)\n",
               "ipa3_q6_clnt_svc_arrive",
               2128,
               (unsigned __int8)ipa3_modem_init_cmplt);
    }
    v187 = ipa3_get_ipc_logbuf_low(v185);
    if ( v187 )
    {
      v188 = ipa3_get_ipc_logbuf_low(v187);
      v187 = ipc_log_string(
               v188,
               "ipa-wan %s:%d load uc related registers (%d)\n",
               "ipa3_q6_clnt_svc_arrive",
               2128,
               (unsigned __int8)ipa3_modem_init_cmplt);
    }
    ipa3_uc_load_notify(v187);
  }
  v189 = ipa3_q6_handshake_complete((unsigned __int8)first_time_handshake);
  first_time_handshake = 1;
  v190 = ipa3_get_ipc_logbuf(v189);
  if ( v190 )
  {
    v191 = ipa3_get_ipc_logbuf(v190);
    v190 = ipc_log_string(
             v191,
             "ipa-wan %s:%d complete, ipa3_qmi_modem_init_fin : %d\n",
             "ipa3_q6_clnt_svc_arrive",
             2136,
             (unsigned __int8)ipa3_qmi_modem_init_fin);
  }
  v192 = ipa3_get_ipc_logbuf_low(v190);
  if ( v192 )
  {
    v193 = ipa3_get_ipc_logbuf_low(v192);
    v192 = ipc_log_string(
             v193,
             "ipa-wan %s:%d complete, ipa3_qmi_modem_init_fin : %d\n",
             "ipa3_q6_clnt_svc_arrive",
             2136,
             (unsigned __int8)ipa3_qmi_modem_init_fin);
  }
  if ( ipa3_qmi_indication_fin != 1 )
  {
    v202 = printk(&unk_3E1632, "ipa3_q6_clnt_svc_arrive");
    v203 = ipa3_get_ipc_logbuf(v202);
    if ( v203 )
    {
      v204 = ipa3_get_ipc_logbuf(v203);
      v203 = ipc_log_string(
               v204,
               "ipa-wan %s:%d not send indication (%d)\n",
               "ipa3_q6_clnt_svc_arrive",
               2161,
               (unsigned __int8)ipa3_qmi_indication_fin);
    }
    result = ipa3_get_ipc_logbuf_low(v203);
    if ( result )
    {
      v205 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(
                 v205,
                 "ipa-wan %s:%d not send indication (%d)\n",
                 "ipa3_q6_clnt_svc_arrive",
                 2161,
                 (unsigned __int8)ipa3_qmi_indication_fin);
    }
    goto LABEL_163;
  }
  v194 = ipa3_get_ipc_logbuf(v192);
  if ( v194 )
  {
    v195 = ipa3_get_ipc_logbuf(v194);
    v194 = ipc_log_string(
             v195,
             "ipa-wan %s:%d send indication to modem (%d)\n",
             "ipa3_q6_clnt_svc_arrive",
             2140,
             (unsigned __int8)ipa3_qmi_indication_fin);
  }
  v196 = ipa3_get_ipc_logbuf_low(v194);
  if ( v196 )
  {
    v197 = ipa3_get_ipc_logbuf_low(v196);
    ipc_log_string(
      v197,
      "ipa-wan %s:%d send indication to modem (%d)\n",
      "ipa3_q6_clnt_svc_arrive",
      2140,
      (unsigned __int8)ipa3_qmi_indication_fin);
  }
  v228 = 0;
  if ( ipa3_svc_handle )
  {
    v198 = qmi_send_indication(
             ipa3_svc_handle,
             ipa3_qmi_ctx + 28864,
             34,
             7,
             &ipa3_master_driver_init_complt_ind_msg_data_v01_ei,
             &v228);
    v199 = ipa3_get_ipc_logbuf(v198);
    if ( v199 )
    {
      v200 = ipa3_get_ipc_logbuf(v199);
      v199 = ipc_log_string(v200, "ipa-wan %s:%d ipa_qmi_service_client good\n", "ipa3_q6_clnt_svc_arrive", 2158);
    }
    result = ipa3_get_ipc_logbuf_low(v199);
    if ( result )
    {
      v201 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(v201, "ipa-wan %s:%d ipa_qmi_service_client good\n", "ipa3_q6_clnt_svc_arrive", 2158);
    }
LABEL_163:
    send_qmi_init_q6 = 0;
    goto LABEL_13;
  }
  v224 = printk(&unk_3A728D, "ipa3_q6_clnt_svc_arrive");
  v225 = ipa3_get_ipc_logbuf(v224);
  if ( v225 )
  {
    v226 = ipa3_get_ipc_logbuf(v225);
    v225 = ipc_log_string(
             v226,
             "ipa-wan %s:%d Invalid svc handle.Ignore sending ind.\n",
             "ipa3_q6_clnt_svc_arrive",
             2147);
  }
  result = ipa3_get_ipc_logbuf_low(v225);
  if ( result )
  {
    v227 = ipa3_get_ipc_logbuf_low(result);
    result = ipc_log_string(
               v227,
               "ipa-wan %s:%d Invalid svc handle.Ignore sending ind.\n",
               "ipa3_q6_clnt_svc_arrive",
               2147);
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
