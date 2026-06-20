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
  __int64 v18; // x22
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x9
  int v30; // w8
  bool v31; // zf
  unsigned int v32; // w8
  const char *v33; // x2
  __int64 result; // x0
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x23
  _QWORD *v45; // x0
  char v46; // w8
  unsigned int v47; // w9
  char v48; // w10
  _QWORD *v49; // x25
  unsigned int v50; // w8
  size_t v51; // x2
  size_t v52; // x2
  int v53; // w9
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  char v62; // w8
  size_t v63; // x2
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  char v72; // w8
  __int64 v73; // x8
  const char *v74; // x2
  __int64 v75; // x8
  unsigned int v76; // w1
  unsigned int v77; // w24
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // [xsp+10h] [xbp-40h] BYREF
  __int64 v95; // [xsp+18h] [xbp-38h]
  __int64 v96; // [xsp+20h] [xbp-30h]
  size_t n; // [xsp+28h] [xbp-28h] BYREF
  size_t v98[2]; // [xsp+30h] [xbp-20h] BYREF
  int v99; // [xsp+40h] [xbp-10h]
  __int64 v100; // [xsp+48h] [xbp-8h]

  v100 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    v33 = "%s: channel 0 requested";
LABEL_21:
    qdf_trace_msg(0x39u, 2u, v33, a3, a4, a5, a6, a7, a8, a9, a10, "wlansap_channel_change_request");
    result = 5;
    goto LABEL_22;
  }
  if ( !a1 )
  {
    v33 = "%s: Invalid SAP pointer";
    goto LABEL_21;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v33 = "%s: Invalid MAC context";
    goto LABEL_21;
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
    v33 = "%s: Invalid channel list";
    goto LABEL_21;
  }
  sap_ch_sw_info = wlan_get_sap_ch_sw_info(*((_QWORD *)a1 + 2), a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !sap_ch_sw_info )
  {
    v33 = "%s: Invalid channel info";
    goto LABEL_21;
  }
  v18 = sap_ch_sw_info;
  wlan_reg_set_channel_params_for_pwrmode(v13[2695], a2, 0, sap_ch_sw_info + 20, 0, a3, a4, a5, a6, a7, a8, a9, a10);
  a1[430] = *a1;
  v27 = *(_QWORD *)(a1 + 377);
  *(_QWORD *)(a1 + 431) = *(_QWORD *)(a1 + 375);
  *(_QWORD *)(a1 + 433) = v27;
  v28 = *(_QWORD *)(v18 + 20);
  v29 = *(_QWORD *)(v18 + 28);
  *a1 = a2;
  *(_QWORD *)(a1 + 375) = v28;
  *(_QWORD *)(a1 + 377) = v29;
  v30 = *(unsigned __int8 *)(v18 + 24);
  if ( v30 == 3 )
  {
    v32 = a2 - 20;
  }
  else
  {
    v31 = v30 == 1;
    v32 = 0;
    if ( v31 )
      v32 = a2 + 20;
  }
  a1[1] = v32;
  sap_dfs_set_current_channel(a1, v19, v20, v21, v22, v23, v24, v25, v26);
  v35 = _qdf_mem_malloc(0x40u, "wlansap_channel_change_request", 2455);
  if ( !v35 )
  {
    result = 16;
    goto LABEL_22;
  }
  v44 = v35;
  v45 = _cds_get_context(53, (__int64)"sap_get_mac_context", v36, v37, v38, v39, v40, v41, v42, v43);
  v46 = *((_BYTE *)a1 + 12);
  v94 = 0;
  v95 = 0;
  v47 = *a1;
  v48 = *((_BYTE *)a1 + 81);
  v49 = v45;
  LOBYTE(v94) = v46;
  v50 = a1[371];
  v51 = *((unsigned __int8 *)a1 + 416);
  v99 = 0;
  v98[0] = 0;
  v98[1] = 0;
  HIDWORD(v94) = v50;
  LODWORD(v95) = v47;
  BYTE1(v94) = v48;
  v96 = 0;
  n = 0;
  qdf_mem_copy((char *)&n + 1, (char *)a1 + 417, v51);
  v52 = *((unsigned __int8 *)a1 + 429);
  LOBYTE(n) = *((_BYTE *)a1 + 416);
  qdf_mem_copy((char *)v98 + 6, (char *)a1 + 430, v52);
  BYTE5(v98[0]) = *((_BYTE *)a1 + 429);
  sme_get_network_params(v49, &v94);
  *(_BYTE *)v44 = *((_BYTE *)a1 + 12);
  *(_DWORD *)(v44 + 4) = *a1;
  *(_BYTE *)(v44 + 8) = *((_BYTE *)a1 + 1504);
  *(_DWORD *)(v44 + 12) = a1[375];
  *(_BYTE *)(v44 + 16) = *((_BYTE *)a1 + 1505);
  *(_BYTE *)(v44 + 17) = *((_BYTE *)a1 + 1506);
  v53 = v96;
  *(_DWORD *)(v44 + 20) = BYTE4(v95);
  *(_DWORD *)(v44 + 24) = v53;
  ((void (__fastcall *)(unsigned int *, __int64, __int64, _QWORD, unsigned int *))sap_get_cac_dur_dfs_region)(
    a1,
    v44 + 28,
    v44 + 32,
    *a1,
    a1 + 375);
  mlme_set_cac_required(*((_QWORD *)a1 + 2), *(_DWORD *)(v44 + 28) != 0, v54, v55, v56, v57, v58, v59, v60, v61);
  if ( (_BYTE)n )
  {
    qdf_mem_copy((void *)(v44 + 37), (char *)&n + 1, (unsigned __int8)n);
    qdf_mem_copy((char *)a1 + 417, (char *)&n + 1, (unsigned __int8)n);
    v62 = n;
    *(_BYTE *)(v44 + 36) = n;
    *((_BYTE *)a1 + 416) = v62;
    v63 = BYTE5(v98[0]);
    if ( BYTE5(v98[0]) )
    {
LABEL_27:
      qdf_mem_copy((void *)(v44 + 50), (char *)v98 + 6, v63);
      qdf_mem_copy((char *)a1 + 430, (char *)v98 + 6, BYTE5(v98[0]));
      v72 = BYTE5(v98[0]);
      *(_BYTE *)(v44 + 49) = BYTE5(v98[0]);
      *((_BYTE *)a1 + 429) = v72;
      goto LABEL_31;
    }
  }
  else
  {
    qdf_mem_set(a1 + 104, 0xDu, 0);
    v63 = BYTE5(v98[0]);
    if ( BYTE5(v98[0]) )
      goto LABEL_27;
  }
  qdf_mem_set((char *)a1 + 429, 0xDu, v63);
