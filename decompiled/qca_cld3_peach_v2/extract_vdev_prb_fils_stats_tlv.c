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
        __int64 a12)
{
  __int64 v12; // x8
  _DWORD *v13; // x21
  unsigned int v14; // w19
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  v12 = *(_QWORD *)(a10 + 112);
  if ( v12 )
  {
    v13 = (_DWORD *)(v12 + 32LL * a11);
    *(_DWORD *)a12 = v13[1];
    *(_DWORD *)(a12 + 4) = v13[2];
    *(_DWORD *)(a12 + 8) = v13[3];
    *(_DWORD *)(a12 + 12) = v13[4];
    *(_DWORD *)(a12 + 16) = v13[5];
    if ( *(_DWORD *)(a10 + 120) )
    {
      v14 = 0;
      *(_BYTE *)(a12 + 20) = (~v13[6] & 3) == 0;
    }
    else
    {
      v15 = a12;
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: No vdev_extd_stats in the event buffer",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_mlo_vdev_status_info");
      a12 = v15;
      v14 = 4;
    }
    *(_DWORD *)(a12 + 24) = v13[7];
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
      v13[5]);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev txpwr: %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "extract_vdev_prb_fils_stats_tlv",
      (unsigned int)v13[7]);
  }
  else
  {
    return 0;
  }
  return v14;
}
