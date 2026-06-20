_QWORD *__fastcall hdd_set_wlm_host_latency_level(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *result; // x0
  _QWORD *v15; // x21
  _QWORD *v16; // x25
  int v17; // w8
  char v18; // w9
  char v19; // w11
  char v20; // w8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x20
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x8
  _DWORD *v55; // x8
  __int64 v56; // x1
  __int64 v57; // x8
  _DWORD *v58; // x8
  __int64 v59; // x1

  result = _cds_get_context(71, (__int64)"hdd_set_wlm_host_latency_level", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( result )
  {
    v15 = result;
    v16 = (_QWORD *)(a2 + 52832);
    v17 = 1 << *(_BYTE *)(*(_QWORD *)(a2 + 52832) + 8LL);
    v18 = *(_BYTE *)(a1 + 6802);
    v19 = v18 & ~(_BYTE)v17;
    v20 = v18 | v17;
    if ( (a3 & 0x10000) == 0 )
      v20 = v19;
    *(_BYTE *)(a1 + 6802) = v20;
    wlan_hdd_set_pm_qos_request(a1, v20 != 0);
    ucfg_dp_set_high_bus_bw_request(*(_QWORD *)a1, *(_BYTE *)(*v16 + 8LL), (a3 & 0x20000) != 0);
    result = (_QWORD *)_hdd_objmgr_get_vdev_by_user(*v16, 97, "hdd_set_wlm_host_latency_level");
    if ( result )
    {
      v29 = (__int64)result;
      ucfg_dp_runtime_disable_rx_thread((__int64)result, a3 & 1, v21, v22, v23, v24, v25, v26, v27, v28);
      ucfg_dp_fisa_route_to_latency_sensitive_reo(v29, (a3 & 2) != 0, v30, v31, v32, v33, v34, v35, v36, v37);
      ucfg_dp_runtime_disable_rx_fisa_aggr(v29, (a3 & 4) != 0, v38, v39, v40, v41, v42, v43, v44, v45);
      if ( (a3 & 0x100) != 0 )
      {
        if ( (*(_BYTE *)(a2 + 71188) & 1) == 0 )
        {
          if ( *v15 && (v57 = *(_QWORD *)(*v15 + 64LL)) != 0 )
          {
            v58 = *(_DWORD **)(v57 + 256);
            if ( v58 )
            {
              v59 = *(unsigned __int8 *)(*v16 + 8LL);
              if ( *(v58 - 1) != 1845374433 )
                __break(0x8228u);
              ((void (__fastcall *)(_QWORD *, __int64, _QWORD))v58)(v15, v59, 0);
            }
          }
          else
          {
            qdf_trace_msg(
              0x89u,
              8u,
              "%s: Invalid Instance:",
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              "cdp_vdev_inform_ll_conn");
          }
          LOBYTE(v55) = 1;
          goto LABEL_24;
        }
      }
      else if ( *(_BYTE *)(a2 + 71188) )
      {
        if ( *v15 && (v54 = *(_QWORD *)(*v15 + 64LL)) != 0 )
        {
          v55 = *(_DWORD **)(v54 + 256);
          if ( !v55 )
          {
LABEL_24:
            *(_BYTE *)(a2 + 71188) = (_BYTE)v55;
            goto LABEL_25;
          }
          v56 = *(unsigned __int8 *)(*v16 + 8LL);
          if ( *(v55 - 1) != 1845374433 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, __int64, __int64))v55)(v15, v56, 1);
        }
        else
        {
          qdf_trace_msg(
            0x89u,
            8u,
            "%s: Invalid Instance:",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "cdp_vdev_inform_ll_conn");
        }
        LOBYTE(v55) = 0;
        goto LABEL_24;
      }
LABEL_25:
      ucfg_dp_rx_aggr_dis_req(v29, 0, *(_WORD *)(a2 + 52098) != 0, v46, v47, v48, v49, v50, v51, v52, v53);
      return (_QWORD *)_hdd_objmgr_put_vdev_by_user(v29, 97, "hdd_set_wlm_host_latency_level");
    }
  }
  return result;
}
