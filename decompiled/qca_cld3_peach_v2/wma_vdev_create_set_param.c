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
  _QWORD *v19; // x20
  unsigned int v20; // w19
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
  unsigned int v46; // w24
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
  __int64 *v57; // x8
  __int64 v58; // x8
  __int64 *v59; // x9
  unsigned int v60; // w23
  int v61; // w10
  __int64 *v62; // x8
  int v63; // w10
  __int64 *v64; // x8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned int v73; // w9
  __int64 *v74; // x8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  unsigned int v83; // w9
  __int64 *v84; // x8
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 *v93; // x10
  int v94; // w8
  int v95; // w8
  __int64 *v96; // x24
  int v97; // w8
  int v98; // w8
  int v99; // w8
  int v100; // w8
  int v101; // w8
  __int64 *v102; // x9
  int v103; // w8
  char sap_ps_with_twt; // w0
  __int64 *v105; // x8
  char is_24ghz_twt_enabled; // w0
  __int64 *v107; // x21
  char is_twt_disable_info_frame; // w0
  __int64 twt_dis_on_scan; // x0
  __int64 v110; // x1
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  int v119; // w8
  __int64 *v120; // x9
  __int64 result; // x0
  unsigned int v122; // w1
  unsigned int v123; // [xsp+4h] [xbp-DCh] BYREF
  _BYTE v124[4]; // [xsp+8h] [xbp-D8h] BYREF
  unsigned int v125; // [xsp+Ch] [xbp-D4h] BYREF
  __int64 v126; // [xsp+10h] [xbp-D0h] BYREF
  int v127; // [xsp+1Ch] [xbp-C4h] BYREF
  __int64 v128; // [xsp+20h] [xbp-C0h] BYREF
  __int64 v129; // [xsp+28h] [xbp-B8h]
  __int64 v130; // [xsp+30h] [xbp-B0h]
  __int64 v131; // [xsp+38h] [xbp-A8h]
  __int64 v132; // [xsp+40h] [xbp-A0h]
  __int64 v133; // [xsp+48h] [xbp-98h]
  __int64 v134; // [xsp+50h] [xbp-90h]
  __int64 v135; // [xsp+58h] [xbp-88h]
  __int64 v136; // [xsp+60h] [xbp-80h]
  __int64 v137; // [xsp+68h] [xbp-78h]
  __int64 v138; // [xsp+70h] [xbp-70h]
  __int64 v139; // [xsp+78h] [xbp-68h]
  __int64 v140; // [xsp+80h] [xbp-60h]
  __int64 v141; // [xsp+88h] [xbp-58h]
  __int64 v142; // [xsp+90h] [xbp-50h]
  __int64 v143; // [xsp+98h] [xbp-48h]
  __int64 v144; // [xsp+A0h] [xbp-40h]
  __int64 v145; // [xsp+A8h] [xbp-38h]
  __int64 v146; // [xsp+B0h] [xbp-30h]
  __int64 v147; // [xsp+B8h] [xbp-28h]
  __int64 v148; // [xsp+C0h] [xbp-20h]
  __int64 v149; // [xsp+C8h] [xbp-18h]
  __int64 v150; // [xsp+D0h] [xbp-10h]
  __int64 v151; // [xsp+D8h] [xbp-8h]

  v151 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v127 = 0;
  context = _cds_get_context(53, (__int64)"wma_vdev_create_set_param", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    goto LABEL_38;
  v19 = context;
  v20 = *(unsigned __int8 *)(a1 + 168);
  v125 = 0;
  v128 = 0;
  v129 = 0;
  v130 = 0;
  v131 = 0;
  v132 = 0;
  v133 = 0;
  v134 = 0;
  v135 = 0;
  v136 = 0;
  v137 = 0;
  v138 = 0;
  v139 = 0;
  v140 = 0;
  v141 = 0;
  v142 = 0;
  v143 = 0;
  v144 = 0;
  v145 = 0;
  v146 = 0;
  v147 = 0;
  v148 = 0;
  v149 = 0;
  v150 = 0;
  v124[0] = 0;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !cmpt_obj )
  {
    v47 = "%s: Failed to get vdev mlme obj!";
LABEL_35:
    v122 = 2;
LABEL_37:
    qdf_trace_msg(0x36u, v122, v47, v22, v23, v24, v25, v26, v27, v28, v29, "wma_vdev_create_set_param");
LABEL_38:
    result = 16;
    goto LABEL_39;
  }
  v30 = v19[1];
  v31 = cmpt_obj;
  v32 = *(unsigned __int8 *)(v30 + 977);
  v33 = *(unsigned __int16 *)(v30 + 1046);
  LODWORD(v128) = 167;
  HIDWORD(v128) = v32;
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
  v34 = v19[2703];
  v35 = *(unsigned __int16 *)(v19[1] + 1046LL);
  LODWORD(v129) = 76;
  HIDWORD(v129) = v35;
  v36 = *((unsigned __int8 *)v19 + 17219);
  LODWORD(v130) = 78;
  HIDWORD(v130) = v36;
  v37 = *((unsigned __int8 *)v19 + 17220);
  LODWORD(v131) = 79;
  HIDWORD(v131) = v37;
  if ( (unsigned int)wlan_mlme_get_rts_threshold(v34, &v127) )
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
    LODWORD(v132) = 1;
    HIDWORD(v132) = v127;
  }
  if ( (unsigned int)wlan_mlme_get_frag_threshold(v19[2703], &v127) )
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
    v56 = v127;
    v57 = &v128 + v46++;
    *(_DWORD *)v57 = 2;
    *((_DWORD *)v57 + 1) = v56;
  }
  v58 = v19[1];
  v59 = &v128 + v46;
  v126 = 0;
  v60 = v46 + 1;
  LODWORD(v58) = (*(unsigned __int16 *)(v58 + 1288) >> 7) & 1;
  *(_DWORD *)v59 = 30;
  *((_DWORD *)v59 + 1) = v58;
  if ( !(unsigned int)wma_vdev_mgmt_tx_rate(&v126) )
  {
    v61 = HIDWORD(v126);
    v62 = &v128 + v60;
    v60 = v46 + 2;
    *(_DWORD *)v62 = v126;
    *((_DWORD *)v62 + 1) = v61;
  }
  if ( !(unsigned int)wma_vdev_mgmt_perband_tx_rate(&v126) )
  {
    v63 = HIDWORD(v126);
    v64 = &v128 + v60++;
    *(_DWORD *)v64 = v126;
    *((_DWORD *)v64 + 1) = v63;
  }
  if ( (wma_get_fw_wlan_feat_caps(14) & 1) != 0 )
  {
    v123 = 0;
    if ( !(unsigned int)wma_set_eht_txbf_vdev_params(v19, &v123) )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: set EHTMU_MODE (ehtmu_mode = 0x%x)",
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        "wma_vdev_create_set_param",
        v123);
      v73 = v123;
      v74 = &v128 + v60++;
      *(_DWORD *)v74 = 32773;
      *((_DWORD *)v74 + 1) = v73;
    }
  }
  if ( (wma_get_fw_wlan_feat_caps(13) & 1) != 0 && !(unsigned int)wma_get_hemu_mode(&v125, v19) )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: set HEMU_MODE (hemu_mode = 0x%x)",
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      "wma_vdev_create_set_param",
      v125);
    v83 = v125;
    v84 = &v128 + v60++;
    *(_DWORD *)v84 = 32770;
    *((_DWORD *)v84 + 1) = v83;
  }
  if ( (wlan_nan_is_beamforming_supported(v19[2703]) & 1) != 0 )
  {
    v93 = &v128 + v60++;
    v94 = *(unsigned __int8 *)(v19[1] + 2827LL)
        | (2 * *(unsigned __int8 *)(v19[1] + 2872LL))
        | (4 * *(unsigned __int8 *)(v19[1] + 2826LL));
    *(_DWORD *)v93 = 45;
    *((_DWORD *)v93 + 1) = v94;
  }
  v95 = *(unsigned __int8 *)(v31 + 179);
  if ( v95 == 2 )
  {
    if ( *(_BYTE *)(v31 + 180) )
      goto LABEL_28;
    v96 = &v128 + (unsigned __int8)v60;
    v97 = *(unsigned __int8 *)(v19[1] + 3664LL);
    *(_DWORD *)v96 = 108;
    *((_DWORD *)v96 + 1) = v97;
    v98 = *(unsigned __int8 *)(v19[1] + 3528LL);
    *((_DWORD *)v96 + 2) = 109;
    *((_DWORD *)v96 + 3) = v98;
    v96[2] = 0xA00000072LL;
    v96[3] = 0x1400000073LL;
    v99 = *(unsigned __int8 *)(v19[1] + 3668LL);
    *((_DWORD *)v96 + 8) = 120;
    *((_DWORD *)v96 + 9) = v99;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: first_bcnt: %d, final_bcnt: %d",
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      "wma_vdev_create_set_param",
      *(unsigned __int8 *)(v19[1] + 1952LL),
      *(unsigned __int8 *)(v19[1] + 1953LL));
    v60 += 7;
    v100 = *(unsigned __int8 *)(v19[1] + 1952LL);
    *((_DWORD *)v96 + 10) = 18;
    *((_DWORD *)v96 + 11) = v100;
    v101 = *(unsigned __int8 *)(v19[1] + 1953LL);
    *((_DWORD *)v96 + 12) = 19;
    *((_DWORD *)v96 + 13) = v101;
    v95 = *(unsigned __int8 *)(v31 + 179);
  }
  if ( v95 == 1 && !*(_BYTE *)(v31 + 180) )
  {
    v102 = &v128 + (unsigned __int8)v60++;
    v103 = *(unsigned __int8 *)(v19[1] + 3668LL);
    *(_DWORD *)v102 = 120;
    *((_DWORD *)v102 + 1) = v103;
  }
