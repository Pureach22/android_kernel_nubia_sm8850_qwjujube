__int64 __fastcall wlan_hdd_cfg80211_set_rekey_data(__int64 a1, __int64 a2, __int64 a3)
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
  __int64 *v14; // x21
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w23
  _BYTE *v33; // x0
  __int64 v34; // x22
  __int64 vdev_by_user; // x0
  __int64 v36; // x20
  unsigned int v37; // w19
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  _QWORD v46[2]; // [xsp+0h] [xbp-10h] BYREF

  v46[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46[0] = 0;
  result = _osif_vdev_sync_op_start(a2, v46, "wlan_hdd_cfg80211_set_rekey_data");
  if ( !(_DWORD)result )
  {
    v14 = *(__int64 **)(a2 + 2712);
    v15 = qdf_trace_msg(
            0x33u,
            8u,
            "%s: enter",
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            "__wlan_hdd_cfg80211_set_rekey_data");
    if ( (unsigned int)hdd_get_conparam(v15) == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "__wlan_hdd_cfg80211_set_rekey_data");
      v32 = -22;
    }
    else if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                              *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL),
                              "__wlan_hdd_cfg80211_set_rekey_data") )
    {
      v32 = -22;
    }
    else
    {
      qdf_mtrace(51, 51, 0x3Au, *(_BYTE *)(*(_QWORD *)(a2 + 55512) + 8LL), *(_DWORD *)(a2 + 2728));
      v32 = _wlan_hdd_validate_context(v14, "__wlan_hdd_cfg80211_set_rekey_data");
      if ( !v32 )
      {
        v33 = (_BYTE *)_qdf_mem_malloc(0x80u, "__wlan_hdd_cfg80211_set_rekey_data", 31753);
        if ( v33 )
        {
          v34 = (__int64)v33;
          v33[119] = **(_BYTE **)(a3 + 16);
          v33[118] = *(_BYTE *)(*(_QWORD *)(a3 + 16) + 1LL);
          v33[117] = *(_BYTE *)(*(_QWORD *)(a3 + 16) + 2LL);
          v33[116] = *(_BYTE *)(*(_QWORD *)(a3 + 16) + 3LL);
          v33[115] = *(_BYTE *)(*(_QWORD *)(a3 + 16) + 4LL);
          v33[114] = *(_BYTE *)(*(_QWORD *)(a3 + 16) + 5LL);
          v33[113] = *(_BYTE *)(*(_QWORD *)(a3 + 16) + 6LL);
          v33[112] = *(_BYTE *)(*(_QWORD *)(a3 + 16) + 7LL);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: current replay counter: %llu in user space",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "__wlan_hdd_cfg80211_set_rekey_data",
            *((_QWORD *)v33 + 14));
          qdf_mem_copy((void *)(v34 + 37), *(const void **)a3, *(unsigned __int8 *)(a3 + 28));
          *(_DWORD *)(v34 + 104) = *(unsigned __int8 *)(a3 + 28);
          qdf_mem_copy((void *)(v34 + 4), *(const void **)(a3 + 8), *(unsigned __int8 *)(a3 + 29));
          *(_BYTE *)(v34 + 36) = *(_BYTE *)(a3 + 29);
          *(_BYTE *)(v34 + 126) = hdd_is_fils_connection(v14, a2 + 2688) & 1;
          vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a2 + 55512), 86, "__wlan_hdd_cfg80211_set_rekey_data");
          if ( vdev_by_user )
          {
            v36 = vdev_by_user;
            v37 = ucfg_pmo_cache_gtk_offload_req(vdev_by_user, v34);
            _hdd_objmgr_put_vdev_by_user(v36, 86, "__wlan_hdd_cfg80211_set_rekey_data");
            if ( v37 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Failed to cache GTK Offload",
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                "__wlan_hdd_cfg80211_set_rekey_data");
              v32 = qdf_status_to_os_return(v37);
            }
            else
            {
              v32 = 0;
            }
          }
          else
          {
            v32 = -22;
          }
          _qdf_mem_free(v34);
        }
        else
        {
          v32 = -12;
        }
      }
    }
    qdf_trace_msg(0x33u, 8u, "%s: exit", v24, v25, v26, v27, v28, v29, v30, v31, "__wlan_hdd_cfg80211_set_rekey_data");
    _osif_vdev_sync_op_stop(v46[0], "wlan_hdd_cfg80211_set_rekey_data");
    result = v32;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
