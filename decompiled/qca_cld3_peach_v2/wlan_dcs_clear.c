__int64 __fastcall wlan_dcs_clear(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  const char *v13; // x2
  __int64 v14; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x24u);
    if ( comp_private_obj )
    {
      if ( a2 < 3 )
      {
        v14 = comp_private_obj + 384LL * a2;
        if ( v14 )
        {
          timer_delete((timer_t)(v14 + 280));
          qdf_mem_set((void *)(v14 + 60), 0x74u, 0);
          qdf_mem_set((void *)(v14 + 184), 0x50u, 0);
          *(_QWORD *)(v14 + 264) = 0;
          *(_BYTE *)(v14 + 272) = 0;
          return wlan_dcs_set_algorithm_process(a1, a2, 0, v15, v16, v17, v18, v19, v20, v21, v22);
        }
      }
      else
      {
        qdf_trace_msg(
          0x74u,
          2u,
          "%s: invalid pdev_id: %u",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "wlan_dcs_get_pdev_private_obj",
          a2);
      }
    }
    else
    {
      qdf_trace_msg(
        0x74u,
        2u,
        "%s: dcs psoc object is null",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_dcs_get_pdev_private_obj");
    }
    v13 = "%s: dcs pdev private object is null";
  }
  else
  {
    v13 = "%s: psoc is null";
  }
  return qdf_trace_msg(0x74u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_dcs_clear");
}
