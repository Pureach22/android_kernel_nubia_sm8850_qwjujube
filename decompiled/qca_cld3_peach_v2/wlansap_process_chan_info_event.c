__int64 __fastcall wlansap_process_chan_info_event(
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
  unsigned int v11; // w22
  _QWORD *context; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned __int8 v32; // w0
  __int64 v33; // x8
  __int64 v34; // x2
  const char *v35; // x2
  unsigned int v36; // w1
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x23
  unsigned __int64 time_of_the_day_ms; // x0
  __int64 v47; // x8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  _QWORD *v56; // x22
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int chan_enum_for_freq; // w0
  unsigned int v66; // w2
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x0

  v11 = *(_DWORD *)(a2 + 360);
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v35 = "%s: Invalid MAC context";
    v36 = 2;
    return qdf_trace_msg(0x39u, v36, v35, v14, v15, v16, v17, v18, v19, v20, v21, "wlansap_process_chan_info_event");
  }
  v22 = (__int64)context;
  result = hdd_sap_is_acs_in_progress(*(_QWORD *)(a1 + 16), v14, v15, v16, v17, v18, v19, v20, v21);
  if ( (result & 1) == 0 || *(_DWORD *)(a1 + 728) )
    return result;
  if ( !*(_QWORD *)(a1 + 1544) )
  {
    v35 = "%s: acs_cfg is null";
    v36 = 8;
    return qdf_trace_msg(0x39u, v36, v35, v14, v15, v16, v17, v18, v19, v20, v21, "wlansap_process_chan_info_event");
  }
  result = wlan_reg_is_24ghz_ch_freq(v11);
  if ( (result & 1) == 0
    || *(_BYTE *)(*(_QWORD *)(a1 + 1544) + 610LL) == 1
    && (v32 = wlan_reg_freq_to_chan(*(_QWORD *)(v22 + 21632), v11, v24, v25, v26, v27, v28, v29, v30, v31),
        result = sap_is_ch_non_overlap(a1, v32),
        (result & 1) != 0) )
  {
    result = wlan_reg_get_channel_state_for_pwrmode(
               *(_QWORD *)(v22 + 21632),
               *(_DWORD *)(a2 + 360),
               0,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               v31);
    if ( (_DWORD)result == 3 && (*(_BYTE *)(a1 + 1778) & 1) == 0 )
    {
      v33 = *(_QWORD *)(a1 + 1544);
      if ( *(_BYTE *)(v33 + 24) )
      {
        result = wlan_reg_is_same_band_freqs(
                   *(_DWORD *)(*(_QWORD *)(v33 + 16) + 4LL * ((unsigned int)*(unsigned __int8 *)(v33 + 24) - 1)),
                   *(_DWORD *)(a2 + 360));
        if ( (result & 1) == 0 )
          return result;
        v33 = *(_QWORD *)(a1 + 1544);
        v34 = *(unsigned __int8 *)(v33 + 24);
      }
      else
      {
        v34 = 0;
      }
      result = wlansap_is_channel_present_in_acs_list(*(unsigned int *)(a2 + 360), *(_QWORD *)(v33 + 16), v34);
      if ( (result & 1) != 0 )
      {
        if ( !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 360))
          || (result = wlan_reg_is_6ghz_psc_chan_freq(*(_DWORD *)(a2 + 360), v37, v38, v39, v40, v41, v42, v43, v44),
              (result & 1) != 0) )
        {
          result = policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(v22 + 21624), *(unsigned __int8 *)(a1 + 12));
          if ( (result & 1) == 0 || *(_BYTE *)(*(_QWORD *)(a1 + 1544) + 610LL) == 1 )
          {
            result = _qdf_mem_malloc(0x2D8u, "wlansap_process_chan_info_event", 1813);
            if ( result )
            {
              v45 = result;
              time_of_the_day_ms = qdf_get_time_of_the_day_ms();
              v47 = *(_QWORD *)(a1 + 1552);
              *(_WORD *)(v45 + 18) = 1;
              *(_QWORD *)(v45 + 8) = time_of_the_day_ms - v47;
              *(_DWORD *)(v45 + 268) = *(_DWORD *)(a2 + 360);
              v56 = ucfg_scan_get_result(*(_QWORD *)(v22 + 21632), v45, v48, v49, v50, v51, v52, v53, v54, v55);
              result = _qdf_mem_free(v45);
              if ( v56 )
              {
                if ( !*((_DWORD *)v56 + 4)
                  && (policy_mgr_is_sap_freq_allowed(
                        *(_QWORD *)(v22 + 21624),
                        *(_DWORD *)(*(_QWORD *)(a1 + 16) + 16LL),
                        *(_DWORD *)(a2 + 360))
                    & 1) != 0
                  && (wlan_reg_is_vlp_depriority_freq(*(_QWORD *)(v22 + 21632), *(_DWORD *)(a2 + 360)) & 1) == 0 )
                {
                  if ( !*(_WORD *)(*(_QWORD *)(a1 + 1544) + 42LL) )
                    goto LABEL_32;
                  chan_enum_for_freq = wlan_reg_get_chan_enum_for_freq(
                                         *(_DWORD *)(a2 + 360),
                                         v57,
                                         v58,
                                         v59,
                                         v60,
                                         v61,
                                         v62,
                                         v63,
                                         v64);
                  if ( chan_enum_for_freq <= 0x65 )
                    *(_BYTE *)(a1 + chan_enum_for_freq + 1779) = 1;
                  if ( (is_freq_allowed_for_sap(*(_QWORD *)(v22 + 21632), a1, *(unsigned int *)(a2 + 360)) & 1) != 0 )
                  {
LABEL_32:
                    qdf_trace_msg(
                      0x39u,
                      8u,
                      "%s: ACS Best channel %d as no beacon/probe rsp found\n",
                      v57,
                      v58,
                      v59,
                      v60,
                      v61,
                      v62,
                      v63,
                      v64,
                      "wlansap_process_chan_info_event",
                      *(unsigned int *)(a2 + 360));
                    v66 = *(unsigned __int8 *)(a1 + 12);
                    *(_BYTE *)(a1 + 1778) = 1;
                    wlan_abort_scan(*(_QWORD *)(v22 + 21632), -1, v66, 0xFFFFFFFF, 0);
                    wlansap_set_acs_ch_freq(v22, a1, *(unsigned int *)(a2 + 360));
                    *(_DWORD *)(*(_QWORD *)(a1 + 1544) + 564LL) = *(_DWORD *)(a2 + 360);
                    sap_config_acs_result(v22, a1, *(_DWORD *)(*(_QWORD *)(a1 + 1544) + 568LL));
                    v75 = *(_QWORD *)(a1 + 1488);
                    *(_QWORD *)(a1 + 1616) = 21;
                    if ( v75 )
                    {
                      _qdf_mem_free(v75);
                      *(_QWORD *)(a1 + 1488) = 0;
                      *(_BYTE *)(a1 + 1496) = 0;
                    }
                    sap_hdd_signal_event_handler(a1, v67, v68, v69, v70, v71, v72, v73, v74);
                  }
                }
                return ucfg_scan_purge_results((__int64)v56, v57, v58, v59, v60, v61, v62, v63, v64);
              }
            }
          }
        }
      }
    }
  }
  return result;
}
