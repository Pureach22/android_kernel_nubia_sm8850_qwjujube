__int64 __fastcall ucfg_dp_traffic_end_indication_update_dscp(__int64 a1, __int64 a2, _BYTE *a3)
{
  __int64 result; // x0
  __int64 v5; // x19
  __int64 comp_private_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8

  result = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 97);
  if ( result )
  {
    v5 = result;
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(result, 0x2Eu);
    if ( comp_private_obj )
    {
      v15 = *(_QWORD *)(comp_private_obj + 32);
      if ( *(_BYTE *)(v15 + 3656) == 1 && *a3 == *(_BYTE *)(v15 + 3658) )
      {
        v15 = *(unsigned __int8 *)(v15 + 3657);
        *a3 = v15;
      }
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Unable to get DP link",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "ucfg_dp_traffic_end_indication_update_dscp");
    }
    return wlan_objmgr_vdev_release_ref(v5, 0x61u, (unsigned int *)v15, v7, v8, v9, v10, v11, v12, v13, v14);
  }
  return result;
}
