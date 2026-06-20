__int64 __fastcall sme_process_sap_ch_width_update_rsp(
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
  __int64 active; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x20
  unsigned int v23; // w24
  unsigned int v24; // w22
  unsigned int v25; // w21
  unsigned int v26; // w23
  const char *v27; // x2
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 4) != 8 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: reason not ch_width update",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "sme_process_sap_ch_width_update_rsp");
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: ch_width update resp param is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_process_sap_ch_width_update_rsp");
  }
  active = csr_nonscan_active_ll_peek_head(a1, 1);
  if ( !active )
  {
    v27 = "%s: No cmd found in active list";
LABEL_11:
    qdf_trace_msg(0x34u, 2u, v27, v14, v15, v16, v17, v18, v19, v20, v21, "sme_process_sap_ch_width_update_rsp");
    return 16;
  }
  v22 = active;
  if ( *(_DWORD *)(active + 16) != 262151 )
  {
    v27 = "%s: Command mismatch!";
    goto LABEL_11;
  }
  v23 = *(_DWORD *)(active + 40);
  v24 = *(_DWORD *)(active + 48);
  v25 = *(unsigned __int8 *)(active + 44);
  if ( a2 )
    v26 = *(_DWORD *)(a2 + 8);
  else
    v26 = 2;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: vdev %d reason %d status %d cm_id 0x%x",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "sme_process_sap_ch_width_update_rsp",
    *(unsigned __int8 *)(active + 44),
    v23,
    v26,
    v24);
  if ( v23 == 14 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Continue connect/reassoc on vdev %d reason %d status %d cm_id 0x%x",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "sme_process_sap_ch_width_update_rsp",
      v25,
      14,
      v26,
      v24);
    wlan_cm_handle_hw_mode_change_resp(*(_QWORD *)(a1 + 21560), v25, v24, v26);
  }
  else if ( v23 == 7 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Continue channel switch for STA on vdev %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "sme_process_sap_ch_width_update_rsp",
      v25);
    csr_sta_continue_csa(a1, v25);
  }
  policy_mgr_set_connection_update(*(_QWORD *)(a1 + 21552));
  if ( (csr_nonscan_active_ll_remove_entry(a1, v22, 1) & 1) != 0 )
    csr_release_command(a1, v22);
  return 0;
}
