__int64 __fastcall wma_beacon_swba_handler(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x23
  unsigned int v22; // w20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned __int8 v31; // w22
  __int64 result; // x0
  _QWORD *v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x8
  unsigned int (__fastcall *v43)(_QWORD); // x8
  __int64 v44; // x8
  _DWORD *v45; // x25
  __int64 v46; // x24
  __int64 v47; // x20
  const char *v48; // x2
  unsigned __int64 StatusReg; // x8
  unsigned __int16 *v50; // x23
  _BYTE *v51; // x21
  char v52; // w8
  char v53; // w8
  char v54; // w8
  __int16 v55; // w8
  unsigned int v56; // w8
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
  int v73; // w6
  unsigned int v74; // w7
  unsigned int v75; // w9
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  int v84; // w8
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  int v93; // w8
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  int v102; // w8
  __int64 v103; // x0
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  int v112; // w9
  __int64 v113; // x9
  __int64 v114; // x8
  int v115; // w8
  __int64 v116; // x8
  __int64 v117; // x0
  __int64 v118; // [xsp+0h] [xbp-70h]
  __int64 v119; // [xsp+0h] [xbp-70h]
  __int64 v120; // [xsp+0h] [xbp-70h]
  __int64 v121; // [xsp+8h] [xbp-68h] BYREF
  __int64 v122; // [xsp+10h] [xbp-60h]
  __int64 v123; // [xsp+18h] [xbp-58h]
  __int64 v124; // [xsp+20h] [xbp-50h]
  _QWORD v125[4]; // [xsp+28h] [xbp-48h] BYREF
  __int64 v126; // [xsp+48h] [xbp-28h]
  _BYTE v127[24]; // [xsp+50h] [xbp-20h] BYREF
  __int64 v128; // [xsp+68h] [xbp-8h]

  v128 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"wma_beacon_swba_handler", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !a2 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid swba event buffer",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_beacon_swba_handler");
    result = 4294967274LL;
