__int64 __fastcall wlansap_dfs_send_csa_ie_request(
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
  _QWORD *v11; // x21
  __int64 sap_ch_sw_info; // x0
  unsigned int *v13; // x23
  unsigned int *v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0
  const char *v40; // x2
  __int64 v41; // [xsp+8h] [xbp-18h]
  __int64 v42; // [xsp+10h] [xbp-10h] BYREF
  __int64 v43; // [xsp+18h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  if ( !a1 )
  {
    v40 = "%s: Invalid SAP pointer";
LABEL_8:
    qdf_trace_msg(0x39u, 2u, v40, a2, a3, a4, a5, a6, a7, a8, a9, "wlansap_dfs_send_csa_ie_request");
    result = 5;
    goto LABEL_9;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v40 = "%s: Invalid MAC context";
    goto LABEL_8;
  }
  v11 = context;
  sap_ch_sw_info = wlan_get_sap_ch_sw_info(*(_QWORD *)(a1 + 16), a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !sap_ch_sw_info )
  {
    v40 = "%s: Invalid channel info";
    goto LABEL_8;
  }
  v13 = (unsigned int *)sap_ch_sw_info;
  *(_DWORD *)(sap_ch_sw_info + 20) = *(_DWORD *)(sap_ch_sw_info + 16);
  v14 = (unsigned int *)(sap_ch_sw_info + 20);
  wlan_reg_get_input_punc_bitmap();
  wlan_reg_set_input_punc_bitmap();
  wlan_reg_set_channel_params_for_pwrmode(v11[2695], *v13, 0, (__int64)v14, 0, v15, v16, v17, v18, v19, v20, v21, v22);
  ((void (__fastcall *)(__int64, char *, __int64 *, _QWORD, unsigned int *))sap_get_cac_dur_dfs_region)(
    a1,
    (char *)&v42 + 4,
    &v42,
    *v13,
    v14);
  mlme_set_cac_required(*(_QWORD *)(a1 + 16), HIDWORD(v42) != 0, v23, v24, v25, v26, v27, v28, v29, v30);
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: chan freq:%d req:%d width:%d off:%d cac %d",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "wlansap_dfs_send_csa_ie_request",
    *v13,
    *((unsigned __int8 *)v13 + 8),
    *v14,
    *((unsigned __int8 *)v13 + 24),
    HIDWORD(v42),
    v41,
    v42,
    v43);
  wlan_reg_set_input_punc_bitmap();
  result = sme_roam_csa_ie_request(
             v11,
             *(unsigned int *)(a1 + 816) | ((unsigned __int64)*(unsigned __int16 *)(a1 + 820) << 32),
             *v13,
             *((unsigned __int8 *)v13 + 8),
             v14,
             HIDWORD(v42),
             *((unsigned __int8 *)v13 + 38),
             *((unsigned __int8 *)v13 + 39));
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
