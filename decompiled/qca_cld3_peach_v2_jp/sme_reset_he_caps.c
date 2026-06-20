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
  __int64 v14; // x10
  __int64 v15; // x11
  __int64 v16; // x11
  __int64 v17; // x9
  __int64 v18; // x10
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x22
  __int64 values; // x0
  unsigned int v38; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 result; // x0
  __int64 v50; // x4
  const char *v51; // x2
  __int64 v52; // [xsp+0h] [xbp-10h] BYREF
  __int64 v53; // [xsp+8h] [xbp-8h]

  v10 = (unsigned __int8)a2;
  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v52 = 29;
  if ( (unsigned __int8)a2 > 5u || !(*(_QWORD *)(a1 + 17224) + 96LL * (unsigned __int8)a2) )
  {
    v51 = "%s: No session for id %d";
    v50 = (unsigned __int8)a2;
    goto LABEL_14;
  }
  qdf_trace_msg(0x34u, 8u, "%s: reset HE caps", a3, a4, a5, a6, a7, a8, a9, a10, "sme_reset_he_caps", v52, v53);
  v13 = *(_QWORD *)(a1 + 8);
  *(_DWORD *)(v13 + 1344) = *(_DWORD *)(v13 + 1404);
  v14 = *(_QWORD *)(v13 + 1388);
  *(_QWORD *)(v13 + 1320) = *(_QWORD *)(v13 + 1380);
  v15 = *(_QWORD *)(v13 + 1396);
  *(_QWORD *)(v13 + 1328) = v14;
  *(_QWORD *)(v13 + 1336) = v15;
  v16 = *(_QWORD *)(v13 + 1356);
  *(_QWORD *)(v13 + 1288) = *(_QWORD *)(v13 + 1348);
  v18 = *(_QWORD *)(v13 + 1364);
  v17 = *(_QWORD *)(v13 + 1372);
  *(_QWORD *)(v13 + 1296) = v16;
  *(_QWORD *)(v13 + 1304) = v18;
  *(_QWORD *)(v13 + 1312) = v17;
  csr_update_session_he_cap(a1);
  qdf_mem_copy((void *)(a1 + 21716), (const void *)(a1 + 21836), 0x3Cu);
  qdf_mem_copy((void *)(a1 + 21776), (const void *)(a1 + 21896), 0x3Cu);
  ucfg_mlme_set_channel_bonding_24ghz(*(_QWORD *)(a1 + 21552), 1);
  wlan_cm_set_check_6ghz_security(*(_QWORD *)(a1 + 21552), 1);
  if ( (unsigned int)wma_form_unit_test_cmd_and_send(v10, 77, 2, &v52) )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: prevent PM reset cmd send failed",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "sme_reset_he_caps");
  *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3544LL) = 0;
  v27 = wlan_mlme_set_enable_bcast_probe_rsp(*(_QWORD *)(a1 + 21552), 1);
  if ( v27 )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed not set enable bcast probe resp info, %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "sme_reset_he_caps",
      v27);
  v36 = *(_QWORD *)(a1 + 21552);
  values = cfg_psoc_get_values(v36);
  ucfg_twt_cfg_set_requestor(v36, *(unsigned __int8 *)(values + 10077));
  v38 = wma_cli_set_command(v10, 108, 1, 1);
  if ( v38 )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed to set enable bcast probe resp in FW, %d",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "sme_reset_he_caps",
      v38);
  v47 = *(_QWORD *)(a1 + 8);
  *(_BYTE *)(a1 + 21711) = 0;
  *(_DWORD *)(v47 + 3304) = *(_DWORD *)(v47 + 3300);
  if ( *(_BYTE *)(a1 + 21710) )
    sme_set_cfg_disable_tx(a1, a2, 0, v39, v40, v41, v42, v43, v44, v45, v46);
  v48 = *(_QWORD *)(a1 + 21552);
  *(_BYTE *)(a1 + 21624) = 1;
  cm_roam_send_disable_config(v48, a2, 0);
  result = wlan_scan_cfg_set_scan_mode_6g(*(_QWORD *)(a1 + 21552), 2);
  if ( (_DWORD)result )
  {
    v50 = (unsigned int)result;
    v51 = "%s: Failed to set scan mode for 6 GHz, %d";
LABEL_14:
    result = qdf_trace_msg(0x34u, 2u, v51, a3, a4, a5, a6, a7, a8, a9, a10, "sme_reset_he_caps", v50, v52, v53);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
