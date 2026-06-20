__int64 __fastcall wlan_ipa_uc_ol_init(
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
  unsigned int v10; // w21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  unsigned int (**v22)(void); // x8
  unsigned int (*v23)(void); // x8
  unsigned __int8 v24; // w26
  __int64 v25; // x20
  __int64 v26; // x27
  __int64 v27; // x28
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x8
  const char *v38; // x2
  int v39; // w3
  int v40; // w4
  int v41; // w5
  int v42; // w6
  int v43; // w7
  __int64 v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x8
  char v55; // w10
  unsigned int v56; // w21
  __int64 v57; // x9
  _DWORD *v58; // x9
  __int64 v59; // x5
  __int64 v60; // x22
  __int64 v61; // x4
  __int64 v62; // x5
  __int64 v63; // x6
  __int64 v64; // x7
  __int64 v65; // x21
  int v66; // w3
  int v67; // w4
  int v68; // w5
  int v69; // w6
  int v70; // w7
  __int64 v71; // x1
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  int v80; // w2
  int v81; // w3
  int v82; // w4
  int v83; // w5
  int v84; // w6
  int v85; // w7
  __int64 i; // x22
  __int64 v87; // x8
  __int64 v88; // x0
  __int64 v89; // x8
  _DWORD *v90; // x8
  int v91; // w2
  int v92; // w3
  int v93; // w4
  int v94; // w5
  int v95; // w6
  int v96; // w7
  __int64 v97; // x0
  __int64 v98; // x8
  void (*v99)(void); // x8
  int v100; // w3
  int v101; // w4
  int v102; // w5
  int v103; // w6
  int v104; // w7
  __int64 v105; // [xsp+0h] [xbp-50h]
  char v106; // [xsp+0h] [xbp-50h]
  char v107; // [xsp+0h] [xbp-50h]
  char v108; // [xsp+0h] [xbp-50h]
  char v109; // [xsp+0h] [xbp-50h]
  __int64 v110; // [xsp+8h] [xbp-48h]
  char v111; // [xsp+10h] [xbp-40h]
  __int64 v112; // [xsp+18h] [xbp-38h]
  char v113; // [xsp+20h] [xbp-30h]
  int v114; // [xsp+28h] [xbp-28h]
  int v115; // [xsp+30h] [xbp-20h]
  __int64 (__fastcall *v116)(); // [xsp+38h] [xbp-18h]

  if ( (**(_BYTE **)(a1 + 1464) & 0x20) != 0 )
  {
    qdf_trace_msg(0x61u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_ipa_uc_ol_init");
    if ( a2 )
    {
      v21 = *(_QWORD *)(a1 + 1456);
      *(_BYTE *)(a1 + 7292) = 5;
      *(_DWORD *)(a1 + 7288) = 84215045;
      *(_DWORD *)(a1 + 7293) = 0;
      *(_BYTE *)(a1 + 7297) = 0;
      *(_DWORD *)(a1 + 7352) = 0;
      *(_BYTE *)(a1 + 7356) = 0;
      if ( v21 && *(_QWORD *)v21 && (v22 = *(unsigned int (***)(void))(*(_QWORD *)v21 + 152LL)) != nullptr )
      {
        v23 = *v22;
        if ( !v23 )
          goto LABEL_11;
        if ( *((_DWORD *)v23 - 1) != 261447488 )
          __break(0x8228u);
        if ( !v23() )
        {
LABEL_11:
          v24 = 0;
          v25 = a1 + 1552;
          v26 = -1408;
          do
          {
            v27 = a1 + v26;
            *(_QWORD *)(v27 + 3016) = a2;
            *(_QWORD *)(v27 + 3008) = 0;
            *(_QWORD *)(v27 + 3024) = a1;
            if ( (unsigned int)v24 - 13 <= 1 )
            {
              v28 = _qdf_mem_malloc(0x28u, "wlan_ipa_uc_ol_init", 6479);
              *(_QWORD *)(v27 + 3032) = v28;
              *(_WORD *)(v27 + 3040) = 1;
              if ( v28 )
              {
                *(_QWORD *)(*(_QWORD *)(v27 + 3032) + 8LL) = _qdf_mem_malloc(0x200u, "wlan_ipa_uc_ol_init", 6488);
                *(_WORD *)(*(_QWORD *)(v27 + 3032) + 16LL) = 16;
                v37 = *(_QWORD *)(v27 + 3032);
                if ( !*(_QWORD *)(v37 + 8) )
                {
                  qdf_trace_msg(
                    0x61u,
                    2u,
                    "%s: msg list memory allocation failed",
                    v13,
                    v14,
                    v15,
                    v16,
                    v17,
                    v18,
                    v19,
                    v20,
                    "wlan_ipa_uc_ol_init");
                  v37 = *(_QWORD *)(v27 + 3032);
                }
                *(_DWORD *)(v37 + 24) = 0;
                *(_QWORD *)(v37 + 32) = 0;
              }
              else
              {
                qdf_trace_msg(
                  0x61u,
                  2u,
                  "%s: msg list struct memory allocation failed",
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  "wlan_ipa_uc_ol_init");
              }
            }
            v26 += 88;
            ++v24;
            *(_QWORD *)(v27 + 3000) = v27 + 2960;
            *(_QWORD *)(v27 + 2960) = 0xFFFFFFFE00000LL;
            *(_QWORD *)(v27 + 2992) = wlan_ipa_uc_fw_op_event_handler;
            *(_QWORD *)(v27 + 2968) = v27 + 2968;
            *(_QWORD *)(v27 + 2976) = v27 + 2968;
            *(_QWORD *)(v27 + 2984) = _qdf_defer_func;
          }
          while ( v26 );
          if ( *(_BYTE *)(a1 + 6984) != 1 )
            goto LABEL_59;
          wlan_ipa_add_rem_flt_cb_event(a1);
          v45 = _qdf_mem_malloc(0x300u, "wlan_ipa_wdi_setup", 676);
          if ( v45 )
          {
            v54 = *(_QWORD *)(a1 + 1456);
            if ( *(_BYTE *)(a1 + 7436) == 1 )
              v55 = *(_BYTE *)(a2 + 608);
            else
              v55 = 0;
            if ( v54 && *(_QWORD *)v54 && (v57 = *(_QWORD *)(*(_QWORD *)v54 + 152LL)) != 0 )
            {
              v58 = *(_DWORD **)(v57 + 120);
              if ( !v58 )
              {
                _qdf_mem_free(v45);
LABEL_50:
                v88 = *(_QWORD *)(a1 + 1456);
                if ( v88 && *(_QWORD *)v88 && (v89 = *(_QWORD *)(*(_QWORD *)v88 + 152LL)) != 0 )
                {
                  v90 = *(_DWORD **)(v89 + 184);
                  if ( !v90 )
                    goto LABEL_57;
                  if ( *(v90 - 1) != -1922697876 )
                    __break(0x8228u);
                  v10 = ((__int64 (__fastcall *)(__int64, _QWORD, const char *, __int64, __int64, __int64, __int64, __int64))v90)(
                          v88,
                          0,
                          "wlan_ipa_uc_ol_init",
                          6524,
                          v61,
                          v62,
                          v63,
                          v64);
                  if ( !v10 )
                  {
LABEL_57:
                    qdf_trace_msg(
                      0x61u,
                      4u,
                      "%s: TX buffers mapped to IPA",
                      v46,
                      v47,
                      v48,
                      v49,
                      v50,
                      v51,
                      v52,
                      v53,
                      "wlan_ipa_uc_ol_init",
                      v105,
                      v110,
                      v111,
                      v112,
                      v113,
                      v114,
                      v115,
                      v116);
                    wlan_ipa_log_message(
                      (int)"wlan_ipa_uc_ol_init",
                      (int)"TX buffers mapped to IPA",
                      v91,
                      v92,
                      v93,
                      v94,
                      v95,
                      v96,
                      v108);
                    cdp_ipa_set_doorbell_paddr(*(_QWORD *)(a1 + 1456));
                    if ( (unsigned int)wlan_ipa_init_perf_level(a1) )
                      qdf_trace_msg(
                        0x61u,
                        2u,
                        "%s: Failed to init perf level",
                        v13,
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        "wlan_ipa_uc_ol_init");
LABEL_59:
                    v97 = *(_QWORD *)(a1 + 1456);
                    if ( v97 && *(_QWORD *)v97 && (v98 = *(_QWORD *)(*(_QWORD *)v97 + 152LL)) != 0 )
                    {
                      v99 = *(void (**)(void))(v98 + 40);
                      if ( v99 )
                      {
                        if ( *((_DWORD *)v99 - 1) != 1214136377 )
                          __break(0x8228u);
                        v99();
                      }
                    }
                    else
                    {
                      qdf_trace_msg(
                        0x45u,
                        1u,
                        "%s invalid instance",
                        v13,
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        "cdp_ipa_register_op_cb");
                    }
                    v10 = 0;
                    *(_BYTE *)(a1 + 7513) = 3;
                    goto LABEL_23;
                  }
                }
                else
                {
                  qdf_trace_msg(
                    0x45u,
                    1u,
                    "%s invalid instance",
                    v46,
                    v47,
                    v48,
                    v49,
                    v50,
                    v51,
                    v52,
                    v53,
                    "cdp_ipa_tx_buf_smmu_mapping",
                    v105,
                    v110,
                    v111,
                    v112,
                    v113,
                    v114,
                    v115,
                    v116);
                  v10 = 16;
                }
                qdf_trace_msg(
                  0x61u,
                  2u,
                  "%s: Failure to map Tx buffers for IPA(status=%d)",
                  v46,
                  v47,
                  v48,
                  v49,
                  v50,
                  v51,
                  v52,
                  v53,
                  "wlan_ipa_uc_ol_init",
                  v10,
                  v105);
                wlan_ipa_log_message(
                  (int)"wlan_ipa_uc_ol_init",
                  (int)"Failure to map Tx buffers for IPA(status=%d)",
                  v10,
                  v100,
                  v101,
                  v102,
                  v103,
                  v104,
                  v109);
LABEL_43:
                qdf_trace_msg(
                  0x61u,
                  8u,
                  "%s: failure case: free allocated resources",
                  v72,
                  v73,
                  v74,
                  v75,
                  v76,
                  v77,
                  v78,
                  v79,
                  "wlan_ipa_uc_ol_init");
                wlan_ipa_log_message(
                  (int)"wlan_ipa_uc_ol_init",
                  (int)"failure case: free allocated resources",
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  v107);
                for ( i = 0; i != 16; ++i )
                {
                  cancel_work_sync(v25);
                  if ( (unsigned int)(unsigned __int8)i - 13 <= 1 )
                  {
                    v87 = *(_QWORD *)(v25 + 72);
                    if ( v87 )
                    {
                      _qdf_mem_free(*(_QWORD *)(v87 + 8));
                      _qdf_mem_free(*(_QWORD *)(v25 + 72));
                    }
                    else
                    {
                      qdf_trace_msg(
                        0x61u,
                        2u,
                        "%s: msg list already freed for work %d",
                        v13,
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        "wlan_ipa_uc_ol_init",
                        (unsigned int)i);
                    }
                  }
                  v25 += 88;
                }
                goto LABEL_23;
              }
              v59 = *(unsigned int *)(*(_QWORD *)(a1 + 1464) + 4LL);
              v112 = v45;
              v60 = v45;
              v116 = wlan_ipa_ast_notify_cb;
              v115 = *(unsigned __int8 *)(a1 + 7456);
              v114 = *(_DWORD *)(a1 + 7460);
              v113 = *(_BYTE *)(a1 + 6986);
              v111 = v55 & 1;
              v105 = a1 + 3712;
              v110 = a1 + 3716;
              if ( *(v58 - 1) != -208635689 )
                __break(0x8229u);
              v56 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 (__fastcall *)(), __int64 (__fastcall *)(), __int64 (__fastcall *)(), __int64, __int64, __int64))v58)(
                      v54,
                      0,
                      wlan_ipa_i2w_cb,
                      wlan_ipa_w2i_cb,
                      wlan_ipa_wdi_meter_notifier_cb,
                      v59,
                      a1,
                      1);
              _qdf_mem_free(v60);
              if ( !v56 )
                goto LABEL_50;
            }
            else
            {
              v65 = v45;
              qdf_trace_msg(0x45u, 1u, "%s invalid instance", v46, v47, v48, v49, v50, v51, v52, v53, "cdp_ipa_setup");
              _qdf_mem_free(v65);
              v56 = 16;
            }
          }
          else
          {
            v56 = 2;
          }
          qdf_trace_msg(
            0x61u,
            2u,
            "%s: Failure to setup IPA pipes (status=%d)",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "wlan_ipa_uc_ol_init",
            v56,
            v105,
            v110,
            v111,
            v112,
            v113,
            v114,
            v115,
            v116);
          wlan_ipa_log_message(
            (int)"wlan_ipa_uc_ol_init",
            (int)"Failure to setup IPA pipes (status=%d)",
            v56,
            v66,
            v67,
            v68,
            v69,
            v70,
            v106);
          if ( (**(_BYTE **)(a1 + 1464) & 0x40) != 0 )
          {
            cancel_work_sync(a1 + 7304);
            wlan_ipa_teardown_sys_pipe((_BYTE *)a1);
          }
          qdf_event_destroy(a1 + 8072, v71);
          *(_BYTE *)(a1 + 6984) = 0;
          v10 = 16;
          goto LABEL_43;
        }
      }
      else
      {
        qdf_trace_msg(0x45u, 1u, "%s invalid instance", v13, v14, v15, v16, v17, v18, v19, v20, "cdp_ipa_get_resource");
      }
      v38 = "%s: IPA UC resource alloc fail";
    }
    else
    {
      v38 = "%s: osdev null";
    }
    qdf_trace_msg(0x61u, 2u, v38, v13, v14, v15, v16, v17, v18, v19, v20, "wlan_ipa_uc_ol_init");
    v10 = 16;
LABEL_23:
    qdf_trace_msg(0x61u, 8u, "%s: exit: status=%d", v13, v14, v15, v16, v17, v18, v19, v20, "wlan_ipa_uc_ol_init", v10);
    wlan_ipa_log_message((int)"wlan_ipa_uc_ol_init", (int)"exit: status=%d", v10, v39, v40, v41, v42, v43, v105);
    return v10;
  }
  return 0;
}
