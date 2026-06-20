__int64 __fastcall ipa_wdi_opt_dpath_add_filter_req(int *a1, __int64 a2)
{
  int v4; // w3
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x11
  __int64 v8; // x8
  int v9; // w21
  int v10; // w22
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w21
  unsigned int v14; // w22
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 (__fastcall *v18)(__int64, __int64 *); // x9
  __int64 v19; // x0
  unsigned int v20; // w21
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  int v24; // w8
  int v25; // w10
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  int v33; // w5
  char s[8]; // [xsp+30h] [xbp-200h] BYREF
  __int64 v35; // [xsp+38h] [xbp-1F8h]
  __int64 v36; // [xsp+40h] [xbp-1F0h]
  __int64 v37; // [xsp+48h] [xbp-1E8h]
  __int64 v38; // [xsp+50h] [xbp-1E0h]
  __int64 v39; // [xsp+58h] [xbp-1D8h]
  __int64 v40; // [xsp+60h] [xbp-1D0h]
  __int64 v41; // [xsp+68h] [xbp-1C8h]
  __int64 v42; // [xsp+70h] [xbp-1C0h]
  __int64 v43; // [xsp+78h] [xbp-1B8h]
  __int64 v44; // [xsp+80h] [xbp-1B0h]
  __int64 v45; // [xsp+88h] [xbp-1A8h]
  __int64 v46; // [xsp+90h] [xbp-1A0h]
  __int64 v47; // [xsp+98h] [xbp-198h]
  __int64 v48; // [xsp+A0h] [xbp-190h]
  __int64 v49; // [xsp+A8h] [xbp-188h]
  __int64 v50; // [xsp+B0h] [xbp-180h]
  __int64 v51; // [xsp+B8h] [xbp-178h]
  __int64 v52; // [xsp+C0h] [xbp-170h]
  __int64 v53; // [xsp+C8h] [xbp-168h]
  __int64 v54; // [xsp+D0h] [xbp-160h]
  __int64 v55; // [xsp+D8h] [xbp-158h]
  __int64 v56; // [xsp+E0h] [xbp-150h]
  __int64 v57; // [xsp+E8h] [xbp-148h]
  __int64 v58; // [xsp+F0h] [xbp-140h]
  __int64 v59; // [xsp+F8h] [xbp-138h]
  __int64 v60; // [xsp+100h] [xbp-130h]
  __int64 v61; // [xsp+108h] [xbp-128h]
  __int64 v62; // [xsp+110h] [xbp-120h]
  __int64 v63; // [xsp+118h] [xbp-118h]
  __int64 v64; // [xsp+120h] [xbp-110h]
  __int64 v65; // [xsp+128h] [xbp-108h]
  __int64 v66; // [xsp+130h] [xbp-100h] BYREF
  unsigned __int64 v67; // [xsp+138h] [xbp-F8h]
  __int64 v68; // [xsp+140h] [xbp-F0h]
  __int64 v69; // [xsp+148h] [xbp-E8h]
  __int64 v70; // [xsp+150h] [xbp-E0h]
  __int64 v71; // [xsp+158h] [xbp-D8h]
  __int64 v72; // [xsp+160h] [xbp-D0h]
  __int64 v73; // [xsp+168h] [xbp-C8h]
  __int64 v74; // [xsp+170h] [xbp-C0h]
  __int64 v75; // [xsp+178h] [xbp-B8h]
  __int64 v76; // [xsp+180h] [xbp-B0h]
  __int64 v77; // [xsp+188h] [xbp-A8h]
  __int64 v78; // [xsp+190h] [xbp-A0h]
  __int64 v79; // [xsp+198h] [xbp-98h]
  __int64 v80; // [xsp+1A0h] [xbp-90h]
  __int64 v81; // [xsp+1A8h] [xbp-88h]
  __int64 v82; // [xsp+1B0h] [xbp-80h]
  __int64 v83; // [xsp+1B8h] [xbp-78h]
  __int64 v84; // [xsp+1C0h] [xbp-70h]
  __int64 v85; // [xsp+1C8h] [xbp-68h]
  __int64 v86; // [xsp+1D0h] [xbp-60h]
  __int64 v87; // [xsp+1D8h] [xbp-58h]
  __int64 v88; // [xsp+1E0h] [xbp-50h]
  __int64 v89; // [xsp+1E8h] [xbp-48h]
  __int64 v90; // [xsp+1F0h] [xbp-40h]
  __int64 v91; // [xsp+1F8h] [xbp-38h]
  __int64 v92; // [xsp+200h] [xbp-30h]
  __int64 v93; // [xsp+208h] [xbp-28h]
  __int64 v94; // [xsp+210h] [xbp-20h]
  __int64 v95; // [xsp+218h] [xbp-18h]
  int v96; // [xsp+220h] [xbp-10h]
  __int64 v97; // [xsp+228h] [xbp-8h]

  v97 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
  v66 = 0;
  v67 = 0;
  v68 = 0;
  v69 = 0;
  v70 = 0;
  v71 = 0;
  v72 = 0;
  v73 = 0;
  v74 = 0;
  v75 = 0;
  v76 = 0;
  v77 = 0;
  v78 = 0;
  v79 = 0;
  v80 = 0;
  v81 = 0;
  v82 = 0;
  v83 = 0;
  v84 = 0;
  v85 = 0;
  v86 = 0;
  v87 = 0;
  v88 = 0;
  v89 = 0;
  v90 = 0;
  v91 = 0;
  v92 = 0;
  v93 = 0;
  v94 = 0;
  v95 = 0;
  v96 = 0;
  if ( !dword_204EAC )
  {
    printk(&unk_3C898A, "ipa_wdi_opt_dpath_add_filter_req");
    v27 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v28 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v28 )
      {
        ipc_log_string(v28, "ipa %s:%d filter add cb not registered", "ipa_wdi_opt_dpath_add_filter_req", 1423);
        v27 = ipa3_ctx;
      }
      v29 = *(_QWORD *)(v27 + 34160);
      if ( v29 )
        ipc_log_string(v29, "ipa %s:%d filter add cb not registered", "ipa_wdi_opt_dpath_add_filter_req", 1423);
    }
    v64 = 0;
    v65 = 0;
    v62 = 0;
    v63 = 0;
    v60 = 0;
    v61 = 0;
    v58 = 0;
    v59 = 0;
    v56 = 0;
    v57 = 0;
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    v50 = 0;
    v51 = 0;
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
    *(_QWORD *)s = 0;
    v35 = 0;
    snprintf(s, 0x100u, "ipa-event-log %s:%d filter add cb not registered", "ipa_wdi_opt_dpath_add_filter_req", 1424);
    goto LABEL_38;
  }
  v4 = a1[1];
  if ( (unsigned int)(v4 - 1) >= 2 )
  {
    printk(&unk_3B9D65, "ipa_wdi_opt_dpath_add_filter_req");
    v30 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v31 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v31 )
      {
        ipc_log_string(v31, "ipa %s:%d Invalid IP Type: %d\n", "ipa_wdi_opt_dpath_add_filter_req", 1433, a1[1]);
        v30 = ipa3_ctx;
      }
      v32 = *(_QWORD *)(v30 + 34160);
      if ( v32 )
        ipc_log_string(v32, "ipa %s:%d Invalid IP Type: %d\n", "ipa_wdi_opt_dpath_add_filter_req", 1433, a1[1]);
    }
    v33 = a1[1];
    v64 = 0;
    v65 = 0;
    v62 = 0;
    v63 = 0;
    v60 = 0;
    v61 = 0;
    v58 = 0;
    v59 = 0;
    v56 = 0;
    v57 = 0;
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    v50 = 0;
    v51 = 0;
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
    *(_QWORD *)s = 0;
    v35 = 0;
    snprintf(s, 0x100u, "ipa-event-log %s:%d Invalid IP Type: %d\n", "ipa_wdi_opt_dpath_add_filter_req", 1434, v33);
