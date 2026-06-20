__int64 __fastcall send_set_roam_trigger_cmd_tlv(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x4
  int v13; // w21
  unsigned int v14; // w19
  unsigned int v15; // w9
  __int64 v16; // x8
  unsigned int v17; // w5
  unsigned int v18; // w7
  unsigned int v19; // w8
  int v20; // w10
  unsigned int v21; // w11
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 i; // x26
  unsigned int v39; // w5
  _DWORD *v40; // x8
  int v41; // w8
  int v42; // w4
  unsigned int v43; // w8
  unsigned int v44; // w8
  unsigned int v45; // w5
  int v46; // w4
  _DWORD *v47; // x8
  unsigned int v48; // w8
  unsigned int v49; // w5
  int v50; // w4
  _DWORD *v51; // x8
  unsigned int v52; // w8
  unsigned int v53; // w5
  int v54; // w4
  _DWORD *v55; // x8
  __int64 v56; // x8
  int v57; // w23
  char *v58; // x9
  int v60; // w10
  int v61; // w8
  int v62; // w19
  int v63; // w24
  __int64 v64; // x0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  _DWORD *v73; // x25
  __int64 v74; // x22
  __int64 v75; // x19
  char *v76; // x21
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned int v85; // w19
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v95; // [xsp+0h] [xbp-360h]
  __int64 v96; // [xsp+28h] [xbp-338h]
  __int64 v97; // [xsp+30h] [xbp-330h] BYREF
  _QWORD v98[5]; // [xsp+38h] [xbp-328h] BYREF
  __int64 v99; // [xsp+60h] [xbp-300h]
  __int64 v100; // [xsp+68h] [xbp-2F8h]
  __int64 v101; // [xsp+70h] [xbp-2F0h]
  __int64 v102; // [xsp+78h] [xbp-2E8h]
  __int64 v103; // [xsp+80h] [xbp-2E0h]
  __int64 v104; // [xsp+88h] [xbp-2D8h]
  __int64 v105; // [xsp+90h] [xbp-2D0h]
  __int64 v106; // [xsp+98h] [xbp-2C8h]
  __int64 v107; // [xsp+A0h] [xbp-2C0h]
  __int64 v108; // [xsp+A8h] [xbp-2B8h]
  __int64 v109; // [xsp+B0h] [xbp-2B0h]
  __int64 v110; // [xsp+B8h] [xbp-2A8h]
  __int64 v111; // [xsp+C0h] [xbp-2A0h]
  __int64 v112; // [xsp+C8h] [xbp-298h]
  __int64 v113; // [xsp+D0h] [xbp-290h]
  __int64 v114; // [xsp+D8h] [xbp-288h]
  __int64 v115; // [xsp+E0h] [xbp-280h]
  __int64 v116; // [xsp+E8h] [xbp-278h]
  __int64 v117; // [xsp+F0h] [xbp-270h]
  __int64 v118; // [xsp+F8h] [xbp-268h]
  __int64 v119; // [xsp+100h] [xbp-260h]
  __int64 v120; // [xsp+108h] [xbp-258h]
  __int64 v121; // [xsp+110h] [xbp-250h]
  __int64 v122; // [xsp+118h] [xbp-248h]
  __int64 v123; // [xsp+120h] [xbp-240h]
  __int64 v124; // [xsp+128h] [xbp-238h]
  __int64 v125; // [xsp+130h] [xbp-230h]
  __int64 v126; // [xsp+138h] [xbp-228h]
  __int64 v127; // [xsp+140h] [xbp-220h]
  __int64 v128; // [xsp+148h] [xbp-218h]
  __int64 v129; // [xsp+150h] [xbp-210h]
  __int64 v130; // [xsp+158h] [xbp-208h]
  __int64 v131; // [xsp+160h] [xbp-200h]
  __int64 v132; // [xsp+168h] [xbp-1F8h]
  __int64 v133; // [xsp+170h] [xbp-1F0h]
  __int64 v134; // [xsp+178h] [xbp-1E8h]
  __int64 v135; // [xsp+180h] [xbp-1E0h]
  __int64 v136; // [xsp+188h] [xbp-1D8h]
  __int64 v137; // [xsp+190h] [xbp-1D0h]
  __int64 v138; // [xsp+198h] [xbp-1C8h]
  __int64 v139; // [xsp+1A0h] [xbp-1C0h]
  __int64 v140; // [xsp+1A8h] [xbp-1B8h]
  __int64 v141; // [xsp+1B0h] [xbp-1B0h]
  __int64 v142; // [xsp+1B8h] [xbp-1A8h]
  __int64 v143; // [xsp+1C0h] [xbp-1A0h]
  __int64 v144; // [xsp+1C8h] [xbp-198h]
  __int64 v145; // [xsp+1D0h] [xbp-190h]
  __int64 v146; // [xsp+1D8h] [xbp-188h]
  __int64 v147; // [xsp+1E0h] [xbp-180h]
  __int64 v148; // [xsp+1E8h] [xbp-178h]
  __int64 v149; // [xsp+1F0h] [xbp-170h]
  __int64 v150; // [xsp+1F8h] [xbp-168h]
  __int64 v151; // [xsp+200h] [xbp-160h]
  __int64 v152; // [xsp+208h] [xbp-158h]
  __int64 v153; // [xsp+210h] [xbp-150h]
  __int64 v154; // [xsp+218h] [xbp-148h]
  __int64 v155; // [xsp+220h] [xbp-140h]
  __int64 v156; // [xsp+228h] [xbp-138h]
  __int64 v157; // [xsp+230h] [xbp-130h]
  __int64 v158; // [xsp+238h] [xbp-128h]
  __int64 v159; // [xsp+240h] [xbp-120h]
  __int64 v160; // [xsp+248h] [xbp-118h]
  __int64 v161; // [xsp+250h] [xbp-110h]
  __int64 v162; // [xsp+258h] [xbp-108h]
  __int64 v163; // [xsp+260h] [xbp-100h]
  __int64 v164; // [xsp+268h] [xbp-F8h]
  __int64 v165; // [xsp+270h] [xbp-F0h]
  __int64 v166; // [xsp+278h] [xbp-E8h]
  __int64 v167; // [xsp+280h] [xbp-E0h]
  __int64 v168; // [xsp+288h] [xbp-D8h]
  __int64 v169; // [xsp+290h] [xbp-D0h]
  __int64 v170; // [xsp+298h] [xbp-C8h]
  __int64 v171; // [xsp+2A0h] [xbp-C0h]
  __int64 v172; // [xsp+2A8h] [xbp-B8h]
  __int64 v173; // [xsp+2B0h] [xbp-B0h]
  __int64 v174; // [xsp+2B8h] [xbp-A8h]
  __int64 v175; // [xsp+2C0h] [xbp-A0h]
  __int64 v176; // [xsp+2C8h] [xbp-98h]
  __int64 v177; // [xsp+2D0h] [xbp-90h]
  int v178; // [xsp+2D8h] [xbp-88h]
  int v179; // [xsp+2DCh] [xbp-84h]
  int v180; // [xsp+2E0h] [xbp-80h]
  unsigned __int64 v181; // [xsp+2E4h] [xbp-7Ch]
  unsigned __int64 v182; // [xsp+2ECh] [xbp-74h]
  unsigned __int64 v183; // [xsp+2F4h] [xbp-6Ch]
  int v184; // [xsp+2FCh] [xbp-64h]
  __int64 v185; // [xsp+300h] [xbp-60h]
  _QWORD v186[11]; // [xsp+308h] [xbp-58h] BYREF

  v186[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v98[4] = 0x1039A0024LL;
  v13 = a2[3];
  v14 = a2[1];
  memset(&v186[5], 0, 32);
  v103 = 0x2039A0024LL;
  v104 = 0;
  v107 = -1;
  v108 = 0x3039A0024LL;
  v184 = 0;
  memset(v186, 0, 32);
  v182 = 0;
  v183 = 0;
  v113 = 0x4039A0024LL;
  v114 = 0;
  v181 = 0;
  v117 = -1;
  v118 = 0x5039A0024LL;
  v97 = 60424228;
  v98[0] = 0;
  v178 = 60424228;
  v123 = 0x6039A0024LL;
  v124 = 0;
  memset(&v98[1], 255, 24);
  v185 = 0x12039A0024LL;
  v127 = -1;
  v128 = 0x7039A0024LL;
  v101 = -1;
  v102 = -1;
  v186[4] = 0x13039A0024LL;
  v15 = a2[9];
  v133 = 0x8039A0024LL;
  v134 = 0;
  v99 = 0;
  v100 = -1;
  v105 = -1;
  v106 = -1;
  v137 = -1;
  v138 = 0x9039A0024LL;
  v111 = -1;
  v112 = -1;
  v109 = 0;
  v110 = -1;
  v143 = 0xA039A0024LL;
  v144 = 0;
  v115 = -1;
  v116 = -1;
  v121 = -1;
  v122 = -1;
  v147 = -1;
  v148 = 0xB039A0024LL;
  v119 = 0;
  v120 = -1;
  v125 = -1;
  v126 = -1;
  v153 = 0xC039A0024LL;
  v131 = -1;
  v132 = -1;
  v129 = 0;
  v130 = -1;
  v158 = 0xD039A0024LL;
  v135 = -1;
  v136 = -1;
  v141 = -1;
  v142 = -1;
  v163 = 0xE039A0024LL;
  v139 = 0;
  v140 = -1;
  v145 = -1;
  v146 = -1;
  v168 = 0xF039A0024LL;
  v152 = -1;
  v150 = -1;
  v151 = -1;
  v157 = -1;
  v156 = -1;
  v155 = -1;
  v162 = -1;
  v161 = -1;
  v160 = -1;
  v167 = -1;
  v166 = -1;
  v165 = -1;
  v172 = -1;
  v171 = -1;
  v170 = -1;
  v177 = -1;
  v176 = -1;
  v175 = -1;
  memset(&v186[1], 255, 24);
  memset(&v186[6], 255, 24);
  v149 = 0;
  v154 = 0;
  v159 = 0;
  v164 = 0;
  v169 = 0;
  v173 = 0x10039A0024LL;
  v174 = 0;
  v180 = 0;
  v186[0] = 0;
  v186[5] = 0;
  v179 = 17;
  if ( !v15 )
  {
    v12 = 1;
    v180 = 1;
  }
  v16 = (unsigned int)a2[4];
  if ( (unsigned int)v16 > 2 )
    v17 = 0;
  else
    v17 = dword_A2E9DC[v16];
  v18 = a2[6];
  v19 = a2[7];
  v20 = a2[8];
  v21 = a2[2];
  v181 = __PAIR64__(a2[5], v17);
  v182 = __PAIR64__(v21, v18);
  v184 = v20;
  v183 = __PAIR64__(v19, v15);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: WTC_BTM: enable:%d scan_mode:%d rssi_thres:%d cand_min_rssi_thres:%d cand_ap_min_rssi_thres: 2.4 Ghz[%d] 5 Ghz[%"
    "d], 6 Ghz[%d] reason_code:%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "send_set_roam_trigger_cmd_tlv",
    v12,
    v19,
    v20,
    v21,
    v15);
  if ( (wmi_service_enabled(a1, 0xD3u, v22, v23, v24, v25, v26, v27, v28, v29) & 1) != 0 )
  {
    v96 = a1;
    if ( a2[16] != -1 )
      LODWORD(v98[0]) = 0;
    for ( i = 0; i != 38; i += 2 )
    {
      v42 = a2[i + 18];
      if ( v42 != -1 )
      {
        v43 = a2[i + 19] - 1;
        if ( v43 <= 0x13 )
          v39 = dword_A2E9E8[v43];
        else
          v39 = 0;
        v40 = &v98[5 * v39 - 1];
        v40[6] = v42;
        v40[1] = v39;
        v40[2] = 1;
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: RSO_CFG: Score delta per: %d converted trig_reason: %d",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "wmi_fill_score_delta_params");
        if ( i == 26 )
          v41 = (v14 >> 14) & 1;
        else
          v41 = 0;
        LODWORD(v98[0]) = v41;
      }
    }
    a1 = v96;
    if ( (v14 & 0x2000) != 0 )
    {
      v44 = a2[11] - 1;
      if ( v44 > 0x13 )
        v45 = 0;
      else
        v45 = dword_A2E9E8[v44];
      v46 = a2[10];
      v47 = &v98[5 * v45 - 1];
      v47[5] = v46;
      v47[8] = v46;
      v47[9] = v46;
      v47[2] = 1;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: RSO_CFG: Min rssi thresh: %d converted trig_reason: %d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "wmi_fill_min_rssi_params");
      if ( (v14 & 4) == 0 )
      {
LABEL_21:
        if ( (v14 & 0x10) == 0 )
          goto LABEL_35;
LABEL_31:
        v52 = a2[15] - 1;
        if ( v52 > 0x13 )
          v53 = 0;
        else
          v53 = dword_A2E9E8[v52];
        v54 = a2[14];
        v55 = &v98[5 * v53 - 1];
        v55[5] = v54;
        v55[8] = v54;
        v55[9] = v54;
        v55[2] = 1;
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: RSO_CFG: Min rssi thresh: %d converted trig_reason: %d",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "wmi_fill_min_rssi_params");
        goto LABEL_35;
      }
    }
    else if ( (v14 & 4) == 0 )
    {
      goto LABEL_21;
    }
    v48 = a2[13] - 1;
    if ( v48 > 0x13 )
      v49 = 0;
    else
      v49 = dword_A2E9E8[v48];
    v50 = a2[12];
    v51 = &v98[5 * v49 - 1];
    v51[5] = v50;
    v51[8] = v50;
    v51[9] = v50;
    v51[2] = 1;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: RSO_CFG: Min rssi thresh: %d converted trig_reason: %d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wmi_fill_min_rssi_params");
    if ( (v14 & 0x10) == 0 )
      goto LABEL_35;
    goto LABEL_31;
  }
LABEL_35:
  v56 = 0;
  v57 = v14 & 0xFFFFF;
  LODWORD(v186[0]) = v14 & 0x40000;
  v58 = (char *)v98 + 4;
  do
  {
    if ( ((1 << v56) & v13) != 0 && ((1 << v56) & v57) != 0 )
      *(_QWORD *)(v58 - 4) = 0x100000001LL;
    ++v56;
    v58 += 40;
  }
  while ( v56 != 20 );
  v60 = v99 != 0;
  if ( LODWORD(v98[0]) )
    ++v60;
  if ( (_DWORD)v104 )
    ++v60;
  if ( (_DWORD)v109 )
    ++v60;
  if ( (_DWORD)v114 )
    ++v60;
  if ( (_DWORD)v119 )
    ++v60;
  if ( (_DWORD)v124 )
    ++v60;
  if ( (_DWORD)v129 )
    ++v60;
  if ( (_DWORD)v134 )
    ++v60;
  if ( (_DWORD)v139 )
    ++v60;
  if ( (_DWORD)v144 )
    ++v60;
  if ( (_DWORD)v149 )
    ++v60;
  if ( (_DWORD)v154 )
    ++v60;
  if ( (_DWORD)v159 )
    ++v60;
  if ( (_DWORD)v164 )
    ++v60;
  if ( (_DWORD)v169 )
    ++v60;
  if ( (_DWORD)v174 )
    ++v60;
  if ( v180 )
    ++v60;
  if ( LODWORD(v186[0]) )
    v61 = v60 + 1;
  else
    v61 = v60;
  if ( LODWORD(v186[5]) )
    v62 = v61 + 1;
  else
    v62 = v61;
  v63 = 40 * v62;
  v64 = wmi_buf_alloc_fl(a1, 40 * v62 + 16, "send_set_roam_trigger_cmd_tlv", 0x6CAu);
  if ( v64 )
  {
    v73 = *(_DWORD **)(v64 + 224);
    v74 = v64;
    *v73 = 53673992;
    v73[1] = *a2;
    v73[2] = v57 | 0x200;
    LODWORD(v95) = v62;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: RSO_CFG: vdev:%d input_trigger_bmap:0x%x final_trigger_bmap: 0x%x roam_scan_scheme:0x%x num_triggers:%d",
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      "send_set_roam_trigger_cmd_tlv",
      v95);
    v75 = 0;
    v76 = (char *)(v73 + 4);
    v73[3] = v63 & 0xFFF8 | 0x120000;
    do
    {
      if ( LODWORD(v98[v75]) )
      {
        qdf_mem_copy(v76, &v98[v75 - 1], 0x28u);
        v76 += 40;
      }
      v75 += 5;
    }
    while ( v75 != 100 );
    wmi_mtrace(0xB017u, *a2, 0);
    v85 = wmi_unified_cmd_send_fl(
            a1,
            v74,
            v63 + 16,
            0xB017u,
            "send_set_roam_trigger_cmd_tlv",
            0x6F2u,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84);
    if ( v85 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send set roam triggers command ret = %d",
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        "send_set_roam_trigger_cmd_tlv",
        v85);
      wmi_buf_free();
    }
  }
  else
  {
    v85 = 2;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to allocate wmi buffer",
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      "send_set_roam_trigger_cmd_tlv");
  }
  _ReadStatusReg(SP_EL0);
  return v85;
}
