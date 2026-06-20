__int64 __fastcall ipa3_connect_mhi_pipe(_BYTE *a1, signed int *a2)
{
  __int64 ipc_logbuf; // x0
  __int64 v5; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x0
  __int64 v8; // x9
  unsigned int v9; // w21
  unsigned int ep_mapping; // w0
  signed int v11; // w22
  __int64 v12; // x19
  _DWORD *v13; // x19
  int v14; // t1
  void *v15; // x0
  char v16; // w8
  __int64 v17; // x28
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x24
  __int64 *v23; // x20
  __int64 v24; // x0
  __int64 v25; // x25
  __int64 v26; // x28
  __int64 v27; // x8
  __int64 v28; // x9
  int v29; // w9
  __int64 v30; // x10
  __int64 v31; // x8
  __int64 v32; // x9
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  unsigned int v41; // w0
  bool v42; // cf
  __int64 *v43; // x9
  int v44; // w20
  __int64 v45; // x8
  __int64 v46; // x9
  __int64 v47; // x9
  _BOOL4 v48; // w26
  int v49; // w8
  unsigned int v50; // w9
  __int64 v51; // x10
  unsigned int v52; // w9
  char v53; // w9
  unsigned int v54; // w0
  unsigned int v55; // w8
  unsigned __int64 v56; // x24
  __int64 v57; // x10
  int v58; // w11
  int v59; // w12
  int v60; // w12
  __int64 v61; // x11
  unsigned __int64 v62; // x10
  unsigned int v63; // w11
  unsigned int v64; // w11
  unsigned __int64 v65; // x25
  __int64 v66; // x9
  __int64 v67; // x10
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
  unsigned int v78; // w0
  unsigned __int64 *v79; // x8
  __int64 v80; // x0
  unsigned int v81; // w25
  __int64 v82; // x0
  __int64 v83; // x0
  __int64 v84; // x0
  __int64 v85; // x0
  __int64 v86; // x0
  __int64 v87; // x0
  __int64 v88; // x0
  __int64 v89; // x0
  __int64 v90; // x0
  __int64 v91; // x0
  __int64 v92; // x0
  __int64 v93; // x0
  __int64 v94; // x0
  unsigned int v95; // w8
  __int64 v96; // x0
  __int64 v97; // x0
  __int64 v98; // x0
  __int64 v99; // x0
  __int64 v100; // x0
  __int64 v101; // x0
  __int64 v102; // x0
  __int64 v103; // x0
  __int64 started; // x0
  unsigned int v105; // w8
  __int64 v106; // x0
  int v107; // w23
  __int64 v108; // x0
  __int64 v109; // x0
  __int64 v110; // x0
  unsigned __int64 v111; // x26
  signed int v112; // w11
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
  __int64 result; // x0
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
  signed int *v169; // x20
  __int64 v170; // x0
  __int64 v171; // x8
  __int64 v172; // x0
  __int64 v173; // x0
  __int64 v174; // x8
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
  int v189; // w23
  __int64 v190; // x0
  __int64 v191; // x0
  __int64 v192; // x0
  __int64 v193; // x0
  __int64 v194; // [xsp+8h] [xbp-138h]
  signed int *v195; // [xsp+10h] [xbp-130h]
  _BYTE v196[24]; // [xsp+18h] [xbp-128h] BYREF
  unsigned int v197; // [xsp+30h] [xbp-110h] BYREF
  __int16 v198; // [xsp+34h] [xbp-10Ch] BYREF
  __int64 v199; // [xsp+38h] [xbp-108h] BYREF
  __int64 v200; // [xsp+40h] [xbp-100h]
  __int64 v201; // [xsp+48h] [xbp-F8h]
  __int64 v202; // [xsp+50h] [xbp-F0h]
  __int64 v203; // [xsp+58h] [xbp-E8h]
  __int64 v204; // [xsp+60h] [xbp-E0h]
  __int64 v205; // [xsp+68h] [xbp-D8h]
  __int64 v206; // [xsp+70h] [xbp-D0h]
  __int64 v207; // [xsp+78h] [xbp-C8h]
  __int64 v208; // [xsp+80h] [xbp-C0h]
  __int64 v209; // [xsp+88h] [xbp-B8h]
  __int64 v210; // [xsp+90h] [xbp-B0h]
  __int64 v211; // [xsp+98h] [xbp-A8h]
  __int64 v212; // [xsp+A0h] [xbp-A0h]
  __int64 v213; // [xsp+A8h] [xbp-98h]
  __int64 v214; // [xsp+B0h] [xbp-90h] BYREF
  __int64 v215; // [xsp+B8h] [xbp-88h]
  __int64 v216; // [xsp+C0h] [xbp-80h]
  __int64 v217; // [xsp+C8h] [xbp-78h]
  __int64 v218; // [xsp+D0h] [xbp-70h]
  __int64 v219; // [xsp+D8h] [xbp-68h]
  __int64 v220; // [xsp+E0h] [xbp-60h]
  __int64 v221; // [xsp+E8h] [xbp-58h]
  __int64 v222; // [xsp+F0h] [xbp-50h]
  __int64 v223; // [xsp+F8h] [xbp-48h]
  __int64 v224; // [xsp+100h] [xbp-40h]
  __int64 v225; // [xsp+108h] [xbp-38h]
  __int64 v226; // [xsp+110h] [xbp-30h]
  __int64 v227; // [xsp+118h] [xbp-28h]
  __int64 v228; // [xsp+120h] [xbp-20h]
  __int64 v229; // [xsp+128h] [xbp-18h]
  __int64 v230; // [xsp+130h] [xbp-10h]

  v230 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v5 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(v5, "ipa_mhi %s:%d ENTRY\n", "ipa3_connect_mhi_pipe", 546);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v7 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v7, "ipa_mhi %s:%d ENTRY\n", "ipa3_connect_mhi_pipe", 546);
  }
  if ( !a1 || !a2 )
  {
    v113 = printk(&unk_3EF3A7, "ipa3_connect_mhi_pipe");
    v114 = ipa3_get_ipc_logbuf(v113);
    if ( v114 )
    {
      v115 = ipa3_get_ipc_logbuf(v114);
      v114 = ipc_log_string(v115, "ipa_mhi %s:%d NULL args\n", "ipa3_connect_mhi_pipe", 549);
    }
    v116 = ipa3_get_ipc_logbuf_low(v114);
    if ( v116 )
    {
      v117 = ipa3_get_ipc_logbuf_low(v116);
      ipc_log_string(v117, "ipa_mhi %s:%d NULL args\n", "ipa3_connect_mhi_pipe", 549);
LABEL_142:
      result = 4294967274LL;
      goto LABEL_208;
    }
LABEL_156:
    result = 4294967274LL;
    goto LABEL_208;
  }
  v8 = *(_QWORD *)a1;
  a1[120] += *(_BYTE *)(ipa3_ctx + 43744);
  v9 = *(_DWORD *)(v8 + 192);
  ep_mapping = ipa_get_ep_mapping(v9);
  if ( ep_mapping == -1 )
  {
    v118 = printk(&unk_3B8322, "ipa3_connect_mhi_pipe");
    v119 = ipa3_get_ipc_logbuf(v118);
    if ( v119 )
    {
      v120 = ipa3_get_ipc_logbuf(v119);
      v119 = ipc_log_string(v120, "ipa_mhi %s:%d Invalid client.\n", "ipa3_connect_mhi_pipe", 558);
    }
    v121 = ipa3_get_ipc_logbuf_low(v119);
    if ( v121 )
    {
      v122 = ipa3_get_ipc_logbuf_low(v121);
      ipc_log_string(v122, "ipa_mhi %s:%d Invalid client.\n", "ipa3_connect_mhi_pipe", 558);
      goto LABEL_142;
    }
    goto LABEL_156;
  }
  v11 = ep_mapping;
  if ( ep_mapping > 0x24 )
    goto LABEL_219;
  v12 = ipa3_ctx + 480LL * (int)ep_mapping;
  v14 = *(_DWORD *)(v12 + 168);
  v13 = (_DWORD *)(v12 + 168);
  if ( v14 == 1 )
  {
    v124 = printk(&unk_3CFDB8, "ipa3_connect_mhi_pipe");
    v125 = ipa3_get_ipc_logbuf(v124);
    if ( v125 )
    {
      v126 = ipa3_get_ipc_logbuf(v125);
      v125 = ipc_log_string(v126, "ipa_mhi %s:%d EP already allocated.\n", "ipa3_connect_mhi_pipe", 565);
    }
    v127 = ipa3_get_ipc_logbuf_low(v125);
    if ( v127 )
    {
      v128 = ipa3_get_ipc_logbuf_low(v127);
      ipc_log_string(v128, "ipa_mhi %s:%d EP already allocated.\n", "ipa3_connect_mhi_pipe", 565);
      result = 0xFFFFFFFFLL;
      goto LABEL_208;
    }
LABEL_214:
    result = 0xFFFFFFFFLL;
    goto LABEL_208;
  }
  v15 = memset(v13, 0, 0x1D8u);
  *v13 = 1;
  v16 = *(_BYTE *)(*(_QWORD *)a1 + 216LL);
  v13[1] = v9;
  *((_BYTE *)v13 + 404) = v16;
  *((_QWORD *)v13 + 47) = *(_QWORD *)(*(_QWORD *)a1 + 208LL);
  *((_QWORD *)v13 + 46) = *(_QWORD *)(*(_QWORD *)a1 + 200LL);
  *((_BYTE *)v13 + 405) = *(_BYTE *)(*(_QWORD *)a1 + 217LL);
  v17 = *(_QWORD *)a1;
  v228 = 0;
  v229 = 0;
  v226 = 0;
  v227 = 0;
  v224 = 0;
  v225 = 0;
  v222 = 0;
  v223 = 0;
  v220 = 0;
  v221 = 0;
  v218 = 0;
  v219 = 0;
  v216 = 0;
  v217 = 0;
  v214 = 0;
  v215 = 0;
  v212 = 0;
  v213 = 0;
  v210 = 0;
  v211 = 0;
  v208 = 0;
  v209 = 0;
  v206 = 0;
  v207 = 0;
  v204 = 0;
  v205 = 0;
  v202 = 0;
  v203 = 0;
  v200 = 0;
  v201 = 0;
  v199 = 0;
  v198 = 0;
  v197 = 0;
  v18 = ipa3_get_ipc_logbuf(v15);
  if ( v18 )
  {
    v19 = ipa3_get_ipc_logbuf(v18);
    v18 = ipc_log_string(v19, "ipa_mhi %s:%d ENTRY\n", "ipa_mhi_start_gsi_channel", 210);
  }
  v20 = ipa3_get_ipc_logbuf_low(v18);
  if ( v20 )
  {
    v21 = ipa3_get_ipc_logbuf_low(v20);
    ipc_log_string(v21, "ipa_mhi %s:%d ENTRY\n", "ipa_mhi_start_gsi_channel", 210);
  }
  v22 = ipa3_ctx;
  v23 = *((__int64 **)a1 + 4);
  v24 = ((__int64 (__fastcall *)(_QWORD))ipa_get_gsi_ep_info)(v9);
  if ( !v24 )
  {
    v129 = printk(&unk_3E3CD2, "ipa_mhi_start_gsi_channel");
    v130 = ipa3_get_ipc_logbuf(v129);
    if ( v130 )
    {
      v131 = ipa3_get_ipc_logbuf(v130);
      v130 = ipc_log_string(v131, "ipa_mhi %s:%d Wrong parameter, ep_cfg is NULL\n", "ipa_mhi_start_gsi_channel", 217);
    }
    v132 = ipa3_get_ipc_logbuf_low(v130);
    if ( v132 )
    {
      v133 = ipa3_get_ipc_logbuf_low(v132);
      ipc_log_string(v133, "ipa_mhi %s:%d Wrong parameter, ep_cfg is NULL\n", "ipa_mhi_start_gsi_channel", 217);
    }
    v81 = -1;
    goto LABEL_209;
  }
  v25 = v24;
  v194 = v17;
  v195 = a2;
  v26 = v22 + 480LL * v11 + 168;
  if ( *((_DWORD *)a1 + 6) == 255 )
  {
    v27 = *((_QWORD *)a1 + 5);
    v228 = 0;
    v229 = 0;
    v226 = 0;
    v227 = 0;
    v224 = 0;
    v225 = 0;
    v222 = 0;
    v223 = 0;
    v220 = 0;
    v221 = 0;
    v218 = 0;
    v219 = 0;
    v216 = 0;
    v217 = 0;
    v28 = *(_QWORD *)(v27 + 20);
    v214 = 0;
    LODWORD(v215) = 16;
    HIDWORD(v215) = v28;
    v29 = (unsigned __int8)a1[96];
    v30 = *(_QWORD *)(v27 + 12);
    if ( a1[96] )
      v30 |= 0x10000000000uLL;
    v216 = v30;
    LOWORD(v218) = (*(_DWORD *)v27 >> 11) & 0xFFE0;
    BYTE2(v218) = *(_DWORD *)v27;
    HIDWORD(v218) = *(_DWORD *)(v27 + 8) & *((_DWORD *)v23 + 3) | v23[1] & ~*((_DWORD *)v23 + 3);
    v31 = *v23;
    if ( v29 )
    {
      v31 |= 0x10000000000uLL;
      v32 = (*((_QWORD *)a1 + 6) + 28LL) | 0x10000000000LL;
    }
    else
    {
      v32 = *((_QWORD *)a1 + 6) + 28LL;
    }
    v223 = v32;
    v66 = *((_QWORD *)a1 + 10);
    v67 = *((_QWORD *)a1 + 11);
    v220 = v31;
    LOBYTE(v225) = 1;
    v226 = v66;
    v227 = v67;
    LOBYTE(v66) = a1[120];
    LOBYTE(v228) = 1;
    BYTE1(v228) = v66;
    v68 = ipa3_get_ipc_logbuf(v24);
    if ( v68 )
    {
      v69 = ipa3_get_ipc_logbuf(v68);
      v68 = ipc_log_string(
              v69,
              "ipa_mhi %s:%d allocating event ring ep:%u evchid:%u\n",
              "ipa_mhi_start_gsi_channel",
              246,
              v11,
              BYTE1(v228));
    }
    v70 = ipa3_get_ipc_logbuf_low(v68);
    if ( v70 )
    {
      v71 = ipa3_get_ipc_logbuf_low(v70);
      ipc_log_string(
        v71,
        "ipa_mhi %s:%d allocating event ring ep:%u evchid:%u\n",
        "ipa_mhi_start_gsi_channel",
        246,
        v11,
        BYTE1(v228));
    }
    v72 = gsi_alloc_evt_ring(&v214, *(_QWORD *)(ipa3_ctx + 43296), v22 + 480LL * v11 + 184);
    if ( !(_DWORD)v72 )
    {
      v73 = ipa3_get_ipc_logbuf(v72);
      if ( v73 )
      {
        v74 = ipa3_get_ipc_logbuf(v73);
        v73 = ipc_log_string(
                v74,
                "ipa_mhi %s:%d client %d, caching event ring hdl %lu\n",
                "ipa_mhi_start_gsi_channel",
                255,
                v9,
                *(_QWORD *)(v22 + 480LL * v11 + 184));
      }
      v75 = ipa3_get_ipc_logbuf_low(v73);
      if ( v75 )
      {
        v76 = ipa3_get_ipc_logbuf_low(v75);
        v75 = ipc_log_string(
                v76,
                "ipa_mhi %s:%d client %d, caching event ring hdl %lu\n",
                "ipa_mhi_start_gsi_channel",
                255,
                v9,
                *(_QWORD *)(v22 + 480LL * v11 + 184));
      }
      **((_QWORD **)a1 + 14) = *(_QWORD *)(v22 + 480LL * v11 + 184);
      v37 = ipa3_get_ipc_logbuf(v75);
      if ( !v37 )
        goto LABEL_26;
LABEL_25:
      v38 = ipa3_get_ipc_logbuf(v37);
      v37 = ipc_log_string(
              v38,
              "ipa_mhi %s:%d Ring event db: evt_ring_hdl=%lu host_wp=0x%llx\n",
              "ipa_mhi_start_gsi_channel",
              273,
              *(_QWORD *)(v22 + 480LL * v11 + 184),
              *(_QWORD *)(*((_QWORD *)a1 + 5) + 36LL));
      goto LABEL_26;
    }
    v81 = v72;
    v159 = printk(&unk_3C70C7, "ipa_mhi_start_gsi_channel");
    v160 = ipa3_get_ipc_logbuf(v159);
    if ( v160 )
    {
      v161 = ipa3_get_ipc_logbuf(v160);
      v160 = ipc_log_string(v161, "ipa_mhi %s:%d gsi_alloc_evt_ring failed %d\n", "ipa_mhi_start_gsi_channel", 250, v81);
    }
    v162 = ipa3_get_ipc_logbuf_low(v160);
    if ( v162 )
    {
      v163 = ipa3_get_ipc_logbuf_low(v162);
      ipc_log_string(v163, "ipa_mhi %s:%d gsi_alloc_evt_ring failed %d\n", "ipa_mhi_start_gsi_channel", 250, v81);
    }
LABEL_209:
    v184 = printk(&unk_3BB3EE, "ipa3_connect_mhi_pipe");
    v185 = ipa3_get_ipc_logbuf(v184);
    if ( v185 )
    {
      v186 = ipa3_get_ipc_logbuf(v185);
      v185 = ipc_log_string(
               v186,
               "ipa_mhi %s:%d ipa_mhi_start_gsi_channel failed %d\n",
               "ipa3_connect_mhi_pipe",
               582,
               v81);
    }
    v187 = ipa3_get_ipc_logbuf_low(v185);
    if ( v187 )
    {
      v188 = ipa3_get_ipc_logbuf_low(v187);
      ipc_log_string(v188, "ipa_mhi %s:%d ipa_mhi_start_gsi_channel failed %d\n", "ipa3_connect_mhi_pipe", 582, v81);
    }
    memset(v13, 0, 0x1D8u);
    goto LABEL_214;
  }
  v33 = ipa3_get_ipc_logbuf(v24);
  if ( v33 )
  {
    v34 = ipa3_get_ipc_logbuf(v33);
    v33 = ipc_log_string(
            v34,
            "ipa_mhi %s:%d event ring already exists: evt_ring_hdl=%lu\n",
            "ipa_mhi_start_gsi_channel",
            261,
            **((_QWORD **)a1 + 14));
  }
  v35 = ipa3_get_ipc_logbuf_low(v33);
  if ( v35 )
  {
    v36 = ipa3_get_ipc_logbuf_low(v35);
    v35 = ipc_log_string(
            v36,
            "ipa_mhi %s:%d event ring already exists: evt_ring_hdl=%lu\n",
            "ipa_mhi_start_gsi_channel",
            261,
            **((_QWORD **)a1 + 14));
  }
  *(_QWORD *)(v22 + 480LL * v11 + 184) = **((_QWORD **)a1 + 14);
  v37 = ipa3_get_ipc_logbuf(v35);
  if ( v37 )
    goto LABEL_25;
