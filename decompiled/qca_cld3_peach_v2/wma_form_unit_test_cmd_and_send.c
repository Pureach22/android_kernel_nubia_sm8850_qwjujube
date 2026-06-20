__int64 __fastcall wma_form_unit_test_cmd_and_send(
        unsigned int a1,
        int a2,
        unsigned int a3,
        int *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 *context; // x23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v34; // x23
  _DWORD *v35; // x0
  __int64 v36; // x24
  _DWORD *v37; // x8
  __int64 v38; // x9
  int v39; // t1
  unsigned int v40; // w19
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7

  context = _cds_get_context(54, (__int64)"wma_form_unit_test_cmd_and_send", a5, a6, a7, a8, a9, a10, a11, a12);
  qdf_trace_msg(0x36u, 8u, "%s: enter", v17, v18, v19, v20, v21, v22, v23, v24, "wma_form_unit_test_cmd_and_send");
  if ( (unsigned int)cds_get_conparam() != 5 && (wma_is_vdev_valid(a1, v25, v26, v27, v28, v29, v30, v31, v32) & 1) == 0 )
    return 16;
  if ( a3 >= 0x65 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: arg_count is crossed the boundary",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "wma_form_unit_test_cmd_and_send");
    return 16;
  }
  if ( context )
  {
    v34 = *context;
    if ( (unsigned int)_wmi_validate_handle(
                         v34,
                         (__int64)"wma_form_unit_test_cmd_and_send",
                         v25,
                         v26,
                         v27,
                         v28,
                         v29,
                         v30,
                         v31,
                         v32) )
      return 16;
    v35 = (_DWORD *)_qdf_mem_malloc(0x1A0u, "wma_form_unit_test_cmd_and_send", 1113);
    if ( v35 )
    {
      v36 = (__int64)v35;
      *v35 = a1;
      v35[1] = a2;
      v35[2] = a3;
      if ( a3 )
      {
        v37 = v35 + 4;
        v38 = a3;
        do
        {
          v39 = *a4++;
          --v38;
          *v37++ = v39;
        }
        while ( v38 );
      }
      v40 = wmi_unified_unit_test_cmd(v34);
      _qdf_mem_free(v36);
      qdf_trace_msg(0x36u, 8u, "%s: exit", v41, v42, v43, v44, v45, v46, v47, v48, "wma_form_unit_test_cmd_and_send");
      return v40;
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid WMA handle (via %s)",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "__wma_validate_handle",
      "wma_form_unit_test_cmd_and_send");
    return 16;
  }
}