LABEL_28:
  if ( *(_DWORD *)(a1 + 16) == 1 )
  {
    sap_ps_with_twt = wlan_mlme_get_sap_ps_with_twt(v19[2703]);
    v105 = &v128 + (unsigned __int8)v60++;
    *(_DWORD *)v105 = 32787;
    *((_DWORD *)v105 + 1) = sap_ps_with_twt & 1;
  }
  is_24ghz_twt_enabled = mlme_is_24ghz_twt_enabled(v19[2703]);
  v107 = &v128 + (unsigned __int8)v60;
  *(_DWORD *)v107 = 191;
  *((_DWORD *)v107 + 1) = (is_24ghz_twt_enabled & 1) == 0;
  is_twt_disable_info_frame = mlme_is_twt_disable_info_frame(v19[2703]);
  *((_DWORD *)v107 + 2) = 192;
  *((_DWORD *)v107 + 3) = is_twt_disable_info_frame & 1;
  twt_dis_on_scan = wlan_twt_cfg_get_twt_dis_on_scan(v19[2703], v124);
  if ( (unsigned __int8)v60 >= 0x15u )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Index:%d OOB to fill param",
      v111,
      v112,
      v113,
      v114,
      v115,
      v116,
      v117,
      v118,
      "mlme_check_index_setparam",
      (unsigned __int8)(v60 + 2));
    v47 = "%s: failed to set wmi_vdev_param_disable_scan_start_twt";
    v122 = 8;
    goto LABEL_37;
  }
  if ( (unsigned __int8)(v60 + 2) != 23 )
  {
    v119 = v124[0];
    v120 = &v128 + (unsigned __int8)(v60 + 2);
    *(_DWORD *)v120 = 200;
    if ( ((8LL * (unsigned __int8)(v60 + 2)) | 4uLL) <= 0xB8 )
    {
      *((_DWORD *)v120 + 1) = v119;
      result = wma_send_multi_pdev_vdev_set_params(1, v20, &v128, v60 + 3);
      if ( !(_DWORD)result )
      {
LABEL_39:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      v47 = "%s: failed to update vdev set all params";
      goto LABEL_35;
    }
  }
  __break(1u);
  return wma_set_vdev_latency_level_param(twt_dis_on_scan, v110);
}
