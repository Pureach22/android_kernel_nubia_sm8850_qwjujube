__int64 __fastcall ipa_wdi_opt_dpath_rsrv_filter_req(__int64 a1, _DWORD *a2)
{
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  int ep_mapping; // w0
  int v11; // w9
  __int64 v12; // x0
  long double v13; // q0
  __int64 v14; // x0
  const char *v15; // x2
  __int64 v16; // x4
  __int64 result; // x0
  int v18; // w9
  unsigned int (__fastcall *v19)(__int64, __int64 *); // x11
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int v37; // w9
  unsigned int v39; // w10
  unsigned int v41; // w10
  __int64 v42; // [xsp+8h] [xbp-168h] BYREF
  char s[8]; // [xsp+10h] [xbp-160h] BYREF
  __int64 v44; // [xsp+18h] [xbp-158h]
  __int64 v45; // [xsp+20h] [xbp-150h]
  __int64 v46; // [xsp+28h] [xbp-148h]
  __int64 v47; // [xsp+30h] [xbp-140h]
  __int64 v48; // [xsp+38h] [xbp-138h]
  __int64 v49; // [xsp+40h] [xbp-130h]
  __int64 v50; // [xsp+48h] [xbp-128h]
  __int64 v51; // [xsp+50h] [xbp-120h]
  __int64 v52; // [xsp+58h] [xbp-118h]
  __int64 v53; // [xsp+60h] [xbp-110h]
  __int64 v54; // [xsp+68h] [xbp-108h]
  __int64 v55; // [xsp+70h] [xbp-100h]
  __int64 v56; // [xsp+78h] [xbp-F8h]
  __int64 v57; // [xsp+80h] [xbp-F0h]
  __int64 v58; // [xsp+88h] [xbp-E8h]
  __int64 v59; // [xsp+90h] [xbp-E0h]
  __int64 v60; // [xsp+98h] [xbp-D8h]
  __int64 v61; // [xsp+A0h] [xbp-D0h]
  __int64 v62; // [xsp+A8h] [xbp-C8h]
  __int64 v63; // [xsp+B0h] [xbp-C0h]
  __int64 v64; // [xsp+B8h] [xbp-B8h]
  __int64 v65; // [xsp+C0h] [xbp-B0h]
  __int64 v66; // [xsp+C8h] [xbp-A8h]
  __int64 v67; // [xsp+D0h] [xbp-A0h]
  __int64 v68; // [xsp+D8h] [xbp-98h]
  __int64 v69; // [xsp+E0h] [xbp-90h]
  __int64 v70; // [xsp+E8h] [xbp-88h]
  __int64 v71; // [xsp+F0h] [xbp-80h]
  __int64 v72; // [xsp+F8h] [xbp-78h]
  __int64 v73; // [xsp+100h] [xbp-70h]
  __int64 v74; // [xsp+108h] [xbp-68h]
  _DWORD v75[4]; // [xsp+114h] [xbp-5Ch] BYREF
  __int64 v76; // [xsp+124h] [xbp-4Ch]
  __int64 v77; // [xsp+12Ch] [xbp-44h]
  __int64 v78; // [xsp+134h] [xbp-3Ch]
  __int64 v79; // [xsp+13Ch] [xbp-34h]
  __int64 v80; // [xsp+144h] [xbp-2Ch]
  __int64 v81; // [xsp+14Ch] [xbp-24h]
  __int64 v82; // [xsp+154h] [xbp-1Ch]
  __int64 v83; // [xsp+15Ch] [xbp-14h]
  int v84; // [xsp+164h] [xbp-Ch]
  __int64 v85; // [xsp+168h] [xbp-8h]

  v85 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a2 = 0;
  v76 = 0;
  v77 = 0;
  v78 = 0;
  v79 = 0;
  v80 = 0;
  v81 = 0;
  v82 = 0;
  v83 = 0;
  _X8 = (unsigned int *)(ipa3_ctx + 33056);
  v42 = 0;
  v84 = 0;
  __asm { PRFM            #0x11, [X8] }
  do
    v37 = __ldxr(_X8);
  while ( __stxr(v37 + 1, _X8) );
  if ( !dword_204EAC )
  {
    printk(&unk_3B6B7D, "ipa_wdi_opt_dpath_rsrv_filter_req");
    v27 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v28 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v28 )
      {
        ipc_log_string(v28, "ipa %s:%d filter reserve cb not registered", "ipa_wdi_opt_dpath_rsrv_filter_req", 1320);
        v27 = ipa3_ctx;
      }
      v29 = *(_QWORD *)(v27 + 34160);
      if ( v29 )
        ipc_log_string(v29, "ipa %s:%d filter reserve cb not registered", "ipa_wdi_opt_dpath_rsrv_filter_req", 1320);
    }
    v73 = 0;
    v74 = 0;
    v71 = 0;
    v72 = 0;
    v69 = 0;
    v70 = 0;
    v67 = 0;
    v68 = 0;
    v65 = 0;
    v66 = 0;
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
    *(_QWORD *)s = 0;
    v44 = 0;
    snprintf(
      s,
      0x100u,
      "ipa-event-log %s:%d filter reserve cb not registered",
      "ipa_wdi_opt_dpath_rsrv_filter_req",
      1321);
    ipa3_send_opt_log_msg(s);
    goto LABEL_54;
  }
  if ( (int)qword_204EC0 < 1 || SHIDWORD(qword_204EC0) <= 0 )
  {
    printk(&unk_3CB217, "ipa_wdi_opt_dpath_rsrv_filter_req");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_wdi %s:%d Either TX/RX ep is not configured. \n",
        "ipa_wdi_opt_dpath_rsrv_filter_req",
        1328);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_wdi %s:%d Either TX/RX ep is not configured. \n",
        "ipa_wdi_opt_dpath_rsrv_filter_req",
        1328);
    }
