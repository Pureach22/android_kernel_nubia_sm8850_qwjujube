__int64 __fastcall ipa3_handle_ipa_wlan_opt_dp_add_ctrl_filter_req(
        __int64 a1,
        __int64 *a2,
        __int64 a3,
        int *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v10; // x9
  int v11; // w11
  __int64 v12; // x10
  __int64 v13; // x0
  __int64 ipc_logbuf; // x0
  __int64 v15; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v17; // x0
  int v18; // w5
  int v19; // w6
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 result; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // [xsp+10h] [xbp-120h] BYREF
  __int64 v40; // [xsp+18h] [xbp-118h]
  int v41; // [xsp+24h] [xbp-10Ch] BYREF
  char s[8]; // [xsp+28h] [xbp-108h] BYREF
  __int64 v43; // [xsp+30h] [xbp-100h]
  __int64 v44; // [xsp+38h] [xbp-F8h]
  __int64 v45; // [xsp+40h] [xbp-F0h]
  __int64 v46; // [xsp+48h] [xbp-E8h]
  __int64 v47; // [xsp+50h] [xbp-E0h]
  __int64 v48; // [xsp+58h] [xbp-D8h]
  __int64 v49; // [xsp+60h] [xbp-D0h]
  __int64 v50; // [xsp+68h] [xbp-C8h]
  __int64 v51; // [xsp+70h] [xbp-C0h]
  __int64 v52; // [xsp+78h] [xbp-B8h]
  __int64 v53; // [xsp+80h] [xbp-B0h]
  __int64 v54; // [xsp+88h] [xbp-A8h]
  __int64 v55; // [xsp+90h] [xbp-A0h]
  __int64 v56; // [xsp+98h] [xbp-98h]
  __int64 v57; // [xsp+A0h] [xbp-90h]
  __int64 v58; // [xsp+A8h] [xbp-88h]
  __int64 v59; // [xsp+B0h] [xbp-80h]
  __int64 v60; // [xsp+B8h] [xbp-78h]
  __int64 v61; // [xsp+C0h] [xbp-70h]
  __int64 v62; // [xsp+C8h] [xbp-68h]
  __int64 v63; // [xsp+D0h] [xbp-60h]
  __int64 v64; // [xsp+D8h] [xbp-58h]
  __int64 v65; // [xsp+E0h] [xbp-50h]
  __int64 v66; // [xsp+E8h] [xbp-48h]
  __int64 v67; // [xsp+F0h] [xbp-40h]
  __int64 v68; // [xsp+F8h] [xbp-38h]
  __int64 v69; // [xsp+100h] [xbp-30h]
  __int64 v70; // [xsp+108h] [xbp-28h]
  __int64 v71; // [xsp+110h] [xbp-20h]
  __int64 v72; // [xsp+118h] [xbp-18h]
  __int64 v73; // [xsp+120h] [xbp-10h]
  __int64 v74; // [xsp+128h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a2;
  v11 = *((_DWORD *)a2 + 2);
  v41 = 0;
  v12 = ipa3_qmi_ctx + 28864;
  v39 = 0;
  v40 = 0;
  *(_QWORD *)(ipa3_qmi_ctx + 28864) = v10;
  *(_DWORD *)(v12 + 8) = v11;
  v13 = qmi_send_response(a1, a2, a3, 80, 7, &ipa_wlan_opt_dp_add_filter_resp_msg_data_v01_ei, &v41, a8);
  ipc_logbuf = ipa3_get_ipc_logbuf(v13);
  if ( ipc_logbuf )
  {
    v15 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v15,
                   "ipa-wan %s:%d add_ctrl_filter_req: filter_idx %x, iptype %d\n",
                   "ipa3_handle_ipa_wlan_opt_dp_add_ctrl_filter_req",
                   1987,
                   *a4,
                   a4[1]);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v17 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(
      v17,
      "ipa-wan %s:%d add_ctrl_filter_req: filter_idx %x, iptype %d\n",
      "ipa3_handle_ipa_wlan_opt_dp_add_ctrl_filter_req",
      1987,
      *a4,
      a4[1]);
  }
  v18 = *a4;
  v19 = a4[1];
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
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
  *(_QWORD *)s = 0;
  v43 = 0;
  snprintf(
    s,
    0x100u,
    "ipa-event-log %s:%d add_ctrl_filter_req: filter_idx %x, iptype %d\n",
    "ipa3_handle_ipa_wlan_opt_dp_add_ctrl_filter_req",
    1989,
    v18,
    v19);
  ipa3_send_opt_log_msg(s);
  v20 = ipa_wdi_opt_dpath_add_ctrl_filter_req(a4, &v39);
  v21 = ipa3_get_ipc_logbuf(v20);
  if ( v21 )
  {
    v22 = ipa3_get_ipc_logbuf(v21);
    v21 = ipc_log_string(
            v22,
            "ipa-wan %s:%d qmi_snd_rsp: ctrl_flt_idx %x, ctrl_flt_hdl%d\n",
            "ipa3_handle_ipa_wlan_opt_dp_add_ctrl_filter_req",
            1995,
            HIDWORD(v39),
            HIDWORD(v40));
  }
  v23 = ipa3_get_ipc_logbuf_low(v21);
  if ( v23 )
  {
    v24 = ipa3_get_ipc_logbuf_low(v23);
    v23 = ipc_log_string(
            v24,
            "ipa-wan %s:%d qmi_snd_rsp: ctrl_flt_idx %x, ctrl_flt_hdl%d\n",
            "ipa3_handle_ipa_wlan_opt_dp_add_ctrl_filter_req",
            1995,
            HIDWORD(v39),
            HIDWORD(v40));
  }
  v25 = ipa3_get_ipc_logbuf(v23);
  if ( v25 )
  {
    v26 = ipa3_get_ipc_logbuf(v25);
    v25 = ipc_log_string(
            v26,
            "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n",
            "ipa3_handle_ipa_wlan_opt_dp_add_ctrl_filter_req",
            1998,
            (unsigned __int16)v39,
            WORD1(v39));
  }
  v27 = ipa3_get_ipc_logbuf_low(v25);
  if ( v27 )
  {
    v28 = ipa3_get_ipc_logbuf_low(v27);
    ipc_log_string(
      v28,
      "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n",
      "ipa3_handle_ipa_wlan_opt_dp_add_ctrl_filter_req",
      1998,
      (unsigned __int16)v39,
      WORD1(v39));
  }
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
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
  *(_QWORD *)s = 0;
  v43 = 0;
  snprintf(
    s,
    0x100u,
    "ipa-event-log %s:%d qmi_snd_rsp: ctrl_flt_idx %x, ctrl_flt_hdl %d, result %d, err %d\n",
    "ipa3_handle_ipa_wlan_opt_dp_add_ctrl_filter_req",
    2002,
    HIDWORD(v39),
    HIDWORD(v40),
    (unsigned __int16)v39,
    WORD1(v39));
  ipa3_send_opt_log_msg(s);
  v29 = qmi_send_indication(a1, ipa3_qmi_ctx + 28864, 80, 21, &ipa_wlan_opt_dp_add_filter_complt_ind_msg_v01_ei, &v39);
  if ( (v29 & 0x80000000) != 0 )
  {
    v34 = printk(&unk_3F593C, "ipa3_handle_ipa_wlan_opt_dp_add_ctrl_filter_req");
    v35 = ipa3_get_ipc_logbuf(v34);
    if ( v35 )
    {
      v36 = ipa3_get_ipc_logbuf(v35);
      v35 = ipc_log_string(
              v36,
              "ipa-wan %s:%d Add  filter rules failed\n",
              "ipa3_handle_ipa_wlan_opt_dp_add_ctrl_filter_req",
              2012);
    }
    v37 = ipa3_get_ipc_logbuf_low(v35);
    if ( v37 )
    {
      v38 = ipa3_get_ipc_logbuf_low(v37);
      ipc_log_string(
        v38,
        "ipa-wan %s:%d Add  filter rules failed\n",
        "ipa3_handle_ipa_wlan_opt_dp_add_ctrl_filter_req",
        2012);
    }
    v72 = 0;
    v73 = 0;
    v70 = 0;
    v71 = 0;
    v68 = 0;
    v69 = 0;
    v66 = 0;
    v67 = 0;
    v64 = 0;
    v65 = 0;
    v62 = 0;
    v63 = 0;
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
    *(_QWORD *)s = 0;
    v43 = 0;
    snprintf(
      s,
      0x100u,
      "ipa-event-log %s:%d Add  filter rules failed\n",
      "ipa3_handle_ipa_wlan_opt_dp_add_ctrl_filter_req",
      2013);
    result = ipa3_send_opt_log_msg(s);
  }
  else
  {
    v30 = ipa3_get_ipc_logbuf(v29);
    if ( v30 )
    {
      v31 = ipa3_get_ipc_logbuf(v30);
      v30 = ipc_log_string(
              v31,
              "ipa-wan %s:%d Replied to add filter request\n",
              "ipa3_handle_ipa_wlan_opt_dp_add_ctrl_filter_req",
              2016);
    }
    result = ipa3_get_ipc_logbuf_low(v30);
    if ( result )
    {
      v33 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(
                 v33,
                 "ipa-wan %s:%d Replied to add filter request\n",
                 "ipa3_handle_ipa_wlan_opt_dp_add_ctrl_filter_req",
                 2016);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
