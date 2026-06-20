__int64 __fastcall wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_install(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _DWORD *v10; // x22
  int v11; // w20
  int v12; // w5
  int v13; // w6
  int v14; // w7
  int v15; // w8
  int v16; // w20
  int v17; // w5
  int v18; // w6
  int v19; // w7
  int v20; // w8
  int v21; // w20
  int v22; // w5
  int v23; // w6
  int v24; // w7
  int v25; // w8
  __int64 v26; // x4
  int v27; // w3
  int v28; // w4
  int v29; // w5
  int v30; // w6
  int v31; // w7
  __int64 v32; // x1
  char vars0; // [xsp+0h] [xbp+0h]

  v10 = (_DWORD *)gp_ipa;
  if ( a1[2] )
  {
    v11 = a1[3];
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: opt_dp_ctrl: i: %d, valid: %d, result: %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_install",
      0);
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_install",
      (int)"opt_dp_ctrl: i: %d, valid: %d, result: %d",
      0,
      a1[2],
      v11,
      v12,
      v13,
      v14,
      vars0);
    if ( !v11 )
      goto LABEL_10;
    v15 = v10[2100];
    v10[1935] = 0;
    v10[2100] = v15 + 1;
  }
  if ( !a1[6] )
    goto LABEL_7;
  v16 = a1[7];
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp_ctrl: i: %d, valid: %d, result: %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_install",
    1);
  wlan_ipa_log_message(
    (int)"wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_install",
    (int)"opt_dp_ctrl: i: %d, valid: %d, result: %d",
    1,
    a1[6],
    v16,
    v17,
    v18,
    v19,
    vars0);
  if ( !v16 )
  {
LABEL_10:
    ++v10[2101];
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Filter installation failed, failure cnt %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_install");
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_install",
      (int)"Filter installation failed, failure cnt %d",
      v10[2101],
      v27,
      v28,
      v29,
      v30,
      v31,
      vars0);
    v26 = 49;
    v10[1935] = 49;
    goto LABEL_12;
  }
  v20 = v10[2100];
  v10[1935] = 0;
  v10[2100] = v20 + 1;
LABEL_7:
  if ( !a1[10] )
  {
    v26 = (unsigned int)v10[1935];
    goto LABEL_12;
  }
  v21 = a1[11];
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp_ctrl: i: %d, valid: %d, result: %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_install",
    2);
  wlan_ipa_log_message(
    (int)"wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_install",
    (int)"opt_dp_ctrl: i: %d, valid: %d, result: %d",
    2,
    a1[10],
    v21,
    v22,
    v23,
    v24,
    vars0);
  if ( !v21 )
    goto LABEL_10;
  v25 = v10[2100];
  v26 = 0;
  v10[1935] = 0;
  v10[2100] = v25 + 1;
LABEL_12:
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp_ctrl: ipa_flt_event_response set status: %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_install",
    v26);
  return qdf_event_set((__int64)(v10 + 2028), v32);
}
