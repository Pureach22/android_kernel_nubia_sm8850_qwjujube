__int64 __fastcall hdd_dcs_chan_select_complete(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x19
  __int64 v11; // x22
  unsigned int freq; // w0
  __int64 v13; // x8
  __int64 v14; // x0
  unsigned int v15; // w20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  __int64 link_info_by_vdev; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x21
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  _BYTE v43[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(__int64 **)(a1 + 24);
  if ( v9 )
  {
    v11 = *(_QWORD *)(a1 + 52824);
    freq = wlansap_dcs_get_freq(*(_QWORD *)(v11 + 272), a2, a3, a4, a5, a6, a7, a8, a9);
    if ( freq && freq != *(_DWORD *)(v11 + 2152) )
    {
      result = hdd_dcs_hostapd_set_chan((__int64)v9, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), freq);
    }
    else
    {
      v13 = *(_QWORD *)(a1 + 52824);
      v14 = *v9;
      v43[0] = 0;
      v15 = *(unsigned __int8 *)(v13 + 8);
      if ( (unsigned int)policy_mgr_get_mac_id_by_session_id(v14, *(_BYTE *)(v13 + 8), v43) )
      {
        result = qdf_trace_msg(
                   0x33u,
                   2u,
                   "%s: get mac id failed",
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   "hdd_dcs_hostapd_enable_wlan_interference_mitigation");
      }
      else
      {
        link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)v9, v15);
        if ( link_info_by_vdev )
        {
          v34 = link_info_by_vdev;
          result = wlansap_dcs_is_wlan_interference_mitigation_enabled(
                     *(_QWORD *)(link_info_by_vdev + 272),
                     v26,
                     v27,
                     v28,
                     v29,
                     v30,
                     v31,
                     v32,
                     v33);
          if ( (result & 1) != 0 )
          {
            result = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v34 + 2152));
            if ( (result & 1) == 0 )
              result = ucfg_config_dcs_event_data(*v9, v43[0], 1, v35, v36, v37, v38, v39, v40, v41, v42);
          }
        }
        else
        {
          result = qdf_trace_msg(
                     0x33u,
                     2u,
                     "%s: vdev_id %u does not exist with host",
                     v26,
                     v27,
                     v28,
                     v29,
                     v30,
                     v31,
                     v32,
                     v33,
                     "hdd_dcs_hostapd_enable_wlan_interference_mitigation",
                     v15);
        }
      }
    }
    *(_DWORD *)(v11 + 2344) = 0;
  }
  else
  {
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: Invalid HDD context pointer",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "hdd_dcs_chan_select_complete");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