LABEL_26:
  v39 = ipa3_get_ipc_logbuf_low(v37);
  if ( v39 )
  {
    v40 = ipa3_get_ipc_logbuf_low(v39);
    ipc_log_string(
      v40,
      "ipa_mhi %s:%d Ring event db: evt_ring_hdl=%lu host_wp=0x%llx\n",
      "ipa_mhi_start_gsi_channel",
      273,
      *(_QWORD *)(v22 + 480LL * v11 + 184),
      *(_QWORD *)(*((_QWORD *)a1 + 5) + 36LL));
  }
  v41 = gsi_ring_evt_ring_db(*(_QWORD *)(v22 + 480LL * v11 + 184), *(_QWORD *)(*((_QWORD *)a1 + 5) + 36LL));
  if ( v41 )
  {
    v81 = v41;
    v134 = printk(&unk_3F841F, "ipa_mhi_start_gsi_channel");
    v135 = ipa3_get_ipc_logbuf(v134);
    if ( v135 )
    {
      v136 = ipa3_get_ipc_logbuf(v135);
      v135 = ipc_log_string(
               v136,
               "ipa_mhi %s:%d fail to ring evt ring db %d. hdl=%lu wp=0x%llx\n",
               "ipa_mhi_start_gsi_channel",
               278,
               v81,
               *(_QWORD *)(v22 + 480LL * v11 + 184),
               *(_QWORD *)(*((_QWORD *)a1 + 5) + 36LL));
    }
    v137 = ipa3_get_ipc_logbuf_low(v135);
    if ( v137 )
    {
      v138 = ipa3_get_ipc_logbuf_low(v137);
      ipc_log_string(
        v138,
        "ipa_mhi %s:%d fail to ring evt ring db %d. hdl=%lu wp=0x%llx\n",
        "ipa_mhi_start_gsi_channel",
        278,
        v81,
        *(_QWORD *)(v22 + 480LL * v11 + 184),
        *(_QWORD *)(*((_QWORD *)a1 + 5) + 36LL));
    }
LABEL_198:
    v168 = gsi_dealloc_evt_ring(*(_QWORD *)(v26 + 16));
    v169 = v195;
    *(_QWORD *)(v26 + 16) = -1;
    if ( !v81 )
      goto LABEL_199;
    goto LABEL_209;
  }
  v212 = 0;
  v213 = 0;
  v42 = (v9 & 1) != 0 || v9 >= 0x86;
  v210 = 0;
  v211 = 0;
  v43 = *((__int64 **)a1 + 14);
  v44 = !v42;
  v208 = 0;
  v209 = 0;
  v206 = 0;
  v207 = 0;
  v204 = 0;
  v205 = 0;
  v202 = 0;
  v203 = 0;
  v200 = 0;
  v201 = 0;
  LODWORD(v199) = 0;
  HIDWORD(v199) = v44;
  LOBYTE(v200) = *(_DWORD *)(v25 + 4);
  v45 = *((_QWORD *)a1 + 7);
  v46 = *v43;
  LODWORD(v202) = 16;
  v201 = v46;
  HIDWORD(v202) = *(_QWORD *)(v45 + 20);
  if ( a1[96] )
    v47 = *(_QWORD *)(v45 + 12) | 0x10000000000LL;
  else
    v47 = *(_QWORD *)(v45 + 12);
  v204 = v47;
  if ( v9 == 81 )
  {
    v48 = 0;
  }
  else
  {
    v49 = *(_BYTE *)(v45 + 1) & 3;
    v48 = v49 == 3 || v49 == 0;
  }
  v50 = *(_DWORD *)(ipa3_ctx + 32240);
  LOWORD(v205) = 1;
  LOBYTE(v208) = 1;
  v51 = *((_QWORD *)a1 + 9);
  v52 = v50 < 0xE || v48;
  v207 = v52;
  HIDWORD(v208) = *(_DWORD *)(v25 + 20);
  v53 = *(_BYTE *)(v25 + 24);
  v211 = v51;
  LOBYTE(v209) = v53;
  v213 = *((_QWORD *)a1 + 11);
  v54 = gsi_alloc_channel(&v199, *(_QWORD *)(ipa3_ctx + 43296), v22 + 480LL * v11 + 176);
  if ( v54 )
  {
    v81 = v54;
    v139 = printk(&unk_3D8872, "ipa_mhi_start_gsi_channel");
    v140 = ipa3_get_ipc_logbuf(v139);
    if ( v140 )
    {
      v141 = ipa3_get_ipc_logbuf(v140);
      v140 = ipc_log_string(v141, "ipa_mhi %s:%d gsi_alloc_channel failed %d\n", "ipa_mhi_start_gsi_channel", 318, v81);
    }
    v142 = ipa3_get_ipc_logbuf_low(v140);
    if ( v142 )
    {
      v143 = ipa3_get_ipc_logbuf_low(v142);
      ipc_log_string(v143, "ipa_mhi %s:%d gsi_alloc_channel failed %d\n", "ipa_mhi_start_gsi_channel", 318, v81);
    }
    goto LABEL_198;
  }
  v55 = *(_DWORD *)(ipa3_ctx + 32240);
  if ( a1[96] )
    v56 = (*((_QWORD *)a1 + 8) + 36LL) | 0x10000000000LL;
  else
    v56 = *((_QWORD *)a1 + 8) + 36LL;
  v57 = 2LL * (unsigned __int8)a1[96];
  if ( v55 <= 0xD )
  {
    v58 = *(_DWORD *)(v25 + 8);
    if ( v58 >= 0 )
      v59 = *(_DWORD *)(v25 + 8);
    else
      v59 = v58 + 1;
    v60 = v59 >> 1;
    v61 = (unsigned int)((v58 * (_DWORD)v202) << 16);
    if ( v60 >= 8 )
      v60 = 8;
    v57 |= v61 | ((unsigned __int64)(unsigned int)(v60 * v202) << 48);
  }
  if ( v48 )
  {
    v62 = v57 & 0xFFFFFFFFFFFFC003LL;
    v63 = *(unsigned __int8 *)(*((_QWORD *)a1 + 7) + 1LL);
    if ( v63 > 3 )
    {
      v64 = v63 >> 2;
    }
    else if ( (v44 & 1) != 0 )
    {
      LOBYTE(v64) = 7;
    }
    else
    {
      v112 = HIDWORD(v202) / (unsigned int)v202;
      if ( v55 < 0x15 )
        v64 = v112 / 16;
      else
        v64 = v112 / 2;
    }
    v65 = v62 | 0x880 | (4 * (v64 & 0x1F));
    if ( v55 < 0x11 )
      goto LABEL_78;
  }
  else
  {
    v65 = v57 & 0xFFFFFFFFFFFFC17FLL | 0x800;
    if ( v55 < 0x11 )
      goto LABEL_78;
  }
  if ( *(_DWORD *)(ipa3_ctx + 32256) )
  {
LABEL_78:
    v77 = *(_QWORD *)(v26 + 8);
    *(_QWORD *)v196 = v56;
    *(_QWORD *)&v196[8] = v65;
    *(_QWORD *)&v196[16] = 0;
    goto LABEL_79;
  }
  v111 = HIDWORD(v56) & 0x1FF;
  if ( v9 == 43 && v55 >= 0x15 )
    gsi_update_almst_empty_thrshold(*(_QWORD *)(v26 + 8), ((unsigned int)v65 >> 2) & 0x1F);
  else
    v111 = HIDWORD(v56) & 0x1FF | ((((unsigned __int64)(unsigned int)v65 >> 2) & 0x1F) << 9);
  v77 = *(_QWORD *)(v26 + 8);
  *(_DWORD *)v196 = v56;
  *(_QWORD *)&v196[12] = 0;
  *(_DWORD *)&v196[20] = 0;
  *(_QWORD *)&v196[4] = v111 | (v65 << 32) & 0x3F8200000000LL;
