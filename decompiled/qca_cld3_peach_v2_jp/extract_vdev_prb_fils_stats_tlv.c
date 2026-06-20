__int64 __fastcall extract_vdev_prb_fils_stats_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned int a11,
        _DWORD *a12)
{
  __int64 v12; // x8
  _DWORD *v13; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v23; // [xsp+0h] [xbp-10h]

  v12 = *(_QWORD *)(a10 + 112);
  if ( v12 )
  {
    v13 = (_DWORD *)(v12 + 32LL * a11);
    *a12 = v13[1];
    a12[1] = v13[2];
    a12[2] = v13[3];
    a12[3] = v13[4];
    a12[4] = v13[5];
    a12[6] = v13[7];
    v23 = v13[5];
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev: %d, fd_s: %d, fd_f: %d, prb_s: %d, prb_f: %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_vdev_prb_fils_stats_tlv",
      (unsigned int)v13[1],
      (unsigned int)v13[2],
      (unsigned int)v13[3],
      (unsigned int)v13[4],
      v23);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev txpwr: %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "extract_vdev_prb_fils_stats_tlv",
      (unsigned int)v13[7]);
  }
  return 0;
}
