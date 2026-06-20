void __fastcall nan_delete_objmgr_pasn_peer(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 comp_private_obj; // x0
  unsigned __int8 v21; // w8
  const char *v22; // x2
  const char *v23; // x3

  if ( !a10 )
  {
    v22 = "%s: Peer is NULL";
LABEL_12:
    v23 = "nan_delete_objmgr_pasn_peer";
    goto LABEL_13;
  }
  if ( *(_DWORD *)(a10 + 68) != 14 )
    return;
  if ( !a11 )
  {
    v22 = "%s: VDEV is NULL";
    goto LABEL_12;
  }
  if ( *(unsigned __int8 *)(a11 + 104) != *(unsigned __int8 *)(*(_QWORD *)(a10 + 88) + 104LL) )
    return;
  if ( (unsigned int)wlan_objmgr_peer_obj_delete(a10, a1, a2, a3, a4, a5, a6, a7, a8) )
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: Failed to delete peer",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "nan_delete_objmgr_pasn_peer");
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a11, 0xFu);
  if ( comp_private_obj )
  {
    if ( *(_BYTE *)(comp_private_obj + 105) )
    {
      v21 = *(_BYTE *)(comp_private_obj + 105) - 1;
      *(_BYTE *)(comp_private_obj + 105) = v21;
      qdf_trace_msg(
        0x53u,
        8u,
        "%s: Pasn peer count:%d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "nan_update_pasn_peer_count",
        v21);
      return;
    }
    v22 = "%s: No PASN peers present";
  }
  else
  {
    v22 = "%s: NAN vdev priv obj is null";
  }
  v23 = "nan_update_pasn_peer_count";
LABEL_13:
  qdf_trace_msg(0x53u, 2u, v22, a1, a2, a3, a4, a5, a6, a7, a8, v23);
}
