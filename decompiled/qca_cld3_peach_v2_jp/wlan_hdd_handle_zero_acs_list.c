__int64 __fastcall wlan_hdd_handle_zero_acs_list(__int64 result, _DWORD *a2, _BYTE *a3, int *a4, unsigned __int8 a5)
{
  __int64 *v9; // x22
  __int16 v10; // w24
  __int16 v11; // w24
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w25
  __int64 v21; // x0
  __int64 v22; // x24
  unsigned __int64 v23; // x28
  unsigned int i; // w26
  int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned __int64 v34; // x24
  unsigned int v35; // w8
  int v36; // w25
  __int64 v37; // x26
  int channel_state_for_pwrmode; // w0
  int v39; // w23
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  int v48; // w4
  __int64 v49; // [xsp+0h] [xbp-10h] BYREF
  __int64 v50; // [xsp+8h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v49) = 0;
  if ( !a3 )
    goto LABEL_30;
  if ( !a2 )
    goto LABEL_30;
  if ( *a3 )
    goto LABEL_30;
  if ( !a4 )
    goto LABEL_30;
  if ( !a5 )
    goto LABEL_30;
  v9 = (__int64 *)result;
  result = policy_mgr_is_force_scc(*(_QWORD *)result);
  if ( (result & 1) == 0 )
    goto LABEL_30;
  v10 = policy_mgr_mode_specific_connection_count(*v9, 0, nullptr);
  v11 = policy_mgr_mode_specific_connection_count(*v9, 2, nullptr) + v10;
  result = wlan_mlme_get_force_sap_enabled(*v9, (_BYTE *)&v49 + 4);
  if ( !v11 && BYTE4(v49) != 1 )
    goto LABEL_30;
  v20 = a5;
  if ( a5 <= 0x65u )
  {
    v21 = _qdf_mem_malloc(0x198u, "wlan_hdd_dump_freq_list", 3490);
    if ( v21 )
    {
      v22 = v21;
      LODWORD(v49) = a5;
      v23 = 0;
      for ( i = 0; i < 0x198; i += v25 )
      {
        v26 = scnprintf(v22 + i, 408 - i, "%d ", a4[v23++]);
        if ( v23 >= a5 )
          break;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Master channel list: %s",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "wlan_hdd_dump_freq_list",
        v22,
        v49,
        v50);
      _qdf_mem_free(v22);
      v20 = v49;
    }
  }
  v34 = 0;
  if ( (a5 & 0xFE) != 0 )
    v35 = v20;
  else
    v35 = 1;
  v36 = 0;
  v37 = 4LL * v35;
  while ( 1 )
  {
    channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(
                                  v9[1],
                                  a4[v34 / 4],
                                  0,
                                  v12,
                                  v13,
                                  v14,
                                  v15,
                                  v16,
                                  v17,
                                  v18,
                                  v19);
    if ( (channel_state_for_pwrmode & 0xFFFFFFFB) == 0 )
      goto LABEL_20;
    v39 = channel_state_for_pwrmode;
    if ( wlan_reg_is_6ghz_chan_freq(a4[v34 / 4])
      && (wlan_reg_is_6ghz_psc_chan_freq(a4[v34 / 4], v40, v41, v42, v43, v44, v45, v46, v47) & 1) == 0 )
    {
      goto LABEL_20;
    }
    if ( (((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_is_safe_channel)(*v9, (unsigned int)a4[v34 / 4]) & 1) == 0 )
      goto LABEL_20;
    v48 = a4[v34 / 4];
    if ( (unsigned int)(v39 - 1) > 1 )
      break;
    v36 = a4[v34 / 4];
LABEL_20:
    v34 += 4LL;
    if ( v37 == v34 )
      goto LABEL_27;
  }
  if ( v48 )
    goto LABEL_29;
LABEL_27:
  v48 = v36;
  if ( !v36 )
    v48 = *a4;
LABEL_29:
  *a2 = v48;
  *a3 = 1;
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: restore acs chan list to single freq %d",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "wlan_hdd_handle_zero_acs_list");
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
