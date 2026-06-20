__int64 __fastcall sme_qos_msg_processor(
        __int64 a1,
        unsigned __int16 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 active; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _DWORD *v31; // x21
  __int64 v32; // x5
  unsigned int v33; // w20
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 result; // x0
  unsigned int v51; // w19
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int v60; // w23
  __int64 v61; // x27
  __int64 v62; // x25
  __int64 v63; // x19
  __int64 v64; // x8
  __int64 v65; // x9
  __int64 v66; // x8
  __int64 v67; // x8
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  int v76; // w0
  int v77; // w8
  __int64 v78; // x8
  char v79; // w21
  unsigned int v80; // w26
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 v90; // x8
  __int64 v91; // x9
  __int64 v92; // x8
  __int64 v93; // x8
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  int v102; // w0
  int v103; // w8
  unsigned int v104; // w26
  const char *v105; // x2
  const char *v106; // x3
  __int64 v107; // x4
  __int64 v108; // x0
  _DWORD *v109; // x22
  double v110; // d0
  unsigned int v111; // w0
  unsigned int v112; // w20
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  unsigned __int8 v128; // w21
  unsigned __int64 v129; // x22
  unsigned int v130; // w23
  double v131; // d0
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  __int64 v147; // [xsp+8h] [xbp-E8h]
  unsigned int v148; // [xsp+10h] [xbp-E0h]
  __int16 v149; // [xsp+14h] [xbp-DCh] BYREF
  _QWORD dest[27]; // [xsp+18h] [xbp-D8h] BYREF

  v11 = a2;
  dest[25] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x34u, 8u, "%s: msg = %d for QoS", a4, a5, a6, a7, a8, a9, a10, a11, "sme_qos_msg_processor", a2);
  if ( v11 > 5151 )
  {
    if ( v11 == 5152 )
    {
      v128 = *(_BYTE *)(a3 + 4);
      v129 = ((unsigned __int64)*(unsigned __int16 *)(a3 + 27) >> 11) & 7;
      dest[0] = 0;
      dest[1] = 0;
      v149 = 1282;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Invoked on session %d for UP %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "sme_qos_process_del_ts_ind",
        v128,
        (unsigned int)v129);
      v130 = sme_qos_up_to_ac_map[v129];
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: up = %d ac = %d returned",
        v131,
        v132,
        v133,
        v134,
        v135,
        v136,
        v137,
        v138,
        "sme_qos_up_to_ac",
        (unsigned int)v129,
        v130);
      if ( v130 == 4 )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: invalid AC %d from UP %d",
          v139,
          v140,
          v141,
          v142,
          v143,
          v144,
          v145,
          v146,
          "sme_qos_process_del_ts_ind",
          4,
          (unsigned int)v129);
        goto LABEL_43;
      }
      if ( v130 >= 5 )
      {
        __break(0x5512u);
        JUMPOUT(0x4B4084);
      }
      qdf_mem_set(dest, 0x10u, 0);
      HIDWORD(dest[0]) = v130;
      BYTE1(dest[0]) = 2;
      LOBYTE(dest[0]) = v128;
      if ( !(unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64 (__fastcall *)()))sme_qos_find_all_in_flow_list)(
                            a1,
                            dest[0],
                            dest[1],
                            sme_qos_del_ts_ind_fnp) )
      {
        sme_set_tspec_uapsd_mask_per_session(a1, a3 + 26, v128, v14, v15, v16, v17, v18, v19, v20, v21);
        host_diag_event_report_payload(1657, 2, &v149);
        goto LABEL_46;
      }
      v107 = HIDWORD(dest[0]);
      v105 = "%s: no match found for ac = %d";
      v106 = "sme_qos_process_del_ts_ind";
