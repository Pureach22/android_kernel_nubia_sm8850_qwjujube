__int64 __fastcall target_if_cm_roam_bss_load_config(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x7
  unsigned int v21; // w8
  int v22; // w10
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  if ( (wmi_service_enabled(a1, 0xACu, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
  {
    v20 = a2[5];
    v21 = a2[6];
  }
  else
  {
    v22 = a2[6] + 96;
    v20 = (unsigned __int8)(*((_BYTE *)a2 + 20) + 96);
    a2[4] = (unsigned __int8)(a2[4] + 96);
    a2[5] = v20;
    v21 = (unsigned __int8)v22;
    a2[6] = (unsigned __int8)v22;
  }
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: RSO_CFG: bss load trig params vdev_id:%u threshold:%u sample_time:%u 5Ghz RSSI threshold:%d 2.4G rssi threshold:%d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "target_if_cm_roam_bss_load_config",
    *a2,
    a2[1],
    a2[2],
    v20,
    v21);
  result = wmi_unified_send_bss_load_config(a1, a2);
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x49u,
             2u,
             "%s: failed to send bss load trigger config command",
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             "target_if_cm_roam_bss_load_config");
  return result;
}
