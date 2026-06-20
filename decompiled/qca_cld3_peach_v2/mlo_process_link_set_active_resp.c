__int64 __fastcall mlo_process_link_set_active_resp(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  wlan_objmgr_iterate_obj_list(a1, 2, mlo_link_set_resp_link_recfg_handler, a2, 1, 0x5Au);
  if ( (*(_BYTE *)(a2 + 4) & 1) == 0 )
  {
    wlan_objmgr_iterate_obj_list(a1, 2, mlo_link_set_active_resp_vdev_handler, a2, 1, 0x5Au);
    if ( (*(_BYTE *)(a2 + 4) & 1) == 0 )
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: link set resp evt not handled",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "mlo_process_link_set_active_resp");
  }
  return 0;
}
