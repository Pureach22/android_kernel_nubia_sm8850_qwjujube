__int64 __fastcall scm_scan_register_bcn_cb(__int64 a1, __int64 a2, unsigned int a3)
{
  _QWORD *comp_private_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  comp_private_obj = (_QWORD *)wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( comp_private_obj )
  {
    if ( a3 == 2 )
    {
      comp_private_obj[226] = a2;
      return 0;
    }
    else if ( a3 == 1 )
    {
      comp_private_obj[225] = a2;
      return 0;
    }
    else
    {
      if ( a3 )
        qdf_trace_msg(
          0x15u,
          2u,
          "%s: invalid cb type %d",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "scm_scan_register_bcn_cb",
          a3);
      else
        comp_private_obj[224] = a2;
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_psoc_get_scan_obj_fl",
      "scm_scan_register_bcn_cb",
      1929);
    qdf_trace_msg(0x15u, 2u, "%s: scan obj is NULL", v15, v16, v17, v18, v19, v20, v21, v22, "scm_scan_register_bcn_cb");
    return 4;
  }
}
