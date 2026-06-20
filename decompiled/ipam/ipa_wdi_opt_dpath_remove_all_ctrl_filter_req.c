__int64 ipa_wdi_opt_dpath_remove_all_ctrl_filter_req()
{
  void (__fastcall *v0)(__int64, _QWORD); // x8
  __int64 v1; // x0
  __int64 result; // x0
  unsigned int v3; // w19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v10; // [xsp+10h] [xbp-100h]
  __int64 v11; // [xsp+18h] [xbp-F8h]
  __int64 v12; // [xsp+20h] [xbp-F0h]
  __int64 v13; // [xsp+28h] [xbp-E8h]
  __int64 v14; // [xsp+30h] [xbp-E0h]
  __int64 v15; // [xsp+38h] [xbp-D8h]
  __int64 v16; // [xsp+40h] [xbp-D0h]
  __int64 v17; // [xsp+48h] [xbp-C8h]
  __int64 v18; // [xsp+50h] [xbp-C0h]
  __int64 v19; // [xsp+58h] [xbp-B8h]
  __int64 v20; // [xsp+60h] [xbp-B0h]
  __int64 v21; // [xsp+68h] [xbp-A8h]
  __int64 v22; // [xsp+70h] [xbp-A0h]
  __int64 v23; // [xsp+78h] [xbp-98h]
  __int64 v24; // [xsp+80h] [xbp-90h]
  __int64 v25; // [xsp+88h] [xbp-88h]
  __int64 v26; // [xsp+90h] [xbp-80h]
  __int64 v27; // [xsp+98h] [xbp-78h]
  __int64 v28; // [xsp+A0h] [xbp-70h]
  __int64 v29; // [xsp+A8h] [xbp-68h]
  __int64 v30; // [xsp+B0h] [xbp-60h]
  __int64 v31; // [xsp+B8h] [xbp-58h]
  __int64 v32; // [xsp+C0h] [xbp-50h]
  __int64 v33; // [xsp+C8h] [xbp-48h]
  __int64 v34; // [xsp+D0h] [xbp-40h]
  __int64 v35; // [xsp+D8h] [xbp-38h]
  __int64 v36; // [xsp+E0h] [xbp-30h]
  __int64 v37; // [xsp+E8h] [xbp-28h]
  __int64 v38; // [xsp+F0h] [xbp-20h]
  __int64 v39; // [xsp+F8h] [xbp-18h]
  __int64 v40; // [xsp+100h] [xbp-10h]
  __int64 v41; // [xsp+108h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( dword_204EB0 && (v0 = (void (__fastcall *)(__int64, _QWORD))off_204E90) != nullptr )
  {
    v1 = qword_204EB8;
    if ( *((_DWORD *)off_204E90 - 1) != 1109313945 )
      __break(0x8228u);
    v0(v1, 0);
    result = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deferred_deactivate)((unsigned int)dword_204ECC);
    if ( (_DWORD)result )
    {
      v3 = result;
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipa_wdi %s:%d fail to deactivate ipa pm\n",
          "ipa_wdi_opt_dpath_remove_all_ctrl_filter_req",
          1875);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipa_wdi %s:%d fail to deactivate ipa pm\n",
          "ipa_wdi_opt_dpath_remove_all_ctrl_filter_req",
          1875);
      }
      result = v3;
    }
  }
  else
  {
    printk(&unk_3A87C7, "ipa_wdi_opt_dpath_remove_all_ctrl_filter_req");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(
          v7,
          "ipa %s:%d ctrl filter remove cb not registered",
          "ipa_wdi_opt_dpath_remove_all_ctrl_filter_req",
          1863);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(
          v8,
          "ipa %s:%d ctrl filter remove cb not registered",
          "ipa_wdi_opt_dpath_remove_all_ctrl_filter_req",
          1863);
    }
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
    v21 = 0;
    v22 = 0;
    v19 = 0;
    v20 = 0;
    v17 = 0;
    v18 = 0;
    v15 = 0;
    v16 = 0;
    v13 = 0;
    v14 = 0;
    v11 = 0;
    v12 = 0;
    *(_QWORD *)s = 0;
    v10 = 0;
    snprintf(
      s,
      0x100u,
      "ipa-event-log %s:%d ctrl filter remove cb not registered",
      "ipa_wdi_opt_dpath_remove_all_ctrl_filter_req",
      1864);
    ipa3_send_opt_log_msg(s);
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
