__int64 __fastcall reg_get_num_rules_of_ap_pwr_type(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_obj; // x0
  __int64 v13; // x1
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int64 v22; // x8
  const char *v23; // x2
  unsigned int v24; // w1

  psoc_obj = reg_get_psoc_obj(*(_QWORD *)(a1 + 80), a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !psoc_obj )
  {
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: Regulatory psoc private object is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "reg_get_reg_rules_for_pdev");
    goto LABEL_7;
  }
  v22 = *(unsigned __int8 *)(a1 + 40);
  if ( v22 >= 3 )
  {
    __break(0x5512u);
    if ( v22 <= 3 )
      JUMPOUT(0x1D90C4);
    return reg_get_cur_6g_client_type(psoc_obj, v13);
  }
  if ( psoc_obj + 30364LL * *(unsigned __int8 *)(a1 + 40) == -29624 )
  {
LABEL_7:
    v23 = "%s: No psoc_reg_rules";
    v24 = 8;
    goto LABEL_8;
  }
  if ( a2 >= 4 )
  {
    v23 = "%s: Unsupported 6G AP power type";
    v24 = 2;
LABEL_8:
    qdf_trace_msg(0x51u, v24, v23, v14, v15, v16, v17, v18, v19, v20, v21, "reg_get_num_rules_of_ap_pwr_type");
    return 0;
  }
  return *(unsigned __int8 *)(psoc_obj + 30364LL * *(unsigned __int8 *)(a1 + 40) + 29624 + a2 + 150);
}
