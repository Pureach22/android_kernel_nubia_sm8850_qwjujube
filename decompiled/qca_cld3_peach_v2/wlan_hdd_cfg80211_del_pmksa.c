__int64 __fastcall wlan_hdd_cfg80211_del_pmksa(__int64 a1, __int64 a2, unsigned __int8 **a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _QWORD *v14; // x21
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x2
  const char *v25; // x3
  unsigned int v26; // w24
  __int64 v27; // x0
  void *v28; // x22
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  _QWORD v45[2]; // [xsp+0h] [xbp-10h] BYREF

  v45[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45[0] = 0;
  result = _osif_vdev_sync_op_start(a2, v45, "wlan_hdd_cfg80211_del_pmksa");
  if ( !(_DWORD)result )
  {
    v14 = *(_QWORD **)(a2 + 2712);
    v15 = qdf_trace_msg(0x33u, 8u, "%s: enter", v6, v7, v8, v9, v10, v11, v12, v13, "__wlan_hdd_cfg80211_del_pmksa");
    if ( (unsigned int)hdd_get_conparam(v15) == 5 )
    {
      v24 = "%s: Command not allowed in FTM mode";
    }
    else
    {
      if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                           *(unsigned __int8 *)(*(_QWORD *)(a2 + 55520) + 8LL),
                           "__wlan_hdd_cfg80211_del_pmksa") )
        goto LABEL_7;
      if ( a3 )
      {
        if ( *a3
          || (qdf_trace_msg(
                0x33u,
                3u,
                "%s: bssid is NULL",
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                "wlan_hdd_is_pmksa_valid"),
              a3[4])
          && a3[6] )
        {
          v26 = _wlan_hdd_validate_context(v14, "__wlan_hdd_cfg80211_del_pmksa");
          if ( !v26 )
          {
            v27 = _qdf_mem_malloc(0x98u, "__wlan_hdd_cfg80211_del_pmksa", 31314);
            if ( v27 )
            {
              v28 = (void *)v27;
              qdf_mtrace(51, 51, 0x48u, *(_BYTE *)(*(_QWORD *)(a2 + 55520) + 8LL), 0);
              hdd_fill_pmksa_info(v28, a3, 1);
              if ( (unsigned int)wlan_hdd_del_pmksa_cache(a2 + 2688, v28) )
              {
                if ( *a3 )
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: Failed to delete PMKSA for %02x:%02x:%02x:**:**:%02x",
                    v29,
                    v30,
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    "__wlan_hdd_cfg80211_del_pmksa",
                    **a3,
                    (*a3)[1],
                    (*a3)[2],
                    (*a3)[5]);
                else
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: Failed to delete PMKSA for null bssid",
                    v29,
                    v30,
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    "__wlan_hdd_cfg80211_del_pmksa");
                v26 = -22;
              }
              else
              {
                sme_clear_sae_single_pmk_info(*v14, *(unsigned __int8 *)(*(_QWORD *)(a2 + 55520) + 8LL), v28);
                sme_set_del_pmkid_cache(*v14, *(unsigned __int8 *)(*(_QWORD *)(a2 + 55520) + 8LL), v28, 0);
                v26 = 0;
              }
              qdf_mem_set(v28, 0x98u, 0);
              _qdf_mem_free((__int64)v28);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: exit",
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                "__wlan_hdd_cfg80211_del_pmksa");
            }
            else
            {
              v26 = -12;
            }
          }
          goto LABEL_8;
        }
        v24 = "%s: either ssid or cache_id are NULL";
        v25 = "wlan_hdd_is_pmksa_valid";
        goto LABEL_5;
      }
      v24 = "%s: pmksa is NULL";
    }
    v25 = "__wlan_hdd_cfg80211_del_pmksa";
LABEL_5:
    qdf_trace_msg(0x33u, 2u, v24, v16, v17, v18, v19, v20, v21, v22, v23, v25);
LABEL_7:
    v26 = -22;
LABEL_8:
    _osif_vdev_sync_op_stop(v45[0], "wlan_hdd_cfg80211_del_pmksa");
    result = v26;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
