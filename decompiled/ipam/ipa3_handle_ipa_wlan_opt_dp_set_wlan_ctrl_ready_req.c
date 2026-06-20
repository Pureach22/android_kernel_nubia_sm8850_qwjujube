__int64 __fastcall ipa3_handle_ipa_wlan_opt_dp_set_wlan_ctrl_ready_req(__int64 a1, _DWORD *a2)
{
  __int64 ipc_logbuf; // x0
  __int64 v5; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int v9; // w19
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 result; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // [xsp+0h] [xbp-130h] BYREF
  _QWORD v25[2]; // [xsp+8h] [xbp-128h] BYREF
  _QWORD v26[2]; // [xsp+18h] [xbp-118h] BYREF
  char s[8]; // [xsp+28h] [xbp-108h] BYREF
  __int64 v28; // [xsp+30h] [xbp-100h]
  __int64 v29; // [xsp+38h] [xbp-F8h]
  __int64 v30; // [xsp+40h] [xbp-F0h]
  __int64 v31; // [xsp+48h] [xbp-E8h]
  __int64 v32; // [xsp+50h] [xbp-E0h]
  __int64 v33; // [xsp+58h] [xbp-D8h]
  __int64 v34; // [xsp+60h] [xbp-D0h]
  __int64 v35; // [xsp+68h] [xbp-C8h]
  __int64 v36; // [xsp+70h] [xbp-C0h]
  __int64 v37; // [xsp+78h] [xbp-B8h]
  __int64 v38; // [xsp+80h] [xbp-B0h]
  __int64 v39; // [xsp+88h] [xbp-A8h]
  __int64 v40; // [xsp+90h] [xbp-A0h]
  __int64 v41; // [xsp+98h] [xbp-98h]
  __int64 v42; // [xsp+A0h] [xbp-90h]
  __int64 v43; // [xsp+A8h] [xbp-88h]
  __int64 v44; // [xsp+B0h] [xbp-80h]
  __int64 v45; // [xsp+B8h] [xbp-78h]
  __int64 v46; // [xsp+C0h] [xbp-70h]
  __int64 v47; // [xsp+C8h] [xbp-68h]
  __int64 v48; // [xsp+D0h] [xbp-60h]
  __int64 v49; // [xsp+D8h] [xbp-58h]
  __int64 v50; // [xsp+E0h] [xbp-50h]
  __int64 v51; // [xsp+E8h] [xbp-48h]
  __int64 v52; // [xsp+F0h] [xbp-40h]
  __int64 v53; // [xsp+F8h] [xbp-38h]
  __int64 v54; // [xsp+100h] [xbp-30h]
  __int64 v55; // [xsp+108h] [xbp-28h]
  __int64 v56; // [xsp+110h] [xbp-20h]
  __int64 v57; // [xsp+118h] [xbp-18h]
  __int64 v58; // [xsp+120h] [xbp-10h]
  __int64 v59; // [xsp+128h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[1] = &ipa_wlan_opt_dp_set_wlan_ctrl_ready_req_msg_data_v01_ei;
  v24 = 0;
  v26[0] = 78;
  v25[0] = 78;
  v25[1] = &ipa_wlan_opt_dp_set_wlan_ctrl_ready_resp_msg_data_v01_ei;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v5 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v5,
                   "ipa-wan %s:%d Sending QMI_IPA_WLAN_OPT_DATAPATH_SET_WLAN_CTRL_READY_REQ_V01\n",
                   "ipa3_handle_ipa_wlan_opt_dp_set_wlan_ctrl_ready_req",
                   1900);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v7 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(
      v7,
      "ipa-wan %s:%d Sending QMI_IPA_WLAN_OPT_DATAPATH_SET_WLAN_CTRL_READY_REQ_V01\n",
      "ipa3_handle_ipa_wlan_opt_dp_set_wlan_ctrl_ready_req",
      1900);
  }
  if ( ipa_q6_clnt )
  {
    v8 = ipa3_qmi_send_req_wait(ipa_q6_clnt, (unsigned __int16 *)v26, a1, (__int64)v25, (__int64)&v24, 0x1388u);
    v9 = v8;
    if ( (v8 & 0x80000000) != 0 )
    {
      v19 = printk(&unk_3CCE82, "ipa3_handle_ipa_wlan_opt_dp_set_wlan_ctrl_ready_req");
      v20 = ipa3_get_ipc_logbuf(v19);
      if ( v20 )
      {
        v21 = ipa3_get_ipc_logbuf(v20);
        v20 = ipc_log_string(
                v21,
                "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
                "ipa3_handle_ipa_wlan_opt_dp_set_wlan_ctrl_ready_req",
                1912,
                49,
                v9);
      }
      v22 = ipa3_get_ipc_logbuf_low(v20);
      if ( v22 )
      {
        v23 = ipa3_get_ipc_logbuf_low(v22);
        ipc_log_string(
          v23,
          "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
          "ipa3_handle_ipa_wlan_opt_dp_set_wlan_ctrl_ready_req",
          1912,
          49,
          v9);
      }
      v57 = 0;
      v58 = 0;
      v55 = 0;
      v56 = 0;
      v53 = 0;
      v54 = 0;
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
      *(_QWORD *)s = 0;
      v28 = 0;
      snprintf(
        s,
        0x100u,
        "ipa-event-log %s:%d QMI send Req %d failed, rc= %d\n",
        "ipa3_handle_ipa_wlan_opt_dp_set_wlan_ctrl_ready_req",
        1915,
        49,
        v9);
      ipa3_send_opt_log_msg(s);
      result = v9;
    }
    else
    {
      v10 = ipa3_get_ipc_logbuf(v8);
      if ( v10 )
      {
        v11 = ipa3_get_ipc_logbuf(v10);
        v10 = ipc_log_string(
                v11,
                "ipa-wan %s:%d QMI_IPA_WLAN_OPT_DATAPATH_SET_WLAN_CTRL_READY_RESP_V01 received\n",
                "ipa3_handle_ipa_wlan_opt_dp_set_wlan_ctrl_ready_req",
                1919);
      }
      v12 = ipa3_get_ipc_logbuf_low(v10);
      if ( v12 )
      {
        v13 = ipa3_get_ipc_logbuf_low(v12);
        v12 = ipc_log_string(
                v13,
                "ipa-wan %s:%d QMI_IPA_WLAN_OPT_DATAPATH_SET_WLAN_CTRL_READY_RESP_V01 received\n",
                "ipa3_handle_ipa_wlan_opt_dp_set_wlan_ctrl_ready_req",
                1919);
      }
      if ( a2 )
      {
        *a2 = HIDWORD(v24);
        v14 = ipa3_get_ipc_logbuf(v12);
        if ( v14 )
        {
          v15 = ipa3_get_ipc_logbuf(v14);
          v14 = ipc_log_string(
                  v15,
                  "ipa-wan %s:%d rt_tbl_idx = %x\n",
                  "ipa3_handle_ipa_wlan_opt_dp_set_wlan_ctrl_ready_req",
                  1923,
                  HIDWORD(v24));
        }
        v16 = ipa3_get_ipc_logbuf_low(v14);
        if ( v16 )
        {
          v17 = ipa3_get_ipc_logbuf_low(v16);
          ipc_log_string(
            v17,
            "ipa-wan %s:%d rt_tbl_idx = %x\n",
            "ipa3_handle_ipa_wlan_opt_dp_set_wlan_ctrl_ready_req",
            1923,
            HIDWORD(v24));
        }
        v57 = 0;
        v58 = 0;
        v55 = 0;
        v56 = 0;
        v53 = 0;
        v54 = 0;
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
        *(_QWORD *)s = 0;
        v28 = 0;
        snprintf(
          s,
          0x100u,
          "ipa-event-log %s:%d rt_tbl_idx = %x\n",
          "ipa3_handle_ipa_wlan_opt_dp_set_wlan_ctrl_ready_req",
          1924,
          HIDWORD(v24));
        ipa3_send_opt_log_msg(s);
      }
      result = ipa3_check_qmi_response(
                 v9,
                 78,
                 (unsigned __int16)v24,
                 WORD1(v24),
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
