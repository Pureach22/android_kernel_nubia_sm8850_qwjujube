__int64 __fastcall reg_get_current_chan_list(__int64 a1, void *a2)
{
  const void *pdev_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  pdev_obj = (const void *)reg_get_pdev_obj(a1);
  if ( pdev_obj )
  {
    qdf_mem_copy(a2, pdev_obj, 0xE58u);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev private obj is NULL",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "reg_get_current_chan_list");
    return 16;
  }
}
