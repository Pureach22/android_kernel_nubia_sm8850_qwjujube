__int64 __fastcall direct_buf_rx_target_attach(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *comp_private_obj; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  if ( a2 && a3 )
  {
    comp_private_obj = (_QWORD *)wlan_objmgr_psoc_get_comp_private_obj(a1, 8u);
    qdf_trace_msg(
      0x5Bu,
      8u,
      "%s: Dbr psoc obj %pK",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "direct_buf_rx_target_attach",
      comp_private_obj);
    if ( comp_private_obj )
    {
      *comp_private_obj = a2;
      comp_private_obj[1] = a3;
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x5Bu,
        2u,
        "%s: dir buf rx psoc obj is null",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "direct_buf_rx_target_attach");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x5Bu,
      2u,
      "%s: hal soc or osdev is null",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "direct_buf_rx_target_attach");
    return 4;
  }
}
