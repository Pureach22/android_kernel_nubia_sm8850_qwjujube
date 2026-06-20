__int64 __fastcall show_device_power_stats(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  _QWORD *context; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x20
  __int64 v40; // x0
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w22
  __int64 v51; // x8
  __int64 v52; // x19
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x21
  unsigned int v70; // w9
  int v71; // w0
  unsigned int i; // w22
  __int64 v73; // x25
  int v74; // w0
  __int64 v75[2]; // [xsp+10h] [xbp-10h] BYREF

  v75[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"show_device_power_stats", a1, a2, a3, a4, a5, a6, a7, a8);
  v75[0] = 0;
  LODWORD(result) = _wlan_hdd_validate_context(
                      (__int64)context,
                      (__int64)"show_device_power_stats",
                      v13,
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20);
  if ( (_DWORD)result
    || (LODWORD(result) = _osif_psoc_sync_op_start(context[12], v75, (__int64)"show_device_power_stats"), (_DWORD)result) )
  {
    result = (int)result;
  }
  else
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter", v22, v23, v24, v25, v26, v27, v28, v29, "__show_device_power_stats");
    v30 = osif_request_alloc(&_show_device_power_stats_params);
    if ( v30 )
    {
      v39 = v30;
      v40 = osif_request_cookie(v30);
      v41 = sme_power_debug_stats_req(context[2], (__int64)hdd_power_debugstats_cb, v40);
      if ( v41 )
      {
        v50 = v41;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: chip power stats request failed",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "__show_device_power_stats");
        v51 = (int)qdf_status_to_os_return(v50);
      }
      else if ( (unsigned int)osif_request_wait_for_response(v39) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Target response timed out Power stats",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "__show_device_power_stats");
        sme_reset_power_debug_stats_cb(context[2]);
        v51 = -110;
      }
      else
      {
        v69 = osif_request_priv(v39);
        scnprintf(
          a11,
          4096,
          "POWER DEBUG STATS\n"
          "=================\n"
          "cumulative_sleep_time_ms: %d\n"
          "cumulative_total_on_time_ms: %d\n"
          "deep_sleep_enter_counter: %d\n"
          "last_deep_sleep_enter_tstamp_ms: %d\n"
          "debug_register_fmt: %d\n"
          "num_debug_register: %d\n",
          *(_DWORD *)v69,
          *(_DWORD *)(v69 + 4),
          *(_DWORD *)(v69 + 8),
          *(_DWORD *)(v69 + 12),
          *(_DWORD *)(v69 + 16),
          *(_DWORD *)(v69 + 20));
        v70 = *(_DWORD *)(v69 + 20);
        v51 = v71;
        if ( v70 )
        {
          for ( i = 0; i < v70; ++i )
          {
            if ( v51 == 4096 )
            {
              i = v70;
            }
            else
            {
              v73 = v51;
              scnprintf(
                a11 + v51,
                4096 - v51,
                "debug_registers[%d]: 0x%x\n",
                i,
                *(_DWORD *)(*(_QWORD *)(v69 + 24) + 4LL * (int)i));
              v70 = *(_DWORD *)(v69 + 20);
              v51 = v73 + v74;
            }
          }
        }
      }
      v52 = v51;
      osif_request_put(v39);
      qdf_trace_msg(0x33u, 8u, "%s: exit", v61, v62, v63, v64, v65, v66, v67, v68, "__show_device_power_stats");
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Request allocation failure",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "__show_device_power_stats");
      v52 = -12;
    }
    _osif_psoc_sync_op_stop(v75[0], (__int64)"show_device_power_stats");
    result = v52;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
