__int64 __fastcall target_send_dfs_offload_enable_cmd(
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
  __int64 v11; // x8
  unsigned int v12; // w19
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x4
  unsigned int v24; // w20
  const char *v26; // x2

  if ( !a1 )
  {
    v26 = "%s: null pdev";
    goto LABEL_9;
  }
  v10 = *(__int64 **)(a1 + 1232);
  if ( !v10 || (v11 = *v10) == 0 )
  {
    v26 = "%s: null wmi_hdl";
LABEL_9:
    qdf_trace_msg(0x49u, 2u, v26, a3, a4, a5, a6, a7, a8, a9, a10, "target_send_dfs_offload_enable_cmd");
    return 16;
  }
  v12 = *(unsigned __int8 *)(a1 + 40);
  if ( (a2 & 1) != 0 )
  {
    v14 = wmi_unified_dfs_phyerr_offload_en_cmd(v11);
    if ( v14 )
    {
LABEL_6:
      v23 = a2 & 1;
      v24 = v14;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: dfs: dfs offload cmd failed, enable:%d, pdev:%d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "target_send_dfs_offload_enable_cmd",
        v23,
        v12);
      return v24;
    }
  }
  else
  {
    v14 = wmi_unified_dfs_phyerr_offload_dis_cmd(v11);
    if ( v14 )
      goto LABEL_6;
  }
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: dfs: sent dfs offload cmd, enable:%d, pdev:%d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "target_send_dfs_offload_enable_cmd",
    a2 & 1,
    v12);
  return 0;
}
