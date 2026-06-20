__int64 __fastcall ucfg_scan_pno_start(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0
  __int64 v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 3u);
  if ( comp_private_obj )
  {
    if ( *(_BYTE *)(comp_private_obj + 1) == 1 )
    {
      qdf_trace_msg(0x15u, 2u, "%s: pno already in progress", v3, v4, v5, v6, v7, v8, v9, v10, "ucfg_scan_pno_start");
      return 6;
    }
    else
    {
      v12 = comp_private_obj;
      result = tgt_scan_pno_start(a1, v3, v4, v5, v6, v7, v8, v9, v10);
      if ( (_DWORD)result )
      {
        v21 = result;
        qdf_trace_msg(0x15u, 2u, "%s: pno start failed", v13, v14, v15, v16, v17, v18, v19, v20, "ucfg_scan_pno_start");
        return v21;
      }
      else
      {
        *(_BYTE *)(v12 + 1) = 1;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x15u, 2u, "%s: null scan_vdev_obj", v3, v4, v5, v6, v7, v8, v9, v10, "ucfg_scan_pno_start");
    return 4;
  }
  return result;
}
