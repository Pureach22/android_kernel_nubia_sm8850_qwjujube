__int64 __fastcall scm_is_scan_allowed(
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
  _DWORD *comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  const char *v21; // x2
  __int64 v22; // x0
  __int64 v23; // x21

  if ( !a1 )
  {
    v21 = "%s: vdev is NULL";
LABEL_8:
    qdf_trace_msg(0x15u, 2u, v21, a2, a3, a4, a5, a6, a7, a8, a9, "scm_is_scan_allowed");
    return 0;
  }
  comp_private_obj = (_DWORD *)wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(*(_QWORD *)(a1 + 216) + 80LL), 3u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_pdev_get_scan_obj",
      764);
    v21 = "%s: Couldn't find scan psoc object";
    goto LABEL_8;
  }
  if ( *comp_private_obj )
  {
    v19 = jiffies;
    if ( scm_is_scan_allowed___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: scan disabled %x, for psoc",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "scm_is_scan_allowed");
      scm_is_scan_allowed___last_ticks = v19;
      return 0;
    }
    return 0;
  }
  v22 = wlan_objmgr_vdev_get_comp_private_obj(a1, 3u);
  if ( !v22 )
  {
    v21 = "%s: Couldn't find scan vdev object";
    goto LABEL_8;
  }
  if ( !*(_DWORD *)(v22 + 4) )
    return 1;
  v23 = jiffies;
  if ( scm_is_scan_allowed___last_ticks_5 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: scan disabled %x on vdev_id:%d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "scm_is_scan_allowed");
    scm_is_scan_allowed___last_ticks_5 = v23;
    return 0;
  }
  return 0;
}
