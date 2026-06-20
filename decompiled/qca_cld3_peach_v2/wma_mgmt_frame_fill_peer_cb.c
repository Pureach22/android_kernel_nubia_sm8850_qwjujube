__int64 __fastcall wma_mgmt_frame_fill_peer_cb(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 pdev_by_id; // x0
  unsigned int *v15; // x8
  __int64 v16; // x8
  __int64 v17; // x1
  __int64 v18; // x19
  const char *v19; // x2

  v10 = *(_QWORD *)(a1 + 96);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 216)) == 0 || (v12 = *(_QWORD *)(v11 + 80)) == 0 )
  {
    v19 = "%s: Psoc handle NULL";
LABEL_9:
    qdf_trace_msg(0x36u, 2u, v19, a3, a4, a5, a6, a7, a8, a9, a10, "wma_mgmt_frame_fill_peer_cb");
    return 4;
  }
  pdev_by_id = wlan_objmgr_get_pdev_by_id(v12, *(_BYTE *)(a1 + 54), 8u);
  if ( !pdev_by_id )
  {
    v19 = "%s: Pdev handle NULL";
    goto LABEL_9;
  }
  if ( a2 )
  {
    v16 = *(_QWORD *)(pdev_by_id + 80);
    v17 = a2;
    v18 = pdev_by_id;
    if ( v16 )
      _qdf_nbuf_unmap_single(*(_QWORD *)(v16 + 2120), v17, 1);
    else
      qdf_trace_msg(0x36u, 2u, "%s: Psoc handle NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wma_mgmt_nbuf_unmap_cb");
    pdev_by_id = v18;
  }
  wlan_objmgr_pdev_release_ref(pdev_by_id, 8u, v15, a3, a4, a5, a6, a7, a8, a9, a10);
  return 0;
}
