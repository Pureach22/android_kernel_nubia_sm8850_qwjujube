__int64 __fastcall qos_process_command(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x4
  __int64 v11; // x5
  unsigned int v14; // w19
  const char *v15; // x2
  const char *v16; // x3
  unsigned int v17; // w19
  unsigned int v18; // w21
  __int64 v20; // x23
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 v32; // x21
  int v33; // w10
  __int16 v34; // w9
  __int16 v35; // w9
  __int16 v36; // w9
  const void *v37; // x22
  __int16 v38; // w9
  __int64 v39; // x21
  char v40; // t1
  __int16 v41; // w9
  __int64 v42; // x8
  __int64 v43; // x23
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 result; // x0
  __int64 v61; // x24
  __int64 v62; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x20
  char v72; // w21
  __int64 v73; // x4
  char v74; // w8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  int v83; // w10
  __int16 v84; // w9
  __int16 v85; // w9
  __int64 v86; // x19
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  __int16 v95; // w9
  char v96; // w10
  __int16 v97; // w9
  __int16 v98; // w9
  __int64 v99; // x9
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  char v108; // w9
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  unsigned int v117; // [xsp+0h] [xbp-10h] BYREF
  int v118; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v119; // [xsp+8h] [xbp-8h]

  v119 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned int *)(a2 + 16);
  if ( (_DWORD)v10 != 262146 )
  {
    if ( (_DWORD)v10 == 262145 )
    {
      v11 = *(unsigned int *)(a2 + 108);
      v14 = (unsigned __int8)*(_DWORD *)(a2 + 24);
      LOWORD(v118) = 0;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: invoked on session %d for AC %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "sme_qos_add_ts_req",
        v14,
        v11);
      if ( v14 < 6 )
      {
        v61 = qword_856120;
        v62 = _qdf_mem_malloc(0xB4u, "sme_qos_add_ts_req", 3679);
        if ( v62 )
        {
          *(_BYTE *)(v62 + 4) = v14;
          *(_DWORD *)(v62 + 12) = 0;
          v71 = v62;
          *(_DWORD *)v62 = 11801628;
          *(_BYTE *)(v62 + 16) = 1;
          v72 = byte_85618C;
          v73 = (unsigned __int8)byte_85618C;
          if ( (((unsigned __int8)byte_85618C + 1) & 0x100) != 0 )
            v74 = 1;
          else
            v74 = byte_85618C + 1;
          byte_85618C = v74;
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: token %d",
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            "sme_qos_assign_dialog_token",
            v73);
          *(_BYTE *)(v71 + 17) = v72;
          *(_DWORD *)(v71 + 64) = 0;
          v83 = *(_DWORD *)(a2 + 68);
          *(_BYTE *)(v71 + 19) = 61;
          *(_DWORD *)(v71 + 36) = v83;
          *(_DWORD *)(v71 + 60) = *(_DWORD *)(a2 + 92);
          *(_WORD *)(v71 + 26) = *(_WORD *)(a2 + 58);
          *(_DWORD *)(v71 + 32) = *(_DWORD *)(a2 + 64);
          *(_DWORD *)(v71 + 52) = *(_DWORD *)(a2 + 84);
          *(_WORD *)(v71 + 74) = *(_WORD *)(a2 + 106);
          *(_DWORD *)(v71 + 48) = *(_DWORD *)(a2 + 80);
          *(_DWORD *)(v71 + 68) = *(_DWORD *)(a2 + 100);
          *(_DWORD *)(v71 + 28) = *(_DWORD *)(a2 + 60);
          *(_WORD *)(v71 + 24) = *(_WORD *)(a2 + 56);
          *(_DWORD *)(v71 + 56) = *(_DWORD *)(a2 + 88);
          *(_WORD *)(v71 + 72) = *(_WORD *)(a2 + 104);
          *(_DWORD *)(v71 + 40) = *(_DWORD *)(a2 + 72);
          *(_DWORD *)(v71 + 44) = 0;
          v84 = *(_WORD *)(v71 + 21) & 0xFF9F | (32 * (*(_WORD *)(a2 + 48) & 3));
          *(_WORD *)(v71 + 21) = v84;
          if ( *(_BYTE *)(a2 + 44) )
          {
            v85 = v84 & 0xFBFF | ((*(_BYTE *)(a2 + 44) & 1) << 10);
            *(_WORD *)(v71 + 21) = v85;
          }
          else
          {
            *(_WORD *)(v71 + 21) = v84 & 0xFBFF;
            *(_BYTE *)(a2 + 44) = 0;
            v85 = *(_WORD *)(v71 + 21);
          }
          v95 = v85 & 0xFFE1 | (2 * (*(_BYTE *)(a2 + 52) & 0xF));
          *(_WORD *)(v71 + 21) = v95;
          v96 = *(_BYTE *)(v71 + 20);
          v97 = v95 & 0xC67F | ((*(_WORD *)(a2 + 40) & 7) << 11) | 0x80;
          *(_WORD *)(v71 + 21) = v97;
          *(_BYTE *)(v71 + 20) = v96 & 0x7F | (*(_BYTE *)(a2 + 32) << 7);
          v98 = v97 & 0x3FFF | (*(_WORD *)(a2 + 36) << 14);
          *(_BYTE *)(v71 + 18) = 2;
          *(_WORD *)(v71 + 21) = v98;
          v99 = *(_QWORD *)(v61 + 3040LL * (v14 & 7) + 2920);
          if ( v99 )
          {
            qdf_mem_copy((void *)(v71 + 5), (const void *)(v99 + 2), 6u);
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: up = %d, tid = %d",
              v100,
              v101,
              v102,
              v103,
              v104,
              v105,
              v106,
              v107,
              "sme_qos_add_ts_req",
              *(unsigned int *)(a2 + 40),
              *(unsigned __int8 *)(a2 + 52));
            if ( (wlan_cm_get_ese_assoc(*(_QWORD *)(a1 + 21560), v14) & 1) != 0 )
            {
              v108 = *(_BYTE *)(v71 + 179);
              *(_BYTE *)(v71 + 170) = *(_DWORD *)(a2 + 40);
              *(_BYTE *)(v71 + 179) = v108 | 1;
            }
            if ( !(unsigned int)umac_send_mb_message_to_mac(v71) )
            {
              qdf_trace_msg(
                0x34u,
                8u,
                "%s: sent down a ADDTS req to PE",
                v109,
                v110,
                v111,
                v112,
                v113,
                v114,
                v115,
                v116,
                "sme_qos_add_ts_req");
              LOWORD(v118) = 1024;
              host_diag_event_report_payload(1657, 2, &v118);
              result = 0;
              goto LABEL_14;
            }
          }
          else
          {
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: BSS descriptor is NULL so we don't send request to PE",
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              "sme_qos_add_ts_req");
            _qdf_mem_free(v71);
          }
        }
        goto LABEL_13;
      }
      v15 = "%s: sessionId(%d) is invalid";
      v16 = "sme_qos_add_ts_req";
      v10 = v14;
    }
    else
    {
      v15 = "%s: invalid command type %d";
      v16 = "qos_process_command";
    }
    qdf_trace_msg(0x34u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, v16, v10);
