__int64 __fastcall wlan_hdd_cm_issue_disconnect(__int64 a1, int a2, char a3)
{
  __int64 v4; // x21
  __int64 vdev_by_user; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w0
  unsigned int v26; // w20

  v4 = *(_QWORD *)a1;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 88, "wlan_hdd_cm_issue_disconnect");
  if ( vdev_by_user )
  {
    v16 = vdev_by_user;
    mlme_set_is_mscs_req_sent(*(_QWORD *)(a1 + 32), 0, v8, v9, v10, v11, v12, v13, v14, v15);
    *(_DWORD *)(a1 + 4408) = 0;
    hdd_conn_set_authenticated(a1, 0, v17, v18, v19, v20, v21, v22, v23, v24);
    wlan_hdd_netif_queue_control(v4, 4, 1);
    qdf_rtpm_sync_resume();
    wlan_rec_debug_log((char *)&off_0 + 1, *(_BYTE *)(a1 + 8), 0x16u, 0, (const void *)(a1 + 300), 0, 0, a2);
    if ( (a3 & 1) != 0 )
      v25 = osif_cm_disconnect_sync(v16, a2);
    else
      v25 = osif_cm_disconnect(*(_QWORD *)(v4 + 32), v16, a2);
    v26 = v25;
    _hdd_objmgr_put_vdev_by_user(v16, 88, "wlan_hdd_cm_issue_disconnect");
  }
  else
  {
    return 4;
  }
  return v26;
}
