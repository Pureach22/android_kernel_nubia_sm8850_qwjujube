__int64 __fastcall p2p_set_sta_vdev_for_p2p_dev_operations(__int64 a1, char a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w20
  __int64 v13; // x19
  __int64 result; // x0

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
  if ( !comp_private_obj )
    return qdf_trace_msg(
             0x4Eu,
             2u,
             "%s: p2p soc context is NULL",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "p2p_set_sta_vdev_for_p2p_dev_operations");
  v12 = a2 & 1;
  v13 = comp_private_obj;
  result = qdf_trace_msg(
             0x4Eu,
             8u,
             "%s: sta_vdev_for_p2p_dev_operations :%d",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "p2p_set_sta_vdev_for_p2p_dev_operations",
             v12);
  *(_BYTE *)(v13 + 288) = v12;
  return result;
}
