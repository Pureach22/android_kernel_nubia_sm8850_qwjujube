__int64 __fastcall wlan_interop_issues_ap_info_cbk(__int64 a1)
{
  __int64 v1; // x20
  __int64 pdev_by_id; // x0
  void (__fastcall *v4)(_QWORD); // x8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x0
  __int64 comp_private_obj; // x0
  __int64 v15; // x0
  unsigned int v16; // w21

  v1 = *(_QWORD *)(a1 + 8);
  pdev_by_id = wlan_objmgr_get_pdev_by_id(*(_QWORD *)(v1 + 8), *(_DWORD *)(v1 + 16), 0x33u);
  *(_QWORD *)v1 = pdev_by_id;
  if ( pdev_by_id )
  {
    v13 = *(_QWORD *)(v1 + 8);
    if ( v13 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v13, 0x1Fu);
      if ( comp_private_obj )
      {
        v4 = *(void (__fastcall **)(_QWORD))(comp_private_obj + 24);
        if ( v4 )
        {
          v15 = *(_QWORD *)(a1 + 8);
          if ( *((_DWORD *)v4 - 1) != -686054009 )
            __break(0x8228u);
          v4(v15);
        }
      }
      else
      {
        qdf_trace_msg(
          0x6Cu,
          2u,
          "%s: psoc private object is null",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "interop_issues_ap_psoc_get_cbs");
      }
    }
    wlan_objmgr_pdev_release_ref(*(_QWORD *)v1, 0x33u, (unsigned int *)v4, v5, v6, v7, v8, v9, v10, v11, v12);
    v16 = 0;
  }
  else
  {
    qdf_trace_msg(0x6Cu, 2u, "%s: pdev is null.", v5, v6, v7, v8, v9, v10, v11, v12, "wlan_interop_issues_ap_info_cbk");
    v16 = 16;
  }
  _qdf_mem_free(v1);
  *(_QWORD *)(a1 + 8) = 0;
  return v16;
}
