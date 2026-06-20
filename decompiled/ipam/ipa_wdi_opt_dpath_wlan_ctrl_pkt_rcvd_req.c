__int64 __fastcall ipa_wdi_opt_dpath_wlan_ctrl_pkt_rcvd_req(int *a1)
{
  int v2; // w8
  unsigned int v3; // w19
  long double v4; // q0
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  const char *v8; // x2
  __int64 v9; // x4
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v19; // w10
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v24; // [xsp+10h] [xbp-100h]
  __int64 v25; // [xsp+18h] [xbp-F8h]
  __int64 v26; // [xsp+20h] [xbp-F0h]
  __int64 v27; // [xsp+28h] [xbp-E8h]
  __int64 v28; // [xsp+30h] [xbp-E0h]
  __int64 v29; // [xsp+38h] [xbp-D8h]
  __int64 v30; // [xsp+40h] [xbp-D0h]
  __int64 v31; // [xsp+48h] [xbp-C8h]
  __int64 v32; // [xsp+50h] [xbp-C0h]
  __int64 v33; // [xsp+58h] [xbp-B8h]
  __int64 v34; // [xsp+60h] [xbp-B0h]
  __int64 v35; // [xsp+68h] [xbp-A8h]
  __int64 v36; // [xsp+70h] [xbp-A0h]
  __int64 v37; // [xsp+78h] [xbp-98h]
  __int64 v38; // [xsp+80h] [xbp-90h]
  __int64 v39; // [xsp+88h] [xbp-88h]
  __int64 v40; // [xsp+90h] [xbp-80h]
  __int64 v41; // [xsp+98h] [xbp-78h]
  __int64 v42; // [xsp+A0h] [xbp-70h]
  __int64 v43; // [xsp+A8h] [xbp-68h]
  __int64 v44; // [xsp+B0h] [xbp-60h]
  __int64 v45; // [xsp+B8h] [xbp-58h]
  __int64 v46; // [xsp+C0h] [xbp-50h]
  __int64 v47; // [xsp+C8h] [xbp-48h]
  __int64 v48; // [xsp+D0h] [xbp-40h]
  __int64 v49; // [xsp+D8h] [xbp-38h]
  __int64 v50; // [xsp+E0h] [xbp-30h]
  __int64 v51; // [xsp+E8h] [xbp-28h]
  __int64 v52; // [xsp+F0h] [xbp-20h]
  __int64 v53; // [xsp+F8h] [xbp-18h]
  __int64 v54; // [xsp+100h] [xbp-10h]
  __int64 v55; // [xsp+108h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !dword_204EB0 )
  {
    printk(&unk_3CB2AD, "ipa_wdi_opt_dpath_wlan_ctrl_pkt_rcvd_req");
    v5 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        v4 = ipc_log_string(
               v6,
               "ipa %s:%d ctrl dpath is not enabled.\n",
               "ipa_wdi_opt_dpath_wlan_ctrl_pkt_rcvd_req",
               1611);
        v5 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v5 + 34160);
      if ( v7 )
        v4 = ipc_log_string(
               v7,
               "ipa %s:%d ctrl dpath is not enabled.\n",
               "ipa_wdi_opt_dpath_wlan_ctrl_pkt_rcvd_req",
               1611);
    }
    v8 = "ipa-event-log %s:%d ctrl dpath is not enabled.\n";
    v9 = 1612;
    v53 = 0;
    v54 = 0;
    v51 = 0;
    v52 = 0;
    v49 = 0;
    v50 = 0;
    v47 = 0;
    v48 = 0;
    goto LABEL_18;
  }
  if ( !dword_204ED0 && *a1 )
  {
    printk(&unk_3B6BAA, "ipa_wdi_opt_dpath_wlan_ctrl_pkt_rcvd_req");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        v4 = ipc_log_string(
               v11,
               "ipa %s:%d num ctrl pkts previously 0\n",
               "ipa_wdi_opt_dpath_wlan_ctrl_pkt_rcvd_req",
               1617);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        v4 = ipc_log_string(
               v12,
               "ipa %s:%d num ctrl pkts previously 0\n",
               "ipa_wdi_opt_dpath_wlan_ctrl_pkt_rcvd_req",
               1617);
    }
    v53 = 0;
    v54 = 0;
    v8 = "ipa-event-log %s:%d num ctrl pkts previously 0\n";
    v51 = 0;
    v52 = 0;
    v49 = 0;
    v50 = 0;
    v47 = 0;
    v48 = 0;
    v9 = 1618;
LABEL_18:
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
    *(_QWORD *)s = 0;
    v24 = 0;
    snprintf(s, 0x100u, v8, "ipa_wdi_opt_dpath_wlan_ctrl_pkt_rcvd_req", v9, *(double *)&v4);
    ipa3_send_opt_log_msg(s);
    v3 = -1;
    goto LABEL_28;
  }
  mutex_lock(ipa_wdi_ctx_list[0] + 96);
  v2 = *a1;
  _X9 = &dword_204ED0;
  __asm { PRFM            #0x11, [X9] }
  do
    v19 = __ldxr((unsigned int *)&dword_204ED0);
  while ( __stxr(v19 - v2, (unsigned int *)&dword_204ED0) );
  if ( dword_204ED0 )
  {
    v3 = 0;
  }
  else
  {
    v3 = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deferred_deactivate)((unsigned int)dword_204ECC);
    if ( v3 )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipa_wdi %s:%d fail to deactivate ipa pm\n",
          "ipa_wdi_opt_dpath_wlan_ctrl_pkt_rcvd_req",
          1627);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipa_wdi %s:%d fail to deactivate ipa pm\n",
          "ipa_wdi_opt_dpath_wlan_ctrl_pkt_rcvd_req",
          1627);
      }
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
      v27 = 0;
      v28 = 0;
      v25 = 0;
      v26 = 0;
      *(_QWORD *)s = 0;
      v24 = 0;
      snprintf(
        s,
        0x100u,
        "ipa-event-log %s:%d fail to deactivate ipa pm\n",
        "ipa_wdi_opt_dpath_wlan_ctrl_pkt_rcvd_req",
        1628);
      ipa3_send_opt_log_msg(s);
    }
  }
  mutex_unlock(ipa_wdi_ctx_list[0] + 96);
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return v3;
}
