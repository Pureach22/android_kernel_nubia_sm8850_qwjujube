__int64 __fastcall ipa3_handle_ipa_wlan_opt_dp_wlan_ctrl_pkt_rcvd_req(__int64 a1, __int64 *a2, __int64 a3, int *a4)
{
  __int64 v8; // x9
  int v9; // w11
  __int64 v10; // x10
  __int64 ipc_logbuf; // x0
  __int64 v12; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v14; // x0
  int v15; // w5
  __int64 v16; // x7
  __int64 result; // x0
  int v18; // [xsp+4h] [xbp-10Ch] BYREF
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v20; // [xsp+10h] [xbp-100h]
  __int64 v21; // [xsp+18h] [xbp-F8h]
  __int64 v22; // [xsp+20h] [xbp-F0h]
  __int64 v23; // [xsp+28h] [xbp-E8h]
  __int64 v24; // [xsp+30h] [xbp-E0h]
  __int64 v25; // [xsp+38h] [xbp-D8h]
  __int64 v26; // [xsp+40h] [xbp-D0h]
  __int64 v27; // [xsp+48h] [xbp-C8h]
  __int64 v28; // [xsp+50h] [xbp-C0h]
  __int64 v29; // [xsp+58h] [xbp-B8h]
  __int64 v30; // [xsp+60h] [xbp-B0h]
  __int64 v31; // [xsp+68h] [xbp-A8h]
  __int64 v32; // [xsp+70h] [xbp-A0h]
  __int64 v33; // [xsp+78h] [xbp-98h]
  __int64 v34; // [xsp+80h] [xbp-90h]
  __int64 v35; // [xsp+88h] [xbp-88h]
  __int64 v36; // [xsp+90h] [xbp-80h]
  __int64 v37; // [xsp+98h] [xbp-78h]
  __int64 v38; // [xsp+A0h] [xbp-70h]
  __int64 v39; // [xsp+A8h] [xbp-68h]
  __int64 v40; // [xsp+B0h] [xbp-60h]
  __int64 v41; // [xsp+B8h] [xbp-58h]
  __int64 v42; // [xsp+C0h] [xbp-50h]
  __int64 v43; // [xsp+C8h] [xbp-48h]
  __int64 v44; // [xsp+D0h] [xbp-40h]
  __int64 v45; // [xsp+D8h] [xbp-38h]
  __int64 v46; // [xsp+E0h] [xbp-30h]
  __int64 v47; // [xsp+E8h] [xbp-28h]
  __int64 v48; // [xsp+F0h] [xbp-20h]
  __int64 v49; // [xsp+F8h] [xbp-18h]
  __int64 v50; // [xsp+100h] [xbp-10h]
  __int64 v51; // [xsp+108h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *a2;
  v9 = *((_DWORD *)a2 + 2);
  v18 = 0;
  v10 = ipa3_qmi_ctx + 28864;
  *(_QWORD *)(ipa3_qmi_ctx + 28864) = v8;
  *(_DWORD *)(v10 + 8) = v9;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v12 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v12,
                   "ipa-wan %s:%d wlan_opt_dp_wlan_ctrl_pkt_rcvd_req: packet_count %d\n",
                   "ipa3_handle_ipa_wlan_opt_dp_wlan_ctrl_pkt_rcvd_req",
                   1949,
                   *a4);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v14 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(
      v14,
      "ipa-wan %s:%d wlan_opt_dp_wlan_ctrl_pkt_rcvd_req: packet_count %d\n",
      "ipa3_handle_ipa_wlan_opt_dp_wlan_ctrl_pkt_rcvd_req",
      1949,
      *a4);
  }
  v15 = *a4;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  *(_QWORD *)s = 0;
  v20 = 0;
  snprintf(
    s,
    0x100u,
    "ipa-event-log %s:%d wlan_opt_dp_wlan_ctrl_pkt_rcvd_req: packet_count %d\n",
    "ipa3_handle_ipa_wlan_opt_dp_wlan_ctrl_pkt_rcvd_req",
    1951,
    v15);
  ipa3_send_opt_log_msg(s);
  ipa_wdi_opt_dpath_wlan_ctrl_pkt_rcvd_req(a4);
  result = qmi_send_response(a1, a2, a3, 79, 7, &ipa_wlan_opt_dp_wlan_ctrl_pkt_rcvd_resp_msg_data_v01_ei, &v18, v16);
  _ReadStatusReg(SP_EL0);
  return result;
}
