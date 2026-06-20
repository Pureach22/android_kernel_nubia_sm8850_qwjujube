__int64 __fastcall reg_get_max_tx_power(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 result; // x0
  int v21; // w10
  __int64 v22; // x20

  pdev_obj = reg_get_pdev_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( pdev_obj )
  {
    v18 = pdev_obj;
    v19 = 0;
    result = 0;
    do
    {
      if ( *(_DWORD *)(v18 + v19 + 8) && *(_DWORD *)(v18 + v19 + 12) != 1 )
      {
        v21 = *(_DWORD *)(v18 + v19 + 16);
        if ( v21 <= (unsigned __int8)result )
          result = (unsigned int)result;
        else
          result = (unsigned int)v21;
      }
      v19 += 36;
    }
    while ( v19 != 3672 );
    if ( !(_BYTE)result )
    {
      v22 = jiffies;
      if ( reg_get_max_tx_power___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x51u,
          2u,
          "%s: max_tx_power is zero",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "reg_get_max_tx_power");
        reg_get_max_tx_power___last_ticks = v22;
      }
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev private obj is NULL",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "reg_get_max_tx_power");
    return 16;
  }
  return result;
}
