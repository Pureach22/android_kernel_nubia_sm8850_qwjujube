__int64 __fastcall wma_scan_probe_setoui(
        __int64 *a1,
        __int64 a2,
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
  __int64 v20; // x20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  if ( !(unsigned int)_wma_validate_handle(
                        (__int64)a1,
                        (__int64)"wma_scan_probe_setoui",
                        a3,
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        a10) )
  {
    v20 = *a1;
    if ( !(unsigned int)_wmi_validate_handle(
                          v20,
                          (__int64)"wma_scan_probe_setoui",
                          v12,
                          v13,
                          v14,
                          v15,
                          v16,
                          v17,
                          v18,
                          v19) )
    {
      if ( (wma_is_vdev_valid(*(_DWORD *)(a2 + 4), v21, v22, v23, v24, v25, v26, v27, v28) & 1) != 0 )
        return wmi_unified_scan_probe_setoui_cmd(v20);
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: vdev_id: %d is not active",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "wma_scan_probe_setoui",
        *(unsigned int *)(a2 + 4));
    }
  }
  return 4;
}
