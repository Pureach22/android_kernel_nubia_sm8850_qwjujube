__int64 __fastcall reg_set_fcc_constraint(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 pdev_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19
  const char *v23; // x2
  __int64 v24; // x22
  __int64 v25; // x0
  __int64 psoc_obj; // x0

  pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( pdev_obj )
  {
    v21 = a2 & 1;
    if ( *(unsigned __int8 *)(pdev_obj + 56753) == v21 )
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: same fcc_constraint %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "reg_set_fcc_constraint",
        v21);
      return 0;
    }
    v24 = pdev_obj;
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: set fcc_constraint: %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "reg_set_fcc_constraint",
      v21);
    v25 = *(_QWORD *)(a1 + 80);
    if ( v25 )
    {
      psoc_obj = reg_get_psoc_obj(v25, v13, v14, v15, v16, v17, v18, v19, v20);
      if ( psoc_obj )
      {
        *(_BYTE *)(psoc_obj + 93969) = v21;
        *(_BYTE *)(v24 + 56753) = v21;
        return 0;
      }
      v23 = "%s: psoc reg component is NULL";
    }
    else
    {
      v23 = "%s: psoc is NULL";
    }
  }
  else
  {
    v23 = "%s: pdev reg component is NULL";
  }
  qdf_trace_msg(0x51u, 2u, v23, v13, v14, v15, v16, v17, v18, v19, v20, "reg_set_fcc_constraint");
  return 4;
}
