__int64 __fastcall ipa3_qmi_send_wdi_opt_dpath_rmv_ctrl_flt_ind(unsigned __int16 *a1)
{
  __int64 ipc_logbuf; // x0
  __int64 v3; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  int v6; // w21
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  int v14; // w5
  int v15; // w6
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v17; // [xsp+10h] [xbp-100h]
  __int64 v18; // [xsp+18h] [xbp-F8h]
  __int64 v19; // [xsp+20h] [xbp-F0h]
  __int64 v20; // [xsp+28h] [xbp-E8h]
  __int64 v21; // [xsp+30h] [xbp-E0h]
  __int64 v22; // [xsp+38h] [xbp-D8h]
  __int64 v23; // [xsp+40h] [xbp-D0h]
  __int64 v24; // [xsp+48h] [xbp-C8h]
  __int64 v25; // [xsp+50h] [xbp-C0h]
  __int64 v26; // [xsp+58h] [xbp-B8h]
  __int64 v27; // [xsp+60h] [xbp-B0h]
  __int64 v28; // [xsp+68h] [xbp-A8h]
  __int64 v29; // [xsp+70h] [xbp-A0h]
  __int64 v30; // [xsp+78h] [xbp-98h]
  __int64 v31; // [xsp+80h] [xbp-90h]
  __int64 v32; // [xsp+88h] [xbp-88h]
  __int64 v33; // [xsp+90h] [xbp-80h]
  __int64 v34; // [xsp+98h] [xbp-78h]
  __int64 v35; // [xsp+A0h] [xbp-70h]
  __int64 v36; // [xsp+A8h] [xbp-68h]
  __int64 v37; // [xsp+B0h] [xbp-60h]
  __int64 v38; // [xsp+B8h] [xbp-58h]
  __int64 v39; // [xsp+C0h] [xbp-50h]
  __int64 v40; // [xsp+C8h] [xbp-48h]
  __int64 v41; // [xsp+D0h] [xbp-40h]
  __int64 v42; // [xsp+D8h] [xbp-38h]
  __int64 v43; // [xsp+E0h] [xbp-30h]
  __int64 v44; // [xsp+E8h] [xbp-28h]
  __int64 v45; // [xsp+F0h] [xbp-20h]
  __int64 v46; // [xsp+F8h] [xbp-18h]
  __int64 v47; // [xsp+100h] [xbp-10h]
  __int64 v48; // [xsp+108h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v3 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v3,
                   "ipa-wan %s:%d Sending QMI_IPA_WLAN_OPT_DATAPATH_REMOVE_CTRL_FILTER_COMPLT_IND_V01\n",
                   "ipa3_qmi_send_wdi_opt_dpath_rmv_ctrl_flt_ind",
                   2980);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v5 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_logbuf_low = ipc_log_string(
                       v5,
                       "ipa-wan %s:%d Sending QMI_IPA_WLAN_OPT_DATAPATH_REMOVE_CTRL_FILTER_COMPLT_IND_V01\n",
                       "ipa3_qmi_send_wdi_opt_dpath_rmv_ctrl_flt_ind",
                       2980);
  }
  if ( ipa3_svc_handle )
  {
    v6 = *(_DWORD *)(ipa3_ctx + 45216);
    v7 = ipa3_get_ipc_logbuf(ipc_logbuf_low);
    if ( v6 )
    {
      if ( v7 )
      {
        v8 = ipa3_get_ipc_logbuf(v7);
        v7 = ipc_log_string(
               v8,
               "ipa-wan %s:%d SSR in progress , no need to send ind\n",
               "ipa3_qmi_send_wdi_opt_dpath_rmv_ctrl_flt_ind",
               2986);
      }
      result = ipa3_get_ipc_logbuf_low(v7);
      if ( result )
      {
        v10 = ipa3_get_ipc_logbuf_low(result);
        ipc_log_string(
          v10,
          "ipa-wan %s:%d SSR in progress , no need to send ind\n",
          "ipa3_qmi_send_wdi_opt_dpath_rmv_ctrl_flt_ind",
          2986);
        result = 0;
      }
    }
    else
    {
      if ( v7 )
      {
        v11 = ipa3_get_ipc_logbuf(v7);
        v7 = ipc_log_string(
               v11,
               "ipa-wan %s:%d wdi_opt_dpath_rmv_all_flt_ind: result %d, err %d\n",
               "ipa3_qmi_send_wdi_opt_dpath_rmv_ctrl_flt_ind",
               2992,
               *a1,
               a1[1]);
      }
      v12 = ipa3_get_ipc_logbuf_low(v7);
      if ( v12 )
      {
        v13 = ipa3_get_ipc_logbuf_low(v12);
        ipc_log_string(
          v13,
          "ipa-wan %s:%d wdi_opt_dpath_rmv_all_flt_ind: result %d, err %d\n",
          "ipa3_qmi_send_wdi_opt_dpath_rmv_ctrl_flt_ind",
          2992,
          *a1,
          a1[1]);
      }
      v14 = *a1;
      v15 = a1[1];
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
      v30 = 0;
      v31 = 0;
      v28 = 0;
      v29 = 0;
      v26 = 0;
      v27 = 0;
      v24 = 0;
      v25 = 0;
      v22 = 0;
      v23 = 0;
      v20 = 0;
      v21 = 0;
      v18 = 0;
      v19 = 0;
      *(_QWORD *)s = 0;
      v17 = 0;
      snprintf(
        s,
        0x100u,
        "ipa-event-log %s:%d wdi_opt_dpath_rmv_all_flt_ind: result %d, err %d\n",
        "ipa3_qmi_send_wdi_opt_dpath_rmv_ctrl_flt_ind",
        2995,
        v14,
        v15);
      ipa3_send_opt_log_msg(s);
      result = qmi_send_indication(
                 ipa3_svc_handle,
                 ipa3_qmi_ctx + 28864,
                 81,
                 14,
                 &ipa_wlan_opt_dp_remove_ctrl_filter_complt_ind_msg_data_v01_ei,
                 a1);
    }
  }
  else
  {
    result = 4294967186LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
