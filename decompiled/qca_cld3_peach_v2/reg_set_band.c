__int64 __fastcall reg_set_band(
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
  __int64 pdev_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x24
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x21
  __int64 psoc_obj; // x0
  __int64 v26; // x22
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v36; // x2
  __int64 v37; // x0
  const char *v38; // x3

  pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !pdev_obj )
  {
    v36 = "%s: pdev reg component is NULL";
LABEL_19:
    v38 = "reg_set_band";
    goto LABEL_20;
  }
  v21 = pdev_obj;
  if ( *(_DWORD *)(pdev_obj + 56756) == a2 )
  {
    v22 = reg_get_pdev_obj(a1, v13, v14, v15, v16, v17, v18, v19, v20);
    if ( v22 )
    {
      if ( (*(_BYTE *)(v22 + 59008) & 1) != 0 )
        goto LABEL_5;
    }
    else
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: pdev reg component is NULL",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "reg_get_keep_6ghz_sta_cli_connection");
    }
    qdf_trace_msg(0x51u, 4u, "%s: same band %d", v13, v14, v15, v16, v17, v18, v19, v20, "reg_set_band", a2);
    return 0;
  }
LABEL_5:
  v23 = reg_get_pdev_obj(a1, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( v23 )
  {
    if ( (*(_BYTE *)(v23 + 56756) & 4) != 0 )
    {
      v24 = *(_QWORD *)(a1 + 80);
      if ( v24 )
      {
LABEL_8:
        psoc_obj = reg_get_psoc_obj(v24, v13, v14, v15, v16, v17, v18, v19, v20);
        if ( psoc_obj )
        {
          v26 = psoc_obj;
          qdf_trace_msg(
            0x51u,
            4u,
            "%s: set band bitmap: %d",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "reg_set_band",
            a2);
          *(_DWORD *)(v21 + 56756) = a2;
          *(_DWORD *)(v26 + 91144) = a2;
          reg_compute_pdev_current_chan_list(v21, v27, v28, v29, v30, v31, v32, v33, v34);
          return reg_send_scheduler_msg_sb(v24, a1);
        }
        v36 = "%s: psoc reg component is NULL";
        goto LABEL_19;
      }
      goto LABEL_14;
    }
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: pdev reg component is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "reg_is_6ghz_band_set");
  }
  v37 = reg_get_pdev_obj(a1, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( v37 )
  {
    *(_BYTE *)(v37 + 59008) = 0;
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: set keep_6ghz_sta_cli_connection = %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "reg_set_keep_6ghz_sta_cli_connection",
      0);
    v24 = *(_QWORD *)(a1 + 80);
    if ( v24 )
      goto LABEL_8;
LABEL_14:
    v36 = "%s: psoc is NULL";
    goto LABEL_19;
  }
  v36 = "%s: pdev reg component is NULL";
  v38 = "reg_set_keep_6ghz_sta_cli_connection";
LABEL_20:
  qdf_trace_msg(0x51u, 2u, v36, v13, v14, v15, v16, v17, v18, v19, v20, v38);
  return 4;
}