LABEL_79:
  v78 = gsi_write_channel_scratch(v77, v196);
  if ( v78 )
  {
    v81 = v78;
    v144 = printk(&unk_3CFE0E, "ipa_mhi_start_gsi_channel");
    v145 = ipa3_get_ipc_logbuf(v144);
    if ( v145 )
    {
      v146 = ipa3_get_ipc_logbuf(v145);
      v145 = ipc_log_string(
               v146,
               "ipa_mhi %s:%d gsi_write_channel_scratch failed %d\n",
               "ipa_mhi_start_gsi_channel",
               379,
               v81);
    }
    v147 = ipa3_get_ipc_logbuf_low(v145);
    if ( v147 )
    {
      v148 = ipa3_get_ipc_logbuf_low(v147);
      ipc_log_string(v148, "ipa_mhi %s:%d gsi_write_channel_scratch failed %d\n", "ipa_mhi_start_gsi_channel", 379, v81);
    }
    goto LABEL_197;
  }
  v79 = *((unsigned __int64 **)a1 + 13);
  *v79 = v56;
  v79[1] = v65;
  v80 = ipa3_enable_data_path(v11);
  if ( (_DWORD)v80 )
  {
    v81 = v80;
    v149 = printk(&unk_3F24C5, "ipa_mhi_start_gsi_channel");
    v150 = ipa3_get_ipc_logbuf(v149);
    if ( v150 )
    {
      v151 = ipa3_get_ipc_logbuf(v150);
      v150 = ipc_log_string(
               v151,
               "ipa_mhi %s:%d enable data path failed res=%d clnt=%d.\n",
               "ipa_mhi_start_gsi_channel",
               388,
               v81,
               v11);
    }
    v152 = ipa3_get_ipc_logbuf_low(v150);
    if ( v152 )
    {
      v153 = ipa3_get_ipc_logbuf_low(v152);
      ipc_log_string(
        v153,
        "ipa_mhi %s:%d enable data path failed res=%d clnt=%d.\n",
        "ipa_mhi_start_gsi_channel",
        388,
        v81,
        v11);
    }
    goto LABEL_196;
  }
  v81 = 0;
  if ( (*(_BYTE *)(v26 + 404) & 1) != 0 )
  {
    v82 = ipa3_get_ipc_logbuf(v80);
    if ( v82 )
    {
      v83 = ipa3_get_ipc_logbuf(v82);
      v82 = ipc_log_string(v83, "ipa_mhi %s:%d skipping ep configuration\n", "ipa_mhi_start_gsi_channel", 403);
    }
    v84 = ipa3_get_ipc_logbuf_low(v82);
    if ( v84 )
    {
      v85 = ipa3_get_ipc_logbuf_low(v84);
      v84 = ipc_log_string(v85, "ipa_mhi %s:%d skipping ep configuration\n", "ipa_mhi_start_gsi_channel", 403);
    }
    if ( v11 == 36 )
LABEL_219:
      __break(0x5512u);
    if ( *(_DWORD *)(ipa3_ctx + 480LL * v11 + 172) == 42 )
    {
      v84 = ipa3_cfg_ep_seq((unsigned int)v11, v194 + 168);
      if ( (_DWORD)v84 )
      {
        v86 = printk(&unk_3AFCEF, "ipa_mhi_start_gsi_channel");
        v87 = ipa3_get_ipc_logbuf(v86);
        if ( v87 )
        {
          v88 = ipa3_get_ipc_logbuf(v87);
          v87 = ipc_log_string(v88, "ipa_mhi %s:%d fail to configure USB pipe seq\n", "ipa_mhi_start_gsi_channel", 409);
        }
        v89 = ipa3_get_ipc_logbuf_low(v87);
        if ( v89 )
        {
          v90 = ipa3_get_ipc_logbuf_low(v89);
          ipc_log_string(v90, "ipa_mhi %s:%d fail to configure USB pipe seq\n", "ipa_mhi_start_gsi_channel", 409);
        }
LABEL_196:
        ipa3_disable_data_path(v11);
LABEL_197:
        gsi_dealloc_channel(*(_QWORD *)(v26 + 8));
        goto LABEL_198;
      }
    }
  }
  else
  {
    if ( (unsigned int)ipa3_cfg_ep((unsigned int)v11, v194) )
    {
      printk(&unk_3D5322, "ipa_mhi_start_gsi_channel");
      v171 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v172 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v172 )
        {
          ipc_log_string(v172, "ipa %s:%d fail to configure EP.\n", "ipa_mhi_start_gsi_channel", 394);
          v171 = ipa3_ctx;
        }
        v173 = *(_QWORD *)(v171 + 34160);
        if ( v173 )
          ipc_log_string(v173, "ipa %s:%d fail to configure EP.\n", "ipa_mhi_start_gsi_channel", 394);
      }
      goto LABEL_196;
    }
    v91 = ipa3_cfg_ep_status((unsigned int)v11, v26 + 352);
    if ( (_DWORD)v91 )
    {
      printk(&unk_3A6426, "ipa_mhi_start_gsi_channel");
      v174 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v175 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v175 )
        {
          ipc_log_string(v175, "ipa %s:%d fail to configure status of EP.\n", "ipa_mhi_start_gsi_channel", 398);
          v174 = ipa3_ctx;
        }
        v176 = *(_QWORD *)(v174 + 34160);
        if ( v176 )
          ipc_log_string(v176, "ipa %s:%d fail to configure status of EP.\n", "ipa_mhi_start_gsi_channel", 398);
      }
      goto LABEL_196;
    }
    v92 = ipa3_get_ipc_logbuf(v91);
    if ( v92 )
    {
      v93 = ipa3_get_ipc_logbuf(v92);
      v92 = ipc_log_string(v93, "ipa_mhi %s:%d ep configuration successful\n", "ipa_mhi_start_gsi_channel", 401);
    }
    v84 = ipa3_get_ipc_logbuf_low(v92);
    if ( v84 )
    {
      v94 = ipa3_get_ipc_logbuf_low(v84);
      v84 = ipc_log_string(v94, "ipa_mhi %s:%d ep configuration successful\n", "ipa_mhi_start_gsi_channel", 401);
    }
  }
  v95 = *(_DWORD *)(v26 + 4);
  if ( v95 > 0x85 || (v95 & 1) != 0 || *(_BYTE *)(v26 + 404) != 1 )
  {
    *(_BYTE *)(v26 + 468) = 0;
  }
  else
  {
    v198 = 256;
    *(_BYTE *)(v26 + 468) = 1;
    v96 = ipa_cfg_ep_ctrl((unsigned int)v11, &v198);
    if ( (_DWORD)v96 )
    {
      v189 = v96;
      v190 = printk(&unk_3E683C, "ipa_mhi_start_gsi_channel");
      v191 = ipa3_get_ipc_logbuf(v190);
      if ( v191 )
      {
        v192 = ipa3_get_ipc_logbuf(v191);
        v191 = ipc_log_string(
                 v192,
                 "ipa_mhi %s:%d client (ep: %d) failed result=%d\n",
                 "ipa_mhi_start_gsi_channel",
                 423,
                 v11,
                 v189);
      }
      v84 = ipa3_get_ipc_logbuf_low(v191);
      if ( v84 )
      {
        v193 = ipa3_get_ipc_logbuf_low(v84);
        v84 = ipc_log_string(
                v193,
                "ipa_mhi %s:%d client (ep: %d) failed result=%d\n",
                "ipa_mhi_start_gsi_channel",
                423,
                v11,
                v189);
      }
    }
    else
    {
      v97 = ipa3_get_ipc_logbuf(v96);
      if ( v97 )
      {
        v98 = ipa3_get_ipc_logbuf(v97);
        v97 = ipc_log_string(v98, "ipa_mhi %s:%d client (ep: %d) success\n", "ipa_mhi_start_gsi_channel", 425, v11);
      }
      v84 = ipa3_get_ipc_logbuf_low(v97);
      if ( v84 )
      {
        v99 = ipa3_get_ipc_logbuf_low(v84);
        v84 = ipc_log_string(v99, "ipa_mhi %s:%d client (ep: %d) success\n", "ipa_mhi_start_gsi_channel", 425, v11);
      }
    }
  }
  if ( v44 && (*(_BYTE *)(v26 + 404) & 1) == 0 )
    v84 = ipa3_install_dflt_flt_rules(v11);
  v100 = ipa3_get_ipc_logbuf(v84);
  if ( v100 )
  {
    v101 = ipa3_get_ipc_logbuf(v100);
    v100 = ipc_log_string(v101, "ipa_mhi %s:%d Starting channel\n", "ipa_mhi_start_gsi_channel", 433);
  }
  v102 = ipa3_get_ipc_logbuf_low(v100);
  if ( v102 )
  {
    v103 = ipa3_get_ipc_logbuf_low(v102);
    ipc_log_string(v103, "ipa_mhi %s:%d Starting channel\n", "ipa_mhi_start_gsi_channel", 433);
  }
  started = gsi_start_channel(*(_QWORD *)(v26 + 8));
  if ( (_DWORD)started )
  {
    v81 = started;
    v154 = printk(&unk_3D88F8, "ipa_mhi_start_gsi_channel");
    v155 = ipa3_get_ipc_logbuf(v154);
    if ( v155 )
    {
      v156 = ipa3_get_ipc_logbuf(v155);
      v155 = ipc_log_string(v156, "ipa_mhi %s:%d gsi_start_channel failed %d\n", "ipa_mhi_start_gsi_channel", 436, v81);
    }
    v157 = ipa3_get_ipc_logbuf_low(v155);
    if ( v157 )
    {
      v158 = ipa3_get_ipc_logbuf_low(v157);
      ipc_log_string(v158, "ipa_mhi %s:%d gsi_start_channel failed %d\n", "ipa_mhi_start_gsi_channel", 436, v81);
    }
    goto LABEL_197;
  }
  v105 = *(_DWORD *)(v26 + 4);
  if ( v105 <= 0x85 && (v105 & 1) == 0 && *(_BYTE *)(v26 + 404) == 1 && *(_BYTE *)(ipa3_ctx + 32268) == 1 )
  {
    if ( v105 != 110 || (started = ipa3_is_modem_up(), (started & 1) == 0) )
    {
      v106 = gsi_enable_flow_control_ee(*(unsigned int *)(v26 + 8), 0, &v197);
      v107 = v106;
      v108 = ipa3_get_ipc_logbuf(v106);
      if ( v107 )
      {
        if ( v108 )
        {
          v109 = ipa3_get_ipc_logbuf(v108);
          v108 = ipc_log_string(
                   v109,
                   "ipa_mhi %s:%d failed to flow ctrll gsi ch %lu code %d\n",
                   "ipa_mhi_start_gsi_channel",
                   451,
                   *(_QWORD *)(v26 + 8),
                   v197);
        }
        started = ipa3_get_ipc_logbuf_low(v108);
        if ( started )
        {
          v110 = ipa3_get_ipc_logbuf_low(started);
          started = ipc_log_string(
                      v110,
                      "ipa_mhi %s:%d failed to flow ctrll gsi ch %lu code %d\n",
                      "ipa_mhi_start_gsi_channel",
                      451,
                      *(_QWORD *)(v26 + 8),
                      v197);
        }
      }
      else
      {
        if ( v108 )
        {
          v164 = ipa3_get_ipc_logbuf(v108);
          v108 = ipc_log_string(
                   v164,
                   "ipa_mhi %s:%d flow ctrl sussess gsi ch %lu code %d\n",
                   "ipa_mhi_start_gsi_channel",
                   448,
                   *(_QWORD *)(v26 + 8),
                   v197);
        }
        started = ipa3_get_ipc_logbuf_low(v108);
        if ( started )
        {
          v165 = ipa3_get_ipc_logbuf_low(started);
          started = ipc_log_string(
                      v165,
                      "ipa_mhi %s:%d flow ctrl sussess gsi ch %lu code %d\n",
                      "ipa_mhi_start_gsi_channel",
                      448,
                      *(_QWORD *)(v26 + 8),
                      v197);
        }
      }
    }
  }
  v166 = ipa3_get_ipc_logbuf(started);
  if ( v166 )
  {
    v167 = ipa3_get_ipc_logbuf(v166);
    v166 = ipc_log_string(v167, "ipa_mhi %s:%d EXIT\n", "ipa_mhi_start_gsi_channel", 455);
  }
  v168 = ipa3_get_ipc_logbuf_low(v166);
  v169 = v195;
  if ( v168 )
  {
    v170 = ipa3_get_ipc_logbuf_low(v168);
    v168 = ipc_log_string(v170, "ipa_mhi %s:%d EXIT\n", "ipa_mhi_start_gsi_channel", 455);
  }
