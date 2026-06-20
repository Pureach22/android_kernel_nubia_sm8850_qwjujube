__int64 __fastcall tdls_teardown_connections(__int64 *a1)
{
  __int64 vdev; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 v22; // x1
  unsigned int *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  vdev = tdls_get_vdev(*a1, 16);
  if ( vdev )
  {
    v11 = vdev;
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(vdev, 0xAu);
    if ( comp_private_obj )
    {
      v21 = comp_private_obj;
      qdf_trace_msg(
        0,
        8u,
        "%s: tdls teardown connections",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "tdls_teardown_connections");
      *(_DWORD *)(v11 + 60) &= ~0x10u;
      tdls_disable_offchan_and_teardown_links(v11);
      tdls_timers_stop(v21);
      qdf_event_set(v21 + 1000, v22);
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: vdev priv is NULL", v13, v14, v15, v16, v17, v18, v19, v20, "tdls_teardown_connections");
    }
    wlan_objmgr_vdev_release_ref(v11, 0x10u, v23, v24, v25, v26, v27, v28, v29, v30, v31);
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: Unable get the vdev", v3, v4, v5, v6, v7, v8, v9, v10, "tdls_teardown_connections");
  }
  wlan_objmgr_psoc_release_ref(*a1, 0x10u, v32, v33, v34, v35, v36, v37, v38, v39);
  return _qdf_mem_free((__int64)a1);
}
