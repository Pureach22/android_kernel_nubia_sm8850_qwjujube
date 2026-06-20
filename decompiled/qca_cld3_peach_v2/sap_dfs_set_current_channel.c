__int64 __fastcall sap_dfs_set_current_channel(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v10; // w22
  unsigned int v11; // w23
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  _QWORD *v22; // x20
  char v23; // w24
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  __int64 v33; // x1
  unsigned __int16 beaconing_concurrent_operation_channel; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x2
  __int64 v44; // [xsp+8h] [xbp-18h]
  __int64 v45; // [xsp+10h] [xbp-10h] BYREF
  __int64 v46; // [xsp+18h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *((unsigned __int8 *)a1 + 1505);
  v11 = *((unsigned __int8 *)a1 + 1506);
  v45 = 0;
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v43 = "%s: Invalid MAC context";
LABEL_12:
    result = qdf_trace_msg(0x39u, 2u, v43, v13, v14, v15, v16, v17, v18, v19, v20, "sap_dfs_set_current_channel");
    goto LABEL_13;
  }
  v21 = context[2704];
  v22 = context;
  if ( !v21 )
  {
    v43 = "%s: null pdev";
    goto LABEL_12;
  }
  v23 = wlan_mlme_check_chan_param_has_dfs(
          context[2704],
          (__int64)(a1 + 375),
          *a1,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20);
  result = qdf_trace_msg(
             0x39u,
             8u,
             "%s: freq=%d, dfs %d seg0=%d, seg1=%d, bw %d",
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             "sap_dfs_set_current_channel",
             *a1,
             v23 & 1,
             v10,
             v11,
             a1[375],
             v44,
             v45,
             v46);
  if ( (v23 & 1) != 0 )
  {
    if ( !policy_mgr_concurrent_beaconing_sessions_running(v22[2703])
      || (beaconing_concurrent_operation_channel = sme_get_beaconing_concurrent_operation_channel(
                                                     v22,
                                                     *((unsigned __int8 *)a1 + 12)),
          (v33 = beaconing_concurrent_operation_channel) == 0)
      || (wlan_reg_is_dfs_for_freq(v21, beaconing_concurrent_operation_channel, v35, v36, v37, v38, v39, v40, v41, v42)
        & 1) == 0 )
    {
      tgt_dfs_get_radars(v21, v33);
    }
    result = tgt_dfs_set_phyerr_filter_offload(v21);
    if ( *(_BYTE *)(v22[1] + 3369LL) == 1 )
      result = tgt_dfs_control(v21, 5, (char *)&v45 + 4, 4, 0, 0, &v45);
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
