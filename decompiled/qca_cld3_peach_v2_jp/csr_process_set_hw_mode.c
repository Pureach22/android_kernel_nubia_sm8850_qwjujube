void __fastcall csr_process_set_hw_mode(
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
  __int64 v12; // x0
  __int64 v13; // x20
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w22
  int v24; // w21
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x20
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w0
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
  _DWORD *v60; // x8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // [xsp+8h] [xbp-38h] BYREF
  __int64 v70; // [xsp+10h] [xbp-30h]
  __int64 v71; // [xsp+18h] [xbp-28h]
  __int64 v72; // [xsp+20h] [xbp-20h]
  __int64 v73; // [xsp+28h] [xbp-18h]
  __int64 v74; // [xsp+30h] [xbp-10h]
  __int64 v75; // [xsp+38h] [xbp-8h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  if ( a2 )
  {
    v12 = _qdf_mem_malloc(0x38u, "csr_process_set_hw_mode", 7576);
    if ( v12 )
    {
      v13 = v12;
      v14 = policy_mgr_validate_dbs_switch(*(_QWORD *)(a1 + 21552), *(_DWORD *)(a2 + 60));
      if ( v14 )
      {
        v23 = v14;
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Hw mode change not sent to FW status = %d",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "csr_process_set_hw_mode",
          v14);
        if ( v23 == 6 )
          v24 = 7;
        else
          v24 = 2;
        goto LABEL_7;
      }
      v43 = policy_mgr_get_hw_mode_change_from_hw_mode_index(*(_QWORD *)(a1 + 21552), *(_DWORD *)(a2 + 32));
      if ( !v43 )
      {
        v24 = 2;
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: hw_mode %d, failing",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "csr_process_set_hw_mode",
          0);
        goto LABEL_7;
      }
      policy_mgr_set_hw_mode_change_in_progress(*(_QWORD *)(a1 + 21552), v43);
      policy_mgr_reset_connection_update(*(_QWORD *)(a1 + 21552));
      if ( *(_DWORD *)(a2 + 48) == 4 )
      {
        v60 = *(_DWORD **)(a1 + 14328);
        if ( *(v60 - 1) != -1366728445 )
          __break(0x8228u);
        if ( (((__int64 (__fastcall *)(_QWORD, _QWORD))v60)(0, 0) & 1) != 0 )
        {
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: Set HW mode refused: conn in progress",
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            "csr_process_set_hw_mode");
          policy_mgr_restart_opportunistic_timer(*(_QWORD *)(a1 + 21552), 0);
LABEL_19:
          policy_mgr_set_hw_mode_change_in_progress(*(_QWORD *)(a1 + 21552), 0);
          v24 = 2;
LABEL_7:
          _qdf_mem_free(v13);
          goto LABEL_10;
        }
        if ( *(_DWORD *)(a2 + 48) == 4
          && !*(_DWORD *)(a2 + 32)
          && !(unsigned int)policy_mgr_need_opportunistic_upgrade(*(_QWORD *)(a1 + 21552), nullptr) )
        {
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: Set HW mode to SMM not needed anymore",
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            "csr_process_set_hw_mode");
          goto LABEL_19;
        }
      }
      *(_DWORD *)v13 = 3675241;
      *(_DWORD *)(v13 + 8) = *(_DWORD *)(a2 + 32);
      *(_DWORD *)(v13 + 24) = *(_DWORD *)(a2 + 48);
      *(_QWORD *)(v13 + 16) = *(_QWORD *)(a2 + 40);
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Posting set hw mode req to PE session:%d reason:%d",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "csr_process_set_hw_mode",
        *(unsigned int *)(a2 + 52),
        *(unsigned int *)(a2 + 48));
      if ( !(unsigned int)umac_send_mb_message_to_mac(v13) )
        goto LABEL_12;
      v24 = 2;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Posting to PE failed",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "csr_process_set_hw_mode");
      policy_mgr_set_hw_mode_change_in_progress(*(_QWORD *)(a1 + 21552), 0);
    }
    else
    {
      v24 = 2;
    }
  }
  else
  {
    v24 = 2;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Set HW mode param is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "csr_process_set_hw_mode");
  }
LABEL_10:
  v25 = _qdf_mem_malloc(0x2Cu, "csr_process_set_hw_mode", 7650);
  if ( v25 )
  {
    v34 = v25;
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Sending set HW fail response to SME",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "csr_process_set_hw_mode");
    *(_DWORD *)v34 = v24;
    *(_QWORD *)(v34 + 4) = 0;
    LOWORD(v69) = 5226;
    v70 = v34;
    HIDWORD(v69) = 0;
    sys_process_mmh_msg(v35, v36, v37, v38, v39, v40, v41, v42, a1, (unsigned __int16 *)&v69);
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
}