LABEL_42:
      qdf_trace_msg(0x34u, 2u, v105, v14, v15, v16, v17, v18, v19, v20, v21, v106, v107);
      goto LABEL_43;
    }
    if ( v11 != 5173 )
    {
LABEL_30:
      v105 = "%s: unknown msg type = %d";
      v106 = "sme_qos_msg_processor";
      v107 = (unsigned int)v11;
      goto LABEL_42;
    }
    v147 = a1;
    v51 = *(unsigned __int8 *)(a3 + 4);
    memset(dest, 0, 200);
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Received AGGR_QOS resp from LIM",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "sme_qos_process_aggr_qos_rsp");
    v60 = 0;
    v61 = 0;
    v62 = 3040LL * v51;
    v63 = a3 + 26;
    v148 = 0;
    do
    {
      v78 = qword_91F2D8 + v62 + v61;
      v79 = *(_BYTE *)(v78 + 321);
      v80 = (*(unsigned __int16 *)(v78 + 357) >> 5) & 3;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Addts rsp from LIM AC=%d, flow=%d dir=%d, tspecIdx=%x",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "sme_qos_process_aggr_qos_rsp",
        v60,
        0,
        v80,
        *(unsigned __int16 *)(a3 + 8));
      if ( ((1 << v60) & *(unsigned __int16 *)(a3 + 8)) != 0 && (v79 & 1) != 0 && (v80 == 3 || v80 == 0) )
      {
        memcpy(dest, (const void *)(qword_91F2D8 + v62 + v61 + 328), 0xC8u);
        LODWORD(dest[1]) = *(_DWORD *)(v63 - 10);
        LODWORD(dest[2]) = dest[1];
        v90 = *(_QWORD *)(v63 + 40);
        *(_QWORD *)((char *)&dest[7] + 2) = *(_QWORD *)(v63 + 32);
        v91 = *(_QWORD *)(v63 + 48);
        *(_QWORD *)((char *)&dest[8] + 2) = v90;
        LOWORD(v90) = *(_WORD *)(v63 + 56);
        *(_QWORD *)((char *)&dest[9] + 2) = v91;
        WORD1(dest[10]) = v90;
        v92 = *(_QWORD *)(v63 + 8);
        *(_QWORD *)((char *)&dest[3] + 2) = *(_QWORD *)v63;
        *(_QWORD *)((char *)&dest[4] + 2) = v92;
        v93 = *(_QWORD *)(v63 + 24);
        *(_QWORD *)((char *)&dest[5] + 2) = *(_QWORD *)(v63 + 16);
        *(_QWORD *)((char *)&dest[6] + 2) = v93;
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Processing Addts rsp from LIM AC=%d, flow=%d",
          v94,
          v95,
          v96,
          v97,
          v98,
          v99,
          v100,
          v101,
          "sme_qos_process_aggr_qos_rsp",
          v60,
          0);
        v102 = ((__int64 (__fastcall *)(__int64, _QWORD *))sme_qos_process_add_ts_rsp)(v147, dest);
        v103 = v148;
        if ( v102 )
          v103 = 16;
        v148 = v103;
      }
      v104 = (*(unsigned __int16 *)(qword_91F2D8 + v62 + v61 + 557) >> 5) & 3;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Addts rsp from LIM AC=%d, flow=%d dir=%d, tspecIdx=%x",
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        "sme_qos_process_aggr_qos_rsp",
        v60,
        1,
        v104);
      if ( ((1 << v60) & *(unsigned __int16 *)(a3 + 8)) != 0 && (v79 & 2) != 0 && (v104 == 3 || !v104) )
      {
        memcpy(dest, (const void *)(qword_91F2D8 + v62 + v61 + 528), 0xC8u);
        LODWORD(dest[1]) = *(_DWORD *)(v63 - 10);
        LODWORD(dest[2]) = dest[1];
        v64 = *(_QWORD *)(v63 + 40);
        *(_QWORD *)((char *)&dest[7] + 2) = *(_QWORD *)(v63 + 32);
        v65 = *(_QWORD *)(v63 + 48);
        *(_QWORD *)((char *)&dest[8] + 2) = v64;
        LOWORD(v64) = *(_WORD *)(v63 + 56);
        *(_QWORD *)((char *)&dest[9] + 2) = v65;
        WORD1(dest[10]) = v64;
        v66 = *(_QWORD *)(v63 + 8);
        *(_QWORD *)((char *)&dest[3] + 2) = *(_QWORD *)v63;
        *(_QWORD *)((char *)&dest[4] + 2) = v66;
        v67 = *(_QWORD *)(v63 + 24);
        *(_QWORD *)((char *)&dest[5] + 2) = *(_QWORD *)(v63 + 16);
        *(_QWORD *)((char *)&dest[6] + 2) = v67;
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Processing Addts rsp from LIM AC=%d, flow=%d",
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          "sme_qos_process_aggr_qos_rsp",
          v60,
          1);
        v76 = ((__int64 (__fastcall *)(__int64, _QWORD *))sme_qos_process_add_ts_rsp)(v147, dest);
        v77 = v148;
        if ( v76 )
          v77 = 16;
        v148 = v77;
      }
      v61 += 728;
      v63 += 188;
      ++v60;
    }
    while ( v61 != 2912 );
    result = v148;
  }
  else
  {
    if ( v11 != 5149 )
    {
      if ( v11 == 5151 )
      {
        active = csr_nonscan_active_ll_peek_head(a1, v14, v15, v16, v17, v18, v19, v20, v21);
        if ( active )
        {
          v31 = (_DWORD *)active;
          if ( *(_DWORD *)(active + 16) == 262146 )
          {
            v32 = *(unsigned int *)(a3 + 8);
            v33 = *(unsigned __int8 *)(a3 + 4);
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: Invoked on session %d with return code %d",
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "sme_qos_process_del_ts_rsp",
              v33,
              v32);
            v34 = sme_qos_process_buffered_cmd(v33);
            if ( csr_nonscan_active_ll_remove_entry(a1, (__int64)v31, v34, v35, v36, v37, v38, v39, v40, v41) )
            {
              qdf_mem_set(v31 + 8, 0x54u, 0);
              csr_release_command(a1, v31, v42, v43, v44, v45, v46, v47, v48, v49);
              result = 0;
              goto LABEL_44;
            }
LABEL_46:
            result = 0;
            goto LABEL_44;
          }
        }
LABEL_43:
        result = 16;
        goto LABEL_44;
      }
      goto LABEL_30;
    }
    v108 = csr_nonscan_active_ll_peek_head(a1, v14, v15, v16, v17, v18, v19, v20, v21);
    if ( !v108 )
      goto LABEL_43;
    v109 = (_DWORD *)v108;
    if ( *(_DWORD *)(v108 + 16) != 262145 )
      goto LABEL_43;
    v110 = ((double (__fastcall *)(__int64, __int64))sme_qos_process_add_ts_rsp)(a1, a3);
    v112 = v111;
    if ( csr_nonscan_active_ll_remove_entry(a1, (__int64)v109, v110, v113, v114, v115, v116, v117, v118, v119) )
    {
      qdf_mem_set(v109 + 8, 0x54u, 0);
      csr_release_command(a1, v109, v120, v121, v122, v123, v124, v125, v126, v127);
    }
    result = v112;
  }
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
