__int64 __fastcall tgt_mgmt_txrx_get_free_desc_pool_count(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 1);
  if ( comp_private_obj )
    return *(unsigned int *)(comp_private_obj + 24);
  qdf_trace_msg(
    0x4Bu,
    2u,
    "%s: Mgmt txrx context empty for pdev %pK",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "tgt_mgmt_txrx_get_free_desc_pool_count",
    a1);
  return 0xFFFFFFFFLL;
}
