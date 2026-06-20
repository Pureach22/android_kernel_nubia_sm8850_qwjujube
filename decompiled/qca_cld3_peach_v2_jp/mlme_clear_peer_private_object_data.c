__int64 __fastcall mlme_clear_peer_private_object_data(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x8

  comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(a1, 0);
  if ( comp_private_obj )
  {
    v10 = comp_private_obj;
    *(_BYTE *)v10 = 0;
    *(_QWORD *)(v10 + 8) = 0;
    *(_DWORD *)(v10 + 16) = 0;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: peer MLME component object is NULL",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "mlme_clear_peer_private_object_data");
    return 16;
  }
}
