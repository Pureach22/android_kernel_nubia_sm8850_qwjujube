__int64 __fastcall ipa_wdi_opt_dpath_remove_all_filter_req(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v3)(__int64); // x9
  __int64 v4; // x0
  int v5; // w20
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
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
  *(_DWORD *)a2 = 0;
  if ( dword_204EAC )
  {
    if ( dword_204EA8 )
    {
      v3 = (__int64 (__fastcall *)(__int64))off_204E70;
      v4 = qword_204EB8;
      if ( *((_DWORD *)off_204E70 - 1) != -1066802076 )
        __break(0x8229u);
      v5 = v3(v4);
      v6 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v7 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v7 )
        {
          ipc_log_string(
            v7,
            "ipa %s:%d flt_rem_all ret from WLAN: %d\n",
            "ipa_wdi_opt_dpath_remove_all_filter_req",
            1587,
            v5);
          v6 = ipa3_ctx;
        }
        v8 = *(_QWORD *)(v6 + 34160);
        if ( v8 )
          ipc_log_string(
            v8,
            "ipa %s:%d flt_rem_all ret from WLAN: %d\n",
            "ipa_wdi_opt_dpath_remove_all_filter_req",
            1587,
            v5);
      }
      *(_WORD *)(a2 + 2) = v5;
      if ( v5 )
        result = 0xFFFFFFFFLL;
      else
        result = 0;
      *(_WORD *)a2 = v5 != 0;
    }
    else
    {
      printk(&unk_3D14C1, "ipa_wdi_opt_dpath_remove_all_filter_req");
      v13 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v14 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v14 )
        {
          ipc_log_string(
            v14,
            "ipa %s:%d Reservation request not sent. IGNORE",
            "ipa_wdi_opt_dpath_remove_all_filter_req",
            1578);
          v13 = ipa3_ctx;
        }
        v15 = *(_QWORD *)(v13 + 34160);
        if ( v15 )
          ipc_log_string(
            v15,
            "ipa %s:%d Reservation request not sent. IGNORE",
            "ipa_wdi_opt_dpath_remove_all_filter_req",
            1578);
      }
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
        "ipa-event-log %s:%d Reservation request not sent. IGNORE",
        "ipa_wdi_opt_dpath_remove_all_filter_req",
        1579);
      ipa3_send_opt_log_msg(s);
      result = 0;
    }
  }
  else
  {
    printk(&unk_3FFAA7, "ipa_wdi_opt_dpath_remove_all_filter_req");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(
          v11,
          "ipa %s:%d filter release cb not registered",
          "ipa_wdi_opt_dpath_remove_all_filter_req",
          1571);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(
          v12,
          "ipa %s:%d filter release cb not registered",
          "ipa_wdi_opt_dpath_remove_all_filter_req",
          1571);
    }
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
      "ipa-event-log %s:%d filter release cb not registered",
      "ipa_wdi_opt_dpath_remove_all_filter_req",
      1572);
    ipa3_send_opt_log_msg(s);
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
