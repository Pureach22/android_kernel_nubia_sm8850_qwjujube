__int64 __fastcall ipa3_handle_ipa_wlan_opt_dp_rsrv_filter_req(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 *a4)
{
  __int64 ipc_logbuf; // x0
  __int64 v9; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v11; // x0
  int v12; // w6
  int v13; // w7
  int v14; // w5
  __int64 v15; // x0
  int v16; // w19
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x7
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 result; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // [xsp+0h] [xbp-110h] BYREF
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v34; // [xsp+10h] [xbp-100h]
  __int64 v35; // [xsp+18h] [xbp-F8h]
  __int64 v36; // [xsp+20h] [xbp-F0h]
  __int64 v37; // [xsp+28h] [xbp-E8h]
  __int64 v38; // [xsp+30h] [xbp-E0h]
  __int64 v39; // [xsp+38h] [xbp-D8h]
  __int64 v40; // [xsp+40h] [xbp-D0h]
  __int64 v41; // [xsp+48h] [xbp-C8h]
  __int64 v42; // [xsp+50h] [xbp-C0h]
  __int64 v43; // [xsp+58h] [xbp-B8h]
  __int64 v44; // [xsp+60h] [xbp-B0h]
  __int64 v45; // [xsp+68h] [xbp-A8h]
  __int64 v46; // [xsp+70h] [xbp-A0h]
  __int64 v47; // [xsp+78h] [xbp-98h]
  __int64 v48; // [xsp+80h] [xbp-90h]
  __int64 v49; // [xsp+88h] [xbp-88h]
  __int64 v50; // [xsp+90h] [xbp-80h]
  __int64 v51; // [xsp+98h] [xbp-78h]
  __int64 v52; // [xsp+A0h] [xbp-70h]
  __int64 v53; // [xsp+A8h] [xbp-68h]
  __int64 v54; // [xsp+B0h] [xbp-60h]
  __int64 v55; // [xsp+B8h] [xbp-58h]
  __int64 v56; // [xsp+C0h] [xbp-50h]
  __int64 v57; // [xsp+C8h] [xbp-48h]
  __int64 v58; // [xsp+D0h] [xbp-40h]
  __int64 v59; // [xsp+D8h] [xbp-38h]
  __int64 v60; // [xsp+E0h] [xbp-30h]
  __int64 v61; // [xsp+E8h] [xbp-28h]
  __int64 v62; // [xsp+F0h] [xbp-20h]
  __int64 v63; // [xsp+F8h] [xbp-18h]
  __int64 v64; // [xsp+100h] [xbp-10h]
  __int64 v65; // [xsp+108h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v9 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v9,
                   "ipa-wan %s:%d rsrv_filter_req: num_fltrs %d, timeout_val %d, rtng_table %d\n",
                   "ipa3_handle_ipa_wlan_opt_dp_rsrv_filter_req",
                   1702,
                   *a4,
                   *((_DWORD *)a4 + 1),
                   *((_DWORD *)a4 + 2));
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v11 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(
      v11,
      "ipa-wan %s:%d rsrv_filter_req: num_fltrs %d, timeout_val %d, rtng_table %d\n",
      "ipa3_handle_ipa_wlan_opt_dp_rsrv_filter_req",
      1702,
      *a4,
      *((_DWORD *)a4 + 1),
      *((_DWORD *)a4 + 2));
  }
  v12 = *((_DWORD *)a4 + 1);
  v13 = *((_DWORD *)a4 + 2);
  v14 = *a4;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
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
  *(_QWORD *)s = 0;
  v34 = 0;
  snprintf(
    s,
    0x100u,
    "ipa-event-log %s:%d rsrv_filter_req: num_fltrs %d, timeout_val %d, rtng_table %d\n",
    "ipa3_handle_ipa_wlan_opt_dp_rsrv_filter_req",
    1704,
    v14,
    v12,
    v13);
  ipa3_send_opt_log_msg(s);
  v15 = ipa_wdi_opt_dpath_rsrv_filter_req(a4, (char *)&v32 + 4);
  v16 = v15;
  v17 = ipa3_get_ipc_logbuf(v15);
  if ( v17 )
  {
    v18 = ipa3_get_ipc_logbuf(v17);
    v17 = ipc_log_string(
            v18,
            "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n",
            "ipa3_handle_ipa_wlan_opt_dp_rsrv_filter_req",
            1709,
            WORD2(v32),
            HIWORD(v32));
  }
  v19 = ipa3_get_ipc_logbuf_low(v17);
  if ( v19 )
  {
    v20 = ipa3_get_ipc_logbuf_low(v19);
    ipc_log_string(
      v20,
      "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n",
      "ipa3_handle_ipa_wlan_opt_dp_rsrv_filter_req",
      1709,
      WORD2(v32),
      HIWORD(v32));
  }
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
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
  *(_QWORD *)s = 0;
  v34 = 0;
  snprintf(
    s,
    0x100u,
    "ipa-event-log %s:%d qmi_snd_rsp: result %d, err %d\n",
    "ipa3_handle_ipa_wlan_opt_dp_rsrv_filter_req",
    1711,
    WORD2(v32),
    HIWORD(v32));
  ipa3_send_opt_log_msg(s);
  v22 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, void *, char *, __int64, __int64))qmi_send_response)(
          a1,
          a2,
          a3,
          73,
          7,
          &ipa_wlan_opt_dp_rsrv_filter_resp_msg_data_v01_ei,
          (char *)&v32 + 4,
          v21,
          v32);
  if ( (v22 & 0x80000000) != 0 )
  {
    v27 = printk(&unk_3E152E, "ipa3_handle_ipa_wlan_opt_dp_rsrv_filter_req");
    v28 = ipa3_get_ipc_logbuf(v27);
    if ( v28 )
    {
      v29 = ipa3_get_ipc_logbuf(v28);
      v28 = ipc_log_string(
              v29,
              "ipa-wan %s:%d Reserve filter rules response failed\n",
              "ipa3_handle_ipa_wlan_opt_dp_rsrv_filter_req",
              1720);
    }
    v30 = ipa3_get_ipc_logbuf_low(v28);
    if ( v30 )
    {
      v31 = ipa3_get_ipc_logbuf_low(v30);
      ipc_log_string(
        v31,
        "ipa-wan %s:%d Reserve filter rules response failed\n",
        "ipa3_handle_ipa_wlan_opt_dp_rsrv_filter_req",
        1720);
    }
    v63 = 0;
    v64 = 0;
    v61 = 0;
    v62 = 0;
    v59 = 0;
    v60 = 0;
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
    *(_QWORD *)s = 0;
    v34 = 0;
    snprintf(
      s,
      0x100u,
      "ipa-event-log %s:%d Reserve filter rules response failed\n",
      "ipa3_handle_ipa_wlan_opt_dp_rsrv_filter_req",
      1721);
    result = ipa3_send_opt_log_msg(s);
    if ( v16 < 0 )
      goto LABEL_15;
  }
  else
  {
    v23 = ipa3_get_ipc_logbuf(v22);
    if ( v23 )
    {
      v24 = ipa3_get_ipc_logbuf(v23);
      v23 = ipc_log_string(
              v24,
              "ipa-wan %s:%d Replied to install filter request\n",
              "ipa3_handle_ipa_wlan_opt_dp_rsrv_filter_req",
              1724);
    }
    result = ipa3_get_ipc_logbuf_low(v23);
    if ( result )
    {
      v26 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(
                 v26,
                 "ipa-wan %s:%d Replied to install filter request\n",
                 "ipa3_handle_ipa_wlan_opt_dp_rsrv_filter_req",
                 1724);
    }
    if ( v16 < 0 )
    {
LABEL_15:
      LODWORD(v32) = HIDWORD(v32);
      result = ipa3_qmi_send_wdi_opt_dpath_rsrv_flt_ind((unsigned __int16 *)&v32);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
