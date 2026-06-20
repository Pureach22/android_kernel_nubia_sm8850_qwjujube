__int64 __fastcall cm_roam_send_disable_config(__int64 a1, unsigned int a2, char a3)
{
  unsigned int v6; // w19
  _BYTE *v7; // x0
  __int64 v8; // x20
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7

  v6 = 2;
  v7 = (_BYTE *)_qdf_mem_malloc(2u, "cm_roam_send_disable_config", 1218);
  if ( v7 )
  {
    v8 = (__int64)v7;
    *v7 = a2;
    v7[1] = a3;
    v6 = wlan_cm_tgt_send_roam_disable_config(a1, a2, v7);
    if ( v6 )
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: fail to send roam disable config",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "cm_roam_send_disable_config");
    _qdf_mem_free(v8);
  }
  return v6;
}
