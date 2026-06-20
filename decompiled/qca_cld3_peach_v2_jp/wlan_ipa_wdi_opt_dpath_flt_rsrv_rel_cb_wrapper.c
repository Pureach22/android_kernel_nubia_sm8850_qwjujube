__int64 __fastcall wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb_wrapper(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  int v10; // w2
  int v11; // w3
  int v12; // w4
  int v13; // w5
  int v14; // w6
  int v15; // w7
  __int64 result; // x0
  unsigned int v17; // w19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)_qdf_op_protect() )
  {
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: opt_dp: driver operation inprogress!",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb_wrapper");
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb_wrapper",
      (int)"opt_dp: driver operation inprogress!",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      0);
  }
  else
  {
    if ( *(_BYTE *)(a1 + 7439) == 1 || *(_BYTE *)(a1 + 7515) == 1 )
    {
      *(_BYTE *)(a1 + 7515) = 1;
      v17 = wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb(a1, v2, v3, v4, v5, v6, v7, v8, v9);
      _qdf_op_unprotect();
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: opt_dp: flt release status - %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb_wrapper",
        v17,
        0,
        v34);
      result = v17;
      goto LABEL_7;
    }
    _qdf_op_unprotect();
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: opt_dp: filter release triggered already from wlan ctx - %d release state - %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb_wrapper",
      *(unsigned __int8 *)(a1 + 7515),
      *(unsigned __int8 *)(a1 + 7439),
      0,
      v34);
  }
  result = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
