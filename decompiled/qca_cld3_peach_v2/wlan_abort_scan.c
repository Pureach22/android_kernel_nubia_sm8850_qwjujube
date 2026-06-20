__int64 __fastcall wlan_abort_scan(__int64 a1, int a2, unsigned int a3, unsigned int a4, char a5)
{
  __int64 v10; // x0
  __int64 v11; // x25
  __int64 v12; // x19
  __int64 vdev_by_id_from_pdev; // x21
  int v14; // w8
  int v15; // w4
  unsigned int v17; // w19

  v10 = _qdf_mem_malloc(32, "wlan_abort_scan", 2329);
  if ( !v10 )
    return 2;
  v11 = *(_QWORD *)(a1 + 24);
  v12 = v10;
  if ( !v11 )
  {
    qdf_trace_msg(72, 2, "%s: Failed to retrieve osif context", "wlan_abort_scan");
    _qdf_mem_free(v12);
    return 16;
  }
  if ( a3 != -1 )
  {
    vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a3, 6);
    if ( vdev_by_id_from_pdev )
      goto LABEL_5;
LABEL_10:
    _qdf_mem_free(v12);
    return 4;
  }
  vdev_by_id_from_pdev = wlan_objmgr_pdev_get_first_vdev(a1, 6);
  if ( !vdev_by_id_from_pdev )
    goto LABEL_10;
LABEL_5:
  v14 = *(unsigned __int16 *)(*(_QWORD *)(v11 + 16) + 88LL);
  *(_QWORD *)v12 = vdev_by_id_from_pdev;
  *(_DWORD *)(v12 + 24) = a3;
  *(_DWORD *)(v12 + 28) = a2;
  *(_DWORD *)(v12 + 12) = v14;
  *(_DWORD *)(v12 + 16) = a4;
  if ( a4 > 0xFFFFFFFD )
  {
    if ( a4 == -2 )
    {
      v15 = 4;
    }
    else if ( a3 == -1 )
    {
      v15 = 3;
    }
    else
    {
      v15 = 2;
    }
  }
  else
  {
    v15 = 1;
  }
  *(_DWORD *)(v12 + 20) = v15;
  qdf_trace_msg(72, 8, "%s: Type %d Vdev %d pdev %d scan id %d sync %d", "wlan_abort_scan", v15, a3, a2, a4, a5 & 1);
  if ( (a5 & 1) != 0 )
  {
    v17 = ucfg_scan_cancel_sync(v12);
    if ( !v17 )
      goto LABEL_21;
    goto LABEL_20;
  }
  v17 = wlan_scan_cancel(v12);
  if ( v17 )
LABEL_20:
    qdf_trace_msg(72, 2, "%s: Cancel scan request failed", "wlan_abort_scan");
LABEL_21:
  wlan_objmgr_vdev_release_ref(vdev_by_id_from_pdev, 6);
  return v17;
}
