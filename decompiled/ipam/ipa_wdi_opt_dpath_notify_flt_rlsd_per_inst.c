__int64 __fastcall ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst(unsigned int a1, char a2)
{
  __int64 v2; // x23
  _DWORD *v3; // x22
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  _BOOL4 v17; // [xsp+4h] [xbp-10Ch] BYREF
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v19; // [xsp+10h] [xbp-100h]
  __int64 v20; // [xsp+18h] [xbp-F8h]
  __int64 v21; // [xsp+20h] [xbp-F0h]
  __int64 v22; // [xsp+28h] [xbp-E8h]
  __int64 v23; // [xsp+30h] [xbp-E0h]
  __int64 v24; // [xsp+38h] [xbp-D8h]
  __int64 v25; // [xsp+40h] [xbp-D0h]
  __int64 v26; // [xsp+48h] [xbp-C8h]
  __int64 v27; // [xsp+50h] [xbp-C0h]
  __int64 v28; // [xsp+58h] [xbp-B8h]
  __int64 v29; // [xsp+60h] [xbp-B0h]
  __int64 v30; // [xsp+68h] [xbp-A8h]
  __int64 v31; // [xsp+70h] [xbp-A0h]
  __int64 v32; // [xsp+78h] [xbp-98h]
  __int64 v33; // [xsp+80h] [xbp-90h]
  __int64 v34; // [xsp+88h] [xbp-88h]
  __int64 v35; // [xsp+90h] [xbp-80h]
  __int64 v36; // [xsp+98h] [xbp-78h]
  __int64 v37; // [xsp+A0h] [xbp-70h]
  __int64 v38; // [xsp+A8h] [xbp-68h]
  __int64 v39; // [xsp+B0h] [xbp-60h]
  __int64 v40; // [xsp+B8h] [xbp-58h]
  __int64 v41; // [xsp+C0h] [xbp-50h]
  __int64 v42; // [xsp+C8h] [xbp-48h]
  __int64 v43; // [xsp+D0h] [xbp-40h]
  __int64 v44; // [xsp+D8h] [xbp-38h]
  __int64 v45; // [xsp+E0h] [xbp-30h]
  __int64 v46; // [xsp+E8h] [xbp-28h]
  __int64 v47; // [xsp+F0h] [xbp-20h]
  __int64 v48; // [xsp+F8h] [xbp-18h]
  __int64 v49; // [xsp+100h] [xbp-10h]
  __int64 v50; // [xsp+108h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 >= 2 )
  {
    printk(&unk_3F6766, "ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_wdi %s:%d Invalid Handle %d\n",
        "ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst",
        1254,
        a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_wdi %s:%d Invalid Handle %d\n",
        "ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst",
        1254,
        a1);
    }
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
    *(_QWORD *)s = 0;
    v19 = 0;
    snprintf(
      s,
      0x100u,
      "ipa-event-log %s:%d Invalid Handle %d\n",
      "ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst",
      1255,
      a1);
    ipa3_send_opt_log_msg(s);
    result = 4294967282LL;
  }
  else if ( ipa_wdi_ctx_list[a1] )
  {
    v2 = a1;
    v3 = &opt_dpath_info + 17 * a1;
    v17 = 0;
    if ( v3[16] )
    {
      v5 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v6 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v6 )
        {
          ipc_log_string(v6, "ipa %s:%d Is success: %d\n", "ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst", 1277, a2 & 1);
          v5 = ipa3_ctx;
        }
        v7 = *(_QWORD *)(v5 + 34160);
        if ( v7 )
          ipc_log_string(v7, "ipa %s:%d Is success: %d\n", "ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst", 1277, a2 & 1);
      }
      if ( (a2 & 1) != 0 )
      {
        v3[16] = 0;
        ((void (__fastcall *)(_QWORD))ipa_pm_deferred_deactivate)(*(unsigned int *)(ipa_wdi_ctx_list[v2] + 176));
        ipa3_check_wdi_opt_chn_empty(v3[23]);
        ipa3_disable_wdi3_opt_dpath((unsigned int)v3[23], v3[22]);
      }
      v17 = (a2 & 1) == 0;
    }
    else
    {
      printk(&unk_3D14C1, "ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst");
      v14 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v15 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v15 )
        {
          ipc_log_string(
            v15,
            "ipa %s:%d Reservation request not sent. IGNORE",
            "ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst",
            1268);
          v14 = ipa3_ctx;
        }
        v16 = *(_QWORD *)(v14 + 34160);
        if ( v16 )
          ipc_log_string(
            v16,
            "ipa %s:%d Reservation request not sent. IGNORE",
            "ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst",
            1268);
      }
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
      *(_QWORD *)s = 0;
      v19 = 0;
      snprintf(
        s,
        0x100u,
        "ipa-event-log %s:%d Reservation request not sent. IGNORE",
        "ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst",
        1269);
      ipa3_send_opt_log_msg(s);
      v17 = 0;
    }
    result = ipa3_qmi_send_wdi_opt_dpath_rmv_all_flt_ind((unsigned __int16 *)&v17);
  }
  else
  {
    printk(&unk_3F0CD4, "ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v12 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v12,
        "ipa_wdi %s:%d wdi ctx is not initialized.\n",
        "ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst",
        1260);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v13 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v13,
        "ipa_wdi %s:%d wdi ctx is not initialized.\n",
        "ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst",
        1260);
    }
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
    *(_QWORD *)s = 0;
    v19 = 0;
    snprintf(
      s,
      0x100u,
      "ipa-event-log %s:%d wdi ctx is not initialized.\n",
      "ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst",
      1261);
    ipa3_send_opt_log_msg(s);
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
