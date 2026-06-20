__int64 __fastcall wlan_hdd_cfg80211_flush_pmksa(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  _QWORD *v30; // x20
  __int64 vdev_by_user; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x22
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  _QWORD v57[2]; // [xsp+0h] [xbp-10h] BYREF

  v57[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v57[0] = 0;
  result = _osif_vdev_sync_op_start(a2, v57, "wlan_hdd_cfg80211_flush_pmksa");
  if ( !(_DWORD)result )
  {
    v12 = qdf_trace_msg(0x33u, 8u, "%s: enter", v4, v5, v6, v7, v8, v9, v10, v11, "__wlan_hdd_cfg80211_flush_pmksa");
    if ( (unsigned int)hdd_get_conparam(v12) == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "__wlan_hdd_cfg80211_flush_pmksa");
      v21 = -22;
    }
    else if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                              *(unsigned __int8 *)(*(_QWORD *)(a2 + 55520) + 8LL),
                              "__wlan_hdd_cfg80211_flush_pmksa") )
    {
      v21 = -22;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Flushing PMKSA",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "__wlan_hdd_cfg80211_flush_pmksa");
      v30 = *(_QWORD **)(a2 + 2712);
      v21 = _wlan_hdd_validate_context(v30, "__wlan_hdd_cfg80211_flush_pmksa");
      if ( !v21 )
      {
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a2 + 55520), 6, "wlan_hdd_flush_pmksa_cache");
        if ( vdev_by_user )
        {
          v40 = vdev_by_user;
          v21 = wlan_crypto_set_del_pmksa(vdev_by_user, 0, 0, v32, v33, v34, v35, v36, v37, v38, v39);
          _hdd_objmgr_put_vdev_by_user(v40, 6, "wlan_hdd_flush_pmksa_cache");
          if ( v21 )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Cannot flush PMKIDCache",
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              "wlan_hdd_flush_pmksa_cache");
            if ( v21 == 11 )
              v21 = -95;
            else
              v21 = -22;
          }
        }
        else
        {
          v21 = -22;
        }
        sme_set_del_pmkid_cache(*v30, *(unsigned __int8 *)(*(_QWORD *)(a2 + 55520) + 8LL), 0, 0);
        qdf_trace_msg(0x33u, 8u, "%s: exit", v49, v50, v51, v52, v53, v54, v55, v56, "__wlan_hdd_cfg80211_flush_pmksa");
      }
    }
    _osif_vdev_sync_op_stop(v57[0], "wlan_hdd_cfg80211_flush_pmksa");
    result = v21;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