LABEL_38:
    ipa3_send_opt_log_msg(s);
    v20 = -1;
    *(_DWORD *)a2 = 196609;
    *(_DWORD *)(a2 + 4) = *a1;
    goto LABEL_25;
  }
  LOBYTE(v66) = 1;
  BYTE4(v66) = v4 != 1;
  if ( v4 == 1 )
  {
    v13 = a1[3];
    v14 = a1[4];
    v15 = ipa3_ctx;
    v67 = __PAIR64__(v14, v13);
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(
          v16,
          "ipa %s:%d IPv4 saddr:0x%x, daddr:0x%x\n",
          "ipa_wdi_opt_dpath_add_filter_req",
          1448,
          v13,
          v14);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(
          v17,
          "ipa %s:%d IPv4 saddr:0x%x, daddr:0x%x\n",
          "ipa_wdi_opt_dpath_add_filter_req",
          1448,
          v13,
          v14);
    }
    v64 = 0;
    v65 = 0;
    v62 = 0;
    v63 = 0;
    v60 = 0;
    v61 = 0;
    v58 = 0;
    v59 = 0;
    v56 = 0;
    v57 = 0;
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    v50 = 0;
    v51 = 0;
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
    *(_QWORD *)s = 0;
    v35 = 0;
    snprintf(
      s,
      0x100u,
      "ipa-event-log %s:%d IPv4 saddr:0x%x, daddr:0x%x\n",
      "ipa_wdi_opt_dpath_add_filter_req",
      1451,
      v13,
      v14);
  }
  else
  {
    v5 = *((_QWORD *)a1 + 4);
    v6 = *((_QWORD *)a1 + 5);
    v7 = *((_QWORD *)a1 + 6);
    v67 = *((_QWORD *)a1 + 3);
    v68 = v5;
    v8 = ipa3_ctx;
    v69 = v6;
    v70 = v7;
    if ( ipa3_ctx )
    {
      v9 = v67;
      v10 = v69;
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(
          v11,
          "ipa %s:%d IPv6 saddr:0x%x:%x:%x:%x, daddr:0x%x:%x:%x:%x\n",
          "ipa_wdi_opt_dpath_add_filter_req",
          1467,
          v67,
          HIDWORD(v67),
          v68,
          HIDWORD(v68),
          v69,
          HIDWORD(v69),
          v70,
          HIDWORD(v70));
        v8 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v8 + 34160);
      if ( v12 )
        ipc_log_string(
          v12,
          "ipa %s:%d IPv6 saddr:0x%x:%x:%x:%x, daddr:0x%x:%x:%x:%x\n",
          "ipa_wdi_opt_dpath_add_filter_req",
          1467,
          v67,
          HIDWORD(v67),
          v68,
          HIDWORD(v68),
          v69,
          HIDWORD(v69),
          v70,
          HIDWORD(v70));
    }
    else
    {
      v9 = v67;
      v10 = v69;
    }
    v64 = 0;
    v65 = 0;
    v62 = 0;
    v63 = 0;
    v60 = 0;
    v61 = 0;
    v58 = 0;
    v59 = 0;
    v56 = 0;
    v57 = 0;
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    v50 = 0;
    v51 = 0;
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
    *(_QWORD *)s = 0;
    v35 = 0;
    snprintf(
      s,
      0x100u,
      "ipa-event-log %s:%d IPv6 saddr:0x%x:%x:%x:%x, daddr:0x%x:%x:%x:%x\n",
      "ipa_wdi_opt_dpath_add_filter_req",
      1476,
      v9,
      HIDWORD(v67),
      v68,
      HIDWORD(v68),
      v10,
      HIDWORD(v69),
      v70,
      HIDWORD(v70));
  }
  ipa3_send_opt_log_msg(s);
  v18 = (__int64 (__fastcall *)(__int64, __int64 *))off_204E78;
  v19 = qword_204EB8;
  if ( *((_DWORD *)off_204E78 - 1) != -1513482081 )
    __break(0x8229u);
  v20 = v18(v19, &v66);
  v21 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v22 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v22 )
    {
      ipc_log_string(v22, "ipa %s:%d flt_add resp from WLAN: %d\n", "ipa_wdi_opt_dpath_add_filter_req", 1484, v20);
      v21 = ipa3_ctx;
    }
    v23 = *(_QWORD *)(v21 + 34160);
    if ( v23 )
      ipc_log_string(v23, "ipa %s:%d flt_add resp from WLAN: %d\n", "ipa_wdi_opt_dpath_add_filter_req", 1484, v20);
  }
  v24 = *a1;
  v25 = v72;
  *(_WORD *)(a2 + 2) = v20;
  *(_DWORD *)(a2 + 4) = v24;
  *(_BYTE *)(a2 + 8) = 1;
  *(_DWORD *)(a2 + 12) = v25;
  *(_WORD *)a2 = v20 != 0;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return v20;
}
