__int64 __fastcall target_if_dfs_set_phyerr_filter_offload(
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
  __int64 *v10; // x8
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x4
  unsigned int v22; // w19
  const char *v23; // x2

  if ( !a1 )
  {
    v23 = "%s: null pdev";
    goto LABEL_8;
  }
  v10 = *(__int64 **)(a1 + 1232);
  if ( !v10 || !*v10 )
  {
    v23 = "%s: null wmi_handle";
LABEL_8:
    qdf_trace_msg(0x49u, 2u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_dfs_set_phyerr_filter_offload");
    return 16;
  }
  result = wmi_unified_dfs_phyerr_filter_offload_en_cmd(*v10);
  if ( (_DWORD)result )
  {
    v21 = a2 & 1;
    v22 = result;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: phyerr filter offload %d set fail: %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_dfs_set_phyerr_filter_offload",
      v21,
      (unsigned int)result);
    return v22;
  }
  return result;
}
