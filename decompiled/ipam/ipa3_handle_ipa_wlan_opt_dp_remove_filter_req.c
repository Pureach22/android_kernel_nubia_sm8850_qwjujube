__int64 __fastcall ipa3_handle_ipa_wlan_opt_dp_remove_filter_req(__int64 a1, __int64 *a2, __int64 a3, int *a4)
{
  __int64 v8; // x9
  int v9; // w11
  __int64 v10; // x10
  __int64 ipc_logbuf; // x0
  __int64 v12; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v14; // x0
  int v15; // w5
  int v16; // w6
  __int64 v17; // x7
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 result; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // [xsp+8h] [xbp-118h] BYREF
  int v33; // [xsp+14h] [xbp-10Ch] BYREF
  char s[8]; // [xsp+18h] [xbp-108h] BYREF
  __int64 v35; // [xsp+20h] [xbp-100h]
  __int64 v36; // [xsp+28h] [xbp-F8h]
  __int64 v37; // [xsp+30h] [xbp-F0h]
  __int64 v38; // [xsp+38h] [xbp-E8h]
  __int64 v39; // [xsp+40h] [xbp-E0h]
  __int64 v40; // [xsp+48h] [xbp-D8h]
  __int64 v41; // [xsp+50h] [xbp-D0h]
  __int64 v42; // [xsp+58h] [xbp-C8h]
  __int64 v43; // [xsp+60h] [xbp-C0h]
  __int64 v44; // [xsp+68h] [xbp-B8h]
  __int64 v45; // [xsp+70h] [xbp-B0h]
  __int64 v46; // [xsp+78h] [xbp-A8h]
  __int64 v47; // [xsp+80h] [xbp-A0h]
  __int64 v48; // [xsp+88h] [xbp-98h]
  __int64 v49; // [xsp+90h] [xbp-90h]
  __int64 v50; // [xsp+98h] [xbp-88h]
  __int64 v51; // [xsp+A0h] [xbp-80h]
  __int64 v52; // [xsp+A8h] [xbp-78h]
  __int64 v53; // [xsp+B0h] [xbp-70h]
  __int64 v54; // [xsp+B8h] [xbp-68h]
  __int64 v55; // [xsp+C0h] [xbp-60h]
  __int64 v56; // [xsp+C8h] [xbp-58h]
  __int64 v57; // [xsp+D0h] [xbp-50h]
  __int64 v58; // [xsp+D8h] [xbp-48h]
  __int64 v59; // [xsp+E0h] [xbp-40h]
  __int64 v60; // [xsp+E8h] [xbp-38h]
  __int64 v61; // [xsp+F0h] [xbp-30h]
  __int64 v62; // [xsp+F8h] [xbp-28h]
  __int64 v63; // [xsp+100h] [xbp-20h]
  __int64 v64; // [xsp+108h] [xbp-18h]
  __int64 v65; // [xsp+110h] [xbp-10h]
  __int64 v66; // [xsp+118h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *a2;
  v9 = *((_DWORD *)a2 + 2);
  v33 = 0;
  v10 = ipa3_qmi_ctx + 28864;
  v32 = 0;
  *(_QWORD *)(ipa3_qmi_ctx + 28864) = v8;
  *(_DWORD *)(v10 + 8) = v9;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v12 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v12,
                   "ipa-wan %s:%d remove_filter_req: filter_idx %x, filter_hdl %d\n",
                   "ipa3_handle_ipa_wlan_opt_dp_remove_filter_req",
                   1851,
                   *a4,
                   a4[1]);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v14 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(
      v14,
      "ipa-wan %s:%d remove_filter_req: filter_idx %x, filter_hdl %d\n",
      "ipa3_handle_ipa_wlan_opt_dp_remove_filter_req",
      1851,
      *a4,
      a4[1]);
  }
  v15 = *a4;
  v16 = a4[1];
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
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  *(_QWORD *)s = 0;
  v35 = 0;
  snprintf(
    s,
    0x100u,
    "ipa-event-log %s:%d remove_filter_req: filter_idx %x, filter_hdl %d\n",
    "ipa3_handle_ipa_wlan_opt_dp_remove_filter_req",
    1853,
    v15,
    v16);
  ipa3_send_opt_log_msg(s);
  qmi_send_response(a1, a2, a3, 75, 7, &ipa_wlan_opt_dp_remove_filter_resp_msg_data_v01_ei, &v33, v17);
  v18 = ipa_wdi_opt_dpath_remove_filter_req(a4, &v32);
  v19 = ipa3_get_ipc_logbuf(v18);
  if ( v19 )
  {
    v20 = ipa3_get_ipc_logbuf(v19);
    v19 = ipc_log_string(
            v20,
            "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n",
            "ipa3_handle_ipa_wlan_opt_dp_remove_filter_req",
            1865,
            (unsigned __int16)v32,
            WORD1(v32));
  }
  v21 = ipa3_get_ipc_logbuf_low(v19);
  if ( v21 )
  {
    v22 = ipa3_get_ipc_logbuf_low(v21);
    ipc_log_string(
      v22,
      "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n",
      "ipa3_handle_ipa_wlan_opt_dp_remove_filter_req",
      1865,
      (unsigned __int16)v32,
      WORD1(v32));
  }
  v23 = qmi_send_indication(
          a1,
          ipa3_qmi_ctx + 28864,
          75,
          14,
          &ipa_wlan_opt_dp_remove_filter_complt_ind_msg_data_v01_ei,
          &v32);
  if ( (v23 & 0x80000000) != 0 )
  {
    v28 = printk(&unk_3A740A, "ipa3_handle_ipa_wlan_opt_dp_remove_filter_req");
    v29 = ipa3_get_ipc_logbuf(v28);
    if ( v29 )
    {
      v30 = ipa3_get_ipc_logbuf(v29);
      v29 = ipc_log_string(
              v30,
              "ipa-wan %s:%d Remove filter rules failed\n",
              "ipa3_handle_ipa_wlan_opt_dp_remove_filter_req",
              1876);
    }
    result = ipa3_get_ipc_logbuf_low(v29);
    if ( result )
    {
      v31 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(
                 v31,
                 "ipa-wan %s:%d Remove filter rules failed\n",
                 "ipa3_handle_ipa_wlan_opt_dp_remove_filter_req",
                 1876);
    }
  }
  else
  {
    v24 = ipa3_get_ipc_logbuf(v23);
    if ( v24 )
    {
      v25 = ipa3_get_ipc_logbuf(v24);
      v24 = ipc_log_string(
              v25,
              "ipa-wan %s:%d Replied to remove filter request\n",
              "ipa3_handle_ipa_wlan_opt_dp_remove_filter_req",
              1878);
    }
    result = ipa3_get_ipc_logbuf_low(v24);
    if ( result )
    {
      v27 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(
                 v27,
                 "ipa-wan %s:%d Replied to remove filter request\n",
                 "ipa3_handle_ipa_wlan_opt_dp_remove_filter_req",
                 1878);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
