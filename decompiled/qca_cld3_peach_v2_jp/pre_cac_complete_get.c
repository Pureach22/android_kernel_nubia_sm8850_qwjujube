__int64 __fastcall pre_cac_complete_get(__int64 a1)
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
  char v11; // w8

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Du);
  if ( comp_private_obj )
  {
    v11 = *(_BYTE *)(comp_private_obj + 1);
  }
  else
  {
    qdf_trace_msg(
      0x98u,
      2u,
      "%s:%u: vdev id: %d, vdev_priv is NULL",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "pre_cac_complete_get",
      144,
      *(unsigned __int8 *)(a1 + 104));
    v11 = 0;
  }
  return v11 & 1;
}
