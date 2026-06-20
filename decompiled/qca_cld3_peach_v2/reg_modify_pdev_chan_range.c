__int64 __fastcall reg_modify_pdev_chan_range(
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
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 pdev_obj; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x21
  __int64 v29; // x20
  __int64 psoc_obj; // x0
  int v31; // w22
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x8
  void (__fastcall *v41)(__int64, __int64); // x8
  const char *v42; // x2

  result = reg_update_channel_ranges(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (_DWORD)result )
    return result;
  pdev_obj = reg_get_pdev_obj(a1, v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !pdev_obj )
  {
    v42 = "%s: pdev reg component is NULL";
LABEL_13:
    qdf_trace_msg(0x51u, 2u, v42, v20, v21, v22, v23, v24, v25, v26, v27, "reg_modify_pdev_chan_range");
    return 4;
  }
  v28 = *(_QWORD *)(a1 + 80);
  if ( !v28 )
  {
    v42 = "%s: psoc is NULL";
    goto LABEL_13;
  }
  v29 = pdev_obj;
  psoc_obj = reg_get_psoc_obj(*(_QWORD *)(a1 + 80), v20, v21, v22, v23, v24, v25, v26, v27);
  if ( !psoc_obj )
  {
    v42 = "%s: psoc reg component is NULL";
    goto LABEL_13;
  }
  v31 = *(unsigned __int8 *)(psoc_obj + 91095);
  reg_compute_pdev_current_chan_list(v29, v20, v21, v22, v23, v24, v25, v26, v27);
  v40 = *(_QWORD *)(v28 + 2128);
  if ( v40 )
  {
    v41 = *(void (__fastcall **)(__int64, __int64))(v40 + 904);
    if ( v41 )
    {
      if ( *((_DWORD *)v41 - 1) != -145496263 )
        __break(0x8228u);
      v41(a1, v29);
      return 0;
    }
    else if ( v31 )
    {
      return reg_send_scheduler_msg_nb(v28, a1);
    }
    else
    {
      return reg_send_scheduler_msg_sb(v28, a1);
    }
  }
  else
  {
    qdf_trace_msg(0x51u, 2u, "%s: tx_ops is NULL", v32, v33, v34, v35, v36, v37, v38, v39, "reg_get_psoc_tx_ops");
    return 16;
  }
}
