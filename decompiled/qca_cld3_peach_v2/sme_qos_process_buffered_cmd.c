__int64 __fastcall sme_qos_process_buffered_cmd(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x19
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x19
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w5
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  const char *v47; // x2
  unsigned int v48; // w21
  unsigned int v49; // w23
  unsigned int v50; // w22
  __int64 v51; // x24
  __int64 v52; // x0
  __int64 v53; // x1
  __int64 v54; // x2
  __int64 v55; // x3
  __int64 v56; // x4
  __int64 v57; // x5
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x27
  __int64 v67; // x9
  __int64 v68; // x9
  __int64 v69; // x8
  __int64 v70; // x9
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x0
  __int64 v80; // x8
  const char *v81; // x3
  __int64 v82; // x4
  __int64 v83; // x4
  unsigned int v84; // w20
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  const char *v101; // x2
  __int64 v102; // [xsp+8h] [xbp-58h]
  __int64 v103; // [xsp+10h] [xbp-50h]
  __int64 v104; // [xsp+18h] [xbp-48h]
  __int64 v105; // [xsp+20h] [xbp-40h]
  __int64 v106; // [xsp+28h] [xbp-38h]
  __int64 v107; // [xsp+30h] [xbp-30h]
  __int64 v108; // [xsp+38h] [xbp-28h]
  __int64 v109; // [xsp+40h] [xbp-20h]
  __int64 v110; // [xsp+48h] [xbp-18h]
  int v111; // [xsp+50h] [xbp-10h]

  _ReadStatusReg(SP_EL0);
  v10 = qword_91F2D8 + 3040LL * a1;
  result = csr_ll_is_list_empty(v10 + 2944, 0, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (result & 1) != 0 )
    goto LABEL_36;
  v20 = csr_ll_remove_head(v10 + 2944, 1, v12, v13, v14, v15, v16, v17, v18, v19);
  if ( !v20 )
  {
    result = qdf_trace_msg(
               0x34u,
               2u,
               "%s: no more buffered commands on session %d",
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               "sme_qos_process_buffered_cmd",
               a1);
LABEL_36:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v29 = v20;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Qos cmd %d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "sme_qos_process_buffered_cmd",
    *(unsigned int *)(v20 + 16));
  v38 = *(_DWORD *)(v29 + 16);
  if ( v38 <= 1 )
  {
    if ( !v38 )
    {
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, __int64, _QWORD, _QWORD, _QWORD, _QWORD, __int64, _BYTE))sme_qos_internal_setup_req)(
                           *(_QWORD *)(v29 + 24),
                           *(unsigned __int8 *)(v29 + 32),
                           v29 + 44,
                           *(_QWORD *)(v29 + 128),
                           *(_QWORD *)(v29 + 120),
                           *(unsigned int *)(v29 + 136),
                           *(unsigned int *)(v29 + 40),
                           1,
                           *(_BYTE *)(v29 + 140)) == 2 )
      {
        v47 = "%s: sme_qos_internal_setup_req failed on session %d";
        goto LABEL_33;
      }
LABEL_35:
      result = _qdf_mem_free(v29);
      goto LABEL_36;
    }
    if ( v38 == 1 )
    {
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64))sme_qos_internal_release_req)(
                           *(_QWORD *)(v29 + 24),
                           *(unsigned __int8 *)(v29 + 32),
                           *(unsigned int *)(v29 + 40),
                           1) == 101 )
      {
        v47 = "%s: sme_qos_internal_release_req failed on session %d";
LABEL_33:
        v81 = "sme_qos_process_buffered_cmd";
        v82 = a1;
LABEL_34:
        qdf_trace_msg(0x34u, 2u, v47, v39, v40, v41, v42, v43, v44, v45, v46, v81, v82);
        goto LABEL_35;
      }
      goto LABEL_35;
    }