LABEL_31:
  if ( *((_BYTE *)a1 + 1752) == 1 )
  {
    v73 = *(unsigned __int8 *)(v44 + 49);
    if ( (unsigned int)v73 > 0xB )
    {
      v75 = *(unsigned __int8 *)(v44 + 36);
      if ( (unsigned int)v75 > 0xB )
      {
        v74 = "%s: rates full, can not add H2E bss membership";
        v76 = 2;
        goto LABEL_38;
      }
      *(_BYTE *)(v44 + v75 + 37) = -5;
      v74 = "%s: H2E bss membership add to support rate";
      *(_BYTE *)(v44 + 36) = v75 + 1;
    }
    else
    {
      v74 = "%s: H2E bss membership add to ext support rate";
      *(_BYTE *)(v44 + v73 + 50) = -5;
      *(_BYTE *)(v44 + 49) = v73 + 1;
    }
    v76 = 8;
LABEL_38:
    qdf_trace_msg(0x39u, v76, v74, v64, v65, v66, v67, v68, v69, v70, v71, "wlansap_fill_channel_change_request");
  }
  v77 = sme_send_channel_change_req(v13, v44);
  _qdf_mem_free(v44);
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: chan_freq:%d phy_mode %d width:%d offset:%d seg0:%d seg1:%d",
    v78,
    v79,
    v80,
    v81,
    v82,
    v83,
    v84,
    v85,
    "wlansap_channel_change_request",
    *a1,
    v15,
    *(unsigned int *)(v18 + 20),
    *(unsigned __int8 *)(v18 + 24),
    *(unsigned __int8 *)(v18 + 25),
    *(unsigned __int8 *)(v18 + 26),
    v94,
    v95);
  if ( (policy_mgr_update_indoor_concurrency(v13[2694], *(unsigned __int8 *)(*((_QWORD *)a1 + 2) + 104LL), a1[430], 2)
      & 1) != 0 )
    wlan_reg_recompute_current_chan_list(v13[2694], v13[2695], v86, v87, v88, v89, v90, v91, v92, v93);
  result = v77;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
