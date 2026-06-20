__int64 __fastcall dp_mon_vdev_attach(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  unsigned int v13; // w21

  v2 = *(_QWORD *)(a1 + 24);
  v3 = _qdf_mem_malloc(0x18u, "dp_mon_vdev_attach", 6475);
  if ( v3 )
  {
    v12 = v3;
    if ( v2 )
      wlan_minidump_log(v4, v5, v6, v7, v8, v9, v10, v11, v3, 24, *(_QWORD *)(*(_QWORD *)(v2 + 8) + 16LL));
    v13 = 0;
    *(_QWORD *)(a1 + 42696) = v12;
  }
  else
  {
    v13 = 2;
    qdf_trace_msg(
      0x92u,
      2u,
      "%s: %pK: Monitor vdev allocation failed",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "dp_mon_vdev_attach",
      a1);
  }
  return v13;
}
