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
  unsigned __int8 *v16; // x23
  char v17; // w21
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2
  unsigned int v35; // w1
  int v36; // w0
  __int64 v37; // x24
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w19
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  int v63; // w0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  int v72; // w20
  _QWORD v73[2]; // [xsp+0h] [xbp-10h] BYREF

  v73[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v73[0] = 0;
  result = _osif_vdev_sync_op_start(a2, v73, "wlan_hdd_cfg80211_set_power_mgmt");
  if ( !(_DWORD)result )
  {
    v16 = *(unsigned __int8 **)(a2 + 55520);
    v17 = a3 & 1;
    qdf_trace_msg(0x33u, 8u, "%s: enter", v8, v9, v10, v11, v12, v13, v14, v15, "__wlan_hdd_cfg80211_set_power_mgmt");
    if ( (a4 & 0x80000000) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: User space timeout: %d; Enter full power or power save: %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "__wlan_hdd_cfg80211_set_power_mgmt",
        a4,
        a3 & 1);
      a4 = 0;
    }
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      v34 = "%s: Command not allowed in FTM mode";
      v35 = 2;
    }
    else
    {
      if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                           v16[8],
                           (__int64)"__wlan_hdd_cfg80211_set_power_mgmt",
                           v26,
                           v27,
                           v28,
                           v29,
                           v30,
                           v31,
                           v32,
                           v33) )
      {
        v36 = -22;
        goto LABEL_10;
      }
      qdf_mtrace(51, 51, 0x33u, v16[8], a4);
      v37 = *(_QWORD *)(a2 + 2712);
      v36 = _wlan_hdd_validate_context(
              v37,
              (__int64)"__wlan_hdd_cfg80211_set_power_mgmt",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45);
      if ( v36 )
        goto LABEL_10;
      if ( *(_BYTE *)(v37 + 8312) != 1 )
      {
        if ( *(_DWORD *)(v37 + 1464) == 1 )
        {
          flush_work(a2 + 2736);
          flush_work(a2 + 2768);
          if ( (wlan_hdd_is_mlo_connection(*(_QWORD *)(a2 + 55520), v47, v48, v49, v50, v51, v52, v53, v54) & 1) != 0 )
            v63 = wlan_hdd_set_mlo_ps(a2 + 2688, a3 & 1, a4, -1);
          else
            v63 = wlan_hdd_set_ps(v16, a2 + 4305, a3 & 1, a4, v55, v56, v57, v58, v59, v60, v61, v62);
          v72 = v63;
          if ( !v63 )
            *(_BYTE *)(a2 + 4304) = v17;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: exit",
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            "__wlan_hdd_cfg80211_set_power_mgmt");
          v36 = v72;
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Driver Module not enabled return success",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "__wlan_hdd_cfg80211_set_power_mgmt");
          v36 = 0;
        }
        goto LABEL_10;
      }
      v34 = "%s: LPC has disabled power save";
      v35 = 8;
    }
    qdf_trace_msg(0x33u, v35, v34, v26, v27, v28, v29, v30, v31, v32, v33, "__wlan_hdd_cfg80211_set_power_mgmt");
    v36 = -22;
LABEL_10:
    v46 = v36;
    _osif_vdev_sync_op_stop(v73[0], "wlan_hdd_cfg80211_set_power_mgmt");
    result = v46;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