LABEL_22:
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: On session %d unknown cmd = %d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "sme_qos_process_buffered_cmd",
      a1);
    goto LABEL_35;
  }
  if ( v38 == 2 )
  {
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64, _QWORD, __int64))sme_qos_internal_modify_req)(
                         *(_QWORD *)(v29 + 24),
                         v29 + 48,
                         *(unsigned int *)(v29 + 40),
                         1) == 202 )
    {
      v47 = "%s: sme_qos_internal_modify_req failed on session %d";
      goto LABEL_33;
    }
    goto LABEL_35;
  }
  if ( v38 != 3 )
    goto LABEL_22;
  v48 = *(unsigned __int8 *)(v29 + 32);
  v49 = *(_DWORD *)(v29 + 44);
  v50 = *(unsigned __int8 *)(v29 + 40);
  v51 = *(_QWORD *)(v29 + 24);
  v52 = qdf_trace_msg(
          0x34u,
          8u,
          "%s:  Invoked on session %d for AC %d TSPEC %d",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "sme_qos_re_request_add_ts",
          *(unsigned __int8 *)(v29 + 32),
          v49,
          *(unsigned __int8 *)(v29 + 40));
  if ( v49 < 5 )
  {
    v66 = qword_91F2D8 + 3040LL * v48 + 728LL * v49;
    if ( v49 )
    {
      v67 = qword_91F2D8 + 3040LL * v48;
      if ( *(_BYTE *)(v67 + 322) || (*(_BYTE *)(v67 + 320) & 1) != 0 )
        goto LABEL_29;
      if ( v49 == 1 )
        goto LABEL_27;
    }
    v68 = qword_91F2D8 + 3040LL * v48;
    if ( *(_BYTE *)(v68 + 1050) || (*(_BYTE *)(v68 + 1048) & 1) != 0 )
      goto LABEL_29;
    if ( v49 != 2 )
    {
LABEL_27:
      v70 = qword_91F2D8 + 3040LL * v48;
      if ( *(_BYTE *)(v70 + 1778) || (*(_BYTE *)(v70 + 1776) & 1) != 0 )
        goto LABEL_29;
      if ( v49 == 3 )
      {
LABEL_38:
        v83 = *(unsigned int *)(v66 + 8);
        if ( (_DWORD)v83 != 3 && (_DWORD)v83 != 5 )
        {
          if ( (_DWORD)v83 == 4 )
          {
            *(_BYTE *)(v66 + 323) = 1;
            v84 = sme_qos_setup(v51, v48, (_BYTE *)(v29 + 48), v49, v58, v59, v60, v61, v62, v63, v64, v65);
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: sme_qos_setup returned in SME_QOS_QOS_ON state sme_qos_setup AC %d with status =%d",
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              v91,
              v92,
              "sme_qos_re_request_add_ts",
              v49,
              v84);
            if ( v84 == 1 || v84 == 7 )
            {
              v47 = "%s: UAPSD is setup already status = %d ";
            }
            else
            {
              if ( v84 == 5 )
              {
                *(_BYTE *)(v66 + 322) = v50;
                goto LABEL_35;
              }
              v47 = "%s: sme_qos_setup return status = %d ";
            }
            v81 = "sme_qos_re_request_add_ts";
            v82 = v84;
            goto LABEL_34;
          }
          v101 = "%s: Re-Add request in unexpected state = %d";
          goto LABEL_48;
        }
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Re-Add request in state = %d  buffer the request",
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          "sme_qos_re_request_add_ts");
        v108 = *(_QWORD *)(v29 + 96);
        v109 = *(_QWORD *)(v29 + 104);
        v110 = *(_QWORD *)(v29 + 112);
        v111 = *(_DWORD *)(v29 + 120);
        v104 = *(_QWORD *)(v29 + 64);
        v105 = *(_QWORD *)(v29 + 72);
        v106 = *(_QWORD *)(v29 + 80);
        v107 = *(_QWORD *)(v29 + 88);
        v102 = *(_QWORD *)(v29 + 48);
        v103 = *(_QWORD *)(v29 + 56);
        qdf_trace_msg(0x34u, 8u, "%s: Invoked", v93, v94, v95, v96, v97, v98, v99, v100, "sme_qos_buffer_cmd");
        v79 = _qdf_mem_malloc(0x90u, "sme_qos_buffer_cmd", 5884);
        if ( !v79 )
        {
          v83 = *(unsigned int *)(v66 + 8);
          v101 = "%s:  couldn't buf the read request state = %d";
LABEL_48:
          qdf_trace_msg(0x34u, 2u, v101, v58, v59, v60, v61, v62, v63, v64, v65, "sme_qos_re_request_add_ts", v83);
          goto LABEL_32;
        }
LABEL_30:
        *(_QWORD *)(v79 + 16) = 3;
        *(_QWORD *)(v79 + 24) = v51;
        *(_QWORD *)(v79 + 112) = v110;
        *(_BYTE *)(v79 + 32) = v48;
        *(_QWORD *)(v79 + 96) = v108;
        *(_QWORD *)(v79 + 104) = v109;
        *(_DWORD *)(v79 + 33) = 0;
        *(_DWORD *)(v79 + 120) = v111;
        *(_DWORD *)(v79 + 36) = 0;
        *(_BYTE *)(v79 + 40) = v50;
        *(_QWORD *)(v79 + 64) = v104;
        *(_QWORD *)(v79 + 72) = v105;
        *(_WORD *)(v79 + 41) = 0;
        *(_BYTE *)(v79 + 43) = 0;
        *(_QWORD *)(v79 + 80) = v106;
        *(_QWORD *)(v79 + 88) = v107;
        *(_DWORD *)(v79 + 44) = v49;
        *(_DWORD *)(v79 + 140) = 0;
        *(_QWORD *)(v79 + 48) = v102;
        *(_QWORD *)(v79 + 56) = v103;
        v80 = qword_91F2D8 + 3040LL * v48;
        *(_QWORD *)(v79 + 132) = 0;
        *(_QWORD *)(v79 + 124) = 0;
        csr_ll_insert_tail(v80 + 2944, (_QWORD *)v79, 1, v58, v59, v60, v61, v62, v63, v64, v65);
        goto LABEL_35;
      }
    }
    v69 = qword_91F2D8 + 3040LL * v48;
    if ( !*(_BYTE *)(v69 + 2506) && *(_BYTE *)(v69 + 2504) != 1 )
      goto LABEL_38;
