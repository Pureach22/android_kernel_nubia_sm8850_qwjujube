bool __fastcall wlan_serialization_is_active_scan_cmd_allowed(__int64 a1)
{
  __int64 pdev_from_cmd; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  unsigned int v11; // w20
  _BOOL8 result; // x0
  const char *v13; // x2
  unsigned int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  pdev_from_cmd = wlan_serialization_get_pdev_from_cmd(a1);
  if ( !pdev_from_cmd )
  {
    v13 = "%s: invalid pdev";
LABEL_6:
    qdf_trace_msg(0x4Cu, 2u, v13, v2, v3, v4, v5, v6, v7, v8, v9, "wlan_serialization_is_active_scan_cmd_allowed");
    result = 0;
    goto LABEL_7;
  }
  v10 = *(_QWORD *)(pdev_from_cmd + 80);
  if ( !v10 )
  {
    v13 = "%s: invalid psoc";
    goto LABEL_6;
  }
  wlan_objmgr_iterate_obj_list(
    *(_QWORD *)(pdev_from_cmd + 80),
    1,
    wlan_serialization_active_scan_cmd_count_handler,
    (__int64)&v14,
    1,
    9u);
  v11 = v14;
  result = v11 < (unsigned int)ucfg_scan_get_max_active_scans(v10);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
