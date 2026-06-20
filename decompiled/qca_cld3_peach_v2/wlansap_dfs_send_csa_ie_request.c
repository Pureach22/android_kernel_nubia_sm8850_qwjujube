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
  _QWORD *v11; // x20
  __int64 sap_ch_sw_info; // x0
  unsigned int *v13; // x21
  __int64 v14; // x22
  __int16 input_punc_bitmap; // w23
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 result; // x0
  const char *v42; // x2
  __int64 v43; // [xsp+8h] [xbp-18h]
  __int64 v44; // [xsp+10h] [xbp-10h] BYREF
  __int64 v45; // [xsp+18h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  if ( !a1 )
  {
    v42 = "%s: Invalid SAP pointer";
LABEL_11:
    qdf_trace_msg(0x39u, 2u, v42, a2, a3, a4, a5, a6, a7, a8, a9, "wlansap_dfs_send_csa_ie_request");
    result = 5;
    goto LABEL_12;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v42 = "%s: Invalid MAC context";
    goto LABEL_11;
  }
  v11 = context;
  sap_ch_sw_info = wlan_get_sap_ch_sw_info(*(_QWORD *)(a1 + 16), a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !sap_ch_sw_info )
  {
    v42 = "%s: Invalid channel info";
    goto LABEL_11;
  }
  v13 = (unsigned int *)sap_ch_sw_info;
  *(_DWORD *)(sap_ch_sw_info + 20) = *(_DWORD *)(sap_ch_sw_info + 16);
  v14 = sap_ch_sw_info + 20;
  input_punc_bitmap = wlan_reg_get_input_punc_bitmap(sap_ch_sw_info + 20);
  wlan_reg_set_input_punc_bitmap(v14, 0);
  v24 = *(_DWORD *)(a1 + 1484);
  if ( v24 == 0x4000 || v24 == 0x2000 )
    wlan_reg_set_create_punc_bitmap(v14, 1);
  wlan_reg_set_channel_params_for_pwrmode(v11[2704], *v13, 0, v14, 0, v16, v17, v18, v19, v20, v21, v22, v23);
  ((void (__fastcall *)(__int64, char *, __int64 *, _QWORD, __int64))sap_get_cac_dur_dfs_region)(
    a1,
    (char *)&v44 + 4,
    &v44,
    *v13,
    v14);
  mlme_set_cac_required(*(_QWORD *)(a1 + 16), HIDWORD(v44) != 0, v25, v26, v27, v28, v29, v30, v31, v32);
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: chan freq:%d req:%d width:%d off:%d cac %d",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "wlansap_dfs_send_csa_ie_request",
    *v13,
    *((unsigned __int8 *)v13 + 8),
    v13[5],
    *((unsigned __int8 *)v13 + 24),
    HIDWORD(v44),
    v43,
    v44,
    v45);
  wlan_reg_set_input_punc_bitmap(v14, input_punc_bitmap);
  result = sme_roam_csa_ie_request(
             v11,
             *(unsigned int *)(a1 + 816) | ((unsigned __int64)*(unsigned __int16 *)(a1 + 820) << 32),
             *v13,
             *((unsigned __int8 *)v13 + 8),
             v14,
             HIDWORD(v44),
             *((unsigned __int8 *)v13 + 46),
             *((unsigned __int8 *)v13 + 47));
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
