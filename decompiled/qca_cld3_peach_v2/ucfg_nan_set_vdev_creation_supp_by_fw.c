__int64 __fastcall ucfg_nan_set_vdev_creation_supp_by_fw(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int16 v20; // w9

  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a3, a4, a5, a6, a7, a8, a9, a10, "nan_get_psoc_priv_obj");
    return qdf_trace_msg(
             0x53u,
             2u,
             "%s: psoc_nan_obj is null",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "ucfg_nan_set_vdev_creation_supp_by_fw");
  }
  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !result )
    return qdf_trace_msg(
             0x53u,
             2u,
             "%s: psoc_nan_obj is null",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "ucfg_nan_set_vdev_creation_supp_by_fw");
  if ( (a2 & 1) != 0 )
    v20 = 32;
  else
    v20 = 0;
  *(_WORD *)(result + 232) = *(_WORD *)(result + 232) & 0xFFDF | v20;
  return result;
}
