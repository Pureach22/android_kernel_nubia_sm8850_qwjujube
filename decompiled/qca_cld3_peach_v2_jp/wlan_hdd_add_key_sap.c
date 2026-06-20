__int64 __fastcall wlan_hdd_add_key_sap(__int64 a1, char a2, unsigned int a3, unsigned int a4)
{
  __int64 vdev_by_user; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x8
  __int64 v18; // x19
  __int64 v19; // x24
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w24
  unsigned int v31; // w0
  unsigned int v32; // w20

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "wlan_hdd_add_key_sap");
  if ( vdev_by_user )
  {
    v17 = *(_QWORD *)(vdev_by_user + 152);
    v18 = vdev_by_user;
    if ( v17 )
    {
      v19 = *(_QWORD *)(v17 + 80);
      if ( v19 )
      {
        if ( (policy_mgr_is_chan_switch_in_progress(*(_QWORD *)(v17 + 80)) & 1) != 0 )
        {
          v20 = policy_mgr_wait_chan_switch_complete_evt(v19);
          if ( v20 )
          {
            v29 = v20;
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Vdev %d wait for csa event failed!!",
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              "wlan_hdd_add_key_sap",
              *(unsigned __int8 *)(a1 + 8));
            _hdd_objmgr_put_vdev_by_user(v18, 6, "wlan_hdd_add_key_sap");
            return qdf_status_to_os_return(v29);
          }
        }
        if ( *(_DWORD *)(a1 + 80) == 1 )
        {
          v31 = wlan_cfg80211_crypto_add_key(v18, 0, (a2 & 1) == 0, a3, 1);
          if ( v31 )
          {
LABEL_14:
            v32 = v31;
            _hdd_objmgr_put_vdev_by_user(v18, 6, "wlan_hdd_add_key_sap");
            return v32;
          }
          wma_update_set_key(*(unsigned __int8 *)(a1 + 8), a2 & 1, a3, 0, a4);
        }
        v31 = 0;
        goto LABEL_14;
      }
    }
    qdf_trace_msg(0x33u, 2u, "%s: psoc is NULL", v9, v10, v11, v12, v13, v14, v15, v16, "wlan_hdd_add_key_sap");
    _hdd_objmgr_put_vdev_by_user(v18, 6, "wlan_hdd_add_key_sap");
  }
  return 4294967274LL;
}
