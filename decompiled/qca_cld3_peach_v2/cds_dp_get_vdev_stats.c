__int64 __fastcall cds_dp_get_vdev_stats(__int64 a1, _DWORD *a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _DWORD *v12; // x19
  __int64 v13; // x0
  __int64 v14; // x8
  unsigned int (*v15)(void); // x8
  unsigned int v16; // w20

  v3 = _qdf_mem_malloc(0xA758u, "cds_dp_get_vdev_stats", 2986);
  if ( v3 )
  {
    v12 = (_DWORD *)v3;
    if ( gp_cds_context )
    {
      v13 = *(_QWORD *)(gp_cds_context + 64);
      if ( v13 )
      {
        if ( *(_QWORD *)v13 )
        {
          v14 = *(_QWORD *)(*(_QWORD *)v13 + 32LL);
          if ( v14 )
          {
            v15 = *(unsigned int (**)(void))(v14 + 200);
            if ( v15 )
            {
              if ( *((_DWORD *)v15 - 1) != 1504611911 )
                __break(0x8228u);
              if ( v15() )
              {
                v16 = 0;
LABEL_16:
                _qdf_mem_free((__int64)v12);
                return v16;
              }
            }
          }
LABEL_15:
          *a2 = v12[647];
          a2[1] = v12[648];
          a2[2] = v12[1075];
          v16 = 1;
          goto LABEL_16;
        }
      }
      else
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: Module ID %d context is Null (via %s)",
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          "__cds_get_context",
          71,
          "cds_get_cdp_vdev_stats");
      }
    }
    else
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: cds context pointer is null (via %s)",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "__cds_get_context",
        "cds_get_cdp_vdev_stats");
    }
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v4, v5, v6, v7, v8, v9, v10, v11, "cdp_host_get_vdev_stats");
    goto LABEL_15;
  }
  return 0;
}
