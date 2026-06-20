__int64 __fastcall regulatory_pdev_close(
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
  __int64 pdev_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 psoc_obj; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  pdev_obj = reg_get_pdev_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( pdev_obj )
  {
    *(_BYTE *)(pdev_obj + 58201) = 0;
    psoc_obj = reg_get_psoc_obj(*(_QWORD *)(a1 + 80), v11, v12, v13, v14, v15, v16, v17, v18);
    if ( psoc_obj )
    {
      reg_reset_ctry_pending_hints(psoc_obj);
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: reg psoc private obj is NULL",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "regulatory_pdev_close");
      return 5;
    }
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev private obj is NULL",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "regulatory_pdev_close");
    return 16;
  }
}
