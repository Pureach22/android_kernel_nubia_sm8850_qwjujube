__int64 __fastcall cm_roam_send_disable_config(__int64 a1, unsigned int a2, char a3)
{
  unsigned int v6; // w21
  _BYTE *v7; // x0
  __int64 v8; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v6 = 2;
  v7 = (_BYTE *)_qdf_mem_malloc(2u, "cm_roam_send_disable_config", 1218);
  if ( v7 )
  {
    v8 = (__int64)v7;
    *v7 = a2;
    v7[1] = a3;
    if ( (wlan_vdev_mlme_get_is_mlo_link(a1, a2) & 1) != 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: MLO ROAM: skip RSO cmd for link vdev %d",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "cm_roam_send_disable_config",
        (unsigned __int8)a2);
      v6 = 16;
    }
    else
    {
      v6 = wlan_cm_tgt_send_roam_disable_config(a1, a2, v8);
      if ( v6 )
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: fail to send roam disable config",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "cm_roam_send_disable_config");
    }
    _qdf_mem_free(v8);
  }
  return v6;
}
