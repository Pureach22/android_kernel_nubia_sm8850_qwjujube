__int64 __fastcall dp_ucfg_enable_link_monitoring(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        int a11)
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
  __int64 v21; // x8

  if ( a10 )
  {
    result = wlan_objmgr_vdev_get_comp_private_obj(a10, 0x2Eu);
    if ( result )
    {
      v21 = *(_QWORD *)(result + 32);
      *(_DWORD *)(v21 + 12) = a11;
      *(_BYTE *)(v21 + 8) = 1;
      return result;
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a1, a2, a3, a4, a5, a6, a7, a8, "dp_get_vdev_priv_obj");
  }
  return qdf_trace_msg(
           0x45u,
           2u,
           "%s: DP link not found",
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           v20,
           "dp_ucfg_enable_link_monitoring");
}