LABEL_29:
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: On session %d buffering the AddTS request for AC %d in state %d as Addts is pending on other AC or waiting for full power",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "sme_qos_re_request_add_ts",
      v48,
      v49,
      *(unsigned int *)(v66 + 8));
    v108 = *(_QWORD *)(v29 + 96);
    v109 = *(_QWORD *)(v29 + 104);
    v110 = *(_QWORD *)(v29 + 112);
    v111 = *(_DWORD *)(v29 + 120);
    v104 = *(_QWORD *)(v29 + 64);
    v105 = *(_QWORD *)(v29 + 72);
    v106 = *(_QWORD *)(v29 + 80);
    v107 = *(_QWORD *)(v29 + 88);
    v102 = *(_QWORD *)(v29 + 48);
    v103 = *(_QWORD *)(v29 + 56);
    qdf_trace_msg(0x34u, 8u, "%s: Invoked", v71, v72, v73, v74, v75, v76, v77, v78, "sme_qos_buffer_cmd");
    v79 = _qdf_mem_malloc(0x90u, "sme_qos_buffer_cmd", 5884);
    if ( !v79 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: On session %d unable to buffer the AddTS request for AC %d TSPEC %d in state %d",
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        "sme_qos_re_request_add_ts",
        v48,
        v49,
        v50,
        *(unsigned int *)(v66 + 8));
LABEL_32:
      v47 = "%s: sme_qos_re_request_add_ts failed on session %d";
      goto LABEL_33;
    }
    goto LABEL_30;
  }
  __break(0x5512u);
  return qos_issue_command(v52, v53, v54, v55, v56, v57);
}
