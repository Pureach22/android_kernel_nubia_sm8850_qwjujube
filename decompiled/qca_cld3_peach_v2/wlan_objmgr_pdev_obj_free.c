__int64 __fastcall wlan_objmgr_pdev_obj_free(
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
  unsigned int v10; // w20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( a1 )
  {
    v10 = *(unsigned __int8 *)(a1 + 40);
    if ( (unsigned int)wlan_objmgr_psoc_pdev_detach(*(_QWORD *)(a1 + 80), a1) == 16 )
    {
      qdf_trace_msg(
        0x57u,
        2u,
        "%s: PSOC PDEV detach failed: pdev-id: %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "wlan_objmgr_pdev_obj_free",
        v10);
      return 16;
    }
    else
    {
      wlan_delayed_peer_obj_free_deinit(a1);
      _qdf_mem_free(a1);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x57u, 2u, "%s: pdev obj is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_objmgr_pdev_obj_free");
    return 16;
  }
}
