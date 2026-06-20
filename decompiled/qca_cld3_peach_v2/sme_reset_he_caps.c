__int64 __fastcall sme_reset_he_caps(
        __int64 a1,
        unsigned int a2,
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
  __int64 v13; // x8
  __int64 v14; // x11
  _QWORD *v15; // x10
  __int64 v16; // x12
  int v17; // w9
  __int64 v18; // x11
  __int64 v19; // x12
  __int64 v20; // x9
  __int64 v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x22
  __int64 values; // x0
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x8
  __int64 v51; // x0
  __int64 result; // x0
  __int64 v53; // x4
  const char *v54; // x2
  __int64 v55; // [xsp+0h] [xbp-10h] BYREF
  __int64 v56; // [xsp+8h] [xbp-8h]

  v10 = (unsigned __int8)a2;
  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = 29;
  if ( (unsigned __int8)a2 > 5u || !(*(_QWORD *)(a1 + 17296) + 96LL * (unsigned __int8)a2) )
  {
    v54 = "%s: No session for id %d";
    v53 = (unsigned __int8)a2;
    goto LABEL_14;
  }
  qdf_trace_msg(0x34u, 8u, "%s: reset HE caps", a3, a4, a5, a6, a7, a8, a9, a10, "sme_reset_he_caps", v55, v56);
  v13 = *(_QWORD *)(a1 + 8);
  v14 = *(_QWORD *)(v13 + 1408);
  v15 = (_QWORD *)(v13 + 1308);
  v16 = *(_QWORD *)(v13 + 1416);
  *(_QWORD *)(v13 + 1340) = *(_QWORD *)(v13 + 1400);
  *(_QWORD *)(v13 + 1348) = v14;
  v17 = *(_DWORD *)(v13 + 1424);
  v18 = *(_QWORD *)(v13 + 1368);
  *(_QWORD *)(v13 + 1356) = v16;
  v19 = *(_QWORD *)(v13 + 1384);
  *(_DWORD *)(v13 + 1364) = v17;
  v20 = *(_QWORD *)(v13 + 1376);
  v21 = *(_QWORD *)(v13 + 1392);
  *v15 = v18;
  v15[1] = v20;
  v15[2] = v19;
  v15[3] = v21;
  csr_update_session_he_cap(a1);
  qdf_mem_copy((void *)(a1 + 21788), (const void *)(a1 + 21908), 0x3Cu);
  qdf_mem_copy((void *)(a1 + 21848), (const void *)(a1 + 21968), 0x3Cu);
  ucfg_mlme_set_channel_bonding_24ghz(*(_QWORD *)(a1 + 21624), 1);
  wlan_cm_set_check_6ghz_security(*(_QWORD *)(a1 + 21624), 1);
  if ( (unsigned int)wma_form_unit_test_cmd_and_send(v10, 77, 2, &v55) )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: prevent PM reset cmd send failed",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "sme_reset_he_caps");
  *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3756LL) = 0;
  v30 = wlan_mlme_set_enable_bcast_probe_rsp(*(_QWORD *)(a1 + 21624), 1);
  if ( v30 )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed not set enable bcast probe resp info, %d",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "sme_reset_he_caps",
      v30);
  v39 = *(_QWORD *)(a1 + 21624);
  values = cfg_psoc_get_values(v39);
  ucfg_twt_cfg_set_requestor(v39, *(unsigned __int8 *)(values + 10185));
  v41 = wma_cli_set_command(v10, 108, 1, 1);
  if ( v41 )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed to set enable bcast probe resp in FW, %d",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "sme_reset_he_caps",
      v41);
  v50 = *(_QWORD *)(a1 + 8);
  *(_BYTE *)(a1 + 21783) = 0;
  *(_DWORD *)(v50 + 3504) = *(_DWORD *)(v50 + 3500);
  if ( *(_BYTE *)(a1 + 21782) )
    sme_set_cfg_disable_tx(a1, a2, 0, v42, v43, v44, v45, v46, v47, v48, v49);
  v51 = *(_QWORD *)(a1 + 21624);
  *(_BYTE *)(a1 + 21696) = 1;
  cm_roam_send_disable_config(v51, a2, 0);
  result = wlan_scan_cfg_set_scan_mode_6g(*(_QWORD *)(a1 + 21624), 2);
  if ( (_DWORD)result )
  {
    v53 = (unsigned int)result;
    v54 = "%s: Failed to set scan mode for 6 GHz, %d";
LABEL_14:
    result = qdf_trace_msg(0x34u, 2u, v54, a3, a4, a5, a6, a7, a8, a9, a10, "sme_reset_he_caps", v53, v55, v56);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
