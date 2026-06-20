__int64 __fastcall sap_dnw_downgrade_channel_width(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  _QWORD *v13; // x20
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  unsigned int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w19
  __int64 sap_ch_sw_info; // x0

  if ( !a1 )
  {
    v23 = "%s: Invalid SAP pointer";
    goto LABEL_9;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v23 = "%s: Invalid MAC context";
    goto LABEL_9;
  }
  if ( *(_DWORD *)(a1 + 728) != 2 )
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: sap isn't started, %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sap_dnw_downgrade_channel_width");
    return 16;
  }
  v13 = context;
  result = wlansap_set_chan_params_for_csa((__int64)context, a1, *(_DWORD *)a1, 0, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (_DWORD)result )
    return result;
  if ( (unsigned int)policy_mgr_check_and_set_hw_mode_for_channel_switch(
                       v13[2694],
                       *(_BYTE *)(a1 + 12),
                       *(_DWORD *)a1,
                       8u) != 16 )
  {
    v24 = policy_mgr_reset_chan_switch_complete_evt(v13[2694]);
    if ( v24 )
    {
      v33 = v24;
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Reset channel switch evt fail",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "sap_dnw_downgrade_channel_width");
      return v33;
    }
    sap_ch_sw_info = wlan_get_sap_ch_sw_info(*(_QWORD *)(a1 + 16), v25, v26, v27, v28, v29, v30, v31, v32);
    if ( sap_ch_sw_info )
    {
      *(_BYTE *)(sap_ch_sw_info + 8) = 1;
      *(_BYTE *)(a1 + 13) = 1;
      sap_cac_reset_current_notify(a1);
      sme_csa_restart(v13, *(unsigned __int8 *)(a1 + 12));
      return 0;
    }
    v23 = "%s: Invalid channel info";
LABEL_9:
    qdf_trace_msg(0x39u, 2u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "sap_dnw_downgrade_channel_width");
    return 5;
  }
  qdf_trace_msg(
    0x39u,
    2u,
    "%s: HW change required but failed to set hw mode",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "sap_dnw_downgrade_channel_width");
  return 16;
}
