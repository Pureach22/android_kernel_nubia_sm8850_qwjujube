__int64 __fastcall policy_mgr_nan_sap_post_enable_conc_check(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _QWORD *v11; // x19
  __int64 *v12; // x23
  char v13; // w21
  __int64 result; // x0
  char mode_specific_conn_info; // w22
  unsigned int channel; // w21
  __int64 _5ghz_social_ch_freq; // x0
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x3
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 (__fastcall *v33)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // x8
  unsigned int v34; // w24
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  void (__fastcall *v43)(__int64, __int64, __int64); // x8
  __int64 v44; // x1
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  _BOOL8 is_24ghz_ch_freq; // x0
  __int64 v62; // x1
  __int64 v63; // x2
  __int64 v64; // x3
  __int64 v65; // x4
  unsigned int v66; // w22
  __int64 ch_width; // x3
  __int64 v68; // x0
  __int64 v69; // x1
  __int64 v70; // x2
  unsigned int v71; // w20
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned int v80; // w22
  __int64 v81; // [xsp+0h] [xbp-60h] BYREF
  __int64 v82; // [xsp+8h] [xbp-58h] BYREF
  __int64 v83; // [xsp+10h] [xbp-50h] BYREF
  __int64 v84; // [xsp+18h] [xbp-48h] BYREF
  __int64 v85; // [xsp+20h] [xbp-40h] BYREF
  __int64 v86; // [xsp+28h] [xbp-38h] BYREF
  __int64 v87; // [xsp+30h] [xbp-30h]
  __int64 v88; // [xsp+38h] [xbp-28h]
  __int64 v89; // [xsp+40h] [xbp-20h] BYREF
  __int64 v90; // [xsp+48h] [xbp-18h]
  unsigned int v91; // [xsp+50h] [xbp-10h]
  __int64 v92; // [xsp+58h] [xbp-8h]

  v92 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v91 = 0;
  v89 = 0;
  v90 = 0;
  BYTE4(v85) = 0;
  LODWORD(v85) = 0;
  BYTE4(v81) = 0;
  LOBYTE(v81) = 0;
  BYTE4(v84) = 0;
  LODWORD(v84) = 0;
  BYTE4(v83) = 0;
  LODWORD(v83) = 0;
  LODWORD(v88) = 0;
  v86 = 0;
  v87 = 0;
  BYTE4(v82) = 0;
  LODWORD(v82) = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid pm context",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "policy_mgr_nan_sap_post_enable_conc_check",
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88);
    result = 4;
