__int64 __fastcall pre_cac_vdev_get_priv_fl(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  result = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Du);
  if ( !result )
  {
    qdf_trace_msg(
      0x98u,
      2u,
      "%s:%u: vdev id: %d, vdev_priv is NULL",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      a2,
      a3,
      *(unsigned __int8 *)(a1 + 104));
    return 0;
  }
  return result;
}
