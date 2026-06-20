__int64 __fastcall sap_select_default_oper_chan(
        _QWORD *a1,
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
  __int64 v10; // x24
  __int64 v13; // x25
  unsigned int v14; // w21
  unsigned int v15; // w22
  int channel_state_for_pwrmode; // w23
  unsigned int v17; // w23
  int *v19; // x8
  __int64 v20; // x5
  unsigned int v21; // w9
  int v22; // w8
  unsigned int v23; // w21

  v10 = *(_QWORD *)(a2 + 1536);
  if ( !v10 )
    return 0;
  if ( *(_BYTE *)(v10 + 24) && *(_QWORD *)(v10 + 16) )
  {
    v13 = 0;
    v14 = 0;
    v15 = 0;
    while ( 1 )
    {
      channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(
                                    a1[2695],
                                    *(_DWORD *)(*(_QWORD *)(v10 + 16) + 4 * v13),
                                    0,
                                    a3,
                                    a4,
                                    a5,
                                    a6,
                                    a7,
                                    a8,
                                    a9,
                                    a10);
      if ( channel_state_for_pwrmode == 3 )
      {
        if ( wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(*(_QWORD *)(v10 + 16) + 4 * v13)) )
        {
          v19 = *(int **)(v10 + 16);
          v20 = (unsigned int)v19[v13];
          if ( (_DWORD)v20 )
            v21 = v19[v13];
          else
            v21 = v15;
LABEL_23:
          v22 = *v19;
          if ( !v21 )
            v21 = v14;
          if ( v21 )
            v17 = v21;
          else
            v17 = v22;
          qdf_trace_msg(
            0x39u,
            8u,
            "%s: default freq %d chosen from %d %d %d %d",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            "sap_select_default_oper_chan",
            v17,
            v20,
            v15,
            v14,
            v22);
LABEL_29:
          v23 = wlan_ll_lt_sap_override_freq(a1[2694], *(unsigned __int8 *)(a2 + 12), v17);
          if ( (unsigned int)policy_mgr_mode_specific_connection_count(a1[2694], 5, nullptr)
            && (wlan_nan_is_sta_sap_nan_allowed(a1[2694]) & 1) != 0 )
          {
            return wlan_nan_sap_override_freq(a1[2694], *(unsigned __int8 *)(a2 + 12), v23);
          }
          else
          {
            return v23;
          }
        }
        if ( !v14 )
          v14 = *(_DWORD *)(*(_QWORD *)(v10 + 16) + 4 * v13);
      }
      else if ( !v15 && channel_state_for_pwrmode == 2 )
      {
        if ( wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(*(_QWORD *)(v10 + 16) + 4 * v13)) )
          v15 = *(_DWORD *)(*(_QWORD *)(v10 + 16) + 4 * v13);
        else
          v15 = 0;
      }
      if ( ++v13 >= (unsigned __int64)*(unsigned __int8 *)(v10 + 24) )
      {
        v19 = *(int **)(v10 + 16);
        v20 = 0;
        v21 = v15;
        goto LABEL_23;
      }
    }
  }
  if ( *(_BYTE *)(a1[1] + 5370LL) == 1 )
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: SAP forced, freq selected %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sap_select_default_oper_chan",
      **(unsigned int **)(v10 + 32));
    v17 = **(_DWORD **)(v10 + 32);
    goto LABEL_29;
  }
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: No channel left for operation",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "sap_select_default_oper_chan");
  return 0;
}
