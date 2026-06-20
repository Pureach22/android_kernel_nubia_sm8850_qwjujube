__int64 __fastcall ucfg_p2p_lo_start(
        __int64 a1,
        unsigned int *a2,
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
  __int64 (__fastcall *v20)(__int64, unsigned int *); // x8
  unsigned int v21; // w19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: soc:%pK, vdev_id:%d, ctl_flags:%d, freq:%d, period:%d, interval:%d, count:%d, dev_types_len:%d, probe_resp_len:%"
    "d, device_types:%pK, probe_resp_tmplt:%pK",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "ucfg_p2p_lo_start",
    a1,
    *a2,
    a2[1],
    a2[2],
    a2[3],
    a2[4],
    a2[5],
    a2[6],
    a2[7],
    *((_QWORD *)a2 + 4),
    *((_QWORD *)a2 + 5));
  if ( a1 )
  {
    v20 = *(__int64 (__fastcall **)(__int64, unsigned int *))(*(_QWORD *)(a1 + 2128) + 152LL);
    if ( v20 )
    {
      if ( *((_DWORD *)v20 - 1) != 1900730919 )
        __break(0x8228u);
      v21 = v20(a1, a2);
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: p2p lo start, status:%d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "ucfg_p2p_lo_start",
        v21);
      return v21;
    }
    else
    {
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: psoc context passed is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "ucfg_p2p_lo_start");
    return 4;
  }
}
