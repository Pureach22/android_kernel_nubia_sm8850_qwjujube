void *__fastcall scm_reset_scan_chan_info(__int64 a1, unsigned __int8 a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 v13; // x0

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( !comp_private_obj )
    return (void *)qdf_trace_msg(
                     0x15u,
                     2u,
                     "%s: %s:%u, Failed to get scan object",
                     v4,
                     v5,
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     "wlan_psoc_get_scan_obj_fl",
                     "scm_reset_scan_chan_info",
                     1955);
  v12 = comp_private_obj;
  v13 = qdf_trace_msg(
          0x15u,
          8u,
          "%s: pdev %d, Reset all channel info",
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          "scm_reset_scan_chan_info",
          a2);
  if ( !a2 )
    return qdf_mem_set((void *)(v12 + 17524), 0x334u, 0);
  __break(0x5512u);
  return (void *)scm_db_init(v13);
}