LABEL_54:
    result = 0xFFFFFFFFLL;
    goto LABEL_26;
  }
  v5 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v6 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d ep_tx = %d\n", "ipa_wdi_opt_dpath_rsrv_filter_req", 1334, qword_204EC0);
      v5 = ipa3_ctx;
    }
    v7 = *(_QWORD *)(v5 + 34160);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d ep_tx = %d\n", "ipa_wdi_opt_dpath_rsrv_filter_req", 1334, qword_204EC0);
      v5 = ipa3_ctx;
    }
    if ( v5 )
    {
      v8 = *(_QWORD *)(v5 + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d ep_rx = %d\n", "ipa_wdi_opt_dpath_rsrv_filter_req", 1335, HIDWORD(qword_204EC0));
        v5 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v5 + 34160);
      if ( v9 )
        ipc_log_string(v9, "ipa %s:%d ep_rx = %d\n", "ipa_wdi_opt_dpath_rsrv_filter_req", 1335, HIDWORD(qword_204EC0));
    }
  }
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
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
  *(_QWORD *)s = 0;
  v44 = 0;
  snprintf(
    s,
    0x100u,
    "ipa-event-log %s:%d rsrv_filter_req: ep_tx = %d, ep_rx = %d\n",
    "ipa_wdi_opt_dpath_rsrv_filter_req",
    1338,
    qword_204EC0,
    HIDWORD(qword_204EC0));
  ipa3_send_opt_log_msg(s);
  v75[0] = HIDWORD(qword_204EC0);
  v75[1] = qword_204EC0;
  ep_mapping = ipa_get_ep_mapping(33);
  if ( dword_204EA4 )
    v11 = dword_204EA4;
  else
    v11 = 14;
  v75[2] = ep_mapping;
  v75[3] = v11;
  if ( (unsigned int)ipa_pm_activate_sync(dword_204EC8) )
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      v12 = ipa3_get_ipc_logbuf();
      ipc_log_string(v12, "ipa_wdi %s:%d fail to activate ipa pm\n", "ipa_wdi_opt_dpath_rsrv_filter_req", 1349);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v14 = ipa3_get_ipc_logbuf_low();
      v13 = ipc_log_string(v14, "ipa_wdi %s:%d fail to activate ipa pm\n", "ipa_wdi_opt_dpath_rsrv_filter_req", 1349);
    }
    v73 = 0;
    v74 = 0;
    v15 = "ipa-event-log %s:%d fail to activate ipa pm\n";
    v71 = 0;
    v72 = 0;
    v69 = 0;
    v70 = 0;
    v67 = 0;
    v68 = 0;
    v16 = 1350;
    goto LABEL_24;
  }
  ipa3_qmi_send_wdi_opt_dpath_ep_info((__int64)v75);
  v18 = *(_DWORD *)(a1 + 4);
  v19 = (unsigned int (__fastcall *)(__int64, __int64 *))opt_dpath_info;
  v20 = qword_204EB8;
  LOBYTE(v42) = *(_BYTE *)a1;
  HIDWORD(v42) = v18;
  if ( *((_DWORD *)opt_dpath_info - 1) != 778304514 )
    __break(0x822Bu);
  if ( v19(v20, &v42) )
  {
    if ( !(unsigned int)((__int64 (__fastcall *)(_QWORD))ipa_pm_deferred_deactivate)((unsigned int)dword_204EC8) )
      goto LABEL_25;
    if ( ipa3_get_ipc_logbuf() )
    {
      v21 = ipa3_get_ipc_logbuf();
      ipc_log_string(v21, "ipa_wdi %s:%d fail to deactivate ipa pm\n", "ipa_wdi_opt_dpath_rsrv_filter_req", 1378);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v22 = ipa3_get_ipc_logbuf_low();
      v13 = ipc_log_string(v22, "ipa_wdi %s:%d fail to deactivate ipa pm\n", "ipa_wdi_opt_dpath_rsrv_filter_req", 1378);
    }
    v15 = "ipa-event-log %s:%d fail to deactivate ipa pm\n";
    v16 = 1379;
    v73 = 0;
    v74 = 0;
    v71 = 0;
    v72 = 0;
    v69 = 0;
    v70 = 0;
    v67 = 0;
    v68 = 0;
LABEL_24:
    v65 = 0;
    v66 = 0;
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
    *(_QWORD *)s = 0;
    v44 = 0;
    snprintf(s, 0x100u, v15, "ipa_wdi_opt_dpath_rsrv_filter_req", v16, *(double *)&v13);
    ipa3_send_opt_log_msg(s);
LABEL_25:
    result = 4294967282LL;
LABEL_26:
    *a2 = 196609;
    goto LABEL_27;
  }
  dword_204EA8 = 1;
  dword_204EA0 = *(_DWORD *)(a1 + 8);
  _X9 = (unsigned int *)(ipa3_ctx + 33060);
  __asm { PRFM            #0x11, [X9] }
  do
    v39 = __ldxr(_X9);
  while ( __stxr(v39 + 1, _X9) );
  _X9 = (unsigned int *)(ipa3_ctx + 33060);
  if ( !*(_DWORD *)(ipa3_ctx + 33060) )
  {
    __asm { PRFM            #0x11, [X9] }
    do
      v41 = __ldxr(_X9);
    while ( __stxr(v41 + 1, _X9) );
  }
  ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))ipa3_enable_wdi3_opt_dpath)(
    HIDWORD(qword_204EC0),
    (unsigned int)qword_204EC0,
    (unsigned int)dword_204EA0);
  *a2 = 0;
  if ( ipa3_get_ipc_logbuf() )
  {
    v25 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v25,
      "ipa_wdi %s:%d rsrv_flt_req: %d, res_req_succs: %d\n",
      "ipa_wdi_opt_dpath_rsrv_filter_req",
      1390,
      *(_DWORD *)(ipa3_ctx + 33056),
      *(_DWORD *)(ipa3_ctx + 33060));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v26 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v26,
      "ipa_wdi %s:%d rsrv_flt_req: %d, res_req_succs: %d\n",
      "ipa_wdi_opt_dpath_rsrv_filter_req",
      1390,
      *(_DWORD *)(ipa3_ctx + 33056),
      *(_DWORD *)(ipa3_ctx + 33060));
  }
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
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
  *(_QWORD *)s = 0;
  v44 = 0;
  snprintf(
    s,
    0x100u,
    "ipa-event-log %s:%d rsrv_filter_req: %d, res_req_succ: %d\n",
    "ipa_wdi_opt_dpath_rsrv_filter_req",
    1393,
    *(_DWORD *)(ipa3_ctx + 33056),
    *(_DWORD *)(ipa3_ctx + 33060));
  ipa3_send_opt_log_msg(s);
  result = 0;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
