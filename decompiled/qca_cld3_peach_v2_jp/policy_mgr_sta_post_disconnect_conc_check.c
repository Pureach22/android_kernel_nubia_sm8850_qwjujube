__int64 __fastcall policy_mgr_sta_post_disconnect_conc_check(__int64 a1)
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
  __int64 *v12; // x21
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 (*v22)(void); // x8
  int v23; // w22
  char v24; // w8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w22
  void (__fastcall *v34)(__int64, __int64, __int64); // x8
  __int64 v35; // x1
  unsigned int v36; // w21
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7

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
      "policy_mgr_sta_post_disconnect_conc_check");
    return 4;
  }
  v11 = (_QWORD *)context;
  qdf_mutex_acquire(context + 56);
  if ( (policy_mgr_is_sap_mode((unsigned int)pm_conc_connection_list) & 1) == 0
    || (v12 = &pm_conc_connection_list, (qword_81C458 & 0x100000000LL) == 0) )
  {
    if ( (policy_mgr_is_sap_mode((unsigned int)qword_81C464) & 1) == 0
      || (v12 = &qword_81C464, (qword_81C47C & 0x100000000LL) == 0) )
    {
      if ( (policy_mgr_is_sap_mode((unsigned int)qword_81C488) & 1) == 0
        || (v12 = &qword_81C488, (qword_81C4A0 & 0x100000000LL) == 0) )
      {
        if ( (policy_mgr_is_sap_mode((unsigned int)qword_81C4AC) & 1) == 0
          || (v12 = &qword_81C4AC, (qword_81C4C4 & 0x100000000LL) == 0) )
        {
          if ( (policy_mgr_is_sap_mode((unsigned int)qword_81C4D0) & 1) == 0
            || (v12 = &qword_81C4D0, (qword_81C4E8 & 0x100000000LL) == 0) )
          {
            qdf_mutex_release((__int64)(v11 + 7));
            goto LABEL_23;
          }
        }
      }
    }
  }
  qdf_mutex_release((__int64)(v11 + 7));
  if ( !*((_DWORD *)v12 + 1) )
  {
LABEL_23:
    result = 0;
    goto LABEL_24;
  }
  result = policy_mgr_mode_specific_get_channel(a1, 5);
  if ( *((_DWORD *)v12 + 1) == (_DWORD)result )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: NAN and SAP already in SCC",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "policy_mgr_sta_post_disconnect_conc_check");
    goto LABEL_23;
  }
  if ( (_DWORD)result )
  {
    v22 = (__int64 (*)(void))v11[40];
    if ( v22 )
    {
      v23 = result;
      if ( *((_DWORD *)v22 - 1) != 799902358 )
        __break(0x8228u);
      v24 = v22();
      LODWORD(result) = v23;
      if ( (v24 & 1) != 0 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: channel switch is already in progress",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "policy_mgr_sta_post_disconnect_conc_check");
        return 0;
      }
    }
    if ( v11[42] )
    {
      v33 = result;
      if ( (wlan_nan_is_sta_sap_nan_allowed(a1) & 1) != 0 )
      {
        v34 = (void (__fastcall *)(__int64, __int64, __int64))v11[42];
        v35 = *((unsigned int *)v12 + 6);
        if ( *((_DWORD *)v34 - 1) != -1125204353 )
          __break(0x8228u);
        v34(a1, v35, 8);
        v36 = policy_mgr_change_sap_channel_with_csa(a1, *((_DWORD *)v12 + 6), v33, 1u, 1);
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: Force SCC for SAP Ch freq: %d",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "policy_mgr_sta_post_disconnect_conc_check",
          v33);
        if ( v36 )
          result = v36;
        else
          result = 24;
        goto LABEL_24;
      }
    }
    goto LABEL_23;
  }
LABEL_24:
  *(_BYTE *)(v11[262] + 52LL) = 0;
  return result;
}
