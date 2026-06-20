__int64 __fastcall wlan_hdd_cfg80211_spectral_scan_get_status(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x23
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 vdev_by_user; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x22
  double status; // d0
  int v47; // w0
  int v48; // w19
  unsigned int *v49; // x8
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w19
  __int64 v66[2]; // [xsp+0h] [xbp-10h] BYREF

  v66[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 488);
  v66[0] = 0;
  result = _osif_psoc_sync_op_start(v8, v66, (__int64)"wlan_hdd_cfg80211_spectral_scan_get_status");
  if ( (_DWORD)result )
  {
LABEL_11:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a1 )
  {
    v18 = *(_QWORD *)(a2 + 32);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__wlan_hdd_cfg80211_spectral_scan_get_status");
    v27 = _wlan_hdd_validate_context(
            a1 + 1536,
            (__int64)"__wlan_hdd_cfg80211_spectral_scan_get_status",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26);
    if ( !v27 )
    {
      if ( (unsigned int)hdd_get_conparam() == 5 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Command not allowed in FTM mode",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "__wlan_hdd_cfg80211_spectral_scan_get_status");
        v27 = -1;
      }
      else
      {
        v27 = _hdd_validate_adapter(
                v18 + 2688,
                (__int64)"__wlan_hdd_cfg80211_spectral_scan_get_status",
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35);
        if ( !v27 )
        {
          vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                           *(_QWORD *)(v18 + 55512),
                           0x55u,
                           (__int64)"__wlan_hdd_cfg80211_spectral_scan_get_status");
          if ( vdev_by_user )
          {
            v45 = vdev_by_user;
            status = wlan_cfg80211_spectral_scan_get_status(a1, *(_QWORD *)(a1 + 1544), vdev_by_user, a3, a4);
            v48 = v47;
            _hdd_objmgr_put_vdev_by_user(
              v45,
              0x55u,
              (__int64)"__wlan_hdd_cfg80211_spectral_scan_get_status",
              v49,
              status,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56);
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: exit",
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              "__wlan_hdd_cfg80211_spectral_scan_get_status");
            v27 = v48;
          }
          else
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: can't get vdev",
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              "__wlan_hdd_cfg80211_spectral_scan_get_status");
            v27 = -22;
          }
        }
      }
    }
    v65 = v27;
    _osif_psoc_sync_op_stop(v66[0], (__int64)"wlan_hdd_cfg80211_spectral_scan_get_status");
    result = v65;
    goto LABEL_11;
  }
  __break(0x800u);
  return hdd_spectral_register_to_dbr(result);
}
