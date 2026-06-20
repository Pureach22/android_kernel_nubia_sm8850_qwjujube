__int64 __fastcall wlan_mgmt_rx_srng_pdev_destroy_notification(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x21
  __int64 comp_private_obj; // x0
  __int64 v12; // x0
  __int64 v13; // x20
  __int64 i; // x21
  __int64 v15; // x8
  __int64 v16; // x0
  const char *v17; // x2
  unsigned int v18; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w19

  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 )
  {
    v17 = "%s: psoc is NULL";
    goto LABEL_15;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 0x35u);
  if ( !comp_private_obj )
  {
    v17 = "%s: psoc priv is NULL";
    goto LABEL_15;
  }
  if ( *(_BYTE *)(comp_private_obj + 8) == 1 )
  {
    v12 = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x35u);
    if ( v12 )
    {
      v13 = v12;
      tgt_mgmt_rx_srng_unregister_ev_handler(v9);
      for ( i = 0; i != 3072; i += 24 )
      {
        v15 = *(_QWORD *)(v13 + 80) + i;
        if ( *(_BYTE *)(v15 + 17) == 1 )
        {
          _qdf_nbuf_unmap_single(*(_QWORD *)(v13 + 16), *(_QWORD *)v15, 2);
          v16 = *(_QWORD *)(*(_QWORD *)(v13 + 80) + i);
          if ( v16 )
            _qdf_nbuf_free(v16);
        }
      }
      _qdf_mem_free_consistent(*(_QWORD *)(v13 + 16), *(_QWORD *)(*(_QWORD *)(v13 + 16) + 40LL), *(_DWORD *)(v13 + 64));
      _qdf_mem_free(*(_QWORD *)(v13 + 80));
      v18 = wlan_objmgr_pdev_component_obj_detach(a1, 0x35u, v13);
      if ( v18 )
      {
        v27 = v18;
        qdf_trace_msg(
          0xA5u,
          2u,
          "%s: Failed to detach mgmt rx srng pdev_priv",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "wlan_mgmt_rx_srng_pdev_destroy_notification");
        return v27;
      }
      _qdf_mem_free(v13);
      return 0;
    }
    v17 = "%s: pdev priv is NULL";
LABEL_15:
    qdf_trace_msg(0xA5u, 2u, v17, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mgmt_rx_srng_pdev_destroy_notification");
    return 16;
  }
  return 0;
}