LABEL_13:
    result = 1;
LABEL_14:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v17 = *(unsigned __int8 *)(a2 + 24);
  v18 = *(_DWORD *)(a2 + 108);
  v20 = *(unsigned __int8 *)(a2 + 112);
  LOWORD(v117) = 0;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: invoked on session %d for AC %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "sme_qos_del_ts_req",
    v17,
    v18,
    v117,
    v119);
  v21 = _qdf_mem_malloc(0x54u, "sme_qos_del_ts_req", 3782);
  if ( !v21 )
    goto LABEL_13;
  if ( v18 < 5 && (unsigned __int64)(v20 - 1) <= 2 )
  {
    v30 = qword_856120;
    *(_BYTE *)(v21 + 4) = v17;
    v31 = v30 + 3040LL * v17;
    *(_DWORD *)v21 = 5510174;
    v32 = v31 + 728LL * v18 + 76LL * ((int)v20 - 1);
    *(_BYTE *)(v21 + 20) = 1;
    *(_DWORD *)(v21 + 71) = *(_DWORD *)(v32 + 80);
    v33 = *(_DWORD *)(v32 + 52);
    *(_BYTE *)(v21 + 26) = 61;
    *(_DWORD *)(v21 + 43) = v33;
    *(_DWORD *)(v21 + 67) = *(_DWORD *)(v32 + 76);
    *(_WORD *)(v21 + 33) = *(_WORD *)(v32 + 42);
    *(_DWORD *)(v21 + 39) = *(_DWORD *)(v32 + 48);
    *(_DWORD *)(v21 + 59) = *(_DWORD *)(v32 + 68);
    *(_WORD *)(v21 + 81) = *(_WORD *)(v32 + 90);
    *(_DWORD *)(v21 + 55) = *(_DWORD *)(v32 + 64);
    *(_DWORD *)(v21 + 75) = *(_DWORD *)(v32 + 84);
    *(_DWORD *)(v21 + 35) = *(_DWORD *)(v32 + 44);
    *(_WORD *)(v21 + 31) = *(_WORD *)(v32 + 40);
    *(_DWORD *)(v21 + 63) = *(_DWORD *)(v32 + 72);
    *(_WORD *)(v21 + 79) = *(_WORD *)(v32 + 88);
    *(_DWORD *)(v21 + 47) = *(_DWORD *)(v32 + 56);
    *(_DWORD *)(v21 + 51) = *(_DWORD *)(v32 + 60);
    v34 = *(_WORD *)(v21 + 28) & 0xFF9F | (32 * (*(_WORD *)(v32 + 32) & 3));
    *(_WORD *)(v21 + 28) = v34;
    v35 = v34 & 0xFBFF | ((*(_BYTE *)(v32 + 28) & 1) << 10);
    *(_WORD *)(v21 + 28) = v35;
    v36 = v35 & 0xFFE1 | (2 * (*(_BYTE *)(v32 + 36) & 0xF));
    *(_WORD *)(v21 + 28) = v36;
    v37 = (const void *)(v21 + 27);
    LOBYTE(v33) = *(_BYTE *)(v21 + 27);
    v38 = v36 & 0xC67F | ((*(_WORD *)(v32 + 24) & 7) << 11) | 0x80;
    *(_WORD *)(v21 + 28) = v38;
    v40 = *(_BYTE *)(v32 + 16);
    v39 = v32 + 16;
    *(_BYTE *)(v21 + 27) = v33 & 0x7F | (v40 << 7);
    v41 = v38 & 0x3FFF | (*(_WORD *)(v39 + 4) << 14);
    *(_BYTE *)(v21 + 25) = 2;
    *(_WORD *)(v21 + 28) = v41;
    v42 = *(_QWORD *)(v31 + 2920);
    if ( v42 )
    {
      v43 = v21;
      qdf_mem_copy((void *)(v21 + 5), (const void *)(v42 + 2), 6u);
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: up = %d, tid = %d",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "sme_qos_del_ts_req",
        *(unsigned int *)(v39 + 8),
        *(unsigned __int8 *)(v39 + 20));
      qdf_mem_set((void *)v39, 0x4Cu, 0);
      qdf_mem_copy(&v118, v37, 4u);
      if ( !(unsigned int)umac_send_mb_message_to_mac(v43) )
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: sent down a DELTS req to PE",
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          "sme_qos_del_ts_req");
        LOWORD(v117) = 1026;
        host_diag_event_report_payload(1657, 2, &v117);
        sme_set_tspec_uapsd_mask_per_session(a1, (__int64)&v118, v17, v87, v88, v89, v90, v91, v92, v93, v94);
        result = 0;
        goto LABEL_14;
      }
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: DELTS req to PE failed",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "sme_qos_del_ts_req");
    }
    else
    {
      v86 = v21;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: BSS descriptor is NULL so we don't send request to PE",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "sme_qos_del_ts_req");
      _qdf_mem_free(v86);
    }
    goto LABEL_13;
  }
  __break(0x5512u);
  return sme_qos_buffer_cmd();
}
