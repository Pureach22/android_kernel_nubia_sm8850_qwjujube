__int64 __fastcall mlme_peer_object_destroyed_notification(
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
  __int64 comp_private_obj; // x0
  __int64 v11; // x19
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  const char *v23; // x2

  if ( !a1 )
  {
    v23 = "%s:  peer is NULL";
LABEL_10:
    qdf_trace_msg(0x1Fu, 2u, v23, a2, a3, a4, a5, a6, a7, a8, a9, "mlme_peer_object_destroyed_notification");
    return 16;
  }
  comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(a1, 0);
  if ( !comp_private_obj )
  {
    v23 = "%s:  peer MLME component object is NULL";
    goto LABEL_10;
  }
  v11 = comp_private_obj;
  v12 = wlan_objmgr_peer_component_obj_detach(a1, 0, comp_private_obj);
  if ( v12 )
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: unable to detach peer_priv obj to peer obj",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlme_peer_object_destroyed_notification");
  v21 = *(_QWORD *)(v11 + 64);
  if ( v21 )
  {
    _qdf_mem_free(v21);
    *(_QWORD *)(v11 + 64) = 0;
    *(_DWORD *)(v11 + 56) = 0;
  }
  _qdf_mem_free(v11);
  return v12;
}
