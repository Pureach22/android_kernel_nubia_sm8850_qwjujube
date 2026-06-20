__int64 __fastcall lim_send_sme_ap_channel_switch_resp(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w23
  char v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w21
  __int64 v26; // x0
  unsigned int v27; // w1
  char is_dfs_for_freq; // w21
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  int channel_state_for_pwrmode; // w0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // [xsp+8h] [xbp-48h] BYREF
  __int64 v47; // [xsp+Ch] [xbp-44h]
  int v48; // [xsp+14h] [xbp-3Ch]
  __int64 v49; // [xsp+18h] [xbp-38h] BYREF
  __int64 v50; // [xsp+20h] [xbp-30h]
  __int64 v51; // [xsp+28h] [xbp-28h]
  __int64 v52; // [xsp+30h] [xbp-20h]
  __int64 v53; // [xsp+38h] [xbp-18h]
  __int64 v54; // [xsp+40h] [xbp-10h]
  __int64 v55; // [xsp+48h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  qdf_runtime_pm_allow_suspend((__int64 *)(a2 + 8600));
  qdf_wake_lock_release(a2 + 8400, 0);
  result = _qdf_mem_malloc(0xCu, "lim_send_sme_ap_channel_switch_resp", 2684);
  if ( !result )
    goto LABEL_18;
  *(_DWORD *)(result + 4) = *(_DWORD *)(a2 + 284);
  *(_BYTE *)(result + 8) = *(_DWORD *)(a3 + 8);
  *(_BYTE *)result = *(_BYTE *)a3;
  v50 = result;
  LOWORD(v49) = 5205;
  HIDWORD(v49) = 0;
  sys_process_mmh_msg(a1, &v49);
  if ( *(_DWORD *)(a3 + 8) )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: failed to change sap freq to %u",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "lim_send_sme_ap_channel_switch_resp",
               *(unsigned int *)(a2 + 284));
    goto LABEL_18;
  }
  v15 = *(_DWORD *)(a2 + 7176);
  v16 = wlan_reg_freq_to_band(*(_DWORD *)(a2 + 284));
  if ( *(_BYTE *)(a2 + 7184) )
  {
    v25 = wlan_reg_chan_band_to_freq(
            a1[2695],
            *(unsigned __int8 *)(a2 + 7184),
            1LL << v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24);
    if ( v15 != 4 )
      goto LABEL_6;
LABEL_9:
    if ( (unsigned int)wlan_reg_get_channel_state_for_pwrmode(
                         a1[2695],
                         *(_DWORD *)(a2 + 284),
                         0,
                         v17,
                         v18,
                         v19,
                         v20,
                         v21,
                         v22,
                         v23,
                         v24) == 2
      || (channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(
                                        a1[2695],
                                        v25,
                                        0,
                                        v29,
                                        v30,
                                        v31,
                                        v32,
                                        v33,
                                        v34,
                                        v35,
                                        v36),
          is_dfs_for_freq = 0,
          channel_state_for_pwrmode == 2) )
    {
      is_dfs_for_freq = 1;
    }
    goto LABEL_13;
  }
  v25 = 0;
  if ( v15 == 4 )
    goto LABEL_9;
LABEL_6:
  if ( v15 == 3 )
  {
    v26 = a1[2695];
    v27 = *(_DWORD *)(a2 + 284);
    v48 = 0;
    v47 = 0;
    v46 = 3;
    is_dfs_for_freq = (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                      v26,
                                      v27,
                                      &v46,
                                      0,
                                      v17,
                                      v18,
                                      v19,
                                      v20,
                                      v21,
                                      v22,
                                      v23,
                                      v24) == 2;
  }
  else
  {
    is_dfs_for_freq = wlan_reg_is_dfs_for_freq(a1[2695], *(_DWORD *)(a2 + 284), v17, v18, v19, v20, v21, v22, v23, v24);
  }
LABEL_13:
  if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 284))
    || (is_dfs_for_freq & 1) == 0
    || (*(_BYTE *)(a2 + 10080) & 1) != 0 )
  {
    lim_apply_configuration(a1, a2, v38, v39, v40, v41, v42, v43, v44, v45);
    lim_send_beacon(a1, a2);
    result = lim_obss_send_detection_cfg(a1, a2, 1);
  }
  else
  {
    result = lim_sap_move_to_cac_wait_state(a2);
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
