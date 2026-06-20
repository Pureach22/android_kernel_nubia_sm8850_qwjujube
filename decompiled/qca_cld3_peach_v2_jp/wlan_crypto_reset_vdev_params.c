__int64 __fastcall wlan_crypto_reset_vdev_params(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  qdf_trace_msg(
    0x1Cu,
    8u,
    "%s: reset params for vdev %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_crypto_reset_vdev_params",
    *(unsigned __int8 *)(a1 + 104));
  result = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( !result )
    return qdf_trace_msg(
             0x1Cu,
             2u,
             "%s: crypto_priv NULL",
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             "wlan_crypto_reset_vdev_params");
  *(_DWORD *)(result + 20) = 0;
  *(_WORD *)(result + 152) = 0;
  *(_QWORD *)result = 0;
  *(_QWORD *)(result + 8) = 0;
  return result;
}
