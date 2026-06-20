__int64 __fastcall wlan_hdd_cfg80211_set_power_mgmt(__int64 a1, __int64 a2, char a3, unsigned int a4)
{
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x2
  unsigned int v34; // w1
  int v35; // w0
  __int64 v36; // x24
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w19
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  int v62; // w0
  int v63; // w19
  _QWORD v64[2]; // [xsp+0h] [xbp-10h] BYREF

  v64[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v64[0] = 0;
  result = _osif_vdev_sync_op_start(a2, v64, "wlan_hdd_cfg80211_set_power_mgmt");
  if ( !(_DWORD)result )
  {
    v16 = *(_QWORD *)(a2 + 55512);
    qdf_trace_msg(0x33u, 8u, "%s: enter", v8, v9, v10, v11, v12, v13, v14, v15, "__wlan_hdd_cfg80211_set_power_mgmt");
    if ( (a4 & 0x80000000) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: User space timeout: %d; Enter full power or power save: %d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "__wlan_hdd_cfg80211_set_power_mgmt",
        a4,
        a3 & 1);
      a4 = 0;
    }
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      v33 = "%s: Command not allowed in FTM mode";
      v34 = 2;
    }
    else
    {
      if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                           *(_BYTE *)(v16 + 8),
                           (__int64)"__wlan_hdd_cfg80211_set_power_mgmt",
                           v25,
                           v26,
                           v27,
                           v28,
                           v29,
                           v30,
                           v31,
                           v32) )
      {
        v35 = -22;
        goto LABEL_10;
      }
      qdf_mtrace(51, 51, 0x33u, *(_BYTE *)(v16 + 8), a4);
      v36 = *(_QWORD *)(a2 + 2712);
      v35 = _wlan_hdd_validate_context(
              v36,
              (__int64)"__wlan_hdd_cfg80211_set_power_mgmt",
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44);
      if ( v35 )
        goto LABEL_10;
      if ( *(_BYTE *)(v36 + 8280) != 1 )
      {
        if ( *(_DWORD *)(v36 + 1464) == 1 )
        {
          flush_work(a2 + 2736);
          flush_work(a2 + 2768);
          if ( (wlan_hdd_is_mlo_connection(*(_QWORD *)(a2 + 55512), v46, v47, v48, v49, v50, v51, v52, v53) & 1) != 0
            || (v62 = wlan_hdd_set_ps(v16, a2 + 4305, a3 & 1, a4)) == 0 )
          {
            v62 = 0;
            *(_BYTE *)(a2 + 4304) = a3 & 1;
          }
          v63 = v62;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: exit",
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            "__wlan_hdd_cfg80211_set_power_mgmt");
          v35 = v63;
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Driver Module not enabled return success",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "__wlan_hdd_cfg80211_set_power_mgmt");
          v35 = 0;
        }
        goto LABEL_10;
      }
      v33 = "%s: LPC has disabled power save";
      v34 = 8;
    }
    qdf_trace_msg(0x33u, v34, v33, v25, v26, v27, v28, v29, v30, v31, v32, "__wlan_hdd_cfg80211_set_power_mgmt");
    v35 = -22;
LABEL_10:
    v45 = v35;
    _osif_vdev_sync_op_stop(v64[0], "wlan_hdd_cfg80211_set_power_mgmt");
    result = v45;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