LABEL_28:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v21 = context;
  v22 = *(_DWORD *)(*a2 + 4LL);
  qdf_trace_msg(0x36u, 8u, "%s: vdev_map = %d", v13, v14, v15, v16, v17, v18, v19, v20, "wma_beacon_swba_handler", v22);
  if ( !v22 || !*(_WORD *)(a1 + 162) )
  {
LABEL_27:
    result = 0;
    goto LABEL_28;
  }
  v31 = 0;
  while ( (v22 & 1) == 0 )
  {
    ++v31;
    v22 >>= 1;
    if ( *(unsigned __int16 *)(a1 + 162) <= (unsigned int)v31 )
      goto LABEL_27;
  }
  v33 = _cds_get_context(65, (__int64)"wma_beacon_swba_handler", v23, v24, v25, v26, v27, v28, v29, v30);
  if ( v21 && *v21 )
  {
    v42 = *(_QWORD *)(*v21 + 104LL);
    if ( v42 )
    {
      v43 = *(unsigned int (__fastcall **)(_QWORD))(v42 + 48);
      if ( v43 )
      {
        if ( *((_DWORD *)v43 - 1) != -298467953 )
          __break(0x8228u);
        if ( v43(v33) )
          goto LABEL_27;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: invalid instance", v34, v35, v36, v37, v38, v39, v40, v41, "cdp_cfg_is_high_latency");
  }
  v44 = *(_QWORD *)(a1 + 520) + 488LL * v31;
  v45 = (_DWORD *)a2[2];
  memset(v127, 0, 17);
  v46 = a2[4];
  v126 = 0;
  v124 = 0;
  memset(v125, 0, sizeof(v125));
  v122 = 0;
  v123 = 0;
  v121 = 0;
  v47 = *(_QWORD *)(v44 + 8);
  if ( !v47 || !*(_QWORD *)v47 )
  {
    v48 = "%s: Invalid beacon buffer";
LABEL_26:
    qdf_trace_msg(0x36u, 2u, v48, v34, v35, v36, v37, v38, v39, v40, v41, "wma_send_bcn_buf_ll");
    goto LABEL_27;
  }
  if ( !v45 || !v46 )
  {
    v48 = "%s: Invalid tim info or p2p noa info";
    goto LABEL_26;
  }
  if ( HIBYTE(*(_DWORD *)(v46 + 4)) >= 5u )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Too many descriptors %d",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "wma_send_bcn_buf_ll");
    goto LABEL_27;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v47 + 104);
  }
  else
  {
    raw_spin_lock_bh(v47 + 104);
    *(_QWORD *)(v47 + 112) |= 1uLL;
  }
  v50 = *(unsigned __int16 **)(*(_QWORD *)v47 + 224LL);
  v51 = (char *)v50 + *(unsigned int *)(v47 + 16);
  if ( v45[7] )
  {
    if ( v45[8] )
      qdf_mem_copy(v51 + 5, v45 + 3, 5u);
    else
      qdf_mem_set(v51 + 5, 5u, 0);
    v51[4] = 0;
  }
  v52 = v51[2];
  if ( !v52 )
    v52 = v51[3];
  v53 = v52 - 1;
  v51[2] = v53;
  *(_BYTE *)(v47 + 20) = v53;
  if ( v45[2] && (!v51[2] || v51[3] == 1) )
    v54 = v51[4] | 1;
  else
    v54 = v51[4] & 0xFE;
  v51[4] = v54;
  v55 = *(_WORD *)(v47 + 22);
  if ( (v55 & 0xF00) == 0 )
  {
    v55 = 256;
    *(_WORD *)(v47 + 22) = 256;
  }
  v50[11] = 16 * v55;
  ++*(_WORD *)(v47 + 22);
  if ( (*(_BYTE *)(v46 + 4) & 1) == 0 )
  {
LABEL_54:
    if ( *(_BYTE *)(v47 + 12) )
    {
      _qdf_nbuf_unmap_single(*(_QWORD *)(a1 + 184), *(_QWORD *)v47, 1);
      *(_BYTE *)(v47 + 12) = 0;
    }
    if ( (unsigned int)_qdf_nbuf_map_single(*(_QWORD *)(a1 + 184), *(_QWORD *)v47, 1u) )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: failed map beacon buf to DMA region",
        v104,
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        "wma_send_bcn_buf_ll");
    }
    else
    {
      v112 = *(_DWORD *)(v47 + 8);
      *(_BYTE *)(v47 + 12) = 1;
      HIDWORD(v121) = v31;
      LODWORD(v122) = v112;
      LODWORD(v123) = *v50;
      v113 = 40;
      if ( (*(_BYTE *)(*(_QWORD *)v47 + 68LL) & 4) != 0 )
        v113 = 80;
      v114 = *(_QWORD *)(*(_QWORD *)v47 + v113);
      HIDWORD(v123) = 0;
      HIDWORD(v122) = v114;
      if ( !v51[2] )
      {
        if ( (v51[4] & 1) != 0 )
          v115 = 3;
        else
          v115 = 1;
        HIDWORD(v123) = v115;
      }
      wmi_unified_bcn_buf_ll_cmd(*(_QWORD *)a1, &v121);
    }
    v116 = *(_QWORD *)(v47 + 112);
    if ( (v116 & 1) != 0 )
    {
      *(_QWORD *)(v47 + 112) = v116 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v47 + 104);
    }
    else
    {
      raw_spin_unlock(v47 + 104);
    }
    goto LABEL_27;
  }
  qdf_mem_set(v125, 0x39u, 0);
  v56 = *(_DWORD *)(v46 + 4);
  BYTE2(v125[0]) = BYTE1(v56);
  BYTE3(v125[0]) = BYTE2(v56);
  BYTE4(v125[0]) = HIBYTE(v56);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: index %u, oppPs %u, ctwindow %u, num_descriptors = %u",
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    "wma_send_bcn_buf_ll",
    BYTE1(v56),
    HIWORD(v56) & 1,
    (v56 >> 17) & 0x7F);
  if ( !BYTE4(v125[0]) )
    goto LABEL_53;
  v73 = *(_DWORD *)(v46 + 16);
  v74 = *(_DWORD *)(v46 + 20);
  v75 = *(_DWORD *)(v46 + 24);
  BYTE5(v125[0]) = *(_DWORD *)(v46 + 12);
  *(_DWORD *)((char *)v125 + 6) = v73;
  *(_QWORD *)((char *)&v125[1] + 2) = __PAIR64__(v75, v74);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: NoA descriptor[%d] type_count %u, duration %u, interval %u, start_time = %u",
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    "wma_send_bcn_buf_ll",
    0,
    BYTE5(v125[0]),
    v75,
    v121,
    v122,
    v123,
    v124,
    v125[0],
    v125[1],
    v125[2],
    v125[3],
    v126,
    *(_QWORD *)v127,
    *(_QWORD *)&v127[8],
    *(_QWORD *)&v127[16],
    v128);
  if ( BYTE4(v125[0]) < 2u )
    goto LABEL_53;
  v84 = *(_DWORD *)(v46 + 32);
  BYTE2(v125[2]) = v84;
  *(_DWORD *)((char *)&v125[2] + 3) = *(_DWORD *)(v46 + 36);
  *(_QWORD *)((char *)&v125[2] + 7) = *(_QWORD *)(v46 + 40);
  LODWORD(v118) = *(_DWORD *)((char *)&v125[3] + 3);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: NoA descriptor[%d] type_count %u, duration %u, interval %u, start_time = %u",
    v76,
    v77,
    v78,
    v79,
    v80,
    v81,
    v82,
    v83,
    "wma_send_bcn_buf_ll",
    1,
    (unsigned __int8)v84,
    v118);
  if ( BYTE4(v125[0]) < 3u )
    goto LABEL_53;
  v93 = *(_DWORD *)(v46 + 52);
  HIBYTE(v125[3]) = v93;
  v126 = *(_QWORD *)(v46 + 56);
  *(_DWORD *)v127 = *(_DWORD *)(v46 + 64);
  LODWORD(v119) = *(_DWORD *)v127;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: NoA descriptor[%d] type_count %u, duration %u, interval %u, start_time = %u",
    v85,
    v86,
    v87,
    v88,
    v89,
    v90,
    v91,
    v92,
    "wma_send_bcn_buf_ll",
    2,
    (unsigned __int8)v93,
    v119);
  if ( BYTE4(v125[0]) < 4u
    || (v102 = *(_DWORD *)(v46 + 72),
        v127[4] = v102,
        *(_DWORD *)&v127[5] = *(_DWORD *)(v46 + 76),
        *(_DWORD *)&v127[9] = *(_DWORD *)(v46 + 80),
        *(_DWORD *)&v127[13] = *(_DWORD *)(v46 + 84),
        LODWORD(v120) = *(_DWORD *)&v127[13],
        v103 = qdf_trace_msg(
                 0x36u,
                 8u,
                 "%s: NoA descriptor[%d] type_count %u, duration %u, interval %u, start_time = %u",
                 v94,
                 v95,
                 v96,
                 v97,
                 v98,
                 v99,
                 v100,
                 v101,
                 "wma_send_bcn_buf_ll",
                 3,
                 (unsigned __int8)v102,
                 v120),
        BYTE4(v125[0]) <= 4u) )
  {
LABEL_53:
    ((void (__fastcall *)(__int64, _QWORD *))wma_update_noa)(v47, v125);
    wma_update_probe_resp_noa(a1, v125);
    goto LABEL_54;
  }
  __break(0x5512u);
  v117 = MEMORY[0xFFFFFFFFF9DF47D0](v103);
  return wma_sta_kickout_event(v117);
}
