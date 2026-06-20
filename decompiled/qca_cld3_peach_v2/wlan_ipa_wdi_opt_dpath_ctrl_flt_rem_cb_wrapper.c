__int64 __fastcall wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb_wrapper(__int64 a1, unsigned __int8 *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  int v12; // w2
  int v13; // w3
  int v14; // w4
  int v15; // w5
  int v16; // w6
  int v17; // w7
  __int64 result; // x0
  unsigned int v19; // w19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)_qdf_op_protect() )
  {
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: opt_dp_ctrl: driver operation inprogress!",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb_wrapper");
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb_wrapper",
      (int)"opt_dp_ctrl: driver operation inprogress!",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      0);
    result = 0;
  }
  else
  {
    v19 = wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb(a1, a2, 0, v4, v5, v6, v7, v8, v9, v10, v11);
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: opt_dp_ctrl: flt del requested from ipa, return code - %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb_wrapper",
      v19,
      0,
      v28);
    _qdf_op_unprotect();
    result = v19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
