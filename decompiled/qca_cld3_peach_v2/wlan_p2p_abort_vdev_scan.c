void __fastcall wlan_p2p_abort_vdev_scan(__int64 a1, __int64 a2)
{
  __int64 v2; // x29
  __int64 v3; // x30
  __int64 v4; // x8
  __int64 v6; // x0
  __int64 comp_private_obj; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x20
  __int64 v17; // x0
  int v18; // w3
  __int64 v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // [xsp+8h] [xbp-18h]

  if ( *(_DWORD *)(a2 + 16) == 7 )
  {
    v45 = v3;
    v4 = *(_QWORD *)(a2 + 216);
    if ( v4 )
      v6 = *(_QWORD *)(v4 + 80);
    else
      v6 = 0;
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v6, 5u);
    if ( comp_private_obj )
    {
      v16 = comp_private_obj;
      v17 = _qdf_mem_malloc(0x20u, "wlan_p2p_abort_vdev_scan", 120);
      if ( v17 )
      {
        *(_QWORD *)v17 = a2;
        *(_DWORD *)(v17 + 12) = *(unsigned __int16 *)(v16 + 80);
        *(_DWORD *)(v17 + 16) = -1;
        v18 = *(unsigned __int8 *)(a2 + 168);
        v19 = v17;
        *(_DWORD *)(v17 + 20) = 2;
        *(_DWORD *)(v17 + 24) = v18;
        qdf_mtrace(78, 21, 2u, v18, -1);
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: abort scan, scan req id:%d, scan id:%d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "wlan_p2p_abort_vdev_scan",
          *(unsigned int *)(v19 + 12),
          *(unsigned int *)(v19 + 16),
          v2,
          v45);
        v36 = wlan_scan_cancel((__int64 *)v19, v28, v29, v30, v31, v32, v33, v34, v35);
        if ( v36 )
          qdf_trace_msg(
            0x4Eu,
            8u,
            "%s: abort scan failed: %d",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "wlan_p2p_abort_vdev_scan",
            v36);
      }
    }
    else
    {
      qdf_trace_msg(
        0x4Eu,
        2u,
        "%s: P2P soc object is NULL",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "wlan_p2p_abort_vdev_scan",
        v2,
        v45);
    }
  }
}
