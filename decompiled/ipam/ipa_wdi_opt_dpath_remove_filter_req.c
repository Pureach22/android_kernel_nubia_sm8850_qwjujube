__int64 __fastcall ipa_wdi_opt_dpath_remove_filter_req(int *a1, __int64 a2)
{
  int v4; // w9
  __int64 (__fastcall *v5)(__int64, _QWORD *); // x8
  __int64 v6; // x0
  unsigned int v7; // w21
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  int v11; // w8
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  _QWORD v16[32]; // [xsp+0h] [xbp-120h] BYREF
  _QWORD v17[4]; // [xsp+100h] [xbp-20h] BYREF

  v17[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)a2 = 0;
  memset(v17, 0, 24);
  if ( dword_204EAC )
  {
    v4 = a1[1];
    LOBYTE(v17[0]) = 1;
    v5 = (__int64 (__fastcall *)(__int64, _QWORD *))off_204E80;
    v6 = qword_204EB8;
    HIDWORD(v17[0]) = v4;
    if ( *((_DWORD *)off_204E80 - 1) != 1109313945 )
      __break(0x8228u);
    v7 = v5(v6, v17);
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(
          v9,
          "ipa %s:%d flt_rem_all resp from WLAN: %d\n",
          "ipa_wdi_opt_dpath_remove_filter_req",
          1537,
          v7);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        ipc_log_string(
          v10,
          "ipa %s:%d flt_rem_all resp from WLAN: %d\n",
          "ipa_wdi_opt_dpath_remove_filter_req",
          1537,
          v7);
    }
    v11 = *a1;
    *(_WORD *)(a2 + 2) = v7;
    *(_DWORD *)(a2 + 4) = v11;
    *(_WORD *)a2 = v7 != 0;
  }
  else
  {
    printk(&unk_3A5582, "ipa_wdi_opt_dpath_remove_filter_req");
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d filter remove cb not registered", "ipa_wdi_opt_dpath_remove_filter_req", 1521);
        v13 = ipa3_ctx;
      }
      v15 = *(_QWORD *)(v13 + 34160);
      if ( v15 )
        ipc_log_string(v15, "ipa %s:%d filter remove cb not registered", "ipa_wdi_opt_dpath_remove_filter_req", 1521);
    }
    memset(v16, 0, sizeof(v16));
    snprintf(
      (char *)v16,
      0x100u,
      "ipa-event-log %s:%d filter remove cb not registered",
      "ipa_wdi_opt_dpath_remove_filter_req",
      1522);
    ipa3_send_opt_log_msg((char *)v16);
    *(_DWORD *)a2 = 0;
    v7 = -1;
    *(_DWORD *)(a2 + 4) = *a1;
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
