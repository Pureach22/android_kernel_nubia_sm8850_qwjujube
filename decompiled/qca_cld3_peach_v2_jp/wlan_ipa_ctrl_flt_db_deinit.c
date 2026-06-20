__int64 __fastcall wlan_ipa_ctrl_flt_db_deinit(__int64 result, unsigned __int8 a2)
{
  _BYTE *v2; // x22
  __int64 v3; // x19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v13; // w4
  int v14; // w5
  int v15; // w6
  int v16; // w7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w4
  int v26; // w5
  int v27; // w6
  int v28; // w7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  int v37; // w4
  int v38; // w5
  int v39; // w6
  int v40; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  v2 = (_BYTE *)(result + 4096);
  v3 = result;
  if ( *(_BYTE *)(result + 7797) == 1 )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD))wlan_ipa_opt_dp_ctrl_flt_add_status)(
               result,
               *(unsigned int *)(result + 7792));
    v2[3701] = 0;
    if ( (result & 1) != 0 && (v2[3416] & 1) == 0 )
    {
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: opt_dp_ctrl: handle deleted internally - %d, status code - %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "wlan_ipa_ctrl_flt_db_deinit",
        *(unsigned int *)(v3 + 7792),
        a2);
      wlan_ipa_log_message(
        (int)"wlan_ipa_ctrl_flt_db_deinit",
        (int)"opt_dp_ctrl: handle deleted internally - %d, status code - %d",
        *(_DWORD *)(v3 + 7792),
        a2,
        v13,
        v14,
        v15,
        v16,
        vars0);
      result = ipa_wdi_opt_dpath_notify_ctrl_flt_rem_per_inst(
                 *(unsigned int *)(v3 + 7460),
                 *(unsigned int *)(v3 + 7792),
                 a2);
    }
  }
  if ( v2[3805] == 1 )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD))wlan_ipa_opt_dp_ctrl_flt_add_status)(
               v3,
               *(unsigned int *)(v3 + 7896));
    v2[3805] = 0;
    if ( (result & 1) != 0 && (v2[3416] & 1) == 0 )
    {
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: opt_dp_ctrl: handle deleted internally - %d, status code - %d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "wlan_ipa_ctrl_flt_db_deinit",
        *(unsigned int *)(v3 + 7896),
        a2);
      wlan_ipa_log_message(
        (int)"wlan_ipa_ctrl_flt_db_deinit",
        (int)"opt_dp_ctrl: handle deleted internally - %d, status code - %d",
        *(_DWORD *)(v3 + 7896),
        a2,
        v25,
        v26,
        v27,
        v28,
        vars0);
      result = ipa_wdi_opt_dpath_notify_ctrl_flt_rem_per_inst(
                 *(unsigned int *)(v3 + 7460),
                 *(unsigned int *)(v3 + 7896),
                 a2);
    }
  }
  if ( v2[3909] == 1 )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD))wlan_ipa_opt_dp_ctrl_flt_add_status)(
               v3,
               *(unsigned int *)(v3 + 8000));
    v2[3909] = 0;
    if ( (result & 1) != 0 && (v2[3416] & 1) == 0 )
    {
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: opt_dp_ctrl: handle deleted internally - %d, status code - %d",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "wlan_ipa_ctrl_flt_db_deinit",
        *(unsigned int *)(v3 + 8000),
        a2);
      wlan_ipa_log_message(
        (int)"wlan_ipa_ctrl_flt_db_deinit",
        (int)"opt_dp_ctrl: handle deleted internally - %d, status code - %d",
        *(_DWORD *)(v3 + 8000),
        a2,
        v37,
        v38,
        v39,
        v40,
        vars0);
      return ipa_wdi_opt_dpath_notify_ctrl_flt_rem_per_inst(
               *(unsigned int *)(v3 + 7460),
               *(unsigned int *)(v3 + 8000),
               a2);
    }
  }
  return result;
}
