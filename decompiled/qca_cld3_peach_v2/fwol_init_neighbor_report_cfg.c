__int64 __fastcall fwol_init_neighbor_report_cfg(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_ext_obj_fl; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8

  if ( a2 )
  {
    *a2 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 1164);
    a2[1] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1168);
    a2[2] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1172);
    a2[3] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1176);
    a2[4] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1180);
    a2[5] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1184);
    a2[6] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1188);
    a2[7] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1192);
    psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
    if ( psoc_ext_obj_fl )
    {
      v21 = psoc_ext_obj_fl;
      *(_DWORD *)(v21 + 2724) = *a2;
      *(_BYTE *)(v21 + 2728) = a2[1];
      *(_DWORD *)(v21 + 2732) = a2[2];
      *(_DWORD *)(v21 + 2736) = a2[3];
      *(_DWORD *)(v21 + 2740) = a2[4];
      *(_DWORD *)(v21 + 2744) = a2[5];
      *(_DWORD *)(v21 + 2748) = a2[6];
      *(_DWORD *)(v21 + 2752) = a2[7];
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x66u,
        2u,
        "%s: Failed to get MLME Obj",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "fwol_set_neighbor_report_offload_params");
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x66u,
      2u,
      "%s: Neighbor report config pointer null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "fwol_init_neighbor_report_cfg");
    return 16;
  }
}
