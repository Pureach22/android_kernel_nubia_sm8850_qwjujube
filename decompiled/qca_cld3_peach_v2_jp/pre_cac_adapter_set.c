__int64 __fastcall pre_cac_adapter_set(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( !a1 )
    return qdf_trace_msg(0x98u, 8u, "%s: vdev is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "pre_cac_adapter_set");
  result = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Du);
  if ( !result )
    return qdf_trace_msg(
             0x98u,
             2u,
             "%s:%u: vdev id: %d, vdev_priv is NULL",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "pre_cac_adapter_set",
             100,
             *(unsigned __int8 *)(a1 + 104));
  *(_BYTE *)(result + 2) = a2 & 1;
  return result;
}
