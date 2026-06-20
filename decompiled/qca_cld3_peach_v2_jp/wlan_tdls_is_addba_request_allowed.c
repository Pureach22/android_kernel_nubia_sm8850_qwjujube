__int64 __fastcall wlan_tdls_is_addba_request_allowed(
        __int64 a1,
        unsigned __int8 *a2,
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *peer; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0, 2u, "%s: NULL vdev", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_tdls_vdev_obj");
    goto LABEL_8;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0xAu);
  if ( !comp_private_obj )
  {
LABEL_8:
    qdf_trace_msg(
      0,
      2u,
      "%s: vdev_obj: %pK is null",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_tdls_is_addba_request_allowed",
      0);
    return 0;
  }
  peer = tdls_find_peer(comp_private_obj, a2);
  if ( peer )
  {
    if ( *((_BYTE *)peer + 30) == 1 && *((_DWORD *)peer + 9) == 4 )
      return 1;
  }
  else
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: tdls peer is null",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wlan_tdls_is_addba_request_allowed");
  }
  return 0;
}
