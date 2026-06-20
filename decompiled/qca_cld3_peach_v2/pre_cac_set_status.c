__int64 __fastcall pre_cac_set_status(__int64 a1, char a2)
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
  _BYTE *v13; // x8

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Du);
  if ( comp_private_obj )
  {
    v13 = (_BYTE *)comp_private_obj;
    *v13 = a2 & 1;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x98u,
      2u,
      "%s:%u: vdev id: %d, vdev_priv is NULL",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "pre_cac_set_status",
      393,
      *(unsigned __int8 *)(a1 + 168));
    return 4;
  }
}
