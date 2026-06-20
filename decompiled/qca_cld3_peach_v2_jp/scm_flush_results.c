__int64 __fastcall scm_flush_results(
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
  __int64 v10; // x19
  unsigned int v11; // w20
  const char *v12; // x2
  __int64 comp_private_obj; // x0
  __int64 v16; // x8

  if ( a1 )
  {
    v10 = *(_QWORD *)(a1 + 80);
    if ( v10 )
    {
      v11 = *(unsigned __int8 *)(a1 + 40);
      if ( v11 < 2 )
      {
        comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 3u);
        if ( comp_private_obj )
        {
          v16 = comp_private_obj + 1560LL * v11;
          if ( v16 != -32 )
          {
            scm_flush_scan_entries(v10, v16 + 32, a2, *(unsigned __int8 *)(a1 + 40));
            return 0;
          }
        }
        else
        {
          qdf_trace_msg(
            0x15u,
            2u,
            "%s: %s:%u, Failed to get scan object",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            "wlan_psoc_get_scan_obj_fl",
            "wlan_pdevid_get_scan_db",
            57);
        }
      }
      else
      {
        qdf_trace_msg(
          0x15u,
          2u,
          "%s: invalid pdev_id %d",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "wlan_pdevid_get_scan_db",
          *(unsigned __int8 *)(a1 + 40));
      }
      v12 = "%s: scan_db is NULL";
    }
    else
    {
      v12 = "%s: psoc is NULL";
    }
  }
  else
  {
    v12 = "%s: pdev is NULL";
  }
  qdf_trace_msg(0x15u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "scm_flush_results");
  return 4;
}
