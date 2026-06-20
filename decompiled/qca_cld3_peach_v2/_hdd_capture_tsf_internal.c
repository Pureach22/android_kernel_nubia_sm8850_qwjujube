__int64 __fastcall hdd_capture_tsf_internal(
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
  __int64 v11; // x21
  __int64 *v12; // x20
  int v13; // w9
  int v14; // w10
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 **context; // x0
  __int64 v24; // x8
  __int64 v25; // x9
  __int64 v27; // x20
  int v28; // w2
  __int64 result; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  const char *v38; // x2
  const char *v39; // x3
  unsigned int v40; // w1
  __int64 v41; // x8
  const char *v42; // x2
  __int64 v43; // x10
  __int64 v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // [xsp+8h] [xbp-38h] BYREF
  __int64 v54; // [xsp+10h] [xbp-30h]
  __int64 v55; // [xsp+18h] [xbp-28h]
  __int64 v56; // [xsp+20h] [xbp-20h]
  __int64 v57; // [xsp+28h] [xbp-18h]
  __int64 v58; // [xsp+30h] [xbp-10h]
  __int64 v59; // [xsp+38h] [xbp-8h]

  v11 = a1 + 38936;
  v12 = (__int64 *)(a1 + 52816);
  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 39156) )
  {
    v55 = 0;
    v56 = 0;
    v53 = 0;
    v54 = 0;
    if ( *(_DWORD *)(a1 + 39156) )
    {
      qdf_mem_set(&v53, 0x20u, 0);
      v13 = *(_DWORD *)(v11 + 212);
      v14 = *(_DWORD *)(v11 + 216);
      LODWORD(v53) = *(unsigned __int8 *)(v12[2] + 8);
      HIDWORD(v53) = v13;
      LODWORD(v54) = v14;
      context = (__int64 **)_cds_get_context(
                              71,
                              (__int64)"wlan_hdd_tsf_reg_get",
                              v15,
                              v16,
                              v17,
                              v18,
                              v19,
                              v20,
                              v21,
                              v22);
      v57 = 0;
      v58 = 0;
      if ( context )
      {
        v24 = **context;
        if ( v24 && (v24 = *(_QWORD *)(v24 + 920)) != 0 )
        {
          if ( *(_DWORD *)(v24 - 4) != 1706411772 )
            __break(0x8228u);
          ((void (*)(void))v24)();
          v24 = v57;
          v25 = v58;
        }
        else
        {
          v25 = 0;
        }
        v55 = v25;
        v56 = v24;
        if ( !(v25 | v24) )
        {
          v38 = "%s: Invalid TSF report";
LABEL_27:
          v39 = "wlan_hdd_tsf_reg_process_report";
          v40 = 2;
          goto LABEL_28;
        }
        if ( a1 )
        {
          v41 = *(_QWORD *)(a1 + 24);
          if ( v41 )
          {
            if ( *(_DWORD *)(v41 + 3232) )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: device_mode is %d",
                a3,
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                "wlan_hdd_tsf_reg_process_report",
                *(unsigned int *)(a1 + 40));
              if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 38976) == 18 )
              {
                v38 = "%s: invalid timer status";
                v39 = "wlan_hdd_tsf_reg_process_report";
                goto LABEL_17;
              }
              qdf_mc_timer_stop(a1 + 38976);
              v43 = *v12;
              v44 = 1000 * v56;
              *(_QWORD *)v11 = v55;
              *(_QWORD *)(v11 + 8) = v44;
              *(_QWORD *)(v11 + 416) = v44 - v43;
              hdd_update_tsf(a1);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: vdev id=%u, tsf=%llu",
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                "wlan_hdd_tsf_reg_process_report",
                *(unsigned __int8 *)(v12[2] + 8),
                v55);
              goto LABEL_11;
            }
            v42 = "%s: TSF is not initialized";
          }
          else
          {
            v42 = "%s: invalid hdd context";
          }
        }
        else
        {
          v42 = "%s: invalid adapter";
        }
        qdf_trace_msg(0x33u, 2u, v42, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_tsf_is_initialized");
        v38 = "%s: tsf is not init, ignore tsf event";
        goto LABEL_27;
      }
      v38 = "%s: Unable to get tsf report";
    }
    else
    {
      v38 = "%s: TSF reg details are not valid!";
    }
    v39 = "hdd_capture_tsf_internal_via_reg";
LABEL_17:
    v40 = 3;
LABEL_28:
    qdf_trace_msg(0x33u, v40, v38, a3, a4, a5, a6, a7, a8, a9, a10, v39);
    result = 1;
    goto LABEL_29;
  }
  v27 = *(_QWORD *)(a1 + 24);
  v28 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL);
  result = wma_cli_set_command(v28, 4, v28, 3);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: cap tsf fail",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "hdd_capture_tsf_internal_via_wmi");
    *a2 = 4;
    *(_QWORD *)(v27 + 3240) = 0;
    *(_DWORD *)(v27 + 3236) = 0;
    qdf_mc_timer_stop(a1 + 38976);
LABEL_11:
    result = 0;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