LABEL_199:
  *v169 = v11;
  if ( v11 == 36 )
    goto LABEL_219;
  *(_BYTE *)(ipa3_ctx + v11 + 17448) = *((_BYTE *)v13 + 404);
  v177 = ipa3_get_ipc_logbuf(v168);
  if ( v177 )
  {
    v178 = ipa3_get_ipc_logbuf(v177);
    v177 = ipc_log_string(v178, "ipa_mhi %s:%d client %d (ep: %d) connected\n", "ipa3_connect_mhi_pipe", 588, v9, v11);
  }
  v179 = ipa3_get_ipc_logbuf_low(v177);
  if ( v179 )
  {
    v180 = ipa3_get_ipc_logbuf_low(v179);
    v179 = ipc_log_string(v180, "ipa_mhi %s:%d client %d (ep: %d) connected\n", "ipa3_connect_mhi_pipe", 588, v9, v11);
  }
  v181 = ipa3_get_ipc_logbuf(v179);
  if ( v181 )
  {
    v182 = ipa3_get_ipc_logbuf(v181);
    v181 = ipc_log_string(v182, "ipa_mhi %s:%d EXIT\n", "ipa3_connect_mhi_pipe", 590);
  }
  result = ipa3_get_ipc_logbuf_low(v181);
  if ( result )
  {
    v183 = ipa3_get_ipc_logbuf_low(result);
    ipc_log_string(v183, "ipa_mhi %s:%d EXIT\n", "ipa3_connect_mhi_pipe", 590);
    result = 0;
  }
LABEL_208:
  _ReadStatusReg(SP_EL0);
  return result;
}
