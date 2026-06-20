__int64 __fastcall reg_disable_cached_channels(
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
  __int64 pdev_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  const char *v21; // x2

  pdev_obj = reg_get_pdev_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( pdev_obj )
  {
    v19 = *(_QWORD *)(a1 + 80);
    if ( v19 )
    {
      *(_BYTE *)(pdev_obj + 56696) = 1;
      reg_compute_pdev_current_chan_list(pdev_obj);
      return reg_send_scheduler_msg_sb(v19, a1);
    }
    v21 = "%s: psoc is NULL";
  }
  else
  {
    v21 = "%s: pdev reg component is NULL";
  }
  qdf_trace_msg(0x51u, 2u, v21, v11, v12, v13, v14, v15, v16, v17, v18, "reg_disable_cached_channels");
  return 4;
}
