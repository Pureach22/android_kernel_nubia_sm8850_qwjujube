__int64 __fastcall wlansap_channel_change_request(
        unsigned int *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  _QWORD *v13; // x20
  unsigned int v14; // w22
  unsigned int v15; // w21
  unsigned int v16; // w8
  __int64 sap_ch_sw_info; // x0
  unsigned int v18; // w8
  __int64 v19; // x22
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x9
  __int64 v29; // x11
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 v32; // x9
  __int64 v33; // x10
  int v34; // w8
  bool v35; // zf
  unsigned int v36; // w8
  const char *v37; // x2
  __int64 result; // x0
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x23
  _QWORD *v49; // x0
  char v50; // w8
  unsigned int v51; // w9
  char v52; // w10
  _QWORD *v53; // x25
  unsigned int v54; // w8
  size_t v55; // x2
  size_t v56; // x2
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int16 v65; // w8
  int v66; // w9
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  char v75; // w8
  size_t v76; // x2
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  char v85; // w8
  __int64 v86; // x8
  const char *v87; // x2
  __int64 v88; // x8
  unsigned int v89; // w1
  unsigned int v90; // w24
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  __int64 v107; // [xsp+0h] [xbp-50h]
  __int64 v108; // [xsp+8h] [xbp-48h]
  __int64 v109; // [xsp+8h] [xbp-48h]
  __int64 v110; // [xsp+10h] [xbp-40h] BYREF
  __int64 v111; // [xsp+18h] [xbp-38h]
  __int64 v112; // [xsp+20h] [xbp-30h]
  size_t n; // [xsp+28h] [xbp-28h] BYREF
  size_t v114[2]; // [xsp+30h] [xbp-20h] BYREF
  int v115; // [xsp+40h] [xbp-10h]
  __int64 v116; // [xsp+48h] [xbp-8h]

  v116 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    v37 = "%s: channel 0 requested";
LABEL_24:
    qdf_trace_msg(0x39u, 2u, v37, a3, a4, a5, a6, a7, a8, a9, a10, "wlansap_channel_change_request");
    result = 5;
    goto LABEL_25;
  }
  if ( !a1 )
  {
    v37 = "%s: Invalid SAP pointer";
    goto LABEL_24;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v37 = "%s: Invalid MAC context";
    goto LABEL_24;
  }
  v13 = context;
  v14 = a1[371];
  if ( !wlan_reg_is_5ghz_ch_freq(a2) || (v15 = 2, v14 != 8) && v14 != 32 )
  {
    if ( wlan_reg_is_24ghz_ch_freq(a2) && v14 == 2 )
      v15 = 8;
    else
      v15 = v14;
  }
  v16 = *a1;
  a1[371] = v15;
  if ( !v16 )
  {
    v37 = "%s: Invalid channel list";
    goto LABEL_24;
  }
  sap_ch_sw_info = wlan_get_sap_ch_sw_info(*((_QWORD *)a1 + 2), a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !sap_ch_sw_info )
  {
    v37 = "%s: Invalid channel info";
    goto LABEL_24;
  }
  v18 = a1[371];
  v19 = sap_ch_sw_info;
  if ( v18 == 0x4000 || v18 == 0x2000 )
    wlan_reg_set_create_punc_bitmap(sap_ch_sw_info + 20, 1);
  wlan_reg_set_channel_params_for_pwrmode(v13[2704], a2, 0, v19 + 20, 0, a3, a4, a5, a6, a7, a8, a9, a10);
  v28 = *(_QWORD *)(a1 + 375);
  v29 = *(_QWORD *)(a1 + 377);
  a1[434] = *a1;
  v30 = *(_QWORD *)(a1 + 379);
  *(_QWORD *)(a1 + 435) = v28;
  *(_QWORD *)(a1 + 437) = v29;
  *(_QWORD *)(a1 + 439) = v30;
  v31 = *(_QWORD *)(v19 + 36);
  v32 = *(_QWORD *)(v19 + 28);
  v33 = *(_QWORD *)(v19 + 20);
  *a1 = a2;
  *(_QWORD *)(a1 + 377) = v32;
  *(_QWORD *)(a1 + 379) = v31;
  *(_QWORD *)(a1 + 375) = v33;
  v34 = *(unsigned __int8 *)(v19 + 24);
  if ( v34 == 3 )
  {
    v36 = a2 - 20;
  }
  else
  {
    v35 = v34 == 1;
    v36 = 0;
    if ( v35 )
      v36 = a2 + 20;
  }
  a1[1] = v36;
  sap_dfs_set_current_channel(a1, v20, v21, v22, v23, v24, v25, v26, v27);
  v39 = _qdf_mem_malloc(0x40u, "wlansap_channel_change_request", 2455);
  if ( !v39 )
  {
    result = 16;
    goto LABEL_25;
  }
  v48 = v39;
  v49 = _cds_get_context(53, (__int64)"sap_get_mac_context", v40, v41, v42, v43, v44, v45, v46, v47);
  v50 = *((_BYTE *)a1 + 12);
  v110 = 0;
  v111 = 0;
  v51 = *a1;
  v52 = *((_BYTE *)a1 + 81);
  v53 = v49;
  LOBYTE(v110) = v50;
  v54 = a1[371];
  v55 = *((unsigned __int8 *)a1 + 416);
  v115 = 0;
  v114[0] = 0;
  v114[1] = 0;
  HIDWORD(v110) = v54;
  LODWORD(v111) = v51;
  BYTE1(v110) = v52;
  v112 = 0;
  n = 0;
  qdf_mem_copy((char *)&n + 1, (char *)a1 + 417, v55);
  v56 = *((unsigned __int8 *)a1 + 429);
  LOBYTE(n) = *((_BYTE *)a1 + 416);
  qdf_mem_copy((char *)v114 + 6, (char *)a1 + 430, v56);
  BYTE5(v114[0]) = *((_BYTE *)a1 + 429);
  sme_get_network_params(v53, &v110);
  *(_BYTE *)v48 = *((_BYTE *)a1 + 12);
  *(_DWORD *)(v48 + 4) = *a1;
  *(_BYTE *)(v48 + 8) = *((_BYTE *)a1 + 1504);
  *(_DWORD *)(v48 + 12) = a1[375];
  *(_BYTE *)(v48 + 16) = *((_BYTE *)a1 + 1505);
  *(_BYTE *)(v48 + 17) = *((_BYTE *)a1 + 1506);
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: target freq %d bw %d ccfs1 %d reg_punc 0x%x input_punc 0x%x",
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    "wlansap_fill_channel_change_puncture",
    *((unsigned __int16 *)a1 + 761),
    v108,
    v110,
    v111);
  v65 = *((_WORD *)a1 + 759);
  if ( !v65 )
    v65 = *((_WORD *)a1 + 761);
  *(_WORD *)(v48 + 18) = v65;
  v66 = v112;
  *(_DWORD *)(v48 + 20) = BYTE4(v111);
  *(_DWORD *)(v48 + 24) = v66;
  ((void (__fastcall *)(unsigned int *, __int64, __int64, _QWORD, unsigned int *))sap_get_cac_dur_dfs_region)(
    a1,
    v48 + 28,
    v48 + 32,
    *a1,
    a1 + 375);
  mlme_set_cac_required(*((_QWORD *)a1 + 2), *(_DWORD *)(v48 + 28) != 0, v67, v68, v69, v70, v71, v72, v73, v74);
  if ( (_BYTE)n )
  {
    qdf_mem_copy((void *)(v48 + 37), (char *)&n + 1, (unsigned __int8)n);
    qdf_mem_copy((char *)a1 + 417, (char *)&n + 1, (unsigned __int8)n);
    v75 = n;
    *(_BYTE *)(v48 + 36) = n;
    *((_BYTE *)a1 + 416) = v75;
    v76 = BYTE5(v114[0]);
    if ( BYTE5(v114[0]) )
    {
LABEL_32:
      qdf_mem_copy((void *)(v48 + 50), (char *)v114 + 6, v76);
      qdf_mem_copy((char *)a1 + 430, (char *)v114 + 6, BYTE5(v114[0]));
      v85 = BYTE5(v114[0]);
      *(_BYTE *)(v48 + 49) = BYTE5(v114[0]);
      *((_BYTE *)a1 + 429) = v85;
      goto LABEL_36;
    }
  }
  else
  {
    qdf_mem_set(a1 + 104, 0xDu, 0);
    v76 = BYTE5(v114[0]);
    if ( BYTE5(v114[0]) )
      goto LABEL_32;
  }
  qdf_mem_set((char *)a1 + 429, 0xDu, v76);
