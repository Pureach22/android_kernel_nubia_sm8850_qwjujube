__int64 __fastcall ucfg_dp_get_txrx_stats(
        __int64 a1,
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
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x9
  _DWORD *v22; // x12
  _DWORD *v23; // x14

  if ( !a1 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_vdev_priv_obj");
    goto LABEL_7;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
LABEL_7:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Unable to get DP link",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "ucfg_dp_get_txrx_stats");
    return 4;
  }
  v20 = *(_QWORD *)(comp_private_obj + 32);
  v21 = 0;
  do
  {
    v22 = (_DWORD *)(v20 + 232 + v21);
    v23 = (_DWORD *)(a2 + 72 + v21);
    v21 += 76;
    *(v23 - 3) = v22[15];
    *(v23 - 2) = v22[16];
    *(v23 - 1) = v22[17];
    *v23 = v22[18];
    *(v23 - 18) = *v22;
    *(v23 - 17) = v22[1];
    *(v23 - 16) = v22[2];
  }
  while ( v21 != 2432 );
  *(_DWORD *)(a2 + 2432) = *(_DWORD *)(v20 + 2664);
  *(_DWORD *)(a2 + 2436) = *(_DWORD *)(v20 + 2668);
  *(_DWORD *)(a2 + 2440) = *(_DWORD *)(v20 + 2672);
  *(_DWORD *)(a2 + 2444) = *(_DWORD *)(v20 + 2676);
  *(_DWORD *)(a2 + 2448) = *(_DWORD *)(v20 + 2680);
  *(_DWORD *)(a2 + 2452) = *(_DWORD *)(v20 + 2684);
  *(_DWORD *)(a2 + 2472) = *(_DWORD *)(v20 + 2704);
  *(_DWORD *)(a2 + 2476) = *(_DWORD *)(v20 + 2708);
  *(_QWORD *)(a2 + 2480) = *(_QWORD *)(v20 + 2712);
  return 0;
}
