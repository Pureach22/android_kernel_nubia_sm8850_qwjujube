__int64 __fastcall ipa3_qmi_send_wdi_opt_dpath_ep_info(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  __int64 v3; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned int v7; // w19
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 result; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  int v18; // [xsp+4h] [xbp-12Ch] BYREF
  _QWORD v19[2]; // [xsp+8h] [xbp-128h] BYREF
  _QWORD v20[2]; // [xsp+18h] [xbp-118h] BYREF
  char s[8]; // [xsp+28h] [xbp-108h] BYREF
  __int64 v22; // [xsp+30h] [xbp-100h]
  __int64 v23; // [xsp+38h] [xbp-F8h]
  __int64 v24; // [xsp+40h] [xbp-F0h]
  __int64 v25; // [xsp+48h] [xbp-E8h]
  __int64 v26; // [xsp+50h] [xbp-E0h]
  __int64 v27; // [xsp+58h] [xbp-D8h]
  __int64 v28; // [xsp+60h] [xbp-D0h]
  __int64 v29; // [xsp+68h] [xbp-C8h]
  __int64 v30; // [xsp+70h] [xbp-C0h]
  __int64 v31; // [xsp+78h] [xbp-B8h]
  __int64 v32; // [xsp+80h] [xbp-B0h]
  __int64 v33; // [xsp+88h] [xbp-A8h]
  __int64 v34; // [xsp+90h] [xbp-A0h]
  __int64 v35; // [xsp+98h] [xbp-98h]
  __int64 v36; // [xsp+A0h] [xbp-90h]
  __int64 v37; // [xsp+A8h] [xbp-88h]
  __int64 v38; // [xsp+B0h] [xbp-80h]
  __int64 v39; // [xsp+B8h] [xbp-78h]
  __int64 v40; // [xsp+C0h] [xbp-70h]
  __int64 v41; // [xsp+C8h] [xbp-68h]
  __int64 v42; // [xsp+D0h] [xbp-60h]
  __int64 v43; // [xsp+D8h] [xbp-58h]
  __int64 v44; // [xsp+E0h] [xbp-50h]
  __int64 v45; // [xsp+E8h] [xbp-48h]
  __int64 v46; // [xsp+F0h] [xbp-40h]
  __int64 v47; // [xsp+F8h] [xbp-38h]
  __int64 v48; // [xsp+100h] [xbp-30h]
  __int64 v49; // [xsp+108h] [xbp-28h]
  __int64 v50; // [xsp+110h] [xbp-20h]
  __int64 v51; // [xsp+118h] [xbp-18h]
  __int64 v52; // [xsp+120h] [xbp-10h]
  __int64 v53; // [xsp+128h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[1] = &ipa_wlan_opt_dp_set_wlan_per_info_req_msg_data_v01_ei;
  v19[1] = &ipa_wlan_opt_dp_set_wlan_per_info_resp_msg_data_v01_ei;
  v18 = 0;
  v20[0] = 77;
  v19[0] = 77;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v3 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v3,
                   "ipa-wan %s:%d Sending QMI_IPA_WLAN_OPT_DATAPATH_SET_WLAN_PER_INFO_REQ_V01\n",
                   "ipa3_qmi_send_wdi_opt_dpath_ep_info",
                   3023);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v5 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(
      v5,
      "ipa-wan %s:%d Sending QMI_IPA_WLAN_OPT_DATAPATH_SET_WLAN_PER_INFO_REQ_V01\n",
      "ipa3_qmi_send_wdi_opt_dpath_ep_info",
      3023);
  }
  if ( ipa_q6_clnt )
  {
    v6 = ipa3_qmi_send_req_wait(ipa_q6_clnt, (unsigned __int16 *)v20, a1, (__int64)v19, (__int64)&v18, 0x1388u);
    v7 = v6;
    if ( (v6 & 0x80000000) != 0 )
    {
      v13 = printk(&unk_3CCE82, "ipa3_qmi_send_wdi_opt_dpath_ep_info");
      v14 = ipa3_get_ipc_logbuf(v13);
      if ( v14 )
      {
        v15 = ipa3_get_ipc_logbuf(v14);
        v14 = ipc_log_string(
                v15,
                "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
                "ipa3_qmi_send_wdi_opt_dpath_ep_info",
                3035,
                49,
                v7);
      }
      v16 = ipa3_get_ipc_logbuf_low(v14);
      if ( v16 )
      {
        v17 = ipa3_get_ipc_logbuf_low(v16);
        ipc_log_string(
          v17,
          "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
          "ipa3_qmi_send_wdi_opt_dpath_ep_info",
          3035,
          49,
          v7);
      }
      v51 = 0;
      v52 = 0;
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
      *(_QWORD *)s = 0;
      v22 = 0;
      snprintf(
        s,
        0x100u,
        "ipa-event-log %s:%d QMI send Req %d failed, rc= %d\n",
        "ipa3_qmi_send_wdi_opt_dpath_ep_info",
        3038,
        49,
        v7);
      ipa3_send_opt_log_msg(s);
      result = v7;
    }
    else
    {
      v8 = ipa3_get_ipc_logbuf(v6);
      if ( v8 )
      {
        v9 = ipa3_get_ipc_logbuf(v8);
        v8 = ipc_log_string(
               v9,
               "ipa-wan %s:%d QMI_IPA_WLAN_OPT_DATAPATH_SET_WLAN_PER_INFO_RESP_V01 received\n",
               "ipa3_qmi_send_wdi_opt_dpath_ep_info",
               3042);
      }
      v10 = ipa3_get_ipc_logbuf_low(v8);
      if ( v10 )
      {
        v11 = ipa3_get_ipc_logbuf_low(v10);
        ipc_log_string(
          v11,
          "ipa-wan %s:%d QMI_IPA_WLAN_OPT_DATAPATH_SET_WLAN_PER_INFO_RESP_V01 received\n",
          "ipa3_qmi_send_wdi_opt_dpath_ep_info",
          3042);
      }
      result = ipa3_check_qmi_response(
                 v7,
                 77,
                 (unsigned __int16)v18,
                 HIWORD(v18),
                 "ipa_wlan_opt_dp_set_wlan_per_info_req_msg_v01");
    }
  }
  else
  {
    result = 4294967186LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
