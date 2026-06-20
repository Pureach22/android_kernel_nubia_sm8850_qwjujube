__int64 __fastcall wlansap_roam_process_ch_change_success(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        _DWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v16; // x0
  unsigned int *sap_ch_sw_info; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int *v26; // x23
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w5
  __int64 result; // x0
  unsigned int v37; // w8
  unsigned int v38; // w23
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  char is_dfs_for_freq; // w24
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  bool is_6ghz_chan_freq; // w0
  __int64 v58; // x4
  bool v59; // w25
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  int v68; // w8
  int v69; // w9
  _QWORD v70[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v71; // [xsp+20h] [xbp-20h] BYREF
  __int64 v72; // [xsp+28h] [xbp-18h]
  __int64 v73; // [xsp+30h] [xbp-10h]
  __int64 v74; // [xsp+38h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *((_QWORD *)a2 + 2);
  v72 = 0;
  v73 = 0;
  v71 = 0;
  sap_ch_sw_info = (unsigned int *)wlan_get_sap_ch_sw_info(v16, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( sap_ch_sw_info )
  {
    v26 = sap_ch_sw_info;
    qdf_trace_msg(
      0x39u,
      8u,
      "sap_fsm: vdev %d: sapdfs: SAP CSA: freq %d state %d evt freq %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      *((unsigned __int8 *)a2 + 12),
      *sap_ch_sw_info,
      a2[182],
      *(unsigned int *)(*(_QWORD *)(a3 + 128) + 4LL));
    v35 = a2[182];
    if ( v35 != 3 && v35 )
    {
      v37 = a2[375];
      v38 = *v26;
      if ( v37 == 4 )
      {
        if ( (unsigned int)wlan_reg_get_channel_state_for_pwrmode(
                             *(_QWORD *)(a1 + 21632),
                             v38,
                             0,
                             v27,
                             v28,
                             v29,
                             v30,
                             v31,
                             v32,
                             v33,
                             v34) == 2
          || (is_dfs_for_freq = 0,
              (unsigned int)wlan_reg_get_channel_state_for_pwrmode(
                              *(_QWORD *)(a1 + 21632),
                              a2[378],
                              0,
                              v49,
                              v50,
                              v51,
                              v52,
                              v53,
                              v54,
                              v55,
                              v56) == 2) )
        {
          is_dfs_for_freq = 1;
        }
      }
      else if ( v37 == 3 )
      {
        memset(v70, 0, sizeof(v70));
        wlan_reg_set_create_punc_bitmap((__int64)v70, 1);
        v39 = *(_QWORD *)(a1 + 21632);
        LODWORD(v70[0]) = a2[375];
        is_dfs_for_freq = (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                          v39,
                                          v38,
                                          (int *)v70,
                                          0,
                                          v40,
                                          v41,
                                          v42,
                                          v43,
                                          v44,
                                          v45,
                                          v46,
                                          v47) == 2;
      }
      else
      {
        is_dfs_for_freq = wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21632), v38, v27, v28, v29, v30, v31, v32, v33, v34);
      }
      is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(*a2);
      v58 = *((unsigned __int8 *)a2 + 12);
      v59 = is_6ghz_chan_freq;
      a2[182] = 1;
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sap_fsm: vdev %d: => SAP_STARTING",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "wlansap_roam_process_ch_change_success",
        v58);
      *a2 = v38;
      if ( v59
        || (is_dfs_for_freq & 1) == 0
        || (wlan_pre_cac_complete_get(*((_QWORD *)a2 + 2)) & 1) != 0
        || (sap_plus_sap_cac_skip(a1, a2, *a2) & 1) != 0
        || *(_BYTE *)(a1 + 14880)
        || (policy_mgr_get_dfs_master_dynamic_enabled(*(_QWORD *)(a1 + 21624)) & 1) == 0 )
      {
        v68 = 7;
        v69 = 18;
        *((_BYTE *)a2 + 13) = 0;
        LODWORD(v72) = 7;
      }
      else
      {
        v69 = 0;
        v68 = 0;
        LODWORD(v72) = 13;
      }
      v71 = a3;
      HIDWORD(v72) = v69;
      LODWORD(v73) = v68;
      result = sap_fsm(a2, &v71);
      if ( (_DWORD)result )
        *a4 = 16;
    }
    else
    {
      result = qdf_trace_msg(
                 0x39u,
                 4u,
                 "%s: sap_fsm: vdev %d: sapdfs: state %d, not starting SAP after channel change",
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 "wlansap_roam_process_ch_change_success",
                 *((unsigned __int8 *)a2 + 12));
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x39u,
               2u,
               "%s: Invalid channel info",
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               "wlansap_roam_process_ch_change_success");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
