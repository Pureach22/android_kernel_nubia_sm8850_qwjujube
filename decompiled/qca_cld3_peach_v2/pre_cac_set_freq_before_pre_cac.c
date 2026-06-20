__int64 __fastcall pre_cac_set_freq_before_pre_cac(__int64 a1, int a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  result = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Du);
  if ( !result )
    return qdf_trace_msg(
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
             "pre_cac_set_freq_before_pre_cac",
             72,
             *(unsigned __int8 *)(a1 + 168));
  *(_DWORD *)(result + 4) = a2;
  return result;
}
