__int64 __fastcall p2p_process_lo_stop(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int *v9; // x19
  __int64 v10; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  void (__fastcall *v20)(__int64, unsigned int *); // x9
  __int64 v21; // x0
  const char *v22; // x2

  if ( !a1 )
  {
    v22 = "%s: invalid lo stop event";
LABEL_12:
    qdf_trace_msg(0x4Eu, 2u, v22, a2, a3, a4, a5, a6, a7, a8, a9, "p2p_process_lo_stop");
    return 4;
  }
  v9 = (unsigned int *)a1[1];
  if ( !v9 )
  {
    v22 = "%s: invalid lo event";
    goto LABEL_12;
  }
  v10 = *a1;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: vdev_id %d, reason %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "p2p_process_lo_stop",
    *v9,
    v9[1]);
  if ( v10 && (v19 = *(_QWORD *)(v10 + 88)) != 0 )
  {
    v20 = *(void (__fastcall **)(__int64, unsigned int *))(v19 + 48);
    if ( v20 )
    {
      v21 = *(_QWORD *)(v19 + 56);
      if ( *((_DWORD *)v20 - 1) != -262195293 )
        __break(0x8229u);
      v20(v21, v9);
    }
    else
    {
      qdf_trace_msg(
        0x4Eu,
        2u,
        "%s: Invalid p2p soc obj or hdd lo event callback",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "p2p_process_lo_stop");
    }
    _qdf_mem_free((__int64)v9);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: Invalid p2p soc object or start parameters",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "p2p_process_lo_stop");
    _qdf_mem_free((__int64)v9);
    return 4;
  }
}
