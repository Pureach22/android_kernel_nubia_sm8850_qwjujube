__int64 __fastcall sme_reset_eht_caps(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w20
  __int64 v11; // x21
  __int64 v13; // x8
  __int64 v14; // x11
  _QWORD *v15; // x10
  __int64 v16; // x12
  int v17; // w9
  __int64 v18; // x11
  __int64 v19; // x12
  __int64 v20; // x9
  __int64 v21; // x9
  __int64 v22; // x11
  __int64 v23; // x9
  __int64 v24; // x12
  __int64 v25; // x8
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 result; // x0
  char v52[4]; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v53; // [xsp+10h] [xbp-20h] BYREF
  int v54; // [xsp+18h] [xbp-18h]
  _QWORD v55[2]; // [xsp+20h] [xbp-10h] BYREF

  v10 = a2;
  v55[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v52[0] = 0;
  if ( a2 <= 5u && (v11 = *(_QWORD *)(a1 + 17296) + 96LL * a2) != 0 )
  {
    qdf_trace_msg(0x34u, 8u, "%s: reset EHT caps", a3, a4, a5, a6, a7, a8, a9, a10, "sme_reset_eht_caps");
    v13 = *(_QWORD *)(a1 + 8);
    v14 = *(_QWORD *)(v13 + 1664);
    v15 = (_QWORD *)(v13 + 1500);
    v16 = *(_QWORD *)(v13 + 1672);
    *(_QWORD *)(v13 + 1564) = *(_QWORD *)(v13 + 1656);
    *(_QWORD *)(v13 + 1572) = v14;
    v17 = *(_DWORD *)(v13 + 1680);
    v18 = *(_QWORD *)(v13 + 1624);
    *(_QWORD *)(v13 + 1580) = v16;
    v19 = *(_QWORD *)(v13 + 1640);
    *(_DWORD *)(v13 + 1588) = v17;
    v20 = *(_QWORD *)(v13 + 1632);
    *(_QWORD *)(v13 + 1532) = v18;
    *(_QWORD *)(v13 + 1540) = v20;
    v21 = *(_QWORD *)(v13 + 1648);
    v22 = *(_QWORD *)(v13 + 1592);
    *(_QWORD *)(v13 + 1548) = v19;
    *(_QWORD *)(v13 + 1556) = v21;
    v23 = *(_QWORD *)(v13 + 1600);
    v24 = *(_QWORD *)(v13 + 1608);
    v25 = *(_QWORD *)(v13 + 1616);
    *v15 = v22;
    v15[1] = v23;
    v15[2] = v24;
    v15[3] = v25;
    csr_update_session_eht_cap(a1, v11);
    qdf_mem_copy((void *)(a1 + 22064), (const void *)(a1 + 22248), 0x5Cu);
    qdf_mem_copy((void *)(a1 + 22156), (const void *)(a1 + 22340), 0x5Cu);
    v26 = *(_QWORD *)(a1 + 21624);
    *(_BYTE *)(a1 + 21785) = 0;
    wlan_mlme_get_24_chan_bonding_mode(v26, (_DWORD *)(a1 + 17192));
    wlan_mlme_set_sta_mlo_conn_band_bmp(*(_QWORD *)(a1 + 21624), 0x77u);
    wlan_mlme_set_sta_mlo_conn_max_num(*(_QWORD *)(a1 + 21624), 2u);
    if ( !(unsigned int)ucfg_mlme_get_bss_color_collision_det_support(*(_QWORD *)(a1 + 21624), v52) )
      ucfg_mlme_set_bss_color_collision_det_sta(*(_QWORD *)(a1 + 21624), v52[0]);
    sme_config_ba_mode_all_vdevs(a1, 0);
    v55[0] = 67;
    v54 = 1;
    v53 = 125;
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Send MCS 15 rx/tx disable to FW",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "sme_set_mcs_15_tx_rx_disable");
    if ( (unsigned int)wma_form_unit_test_cmd_and_send(v10, 10, 2, v55) )
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Failed to send MCS 15 tx disable",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "sme_set_mcs_15_tx_rx_disable");
    if ( (unsigned int)wma_form_unit_test_cmd_and_send(v10, 67, 3, &v53) )
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Failed to send MCS 15 rx disable",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "sme_set_mcs_15_tx_rx_disable");
    wlan_mlme_set_btm_abridge_flag(*(_QWORD *)(a1 + 21624), 0);
    wlan_mlme_set_eht_mld_id(*(_QWORD *)(a1 + 21624), 0);
    result = wlan_mlme_set_ext_mld_cap_supp(*(_QWORD *)(a1 + 21624), 1);
  }
  else
  {
    result = qdf_trace_msg(
               0x34u,
               2u,
               "%s: No session for id %d",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "sme_reset_eht_caps",
               a2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
