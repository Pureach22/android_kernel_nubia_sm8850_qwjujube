__int64 __fastcall ipa_wdi_opt_dpath_notify_flt_rsvd_per_inst(unsigned int a1, char a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  int v11; // w5
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v13; // [xsp+10h] [xbp-100h]
  __int64 v14; // [xsp+18h] [xbp-F8h]
  __int64 v15; // [xsp+20h] [xbp-F0h]
  __int64 v16; // [xsp+28h] [xbp-E8h]
  __int64 v17; // [xsp+30h] [xbp-E0h]
  __int64 v18; // [xsp+38h] [xbp-D8h]
  __int64 v19; // [xsp+40h] [xbp-D0h]
  __int64 v20; // [xsp+48h] [xbp-C8h]
  __int64 v21; // [xsp+50h] [xbp-C0h]
  __int64 v22; // [xsp+58h] [xbp-B8h]
  __int64 v23; // [xsp+60h] [xbp-B0h]
  __int64 v24; // [xsp+68h] [xbp-A8h]
  __int64 v25; // [xsp+70h] [xbp-A0h]
  __int64 v26; // [xsp+78h] [xbp-98h]
  __int64 v27; // [xsp+80h] [xbp-90h]
  __int64 v28; // [xsp+88h] [xbp-88h]
  __int64 v29; // [xsp+90h] [xbp-80h]
  __int64 v30; // [xsp+98h] [xbp-78h]
  __int64 v31; // [xsp+A0h] [xbp-70h]
  __int64 v32; // [xsp+A8h] [xbp-68h]
  __int64 v33; // [xsp+B0h] [xbp-60h]
  __int64 v34; // [xsp+B8h] [xbp-58h]
  __int64 v35; // [xsp+C0h] [xbp-50h]
  __int64 v36; // [xsp+C8h] [xbp-48h]
  __int64 v37; // [xsp+D0h] [xbp-40h]
  __int64 v38; // [xsp+D8h] [xbp-38h]
  __int64 v39; // [xsp+E0h] [xbp-30h]
  __int64 v40; // [xsp+E8h] [xbp-28h]
  __int64 v41; // [xsp+F0h] [xbp-20h]
  __int64 v42; // [xsp+F8h] [xbp-18h]
  __int64 v43; // [xsp+100h] [xbp-10h]
  __int64 v44; // [xsp+108h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 < 2 )
  {
    v2 = ipa_wdi_ctx_list[a1];
    if ( v2 )
    {
      if ( a1 != 1 || *(_DWORD *)(v2 + 144) > 1u )
      {
        *(_WORD *)&s[2] = 0;
        *(_WORD *)s = (a2 & 1) == 0;
        result = ipa3_qmi_send_wdi_opt_dpath_rsrv_flt_ind((unsigned __int16 *)s);
        goto LABEL_6;
      }
      printk(&unk_3E2714, "ipa_wdi_opt_dpath_notify_flt_rsvd_per_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipa_wdi %s:%d More than one instance not supported for WDI ver = %d\n",
          "ipa_wdi_opt_dpath_notify_flt_rsvd_per_inst",
          1224,
          *(_DWORD *)(qword_204E60 + 144));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipa_wdi %s:%d More than one instance not supported for WDI ver = %d\n",
          "ipa_wdi_opt_dpath_notify_flt_rsvd_per_inst",
          1224,
          *(_DWORD *)(qword_204E60 + 144));
      }
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
      v11 = *(_DWORD *)(qword_204E60 + 144);
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
      v16 = 0;
      v17 = 0;
      v14 = 0;
      v15 = 0;
      *(_QWORD *)s = 0;
      v13 = 0;
      snprintf(
        s,
        0x100u,
        "ipa-event-log %s:%d More than one instance not supported for WDI ver = %d\n",
        "ipa_wdi_opt_dpath_notify_flt_rsvd_per_inst",
        1226,
        v11);
    }
    else
    {
      printk(&unk_3F0CD4, "ipa_wdi_opt_dpath_notify_flt_rsvd_per_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        v7 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v7,
          "ipa_wdi %s:%d wdi ctx is not initialized.\n",
          "ipa_wdi_opt_dpath_notify_flt_rsvd_per_inst",
          1215);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v8 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v8,
          "ipa_wdi %s:%d wdi ctx is not initialized.\n",
          "ipa_wdi_opt_dpath_notify_flt_rsvd_per_inst",
          1215);
      }
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
      v16 = 0;
      v17 = 0;
      v14 = 0;
      v15 = 0;
      *(_QWORD *)s = 0;
      v13 = 0;
      snprintf(
        s,
        0x100u,
        "ipa-event-log %s:%d wdi ctx is not initialized.\n",
        "ipa_wdi_opt_dpath_notify_flt_rsvd_per_inst",
        1216);
    }
    ipa3_send_opt_log_msg(s);
    result = 0xFFFFFFFFLL;
    goto LABEL_6;
  }
  printk(&unk_3F6766, "ipa_wdi_opt_dpath_notify_flt_rsvd_per_inst");
  if ( ipa3_get_ipc_logbuf() )
  {
    v5 = ipa3_get_ipc_logbuf();
    ipc_log_string(v5, "ipa_wdi %s:%d Invalid Handle %d\n", "ipa_wdi_opt_dpath_notify_flt_rsvd_per_inst", 1209, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v6 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v6, "ipa_wdi %s:%d Invalid Handle %d\n", "ipa_wdi_opt_dpath_notify_flt_rsvd_per_inst", 1209, a1);
  }
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
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  *(_QWORD *)s = 0;
  v13 = 0;
  snprintf(s, 0x100u, "ipa-event-log %s:%d Invalid Handle %d\n", "ipa_wdi_opt_dpath_notify_flt_rsvd_per_inst", 1210, a1);
  ipa3_send_opt_log_msg(s);
  result = 4294967282LL;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
