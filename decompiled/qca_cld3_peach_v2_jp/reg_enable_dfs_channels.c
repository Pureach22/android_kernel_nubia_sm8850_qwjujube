__int64 __fastcall reg_enable_dfs_channels(
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
  unsigned int v21; // w21
  const char *v23; // x2
  __int64 v24; // x20
  __int64 v25; // x22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8
  void (__fastcall *v35)(__int64, __int64); // x8

  pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !pdev_obj )
  {
    v23 = "%s: pdev reg component is NULL";
LABEL_15:
    qdf_trace_msg(0x51u, 2u, v23, v13, v14, v15, v16, v17, v18, v19, v20, "reg_enable_dfs_channels");
    return 4;
  }
  v21 = a2 & 1;
  if ( *(unsigned __int8 *)(pdev_obj + 56752) == v21 )
  {
    qdf_trace_msg(
      0x51u,
      4u,
      "%s: dfs_enabled is already set to %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "reg_enable_dfs_channels",
      a2 & 1);
    return 0;
  }
  v24 = *(_QWORD *)(a1 + 80);
  if ( !v24 )
  {
    v23 = "%s: psoc is NULL";
    goto LABEL_15;
  }
  v25 = pdev_obj;
  if ( !reg_get_psoc_obj(*(_QWORD *)(a1 + 80), v13, v14, v15, v16, v17, v18, v19, v20) )
  {
    v23 = "%s: psoc reg component is NULL";
    goto LABEL_15;
  }
  qdf_trace_msg(
    0x51u,
    4u,
    "%s: set dfs_enabled: %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "reg_enable_dfs_channels",
    v21);
  *(_BYTE *)(v25 + 56752) = v21;
  reg_compute_pdev_current_chan_list(v25);
  v34 = *(_QWORD *)(v24 + 2128);
  if ( v34 )
  {
    v35 = *(void (__fastcall **)(__int64, __int64))(v34 + 904);
    if ( v35 )
    {
      if ( *((_DWORD *)v35 - 1) != -145496263 )
        __break(0x8228u);
      v35(a1, v25);
    }
    return reg_send_scheduler_msg_sb(v24, a1);
  }
  else
  {
    qdf_trace_msg(0x51u, 2u, "%s: tx_ops is NULL", v26, v27, v28, v29, v30, v31, v32, v33, "reg_get_psoc_tx_ops");
    return 16;
  }
}