LABEL_57:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v11 = (_QWORD *)context;
  qdf_mutex_acquire(context + 56);
  if ( (policy_mgr_is_sap_mode((unsigned int)pm_conc_connection_list) & 1) != 0
    && (v12 = &pm_conc_connection_list, (qword_81C458 & 0x100000000LL) != 0)
    || (policy_mgr_is_sap_mode((unsigned int)qword_81C464) & 1) != 0
    && (v12 = &qword_81C464, (qword_81C47C & 0x100000000LL) != 0)
    || (policy_mgr_is_sap_mode((unsigned int)qword_81C488) & 1) != 0
    && (v12 = &qword_81C488, (qword_81C4A0 & 0x100000000LL) != 0)
    || (policy_mgr_is_sap_mode((unsigned int)qword_81C4AC) & 1) != 0
    && (v12 = &qword_81C4AC, (qword_81C4C4 & 0x100000000LL) != 0)
    || (policy_mgr_is_sap_mode((unsigned int)qword_81C4D0) & 1) != 0
    && (v12 = &qword_81C4D0, (qword_81C4E8 & 0x100000000LL) != 0) )
  {
    v13 = 0;
  }
  else
  {
    v12 = nullptr;
    v13 = 1;
  }
  qdf_mutex_release((__int64)(v11 + 7));
  mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(a1, &v89, &v85, 0);
  ((void (__fastcall *)(__int64, char *, __int64 *, __int64 *, __int64 *, __int64 *, __int64 *, _QWORD))policy_mgr_get_ml_and_non_ml_mode_count)(
    a1,
    (char *)&v81 + 4,
    &v84,
    &v81,
    &v83,
    &v86,
    &v82,
    0);
  result = 0;
  if ( (v13 & 1) != 0 )
    goto LABEL_56;
  if ( !*((_DWORD *)v12 + 1) )
    goto LABEL_55;
  channel = policy_mgr_mode_specific_get_channel(a1, 5);
  _5ghz_social_ch_freq = wlan_nan_get_5ghz_social_ch_freq(v11[1]);
  if ( *((_DWORD *)v12 + 1) == channel && !mode_specific_conn_info )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: NAN and SAP already in SCC",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "policy_mgr_nan_sap_post_enable_conc_check",
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88);
    goto LABEL_55;
  }
  if ( !channel )
    goto LABEL_55;
  v33 = (__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))v11[40];
  v34 = _5ghz_social_ch_freq;
  if ( v33 )
  {
    if ( *((_DWORD *)v33 - 1) != 799902358 )
      __break(0x8228u);
    if ( (v33(_5ghz_social_ch_freq, v18, v19, v20, v21, v22, v23, v24) & 1) != 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: channel switch is already in progress",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "policy_mgr_nan_sap_post_enable_conc_check",
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        v88);
      result = 0;
      goto LABEL_57;
    }
  }
  v43 = (void (__fastcall *)(__int64, __int64, __int64))v11[42];
  if ( v43 )
  {
    v44 = *((unsigned int *)v12 + 6);
    if ( *((_DWORD *)v43 - 1) != -1125204353 )
      __break(0x8228u);
    v43(a1, v44, 8);
  }
  if ( ((ucfg_is_nan_dbs_supported(*v11) & 1) == 0 || wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v12 + 1)))
    && (wlan_nan_is_sta_sap_nan_allowed(a1) & 1) == 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Force SCC for NAN+SAP Ch freq: %d",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "policy_mgr_nan_sap_post_enable_conc_check",
      channel,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88);
    v66 = *((_DWORD *)v12 + 6);
    ch_width = (unsigned int)policy_mgr_get_ch_width(*((unsigned int *)v12 + 2));
    v68 = a1;
    v69 = v66;
    v70 = channel;
    goto LABEL_63;
  }
  if ( v34 && wlan_reg_is_5ghz_ch_freq(*((_DWORD *)v12 + 1)) && (wlan_nan_is_sta_sap_nan_allowed(a1) & 1) == 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Force SCC for NAN+SAP Ch freq: %d",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "policy_mgr_nan_sap_post_enable_conc_check",
      v34,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88);
    v80 = *((_DWORD *)v12 + 6);
    ch_width = (unsigned int)policy_mgr_get_ch_width(*((unsigned int *)v12 + 2));
    v68 = a1;
    v69 = v80;
    v70 = v34;
LABEL_63:
    LODWORD(result) = policy_mgr_change_sap_channel_with_csa(v68, v69, v70, ch_width, 1);
    if ( (_DWORD)result )
      result = (unsigned int)result;
    else
      result = 24;
    goto LABEL_56;
  }
  if ( (wlan_nan_is_sta_sap_nan_allowed(a1) & 1) == 0 )
    goto LABEL_55;
  if ( !mode_specific_conn_info || BYTE4(v81) > 1u )
    goto LABEL_54;
  if ( wlan_reg_is_24ghz_ch_freq(v89) )
    channel = v89;
  if ( mode_specific_conn_info == 1 )
    goto LABEL_54;
  if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(v89)) )
    channel = HIDWORD(v89);
  if ( mode_specific_conn_info == 2 )
    goto LABEL_54;
  if ( wlan_reg_is_24ghz_ch_freq(v90) )
    channel = v90;
  if ( mode_specific_conn_info == 3 )
    goto LABEL_54;
  if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(v90)) )
    channel = HIDWORD(v90);
  if ( mode_specific_conn_info == 4 )
    goto LABEL_54;
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v91);
  if ( is_24ghz_ch_freq )
    channel = v91;
  if ( mode_specific_conn_info == 5 )
  {
LABEL_54:
    if ( *((_DWORD *)v12 + 1) != channel )
    {
      v71 = policy_mgr_change_sap_channel_with_csa(a1, *((unsigned int *)v12 + 6), channel, 1, 1);
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Force SCC for SAP Ch freq: %d",
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        "policy_mgr_nan_sap_post_enable_conc_check",
        channel,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        v88);
      if ( v71 )
        result = v71;
      else
        result = 24;
      goto LABEL_56;
    }
LABEL_55:
    result = 0;
LABEL_56:
    *(_BYTE *)(v11[262] + 52LL) = 0;
    goto LABEL_57;
  }
  __break(0x5512u);
  return policy_mgr_change_sap_channel_with_csa(is_24ghz_ch_freq, v62, v63, v64, v65);
}
