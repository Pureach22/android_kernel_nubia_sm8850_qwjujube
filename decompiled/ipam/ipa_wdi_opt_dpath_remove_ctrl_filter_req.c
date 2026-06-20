__int64 __fastcall ipa_wdi_opt_dpath_remove_ctrl_filter_req(_DWORD *a1, __int64 a2)
{
  __int64 (__fastcall *v4)(__int64, _QWORD *); // x8
  int v5; // w10
  __int64 v6; // x0
  int v7; // w0
  int v9; // w21
  __int16 v10; // w8
  __int64 result; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int v20; // w10
  __int64 v21; // [xsp+0h] [xbp-120h] BYREF
  __int64 v22; // [xsp+8h] [xbp-118h]
  __int64 v23; // [xsp+10h] [xbp-110h]
  __int64 v24; // [xsp+18h] [xbp-108h]
  __int64 v25; // [xsp+20h] [xbp-100h]
  __int64 v26; // [xsp+28h] [xbp-F8h]
  __int64 v27; // [xsp+30h] [xbp-F0h]
  __int64 v28; // [xsp+38h] [xbp-E8h]
  __int64 v29; // [xsp+40h] [xbp-E0h]
  __int64 v30; // [xsp+48h] [xbp-D8h]
  __int64 v31; // [xsp+50h] [xbp-D0h]
  __int64 v32; // [xsp+58h] [xbp-C8h]
  __int64 v33; // [xsp+60h] [xbp-C0h]
  __int64 v34; // [xsp+68h] [xbp-B8h]
  __int64 v35; // [xsp+70h] [xbp-B0h]
  __int64 v36; // [xsp+78h] [xbp-A8h]
  __int64 v37; // [xsp+80h] [xbp-A0h]
  __int64 v38; // [xsp+88h] [xbp-98h]
  __int64 v39; // [xsp+90h] [xbp-90h]
  __int64 v40; // [xsp+98h] [xbp-88h]
  __int64 v41; // [xsp+A0h] [xbp-80h]
  __int64 v42; // [xsp+A8h] [xbp-78h]
  __int64 v43; // [xsp+B0h] [xbp-70h]
  __int64 v44; // [xsp+B8h] [xbp-68h]
  __int64 v45; // [xsp+C0h] [xbp-60h]
  __int64 v46; // [xsp+C8h] [xbp-58h]
  __int64 v47; // [xsp+D0h] [xbp-50h]
  __int64 v48; // [xsp+D8h] [xbp-48h]
  __int64 v49; // [xsp+E0h] [xbp-40h]
  __int64 v50; // [xsp+E8h] [xbp-38h]
  __int64 v51; // [xsp+F0h] [xbp-30h]
  __int64 v52; // [xsp+F8h] [xbp-28h]
  _QWORD v53[4]; // [xsp+100h] [xbp-20h] BYREF

  v53[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v53, 0, 24);
  *(_QWORD *)a2 = 0;
  if ( dword_204EB0 && (v4 = (__int64 (__fastcall *)(__int64, _QWORD *))off_204E90) != nullptr )
  {
    v5 = a1[1];
    v6 = qword_204EB8;
    LOBYTE(v53[0]) = 1;
    HIDWORD(v53[0]) = v5;
    if ( *((_DWORD *)off_204E90 - 1) != 1109313945 )
      __break(0x8228u);
    v7 = v4(v6, v53);
    *(_WORD *)(a2 + 2) = v7;
    if ( v7 )
      _ZF = v7 == 201;
    else
      _ZF = 1;
    v9 = v7;
    v10 = !_ZF;
    *(_WORD *)a2 = v10;
    *(_DWORD *)(a2 + 4) = *a1;
    _X9 = (unsigned int *)(ipa3_ctx + 33080);
    __asm { PRFM            #0x11, [X9] }
    do
      v20 = __ldxr(_X9);
    while ( __stxr(v20 + 1, _X9) );
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
    v23 = 0;
    v24 = 0;
    v21 = 0;
    v22 = 0;
    snprintf(
      (char *)&v21,
      0x100u,
      "ipa-event-log %s:%d add_ctrl_flt_req_count: %d, rm_ctrl_flt_req_count: %d\n",
      "ipa_wdi_opt_dpath_remove_ctrl_filter_req",
      1843,
      *(_DWORD *)(ipa3_ctx + 33072),
      *(_DWORD *)(ipa3_ctx + 33080));
    ipa3_send_opt_log_msg((char *)&v21);
    if ( v9 == 202 )
      result = 0xFFFFFFFFLL;
    else
      result = 0;
  }
  else
  {
    printk(&unk_3A5582, "ipa_wdi_opt_dpath_remove_ctrl_filter_req");
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(
          v14,
          "ipa %s:%d filter remove cb not registered",
          "ipa_wdi_opt_dpath_remove_ctrl_filter_req",
          1818);
        v13 = ipa3_ctx;
      }
      v15 = *(_QWORD *)(v13 + 34160);
      if ( v15 )
        ipc_log_string(
          v15,
          "ipa %s:%d filter remove cb not registered",
          "ipa_wdi_opt_dpath_remove_ctrl_filter_req",
          1818);
    }
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
    v23 = 0;
    v24 = 0;
    v21 = 0;
    v22 = 0;
    snprintf(
      (char *)&v21,
      0x100u,
      "ipa-event-log %s:%d filter remove cb not registered",
      "ipa_wdi_opt_dpath_remove_ctrl_filter_req",
      1819);
    ipa3_send_opt_log_msg((char *)&v21);
    *(_DWORD *)a2 = 0;
    result = 0xFFFFFFFFLL;
    *(_DWORD *)(a2 + 4) = *a1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
