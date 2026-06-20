__int64 __fastcall mlo_link_recfg_is_start_as_active(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
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

  v9 = *(_QWORD *)(a1 + 1360);
  if ( v9 )
  {
    v10 = *(_QWORD *)(v9 + 3888);
    if ( v10 )
    {
      qdf_mutex_acquire(v10 + 760);
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: recfg_type %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "mlo_link_recfg_is_start_as_active",
        *(unsigned int *)(v10 + 284));
      v19 = *(_QWORD *)(v9 + 3888);
      LODWORD(v9) = *(_DWORD *)(v10 + 284) == 4;
      qdf_mutex_release(v19 + 760);
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: invalid recfg_ctx",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "mlo_link_recfg_is_start_as_active");
      LODWORD(v9) = 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: invalid mlo_dev_ctx",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "mlo_link_recfg_is_start_as_active");
  }
  return (unsigned int)v9;
}
