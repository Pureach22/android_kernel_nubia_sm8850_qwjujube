__int64 __fastcall reg_get_6g_ap_master_chan_list(__int64 a1, unsigned int a2, void *a3)
{
  __int64 pdev_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  pdev_obj = reg_get_pdev_obj(a1);
  if ( pdev_obj )
  {
    if ( a2 <= 3 )
    {
      qdf_mem_copy(a3, (const void *)(pdev_obj + 2160LL * a2 + 11020), 0x870u);
      return 0;
    }
    else
    {
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev private obj is NULL",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "reg_get_6g_ap_master_chan_list");
    return 16;
  }
}
