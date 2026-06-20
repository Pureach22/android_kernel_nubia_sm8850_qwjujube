__int64 __fastcall target_if_pmo_set_multiple_mc_filter_req(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x21
  _DWORD *v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  __int64 v32; // x0
  unsigned int v33; // w20
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  const char *v43; // x2

  if ( !a1 )
  {
    v43 = "%s: vdev ptr passed is NULL";
    goto LABEL_12;
  }
  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v43 = "%s: psoc handle is NULL";
LABEL_12:
    qdf_trace_msg(0x49u, 2u, v43, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_pmo_set_multiple_mc_filter_req");
    return 4;
  }
  v13 = (_DWORD *)_qdf_mem_malloc(0x5A8u, "target_if_pmo_set_multiple_mc_filter_req", 137);
  if ( !v13 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: memory alloc failed for filter_params",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_pmo_set_multiple_mc_filter_req");
    return 2;
  }
  v22 = (__int64)v13;
  *v13 = *(unsigned __int8 *)(a2 + 1);
  qdf_mem_copy(v13 + 1, (const void *)(a2 + 2), 6 * (unsigned int)*(unsigned __int8 *)(a2 + 1));
  *(_BYTE *)(v22 + 1444) = 1;
  v31 = *(_QWORD *)(v11 + 2800);
  if ( !v31 || (v32 = *(_QWORD *)(v31 + 16)) == 0 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Invalid wmi handle",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "target_if_pmo_set_multiple_mc_filter_req");
    _qdf_mem_free(v22);
    return 4;
  }
  v33 = wmi_unified_multiple_add_clear_mcbc_filter_cmd(v32);
  if ( v33 )
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Failed to send add/clear mcbc filter cmd",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "target_if_pmo_set_multiple_mc_filter_req");
  _qdf_mem_free(v22);
  return v33;
}
