__int64 __fastcall p2p_psoc_priv_set_sta_vdev_id(__int64 a1, unsigned __int8 a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
  if ( !result )
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
             "p2p_psoc_priv_set_sta_vdev_id");
  *(_DWORD *)(result + 292) = a2;
  return result;
}
