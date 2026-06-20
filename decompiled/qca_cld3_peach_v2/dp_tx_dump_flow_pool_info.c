__int64 __fastcall dp_tx_dump_flow_pool_info(__int64 a1)
{
  unsigned __int16 *v2; // x20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v28; // x20
  unsigned __int64 v29; // x21
  __int64 v30; // x22
  __int64 v31; // x9
  __int64 v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  double v161; // d0
  double v162; // d1
  double v163; // d2
  double v164; // d3
  double v165; // d4
  double v166; // d5
  double v167; // d6
  double v168; // d7
  __int64 v169; // x8
  __int64 result; // x0
  _QWORD s[39]; // [xsp+8h] [xbp-138h] BYREF

  v2 = (unsigned __int16 *)(a1 + 12288);
  s[37] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x128u);
  qdf_trace_msg(0x45u, 2u, "No of pool map received %d", v3, v4, v5, v6, v7, v8, v9, v10, v2[320]);
  qdf_trace_msg(0x45u, 2u, "No of pool unmap received %d", v11, v12, v13, v14, v15, v16, v17, v18, v2[321]);
  qdf_trace_msg(
    0x45u,
    2u,
    "Pkt dropped due to unavailablity of pool %d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v2[322]);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 12904);
  }
  else
  {
    raw_spin_lock_bh(a1 + 12904);
    *(_QWORD *)(a1 + 12912) |= 1uLL;
  }
  v28 = 0;
  v29 = _ReadStatusReg(SP_EL0);
  do
  {
    v30 = a1 + v28;
    if ( *(_DWORD *)(a1 + v28 + 2368) > 5u )
      goto LABEL_7;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v29 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v29 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v30 + 2560);
    }
    else
    {
      raw_spin_lock_bh(v30 + 2560);
      *(_QWORD *)(a1 + v28 + 2568) |= 1uLL;
    }
    qdf_mem_copy(s, (const void *)(v30 + 2304), 0x128u);
    v31 = *(_QWORD *)(a1 + v28 + 2568);
    if ( (v31 & 1) != 0 )
    {
      *(_QWORD *)(a1 + v28 + 2568) = v31 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v30 + 2560);
      v32 = *(_QWORD *)(a1 + 12912);
      if ( (v32 & 1) != 0 )
      {
LABEL_21:
        *(_QWORD *)(a1 + 12912) = v32 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 12904);
        goto LABEL_16;
      }
    }
    else
    {
      raw_spin_unlock(v30 + 2560);
      v32 = *(_QWORD *)(a1 + 12912);
      if ( (v32 & 1) != 0 )
        goto LABEL_21;
    }
    raw_spin_unlock(a1 + 12904);
LABEL_16:
    qdf_trace_msg(0x45u, 2u, "\n", v33, v34, v35, v36, v37, v38, v39, v40);
    qdf_trace_msg(
      0x45u,
      2u,
      "Flow_pool_id %d :: status %d",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      BYTE2(s[7]),
      LODWORD(s[8]));
    qdf_trace_msg(
      0x45u,
      2u,
      "Total %d :: Available %d",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      LOWORD(s[7]),
      WORD2(s[7]));
    qdf_trace_msg(
      0x45u,
      2u,
      "Level %d :: Start threshold %d :: Stop threshold %d",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      0,
      LOWORD(s[10]),
      LOWORD(s[9]));
    qdf_trace_msg(0x45u, 2u, "Level %d :: Maximum pause time %lu ms", v65, v66, v67, v68, v69, v70, v71, v72, 0, s[11]);
    qdf_trace_msg(0x45u, 2u, "Level %d :: Latest pause timestamp %lu", v73, v74, v75, v76, v77, v78, v79, v80, 0, s[15]);
    qdf_trace_msg(
      0x45u,
      2u,
      "Level %d :: Start threshold %d :: Stop threshold %d",
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      1,
      WORD1(s[10]),
      WORD1(s[9]));
    qdf_trace_msg(0x45u, 2u, "Level %d :: Maximum pause time %lu ms", v89, v90, v91, v92, v93, v94, v95, v96, 1, s[12]);
    qdf_trace_msg(
      0x45u,
      2u,
      "Level %d :: Latest pause timestamp %lu",
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      1,
      s[16]);
    qdf_trace_msg(
      0x45u,
      2u,
      "Level %d :: Start threshold %d :: Stop threshold %d",
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      2,
      WORD2(s[10]),
      WORD2(s[9]));
    qdf_trace_msg(
      0x45u,
      2u,
      "Level %d :: Maximum pause time %lu ms",
      v113,
      v114,
      v115,
      v116,
      v117,
      v118,
      v119,
      v120,
      2,
      s[13]);
    qdf_trace_msg(
      0x45u,
      2u,
      "Level %d :: Latest pause timestamp %lu",
      v121,
      v122,
      v123,
      v124,
      v125,
      v126,
      v127,
      v128,
      2,
      s[17]);
    qdf_trace_msg(
      0x45u,
      2u,
      "Level %d :: Start threshold %d :: Stop threshold %d",
      v129,
      v130,
      v131,
      v132,
      v133,
      v134,
      v135,
      v136,
      3,
      HIWORD(s[10]),
      HIWORD(s[9]));
    qdf_trace_msg(
      0x45u,
      2u,
      "Level %d :: Maximum pause time %lu ms",
      v137,
      v138,
      v139,
      v140,
      v141,
      v142,
      v143,
      v144,
      3,
      s[14]);
    qdf_trace_msg(
      0x45u,
      2u,
      "Level %d :: Latest pause timestamp %lu",
      v145,
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      v152,
      3,
      s[18]);
    qdf_trace_msg(
      0x45u,
      2u,
      "Member flow_id  %d :: flow_type %d",
      v153,
      v154,
      v155,
      v156,
      v157,
      v158,
      v159,
      v160,
      BYTE2(s[7]),
      HIDWORD(s[8]));
    qdf_trace_msg(
      0x45u,
      2u,
      "Pkt dropped due to unavailablity of descriptors %d",
      v161,
      v162,
      v163,
      v164,
      v165,
      v166,
      v167,
      v168,
      WORD1(s[31]));
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v29 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v29 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 12904);
    }
    else
    {
      raw_spin_lock_bh(a1 + 12904);
      *(_QWORD *)(a1 + 12912) |= 1uLL;
    }
LABEL_7:
    v28 += 296;
  }
  while ( v28 != 1776 );
  v169 = *(_QWORD *)(a1 + 12912);
  if ( (v169 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 12912) = v169 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 12904);
  }
  else
  {
    result = raw_spin_unlock(a1 + 12904);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
