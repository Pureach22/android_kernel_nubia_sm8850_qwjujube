__int64 __fastcall tgt_mgmt_txrx_get_peer_from_desc_id(__int64 a1, unsigned int a2)
{
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 1);
  if ( comp_private_obj )
  {
    v13 = *(_QWORD *)(comp_private_obj + 32) + 72LL * a2;
    if ( v13 && (*(_BYTE *)(v13 + 65) & 1) != 0 )
      return *(_QWORD *)(v13 + 48);
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: Mgmt descriptor unavailable for id %d pdev %pK",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "tgt_mgmt_txrx_get_peer_from_desc_id",
      a2,
      a1);
  }
  else
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: Mgmt txrx context empty for pdev %pK",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "tgt_mgmt_txrx_get_peer_from_desc_id",
      a1);
  }
  return 0;
}
