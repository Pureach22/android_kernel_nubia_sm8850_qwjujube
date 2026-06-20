__int64 __fastcall sap_fsm_handle_radar_during_cac(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int *sap_ch_sw_info; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int *v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x25
  const char *v31; // x2
  int v32; // w8
  __int64 v33; // x24
  __int64 v34; // x0
  __int64 active_channel; // x0

  sap_ch_sw_info = (unsigned int *)wlan_get_sap_ch_sw_info(*(_QWORD *)(a1 + 16), a3, a4, a5, a6, a7, a8, a9, a10);
  if ( sap_ch_sw_info )
  {
    v21 = sap_ch_sw_info;
    if ( *sap_ch_sw_info )
    {
      wlan_reg_set_channel_params_for_pwrmode(
        *(_QWORD *)(a2 + 21560),
        *sap_ch_sw_info,
        0,
        a1 + 1500,
        0,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20);
      v30 = -96;
      while ( 1 )
      {
        v32 = *(_DWORD *)(a2 + v30 + 14920);
        v33 = *(_QWORD *)(a2 + v30 + 14912);
        if ( v32 != 1 && v32 != 3 || !v33 || !*(_DWORD *)(v33 + 728) )
          goto LABEL_6;
        v34 = *(_QWORD *)(v33 + 16);
        if ( v34 )
        {
          active_channel = wlan_vdev_get_active_channel(v34);
          if ( active_channel )
          {
            if ( (*(_WORD *)(active_channel + 6) & 6) != 0 )
            {
              *(_BYTE *)(v33 + 1628) = 1;
              wlansap_channel_change_request(v33, *v21);
            }
            goto LABEL_6;
          }
          v31 = "%s: Couldn't get vdev active channel";
        }
        else
        {
          v31 = "%s: vdev invalid";
        }
        qdf_trace_msg(0x39u, 8u, v31, v22, v23, v24, v25, v26, v27, v28, v29, "sap_operating_on_dfs");
LABEL_6:
        v30 += 16;
        if ( !v30 )
          return 0;
      }
    }
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid target channel freq %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "sap_fsm_handle_radar_during_cac",
      0);
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid channel info",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "sap_fsm_handle_radar_during_cac");
  }
  return 16;
}
