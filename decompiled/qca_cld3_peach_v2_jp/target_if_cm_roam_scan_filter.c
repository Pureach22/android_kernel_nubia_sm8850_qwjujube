__int64 __fastcall target_if_cm_roam_scan_filter(
        __int64 a1,
        char a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w8

  if ( a3[12] >= 6u )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Invalid vdev id:%d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "target_if_cm_roam_scan_filter");
    return 16;
  }
  if ( a2 == 2 )
    goto LABEL_10;
  v11 = *a3;
  if ( (unsigned int)(v11 - 26) < 2 || v11 == 29 )
    goto LABEL_10;
  if ( v11 != 40 )
  {
    if ( a2 == 1 )
      goto LABEL_10;
LABEL_12:
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: Roam Filter need not be sent",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "target_if_cm_roam_scan_filter");
    return 0;
  }
  if ( a2 != 1 )
    goto LABEL_12;
  *((_DWORD *)a3 + 2) |= 0x18u;
LABEL_10:
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: RSO_CFG: vdev %d op_bitmap:0x%x num_rssi_rejection_ap:%d delta_rssi:%d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "target_if_cm_roam_scan_filter");
  return wmi_unified_roam_scan_filter_cmd(a1, a3 + 8);
}
