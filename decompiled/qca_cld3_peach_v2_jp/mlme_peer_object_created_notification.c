__int64 __fastcall mlme_peer_object_created_notification(
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
  __int64 v10; // x0
  __int64 v11; // x19
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20

  if ( a1 )
  {
    v10 = _qdf_mem_malloc(0x50u, "mlme_peer_object_created_notification", 1027);
    if ( v10 )
    {
      v11 = v10;
      result = wlan_objmgr_peer_component_obj_attach(a1, 0, v10, 0);
      if ( (_DWORD)result )
      {
        v21 = result;
        qdf_trace_msg(
          0x1Fu,
          2u,
          "%s: unable to attach peer_priv obj to peer obj",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "mlme_peer_object_created_notification");
        _qdf_mem_free(v11);
        return v21;
      }
      else
      {
        *(_DWORD *)(v11 + 72) = 8;
      }
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s:  peer is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "mlme_peer_object_created_notification");
    return 16;
  }
  return result;
}