LABEL_36:
  if ( *((_BYTE *)a1 + 1776) == 1 )
  {
    v86 = *(unsigned __int8 *)(v48 + 49);
    if ( (unsigned int)v86 > 0xB )
    {
      v88 = *(unsigned __int8 *)(v48 + 36);
      if ( (unsigned int)v88 > 0xB )
      {
        v87 = "%s: rates full, can not add H2E bss membership";
        v89 = 2;
        goto LABEL_43;
      }
      *(_BYTE *)(v48 + v88 + 37) = -5;
      v87 = "%s: H2E bss membership add to support rate";
      *(_BYTE *)(v48 + 36) = v88 + 1;
    }
    else
    {
      v87 = "%s: H2E bss membership add to ext support rate";
      *(_BYTE *)(v48 + v86 + 50) = -5;
      *(_BYTE *)(v48 + 49) = v86 + 1;
    }
    v89 = 8;
LABEL_43:
    qdf_trace_msg(0x39u, v89, v87, v77, v78, v79, v80, v81, v82, v83, v84, "wlansap_fill_channel_change_request");
  }
  v90 = sme_send_channel_change_req(v13, v48);
  _qdf_mem_free(v48);
  LODWORD(v109) = *(unsigned __int8 *)(v19 + 26);
  LODWORD(v107) = *(unsigned __int8 *)(v19 + 25);
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: chan_freq:%d phy_mode %d width:%d offset:%d seg0:%d seg1:%d",
    v91,
    v92,
    v93,
    v94,
    v95,
    v96,
    v97,
    v98,
    "wlansap_channel_change_request",
    *a1,
    v15,
    *(unsigned int *)(v19 + 20),
    *(unsigned __int8 *)(v19 + 24),
    v107,
    v109);
  if ( (policy_mgr_update_indoor_concurrency(v13[2703], *(unsigned __int8 *)(*((_QWORD *)a1 + 2) + 168LL), a1[434], 2)
      & 1) != 0 )
    wlan_reg_recompute_current_chan_list(v13[2703], v13[2704], v99, v100, v101, v102, v103, v104, v105, v106);
  result = v90;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
