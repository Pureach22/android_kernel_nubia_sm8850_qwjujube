__int64 __fastcall ucfg_coex_send_dbam_config(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 comp_private_obj; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v27; // x2

  if ( a1 )
  {
    v12 = *(_QWORD *)(a1 + 216);
    if ( v12 && (v13 = *(_QWORD *)(v12 + 80)) != 0 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v13, 0x21u);
      if ( comp_private_obj )
      {
        *(_QWORD *)(comp_private_obj + 16) = a3;
        *(_QWORD *)(comp_private_obj + 24) = a4;
        qdf_trace_msg(
          0x70u,
          8u,
          "%s: send dbam config mode %d for vdev_id %d",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "ucfg_coex_send_dbam_config",
          a2[1],
          *a2);
        return wlan_dbam_config_send();
      }
      qdf_trace_msg(
        0x70u,
        2u,
        "%s: %s:%u, Failed to get coex psoc object",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "wlan_psoc_get_coex_obj_fl",
        "ucfg_coex_send_dbam_config",
        111);
      v27 = "%s: failed to get coex_obj";
    }
    else
    {
      v27 = "%s: psoc is null";
    }
  }
  else
  {
    v27 = "%s: Null vdev";
  }
  qdf_trace_msg(0x70u, 2u, v27, a5, a6, a7, a8, a9, a10, a11, a12, "ucfg_coex_send_dbam_config");
  return 4;
}
