__int64 __fastcall policy_mgr_get_updated_scan_and_fw_mode_config(
        __int64 a1,
        unsigned int *a2,
        unsigned int *a3,
        int a4,
        char a5)
{
  __int64 context; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int v19; // w8
  unsigned int *v20; // x9
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "policy_mgr_get_updated_scan_and_fw_mode_config");
    return 16;
  }
  *a2 = *(_DWORD *)(context + 1512);
  *a3 = *(_DWORD *)(context + 1516);
  if ( a4 > 3 )
  {
    if ( a4 == 4 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: dual_mac_disable_ini:%d async off",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "policy_mgr_get_updated_scan_and_fw_mode_config",
        4);
      v19 = -268435457;
    }
    else
    {
      if ( a4 != 5 )
        goto LABEL_15;
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: dual_mac_disable_ini:%d ",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "policy_mgr_get_updated_scan_and_fw_mode_config",
        5);
      v19 = 0x7FFFFFFF;
    }
    v20 = a2;
    goto LABEL_14;
  }
  if ( a4 == 2 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: dual_mac_disable_ini:%d dbs_cxn off",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "policy_mgr_get_updated_scan_and_fw_mode_config",
      2);
    goto LABEL_11;
  }
  if ( a4 == 3 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: dual_mac_disable_ini:%d async/dbs off",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "policy_mgr_get_updated_scan_and_fw_mode_config",
      3);
    *a2 &= ~0x10000000u;
LABEL_11:
    v19 = -536870913;
    v20 = a3;
LABEL_14:
    *v20 &= v19;
  }
LABEL_15:
  *a3 = *a3 & 0xE7FFFFFF | (__rbit32(a5 & 3) >> 3);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: *scan_config:%x ",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "policy_mgr_get_updated_scan_and_fw_mode_config",
    *a2);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: *fw_mode_config:%x ",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "policy_mgr_get_updated_scan_and_fw_mode_config",
    *a3);
  return 0;
}
