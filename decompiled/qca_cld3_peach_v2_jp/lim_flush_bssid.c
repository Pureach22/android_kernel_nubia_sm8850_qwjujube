__int64 __fastcall lim_flush_bssid(__int64 result, unsigned __int8 *a2)
{
  __int64 v3; // x21
  __int64 v4; // x19
  __int64 pdev_by_id; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  int v15; // w22
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  if ( a2 )
  {
    v3 = result;
    result = _qdf_mem_malloc(0x2D0u, "lim_flush_bssid", 11273);
    if ( result )
    {
      v4 = result;
      *(_BYTE *)(result + 16) = 1;
      qdf_mem_copy((void *)(result + 70), a2, 6u);
      pdev_by_id = wlan_objmgr_get_pdev_by_id(*(_QWORD *)(v3 + 21552), 0, 7u);
      if ( pdev_by_id )
      {
        v14 = pdev_by_id;
        v15 = ucfg_scan_flush_results(pdev_by_id, v4, v6, v7, v8, v9, v10, v11, v12, v13);
        wlan_objmgr_pdev_release_ref(v14, 7u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
        if ( !v15 )
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Removed BSS entry:%02x:%02x:%02x:**:**:%02x from scan cache",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "lim_flush_bssid",
            *a2,
            a2[1],
            a2[2],
            a2[5]);
      }
      else
      {
        qdf_trace_msg(0x35u, 2u, "%s: pdev is NULL", v6, v7, v8, v9, v10, v11, v12, v13, "lim_flush_bssid");
      }
      return _qdf_mem_free(v4);
    }
  }
  return result;
}
