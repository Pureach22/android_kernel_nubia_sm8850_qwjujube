__int64 __fastcall wma_vdev_create_set_param(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x19
  unsigned int v20; // w20
  __int64 cmpt_obj; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8
  __int64 v31; // x22
  int v32; // w9
  __int64 v33; // x4
  __int64 v34; // x0
  int v35; // w8
  int v36; // w8
  int v37; // w8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  int v46; // w24
  const char *v47; // x2
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w9
  _DWORD *v57; // x8
  __int64 v58; // x8
  _DWORD *v59; // x9
  int v60; // w23
  int v61; // w10
  _DWORD *v62; // x8
  int v63; // w10
  _DWORD *v64; // x8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned int v73; // w9
  _DWORD *v74; // x8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  _DWORD *v83; // x10
  int v84; // w8
  int v85; // w8
  _DWORD *v86; // x24
  int v87; // w8
  int v88; // w8
  int v89; // w8
  int v90; // w8
  int v91; // w8
  _DWORD *v92; // x9
  int v93; // w8
  char sap_ps_with_twt; // w0
  _DWORD *v95; // x8
  char is_24ghz_twt_enabled; // w0
  _DWORD *v97; // x21
  char is_twt_disable_info_frame; // w0
  int v99; // w8
  __int64 result; // x0
  _BYTE v101[4]; // [xsp+8h] [xbp-D8h] BYREF
  unsigned int v102; // [xsp+Ch] [xbp-D4h] BYREF
  __int64 v103; // [xsp+10h] [xbp-D0h] BYREF
  int v104; // [xsp+1Ch] [xbp-C4h] BYREF
  _DWORD v105[8]; // [xsp+20h] [xbp-C0h] BYREF
  __int64 v106; // [xsp+40h] [xbp-A0h]
  __int64 v107; // [xsp+48h] [xbp-98h]
  __int64 v108; // [xsp+50h] [xbp-90h]
  __int64 v109; // [xsp+58h] [xbp-88h]
  __int64 v110; // [xsp+60h] [xbp-80h]
  __int64 v111; // [xsp+68h] [xbp-78h]
  __int64 v112; // [xsp+70h] [xbp-70h]
  __int64 v113; // [xsp+78h] [xbp-68h]
  __int64 v114; // [xsp+80h] [xbp-60h]
  __int64 v115; // [xsp+88h] [xbp-58h]
  __int64 v116; // [xsp+90h] [xbp-50h]
  __int64 v117; // [xsp+98h] [xbp-48h]
  __int64 v118; // [xsp+A0h] [xbp-40h]
  __int64 v119; // [xsp+A8h] [xbp-38h]
  __int64 v120; // [xsp+B0h] [xbp-30h]
  __int64 v121; // [xsp+B8h] [xbp-28h]
  __int64 v122; // [xsp+C0h] [xbp-20h]
  __int64 v123; // [xsp+C8h] [xbp-18h]
  __int64 v124; // [xsp+D0h] [xbp-10h]
  __int64 v125; // [xsp+D8h] [xbp-8h]

  v125 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v104 = 0;
  context = _cds_get_context(53, (__int64)"wma_vdev_create_set_param", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    goto LABEL_30;
  v19 = context;
  v20 = *(unsigned __int8 *)(a1 + 104);
  v102 = 0;
  v106 = 0;
  v107 = 0;
  v108 = 0;
  v109 = 0;
  v110 = 0;
  v111 = 0;
  v112 = 0;
  v113 = 0;
  v114 = 0;
  v115 = 0;
  v116 = 0;
  v117 = 0;
  v118 = 0;
  v119 = 0;
  v120 = 0;
  v121 = 0;
  v122 = 0;
  v123 = 0;
  v124 = 0;
  v101[0] = 0;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !cmpt_obj )
  {
    v47 = "%s: Failed to get vdev mlme obj!";
LABEL_29:
    qdf_trace_msg(0x36u, 2u, v47, v22, v23, v24, v25, v26, v27, v28, v29, "wma_vdev_create_set_param");
LABEL_30:
    result = 16;
    goto LABEL_31;
  }
  v30 = v19[1];
  v31 = cmpt_obj;
  v32 = *(unsigned __int8 *)(v30 + 977);
  v33 = *(unsigned __int16 *)(v30 + 1046);
  v105[0] = 167;
  v105[1] = v32;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Setting wmi_vdev_param_disconnect_th: %d",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "wma_vdev_create_set_param",
    v33);
  v34 = v19[2694];
  v35 = *(unsigned __int16 *)(v19[1] + 1046LL);
  v105[2] = 76;
  v105[3] = v35;
  v36 = *((unsigned __int8 *)v19 + 17147);
  v105[4] = 78;
  v105[5] = v36;
  v37 = *((unsigned __int8 *)v19 + 17148);
  v105[6] = 79;
  v105[7] = v37;
  if ( (unsigned int)wlan_mlme_get_rts_threshold(v34, &v104) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Fail to get val for rts threshold, leave unchanged",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "wma_vdev_create_set_param");
    v46 = 4;
  }
  else
  {
    v46 = 5;
    LODWORD(v106) = 1;
    HIDWORD(v106) = v104;
  }
  if ( (unsigned int)wlan_mlme_get_frag_threshold(v19[2694], &v104) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Fail to get val for frag threshold, leave unchanged",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "wma_vdev_create_set_param");
  }
  else
  {
    v56 = v104;
    v57 = &v105[2 * v46++];
    *v57 = 2;
    v57[1] = v56;
  }
  v58 = v19[1];
  v59 = &v105[2 * v46];
  v103 = 0;
  v60 = v46 + 1;
  LODWORD(v58) = (*(unsigned __int16 *)(v58 + 1268) >> 7) & 1;
  *v59 = 30;
  v59[1] = v58;
  if ( !(unsigned int)wma_vdev_mgmt_tx_rate(&v103) )
  {
    v61 = HIDWORD(v103);
    v62 = &v105[2 * v60];
    v60 = v46 + 2;
    *v62 = v103;
    v62[1] = v61;
  }
  if ( !(unsigned int)wma_vdev_mgmt_perband_tx_rate(&v103) )
  {
    v63 = HIDWORD(v103);
    v64 = &v105[2 * v60++];
    *v64 = v103;
    v64[1] = v63;
  }
  if ( (wma_get_fw_wlan_feat_caps(13) & 1) != 0 && !(unsigned int)wma_get_hemu_mode(&v102, v19) )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: set HEMU_MODE (hemu_mode = 0x%x)",
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      "wma_vdev_create_set_param",
      v102);
    v73 = v102;
    v74 = &v105[2 * v60++];
    *v74 = 32770;
    v74[1] = v73;
  }
  if ( (wlan_nan_is_beamforming_supported(v19[2694]) & 1) != 0 )
  {
    v83 = &v105[2 * v60++];
    v84 = *(unsigned __int8 *)(v19[1] + 2623LL)
        | (2 * *(unsigned __int8 *)(v19[1] + 2668LL))
        | (4 * *(unsigned __int8 *)(v19[1] + 2622LL));
    *v83 = 45;
    v83[1] = v84;
  }
  v85 = *(unsigned __int8 *)(v31 + 163);
  if ( v85 == 2 )
  {
    if ( *(_BYTE *)(v31 + 164) )
      goto LABEL_25;
    v86 = &v105[2 * v60];
    v87 = *(unsigned __int8 *)(v19[1] + 3452LL);
    *v86 = 108;
    v86[1] = v87;
    v88 = *(unsigned __int8 *)(v19[1] + 3328LL);
    v86[2] = 109;
    v86[3] = v88;
    *((_QWORD *)v86 + 2) = 0xA00000072LL;
    *((_QWORD *)v86 + 3) = 0x1400000073LL;
    v89 = *(unsigned __int8 *)(v19[1] + 3456LL);
    v86[8] = 120;
    v86[9] = v89;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: first_bcnt: %d, final_bcnt: %d",
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      "wma_vdev_create_set_param",
      *(unsigned __int8 *)(v19[1] + 1748LL),
      *(unsigned __int8 *)(v19[1] + 1749LL));
    v60 += 7;
    v90 = *(unsigned __int8 *)(v19[1] + 1748LL);
    v86[10] = 18;
    v86[11] = v90;
    v91 = *(unsigned __int8 *)(v19[1] + 1749LL);
    v86[12] = 19;
    v86[13] = v91;
    v85 = *(unsigned __int8 *)(v31 + 163);
  }
  if ( v85 == 1 && !*(_BYTE *)(v31 + 164) )
  {
    v92 = &v105[2 * (unsigned __int8)v60++];
    v93 = *(unsigned __int8 *)(v19[1] + 3456LL);
    *v92 = 120;
    v92[1] = v93;
  }
LABEL_25:
  if ( *(_DWORD *)(a1 + 16) == 1 )
  {
    sap_ps_with_twt = wlan_mlme_get_sap_ps_with_twt(v19[2694]);
    v95 = &v105[2 * (unsigned __int8)v60++];
    *v95 = 32787;
    v95[1] = sap_ps_with_twt & 1;
  }
  is_24ghz_twt_enabled = mlme_is_24ghz_twt_enabled(v19[2694]);
  v97 = &v105[2 * (unsigned __int8)v60];
  *v97 = 191;
  v97[1] = (is_24ghz_twt_enabled & 1) == 0;
  is_twt_disable_info_frame = mlme_is_twt_disable_info_frame(v19[2694]);
  v97[2] = 192;
  v97[3] = is_twt_disable_info_frame & 1;
  wlan_twt_cfg_get_twt_dis_on_scan(v19[2694], v101);
  v99 = v101[0];
  v97[4] = 200;
  v97[5] = v99;
  result = wma_send_multi_pdev_vdev_set_params(1, v20, v105, (unsigned int)(v60 + 3));
  if ( (_DWORD)result )
  {
    v47 = "%s: failed to update vdev set all params";
    goto LABEL_29;
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
