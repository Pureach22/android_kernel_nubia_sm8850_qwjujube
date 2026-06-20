__int64 __fastcall target_if_infra_cp_stats_event_handler(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 psoc_from_scn_hdl; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x24
  __int64 v32; // x8
  __int64 v33; // x23
  __int64 v34; // x21
  __int64 v35; // x22
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
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
  unsigned int v61; // w0
  unsigned int v62; // w19
  const char *v63; // x2
  __int64 result; // x0
  const char *v65; // x2
  const char *v66; // x3
  _QWORD v67[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v68; // [xsp+18h] [xbp-28h]
  __int64 v69; // [xsp+20h] [xbp-20h]
  __int64 v70; // [xsp+28h] [xbp-18h]
  int v71; // [xsp+34h] [xbp-Ch]
  __int64 v72; // [xsp+38h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v69 = 0;
  v70 = 0;
  v67[1] = 0;
  v68 = 0;
  v67[0] = 0;
  qdf_trace_msg(0x62u, 8u, "%s: Enter", a4, a5, a6, a7, a8, a9, a10, a11, "target_if_infra_cp_stats_event_handler");
  if ( a1 && a2 )
  {
    psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
    if ( psoc_from_scn_hdl )
    {
      v31 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
      if ( v31 )
      {
        if ( *(_QWORD *)(v31 + 176) )
        {
          v32 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
          if ( v32 )
          {
            v33 = *(_QWORD *)(v32 + 16);
            if ( v33 )
            {
              v34 = psoc_from_scn_hdl;
              v35 = _qdf_mem_malloc(0x38u, "target_if_infra_cp_stats_twt_event_alloc", 76);
              v68 = v35;
              if ( v35 )
              {
                v69 = _qdf_mem_malloc(0x84u, "target_if_infra_cp_stats_bmiss_event_alloc", 150);
                if ( v69 )
                {
                  v70 = _qdf_mem_malloc(0x24u, "target_if_infra_cp_stats_rrm_sta_stats_event_alloc", 116);
                  if ( v70 )
                  {
                    v71 = 0;
                    wmi_unified_extract_cp_stats_more_pending(v33);
                    wmi_unified_extract_infra_cp_stats(v33, a2, a3, v67);
                    qdf_trace_msg(
                      0x62u,
                      8u,
                      "%s: request_id %d",
                      v52,
                      v53,
                      v54,
                      v55,
                      v56,
                      v57,
                      v58,
                      v59,
                      "target_if_extract_infra_cp_stats_event",
                      HIDWORD(v67[0]));
                    v60 = *(_DWORD **)(v31 + 184);
                    if ( *(v60 - 1) != 1448499214 )
                      __break(0x8228u);
                    v61 = ((__int64 (__fastcall *)(__int64, _QWORD *))v60)(v34, v67);
                    v35 = v68;
                    v62 = v61;
                    goto LABEL_26;
                  }
LABEL_25:
                  v62 = 2;
                  qdf_trace_msg(
                    0x62u,
                    2u,
                    "%s: Alloc event mem failed",
                    v44,
                    v45,
                    v46,
                    v47,
                    v48,
                    v49,
                    v50,
                    v51,
                    "target_if_infra_cp_stats_event_handler");
LABEL_26:
                  _qdf_mem_free(v35);
                  v68 = 0;
                  _qdf_mem_free(v69);
                  v69 = 0;
                  _qdf_mem_free(v70);
                  v70 = 0;
                  result = qdf_status_to_os_return(v62);
                  goto LABEL_21;
                }
                v65 = "%s: mem alloc failed for ev.bmiss_infra_cp_stats";
                v66 = "target_if_infra_cp_stats_bmiss_event_alloc";
              }
              else
              {
                v65 = "%s: mem alloc failed for ev.twt_infra_cp_stats";
                v66 = "target_if_infra_cp_stats_twt_event_alloc";
              }
              qdf_trace_msg(0x62u, 2u, v65, v36, v37, v38, v39, v40, v41, v42, v43, v66);
              goto LABEL_25;
            }
          }
          v63 = "%s: wmi_handle is null";
          goto LABEL_19;
        }
      }
      else
      {
        qdf_trace_msg(
          0x62u,
          2u,
          "%s: rx_ops is NULL",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "target_if_cp_stats_get_rx_ops");
      }
      v63 = "%s: callback not registered";
    }
    else
    {
      v63 = "%s: null psoc";
    }
LABEL_19:
    qdf_trace_msg(0x62u, 2u, v63, v23, v24, v25, v26, v27, v28, v29, v30, "target_if_infra_cp_stats_event_handler");
    goto LABEL_20;
  }
  qdf_trace_msg(
    0x62u,
    2u,
    "%s: scn: 0x%pK, data: 0x%pK",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "target_if_infra_cp_stats_event_handler",
    a1,
    a2);
LABEL_20:
  result = 4294967274LL;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
