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
  char is_dfs_for_freq; // w24
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  bool is_6ghz_chan_freq; // w0
  __int64 v50; // x4
  bool v51; // w25
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  int v60; // w8
  int v61; // w9
  unsigned int v62; // [xsp+0h] [xbp-30h] BYREF
  __int64 v63; // [xsp+4h] [xbp-2Ch]
  int v64; // [xsp+Ch] [xbp-24h]
  __int64 v65; // [xsp+10h] [xbp-20h] BYREF
  __int64 v66; // [xsp+18h] [xbp-18h]
  __int64 v67; // [xsp+20h] [xbp-10h]
  __int64 v68; // [xsp+28h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *((_QWORD *)a2 + 2);
  v66 = 0;
  v67 = 0;
  v65 = 0;
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
                             *(_QWORD *)(a1 + 21560),
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
                              *(_QWORD *)(a1 + 21560),
                              a2[378],
                              0,
                              v41,
                              v42,
                              v43,
                              v44,
                              v45,
                              v46,
                              v47,
                              v48) == 2) )
        {
          is_dfs_for_freq = 1;
        }
      }
      else if ( v37 == 3 )
      {
        v39 = *(_QWORD *)(a1 + 21560);
        v64 = 0;
        v63 = 0;
        v62 = 3;
        is_dfs_for_freq = (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                          v39,
                                          v38,
                                          &v62,
                                          0,
                                          v27,
                                          v28,
                                          v29,
                                          v30,
                                          v31,
                                          v32,
                                          v33,
                                          v34) == 2;
      }
      else
      {
        is_dfs_for_freq = wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21560), v38, v27, v28, v29, v30, v31, v32, v33, v34);
      }
      is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(*a2);
      v50 = *((unsigned __int8 *)a2 + 12);
      v51 = is_6ghz_chan_freq;
      a2[182] = 1;
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sap_fsm: vdev %d: => SAP_STARTING",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "wlansap_roam_process_ch_change_success",
        v50);
      *a2 = v38;
      if ( v51
        || (is_dfs_for_freq & 1) == 0
        || (wlan_pre_cac_complete_get(*((_QWORD *)a2 + 2)) & 1) != 0
        || (sap_plus_sap_cac_skip(a1, a2, *a2) & 1) != 0
        || *(_BYTE *)(a1 + 14808)
        || (policy_mgr_get_dfs_master_dynamic_enabled(*(_QWORD *)(a1 + 21552)) & 1) == 0 )
      {
        v60 = 7;
        v61 = 18;
        *((_BYTE *)a2 + 13) = 0;
        LODWORD(v66) = 7;
      }
      else
      {
        v61 = 0;
        v60 = 0;
        LODWORD(v66) = 13;
      }
      v65 = a3;
      HIDWORD(v66) = v61;
      LODWORD(v67) = v60;
      result = sap_fsm(a2, &v65);
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
