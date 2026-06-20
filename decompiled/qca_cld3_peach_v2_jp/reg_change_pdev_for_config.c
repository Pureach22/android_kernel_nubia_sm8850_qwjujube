__int64 __fastcall reg_change_pdev_for_config(
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
  __int64 psoc_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 pdev_obj; // x0
  const char *v24; // x2

  psoc_obj = reg_get_psoc_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( psoc_obj )
  {
    v21 = psoc_obj;
    pdev_obj = reg_get_pdev_obj(a2, v13, v14, v15, v16, v17, v18, v19, v20);
    if ( pdev_obj )
    {
      *(_BYTE *)(pdev_obj + 56752) = *(_BYTE *)(v21 + 91140);
      *(_BYTE *)(pdev_obj + 56760) = *(_BYTE *)(v21 + 91148);
      *(_BYTE *)(pdev_obj + 57456) = *(_BYTE *)(v21 + 93232);
      *(_DWORD *)(pdev_obj + 56756) = *(_DWORD *)(v21 + 91144);
      *(_BYTE *)(pdev_obj + 58944) = *(_BYTE *)(v21 + 93958);
      *(_BYTE *)(pdev_obj + 58945) = *(_BYTE *)(v21 + 93959);
      reg_compute_pdev_current_chan_list(pdev_obj);
      return reg_send_scheduler_msg_sb(a1, a2);
    }
    v24 = "%s: reg pdev private obj is NULL";
  }
  else
  {
    v24 = "%s: psoc priv obj is NULL";
  }
  return qdf_trace_msg(0x51u, 2u, v24, v13, v14, v15, v16, v17, v18, v19, v20, "reg_change_pdev_for_config");
}
