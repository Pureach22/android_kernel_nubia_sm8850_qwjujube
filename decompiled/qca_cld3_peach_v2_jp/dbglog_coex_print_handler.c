__int64 __fastcall dbglog_coex_print_handler(
        unsigned int a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned __int16 a5,
        unsigned int *a6)
{
  char *v11; // x20
  __int64 result; // x0
  int v13; // w24
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x10
  __int64 v17; // x8
  char **v18; // x9
  __int64 v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  char v28; // w8
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x7
  unsigned int v33; // w8
  const char *v34; // x2
  __int64 v35; // x8
  char **v36; // x9
  const char *v37; // x2
  __int64 v38; // x8
  __int64 v39; // x9
  __int64 v40; // x4
  __int64 v41; // x5
  __int64 v42; // x6
  __int64 v43; // x8
  __int64 v44; // x9
  __int64 v45; // x8
  __int64 v46; // x8
  __int64 v47; // x9
  __int64 v48; // x10
  __int64 v49; // x11
  unsigned int v50; // w5
  const char *v51; // x4
  const char *v52; // x6
  __int64 v53; // x8
  __int64 v54; // x9
  __int64 v55; // x0
  __int64 v56; // x1
  char *v57; // x3
  __int64 v58; // x8
  __int64 v59; // x9
  __int64 v60; // x10
  __int64 v61; // x8
  __int64 v62; // x9
  __int64 v63; // x8
  __int64 v64; // x9
  unsigned __int8 v65; // w24
  unsigned int v66; // [xsp+0h] [xbp-10h]

  if ( a1 > 0x9C || a3 > 0xFF )
    goto LABEL_6;
  if ( (((unsigned __int64)a1 << 11) | (8LL * a3)) >> 11 > 0x9C )
  {
    __break(1u);
    return dbglog_beacon_print_handler();
  }
  v11 = (&DBG_MSG_ARR[256 * (unsigned __int64)a1])[a3];
  if ( !v11 || !*v11 )
  {
LABEL_6:
    v11 = dbglog_get_msg_unknown_str;
    snprintf(dbglog_get_msg_unknown_str, 0x40u, "UNKNOWN %u:%u", a1, a3);
  }
  result = 0;
  switch ( a3 )
  {
    case 1u:
    case 2u:
    case 3u:
    case 4u:
    case 5u:
    case 6u:
    case 7u:
    case 8u:
    case 9u:
    case 0xAu:
    case 0xB1u:
    case 0xB2u:
    case 0xB3u:
    case 0xB4u:
    case 0xB5u:
    case 0xB6u:
      if ( !a5 )
        return 0;
      dbglog_printf_no_line_break(a4, a2, "%s: %u", v11, *a6);
      if ( a5 != 1 )
      {
        v13 = 1;
        do
          dbglog_printf_no_line_break(a4, a2, "%u", a6[(unsigned __int8)v13++]);
        while ( (unsigned __int8)v13 < (unsigned int)a5 );
      }
      dbglog_printf_no_line_break(a4, a2, "\n");
      return 1;
    case 0x15u:
      if ( a5 < 4u )
        return 0;
      v40 = a6[1];
      v41 = a6[2];
      v42 = a6[3];
      if ( *a6 )
        dbglog_printf(a4, a2, "%s Alloc: LocalID(%u), RemoteID(%u), MinFreeLocalID(%u)", v11, v40, v41, v42);
      else
        dbglog_printf(a4, a2, "%s Dealloc: LocalID(%u), RemoteID(%u), MinFreeLocalID(%u)", v11, v40, v41, v42);
      return 1;
    case 0x28u:
      if ( a5 < 5u )
        return 0;
      v38 = a6[3];
      if ( (unsigned int)v38 > 1 )
        return 0;
      v39 = a6[4];
      if ( (unsigned int)v39 > 0xE )
        return 0;
      dbglog_printf(
        a4,
        a2,
        "%s: %uMhz->%uMhz, WlanSysState(0x%x), CurrBand(%s), PhyMode(%s)",
        v11,
        *a6,
        a6[1],
        a6[2],
        dbglog_coex_print_handler_wlan_curr_band[v38],
        dbglog_coex_print_handler_wlan_phymode[v39]);
      return 1;
    case 0x29u:
      if ( a5 < 3u )
        return 0;
      v43 = a6[1];
      if ( (unsigned int)v43 > 2 )
        return 0;
      v44 = a6[2];
      if ( (unsigned int)v44 > 2 )
        return 0;
      dbglog_printf(
        a4,
        a2,
        "%s: Event(0x%x) %s->%s",
        v11,
        *a6,
        dbglog_coex_print_handler_wlan_power_state[v43],
        dbglog_coex_print_handler_wlan_power_state[v44]);
      return 1;
    case 0x68u:
      if ( !a5 )
        return 0;
      v17 = *a6;
      if ( (unsigned int)v17 > 5 )
        return 0;
      v18 = dbglog_coex_print_handler_coex_bt_scheme;
      goto LABEL_42;
    case 0x6Bu:
      if ( a5 == 1 )
      {
        v17 = *a6;
        if ( (unsigned int)v17 <= 8 )
        {
          v18 = dbglog_coex_print_handler_coex_system_status;
LABEL_42:
          dbglog_printf(a4, a2, "%s: %s", v11, v18[v17]);
          return 1;
        }
        return 0;
      }
      if ( a5 < 5u )
        return 0;
      v63 = *a6;
      if ( (unsigned int)v63 > 8 )
        return 0;
      v64 = a6[2];
      if ( (unsigned int)v64 > 8 )
        return 0;
      dbglog_printf(
        a4,
        a2,
        "%s: %s, WlanSysState(0x%x), %s, NumChains(%u), AggrLimit(%u)",
        v11,
        dbglog_coex_print_handler_coex_system_status[v63],
        a6[1],
        dbglog_coex_print_handler_coex_trf_mgmt_type[v64],
        a6[3],
        a6[4]);
      return 1;
    case 0x6Eu:
      if ( a5 < 5u )
        return 0;
      v29 = *a6;
      v30 = a6[1];
      v31 = a6[2];
      v32 = a6[3];
      v33 = a6[4];
      v34 = "%s: BtIntvlCnt(%u), Duration(%u), Weight(%u), BaseIdleOverride(%u), WeightMat[0](0x%x), ";
      goto LABEL_78;
    case 0x6Fu:
      if ( a5 < 5u )
        return 0;
      v29 = *a6;
      v30 = a6[1];
      v31 = a6[2];
      v32 = a6[3];
      v33 = a6[4];
      v34 = "%s: WlanIntvlCnt(%u), Duration(%u), Weight(%u), BaseIdleOverride(%u), WeightMat[0](0x%x)";
      goto LABEL_78;
    case 0x9Bu:
      if ( a5 < 5u )
        return 0;
      v46 = *a6;
      if ( (unsigned int)v46 > 4 )
        return 0;
      v47 = a6[2];
      if ( (unsigned int)v47 > 8 )
        return 0;
      v48 = a6[3];
      if ( (unsigned int)v48 > 3 )
        return 0;
      v49 = a6[4];
      if ( (unsigned int)v49 > 3 )
        return 0;
      v50 = a6[1];
      v51 = dbglog_coex_print_handler_coex_sched_req[v46];
      v52 = dbglog_coex_print_handler_coex_trf_mgmt_type[v47];
      if ( v50 == -1 )
        dbglog_printf(
          a4,
          a2,
          "%s: %s, DETERMINE_DURATION, %s, %s, %s",
          v11,
          v51,
          v52,
          dbglog_coex_print_handler_wlan_rx_xput_status[v48],
          dbglog_coex_print_handler_wlan_rssi_type[v49]);
      else
        dbglog_printf(
          a4,
          a2,
          "%s: %s, IntvlDur(%u), %s, %s, %s",
          v11,
          v51,
          v50,
          v52,
          dbglog_coex_print_handler_wlan_rx_xput_status[v48],
          dbglog_coex_print_handler_wlan_rssi_type[v49]);
      return 1;
    case 0x9Cu:
      if ( a5 < 5u )
        return 0;
      v58 = *a6;
      if ( (unsigned int)v58 > 4 )
        return 0;
      v59 = a6[1];
      if ( (unsigned int)v59 > 8 )
        return 0;
      v60 = a6[2];
      if ( (unsigned int)v60 > 8 )
        return 0;
      dbglog_printf(
        a4,
        a2,
        "%s: %s, %s, %s, CoexMgrPolicy(%u), IdleOverride(%u)",
        v11,
        dbglog_coex_print_handler_coex_sched_req[v58],
        dbglog_coex_print_handler_coex_trf_mgmt_type[v59],
        dbglog_coex_print_handler_coex_trf_mgmt_type[v60],
        a6[3],
        a6[4]);
      return 1;
    case 0xA0u:
      if ( a5 < 5u )
        return 0;
      v45 = a6[4];
      if ( (unsigned int)v45 > 2 )
        return 0;
      dbglog_printf(
        a4,
        a2,
        "%s: NumUnderThreshPeers(%u), MinDirectRate(%u), LastRateSample(%u), DeltaT(%u), %s",
        v11,
        *a6,
        a6[1],
        a6[2],
        a6[3],
        dbglog_coex_print_handler_wal_peer_rx_rate_stats_event_sent[v45]);
      return 1;
    case 0xA8u:
      if ( a5 < 4u )
        return 0;
      v29 = *a6;
      v30 = a6[1];
      v31 = a6[2];
      v32 = a6[3];
      v34 = "%s: WlanPostPauseIntvlCnt(%u), XputMonitorActiveNum(%u), Duration(%u), Weight(%u)";
      goto LABEL_101;
    case 0xA9u:
      if ( a5 < 5u )
        return 0;
      v35 = *a6;
      if ( (unsigned int)v35 > 6 )
        return 0;
      v36 = dbglog_coex_print_handler_coex_sched_type;
      v37 = "%s: %s, AllocatedBtIntvls(%u), BtIntvlCnt(%u), AllocatedWlanIntvls(%u), WlanIntvlCnt(%u)";
      goto LABEL_36;
    case 0xAAu:
      if ( a5 < 3u )
        return 0;
      dbglog_printf(a4, a2, "%s: IntvlLength(%u), BtDuration(%u), WlanDuration(%u)", v11, *a6, a6[1], a6[2]);
      return 1;
    case 0xABu:
      if ( a5 < 5u )
        return 0;
      v53 = *a6;
      if ( (unsigned int)v53 > 6 )
        return 0;
      v54 = a6[1];
      if ( (unsigned int)v54 > 6 )
        return 0;
      dbglog_printf(
        a4,
        a2,
        "%s: %s, %s, Dur(%u), BtTriggerRecvd(%u), PspWlanCritical(%u)",
        v11,
        dbglog_coex_print_handler_coex_sched_type[v53],
        dbglog_coex_print_handler_wlan_weight[v54],
        a6[2],
        a6[3],
        a6[4]);
      return 1;
    case 0xAEu:
      if ( a5 < 5u )
        return 0;
      v61 = a6[1];
      if ( (unsigned int)v61 > 3 )
        return 0;
      v62 = a6[4];
      if ( (unsigned int)v62 > 3 )
        return 0;
      dbglog_printf(
        a4,
        a2,
        "%s: WlanRxCritical(%u), %s, MinDirectRxRate(%u), MonitorActiveNum(%u), %s",
        v11,
        *a6,
        dbglog_coex_print_handler_wlan_rx_xput_status[v61],
        a6[2],
        a6[3],
        dbglog_coex_print_handler_wlan_rssi_type[v62]);
      return 1;
    case 0xB9u:
      if ( a5 < 5u )
        return 0;
      v29 = *a6;
      v30 = a6[1];
      v31 = a6[2];
      v32 = a6[3];
      v33 = a6[4];
      v34 = "%s: ApResp0(%u), ApResp1(%u), ApResp2(%u), ApResp3(%u), ApResp4(%u)";
      goto LABEL_78;
    case 0xBAu:
      if ( a5 < 5u )
        return 0;
      v29 = *a6;
      v30 = a6[1];
      v31 = a6[2];
      v32 = a6[3];
      v33 = a6[4];
      v34 = "%s: PsPollSpecEna(%u), Count(%u), NextTS(%u), AllowSpecPsPollTx(%u), Intvl(%u)";
      goto LABEL_78;
    case 0xBBu:
      if ( a5 < 5u )
        return 0;
      v29 = *a6;
      v30 = a6[1];
      v31 = a6[2];
      v32 = a6[3];
      v33 = a6[4];
      v34 = "%s: T2NonWlan(%u), CoexSchedulerEndTS(%u), MoreData(%u), PSPRespExpectedTS(%u), NonWlanIdleT(%u)";
      goto LABEL_78;
    case 0xBDu:
      if ( a5 < 5u )
        return 0;
      v30 = a6[1];
      v31 = a6[3];
      v32 = a6[4];
      v29 = *a6;
      if ( a6[2] )
        v34 = "%s: RsExpectedTS(%u), RespActualTS(%u), Overrun, RsOverrunT(%u), RsRxDur(%u)";
      else
        v34 = "%s: RsExpectedTS(%u), RespActualTS(%u), Underrun, RsUnderrunT(%u), RsRxDur(%u)";
      goto LABEL_101;
    case 0xC2u:
      if ( a5 < 5u )
        return 0;
      v14 = *a6;
      if ( (unsigned int)v14 > 0x16 )
        return 0;
      v15 = a6[1];
      if ( (unsigned int)v15 > 5 )
        return 0;
      v16 = a6[3];
      if ( (unsigned int)v16 > 1 )
        return 0;
      dbglog_printf(
        a4,
        a2,
        "%s: %s, %s, PsPollAvg(%u), %s, CurrT(%u)",
        v11,
        dbglog_coex_print_handler_wlan_psp_stimulus[v14],
        dbglog_coex_print_handler_coex_pspoll_state[v15],
        a6[2],
        dbglog_coex_print_handler_coex_scheduler_interval[v16],
        a6[4]);
      return 1;
    case 0xC3u:
      if ( a5 < 5u )
        return 0;
      v35 = *a6;
      if ( (unsigned int)v35 > 5 )
        return 0;
      v36 = dbglog_coex_print_handler_coex_pspoll_state;
      v37 = "%s: %s, PsPollAvg(%u), EstimationOverrun(%u), EstimationUnderun(%u), NotReadyErr(%u)";
LABEL_36:
      dbglog_printf(a4, a2, v37, v11, v36[v35], a6[1], a6[2], a6[3], a6[4]);
      return 1;
    case 0xC4u:
      if ( a5 < 4u )
        return 0;
      v29 = *a6;
      v30 = a6[1];
      v31 = a6[2];
      v32 = a6[3];
      v34 = "%s: NonWlanBaseIntvl(%u), NonWlanIdleT(%u), PSPSpecIntvl(%u), ApRespTimeout(%u)";
LABEL_101:
      v55 = a4;
      v56 = a2;
      v57 = v11;
      goto LABEL_102;
    case 0xC5u:
      if ( a5 < 5u )
        return 0;
      v29 = *a6;
      v30 = a6[1];
      v31 = a6[2];
      v32 = a6[3];
      v33 = a6[4];
      v34 = "%s: DataPt(%u), Max(%u), NextApRespIndex(%u), NumOfValidDataPts(%u), PsPollAvg(%u)";
LABEL_78:
      v55 = a4;
      v56 = a2;
      v57 = v11;
      v66 = v33;
LABEL_102:
      dbglog_printf(v55, v56, v34, v57, v29, v30, v31, v32, v66);
      return 1;
    case 0xC7u:
      if ( !a5 )
        return 0;
      v19 = *a6;
      if ( (unsigned int)v19 > 8 )
        return 0;
      dbglog_printf_no_line_break(a4, a2, "%s: %s", v11, dbglog_coex_print_handler_coex_psp_error_type[v19]);
      v28 = dword_17AC4;
      if ( a5 != 1 )
      {
        v65 = 1;
        do
        {
          if ( (v28 & 4) != 0 )
          {
            qdf_trace_msg(
              0x38u,
              2u,
              "%s: , %u",
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              "dbglog_coex_print_handler",
              a6[v65]);
            v28 = dword_17AC4;
          }
          ++v65;
        }
        while ( v65 < (unsigned int)a5 );
      }
      if ( (v28 & 4) != 0 )
        qdf_trace_msg(0x38u, 2u, "%s: \n", v20, v21, v22, v23, v24, v25, v26, v27, "dbglog_coex_print_handler");
      return 1;
    default:
      return result;
  }
}
