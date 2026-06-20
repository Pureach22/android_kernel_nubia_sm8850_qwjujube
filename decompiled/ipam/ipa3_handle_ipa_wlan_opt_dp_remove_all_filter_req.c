__int64 __fastcall ipa3_handle_ipa_wlan_opt_dp_remove_all_filter_req(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 ipc_logbuf; // x0
  __int64 v9; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  int v13; // w19
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x7
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 result; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // [xsp+0h] [xbp-110h] BYREF
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v31; // [xsp+10h] [xbp-100h]
  __int64 v32; // [xsp+18h] [xbp-F8h]
  __int64 v33; // [xsp+20h] [xbp-F0h]
  __int64 v34; // [xsp+28h] [xbp-E8h]
  __int64 v35; // [xsp+30h] [xbp-E0h]
  __int64 v36; // [xsp+38h] [xbp-D8h]
  __int64 v37; // [xsp+40h] [xbp-D0h]
  __int64 v38; // [xsp+48h] [xbp-C8h]
  __int64 v39; // [xsp+50h] [xbp-C0h]
  __int64 v40; // [xsp+58h] [xbp-B8h]
  __int64 v41; // [xsp+60h] [xbp-B0h]
  __int64 v42; // [xsp+68h] [xbp-A8h]
  __int64 v43; // [xsp+70h] [xbp-A0h]
  __int64 v44; // [xsp+78h] [xbp-98h]
  __int64 v45; // [xsp+80h] [xbp-90h]
  __int64 v46; // [xsp+88h] [xbp-88h]
  __int64 v47; // [xsp+90h] [xbp-80h]
  __int64 v48; // [xsp+98h] [xbp-78h]
  __int64 v49; // [xsp+A0h] [xbp-70h]
  __int64 v50; // [xsp+A8h] [xbp-68h]
  __int64 v51; // [xsp+B0h] [xbp-60h]
  __int64 v52; // [xsp+B8h] [xbp-58h]
  __int64 v53; // [xsp+C0h] [xbp-50h]
  __int64 v54; // [xsp+C8h] [xbp-48h]
  __int64 v55; // [xsp+D0h] [xbp-40h]
  __int64 v56; // [xsp+D8h] [xbp-38h]
  __int64 v57; // [xsp+E0h] [xbp-30h]
  __int64 v58; // [xsp+E8h] [xbp-28h]
  __int64 v59; // [xsp+F0h] [xbp-20h]
  __int64 v60; // [xsp+F8h] [xbp-18h]
  __int64 v61; // [xsp+100h] [xbp-10h]
  __int64 v62; // [xsp+108h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v9 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v9,
                   "ipa-wan %s:%d remove_all_filter_req:\n",
                   "ipa3_handle_ipa_wlan_opt_dp_remove_all_filter_req",
                   1745);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v11 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(
      v11,
      "ipa-wan %s:%d remove_all_filter_req:\n",
      "ipa3_handle_ipa_wlan_opt_dp_remove_all_filter_req",
      1745);
  }
  v12 = ipa_wdi_opt_dpath_remove_all_filter_req(a4, (char *)&v29 + 4);
  v13 = v12;
  v14 = ipa3_get_ipc_logbuf(v12);
  if ( v14 )
  {
    v15 = ipa3_get_ipc_logbuf(v14);
    v14 = ipc_log_string(
            v15,
            "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n",
            "ipa3_handle_ipa_wlan_opt_dp_remove_all_filter_req",
            1751,
            WORD2(v29),
            HIWORD(v29));
  }
  v16 = ipa3_get_ipc_logbuf_low(v14);
  if ( v16 )
  {
    v18 = ipa3_get_ipc_logbuf_low(v16);
    ipc_log_string(
      v18,
      "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n",
      "ipa3_handle_ipa_wlan_opt_dp_remove_all_filter_req",
      1751,
      WORD2(v29),
      HIWORD(v29));
  }
  if ( HIWORD(v29) )
  {
    v60 = 0;
    v61 = 0;
    v58 = 0;
    v59 = 0;
    v56 = 0;
    v57 = 0;
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    v50 = 0;
    v51 = 0;
    v48 = 0;
    v49 = 0;
    v46 = 0;
    v47 = 0;
    v44 = 0;
    v45 = 0;
    v42 = 0;
    v43 = 0;
    v40 = 0;
    v41 = 0;
    v38 = 0;
    v39 = 0;
    v36 = 0;
    v37 = 0;
    v34 = 0;
    v35 = 0;
    v32 = 0;
    v33 = 0;
    *(_QWORD *)s = 0;
    v31 = 0;
    snprintf(
      s,
      0x100u,
      "ipa-event-log %s:%d qmi_snd_rsp: result %d, err %d\n",
      "ipa3_handle_ipa_wlan_opt_dp_remove_all_filter_req",
      1754,
      WORD2(v29),
      HIWORD(v29));
    ipa3_send_opt_log_msg(s);
  }
  v19 = qmi_send_response(
          a1,
          a2,
          a3,
          76,
          7,
          &ipa_wlan_opt_dp_remove_all_filter_resp_msg_data_v01_ei,
          (char *)&v29 + 4,
          v17);
  if ( (v19 & 0x80000000) != 0 )
  {
    v24 = printk(&unk_3FE661, "ipa3_handle_ipa_wlan_opt_dp_remove_all_filter_req");
    v25 = ipa3_get_ipc_logbuf(v24);
    if ( v25 )
    {
      v26 = ipa3_get_ipc_logbuf(v25);
      v25 = ipc_log_string(
              v26,
              "ipa-wan %s:%d Remove all filter rules failed\n",
              "ipa3_handle_ipa_wlan_opt_dp_remove_all_filter_req",
              1763);
    }
    v27 = ipa3_get_ipc_logbuf_low(v25);
    if ( v27 )
    {
      v28 = ipa3_get_ipc_logbuf_low(v27);
      ipc_log_string(
        v28,
        "ipa-wan %s:%d Remove all filter rules failed\n",
        "ipa3_handle_ipa_wlan_opt_dp_remove_all_filter_req",
        1763);
    }
    v60 = 0;
    v61 = 0;
    v58 = 0;
    v59 = 0;
    v56 = 0;
    v57 = 0;
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    v50 = 0;
    v51 = 0;
    v48 = 0;
    v49 = 0;
    v46 = 0;
    v47 = 0;
    v44 = 0;
    v45 = 0;
    v42 = 0;
    v43 = 0;
    v40 = 0;
    v41 = 0;
    v38 = 0;
    v39 = 0;
    v36 = 0;
    v37 = 0;
    v34 = 0;
    v35 = 0;
    v32 = 0;
    v33 = 0;
    *(_QWORD *)s = 0;
    v31 = 0;
    snprintf(
      s,
      0x100u,
      "ipa-event-log %s:%d Remove all filter rules failed\n",
      "ipa3_handle_ipa_wlan_opt_dp_remove_all_filter_req",
      1764);
    result = ipa3_send_opt_log_msg(s);
    if ( v13 < 0 )
      goto LABEL_17;
  }
  else
  {
    v20 = ipa3_get_ipc_logbuf(v19);
    if ( v20 )
    {
      v21 = ipa3_get_ipc_logbuf(v20);
      v20 = ipc_log_string(
              v21,
              "ipa-wan %s:%d Replied to remove all filter request\n",
              "ipa3_handle_ipa_wlan_opt_dp_remove_all_filter_req",
              1767);
    }
    result = ipa3_get_ipc_logbuf_low(v20);
    if ( result )
    {
      v23 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(
                 v23,
                 "ipa-wan %s:%d Replied to remove all filter request\n",
                 "ipa3_handle_ipa_wlan_opt_dp_remove_all_filter_req",
                 1767);
    }
    if ( v13 < 0 )
    {
LABEL_17:
      LODWORD(v29) = HIDWORD(v29);
      result = ipa3_qmi_send_wdi_opt_dpath_rmv_all_flt_ind((unsigned __int16 *)&v29);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
