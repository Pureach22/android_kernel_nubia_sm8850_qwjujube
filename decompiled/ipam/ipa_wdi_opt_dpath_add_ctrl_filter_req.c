__int64 __fastcall ipa_wdi_opt_dpath_add_ctrl_filter_req(int *a1, __int64 a2)
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
  int v18; // w21
  int v19; // w22
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 (__fastcall *v23)(__int64, __int64 *); // x8
  __int64 v24; // x0
  unsigned int v25; // w21
  __int64 *v26; // x8
  int v27; // w10
  int v28; // w8
  int v29; // w9
  __int64 v30; // x10
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  unsigned int v47; // w9
  char s[8]; // [xsp+30h] [xbp-200h] BYREF
  __int64 v49; // [xsp+38h] [xbp-1F8h]
  __int64 v50; // [xsp+40h] [xbp-1F0h]
  __int64 v51; // [xsp+48h] [xbp-1E8h]
  __int64 v52; // [xsp+50h] [xbp-1E0h]
  __int64 v53; // [xsp+58h] [xbp-1D8h]
  __int64 v54; // [xsp+60h] [xbp-1D0h]
  __int64 v55; // [xsp+68h] [xbp-1C8h]
  __int64 v56; // [xsp+70h] [xbp-1C0h]
  __int64 v57; // [xsp+78h] [xbp-1B8h]
  __int64 v58; // [xsp+80h] [xbp-1B0h]
  __int64 v59; // [xsp+88h] [xbp-1A8h]
  __int64 v60; // [xsp+90h] [xbp-1A0h]
  __int64 v61; // [xsp+98h] [xbp-198h]
  __int64 v62; // [xsp+A0h] [xbp-190h]
  __int64 v63; // [xsp+A8h] [xbp-188h]
  __int64 v64; // [xsp+B0h] [xbp-180h]
  __int64 v65; // [xsp+B8h] [xbp-178h]
  __int64 v66; // [xsp+C0h] [xbp-170h]
  __int64 v67; // [xsp+C8h] [xbp-168h]
  __int64 v68; // [xsp+D0h] [xbp-160h]
  __int64 v69; // [xsp+D8h] [xbp-158h]
  __int64 v70; // [xsp+E0h] [xbp-150h]
  __int64 v71; // [xsp+E8h] [xbp-148h]
  __int64 v72; // [xsp+F0h] [xbp-140h]
  __int64 v73; // [xsp+F8h] [xbp-138h]
  __int64 v74; // [xsp+100h] [xbp-130h]
  __int64 v75; // [xsp+108h] [xbp-128h]
  __int64 v76; // [xsp+110h] [xbp-120h]
  __int64 v77; // [xsp+118h] [xbp-118h]
  __int64 v78; // [xsp+120h] [xbp-110h]
  __int64 v79; // [xsp+128h] [xbp-108h]
  __int64 v80; // [xsp+130h] [xbp-100h] BYREF
  unsigned __int64 v81; // [xsp+138h] [xbp-F8h]
  __int64 v82; // [xsp+140h] [xbp-F0h]
  __int64 v83; // [xsp+148h] [xbp-E8h]
  __int64 v84; // [xsp+150h] [xbp-E0h]
  __int64 v85; // [xsp+158h] [xbp-D8h]
  __int64 v86; // [xsp+160h] [xbp-D0h]
  __int64 v87; // [xsp+168h] [xbp-C8h]
  __int64 v88; // [xsp+170h] [xbp-C0h]
  __int64 v89; // [xsp+178h] [xbp-B8h]
  __int64 v90; // [xsp+180h] [xbp-B0h]
  __int64 v91; // [xsp+188h] [xbp-A8h]
  __int64 v92; // [xsp+190h] [xbp-A0h]
  __int64 v93; // [xsp+198h] [xbp-98h]
  __int64 v94; // [xsp+1A0h] [xbp-90h]
  __int64 v95; // [xsp+1A8h] [xbp-88h]
  __int64 v96; // [xsp+1B0h] [xbp-80h]
  __int64 v97; // [xsp+1B8h] [xbp-78h]
  __int64 v98; // [xsp+1C0h] [xbp-70h]
  __int64 v99; // [xsp+1C8h] [xbp-68h]
  __int64 v100; // [xsp+1D0h] [xbp-60h]
  __int64 v101; // [xsp+1D8h] [xbp-58h]
  __int64 v102; // [xsp+1E0h] [xbp-50h]
  __int64 v103; // [xsp+1E8h] [xbp-48h]
  __int64 v104; // [xsp+1F0h] [xbp-40h]
  __int64 v105; // [xsp+1F8h] [xbp-38h]
  __int64 v106; // [xsp+200h] [xbp-30h]
  __int64 v107; // [xsp+208h] [xbp-28h]
  __int64 v108; // [xsp+210h] [xbp-20h]
  __int64 v109; // [xsp+218h] [xbp-18h]
  int v110; // [xsp+220h] [xbp-10h]
  __int64 v111; // [xsp+228h] [xbp-8h]

  v111 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
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
  v97 = 0;
  v98 = 0;
  v99 = 0;
  v100 = 0;
  v101 = 0;
  v102 = 0;
  v103 = 0;
  v104 = 0;
  v105 = 0;
  v106 = 0;
  v107 = 0;
  v108 = 0;
  v109 = 0;
  v110 = 0;
  if ( !dword_204EB0 || !off_204E88 )
  {
    printk(&unk_3C898A, "ipa_wdi_opt_dpath_add_ctrl_filter_req");
    v33 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v34 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v34 )
      {
        ipc_log_string(v34, "ipa %s:%d filter add cb not registered", "ipa_wdi_opt_dpath_add_ctrl_filter_req", 1659);
        v33 = ipa3_ctx;
      }
      v35 = *(_QWORD *)(v33 + 34160);
      if ( v35 )
        ipc_log_string(v35, "ipa %s:%d filter add cb not registered", "ipa_wdi_opt_dpath_add_ctrl_filter_req", 1659);
    }
    goto LABEL_41;
  }
  v4 = a1[1];
  if ( (unsigned int)(v4 - 1) >= 2 )
  {
    printk(&unk_3B9D65, "ipa_wdi_opt_dpath_add_ctrl_filter_req");
    v36 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v37 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v37 )
      {
        ipc_log_string(v37, "ipa %s:%d Invalid IP Type: %d\n", "ipa_wdi_opt_dpath_add_ctrl_filter_req", 1668, a1[1]);
        v36 = ipa3_ctx;
      }
      v38 = *(_QWORD *)(v36 + 34160);
      if ( v38 )
        ipc_log_string(v38, "ipa %s:%d Invalid IP Type: %d\n", "ipa_wdi_opt_dpath_add_ctrl_filter_req", 1668, a1[1]);
    }
    goto LABEL_41;
  }
  LOBYTE(v80) = 1;
  BYTE4(v80) = v4 != 1;
  if ( v4 == 1 )
  {
    v13 = a1[3];
    v14 = a1[4];
    v15 = ipa3_ctx;
    v81 = __PAIR64__(v14, v13);
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(
          v16,
          "ipa %s:%d IPv4 saddr:0x%x, daddr:0x%x\n",
          "ipa_wdi_opt_dpath_add_ctrl_filter_req",
          1682,
          v13,
          v14);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(
          v17,
          "ipa %s:%d IPv4 saddr:0x%x, daddr:0x%x\n",
          "ipa_wdi_opt_dpath_add_ctrl_filter_req",
          1682,
          v13,
          v14);
    }
  }
  else
  {
    v5 = *((_QWORD *)a1 + 4);
    v6 = *((_QWORD *)a1 + 5);
    v7 = *((_QWORD *)a1 + 6);
    v81 = *((_QWORD *)a1 + 3);
    v82 = v5;
    v8 = ipa3_ctx;
    v83 = v6;
    v84 = v7;
    if ( ipa3_ctx )
    {
      v9 = v81;
      v10 = v83;
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(
          v11,
          "ipa %s:%d IPv6 saddr:0x%x:%x:%x:%x, daddr:0x%x:%x:%x:%x\n",
          "ipa_wdi_opt_dpath_add_ctrl_filter_req",
          1698,
          v81,
          HIDWORD(v81),
          v82,
          HIDWORD(v82),
          v83,
          HIDWORD(v83),
          v84,
          HIDWORD(v84));
        v8 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v8 + 34160);
      if ( v12 )
        ipc_log_string(
          v12,
          "ipa %s:%d IPv6 saddr:0x%x:%x:%x:%x, daddr:0x%x:%x:%x:%x\n",
          "ipa_wdi_opt_dpath_add_ctrl_filter_req",
          1698,
          v81,
          HIDWORD(v81),
          v82,
          HIDWORD(v82),
          v83,
          HIDWORD(v83),
          v84,
          HIDWORD(v84));
    }
    else
    {
      v9 = v81;
      v10 = v83;
    }
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = 0;
    v72 = 0;
    v73 = 0;
    v70 = 0;
    v71 = 0;
    v68 = 0;
    v69 = 0;
    v66 = 0;
    v67 = 0;
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
    *(_QWORD *)s = 0;
    v49 = 0;
    snprintf(
      s,
      0x100u,
      "ipa-event-log %s:%d IPv6 saddr:0x%x:%x:%x:%x, daddr:0x%x:%x:%x:%x\n",
      "ipa_wdi_opt_dpath_add_ctrl_filter_req",
      1707,
      v9,
      HIDWORD(v81),
      v82,
      HIDWORD(v82),
      v10,
      HIDWORD(v83),
      v84,
      HIDWORD(v84));
    ipa3_send_opt_log_msg(s);
  }
  v18 = *((unsigned __int16 *)a1 + 29);
  v19 = *((unsigned __int16 *)a1 + 31);
  LOBYTE(v85) = 17;
  v20 = ipa3_ctx;
  WORD1(v85) = v18;
  WORD2(v85) = v19;
  if ( ipa3_ctx )
  {
    v21 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v21 )
    {
      ipc_log_string(
        v21,
        "ipa %s:%d Src_port:0x%x, dst_port:0x%x\n",
        "ipa_wdi_opt_dpath_add_ctrl_filter_req",
        1714,
        v18,
        v19);
      v20 = ipa3_ctx;
    }
    v22 = *(_QWORD *)(v20 + 34160);
    if ( v22 )
      ipc_log_string(
        v22,
        "ipa %s:%d Src_port:0x%x, dst_port:0x%x\n",
        "ipa_wdi_opt_dpath_add_ctrl_filter_req",
        1714,
        v18,
        v19);
  }
  v78 = 0;
  v79 = 0;
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
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
  *(_QWORD *)s = 0;
  v49 = 0;
  snprintf(
    s,
    0x100u,
    "ipa-event-log %s:%d Src_port:0x%x, dst_port:0x%x\n",
    "ipa_wdi_opt_dpath_add_ctrl_filter_req",
    1717,
    v18,
    v19);
  ipa3_send_opt_log_msg(s);
  v23 = (__int64 (__fastcall *)(__int64, __int64 *))off_204E88;
  v24 = qword_204EB8;
  if ( *((_DWORD *)off_204E88 - 1) != -1513482081 )
    __break(0x8228u);
  v25 = v23(v24, &v80);
  if ( v25 )
    goto LABEL_29;
  v26 = &qword_204ED8;
  if ( qword_204ED8 )
  {
    v26 = &qword_204EE0;
    if ( qword_204EE0 )
    {
      v26 = &qword_204EE8;
      if ( qword_204EE8 )
      {
        printk(&unk_3BCC6E, "ipa_wdi_opt_dpath_add_ctrl_filter_req");
        v39 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v40 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v40 )
          {
            ipc_log_string(v40, "ipa %s:%d MAX WDI filters reached\n", "ipa_wdi_opt_dpath_add_ctrl_filter_req", 1735);
            v39 = ipa3_ctx;
          }
          v41 = *(_QWORD *)(v39 + 34160);
          if ( v41 )
            ipc_log_string(v41, "ipa %s:%d MAX WDI filters reached\n", "ipa_wdi_opt_dpath_add_ctrl_filter_req", 1735);
        }
        v78 = 0;
        v79 = 0;
        v76 = 0;
        v77 = 0;
        v74 = 0;
        v75 = 0;
        v72 = 0;
        v73 = 0;
        v70 = 0;
        v71 = 0;
        v68 = 0;
        v69 = 0;
        v66 = 0;
        v67 = 0;
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
        *(_QWORD *)s = 0;
        v49 = 0;
        snprintf(
          s,
          0x100u,
          "ipa-event-log %s:%d MAX WDI filters reached\n",
          "ipa_wdi_opt_dpath_add_ctrl_filter_req",
          1736);
        ipa3_send_opt_log_msg(s);
LABEL_41:
        v25 = -1;
        *(_DWORD *)a2 = 196609;
        *(_DWORD *)(a2 + 4) = *a1;
        goto LABEL_30;
      }
    }
  }
  v27 = v86;
  *(_DWORD *)v26 = *a1;
  *((_DWORD *)v26 + 1) = v27;
LABEL_29:
  v28 = *a1;
  *(_WORD *)(a2 + 2) = v25;
  *(_DWORD *)(a2 + 4) = v28;
  *(_WORD *)a2 = v25 != 0;
  v29 = v86;
  v30 = ipa3_ctx;
  *(_BYTE *)(a2 + 8) = 1;
  *(_DWORD *)(a2 + 12) = v29;
  _X8 = (unsigned int *)(v30 + 33072);
  __asm { PRFM            #0x11, [X8] }
  do
    v47 = __ldxr(_X8);
  while ( __stxr(v47 + 1, _X8) );
  v78 = 0;
  v79 = 0;
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
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
  *(_QWORD *)s = 0;
  v49 = 0;
  snprintf(
    s,
    0x100u,
    "ipa-event-log %s:%d add_ctrl_flt_req_count: %d, rm_ctrl_flt_req_count: %d\n",
    "ipa_wdi_opt_dpath_add_ctrl_filter_req",
    1753,
    *(_DWORD *)(ipa3_ctx + 33072),
    *(_DWORD *)(ipa3_ctx + 33080));
  ipa3_send_opt_log_msg(s);
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return v25;
}
