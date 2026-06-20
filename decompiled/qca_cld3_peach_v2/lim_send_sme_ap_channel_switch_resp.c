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
  int v15; // w22
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
  unsigned int v26; // w8
  __int64 v27; // x0
  unsigned int v28; // w1
  char is_dfs_for_freq; // w21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int channel_state_for_pwrmode; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  _QWORD v47[3]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v48; // [xsp+18h] [xbp-38h] BYREF
  __int64 v49; // [xsp+20h] [xbp-30h]
  __int64 v50; // [xsp+28h] [xbp-28h]
  __int64 v51; // [xsp+30h] [xbp-20h]
  __int64 v52; // [xsp+38h] [xbp-18h]
  __int64 v53; // [xsp+40h] [xbp-10h]
  __int64 v54; // [xsp+48h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  qdf_runtime_pm_allow_suspend((__int64 *)(a2 + 8600));
  qdf_wake_lock_release(a2 + 8400, 0);
  result = _qdf_mem_malloc(0xCu, "lim_send_sme_ap_channel_switch_resp", 2684);
  if ( !result )
    goto LABEL_21;
  *(_DWORD *)(result + 4) = *(_DWORD *)(a2 + 284);
  *(_BYTE *)(result + 8) = *(_DWORD *)(a3 + 8);
  *(_BYTE *)result = *(_BYTE *)a3;
  v49 = result;
  LOWORD(v48) = 5205;
  HIDWORD(v48) = 0;
  sys_process_mmh_msg(a1, &v48);
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
    goto LABEL_21;
  }
  v15 = *(_DWORD *)(a2 + 7176);
  v16 = wlan_reg_freq_to_band(*(_DWORD *)(a2 + 284));
  if ( *(_BYTE *)(a2 + 7186) )
  {
    v25 = wlan_reg_chan_band_to_freq(
            a1[2704],
            *(unsigned __int8 *)(a2 + 7186),
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
LABEL_12:
    if ( (unsigned int)wlan_reg_get_channel_state_for_pwrmode(
                         a1[2704],
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
                                        a1[2704],
                                        v25,
                                        0,
                                        v30,
                                        v31,
                                        v32,
                                        v33,
                                        v34,
                                        v35,
                                        v36,
                                        v37),
          is_dfs_for_freq = 0,
          channel_state_for_pwrmode == 2) )
    {
      is_dfs_for_freq = 1;
    }
    goto LABEL_16;
  }
  v25 = 0;
  if ( v15 == 4 )
    goto LABEL_12;
LABEL_6:
  if ( v15 == 3 )
  {
    v26 = *(unsigned __int8 *)(a2 + 154);
    memset(v47, 0, sizeof(v47));
    if ( v26 <= 0xD && ((1 << v26) & 0x3001) != 0 )
      wlan_reg_set_create_punc_bitmap((__int64)v47, 1);
    v27 = a1[2704];
    v28 = *(_DWORD *)(a2 + 284);
    LODWORD(v47[0]) = 3;
    is_dfs_for_freq = (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                      v27,
                                      v28,
                                      (int *)v47,
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
    is_dfs_for_freq = wlan_reg_is_dfs_for_freq(a1[2704], *(_DWORD *)(a2 + 284), v17, v18, v19, v20, v21, v22, v23, v24);
  }
LABEL_16:
  if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 284))
    || (is_dfs_for_freq & 1) == 0
    || (*(_BYTE *)(a2 + 13288) & 1) != 0 )
  {
    lim_apply_configuration(a1, a2, v39, v40, v41, v42, v43, v44, v45, v46);
    lim_send_beacon(a1, a2);
    result = lim_obss_send_detection_cfg(a1, a2, 1);
  }
  else
  {
    result = lim_sap_move_to_cac_wait_state(a2);
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
