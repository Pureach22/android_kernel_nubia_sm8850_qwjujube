__int64 __fastcall wlan_drop_mgmt_frame_on_link_removal(__int64 a1)
{
  unsigned int v2; // w19
  __int64 ap_link_by_link_id; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8

  if ( !a1 )
    return 0;
  if ( (mlo_is_mld_sta(a1) & 1) == 0 || (mlo_is_mld_sta(a1) & 1) == 0 )
    goto LABEL_8;
  v2 = *(unsigned __int8 *)(a1 + 93);
  ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(a1 + 1360), *(unsigned __int8 *)(a1 + 93));
  if ( !ap_link_by_link_id )
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: link info null, id %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_get_vdev_link_removed_flag",
      v2);
LABEL_8:
    LOBYTE(v12) = 0;
    return v12 & 1;
  }
  v12 = *(_QWORD *)(ap_link_by_link_id + 16);
  return v12 & 1;
}
